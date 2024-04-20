#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
const long long INF = 1e15;

long long tree[MAXN * 4];

void makeTree() {
    for (int i = 1; i < MAXN * 4; ++i) {
        tree[i] = -INF;
    }
}
void update(int x, long long val, int u = 1, int l = 1, int r = MAXN) {
    if (l == r) {
        tree[u] = val;
        return;
    }
    int m = (l + r) / 2;
    if (x <= m) {
        update(x, val, 2 * u, l, m);
    }
    else {
        update(x, val, 2 * u + 1, m + 1, r);
    }
    tree[u] = max(tree[2 * u], tree[2 * u + 1]);
}

long long query(int x, int y, int u = 1, int l = 1, int r = MAXN) {
    if (x > r or y < l) {
        return -INF;
    }
    if (x <= l and r <= y) {
        return tree[u];
    }
    int m = (l + r) / 2;
    return max(query(x, y, 2 * u, l, m), query(x, y, 2 * u + 1, m + 1, r));
}

struct Point {
    int x, y, z, w;
    long long dp;
    bool operator < (const Point &o) const {
        return z < o.z;
    }
};
Point p[MAXN + 1];
long long DP[MAXN + 1];
int X_LIM, Y_LIM;
void merge(int l, int r) {
    int m = (l + r) / 2;

    vector<pair<int, int> > left;
    vector<pair<int, int> > right;
    for (int i = l; i <= m; ++i) {
        left.push_back({p[i].x, p[i].z});
    }       
    for (int i = m + 1; i <= r; ++i) {
        right.push_back({p[i].x, p[i].z});
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int left_l = 0;
    int left_r = -1;
    for (auto u : right) {
        int i = u.second;
        int x = u.first;
        while (left_r + 1 < left.size() and left[left_r + 1].first - x <= X_LIM) {
            ++left_r;
            int who = left[left_r].second;
            update(p[who].y, p[who].dp);            
        }
        while (left_l < left.size() and x - left[left_l].first > X_LIM) {
            int who = left[left_l].second;
            update(p[who].y, -INF);
            ++left_l;
        }
        int yLow = max(1, p[i].y - Y_LIM);
        int yHigh = min(MAXN, p[i].y + Y_LIM);
        p[i].dp = max(p[i].dp, p[i].w + query(yLow, yHigh));
    } 
    while (left_l <= left_r) {
        int who = left[left_l].second;
        update(p[who].y, -INF);
        ++left_l;
    }
}
void solve(int l, int r) {
    if (l == r) {
        p[l].dp = max(p[l].dp, (long long)p[l].w);
        return;
    }
    int m = (l + r) / 2;
    solve(l, m);
    merge(l, r);
    solve(m + 1, r);
}
int main() {
    makeTree();
    int n;
    cin >>n >> X_LIM >> Y_LIM; 
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].z >> p[i].w;
        p[i].dp = -INF;
    }
    sort(p, p + n);
    for (int i = 0; i < n; ++i) {
        p[i].z = i;
    }
    solve(0, n - 1);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, p[i].dp);
    }
    cout << ans;
}
