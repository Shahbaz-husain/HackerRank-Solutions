#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void almostSorted(vector<int> arr)
{
    int l= -1 , r = -1, n = arr.size();
    
    // taking a sorted copy of our array to compare whether our array is already sorted or not , if yes returning
    vector<int> sorted(arr);
    sort(sorted.begin(), sorted.end());
    if(arr == sorted){
        cout << "yes\n";    return;
    }
    
    // checking whether we can sort or not using either of the provided operation
    // finding the first wrong positioned number from the left and right
    for(int i = 0; i < n - 1; i++)
        if(arr[i] > arr[i+1]){
            l = i;  break;
        }
        
    for(int i = n - 1; i > 0; i--)
        if(arr[i] < arr[i-1]){
            r = i;  break;
        }
    
    //case 1 : if swapping l and r element sorts the array , returning
    vector<int> temp(arr);
    swap(temp[l], temp[r]);
    if(temp == sorted){
        cout << "yes\n" <<  "swap " << l+1 << " " << r+1 << endl;   return;
    }
    
    // case 2 : reverse case
    vector<int> temp2;
    for(int i = 0 ; i < l; i++)     temp2.push_back(arr[i]);
    for(int i = r ; i >= l; i--)    temp2.push_back(arr[i]);
    for(int i = r+1; i < n; i++)    temp2.push_back(arr[i]);
    if(temp2 == sorted){
        cout << "yes\n" << "reverse " << l+1 << " " << r+1 << endl; return;
    }
    
    cout << "no\n";
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    almostSorted(arr);
}