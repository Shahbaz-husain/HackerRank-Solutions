#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> missingNumbers(vector<int> arr1, vector<int> arr2){
    vector<int> result;
    
    // unordered map to count the freq of each number
    unordered_map<int, int> attend;
    
    // counting frequencies of the complete array
    for(int n : arr2)
        attend[n]++;
    
    // substracting freq of each number present in the incomplete array
    for(int n : arr1){
        attend[n]--;
    }
    
    // which number's frequency is more than 0 , that number is missing from the incomplete array 
    for(auto pair: attend){
        
        // pushing incomplete array numbers into our result
        if(pair.second != 0)
            result.push_back(pair.first);
    }
    
    // sorting the result as output is expected in sorted order
    sort(result.begin(),result.end());
    
    return result;
}

int main()
{
    int n , m;
    cin >> n;
    vector<int> arr1(n);
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
        
    cin >> m;
    vector<int> arr2(m);
    for(int i = 0; i < m; i++)
        cin >> arr2[i];
        
    vector<int> result = missingNumbers(arr1,arr2);
    
    for(int el : result)
        cout << el << " ";
}