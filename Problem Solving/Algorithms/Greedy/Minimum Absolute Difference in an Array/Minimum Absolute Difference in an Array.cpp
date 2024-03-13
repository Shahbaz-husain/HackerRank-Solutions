#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumAbsoluteDifference(vector<int> arr){
    sort(arr.begin(), arr.end());
    int ans = abs(arr[1] - arr[0]);
    for(int i = 1; i < arr.size(); i++)
        ans = min(ans, abs(arr[i] - arr[i - 1]));
    
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << minimumAbsoluteDifference(arr);
}