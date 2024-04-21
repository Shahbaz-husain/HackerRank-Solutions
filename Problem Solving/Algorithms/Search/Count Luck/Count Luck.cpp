#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

int hantai(int dir) {
  if (dir == LEFT) return RIGHT;
  if (dir == UP) return DOWN;
  if (dir == RIGHT) return LEFT;
  if (dir == DOWN) return UP;
  return -1;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    string mMap[n];
    for (int j = 0; j < n; j++) cin >> mMap[j];
    int kk;
    cin >> kk;
    int sx, sy;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (mMap[j][k] == 'M') {
          sx = k;
          sy = j;
          break;
        }
      }
    }
    // for (int j = 0; j < n; j++) {
    //   for (int k = 0; k < m; k++) {
    //     cout << char(mMap[j][k]);
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    int memo[n][m];
    memset(memo, 0, sizeof(memo));
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    stack <int> st; // x y val dir
    int cnt = 0;
    for (int j = 0; j < 4; j++) {
      int nx = sx+dx[j];
      int ny = sy+dy[j];
      if (nx >= 0 && ny >= 0 && nx < m && ny < n && mMap[ny][nx] == '.') cnt++;
    }
    for (int j = 0; j < 4; j++) {
      int nx = sx+dx[j];
      int ny = sy+dy[j];
      if (nx >= 0 && ny >= 0 && nx < m && ny < n && mMap[ny][nx] == '.') {
        st.push(sx);
        st.push(sy);
        if (cnt >= 2) {
          st.push(1);
        }else {
          st.push(0);
        }
        st.push(j);
      }
    }

    int ans = 0;
    bool goal = false;
    while (!st.empty() && !goal) {
      int dir = st.top(); st.pop();
      int val = st.top(); st.pop();
      int py = st.top(); st.pop();
      int px = st.top(); st.pop();

      int nx = px;
      int ny = py;
      while (true) {
        nx += dx[dir];
        ny += dy[dir];
        if (nx >= 0 && ny >= 0 && nx < m && ny < n && mMap[ny][nx] == '*') {
          goal = true;
          ans = val;
        }

        if (nx < 0 || ny < 0 || nx >= m || ny >= n || mMap[ny][nx] == 'X') break;
        int cnt2 = 0;
        for (int j = 0; j < 4; j++) {
          int cx = nx+dx[j];
          int cy = ny+dy[j];
          if (cx >= 0 && cy >= 0 && cx < m && cy < n && mMap[cy][cx] != 'X' && j != hantai(dir)) cnt2++;
        }

        if (cnt2 >= 2) val++;
        for (int j = 0; j < 4; j++) {
          int cx = nx+dx[j];
          int cy = ny+dy[j];
          if (cx >= 0 && cy >= 0 && cx < m && cy < n && mMap[cy][cx] != 'X' && j != hantai(dir) && j != dir) {
            st.push(nx);
            st.push(ny);
            st.push(val);
            st.push(j);
          }
        }
      }
    }

    if (ans == kk) {
      cout << "Impressed" << endl;
    }else {
      cout << "Oops!" << endl;
    }
  }
}