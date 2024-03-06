#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Row {
    public:
    long row;
    long start;
    long end;
    long diff;
    bool operator<( const Row& t ) const {
        if (row != t.row) {
            return row < t.row;
        }
        
        return start < t.start;
    }
};

int main() {
    long n, m;
    int k;
    
    cin >> n >> m >> k;
    vector<Row> v(k);
    for(int i = 0; i < k; i++) {
        Row t;
        cin >> t.row >> t.start >> t.end;
        t.diff = t.end - t.start + 1;
        v[i] = t;
    }
    
    sort(v.begin(), v.end());
    
    // calculating filled cells
    long filled_cells = 0;
    int pt = -1;
    for(int i = 0; i < k; i++) {
        if (v[pt].row != v[i].row || v[pt].end < v[i].start) {
            filled_cells += v[i].diff;
        }
        else {
            // merging
            filled_cells -= v[pt].diff;
            v[i].start = v[pt].start;
            v[i].end = max(v[pt].end, v[i].end);
            v[i].diff = v[i].end - v[i].start + 1;
            filled_cells += v[i].diff;
        }
        
        pt = i;
    }
    
    // Calculting empty cells by substracting filled cells from total cells(n*m)
    long long total = n * m - filled_cells;
    cout << total << endl;
    return 0;
}