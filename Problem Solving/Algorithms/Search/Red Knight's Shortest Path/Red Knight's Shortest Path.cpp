#include <string.h>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int dx[] = {-1, 1, 2, 1, -1, -2};
int dy[] = {-2, -2, 0, 2, 2, 0};

int from[210][210];
int N;
int yt, xt;
char moveNames[][5] = {"UL", "UR", "R", "LR", "LL", "L"};

queue<int> q;
stack<int> moves;

int main(){
    memset(from, -1, sizeof(from));
    int yf, xf;
    
    scanf("%d", &N);
    scanf("%d %d %d %d", &yf, &xf, &yt, &xt);
    
    q.push(yf*1000 + xf);
    from[yf][xf] = 10;
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        xf = now % 1000;
        yf = now / 1000;
        if(xf == xt && yf == yt) 
            break;
        
        for(int i=0; i<6; i++){
            int nx = xf + dx[i];
            int ny = yf + dy[i];
            if(nx < 0) 
                continue;
            if(ny < 0) 
                continue;
            if(nx >= N) 
                continue;
            if(ny >= N) 
                continue;
            
            if(from[ny][nx] == -1){
                from[ny][nx] = i;
                q.push(ny*1000 + nx);
            }
        }
    }
    
    if(xf == xt && yf == yt){
        while(from[yf][xf] != 10){
            moves.push(from[yf][xf]);
            int ny = yf - dy[from[yf][xf]];
            int nx = xf - dx[from[yf][xf]];
            yf = ny;
            xf = nx;
        }
        
        cout << moves.size() << endl;
        while(!moves.empty()){
            int mo = moves.top();
            moves.pop();
            cout << moveNames[mo];
            if(moves.empty()) 
                cout << endl;
            else 
                cout << " ";
        }
    }
    else{
        cout << "Impossible" << endl;
    }
}