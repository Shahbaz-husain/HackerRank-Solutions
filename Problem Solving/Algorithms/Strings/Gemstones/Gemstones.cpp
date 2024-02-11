#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gemstones' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY arr as parameter.
 */

int gemstones(vector<string> arr) {
    int count = 0;
    
    // vector to store the occurence of minerals
    vector<int> chars(26,0);
    
    // reducing each rock to distinct minerals using sets
    for(int i = 0; i < arr.size(); i++){
        unordered_set<char> uc(arr[i].begin(), arr[i].end());
        
        // storing each occurence in the mineral occurance vector (0-25)
        for(const char c : uc){
            chars[c-'a']++;
        } 
    }
    
    // retrieving the count of each minerals occurence , if any occurence is equals to the numver of rocks that means that mineral is present in every rock and hence increasing the count of the gemstone.
    for(int i = 0; i < chars.size(); i++)
    {
        if(chars[i] == arr.size())
            count++;
    }
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

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
