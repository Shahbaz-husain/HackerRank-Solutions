#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int toys(vector<int> weights){
    int count = 0;
    
    // sorting the weights
    sort(weights.begin(), weights.end());
    
    // Initializing next index k and the range varible which will store current range
    int k = 0, i = 0;
    int range = weights[0] + 4;
    
    // while every next index is in weights limit
    while(k < weights.size()){
        
        // if current weight is in current range .... continuing
        if(weights[i] <= range)
            i++;
            
        // else incrementing toys count and setting next index and new range
        else{
            count++;
            k = i;
            range = weights[k] + 4;
        }
    }
    
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> weights(n);
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    
    cout << toys(weights);
}