#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumLoss(vector<long long> arr){
    long long ans = 10000000;
    vector<pair<long long, int>> index(arr.size());
    
    // Storing the indices of the prices , so that later we can find the difference of prices in proper order
    // For Eg :
    // 5 10 3 <- after sort -> 3 5 10 <- here we have lost the days indices that which day came first that's why need to store the indices of the days before sorting them
    for(int i = 0; i < arr.size(); i++)
    {
        index[i].first = arr[i];
        index[i].second = i;
    }
    
    sort(index.begin(), index.end());
    
    // Calculating the min difference of the consecutive days only on the basis of their indices
    for(int i = 1; i < arr.size(); i++){
        if(index[i].second < index[i-1].second){
            ans = min(ans , index[i].first - index[i-1].first);
        }
    }
    
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << minimumLoss(arr);
}