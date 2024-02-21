#include <iostream>
#include <vector>

using namespace std;

int twoPluses(vector<string> grid){
    int row = grid.size();
    int column = grid[0].size();
    
    // Adding boundaries to out grid
    vector<string> bound_grid(row+2, string(column+2, 'O'));
    for(int i = 1; i < row+1; i++)
    {
        for(int j = 1; j < column+1; j++){
            bound_grid[i][j] = grid[i-1][j-1];
        }
    }
    
    grid = bound_grid;
    int result = 0;
    
    // tracking over only our actual grid
    for(int i = 1; i < row+1; i++)
    {
        for(int j = 1; j < column+1; j++)
        {
            // tracking first cell
            int r = 0;
            while(grid[i+r][j] == 'G' and grid[i-r][j] == 'G' and grid[i][j+r] == 'G' and grid[i][j-r] == 'G'){
                // changing the values for this iteration
                grid[i+r][j] = grid[i-r][j] = grid[i][j+r] = grid[i][j-r] = 'g';
                
                // iterate for second cell
                for(int ii = 1; ii < row+1; ii++){
                    for(int jj = 1; jj<column+1; jj++)
                    {
                        // tracking second cell
                        int rr = 0;
                        while(grid[ii+rr][jj] == 'G' and grid[ii-rr][jj] == 'G' and grid[ii][jj+rr] == 'G' and grid[ii][jj-rr] == 'G'){
                            result = max(result, (4*r + 1) * (4*rr + 1));
                            rr++;
                        }
                    }
                }
                r++;
            }
            
            // reverting back the changes if made any to get the original grid
            r = 0;
            while(grid[i+r][j] == 'g' and grid[i-r][j] == 'g' and grid[i][j+r] == 'g' and grid[i][j-r] == 'g'){
                grid[i+r][j] = grid[i-r][j] = grid[i][j+r] = grid[i][j-r] = 'G';
                r++;
            }
        }
    }
    
    return result;
}

int main(){
    int n , m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i =0; i < n; i++){
        cin  >> grid[i];
    }
    
    cout << twoPluses(grid);
}
