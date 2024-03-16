#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int luckBalance(int k , vector<pair<int,int>> contests){
    int result = 0;
    vector<int> imp; // vector to store luck points only of important matches
    
    for(auto pair : contests){ // iterating over all the pairs
        if(pair.second == 1) // Adding important matches luck points in the important vector
            imp.push_back(pair.first);

        else    // if pair is of unimportant match, we can lose this match hence adding the luck points in res.
            result += pair.first;
    }
    
    // sorting important points so that we can win the least luck counts matches to maximize the result
    sort(imp.begin(), imp.end());
    for(int i = imp.size()-1; i >= 0; i--){
        
        // losing matches and adding luck points until we are allowed to losw imp matches
        if(k-->0)
            result += imp[i];
            
        // substracting remaining matches luck points as we can't lose any more imp match
        else
            result -= imp[i];
    }
    return result;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> contests(n);
    for(int i = 0; i < n; i++){
        cin >> contests[i].first >> contests[i].second;
    }
    cout << luckBalance(k, contests);
}