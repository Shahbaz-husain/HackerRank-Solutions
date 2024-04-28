#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    int n,query,x;
    long long ans=0,qsum=0;
    cin >> n;
    int a[n+1];
    long long sum[n+1];
    sum[0]=0;
    for(int i=1; i<=n; i++)
    {
     cin >> a[i];
    }
    cin >> query;
    int en,st,mid;
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++)
    sum[i]=sum[i-1]+a[i];
    while(query--)
    {
        cin >> x;
        qsum+=x;
        st=0;
        en=n+1;
        while(en-st>1)
            {
                mid=(en+st)/2;
                if
                    (a[mid]+qsum>=0) en=mid;
                else 
                    st=mid;
            }
            ans=-sum[en-1]-(en-1)*qsum+sum[n]-sum[en-1]+(n-en+1)*qsum;
            cout << ans << endl;
    }
}