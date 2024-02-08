#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
    // used unordered_map so that same distances doesn't get repeat and data doesn't get sorted
    unordered_set<int> temp;
    
    // case when all the cities are space stations
    if (n == c.size())
        return 0;
        
    // Iterating for all cities
    for(int i = 0; i < n; i++){
        int diff;
        int ans = INT_MAX;
        for(int j : c){
            // If city is a space station , breaking the loop ans setting the ans in set
            if(i == j)  {
                ans = 0;
                break;
            }
            
            // If city is not a space station , calculating the distance to the nearest space station
            else if(i != j){
                diff = abs(i - j);
                // Finding the distance between the city and the nearest station among all space stations
                ans = min(diff, ans);
            }     
        }
        // Only inserting when distance between the city and space station is more than 0 so that unnecessary insertions can be ignored
        if (ans > 0) temp.insert(ans);
    }
    // returning the maximum distance present in the set
    return *max_element(temp.begin(), temp.end());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
