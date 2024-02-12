#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

string twoStrings(string s1, string s2) {
    int count = 0;
    
    // storing chars frequencies for both the strings
    vector<int> v1(26,0);
    vector<int> v2(26,0);
    
    for(int i = 0; i < s1.size(); i++)
        v1[s1[i] - 'a']++;
        
    for(int i = 0; i < s2.size(); i++)
        v2[s2[i] - 'a']++;
        
    // iterating over all frquencies in v1 and v2
    for(int i = 0; i < 26; i++)
    {
        
        // At any moment , we have a common character , we'll return YES because now we have atleast one common current indicating a common substring
        if(v1[i] > 0 and v2[i]> 0)
            return "YES";
    }
    
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

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
