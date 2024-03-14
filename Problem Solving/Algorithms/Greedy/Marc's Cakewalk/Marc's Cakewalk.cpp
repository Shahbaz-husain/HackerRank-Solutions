#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long marcsCakewalk(vector<int> calories){
    long miles = 0;
    
    // sorting the calories in descending order because by adding 2^i * cal[i] in descedning order will only give us the minimum sum
    sort(calories.begin(), calories.end(), greater<int>());
    
    // calculating the minimum miles
    for(long i = 0; i < calories.size(); i++){
        miles += (pow(2,i) * calories[i]);
    }
    return miles;
}

int main(){
    int n;
    cin >> n;
    vector<int> calories(n);
    for(int i = 0; i < n; i++){
        cin >> calories[i];
    }
    
    cout << marcsCakewalk(calories);
}