#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std; 

const int MAXN = 5e5, MAXX = MAXN << 1, MAXLEAVES = 1 << 19; 
char S[MAXX + 1]; int R[2][MAXX + 1], fsize, T[2][MAXX + 1]; 

void manacher(const int length, const int rx) { 
    register int i, j, k; int *table = R[rx]; 
    for (i = j = 0; i < length; i += k, j = max(j - k, 0)) { 
        while (i - j >= 0 && i + j + rx < length && S[i - j] == S[i + j + rx]) 
            ++j; 
        table[i] = j; 
        for (k = 1; k < j && table[i - k] != table[i] - k; ++k) { 
            table[i + k] = min(table[i - k], table[i] - k);
        } 
    } 
} 

int tree[(MAXLEAVES << 1) + 1], rval, ileft, iright, leaves;

void update_tree(const int x, const int left, const int right) { 
    if (ileft > right || iright < left) { return; } if (ileft <= left && right <= iright) { 
        //node completely inside the update interval 
        tree[x] = max(tree[x], rval); 
    } else { 
        int mid = (left + right) >> 1; 
        update_tree(x << 1, left, mid); 
        update_tree((x << 1) + 1, mid + 1, right); 
    } 
} 

void adjust_and_gather(const int pos, const int parity) { 
    int &ptr = R[parity][pos]; 
    int diff = (ptr << 1) - (!parity) - fsize, lx, rx, flen; 
    if (diff > 0) { 
        diff += (diff & 1);
        ptr -= diff >> 1; 
    } 
    lx = pos - ptr + 1;
    rx = pos + ptr - (parity == 0); flen = (ptr << 1) - (!parity); 
    if ((parity == 0 && ptr > 1) || (parity == 1 && ptr > 0)) { 
        T[0][lx] = max(T[0][lx], flen); T[1][rx] = max(T[1][rx], flen);
        ileft = max(0, rx - fsize + 1), iright = min(fsize - 1, lx); 
        rval = flen; 
        update_tree(1, 0, leaves - 1); 
    } 
} 

inline void process_manacher_table(const int length) { 
    for (register int i = 0; i < length; ++i) { 
        adjust_and_gather(i, 0); //odd length; 
        adjust_and_gather(i, 1); //even length; 
    } 
}

inline int read_tree(const int pos) { 
    register int x = pos + leaves; 
    int result = 1; 
    while (x) { 
        result = max(result, tree[x]);
        x >>= 1; 
    } 
    return result; 
}

inline void init_leaves(const int n) { 
    leaves = 1; while (leaves < n) 
    { 
        leaves <<= 1; 
    } 
}

int main() { 
    register int N, i, answer; 
    scanf("%d%s", &N, S); 
    memcpy(S + N, S, (N - 1) * sizeof(char)); 
    init_leaves(N); 
    fsize = N, N = (N << 1) - 1; 
    manacher(N, 0); //odd length;
    manacher(N, 1); //even length; 
    process_manacher_table(N); 
    for (i = 1; i < N; ++i) {
        T[0][i] = max(T[0][i], T[0][i - 1] - 2); 
        T[1][N - i - 1] = max(T[1][N - i - 1], T[1][N - i] - 2); 
    } 
    for (i = 0; i < fsize; ++i) { 
        answer = read_tree(i); 
        answer = max(answer, T[0][i]);
        answer = max(answer, T[1][i + fsize - 1]); 
        cout << answer << endl; 
    } 
    return 0;
}
