#include <bits/stdc++.h>

using namespace std;

int queensAttack(int n, int k, int row, int column, int board[][2])
{
    // calculating total steps queen can move without any obstacle on the board in every direction
    int left, right,up, down, leftup, rightup, leftdown, rightdown;
    
    left = column - 1;
    
    right = n - column;
    
    up = n - row ;
    
    down = row - 1;
    
    leftup = min(left, up);
    
    rightup = min(up , right);
    
    leftdown = min(left, down);
    
    rightdown = min(right , down);
    
    for(int i = 0; i < k; i++)
    {
        // Handling cases when obstacles are on the same row and considering only the nearest obstacle
        if(board[i][0] == row){
            if(board[i][1] > column){
                if(board[i][1] - column - 1 < right)
                    right = board[i][1] - column - 1;
            }
            
            else if(board[i][1] < column){
                if(column - board[i][1] - 1 < left)
                    left = column - board[i][1] - 1;
            }
        }
        
        // Handling cases when columns are same and considering only the nearest obstacle column wise
        else if(board[i][1] == column){
            if(board[i][0] > row){
                if(board[i][0] - row - 1 < up)
                    up = board[i][0] - row - 1;
            }
                    
            else if(board[i][0] < row){
                if(row - board[i][0] - 1 < down)
                    down = row - board[i][0] - 1;
            }
                    
        }
        
        // Handling left up diagonal case
        else if (board[i][0] > row and board[i][1] < column){
            if(board[i][0] - row == column - board[i][1]){
                if(board[i][0] - row - 1 < leftup)
                    leftup = board[i][0] - row - 1;
            }
        }
        
        // Handling left down diagonal case
        else if (board[i][0] < row and board[i][1] < column){
            if( row - board[i][0] == column - board[i][1]){
                if(row - board[i][0] - 1 < leftdown)
                    leftdown = row - board[i][0] - 1;
            }
        }
        
        // Handling right up diagonal case
        else if (board[i][0] > row and board[i][1] > column){
            if( board[i][0] - row == board[i][1] - column){
                if( board[i][1] - column - 1 < rightup)
                    rightup = board[i][1] - column - 1;
            }
        }
        
        // Handling right down diagonal case
        else if (board[i][0] < row and board[i][1] > column){
            if( board[i][0] - row == column - board[i][1]){
                if(board[i][1] - column - 1 < rightdown)
                    rightdown = board[i][1] - column - 1;
            }
        }
    }
    
    int steps = left + right + up + down + leftup + rightup + leftdown + rightdown;
    return steps;
}

int main()
{
    // number of rows and columns and obstacles
    int n, k;
    cin >> n >> k;
    
    // Position of queen
    int rq, cq;
    cin >> rq >> cq;
    
    int obstacles[k][2];
    for(int i = 0; i < k;i++)
        for(int j = 0; j<2; j++ )
            cin >> obstacles[i][j];   
            
    cout <<  queensAttack(n,k,rq,cq,obstacles);
}