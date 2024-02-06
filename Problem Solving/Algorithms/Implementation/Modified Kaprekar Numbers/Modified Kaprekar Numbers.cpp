#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */



void kaprekarNumbers(int p, int q) {
    bool flg = false;
    for(long i = p ; i <= q; i++){
        // Calculating square for each number
        long int square = i*i;
        
        //Varibale to count the power of 10 require to slpit the digit
        int count = 0;
        long int temp = i;
        
        // Calucaling power of 10 to divide the number into respective left and right digits
        while(temp){
          temp /= 10;
          count++;  
        } 
        
        // Calculating divisor to actually split the digits
        long int div = pow(10, count);
        
        // adding the left and right splitted digits
        long int sum = (square/div) + (square%div);
        
        if(sum == i){
            cout << i << " ";
            flg = true;
        }    
    }
    if(flg == false)
        cout << "INVALID RANGE" ;
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
