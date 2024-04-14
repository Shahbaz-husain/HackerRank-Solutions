#include <string.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int const N=510100;
char s[N];                          // N > 256
int n, sa[N], height[N], ranks[N], tmp[N], top[N];
void makesa()                       // O(N * log N)
{
    int i, j, len, na;
    na = (n < 256 ? 256 : n);
    memset(top, 0, na * sizeof(int));
    for (i = 0; i < n ; i++) top[ ranks[i] = s[i] & 0xff ]++;
    for (i = 1; i < na; i++) top[i] += top[i - 1];
    for (i = 0; i < n ; i++) sa[ --top[ ranks[i] ] ] = i;
    for (len = 1; len < n; len <<= 1) {
        for (i = 0; i < n; i++) {
            j = sa[i] - len; if (j < 0) j += n;
            tmp[ top[ ranks[j] ]++ ] = j;
        }
        sa[ tmp[ top[0] = 0 ] ] = j = 0;
        for (i = 1; i < n; i++) {
            if (ranks[ tmp[i] ] != ranks[ tmp[i-1] ] ||
                ranks[ tmp[i]+len ]!=ranks[ tmp[i-1]+len ])
                top[++j] = i;
            sa[ tmp[i] ] = j;
        }
        memcpy(ranks, sa , n * sizeof(int));
        memcpy(sa  , tmp, n * sizeof(int));
        if (j >= n - 1) break;
    }
}
void lcp()                          // O(4 * N)
{
    int i, j, k;
    for (j = ranks[height[i=k=0]=0]; i < n - 1; i++, k++)
        while (k >= 0 && s[i] != s[ sa[j-1] + k ])
            height[j] = (k--), j = ranks[ sa[j] + 1 ];
}

int len[N];
int main()
{
    memset(sa,0,sizeof(sa));
    memset(height,0,sizeof(height));
    memset(len,0,sizeof(len));
    int m,q,i,j,k;
    cin >> m;
    s[0]=0;
    char str[2010];
    for (i=0,j=0;i<m;i++)
    {
        cin >> str;
        for (k=0;str[k];k++)
        {
            s[j++]=str[k];
        }
        s[j++]=i+2;
    }
    s[j]='A'-1;
    n=j+1;
    makesa();
    lcp();
    for (i=n-1,j=0;i>=0;i--)
    {
        if (s[i]<'A')
            j=0;
        else
            j++;
        len[i]=j;    
    }
    int sum=0;
    for (i=0;i<n;i++)
    {
        sum+=len[sa[i]]-height[i];
    }
    map<int,int>::iterator it;
    cin >> q;
    while (q--)
    {
        cin >> m;
        if (m>sum||m<1)
        {
            printf("INVALID\n");
        }
        else
        {
            for (i=1,j=0;(j+=len[sa[i]]-height[i])<m;i++);
            while (sa[i]<0||sa[i]>n+1)
            {
            }
            j=len[sa[i]]-(j-m);
            i=sa[i];
            while (j--)
            {
                putchar(s[i]);
                i++;
            }
            puts("");
        }
    }
}