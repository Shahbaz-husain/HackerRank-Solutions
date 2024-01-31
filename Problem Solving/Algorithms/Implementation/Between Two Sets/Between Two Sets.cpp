#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

// int getTotalX(vector<int> a, vector<int> b) {
//     int count = 0;
//     int maxa = a[0];
//     bool nope = false;
//     for(int i = 1; i < a.size(); ++i){
//         if(maxa < a[i])
//             maxa = a[i];
//     }
//     int minb = b[0];
//     for(int i = 1; i < b.size(); ++i){
//         if(minb > b[i])
//             minb = b[i];
//     }
    
//     for(int i = maxa ; i <= minb; ++i){
//         nope = false;
//         for(int j = 0; j < a.size(); j++){
//             if(i%a[j] != 0){
//               nope = true;
//               break;  
//             }
//         }
//         if(!nope){
//             for(int j = 0; j < b.size(); j++){
//                 if(b[j]%i != 0){
//                     nope = true;
//                     break;
//                 }
//             }
//         }
//         if(!nope)
//             count++;
//     }  
//     return count;
// }

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int getTotalX(vector<int> a, vector<int> b) {
    int lcm_val = a[0];
    for (int i = 1; i < a.size(); ++i)
        lcm_val = lcm(lcm_val, a[i]);

    int gcd_val = b[0];
    for (int i = 1; i < b.size(); ++i)
        gcd_val = gcd(gcd_val, b[i]);

    int count = 0;
    for (int i = lcm_val, j = 2; i <= gcd_val; i = lcm_val * j, j++) {
        if (gcd_val % i == 0)
            count++;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
