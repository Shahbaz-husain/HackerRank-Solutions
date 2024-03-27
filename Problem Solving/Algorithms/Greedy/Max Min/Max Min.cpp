#include <bits/stdc++.h>

using namespace std;

int maxMin(int k, vector<int> arr) {
    // initializing ans varianle with int max value because we want the min result
    int ans = INT_MAX;
    
    // sorting the array so that the result stays positive and selection becomes easy
    sort(arr.begin(), arr.end());
    
    // Starting from k - 1 because after sorting it will be the first max value of arr'
    // And the min will start from 0th index till n - k 
    
    // Eg : 1 4 7 9   k = 2
    // max_ind (k - 1) = 1 ... 2 ... 3    max = 4 ... 7 .... 9
    // min_ind = 0 ... 1 ... 2            min = 1 ... 4 .... 7
    for(int max_ind = k - 1, min_ind = 0; max_ind < arr.size(); max_ind++, min_ind++ ){
        ans = min(arr[max_ind] - arr[min_ind], ans);
    }
    
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << maxMin(k, arr);
}