#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string twoArrays(long k, vector<long> A, vector<long> B){
    long n = A.size();
    
    // sorting both arrays 
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // Comparing A's elements from the start and B's elements from the end
    for(int i = 0; i < n; i++){
        if(A[i] + B[n-1-i] < k)
            return "NO";
    }
    
    return "YES";
}

int main(){
    int q;
    cin >> q;
    while(q--){
        long n, k;
        cin >> n >> k;
        vector<long> A(n);
        vector<long> B(n);
        for(long i = 0; i < n; i++)
            cin >> A[i]; 
        
        for(long i = 0; i < n; i++)
            cin >> B[i]; 
        
        cout << twoArrays(k,A,B) << endl;
    }
}