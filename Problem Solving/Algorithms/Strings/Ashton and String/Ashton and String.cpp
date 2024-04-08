#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100005;
typedef long long LL;
int n, k, sa[MAX_N], rk[MAX_N], lcp[MAX_N], tmp[MAX_N];

bool compare_sa(int i, int j) {
    if (rk[i] != rk[j]) return rk[i] < rk[j];
    int ri = i + k <= n ? rk[i + k] : -1;
    int rj = j + k <= n ? rk[j + k] : -1;
    return ri < rj;
}

void construct_sa(const string &S, int *sa) {
    n = S.length();
    for (int i = 0; i <= n; i++) {
        sa[i] = i;
        rk[i] = (i < n ? S[i] : -1);
    }
    
    for (k = 1; k <= n; k *= 2) {
        sort(sa, sa + n + 1, compare_sa);
        
        tmp[sa[0]] = 0;
        for (int i = 1; i <= n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i <= n; i++) rk[i] = tmp[i];
    }
}

void construct_lcp(const string &S, int *sa, int *lcp) {
    n = S.length();
    for (int i = 0; i <= n; i++) rk[sa[i]] = i;
    
    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; i++) {
        int j = sa[rk[i] - 1];
        
        if (h > 0) h--;
        for (; i + h < n && j + h < n; h++) if (S[i + h] != S[j + h]) break;
        
        lcp[rk[i] - 1] = h;
    }
} 

string S;

void solve(LL k) {
    n = S.length();
    construct_sa(S, sa);
    construct_lcp(S, sa, lcp);   
    
    for (int i = 0; i < n; i++) {
        int L = lcp[i];
        int left = n - sa[i + 1];
        LL sum = (L + 1 + left) * (LL)(left - L) / 2;
        if (k > sum) {k -= sum;}
        else {
            for (int j = L + 1; j <= left; j++) {
                if (k <= j) {
                   int index = sa[i + 1] + k;
                   cout << S[index - 1] << endl;
                   return ;
                } else {
                    k -= j;
                }
            }
        }
    }
}
int main(void) {
    int T;
    cin >> T;
    while (T--) {
        LL k;
        cin >> S >> k;
        solve(k);
    }
    return 0;
}