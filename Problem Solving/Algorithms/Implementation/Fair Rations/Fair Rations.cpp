#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'fairRations' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY B as parameter.
 */

string fairRations(vector<int> B) {
    int count = 0;
    // checking every person except last person
    for( int i = 0 ; i < B.size() - 1; i++){
        
        // If any person have odd loaves then giving one loaf to him and his neighbour
        if (B[i]%2 != 0){
            // Incrementing two breads because giving bread to two persons
            count +=2;
            
            // Incrementing i person's and his neighbour's bread count
            B[i]++;
            B[i+1]++;
        }
    }
    
    // iterating thourgh the people whether any of them have odd number of breads 
    for(int i = 0; i < B.size(); i++){
        // If any person have odd breads then NO
        if(B[i]%2 != 0)
            return "NO";
    }
    
    // Else returning count of breads in string 
    return to_string(count);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    string B_temp_temp;
    getline(cin, B_temp_temp);

    vector<string> B_temp = split(rtrim(B_temp_temp));

    vector<int> B(N);

    for (int i = 0; i < N; i++) {
        int B_item = stoi(B_temp[i]);

        B[i] = B_item;
    }

    string result = fairRations(B);

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
