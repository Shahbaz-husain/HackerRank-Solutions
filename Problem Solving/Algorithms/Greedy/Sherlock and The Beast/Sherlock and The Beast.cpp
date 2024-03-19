#include <iostream>
using namespace std;

void decentNumber(int n) {
    int fives = -1;
    
    // Finding number of 5s which can be printed as they can be printed only multiple of 3 times
    for(int i = 0; 3*i <= n; i++){
        int threes = n - 3*i;
        
        // after finding 5s count , if 3s count is multiple of 5 , that will become number of 3s
        if(threes % 5 == 0)
            fives = 3*i;
    }
    
    // if after extracting 5s , 3s are not multiple of 5 returning -1 (can't form decent number)
    if(fives == -1){
        cout << "-1" << endl;
        return;
    }
    
    // else printing 5s first as we want maximum number
    for(int i = 0; i < fives; i++)
        cout << "5" ; 
    
    // then print 3 for remaining length
    for(int i = fives; i < n; i++)
        cout << "3" ;
    
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        decentNumber(n);
    }

    return 0;
}