#include <iostream>
#include <vector>

using namespace std;

void set(int x, int y, vector<string>& temp) {
    if (x >= 0 && x < temp.size() && y >= 0 && y < temp[0].size()) {
        temp[x][y] = '.';
    }
}

vector<string> bomberMan(int n , vector<string> grid)
{
    // at second 1 bomber isn't doing anything so grid will remain in same state
    if(n == 1)
        return grid;
    
    // in every even second , bomber is filling grid completely with bombs
    if(n % 2 == 0)
    {
        vector<string> result(grid.size(), string(grid[0].size(), 'O'));
        return result;
    }
    
    else{
        // removing even states
        n /= 2;
        
        vector<string> result(grid);
        // alternating states (can be 0 or 1 depending on the value of n)
        for(int i = 0; i <= (n+1)%2; i++)
        {
            // Taking a temp grid initialized to all bombs
            vector<string> temp(grid.size(), string(grid[0].size(), 'O'));
            
            // storing neighbouring indices in xi and yi
            int xi[5] = {0,0,0,1,-1};
            int yi[5] = {0,-1,1,0,0};
            
            // iterating over all the current indices of result
            for (int a = 0; a < temp.size(); a++ )
            {
                for(int b = 0; b <temp[a].size(); b++)
                {
                    // if bomb found , replace it and the neighbouring indices to '.'
                    if(result[a][b] == 'O'){
                        for(int k = 0; k < 5 ; k++){
                            set(a, b + yi[k], temp);
                            set(a + xi[k], b, temp);
                        }
                    }
                }
            }
            
            // storing the current value of temp grid in result in case of alternate possibilities
            result = temp;
        }
        return result;
    }
}

int main()
{
    int r, c, n;
    cin >> r >> c >> n;
    vector<string> grid(r, "");
    for(int i = 0; i < r; i++)
    {
        cin >> grid[i];
    }
    
    vector<string> result = bomberMan(n, grid);
    for(string row : result)
        cout << row << endl;
}