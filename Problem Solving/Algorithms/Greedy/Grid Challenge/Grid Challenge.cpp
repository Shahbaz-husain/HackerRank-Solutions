#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string gridChallenge(vector<string> grid){
    // sorting each string in the grid
    for(int i = 0; i < grid.size(); i++){
        sort(grid[i].begin(), grid[i].end());
    }
    
    // comparing every row's char to it's previous row's char
    for(int i = 1; i < grid.size(); i++)
    {
        for(int j = 0; j < grid.size(); j++){
            
            // if any char is smaller than its predecessor , returning NO
            if(grid[i][j] < grid[i-1][j])
                return "NO";
        }
    }
    
    // returning YES in case of no return in above for loop
    return "YES";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> grid(n);
        for(int i = 0; i < n; i++)
            cin >> grid[i];
            
        cout << gridChallenge(grid) << endl;
    }
}