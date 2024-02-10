#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

void separateNumbers(string s) {
    if(s.size() < 2){
        cout << "NO" << endl;
        return;
    }
    long long int ans = 0;
    bool flag = false; 
    // Iterating till half because our first number length can't be greater than the second number's
    for(int i = 1; i <= s.size()/2 ; i++){
        
        // Mulitipying tby 10 to increment the digit count on every pass if doesn't match
        ans = ans * 10 + (s[i-1] - '0');
        long long int next = ans + 1;
        
        // Fetching substring from the original string upto length i
        string st = s.substr(0,i);
        while(st.size() < s.size()){
        // Appending each integer by adding 1 to that as 1 can be the max difference between them
            st += to_string(next);
            next++;
        }
        if(st == s){
            flag = true;
            break;
        }
    }
    if(flag)
        cout << "YES " << ans << endl;
    else
        cout << "NO" << endl;    
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
