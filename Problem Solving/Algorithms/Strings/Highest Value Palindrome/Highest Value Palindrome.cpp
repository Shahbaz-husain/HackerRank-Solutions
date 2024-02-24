#include <iostream>
#include <vector>

using namespace std;

string highestValuePalindrome(string s, int n, int k)
{
    // taking freq vector to keep the record of the changed char at ith index
    vector<int> freq(n,0);
    int left = 0;
    int right = n - 1;
    
    // converting to palidrome by copying the bigger char into the smaller one while marking which index char was changed chances taken
    while(left < right)
    {
        if(s[left] != s[right]){
            if(s[left] > s[right]){
                s[right] = s[left];
                freq[right] = 1;
            }
            else{
                s[left] = s[right];
                freq[left] = 1;
            }
            
            // if not able to convert into palidrome within k chances , then returning
            if(--k < 0)
                return "-1";
        }
        left++;
        right--;
    }
    
    left = 0;
    right = n - 1;
    
    // now if we have the palindrome , maximizing it
    while(left <= right)
    {
        // if left or right is not 9 , then we can change it to 9
        if(s[left] != '9'){
            
            // if center char is not 9 and only one chance of conversion is left , changing the center element to 9
            if (left == right and k >= 1){
                s[left] = '9';
                break;
            }
            
            // if left and right were not change earlier and we still have 2 chances , converting both to 9
            if (freq[left] == 0 and freq[right] == 0 and k >= 2){
                s[left] = s[right] = '9';
                k -= 2;
            }
            
            // if any of the left or right was changed before , converting both to 9 , but by utilizing only one chance as we used one chance in marking freq
            if ((freq[left] == 1 or freq[right] == 1) and k >= 1){
                s[left] = s[right] = '9';
                k--;
            }
        }
        left++;
        right--;
    }
    
    return s;
}

int main()
{
    int n , k ;
    cin >> n >> k;
    string s;
    cin >> s;
    
    cout << highestValuePalindrome(s, n , k) << endl;
}