#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int sherlockAndAnagrams(string s)
{
    // unordered map to store the frequencies of all substrings
    unordered_map<string, int> um;
    for(int i = 1; i < s.size(); i++)
    {
        for(int j = 0; j <= s.size() - i; j++ ){
            // storing the frequencies of sorted substrings because anyways anagrams will have same chars so with sorted substring we can retrieve the anagrams easily
            string temp = s.substr(j , i);
            sort(temp.begin(), temp.end());
            um[temp]++;
        }
    }
    
    int result = 0;
    
    // calculating unique pair frequencies only
    for(auto pair : um){
        result += pair.second * (pair.second - 1)/2;
    }
    
    return result;
}

int main()
{
    int q ;
    cin >> q;
    while(q--)
    {
        string s;
        cin >> s;
        cout << sherlockAndAnagrams(s) << endl;
    }
}