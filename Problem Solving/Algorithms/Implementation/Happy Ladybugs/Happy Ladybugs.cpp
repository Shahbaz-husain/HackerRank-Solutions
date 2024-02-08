#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'happyLadybugs' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */

string happyLadybugs(string b) {
    // decalring two bools to track pairs and dashes
    bool pairs = true, dashes = false;
    
    // Iterating over all chars
    for(int i = 0; i < b.size(); i++)
    {
        // If string is already sorted and pairs are there
        if((b[i] == b[i+1] or b[i] == b[i-1]) and pairs == true)  {pairs = true;}
        
        // If string is sorted but pairs are not there
        else pairs = false;
        
        // If dashes are present
        if(b[i] == '_') {dashes = true;}
    }
    // If pairs are there in sorted order, then we won't check for dashes also
    if(pairs) return "YES";
    
    // If string is not sorted and dashes are also not there
    else if(not pairs and not dashes) return "NO";
        
    // if string is not sorted but dashes are there , first sort the string
    else if(not pairs and dashes)
    {
        sort(b.begin(),b.end());
        
        // checking for pairs in sorted array and ignoring dashes
        for(int i = 0; i < b.size(); i++)
        {
            if(b[i] == b[i+1] or b[i] == b[i-1] or b[i] == '_') {pairs = true;}
            else {
                pairs = false;
                break;
            }
        }
        // if pairs are there in sorted string
        if (pairs) return "YES";
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

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
