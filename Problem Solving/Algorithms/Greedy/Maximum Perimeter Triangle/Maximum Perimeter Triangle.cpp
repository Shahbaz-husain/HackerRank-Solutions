#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> maximumPerimeterTriangle(vector<int> sticks){
    // vector to store possible sides
    vector<vector<int>> possible;
    vector<int> result;
    
    // sorting sticks lengths in case they are in unsorted order
    sort(sticks.begin(), sticks.end());
    
    // checking each first two sides with every other side whether triangle is forming or not
    for(int i = 0; i < sticks.size()-2; i++){
        for(int j = i+2; j <sticks.size(); j++){
            int b = sticks[i];
            int p = sticks[i+1];
            int h = sticks[j];
            
            // if length of 2 sticks is greater than the third , triangle can be formed
            // hence adding those lengths in the possible vector
            if(b + p > h){
                possible.push_back({sticks[i], sticks[i+1], sticks[j]});
            }
        }
    }
    
    // if possible is empty returning -1
    if(possible.empty())    result.push_back(-1);
        
    // else returning the last entry of the possible as it will contain max length sticks
    else                    result = possible[possible.size()-1];
    return result;
}

int main(){
    int n ;
    cin >> n;
    vector<int> sticks(n);
    for(int i = 0; i < n; i++)
        cin >> sticks[i];
        
    vector<int> result = maximumPerimeterTriangle(sticks);
    for(int el : result)
        cout << el << " ";
}