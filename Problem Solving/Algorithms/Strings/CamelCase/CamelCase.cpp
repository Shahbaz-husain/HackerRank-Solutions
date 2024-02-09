#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'camelcase' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int camelcase(string s) {
    // initiating the count by 1 because first word will always start with small case
    int count = 1;
    
    // Iterating over each character in the string
    for(int i = 0; i < s.length(); i++)
    {
        // Checking whether any char is cap char
        if(s[i] >= 'A' and s[i] <= 'Z')
            count++;
    }
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
