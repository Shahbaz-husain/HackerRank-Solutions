#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    // declaring an empty string to store the reduced string
    string result = "";
    
    //Iterating over each char
    for(int i = 0; i < s.size(); i++)
    {
        // When either result is empty or curr s[i] is not equal to the last inserted char , we'll add s[i] into the string
        if(result.length() == 0 or result[result.length()-1] != s[i])
            result += s[i];
            
        // If curr char matches the last inserted match , we'll remove the last char
        else
            result.pop_back();
    }
    
    if(not result.empty())
        return result;
    return "Empty String";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
