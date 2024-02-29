#include <iostream>
#include <vector>

using namespace std;

vector<int> icecreamParlor(int m, vector<int> costs){
    vector<int> result;
    
    // checking every cost except the last one with the next remaining costs
    for(int i = 0; i < costs.size() -1; i++)
    {
        // only comparing with the next entries from the current pointer
        for(int j = i+1; j < costs.size(); j++)
        {
            // if sum of costs becomes equal to target , pushing the 1 based indices into the result
            if(costs[i] + costs[j] == m){
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }
        }
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k, n;
        cin >> k >> n;
        vector<int> costs(n);
        for(int i = 0; i < n; i++)
        {
            cin >> costs[i];
        }
        
        vector<int> result = icecreamParlor(k,costs);
        for(int i : result)
            cout << i << " ";
        cout << endl;
    }
}