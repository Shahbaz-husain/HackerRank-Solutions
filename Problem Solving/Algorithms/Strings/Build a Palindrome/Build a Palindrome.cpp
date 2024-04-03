#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <bits/stdc++.h>



#ifndef SUFFIXARRAY_H_INCLUDED
#define SUFFIXARRAY_H_INCLUDED



class suffix_array
{
public:
    std::vector<int> suftab[2];
    std::vector<int> order;
    std::vector<int> sufarr;
    std::vector<int> bucket_count, bucket_size;
    std::vector<int> lcp; // lcp(sa[i], sa[i+1]) == sa.lcp[i]
    template<class T>
    void build_sa(T S[], int N)
    {
        suftab[0].resize(N);
        suftab[1].resize(N);
        order.resize(N);
        sufarr.resize(N);
        bucket_count.resize(N+1);
        bucket_size.resize(N+1);
        for(int i=0; i<N; i++)
            order[i]=S[i];
        std::sort(order.begin(), order.end());
        for(int i=0; i<N; i++)
            suftab[0][i]=std::lower_bound(order.begin(), order.end(), S[i])-order.begin();
        int lg=0;
        while((1<<lg)<N)
            lg++;
        int row=0;
        for(int hlen=1; hlen<(1<<lg); hlen*=2, row^=1)
        {
            bucket_count.assign(N+1, 0);
            int pos=0;
            for(int i=0; i+hlen<N; i++)
                bucket_count[suftab[row][i+hlen]+1]++;
            for(int i=N-hlen; i<N; i++)
                order[pos++]=i;
            bucket_count[0]=pos;
            std::partial_sum(bucket_count.begin(), bucket_count.end(), bucket_size.begin());
            for(int i=0; i+hlen<N; i++)
                order[bucket_size[suftab[row][i+hlen]]++]=i;
            bucket_count[0]=0;
            for(int i=0; i<hlen; i++)
                bucket_count[suftab[row][i]+1]++;
            std::partial_sum(bucket_count.begin(), bucket_count.end(), bucket_size.begin());
            for(int i=0; i<N; i++)
                sufarr[bucket_size[suftab[row][order[i]]]++]=order[i];
            int prev_a=-1, prev_b=-1, prev_c=-1;
            for(int i=0; i<N; i++)
            {
                const int x=sufarr[i];
                const int now_a=suftab[row][x];
                const int now_b=(x+hlen<N?suftab[row][x+hlen]:-1);
                prev_c+=now_a!=prev_a || now_b!=prev_b;
                suftab[row^1][x]=prev_c;
                prev_a=now_a;
                prev_b=now_b;
            }
        }
        if(row==1)
            suftab[0].swap(suftab[1]);
    }
    template<class T>
    void build(T S[], int N)
    {
        build_sa(S, N);
        lcp.resize(sufarr.size());
        for(int i=0, len=0; i<N; i++)
        {
            if(get_rank(i)==N-1)
                len=0;
            else
            {
                int j=sufarr[get_rank(i)+1];
                int maxl=N-std::max(i, j);
                while(len<maxl && S[i+len]==S[j+len])
                    len++;
                lcp[get_rank(i)]=len;
                if(len>0)
                    len--;
            }
        }
    }
    inline int get_rank(const int& idx) const
    {
        return suftab[0][idx];
    }
    int operator[] (const int& idx) const
    {
        return sufarr[idx];
    }
};

#endif // SUFFIXARRAY_H_INCLUDED

const int HASH_MAXN=400001;
const int X=129;
const int MOD1=1000000009;
const int MOD2=1000000021;
int P1[HASH_MAXN];
int P2[HASH_MAXN];

struct Hash
{
    int len, val0, val1;
    Hash():
        len(0),
        val0(0),
        val1(0)
    {
        //
    }
    Hash(int val):
        len(1),
        val0(val),
        val1(val)
    {
        //
    }
    Hash operator+ (const Hash& other) const
    {
        Hash ret;
        ret.len=len+other.len;
        ret.val0=(other.val0+1LL*P1[other.len]*val0)%MOD1;
        ret.val1=(other.val1+1LL*P2[other.len]*val1)%MOD2;
        return ret;
    }
    Hash operator- (const Hash& other) const
    {
        Hash ret;
        ret.len=len-other.len;
        ret.val0=val0-1LL*P1[len-other.len]*other.val0%MOD1;
        if(ret.val0<0)
            ret.val0+=MOD1;
        ret.val1=val1-1LL*P2[len-other.len]*other.val1%MOD2;
        if(ret.val1<0)
            ret.val1+=MOD2;
        return ret;
    }
    bool operator< (const Hash& other) const
    {
        if(len!=other.len)
            return len<other.len;
        if(val0!=other.val0)
            return val0<other.val0;
        return val1<other.val1;
    }
    bool operator== (const Hash& other) const
    {
        return len==other.len && val0==other.val0 && val1==other.val1;
    }
    bool operator!= (const Hash& other) const
    {
        return !(*this==other);
    }
};

void init_hash()
{
    P1[0]=1;
    for(int i=1; i<HASH_MAXN; i++)
        P1[i]=1LL*P1[i-1]*X%MOD1;
    P2[0]=1;
    for(int i=1; i<HASH_MAXN; i++)
        P2[i]=1LL*P2[i-1]*X%MOD2;
}

static int _hash_initialized=(init_hash(), 0);

int tlen;
int msuf[200001];
Hash H[200001];
Hash R[200001];

Hash get_substr(int l, int r)
{
    if(l==0)
        return H[r];
    return H[r]-H[l-1];
}

Hash get_r_substr(int l, int r)
{
    if(r==tlen-1)
        return R[l];
    return R[l]-R[r+1];
}

Hash get_hash(vector<pair<int, int>>& a, int l)
{
    Hash h;
    for(auto& it: a)
    {
        if(l==0)
            break;
        if(abs(it.first-it.second)+1<=l)
        {
            l-=abs(it.first-it.second)+1;
            if(it.first>it.second)
                h=h+get_r_substr(it.second, it.first);
            else
                h=h+get_substr(it.first, it.second);
        }
        else
        {
            if(it.first>it.second)
                h=h+get_r_substr(it.first-l+1, it.first);
            else
                h=h+get_substr(it.first, it.first+l-1);
            break;
        }
    }
    return h;
}

char get_char(string& t, vector<pair<int, int>>& a, int l)
{
    for(auto& it: a)
    {
        if(abs(it.first-it.second)+1<=l)
            l-=abs(it.first-it.second)+1;
        else
        {
            if(it.first>it.second)
                return t[it.first-l];
            return t[it.first+l];
        }
    }
    return '?';
}

vector<pair<int, int>> get_min(string& t, vector<pair<int, int>> a, vector<pair<int, int>> b)
{
    int la=0, lb=0;
    for(auto& it: a)
        la+=abs(it.first-it.second)+1;
    for(auto& it: b)
        lb+=abs(it.first-it.second)+1;
    assert(la==lb);
    int lo=0, mid, hi=min(la, lb);
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        if(get_hash(a, mid)==get_hash(b, mid))
            lo=mid;
        else
            hi=mid-1;
    }
    if(lo==min(la, lb) || get_char(t, a, lo)<get_char(t, b, lo))
        return a;
    return b;
}

pair<int, string> solve(string s, string t)
{
    tlen=t.length();
    reverse(s.begin(), s.end());
    string S=t+'#'+s;
    suffix_array sa;
    sa.build(S.c_str(), S.length());
    for(int i=0; i<=(int)t.length(); i++)
        msuf[i]=0;
    int len=0;
    for(int i=0; i<(int)S.length(); i++)
    {
        int suf=sa[i];
        if(suf<(int)t.length())
            msuf[suf]=max(msuf[suf], len);
        else if(suf>(int)t.length() && i+1<(int)S.length())
            len=max(len, sa.lcp[i]);
        if(i+1<(int)S.length())
            len=min(len, sa.lcp[i]);
    }
    len=0;
    for(int i=(int)S.length()-1; i>=0; i--)
    {
        int suf=sa[i];
        if(suf<(int)t.length())
            msuf[suf]=max(msuf[suf], len);
        else if(suf>(int)t.length() && i-1>=0)
            len=max(len, sa.lcp[i-1]);
        if(i-1>=0)
            len=min(len, sa.lcp[i-1]);
    }
    Hash h;
    for(int i=0; i<(int)t.length(); i++)
    {
        h=h+Hash(t[i]);
        H[i]=h;
    }
    h=Hash();
    for(int i=(int)t.length()-1; i>=0; i--)
    {
        h=h+Hash(t[i]);
        R[i]=h;
    }
    vector<pair<int, int>> ans2;
    int ans=0;
    for(int i=0; i<(int)t.length(); i++) if(msuf[i])
    {
        if(msuf[i]*2>ans)
        {
            ans=msuf[i]*2;
            ans2={{i, i+msuf[i]-1}, {i+msuf[i]-1, i}};
        }
        else if(msuf[i]*2==ans)
            ans2=get_min(t, ans2, {{i, i+msuf[i]-1}, {i+msuf[i]-1, i}});
    }
    // one center
    for(int i=0; i<(int)t.length(); i++)
    {
        int l=min(i+1, (int)t.length()-i);
        int lo=1, mid, hi=l;
        while(lo<hi)
        {
            mid=(lo+hi+1)/2;
            if(get_r_substr(i-mid+1, i)==get_substr(i, i+mid-1))
                lo=mid;
            else
                hi=mid-1;
        }
        if(msuf[i+lo])
        {
            int v=2*lo-1+2*msuf[i+lo];
            if(v>ans)
            {
                ans=v;
                ans2={{i+lo+msuf[i+lo]-1, i+lo}, {i-lo+1, i+lo+msuf[i+lo]-1}};
            }
            else if(v==ans)
                ans2=get_min(t, ans2, {{i+lo+msuf[i+lo]-1, i+lo}, {i-lo+1, i+lo+msuf[i+lo]-1}});
        }
    }
    // two centers
    for(int i=0; i<(int)t.length()-1; i++)
    {
        int l=min(i+1, (int)t.length()-(i+1));
        int lo=0, mid, hi=l;
        while(lo<hi)
        {
            mid=(lo+hi+1)/2;
            if(get_r_substr(i-mid+1, i)==get_substr(i+1, i+1+mid-1))
                lo=mid;
            else
                hi=mid-1;
        }
        if(msuf[i+1+lo])
        {
            int v=2*lo+2*msuf[i+1+lo];
            if(v>ans)
            {
                ans=v;
                ans2={{i+1+lo+msuf[i+1+lo]-1, i+1+lo}, {i-lo+1, i+1+lo+msuf[i+1+lo]-1}};
            }
            else if(v==ans)
                ans2=get_min(t, ans2, {{i+1+lo+msuf[i+1+lo]-1, i+1+lo}, {i-lo+1, i+1+lo+msuf[i+1+lo]-1}});
        }
    }
    string res="";
    for(auto& it: ans2)
    {
        if(it.first>it.second)
        {
            for(int i=it.first; i>=it.second; i--)
                res+=t[i];
        }
        else
        {
            for(int i=it.first; i<=it.second; i++)
                res+=t[i];
        }
    }
    return make_pair(ans, res);
}

string _main()
{
    string a, b;
    cin>>a>>b;
    if(a.length()<=50 and b.length()<=50)
    {
        string ans="";
        for(int la=1; la<=(int)a.length(); la++)
        {
            for(int i=0; i+la-1<(int)a.length(); i++)
            {
                for(int lb=1; lb<=(int)b.length(); lb++)
                {
                    for(int j=0; j+lb-1<(int)b.length(); j++)
                    {
                        string s=a.substr(i, la)+b.substr(j, lb);
                        string t=s;
                        reverse(t.begin(), t.end());
                        if(s==t)
                        {
                            if(s.length()>ans.length())
                                ans=s;
                            else if(s.length()==ans.length())
                                ans=min(ans, s);
                        }
                    }
                }
            }
        }
        if(ans.empty())
            return "-1";
        return ans;
    }
    auto x=solve(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    auto y=solve(b, a);
    reverse(y.second.begin(), y.second.end());
    if(max(x.first, y.first)==0)
        return "-1";
    if(x.first>y.first)
        return x.second;
    else if(x.first<y.first)
        return y.second;
    return min(x.second, y.second);
}

int main()
{
    int q;
    cin >> q;
    while(q--)
        cout<<_main()<<endl;
    return 0;
}