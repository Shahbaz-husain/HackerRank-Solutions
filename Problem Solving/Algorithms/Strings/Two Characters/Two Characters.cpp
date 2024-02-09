#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
 
int validateString(char a, char b, string s){
    int count = 0;
    char last_char;
    
    // Iterating over the string
    for(int i = 0; i < s.size(); i++){
        
        // If char is from our selected set : if it's same as our last char that means the string is not an alternate string anymore, so will return otherise will increase the length count and set the curr char to last char
        if((s[i] == a or s[i] == b)){
            if(last_char == s[i])
                return 0;
                
            count++;
            last_char = s[i];
        }
    }
    // only return count when length is >=2
    return count < 2 ? 0 : count;
} 

int alternate(string s) {
    int res = 0;
    
    // First char from the set will be from a to y
    for (int i = 'a'; i < 'z'; i++){
        
        // Second char for the set will be from i + 1 to z
        for(int j = i+1; j <= 'z'; j++){
            
            // validating the reduced string and fetching the length of it through this function
            int count = validateString(i,j, s);
            
            // Keeping the max length count in the result
            if (res < count) res = count;
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

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
