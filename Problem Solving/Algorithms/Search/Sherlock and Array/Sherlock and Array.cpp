#include <iostream>
#include <vector>

using namespace std;

string balancedSums(vector<int> arr){
    int n = arr.size();
    
    // vectors to store the left and right sums from each index
    vector<int> leftSum(n),rightSum(n);
    
    // from 0th index left sum will be 0
    leftSum[0]=0;
    
    // from n-1 index right sum will be 0
    rightSum[n-1]=0;
    
    // storting the left sums retrieved upto current index in each iteration
    for(int i=1;i < n;i++)
    {
        leftSum[i]=arr[i-1]+leftSum[i-1];
    }
    
    // storting the right sums retrieved from current to end index in each iteration
    for(int i=n-2; i >=0;i--)
    {
        rightSum[i]=rightSum[i+1]+arr[i+1];
    }
    
    // if any sum is equal returning Yes
    for(int i=0; i < n;i++)
    {
        if(leftSum[i]==rightSum[i])
            return "YES";
    }
    
    // else no
    return "NO";
}

int main(){
    int t , n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
            
        cout<< balancedSums(arr) << endl;
    }
}