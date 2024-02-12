#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2) {
    // taking 2 vectors to store frequencies of both strings chars
    vector<int> v1(26,0);
    vector<int> v2(26,0);
    
    // Storing frequencies
    for(int i = 0; i < s1.size(); i++)
    {
        v1[s1[i] - 'a']++;
    }
    for(int i = 0; i < s2.size(); i++)
    {
        v2[s2[i] - 'a']++;
    }
    
    int count = 0;
    
    // If frequency of any char doesn't matches of either of the string chars, then adding the difference in the count
    for(int i = 0; i < 26; i++)
    {
        if(v1[i] != v2[i])
            count += abs(v1[i] - v2[i]);
    }
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
