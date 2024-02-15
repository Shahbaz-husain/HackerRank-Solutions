#include <bits/stdc++.h>

using namespace std;

vector<int> ranks(vector<int> ranked, vector<int> players){
    // Using a set to remove duplictated scores
    unordered_set<int> distict(ranked.begin(), ranked.end());
    
    // copying the distinct score into the distinct vector and sorting it
    vector<int> distinct(distict.begin(), distict.end());
    sort(distinct.begin(), distinct.end());
    
    // vector to store the ranks 
    vector<int> result;
    
    // itarating over all the players score
    for(int i = 0; i < players.size(); i++)
    {
        
        // Calculating rank using distance function with begin point as the upperbound of the player[i] in distinct
        int rank = distance(upper_bound(distinct.begin(), distinct.end(), players[i]) , distinct.end()) + 1;
        result.push_back(rank);
    }
    
    return result;
}

int main(){
    int n, m, input;
    
    cin >> n;
    vector<int> ranked;
    for(int i = 0; i < n; i++){
        cin >> input;
        ranked.push_back(input);
    }
    
    cin >> m;
    vector<int> players;
    for(int i = 0; i < m; i++){
        cin >> input;
        players.push_back(input);
    }
    
    vector<int> result = ranks(ranked, players);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}