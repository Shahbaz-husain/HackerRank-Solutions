#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    string temp = s;
    // converting the string to lower case
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    
    // Using set so that none of the characters get repeated
    unordered_set<char> uc;
    for(int i = 0; i < temp.size(); i++)
    {
        // only inserting alphabets in the set
        if(isalpha(temp[i]))
            uc.insert(temp[i]);
        
    }
        
    // If size of set is equals to 26 that means all the alphabets are there in the string as there are total 26 alphabets
    if(uc.size() == 26)
        return "pangram";
    return "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
