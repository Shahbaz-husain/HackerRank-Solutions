#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int inf=1000000000;
struct suffix
{
    int s1,s2,poz;
    bool operator <(const suffix &aux) const
    {
        if(s1==aux.s1) return s2<aux.s2;
        else return s1<aux.s1;
    }
    bool operator ==(const suffix &aux) const
    {
        return s1==aux.s1 && s2==aux.s2;
    }
}s[30010];
struct arbint
{
    int minn,lazy;
}arb[200010];
int p[17][30010],logg[30010],pas[30010];
int poz[30010],st[30010],dr[30010],rmq[17][30010],n,sol;
char sir[30010];

int LCP(int x,int y)
{
    int rez=0;
    for(int i=logg[n];i>=0 && x<=n && y<=n;i--)
        if(p[i][x]==p[i][y]) {rez+=1<<i;x+=1<<i;y+=1<<i;}
    return rez;
}

void arbint_init(int nod,int st,int dr)
{
    arb[nod].minn=arb[nod].lazy=inf;
    if(st==dr) return;
    int mid=(st+dr)/2;
    arbint_init(nod*2,st,mid);
    arbint_init(nod*2+1,mid+1,dr);
}

void update(int nod,int st,int dr)
{
    arb[nod].minn=min(arb[nod].minn,arb[nod].lazy);
    if(st<dr)
    {
        arb[nod*2].lazy=min(arb[nod*2].lazy,arb[nod].lazy);
        arb[nod*2+1].lazy=min(arb[nod*2+1].lazy,arb[nod].lazy);
    }
}

void arbint_update(int nod,int st,int dr,int left,int right,int val)
{
    if(left<=st && dr<=right)
    {
        arb[nod].lazy=min(arb[nod].lazy,val);
        update(nod,st,dr);
        return;
    }
    update(nod,st,dr);
    int mid=(st+dr)/2;
    if(left<=mid) arbint_update(nod*2,st,mid,left,right,val);
    else update(nod*2,st,mid);
    if(mid<right) arbint_update(nod*2+1,mid+1,dr,left,right,val);
    else update(nod*2+1,mid+1,dr);
    arb[nod].minn=min(arb[nod*2].minn,arb[nod*2+1].minn);
}

void arbint_query(int nod,int st,int dr,int poz)
{
    update(nod,st,dr);
    if(st==dr)
    {
        sol=arb[nod].minn;
        return;
    }
    int mid=(st+dr)/2;
    if(poz<=mid) arbint_query(nod*2,st,mid,poz);
    else arbint_query(nod*2+1,mid+1,dr,poz);
}

int get_min(int x,int y)
{
    int lim=logg[y-x+1];
    return min(rmq[lim][x],rmq[lim][y-(1<<lim)+1]);
}

int main()
{
    int t;
    for(cin >> t;t;t--)
    {
        int cost1,cost2;
        scanf("%d%d%d\n%s",&n,&cost1,&cost2,sir+1);
        for(int i=2;i<=n;i++) logg[i]=logg[i/2]+1;
        for(int i=1;i<=n;i++)
        {
            p[0][i]=sir[i];
            s[i].poz=i;
        }
        for(int i=1;i<=logg[n]+1;i++)
        {
            for(int j=1;j<=n;j++)
            {
                s[j].s1=p[i-1][s[j].poz];
                if(s[j].poz+(1<<(i-1))<=n) s[j].s2=p[i-1][s[j].poz+(1<<(i-1))];
                else s[j].s2=-1;
            }
            sort(s+1,s+n+1);
            for(int j=1;j<=n;j++)
                if(j>1 && s[j]==s[j-1]) p[i][s[j].poz]=p[i][s[j-1].poz];
                else p[i][s[j].poz]=j;
        }
        for(int i=1;i<=n;i++) rmq[0][i]=s[i].poz;
        for(int i=1;i<=logg[n];i++)
        {
            int lim=n-(1<<(i-1))+1;
            for(int j=1;j<=lim;j++) rmq[i][j]=min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
        }
        for(int i=1;i<=n;i++)
        {
            int st=1,dr=min(n-s[i].poz+1,s[i].poz-1);
            while(st<=dr)
            {
                int mid=(st+dr)/2,ok=0;
                int l=1,r=i-1;
                while(l<=r)
                {
                    int m=(l+r)/2;
                    if(get_min(m,i)<=s[i].poz-mid) 
                        l=m+1;
                    else 
                        r=m-1;
                }
                int a=r;
                l=i+1;r=n;
                while(l<=r)
                {
                    int m=(l+r)/2;
                    if(get_min(i,m)<=s[i].poz-mid) 
                        r=m-1;
                    else 
                        l=m+1;
                }
                int b=l;
                if(1<=a && LCP(s[a].poz,s[i].poz)>=mid) 
                    ok=1;
                if(b<=n && LCP(s[b].poz,s[i].poz)>=mid) 
                    ok=1;
                if(ok) 
                    st=mid+1;
                else 
                    dr=mid-1;
            }
            pas[s[i].poz]=dr;
        }
        arbint_init(1,1,n);
        arbint_update(1,1,n,1,1,cost1);
        for(int i=1;i<n;i++)
        {
            arbint_query(1,1,n,i);
            if(pas[i+1]) 
                arbint_update(1,1,n,i+1,i+pas[i+1],sol+cost2);
            arbint_update(1,1,n,i+1,i+1,sol+cost1);
        }
        arbint_query(1,1,n,n);
        cout << sol << endl;
    }
    return 0;
}