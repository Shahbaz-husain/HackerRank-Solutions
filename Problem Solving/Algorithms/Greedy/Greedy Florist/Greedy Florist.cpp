#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {
    int ans = 0, n = c.size();
    
    // sorting the flowers prices so that can be traveresed in descending order to max the profit
    sort(c.begin(), c.end());
    
    // variable to store the last buy flower count initialized to 0
    int count = 0;
    
    // variable to store the index of the current friend who's buying the flower initialized to first one
    int curr_friend = 1;
    
    // traversing the flowers from the end to maximize the profit
    for(int i = n-1; i>=0; i--){
        
        // if current friend is first one , then increase last flower bought count
        if(curr_friend == 1)
            count++;
        
        ans += count*c[i];
        
        // if current friend reaches last friend , then again point towards the first friend
        if(curr_friend++ == k)
            curr_friend = 1;
    }
    
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> flowers(n);
    for(int i = 0; i < n; i++)
        cin >> flowers[i];
        
    cout << getMinimumCost(k, flowers);
}