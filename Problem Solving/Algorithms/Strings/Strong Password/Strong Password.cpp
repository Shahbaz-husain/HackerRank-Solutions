#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Variables to check each required char
    int digit = 1, lc = 1, cc = 1, sp = 1;
    
    for(int i = 0; i < password.length(); i++){
        
        // checking digit
        if(password[i] >= '0' and password[i] <= '9')
            digit = 0;
        // checking lowercase
        if(password[i] >= 'a' and password[i] <= 'z')
            lc = 0;
        // checking uppercase
        if(password[i] >= 'A' and password[i] <= 'Z')
            cc = 0;
        // checking specail char  
        if(password[i] == '!' or password[i] == '@' or
        password[i] == '#' or password[i] == '$' or password[i] == '%'
        or password[i] == '^' or password[i] == '&' or password[i] == '*'
        or password[i] == '(' or password[i] == ')' or password[i] == '-'
        or password[i] == '+')
            sp = 0;     
    }
    // calculating what else is required
    int req = digit + lc + cc + sp;
    
    // if what is required + existing length >= 6 , then just required is enough else , 
    // if require count is not enough to reach the min length , then we'll subtract the curr len from the min length and those many characters will be required
    return req + n >= 6 ? req : 6 - n ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

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
