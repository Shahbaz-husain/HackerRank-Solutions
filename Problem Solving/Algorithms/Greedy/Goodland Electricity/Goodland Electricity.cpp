#include <bits/stdc++.h>

using namespace std;

int pylons(int k, vector<int> arr) {
    
    // taking a vector of bools which will hold n + 2k records so that we can start checking from the very first city that light can be distributed among which previous and next cities
    vector<bool> cities(arr.size() + 2*k);
    int count = 0, curr_city = 0;
    
    // Filling this vector from k+i position
    for(int i = 0; i< arr.size(); i++){
        cities[k + i] = arr[i];
    }
    
    // Checking for all cities whether pp can be implemented or not
    for(int i = 0; i < arr.size(); ){
        
        // starting from 1st city in cities that is present at i + k - 1 index  
        // Among the covered region , which last city can be implemented with pp
        for(curr_city = i + k - 1; curr_city + k > i; curr_city--){
            if(cities[curr_city+k]) break;
        }
        
        // j + k = i means there's a region where not even a single pp can be installed
        if(curr_city + k == i)
            return -1;

        // if pp installable city found , increasing the count and jumping to next untracked region
        count++;
        i = curr_city + k;
    }
    
    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
        
    cout << pylons(k, arr);
}
