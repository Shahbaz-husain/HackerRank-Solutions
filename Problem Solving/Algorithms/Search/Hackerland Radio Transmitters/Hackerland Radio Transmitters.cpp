#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hackerlandRadioTransmitters(vector<int> houses, int k){
    sort(houses.begin(), houses.end());
    int count = 0, n = houses.size();
    int first = houses[0];
    
    // initially no house has tower installed
    int lastRadio = -1;
    
    // checking distances between the houses from 1 to n-1 indices
    for(int i = 1; i < n; i++)
    
        // as soon as current house get out of the range of the recently installed tower
        if (houses[i] > first + k) {
            
            // install the tower at the previous house
            lastRadio = houses[i - 1];
            count++;
            
            // and skip next houses coming in the newly installed tower's range
            while (i < n and houses[i] <= lastRadio + k) {
                i++;
            }
            
            // if still there are houses left , check for towers from the last house
            if (i < n) {
                first = houses[i];
            }
        }
    
    // if last house is still not coming in any tower's range , install one more tower
    if (houses[n - 1] > lastRadio + k) {
        count++;
    }
    return count;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> houses(n);
    for(int i = 0; i < n; i++)
        cin >> houses[i];
        
    cout << hackerlandRadioTransmitters(houses, k);
}