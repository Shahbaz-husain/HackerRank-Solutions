#include <bits/stdc++.h>

using namespace std;

int magicSquare0(int a[3][3])
{
    int sum = 0;
    sum = (abs(8-a[0][0]) + abs(3-a[0][1]) + abs(4-a[0][2]) + abs(1-a[1][0]) + abs(5-a[1][1]) + abs(9-a[1][2]) + abs(6-a[2][0]) + abs(7-a[2][1]) + abs(2-a[2][2]));
    return sum;
}

int magicSquare1(int a[3][3])
{
    int sum = 0;
    sum = (abs(6-a[0][0]) + abs(1-a[0][1]) + abs(8-a[0][2]) + abs(7-a[1][0]) + abs(5-a[1][1]) + abs(3-a[1][2]) + abs(2-a[2][0]) + abs(9-a[2][1]) + abs(4-a[2][2]));
    return sum;
}

int magicSquare2(int a[3][3])
{
    int sum = 0;
    sum = (abs(2-a[0][0]) + abs(7-a[0][1]) + abs(6-a[0][2]) + abs(9-a[1][0]) + abs(5-a[1][1]) + abs(1-a[1][2]) + abs(4-a[2][0]) + abs(3-a[2][1]) + abs(8-a[2][2]));
    return sum;
}

int magicSquare3(int a[3][3])
{
    int sum = 0;
    sum = (abs(4-a[0][0]) + abs(9-a[0][1]) + abs(2-a[0][2]) + abs(3-a[1][0]) + abs(5-a[1][1]) + abs(7-a[1][2]) + abs(8-a[2][0]) + abs(1-a[2][1]) + abs(6-a[2][2]));
    return sum;
}

int magicSquare4(int a[3][3])
{
    int sum = 0;
    sum = (abs(8-a[0][0]) + abs(1-a[0][1]) + abs(6-a[0][2]) + abs(3-a[1][0]) + abs(5-a[1][1]) + abs(7-a[1][2]) + abs(4-a[2][0]) + abs(9-a[2][1]) + abs(2-a[2][2]));
    return sum;
}

int magicSquare5(int a[3][3])
{
    int sum = 0;
    sum = (abs(4-a[0][0]) + abs(3-a[0][1]) + abs(8-a[0][2]) + abs(9-a[1][0]) + abs(5-a[1][1]) + abs(1-a[1][2]) + abs(2-a[2][0]) + abs(7-a[2][1]) + abs(6-a[2][2]));
    return sum;
}

int magicSquare6(int a[3][3])
{
    int sum = 0;
    sum = (abs(2-a[0][0]) + abs(9-a[0][1]) + abs(4-a[0][2]) + abs(7-a[1][0]) + abs(5-a[1][1]) + abs(3-a[1][2]) + abs(6-a[2][0]) + abs(1-a[2][1]) + abs(8-a[2][2]));
    return sum;
}

int magicSquare7(int a[3][3])
{
    int sum = 0;
    sum = (abs(6-a[0][0]) + abs(7-a[0][1]) + abs(2-a[0][2]) + abs(1-a[1][0]) + abs(5-a[1][1]) + abs(9-a[1][2]) + abs(8-a[2][0]) + abs(3-a[2][1]) + abs(4-a[2][2]));
    return sum;
}

int main()
{
    int arr[3][3] , sum = 0;
    // using HEBCIGFAD approach 
    // A B C
    // H I D
    // G F E
    
    // H E B C I G F A D
    // 1 2 3 4 5 6 7 8 9
    
    // to store all 8 possible magic squares
    int b[8];
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    // storing all magic squares differences sum wrt current square matrix
    b[0] = magicSquare0(arr);
    b[1] = magicSquare1(arr);
    b[2] = magicSquare2(arr);
    b[3] = magicSquare3(arr);
    b[4] = magicSquare4(arr);
    b[5] = magicSquare5(arr);
    b[6] = magicSquare6(arr);
    b[7] = magicSquare7(arr);
    
    sum = b[0];
    for(int i = 1; i < 8; i++){
        if(sum > b[i])
            sum = b[i];
    }
    cout << sum;
}