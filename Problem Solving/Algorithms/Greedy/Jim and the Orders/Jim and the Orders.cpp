#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> jimOrders(vector<vector<int>> orders) {
    // Taking a vector of pairs to assign index to each order and serve time pair
    vector<pair<int, int>> pairs;
        
    // Assigning index to each pair starting from 1 to n and 
    for(int i = 0; i < orders.size(); i++){
        pairs.push_back({orders[i][0] + orders[i][1], i+1 });
    }
    
    // Sorting the pairs on the basis of the sum of order num and serve time
    sort(pairs.begin(), pairs.end());
    
    // Stroring the resultant order in the result vector
    vector<int> result;
    for(auto p : pairs)
        result.push_back(p.second);
        
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> orders(n, vector<int>(2));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            cin >> orders[i][j];
        }
    }
    
    vector<int> result = jimOrders(orders);
    for(int el : result)
        cout << el << " ";
}