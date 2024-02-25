#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// max string size according to constraints
const int maxsize=5001;

int main(){
    char a[maxsize],b[maxsize];
    // inputting string from the 1st index instead of 0
    cin >> a+1 >> b+1;
    int n = 0;
    
    // finding the size of the filled array
    while(a[n+1] != '\0')
        n++;
    
    // Taking a double vector to track the count of max size substring
    vector<vector<int>> dp(maxsize , vector<int>(maxsize,0));
        
    // calculating the max size substring 
    for(int i = 1; i <=n; i++) 
        for(int j = 1; j <= n ; j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j]) 
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    }
    cout << dp[n][n];
    return 0;
}
