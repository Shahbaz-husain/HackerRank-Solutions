#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int helper(int i, int j, vector<vector<int>> &grid, int count){
    // adjacent indices 
    int xi[] = {-1,-1,-1, 0, 0, 0, 1, 1, 1};
    int yi[] = {-1,0,1, -1, 0, 1 , -1, 0 , 1};
    
    int n = grid.size();
    int m = grid[0].size();
    
    // if current cell is not 1, returning
    if(grid[i][j] != 1)
        return count;
        
    // marking the cell as visited by changing it's value to 2
    count++;
    grid[i][j] = 2;
    
    // checking the adjacent cells of the current cell
    for(int k = 0; k < 8; k++)
    {
        if((0 <= i+xi[k] and  i+xi[k] < n) and (0 <= j+yi[k] and j+yi[k] < m))
            count = max(count , helper(i+xi[k], j+yi[k], grid , count));
    }
    return count;
}

int connectedCell(vector<vector<int>> grid){
    int max_count = 0;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i < n;i++)
    {
        for(int j = 0; j < m;j++)
        {
            max_count = max(max_count, helper(i,j, grid, 0));
        }
    }
    return max_count;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n;i++)
    {
        for(int j = 0;  j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << connectedCell(grid) << endl;
}
