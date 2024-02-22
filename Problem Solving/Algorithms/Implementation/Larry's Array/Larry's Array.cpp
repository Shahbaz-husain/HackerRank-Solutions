#include <iostream>
#include <vector>

using namespace std;

// Logic : 
// if sum of number of inversions(putting in proper place wrt to previous numbers) is even , it can be sorted otherwise no

// For eg :
// 1 6 5 2 4 3
// for 1 = 0
// for 6 = 0
// 5 = 1
// 2 = 2
// 4 = 2
// 3 = 3
// total = 1 + 2 + 2 + 3 = 8 / 2  hence yes

// Eg : 2
// 1 2 3 5 4
// 1 = 0 , 2 = 0 , 3 = 0 , 5 = 0 , 4 = 0
// total = 1 , hence no

// i = 3                sum = 8
// j = 3

string larrysArray(vector<int> arr)
{
    int sum = 0;
    
    // counting inversions by checking current number with all the next numbers
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = i+1; j <arr.size(); j++)
        {
            // if next number is smaller that means we'll need to shift that many places
            if(arr[i] > arr[j])
                sum += 1;
        }
    }
    if (sum % 2 == 0)
        return "YES";
    return "NO";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        cout << larrysArray(arr) << endl;
    }
}