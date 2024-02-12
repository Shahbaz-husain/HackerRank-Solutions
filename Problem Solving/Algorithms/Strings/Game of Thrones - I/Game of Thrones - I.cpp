#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) {
    // if length is 1 , it's already a palindrome
    if(s.length() == 1)
        return "YES";
    
    // Declaring a varible to check how many chars has odd frequencies because a palindrome can only have odd frequency of only one char that will go the the middle of the odd string eg : babab
    int oddFound = 0;
        
    // Using unordered map to store the frequencies
    unordered_map<char,int> um;
    for(int i = 0; i < s.size(); i++)
    {
        um[s[i]]++;
    }
    
    for(auto pair : um){
        // If any first frequency is odd , incrementing the count to 1
        if(pair.second %2 != 0)
            oddFound++;
        
        // If at any moment odd freuency counts becomes greater than 1 , returning No
        if(oddFound > 1)
            return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
