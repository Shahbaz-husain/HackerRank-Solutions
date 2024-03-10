#include <iostream>
#include <vector>
#include <set>

using namespace std;

long maximumSum(vector<long> arr, long m){
    long curr_sum = 0, max_sum = 0;
    set<long> mod;
    for (int i = 0; i < arr.size(); i++)
    {
        // Finding modulo sum till current index.
        curr_sum = (curr_sum + arr[i])%m;

        // Finding maximum modulo sum till current index.
        max_sum = max(max_sum, curr_sum);
 
        // Finding position to the last sum stored in the set
        auto max_pos = mod.lower_bound(curr_sum+1);
 
        if (max_pos != mod.end())
            max_sum = max(max_sum, curr_sum - (*max_pos) + m );
 
        // Inserting curr_sum in the set.
        mod.insert(curr_sum);
    }
    
    return max_sum;
}

int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        long m;
        cin >> n >> m;
        vector<long> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        cout << maximumSum(a,m) << endl;
    }
}