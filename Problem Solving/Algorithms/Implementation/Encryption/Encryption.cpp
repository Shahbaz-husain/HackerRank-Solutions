#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string encryption(string s)
{
    string result = "";
    int n= s.length();
    int row = floor(sqrt(n));
    int column = ceil(sqrt(n));
    
    // calculating row if row * column can't store all the chars in the matrix
    if(row * column < n) row++;
    vector<string> temp(row, "");
    
    // string index
    int k = 0;
    
    // Filling substring into vector
    for(int i = 0; i < row; i++)
    {
        for(int j = 0;  j < column; j++)
        {
            temp[i] += s[k];
            k++;
        }
    }
    
    // Retrieving string column vice
    for(int i = 0; i < column; i++)
    {
        for(int j = 0; j < row; j++){
            if(temp[j][i])
                result += temp[j][i]; 
        } 
        // Adding space after adding each column elements
        result += ' ';
    }
    
    return result;
}

int main()
{
    string s;
    cin >> s;
    
    string result = encryption(s);
    
    cout << result << endl;
}