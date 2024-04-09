#include <iostream>
#include <string>

using namespace std;

typedef long int l;

long int z_func(const string &s)
{
    l sum = 0;
    l len = s.length();
    l Z[len] = {0};
    l left = 0;
    l right = 0;
    for (l k = 1; k < len; ++k)
    {
        if (k > right) {
            left = right = k;
            while (right < len && s[right] == s[right - left]) {
                right ++;
            }
            Z[k] = right - left;
            right --;
        } else {
            int k1 = k - left;
            if (Z[k1] < right - k + 1) {
                Z[k] = Z[k1];
            } else {
                left = k;
                while (right < len && s[right] == s[right - left]) {
                    right ++;
                }
                Z[k] = right - left;
                right --;
            }
        }
    }

    for (l i = 0; i < len; ++i)
    {
        sum += Z[i];
    }

    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        l res = z_func(s);

        cout << s.length() + res << endl;
    }
}