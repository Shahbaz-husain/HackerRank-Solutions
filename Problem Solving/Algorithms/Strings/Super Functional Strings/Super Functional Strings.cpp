#include <bits/stdc++.h>
using namespace std ;

#define ft first
#define sd second
#define pb push_back
#define all(x) x.begin(),x.end()

#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define mp make_pair
#define ms(A, v) memset(A, v, sizeof A)

#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define scll1(x) scanf("%lld",&x)
#define scll2(x,y) scanf("%lld%lld",&x,&y)
#define scll3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define pr1(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)

#define prll1(x) printf("%lld\n",x)
#define prll2(x,y) printf("%lld %lld\n",x,y)
#define prll3(x,y,z) printf("%lld %lld %lld\n",x,y,z)

#define pr_vec(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;

#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

const int mod = 1e9 + 7;
const int maxn = 500100;

char txt[ maxn ];
int iSA[maxn], SA[maxn]; //output
int cnt[maxn], next_gen[maxn], lcp[maxn], LCP[maxn][22]; //internal
bool bh[maxn], b2h[maxn];
int len;

void reset( int len ) {
    int i; fr(i, 0, len) {
        iSA[i] = 0;
        SA[i] = 0;
        cnt[i] = 0;
        next_gen[i] = 0;
        lcp[i] = 0;
        ms(LCP[i], 0);
        bh[i] = 0;
        b2h[i] = 0;
    }
}

bool smaller_first_char(int a, int b){
    return txt[a] < txt[b];
}

void SuffixSort(int n) {
    for (int i=0; i<n; ++i){
        SA[i] = i;
    }
    sort(SA, SA + n, smaller_first_char);
    for (int i=0; i<n; ++i){
        bh[i] = i == 0 || txt[SA[i]] != txt[SA[i-1]];
        b2h[i] = false;
    }
    for (int h = 1; h < n; h <<= 1){
        int buckets = 0;
        for (int i=0, j; i < n; i = j){
            j = i + 1;
            while (j < n && !bh[j]) j++;
            next_gen[i] = j;
            buckets++;
        }
        if (buckets == n) break;
        for (int i = 0; i < n; i = next_gen[i]){
            cnt[i] = 0;
            for (int j = i; j < next_gen[i]; ++j){
                iSA[SA[j]] = i;
            }
        }
        cnt[iSA[n - h]]++;
        b2h[iSA[n - h]] = true;
        for (int i = 0; i < n; i = next_gen[i]){
            for (int j = i; j < next_gen[i]; ++j){
                int s = SA[j] - h;
                if (s >= 0){
                int head = iSA[s];
                iSA[s] = head + cnt[head]++;
                b2h[iSA[s]] = true;
                }
            }

            for (int j = i; j < next_gen[i]; ++j){
                int s = SA[j] - h;
                if (s >= 0 && b2h[iSA[s]]){
                    for (int k = iSA[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
                }
            }
        }

        for (int i=0; i<n; ++i){
            SA[iSA[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    for (int i=0; i<n; ++i){
        iSA[SA[i]] = i;
    }
}

void InitLCP(int n) {
    for (int i=0; i<n; ++i) 
        iSA[SA[i]] = i;
    lcp[0] = 0;
    for (int i=0, h=0; i<n; ++i)
    {
        if (iSA[i] > 0)
        {
            int j = SA[iSA[i]-1];
            while (i + h < n && j + h < n && txt[i+h] == txt[j+h]) 
                h++;
            lcp[iSA[i]] = h;
            if (h > 0) 
                h--;
        }
    }
}

void ConstructLCP() {
    InitLCP( len );
    for(int i = 0;i<len;++i)
        LCP[i][0] = lcp[i];
    for(int j = 1;(1<<j)<=len;++j){
        for(int i = 0;i+(1<<j)-1<len;++i){
            if(LCP[i][j-1]<=LCP[i+ ( 1<<(j-1) )][j-1])
                LCP[i][j] = LCP[i][j-1];
            else
                LCP[i][j] = LCP[i+(1<<(j-1))][j-1];
        }
    }
}

int GetLCP(int x, int y) {
    if(x == y) return len-SA[x];
    if(x > y) swap(x,y);
    int log = 0;
    while((1<<log)<=(y-x)) ++log;
    --log;
    return min(LCP[x+1][log],LCP[y-(1<<log)+1][log]);
}

const int maxm = 1e5 + 10;
int val[30][maxm];

void pre() {
    int i, j;
    fr(i, 1, 100000) {
        int v = 1;
        fr(j, 0, 26) {
            val[j][i] = v;
            v = 1LL * v * i % mod;
        }
    }
    fr(i, 1, 26) {
        fr(j, 1, 100000) {
            val[i][j] += val[i][j-1];
            if( val[i][j] >= mod ) {
                val[i][j] -= mod;
            }
        }
    }
}

int get(int l, int r, int d) {
    if( r < l ) return 0;
    int v = val[d][r] - val[d][l-1];
    if( v < 0 ) v += mod;
    return v;
}

char s[ maxm ];

int dp[ 30 ][ maxm ];

void solve() {
    pre();
    int t; sc1( t );
    while( t-- ) {
        scanf("%s", txt);
        len = strlen(txt);
        reset( len );
        SuffixSort( len );
        ConstructLCP();
        int i, j;

        fr(i, 0, len) 
            fr(j, 1, 26) 
                dp[j][i] = -1;

        fb(i, len-1, 0) {
            fr(j, 1, 26) dp[j][i] = dp[j][i+1];
            dp[txt[i]-'a'+1][i] = i;
        }

        int ans = 0;
        vi b;
        fr(j, 1, 26) {
            if(dp[j][SA[0]] != -1 )
                b.pb(dp[j][SA[0]]);
        }
        b.pb(len);
        sort(all(b));
        int sz = b.size();
        fr(j, 1, sz-1) {
            ans += get(b[j-1]-SA[0]+1, b[j]-SA[0], j);
            if( ans >= mod ) ans -= mod;
        }

        fr(i, 1, len-1) {
            b.clear();
            fr(j, 1, 26) {
                if(dp[j][SA[i]] != -1 )
                    b.pb(dp[j][SA[i]]);
            }
            b.pb(len);
            sort(all(b));
            int sz = b.size();
            fr(j, 1, sz-1) {
                ans += get(max(lcp[i], b[j-1]-SA[i])+1, b[j]-SA[i], j);
                if( ans >= mod ) ans -= mod;
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    solve();
    return 0;
}
