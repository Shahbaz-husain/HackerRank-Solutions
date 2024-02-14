#include <bits/stdc++.h>

using namespace std;

// Taking an arr of max size according to given constraints and a frequency array to store the occurences
int arr[200001];
int freq[201] = {0};

int double_median(int days){
    int sum = 0;
    for(int i = 0; i < 201; i++){
        sum += freq[i];
        if(2*sum > days)
            return 2*i;
        else if(2*sum == days){
            for(int j = i+1; ; j++){
                if(freq[j])
                    return i+j;
            }
        }
    }
    return -1;
}

int main()
{
    int n, d, count = 0; // size of array and window size
    cin >> n >> d;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        if(i >= d){
            // If current day exp is greater than double median of the earlier d days
            if(arr[i] >= double_median(d))
                count++;
            // Removing the previous used day expenditure
            freq[arr[i-d]]--;
        }
        // Adding for frequencies for all occurence of arr[i]
        freq[arr[i]]++;
    }
    cout << count;
}