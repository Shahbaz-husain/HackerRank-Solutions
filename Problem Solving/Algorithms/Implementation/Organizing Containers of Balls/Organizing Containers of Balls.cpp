#include <iostream>
#include <vector>
using namespace std;

// vertically we have balls of each type 
// horizontally we have space for each type of ball

void organizingContainers(int n, vector<vector<int>> a){
    // vectors to store space and balls
    vector<int> space(n,0), balls(n,0);
    int possible = false;
    
    // calculating space and balls for each type of ball
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            space[i] += a[i][j]; // no of spaces
            balls[i] += a[j][i]; // no of balls of each type
        }
    }
    
    // Filling balls
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // If ball can be filled inside the container , possible will become true
            if(space[i] == balls[j])
            {
                balls[j] = NULL;
                space[i] = NULL;
                possible = true;
                break; 
            }
            
            // if ball can't be inserted that means we can't sort the matrix , hence breaking
            else {
                possible = false;
            }
        }
        
        // If any of the ball type can't be sorted , that means we can't sort the square matrix hence ending the outer loop
        if(not possible)
            break;
    }
    
    if(not possible)
        cout << "Impossible" << endl;
    else
        cout << "Possible" << endl;
}

int main()
{
    // to store number of queries and size of sqaure matrix in each query
    int n , q;
    cin >> q;
    while(q--)
    {
        cin >> n;
        // taking vector of vactor to store square matrix
        vector<vector<int>> a(n, vector<int>(n));
        
        // filling square matrix 
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        
        organizingContainers(n,a);
    }
}