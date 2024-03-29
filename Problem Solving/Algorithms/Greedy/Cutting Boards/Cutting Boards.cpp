#include <bits/stdc++.h>

using namespace std;

typedef unsigned long ul;

int boardCutting(vector<int> cost_y, vector<int> cost_x) {
    ul minCost = 0;
    ul xmul = 1, ymul = 1;
    ul xi = 0, yi = 0;
    
    // sorting the vectors in descending order
    sort(cost_x.begin(), cost_x.end() , greater<ul>());
    sort(cost_y.begin(), cost_y.end() , greater<ul>());
    
    
    // while neither of the vector is completely iterated
    while(xi != cost_x.size() or yi != cost_y.size()){
        
        // if cost_x is completely iterated , then calculating the remaining costs of y
        if(xi == cost_x.size()){
            while(yi != cost_y.size()){
                minCost += ymul * cost_y[yi];
                yi++;
            }
        }
        
        // if cost_y is completely iterated , then calculating the remaining costs of x
        else if(yi == cost_y.size()){
            while(xi != cost_x.size()){
                minCost += xmul * cost_x[xi];
                xi++;
            }
        }
        
        // Else calculating minCost depending on the min of cost_x and cost_y at respective indices
        else if(cost_x[xi] > cost_y[yi]){
            minCost += xmul * cost_x[xi];
            ymul++;
            xi++;
        }
        else{
            minCost += ymul * cost_y[yi];
            xmul++;
            yi++;
        }
    }
    
    return minCost % 1000000007;
}

int main()
{
    int q;
    cin >> q;
    while(q--){
        ul m , n;
        cin >> m >> n;
        
        // indexing starting from 1 not from 0, so storing one element less
        vector<int> cost_y(m - 1);
        vector<int> cost_x(n - 1);
        
        for(int i = 0; i < m - 1; i++)
            cin >> cost_y[i];
        
        for(int i = 0; i < n - 1; i++)
            cin >> cost_x[i];
            
        cout << boardCutting(cost_y,cost_x) << endl;
    }
}
