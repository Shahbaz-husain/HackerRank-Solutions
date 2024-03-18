#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int beautifulPairs(vector<int> A, vector<int> B) {
    int count = 0;
    
    // Using hash vectors to store the elements of A and B according to their values index
    vector<int> indA(1000,0);
    vector<int> indB(1000,0);
    
    for(int i = 0; i < A.size(); i++){
        indA[A[i]]++;
    }
    
    for(int i = 0; i < B.size(); i++){
        indB[B[i]]++;
    }
    
    // Whichever vector has less occurance of a number, adding only that count
    for(int i = 1; i <= 1000; i++){
        count += min(indA[i], indB[i]);
    }
    
    // If count becomes equal to size , becuase of the condition reducing 1 from it else adding 1 because we can change one number to make one more pair
    count = count == A.size() ? count - 1 : count + 1;

    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n) , B(n);
    for(int i = 0; i < n; i++)
        cin >> A[i];
        
    for(int i = 0; i < n; i++)
        cin >> B[i];
        
    cout << beautifulPairs(A,B);
}