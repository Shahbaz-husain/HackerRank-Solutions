#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <functional>
#include <string>
#include <cstring>
#include <cstdint>
using namespace std;

int gNPaths = 0;
const unsigned int kHashSize = 4096*16;
vector< set<unsigned int> > gHashTab;
size_t gN  = 0;
size_t gNx  = 0;

inline void checkThis(const char *knightPath, const unsigned int hashp = 0){
    auto hashx = (hashp)? hashp : std::_Hash_impl::hash(knightPath, gNx, 11); 
    auto hashy = std::_Hash_impl::hash(knightPath+gNx, gNx, 11); 
    auto hash2 = hashx^(hashy<<1); 
    auto hash  = hashx%kHashSize;
    if(gHashTab[hash].size()==0){
        gHashTab[hash].insert(hash2);
        ++gNPaths;
        return;
    }
    if(gHashTab[hash].size()!=0){
        if(gHashTab[hash].count(hash2)) return;
        gHashTab[hash].insert(hash2);
        ++gNPaths;
        return;
    }
}

void zigs(const string aS, const string bS){
    const int n = aS.size();
    string raS = aS;
    reverse(raS.begin(), raS.end());
    string rbS = bS;
    reverse(rbS.begin(), rbS.end());

    if(n<3) return;
    char a[n+1];
    char b[n+1];
    strcpy(a, aS.c_str());
    strcpy(b, bS.c_str());

    char ra[n+1];
    char rb[n+1];
    strcpy(ra, raS.c_str());
    strcpy(rb, rbS.c_str());

    a[n]='\0';
    b[n]='\0';
    ra[n]='\0';
    rb[n]='\0';

    int kStart = 0;
    for (; kStart < n; ++kStart){
        if(a[kStart]!=a[0] || b[kStart]!=a[0]) break;
    }
    kStart = max(1,kStart);
    int kEnd   = n-1;
    for (; kEnd != 0; --kEnd){
        if(a[kEnd]!=a[n-1] || b[kEnd]!=a[n-1]) break;
    }
    kEnd+=2;
    kEnd = min(n+1,kEnd);
    
    char knightPath[gN+1];
    char revKnightPath[gN+1];
    knightPath[gN]    ='\0';
    revKnightPath[gN] ='\0';

    char frontLoopTop[gN+1];
    memcpy(frontLoopTop, ra, n);
    memcpy(frontLoopTop+n, b, n);
    frontLoopTop[gN]   ='\0';

    char frontLoopBottom[gN+1];
    memcpy(frontLoopBottom, rb, n);
    memcpy(frontLoopBottom+n, a, n);
    frontLoopBottom[gN]   ='\0';

    char tailLoopTop[gN+1];
    memcpy(tailLoopTop, a, n);
    memcpy(tailLoopTop+n, rb, n);
    tailLoopTop[gN]   ='\0';

    char tailLoopBottom[gN+1];
    memcpy(tailLoopBottom, b, n);
    memcpy(tailLoopBottom+n, ra, n);
    tailLoopBottom[gN]   ='\0';
    
    char zigEvenUp[gN+1];
    char zigEvenDown[gN+1];
    bool goingEvenDown = true;
    for (int k = 0; k < n; ++k){
        if(goingEvenDown){
            zigEvenDown[2*k]   = a[k];
            zigEvenDown[2*k+1] = b[k];

            zigEvenUp[2*k]   = b[k];
            zigEvenUp[2*k+1] = a[k];
            goingEvenDown = false;
        }
        else{
            zigEvenDown[2*k]   = b[k];
            zigEvenDown[2*k+1] = a[k];
            zigEvenUp[2*k]   = a[k];
            zigEvenUp[2*k+1] = b[k];
            goingEvenDown = true;
        }
    }
    zigEvenUp[gN]   ='\0';
    zigEvenDown[gN] ='\0';

    for (int k = kStart; k < n; ++k)
    {   
        memcpy(knightPath,    frontLoopTop+n-k,    2*k);
        memcpy(revKnightPath, frontLoopBottom+n-k, 2*k);

        unsigned int hashx    = 0;
        unsigned int revHashx = 0;
        if(2*k>n){
            hashx = std::_Hash_impl::hash(knightPath, gNx, 11);
            revHashx = std::_Hash_impl::hash(revKnightPath, gNx, 11);  
        } 
        for(int i=k+1;i<kEnd;++i){
            bool zigEndsTop = true;
            if(k%2 == 1){ //loop starts at the bottom
                memcpy(knightPath+2*k,    zigEvenDown+2*k, 2*(i-k));
                memcpy(revKnightPath+2*k, zigEvenUp+2*k,   2*(i-k));
            } 
            else{//loop starts at the bottom   
                memcpy(knightPath+2*k,    zigEvenUp+2*k,   2*(i-k)); 
                memcpy(revKnightPath+2*k, zigEvenDown+2*k, 2*(i-k));
            }

            if( i<n ){
                if(i%2 == k%2){
                    memcpy(knightPath+2*i,    tailLoopBottom+i, 2*(n-i)); 
                    memcpy(revKnightPath+2*i, tailLoopTop+i, 2*(n-i)); 
                }
                else{
                    memcpy(knightPath+2*i,    tailLoopTop+i, 2*(n-i)); 
                    memcpy(revKnightPath+2*i, tailLoopBottom+i, 2*(n-i)); 
                }
            }
            checkThis(knightPath, hashx);
            checkThis(revKnightPath, revHashx);
        }
    }
}

void bigLoop(const string a, const string b){
    const int n = a.size();
    
    string knightPath = a + b;
    reverse(knightPath.begin(),knightPath.begin()+n);
    for(int i=0;i<gN;++i){
        rotate(knightPath.begin(), knightPath.begin()+1, knightPath.end());
        checkThis(knightPath.c_str());
    }
}


void paths(const string a, const string b){
    string ra = a;
    reverse(ra.begin(), ra.end());
    string rb = b;
    reverse(rb.begin(), rb.end());

    bigLoop(a, b);
    unsigned int gNPathsAux = gNPaths;

    if(ra == b) return;

    zigs(a, b);

    if(a!=ra || b!=rb){
        bigLoop(ra, rb);
        zigs(ra, rb);
    }
    
}

int main() {

    int nTests;
    cin >> nTests;

    for(int i=0;i<nTests;++i){
        gHashTab.clear();
        gHashTab.resize(kHashSize);
        gNPaths = 0;
        int n;
        cin >> n;
        string a,b;
        cin >> a;
        cin >> b;

        gN = a.size()*2;
        gNx = a.size();
        paths(a,b);
        cout << gNPaths << endl;
    }
      
    return 0;
}