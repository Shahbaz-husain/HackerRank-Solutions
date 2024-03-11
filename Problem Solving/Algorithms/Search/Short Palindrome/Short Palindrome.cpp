#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int shortPalindrome(string s){
    // Handling base case where a,b,c,d should atleast have a single char
    if(s.length()<4)    return 0;
    
    ull ans = 0;
    ull max_ans = pow(10,9)+7;
    
    // vectors to store characters and their different combinations, initially all set to 0
    vector<ull> chars(26,0);
    vector<vector<ull>> comb1(26, vector<ull>(26,0));
    vector<vector<vector<ull>>> comb2(26, vector<vector<ull>>(26, vector<ull>(26,0)));
    
    // Counting chars in the string and their combinations
    for(char c: s){
        int c_index = c-'a';
        for(int i =0;i<26;i++){
            //no of times c_index,i,i,c_index occurring in any position
            ans += comb2[c_index][i][i]; 
            ans %= max_ans;
            
            //no of times i has preceded 2c_index's incremented by no of times i has preceded 1c_index
            comb2[i][c_index][c_index] += comb1[i][c_index]; 
            
            //no of times i has preceded 1c_index incremented by no of times it has existed
            comb1[i][c_index] += chars[i]; 
        }
        chars[c_index]+=1;
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << shortPalindrome(s) << endl;
}