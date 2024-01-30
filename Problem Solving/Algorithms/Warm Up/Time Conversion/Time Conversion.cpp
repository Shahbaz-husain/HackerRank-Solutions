#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string result = "";
    if (s[8] == 'P' and !(s[0] == '1' and s[1] == '2')) {
        int hour = stoi(s.substr(0, 2)); 
        hour = (hour % 12) + 12; // Convert hour to 24-hour format
        s[0] = (hour / 10) + '0'; // Update tens digit
        s[1] = (hour % 10) + '0'; // Update ones digit
    }
    else if(s[8] == 'A' and s[0] == '1' and s[1] == '2'){
        s[0] = '0';
        s[1] = '0';
    }   

    for(int i = 0; i < 8; i++)
        result += s[i];
        
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
