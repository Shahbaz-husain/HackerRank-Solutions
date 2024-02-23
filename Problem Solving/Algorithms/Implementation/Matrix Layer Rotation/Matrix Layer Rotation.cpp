#include <iostream>
#include <vector>

using namespace std;

void matrixRotation(vector<vector<long>> matrix, long r)
{
    long m = matrix.size();
    long n = matrix[0].size();
    // how many rects can be rotated will be the half of min of rows and colunns 
    // Eg : 4 6 
    // * * * * * *
    // * * * * * *
    // * * * * * *
    // * * * * * *
    // By below mentioned way we can find the number of rects present, in above case 2 rects, outer rect and inner rect 
    long rects = min(m,n) / 2;
    
    // number of rotations to get back to original place formula : 2 * m + 2 * n - 4 - 8 * i 
    
    // for all rects
    for(long i = 0; i < rects; i++){
        // number of rotations to get back to original place formula : 2 * m + 2 * n - 4 - 8 * i 
        long rotations = r % (2*m + 2*n - 4 - 8*i);
        
        // rotating each rectangle r times
        while(rotations--)
        {
            // top row rotate
            for(int j = i; j < n -  i - 1; j++)
                swap(matrix[i][j], matrix[i][j+1]);
            
            // right column rotate
            for(int j = i; j < m - i - 1; j++)
                swap(matrix[j][n-i-1], matrix[j+1][n-i-1]);
            
            // bottom row roatte
            for(int j = n - i - 1; j > i; j--)
                swap(matrix[m-i-1][j], matrix[m-i-1][j-1]);
            
            // left column rotate
            for(int j = m - i - 1; j > i + 1; j--)
                swap(matrix[j][i], matrix[j-1][i]);
        }
    }
    
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    long m , n , r;
    cin >> m >> n >> r;
    vector< vector<long> > matrix(m , vector<long>(n));
    
    for(long i = 0; i < m; i++)
    {
        for(long j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    
    matrixRotation(matrix, r);
}