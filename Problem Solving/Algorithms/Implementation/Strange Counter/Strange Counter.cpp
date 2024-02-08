#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'strangeCounter' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER t as parameter.
 */

long strangeCounter(long t) {
    // Time complexity is O(n)
    // long iter = 3;
    // long value = iter;
    // long time = 1;
    // while(true){
    //     if(time == t)
    //         return value;
    //     else if (time > t)
    //         return -1;
    //     time++;
    //     value--;
    //     if(value == 0){
    //         iter = iter*2;
    //         value = iter;
    //     }
    // }

    // Time complexity ~ O(logn) as we 
    long cycle = 3; // Initial cycle length
    while (t > cycle) {
        t -= cycle; // Subtract the current cycle length
        cycle *= 2; // Double the cycle length for the next iteration
    }
    return cycle - t + 1; // Calculate the value at time t
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    long t = stol(ltrim(rtrim(t_temp)));

    long result = strangeCounter(t);

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
