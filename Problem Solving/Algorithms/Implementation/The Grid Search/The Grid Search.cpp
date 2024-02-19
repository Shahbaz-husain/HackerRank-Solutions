#include <iostream>
#include <vector>

using namespace std;

string gridSearch(vector<string> grid, vector<string> pattern){
    int find = false;
    // will only traverse gr - pr rows because we need to find the complete pattern heightwise 
    for(int i = 0; i <= grid.size() - pattern.size(); i++)
    {
        // Similarly we'll only traverse gc - pc columns widthwise because of same reason
        for(int j = 0; j<= grid[0].size() - pattern[0].size(); j++){
            
            // if our patterns very first element matches the current char we'll check for all the remaining pattern chars
            if(pattern[0][0] == grid[i][j]){
                
                // Incrementing both pattern and grid indices row and column wise , wherever it doesn't match we'll come out of the loop
                for(int m = 0, x = i; m < pattern.size(); m++,x++)
                {
                    for(int n = 0, y = j; n < pattern[0].size(); n++, y++)
                    {
                        if(pattern[m][n] == grid[x][y])
                            find = true;
                            
                        // If pattern couldn't be matched breaking from both the loops so that can search in next set of rows and column
                        else{
                            find = false;
                            break;
                        }
                    }
                    if(!find)
                        break;
                }
            }
            if(find)
               return "YES";
        }
    }
    return "NO";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int gr, gc;
        cin >> gr >> gc;
        
        vector<string> grid(gr);
        for(int i = 0; i < gr; i++)
        {
            cin >> grid[i];
        }
        
        int pr, pc;
        cin >> pr >> pc;
        
        vector<string> pattern(pr);
        for(int i = 0; i < pr; i++)
        {
            cin >> pattern[i];
        }
        
        cout << gridSearch(grid, pattern) << endl;
    }
}