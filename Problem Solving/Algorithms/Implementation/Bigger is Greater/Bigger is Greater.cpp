#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string biggerIsGreater(const string s)
{
    int divider = 0;
    // checking first element to divide the substring
    for(int i = s.length()-1; i >= 1; i--)
    {
        if(s[i] > s[i-1]){
            divider = i;
            break;
        }
    }
    
    // If everything is already sorted in desc order, we can't permutate the string
    if(not divider)
        return "no answer";
        
    // in the basis of our divider , extracting a substring
    string s2 = s.substr(divider,s.length());
    
    // finding the smallest char in the substring with which we can make the same while maintaining lexalogical order
    int small = 0;
    for(int i = 1 ; i < s2.length(); i++)
    {
        if(s2[small] > s2[i]){
            if(s[divider-1] < s2[i])
                small = i;
        }    
    }
    
    // Swapping the smallest char
    string ans = s;
    swap(ans[divider-1], s2[small]);
    
    // sorting the remaining substring
    sort(s2.begin(),s2.end());
    
    // copying the sorted substring back into our main string
    for(int i = 0, k = divider; i < s2.length(); i++, k++)
        ans[k] = s2[i];
        
    return ans;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        
        cout << biggerIsGreater(s) << endl;
    }
}