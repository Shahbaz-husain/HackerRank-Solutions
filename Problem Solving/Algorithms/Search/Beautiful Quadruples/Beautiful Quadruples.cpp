#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector<int> A(4);
    for(int i = 0; i < 4; i++) 
        cin >> A[i];
    sort(A.begin(), A.end());

    vector<long long> T(A[2]+1, 0);
    vector<vector<int> > P(1<<12);
    for(int i = 1; i <= A[0]; i++) 
    {
        for(int j = i; j <= A[1]; j++) 
        {
            T[j]++;
            P[i^j].push_back(j);
        }
    }
    for(int i = 1; i < T.size() ; i++)
        T[i] += T[i-1];
    for(int i = 0; i < P.size(); i++) 
        sort(P[i].begin(), P[i].end());

    long long ans = 0;
    for(int i = 1; i <= A[2]; i++) 
    {
        for(int j = i; j <= A[3]; j++)
        {
            long long tmp = T[i];
            if (!P[i^j].empty())
                tmp -= upper_bound(P[i^j].begin(), P[i^j].end(), i) - P[i^j].begin();
            ans += tmp;
        }
    }

    cout << ans << endl;
}