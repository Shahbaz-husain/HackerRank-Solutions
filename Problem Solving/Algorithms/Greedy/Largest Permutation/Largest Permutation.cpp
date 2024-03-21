#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> largestPermutation(int k, vector<int> arr) {
    vector<int> valueindex(arr.size()+1);
    
    // Storing numbers according to their indices in arr
    for(int i = 0; i < arr.size(); i++){
        valueindex[arr[i]] = i;
    }
    
    for(int i = arr.size(); i>= 1 and k > 0; i--){
        int update_index = arr.size() - i;
        if(update_index == valueindex[i]) continue;
        
        int index_of_max_num = valueindex[i];
        
        // Swapping indices of current index and the index at which we want to place max number
        swap(valueindex[i], valueindex[arr[update_index]]);
        
        // Swapping max number with the update_pos index number
        swap(arr[index_of_max_num], arr[update_index]);
        k--;
    }
    
    return arr;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<int> result = largestPermutation(k,arr);
    for(int el : result)
        cout << el << " ";
}