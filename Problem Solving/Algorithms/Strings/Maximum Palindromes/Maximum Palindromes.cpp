#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long int invf[101010],fact[101010];
int bit[26][101010];

void update(int p,int c,int v){
    while(p<=100000){
        bit[c][p]+=v;
        p+=p&(-p);
    }
}

int query(int p,int c){
    int sum = 0;
    while(p>0){
        sum+=bit[c][p];
        p-=p&(-p);
    }
    return sum;
}

int query(int l,int r, int c){
    return query(r,c)-query(l-1,c);
}

long long int solve(int l,int r){
    int c_odd = 0;
    int c_even = 0;
    long long int res = 1;
    for(int c=0;c<26;c++){
        int q_range = query(l,r,c);
        if(q_range%2==1)c_odd++;
        res=(res * invf[q_range/2])%MOD;
        c_even+=q_range/2;
    }
    if(c_even == 0 && c_odd == 0)return 0LL;
    res = (res * fact[c_even])%MOD;
    if(c_odd>0)res = (res * c_odd)%MOD;
    return res;
    
}

long long int fexp(long long int a,long long int b){
    if(b==0)return 1LL;
    long long int res = fexp(a,b/2);
    res = (res * res)%MOD;
    if(b%2==1)res = (res * a)%MOD;
    return res;
}

long long int inv(long long int a){
    return fexp(a,MOD-2);
}

int main() {
    fact[0] = 1;
    for (int i=1;i<=100000;i++)
        fact[i]=(fact[i-1]*i)%MOD;
    
    for(int i=0;i<=100000;i++)
        invf[i]=inv(fact[i]);
    
    
    int q,l,r;
    string s;
    cin>>s;
    for(int i=1;i<=s.length();i++)update(i,s[i-1]-'a',1);
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<solve(l,r)<<endl;
    }
    return 0;
}