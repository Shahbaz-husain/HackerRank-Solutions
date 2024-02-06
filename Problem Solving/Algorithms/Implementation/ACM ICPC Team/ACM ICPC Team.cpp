#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'acmTeam' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY topic as parameter.
 */

// function which will count the number of max_subjects by comparing 2 subjects strings
int count(string a, string b){
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '1' or b[i] == '1')
            count++;
    }
    return count;
}

vector<int> acmTeam(vector<string> topic) {
    int max_subj = 0;
    int teams = 0;
    // comparing each attendees data with every other attendee
    for(int i = 0 ; i < topic.size(); i++)
        for(int j = i+1; j < topic.size(); j++){
            int c = count(topic[i], topic[j]);

            // if count of the current 2 attendees is greater than our last max_subj count then we'll change the max_subject and will reset our teams count
            if(max_subj < c){
                teams = 1;
                max_subj = c;
            }
            
            // if in case we don't have any other max_subj but different teams with same max_subj count then we'll just increment the teams count 
            else if (max_subj == c) teams++;
        }
    vector<int> result;
    result.push_back(max_subj);
    result.push_back(teams);
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
