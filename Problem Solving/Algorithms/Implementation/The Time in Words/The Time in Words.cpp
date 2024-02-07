#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(int h, int m) {
    string hour;
    string min;
    int mt = m;
    h = m <= 30 ? h : h+1;
    h = h == 13 ? 1 : h;
    m = m > 30 ? 60 - m : m;
    // can use string array also but just to show switch
    switch(h){
        case 1: hour = "one";break;
        case 2: hour = "two";break;
        case 3: hour = "three";break;
        case 4: hour = "four";break;
        case 5: hour = "five";break;
        case 6: hour = "six";break;
        case 7: hour = "seven";break;
        case 8: hour = "eight";break;
        case 9: hour = "nine";break;
        case 10: hour = "ten";break;
        case 11: hour = "eleven";break;
        case 12: hour = "twelve";break;
    }
    switch(m){
        case 2: min = "two";break;
        case 3: min = "three";break;
        case 4: min = "four";break;
        case 5: min = "five";break;
        case 6: min = "six";break;
        case 7: min = "seven";break;
        case 8: min = "eight";break;
        case 9: min = "nine";break;
        case 10: min = "ten";break;
        case 11: min = "eleven";break;
        case 12: min = "twelve";break;
        case 13: min = "thirteen";break;
        case 14: min = "fourteen";break;
        case 16: min = "sixteen";break;
        case 17: min = "seventeen"; break;
        case 18: min = "eighteen";break;
        case 19: min = "nineteen";break;
        case 20: min = "twenty";break;
        case 21: min = "twenty one";break;
        case 22: min = "twenty two";break;
        case 23: min = "twenty three";break;
        case 24: min = "twenty four";break;
        case 25: min = "twenty five";break;
        case 26: min = "twenty six";break;
        case 27: min = "twenty seven";break;
        case 28: min = "twenty eight";break;
        case 29: min = "twenty nine";break;
    }
    if(mt == 0) return hour + " o' clock";
    else if(mt == 1) return "one minute past " + hour;
    else if(mt > 1 and mt < 15) return min + " minutes past " + hour;
    else if(mt == 15) return "quarter past " + hour;
    else if(mt > 15 and mt < 30) return min + " minutes past " + hour;
    else if(mt == 30) return "half past " + hour;
    else if(mt > 30 and mt < 45) return min + " minutes to " + hour;
    else if(mt == 45) return "quarter to " + hour;
    else return min + " minutes to " + hour;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

    fout << result << "\n";

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
