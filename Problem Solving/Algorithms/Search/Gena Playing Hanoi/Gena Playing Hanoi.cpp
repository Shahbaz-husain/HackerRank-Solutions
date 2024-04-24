#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int Maxn = 10;
const int Inf = 1000000000;

int n;
int dp[1 << 2 * Maxn];

int Get(int mask, int ind)
{
    return (mask & 3 << 2 * ind) >> 2 * ind;    
}

int Set(int mask, int ind, int val)
{
    int got = mask & 3 << 2 * ind;
    mask ^= got;
    mask |= val << 2 * ind;
    return mask;
}

int main(){
    cin >> n;
    fill(dp, dp + (1 << 2 * Maxn), Inf);
    int got = 0;
    for (int i = 0; i < n; i++) {
        int a; 
        cin >> a; 
        a--;
        got |= a << 2 * i;
    }
    dp[got] = 0;
    queue <int> Q; Q.push(got);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        bool tk[4] = {};
        for (int i = 0; i < n; i++) {
            int my = Get(v, i);
            if (tk[my]) 
                continue;
            for (int j = 0; j < 4; j++) 
                if (my != j && !tk[j]) {
                    int u = Set(v, i, j);
                    if (dp[v] + 1 < dp[u]) {
                        dp[u] = dp[v] + 1;
                        Q.push(u);
                    }
                }
            tk[my] = true;
        }
    }
    cout << dp[0];
    return 0;
}