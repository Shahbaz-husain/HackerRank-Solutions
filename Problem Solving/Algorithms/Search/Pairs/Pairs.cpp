#include <iostream>
#include <vector>
#include <unordered_set>

using namespace  std;

// Using Reverse Difference Technique
// To find the pair whose sum equals to a given target
// Solution Logic :
// Instead of iterating over all the elements and finding difference of all tha pairs
// More efficient way is to check whether the counterpart of the element is present in the array or not, if it's there , that means using those two elements we can get the pair

int pairs(int k, vector<long long> arr){
    // Variable to store the result
    int count = 0;
    
    // Using set to store the unqiue values in the array
    unordered_set<long long> unique(arr.begin(), arr.end());
    
    // for each element of the array
    for(long long el : arr)
    {
        // if the counterpart of the current element is present in the set , increasing the count
        long long counterpart = el - k;
        if(unique.count(counterpart))
            count++;
    }
    return count;
}

int main(){
    int  n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(long long i = 0; i < n;i++)
    {
        cin >> arr[i];
    }
    
    cout << pairs(k, arr);
}
