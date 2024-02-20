#include <iostream>
#include <vector>

using namespace std;

// Eg n = 10 , k = 5
// 1 - 6 = 5
// 2 - 7 = 5
// 3 - 8 = 5
// 4 - 9 = 5
// 5 - 10 = 5
// 6 - 1 = 5
// 7 - 2 = 5
// 8 - 3 = 5
// 9 - 4 = 5
// 10 - 5 = 5

// here n % 2 * k == 0

// in case n % 2k != 0

// n = 5 , k = 2
// 1 - 3 = 2
// 2 - 4 = 2
// 3 - 1 = 2
// 4 - 2 = 2
// 5 is left now as all values of i are already utilized

vector<int> absolutePermutation(int n , int k)
{
    vector<int> result;
    // case when k = 0 it means each number will have to subtract itself , so returning all values upto n
    if(k == 0)
    {
        for(int i = 1; i <= n; i++ )
            result.push_back(i);
        return result;
    }
    
    // Incase n is not a multiple of 2*k , returning because it can't be absolutely permuted, reason is explained at the top
    if(n % (2*k) != 0)
    {
        result = {-1};
        return result;
    }
    
    // When n is a mulitple of 2k
    else{
        // find out the number of groups formed , can be calculated by n/2k , loop will only continue for these many times
        for(int i = 0; i < n/(2*k) ; i++)
        {
            // fillling first half entries 
            // Note : 2*k*i will shift us to the groups
            for(int j = 1; j <= k; j++)
            {
                result.push_back((2*k*i) + j+k);
            }
            
            // filling second half entries
            for(int j = 1; j <= k; j++)
            {
                result.push_back((2*k*i) + j);
            }
        }
        return result;
    }
    
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n , k;
        cin >> n >> k;
        vector<int> result = absolutePermutation(n, k);
        for(int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}