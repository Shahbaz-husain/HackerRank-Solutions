#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#ifdef zerol
#define dbg(args...) do { cout << "\033[32;1m" << #args << " -> "; err(args); } while (0)
#else
#define dbg(...)
#endif
const int N = 5E4 * 10 * 2, M = N;

int t[M][2], len[M] = {0}, fa[M], sz = 2, last = 1;
char* one[M];
void ins(int ch, char* pp) {
    int p = last, np = 0, nq = 0, q = -1;
    if (!t[p][ch]) {
        np = sz++; one[np] = pp;
        len[np] = len[p] + 1;
        for (; p && !t[p][ch]; p = fa[p]) t[p][ch] = np;
    }
    if (!p) fa[np] = 1;
    else {
        q = t[p][ch];
        if (len[p] + 1 == len[q]) fa[np] = q;
        else {
            nq = sz++; len[nq] = len[p] + 1; one[nq] = one[q];
            memcpy(t[nq], t[q], sizeof t[0]);
            fa[nq] = fa[q];
            fa[np] = fa[q] = nq;
            for (; t[p][ch] == q; p = fa[p]) t[p][ch] = nq;
        }
    }
    last = np ? np : nq ? nq : q;
}
int up[M], c[256] = {2}, aa[M];
vector<int> G[M];
void rsort() {
    FOR (i, 1, 256) c[i] = 0;
    FOR (i, 2, sz) up[i] = *(one[i] + len[fa[i]]);
    FOR (i, 2, sz) c[up[i]]++;
    FOR (i, 1, 256) c[i] += c[i - 1];
    FOR (i, 2, sz) aa[--c[up[i]]] = i;
    FOR (i, 2, sz) G[fa[aa[i]]].push_back(aa[i]);
}

int idx[N], clk, dfn_p, dfn[N * 2][22], rdfn[N], dep[N];
void dfs(int u) {
    idx[u] = ++clk;
    rdfn[u] = dfn_p; dfn[dfn_p++][0] = u;
    for (int& v: G[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
        dfn[dfn_p++][0] = u;
    }
}
inline int highbit(int x) { return 31 - __builtin_clz(x); }
inline int dmin(int a, int b) { return dep[a] < dep[b] ? a : b; }
void rmq_init() {
    FOR (x, 1, highbit(dfn_p) + 1)
        FOR (i, 0, dfn_p - (1 << x) + 1)
            dfn[i][x] = dmin(dfn[i][x - 1], dfn[i + (1 << (x - 1))][x - 1]);
}
int lca(int u, int v) {
    u = rdfn[u]; v = rdfn[v]; if (u > v) swap(u, v);
    int t = highbit(v - u + 1);
    return dmin(dfn[u][t], dfn[v - (1 << t) + 1][t]);
}

char s[N];
int ed[10][N], mp[N][10];
char a[10][N];
struct P { int u, c; };
P p[N][10];

int n;
int lcp(int a, int b) {
    int ret = N;
    FOR (c, 0, 10) ret = min(ret, len[lca(p[a][c].u, p[b][c].u)]);
    return min(ret, min(n - a, n - b));
}

bool cmp(int x, int y) {
    int l = lcp(x, y);
    if (x + l >= n || y + l >= n) return x > y;
    return mp[x][s[x + l] - 'a'] < mp[y][s[y + l] - 'a'];
}
int sa[N], rk[N];

int main() {
    int Qn; cin >> n >> Qn;
    scanf("%s", s);
    FOR (c, 0, 10) {
        last = 1;
        FORD (i, n - 1, -1) {
            a[c][i] = s[i] - 'a' == c ? 0 : 1;
            ins(a[c][i], &a[c][i]);
            ed[c][i] = last;
        }
    }
    rsort();
    dfs(1);
    rmq_init();
    FOR (i, 0, n) {
        FOR (c, 0, 10) p[i][c] = {ed[c][i], c};
        sort(p[i], p[i] + 10, [](const P& a, const P& b){ return idx[a.u] < idx[b.u]; });
        FOR (c, 0, 10) mp[i][p[i][c].c] = c;
    }
    FOR (i, 0, n) sa[i] = i;
    sort(sa, sa + n, cmp);
    dbg(lcp(4, 6));
    FOR (i, 0, n - 1) dbg(sa[i], sa[i + 1], lcp(sa[i], sa[i + 1]));
    FOR (i, 0, n) rk[sa[i]] = i;
    while (Qn--) {
        int L, R; scanf("%d%d", &L, &R); --L; --R;
        int len = R - L + 1;
        int l = 0, r = rk[L], ll = -1, rr = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (lcp(L, sa[m]) >= len) { ll = m; r = m - 1; }
            else l = m + 1;
        }
        l = rk[L]; r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (lcp(L, sa[m]) >= len) { rr = m; l = m + 1; }
            else r = m - 1;
        }
        dbg(ll, rr, rk[L]);
        printf("%d\n", rr - ll + 1);
    }
}