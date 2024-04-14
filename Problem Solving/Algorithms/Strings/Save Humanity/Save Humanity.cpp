#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MaxN = 200005;

void e_kmp(char *s, char *t, int *has, int *e_has)
{
    int sp, p, mx, tn;
    for (sp = p = mx = 0; s[p] > 0; p++)
    {
        if (mx == p || p + e_has[p - sp] >= mx)
        {
            for (tn = mx - p; s[mx] == t[tn]; tn++)
                mx++;
            has[sp = p] = mx - p;
            if (mx == p)
                sp = mx = p + 1;
        }
        else
            has[p] = e_has[p - sp];
    }
}
char s[MaxN],t[MaxN];
int A[MaxN],B[MaxN],A2[MaxN],B2[MaxN];
int ans[MaxN],n,m;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> s >> t;
        n = strlen(s), m = strlen(t);
        t[m] = -1;
        A[0] = m;
        e_kmp(t+1,t,A+1,A);
        e_kmp(s,t,B,A);
        reverse(s,s+n);
        reverse(t,t+m);
        A2[0] = m;
        e_kmp(t+1,t,A2+1,A2);
        e_kmp(s,t,B2,A2);

        int cnt = 0;
        for(int i = 0; i+m-1 < n; i++)
        {
            if(B[i]>=m || B2[n-(i+m)]+B[i]>=m-1)
                ans[cnt++] = i;
        }
        for(int i = 0; i < cnt; i++){
           cout << ans[i] << ' ';
            if(i==cnt-1)
                cout << endl;
        }
        if(cnt==0)puts("No Match!");
    }

    return 0;
}