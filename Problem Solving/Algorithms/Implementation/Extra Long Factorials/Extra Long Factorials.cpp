#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Big Integer Problem in c/c++
    int n, size = 1; // because we already know our first value is 1 , so initialized the size with 1;
    cin >> n;
    int bigInt[200];
    bigInt[0] = 1; // because in factorial series first value is 1
    for(int i = 2 ; i <= n; i++)
    {
        // variable to story the carry of the multiplication
        int carry = 0;
        for(int j = 0; j < size; j++)
        {
            // Finding the value whose remainder needs to be stored in jth index of our bigInt
            int val = bigInt[j] * i + carry;
            bigInt[j] = val % 10;
            
            // Calculating the carry from the value
            carry = val/10;
        }
        
        // handling all the digits of the carry
        while(carry)
        {
            bigInt[size] = carry%10;
            carry /= 10;
            
            // increasing the size if carry if more than 0 upto its digits size
            size++;
        }
    }
    
    // Values will be stored in the reverse order in the array , so backtracking the digits
    for(int i = size-1; i>=0; i--)
        cout << bigInt[i];
}