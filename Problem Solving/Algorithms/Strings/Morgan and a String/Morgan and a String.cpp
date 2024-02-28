#include <iostream>

using namespace std;

string morganAndString(string s1, string s2){
    string res = "";
    int p1 = 0, p2 = 0;
    int l1 = s1.length() , l2 = s2.length();
    
    // iterating over both string until reaches one's end
    while(p1 < l1 and p2 < l2){
        
        // as long as the chars at p1 and p2 positions are different
        while(p1 < l1 and p2 < l2 and s1[p1] != s2[p2]){
            if(s1[p1] < s2[p2])
                res += s1[p1++];
            else
                res += s2[p2++];
        } 
            
        // when chars are same at p1 and p2, counting their consecutivity
        int c = 0, e = 0;
        while(p1+c < l1 and p2+c < l2 and s1[p1+c] == s2[p2+c] and s1[p1+c] == s1[p1]) {
            ++e;
            ++c;
        }
        
        while(p1+c < l1 and p2+c < l2 and s1[p1+c] == s2[p2+c] and s1[p1+c] <= s1[p1]) 
            ++c;
        
        // checking which string's next char is greater 
        if(p1+c < l1 and p2+c < l2)
            if(s1[p1+c] < s2[p2+c])
                while(e--) 
                    res += s1[p1++];
            else
                while(e--) 
                    res += s2[p2++];
        else
            if(p1+c == l1)
                while(e--) 
                    res += s2[p2++];
            else if(p2+c == l2)
                while(e--) 
                    res += s1[p1++];
    }
    
    while(p1 < l1)  res += s1[p1++];   
    while(p2 < l2)  res += s2[p2++];  
    return res;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << morganAndString(s1,s2) << endl;
    }
}
