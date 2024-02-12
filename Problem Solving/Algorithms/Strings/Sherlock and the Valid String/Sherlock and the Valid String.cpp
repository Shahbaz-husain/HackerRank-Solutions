#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    vector<int> frq(26,0);
    
    int common = 0, invalid = 0;
    
    // storing the frequencies
    for(char c : s)
        frq[c - 'a']++;
    
    for(int i = 0; i < 26; i++)
    {
        // will only iterate on nonzero frequencies
        if(frq[i] != 0)
        {
            if(common == 0)  common = frq[i]; // will only execute once 
            
            // if frequency is not common in any index , it means this char appeared more or less times, so increasing the invalid chars count
            else if(common != frq[i])  invalid++;
            
            // if invalid chars count becomes 2 or invalid is 1 and the difference in the frquencies is not 0 or 1 , then returning no
            if(invalid > 1 or frq[i] - common > 1)
                return "NO";
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
