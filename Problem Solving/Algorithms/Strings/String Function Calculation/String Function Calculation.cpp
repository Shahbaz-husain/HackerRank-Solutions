#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define maxn 100010

int wa[maxn] = {};
int wb[maxn] = {};
int wv[maxn] = {}; 
int height[maxn] = {};
int r[maxn] = {};
int sa[maxn] = {};
int wws[maxn] = {};
int rrank[maxn] = {};

int cmp(int *r,int a,int b,int l) {
    return r[a]==r[b] and r[a+l]==r[b+l];
} 

void da(int *r,int *sa,int n,int m) {
    int i,j,p,*x=wa,*y=wb,*t;
    
    for(i=0;i<m;i++) 
        wws[i]=0;
    
    for(i=0;i<n;i++) 
        wws[x[i]=r[i]]++;
        
    for(i=1;i<m;i++) 
        wws[i]+=wws[i-1];
        
    for(i=n-1;i>=0;i--) 
        sa[--wws[x[i]]]=i;
        
    for(j=1,p=1;p<n;j*=2,m=p) {
        
        for(p=0,i=n-j;i<n;i++) 
            y[p++]=i;
            
        for(i=0;i<n;i++) 
            if(sa[i]>=j) 
                y[p++]=sa[i]-j;
        
        for(i=0;i<n;i++) 
            wv[i]=x[y[i]];
            
        for(i=0;i<m;i++) 
            wws[i]=0;
            
        for(i=0;i<n;i++) 
            wws[wv[i]]++;
            
        for(i=1;i<m;i++) 
            wws[i]+=wws[i-1];
            
        for(i=n-1;i>=0;i--) 
            sa[--wws[wv[i]]]=y[i];
            
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
            
    }
    return; 
}

void calheight(int *r,int *sa,int n) {
    int i,j,k=0;
    
    for(i=1;i<=n;i++) 
        rrank[sa[i]]=i;
        
    for(i=0;i<n;height[rrank[i++]]=k)
        for(k?k--:0,j=sa[rrank[i]-1];r[i+k]==r[j+k];k++);
            
    return;
}

int find(int n) {
    stack<int> s;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        while(!s.empty() and height[s.top()] > height[i]) {
            int h = height[s.top()];
            s.pop();
            int index = s.empty()?0:s.top();
            res = max(res, (i-index)*h);
        }
        s.push(i);
    }
    return res;
}

int main() {
    string ss;
    cin >> ss;
    int l = ss.size();
    for(int i = 0; i < l; i++) {
        r[i] = ss[i]-'a'+1;
    }
    da(r, sa, l+1, 27);
    calheight(r, sa, l);
    cout <<  max(find(l+1), l) ;
    return 0;
}