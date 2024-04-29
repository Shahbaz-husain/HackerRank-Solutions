#include<iostream>
#include<vector>
using namespace std;
vector<int> graph[110001];
int T, N, deg[100001] = {0};
long long ST[100001*4] = {0};

void update(int node, int b, int e, int idx, int val)  {

    if(b > node || e < node) 
        return;

    if(b == e) {
        ST[idx] += val;
        return;
    }

    int m = (b + e) >> 1;
    int q = idx << 1;
    update(node, b, m, q, val);
    update(node, m + 1, e, q + 1, val);

    ST[idx] = ST[q]  + ST[q+1];

}

long long Query(int l, int r, int b, int e, int idx) {

    if( l > e || r < b) 
        return 0;

    if(l <= b && r >= e) 
        return ST[idx];

    int m = (b + e) >> 1;
    int q = idx << 1;
    return Query(l, r, b, m, q) + Query(l, r, m + 1, e, q + 1);
}

long long SimilarPairs(int node) {

    int l = max(1, node - T), r  = min(N, node + T);
    long long res = 0;

    res = Query(l, r, 1, N, 1);
    update(node, 1, N, 1, 1);

    for(int i = 0; i < graph[node].size(); i++) {
       res +=  SimilarPairs(graph[node][i]);
    }

    update(node, 1, N, 1, -1);
    return res;
}

int main() {

    long x, y, root, start;
    cin >> N >> T;

    for(int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        deg[y]++;
    }

    for(int i = 1; i <= N; i++) 
        if(!deg[i]) 
            root = i;

    long long result = SimilarPairs(root);
    cout << result << endl;
}