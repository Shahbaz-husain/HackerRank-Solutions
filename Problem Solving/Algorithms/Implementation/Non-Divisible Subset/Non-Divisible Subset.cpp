#include <bits/stdc++.h>

using namespace std;

// Using Remainder Frequency Algorithms

int nonDivisibleSubset(int k, vector<int> arr)
{
    int result = 0;
    // Taking a vector to store the remainders frequency
    vector<int> remainders(k,0);
    for(int elem : arr)
    {
        // storing the remainders frequency
        int rem = elem%k;
        remainders[rem]++;
    }
    for(int i = 0; i <= k/2; i++)
    {
        // In case of 0 , will only take 1 elem if there's any record
        if(i == 0){
            if(remainders[i] > 0)
                result++;
        }
    
        // half of k case (will only happen at the mid remainder eg 5 for 10 , 2 for 4) here also will only take one element because half + half = full eg 15 + 25 = 40 % 10 == 0;
        else if(i == k-i){
            if(remainders[i] > 0)
                result++;
        }
        
        // Else we'll take the max number of alternate elements frequencies, for eg : 1 and 9 remainder elements : 1 + 9 = 10 , so we'll only take one type elements so that they don't sum up to k
        else{
            int count = max(remainders[i], remainders[k-i]);
            result += count;
        }
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int result = nonDivisibleSubset(k, arr);
    
    cout << result << endl;
}