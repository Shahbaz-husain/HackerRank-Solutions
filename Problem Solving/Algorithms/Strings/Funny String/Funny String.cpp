#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'funnyString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string funnyString(string s) {
    // vector to store abs differences of s and reverse strings
    vector<int> vs;
    vector<int> vrev;
    string rev = "";
    
    // creating a reversed string
    for(int i = 0; i < s.size(); i++)
    {
        rev += s[s.size() - 1 - i];
    }
    
    // storing abs differences in vectors
    for(int i = 1; i < s.size(); i++)
    {
        vs.push_back(abs(s[i] - s[i-1]));
        vrev.push_back(abs(rev[i] - rev[i-1]));
    }
    
    // checking if any of the abs difference is different than returning not funny
    for(int i = 0; i < vs.size(); i++)
    {
        if(vs[i] != vrev[i])
            return "Not Funny";
    }
    
    // else if any difference is not there returning funny
    return "Funny";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = funnyString(s);

        fout << result << "\n";
    }

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
