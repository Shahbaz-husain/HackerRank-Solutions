#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int maximumToys(vector<ll> prices, ll k){
    int toys = 0;
    
    // sorting the toys according to their prices
    sort(prices.begin(), prices.end());
    
    // iterating over each toy
    for(ll i = 0; i < prices.size(); i++){
        
        // if the current toy price is greater than current amount left , break
        if(k < prices[i])
            break;
        
        // else incrementing toys count and substracting the price from our available amount
        k -= prices[i];
        toys++;
    }
    
    return toys;
}

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> prices(n);
    for(ll i = 0; i < n; i++)
        cin >> prices[i];
        
    cout << maximumToys(prices, k);
}