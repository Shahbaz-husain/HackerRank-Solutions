#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
    // If string can't be evenly distributed , then return -1 because it can't be an anagram
    if(s.length() % 2 != 0)
        return -1;
    
    // number of chars needs to be change initialized to total number of chars in first half string
    int n1 = s.size()/2, count = n1;
    
    // retrieving first half and second half strings
    string s1 = s.substr(0,n1);
    string s2 = s.substr(n1);
    
    // using unordered map to store the frequenciesof the chars in second half string
    unordered_map<char, int> um;
    
    // string the frequencies
    for(int i = 0; i < n1; i++){
        um[s2[i]]++;
    }
    
    // if s1[i] is there in s2 then we are decreasing the count and udpdating the frequency
    for(int i = 0; i < n1; i++){
        if(um[s1[i]] > 0){
            count--;
            um[s1[i]]--;
        }
    }
    
    return count;
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

        int result = anagram(s);

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
