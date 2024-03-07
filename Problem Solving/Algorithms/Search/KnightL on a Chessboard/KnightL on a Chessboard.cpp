#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define mp(first, second) make_pair(first, second)

typedef unsigned long long ul;
typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n;
vector<vi> ansMatrix;
vector<vi> chessBoard;

void tryAdd(int tRow, int tCol, int pRow, int pCol, queue<ii> &q)
{
    if (tRow < 0 || tRow >= chessBoard.size() || tCol < 0 || tCol >= chessBoard[0].size() || chessBoard[tRow][tCol] != 0)
        return;

    chessBoard[tRow][tCol] = chessBoard[pRow][pCol] + 1;
    q.push(mp(tRow, tCol));
}

void bfs(int sRow, int sCol)
{
    queue<ii> q;
    q.push(mp(0, 0));
    ++sRow; ++sCol;

    int dx[] = {-sRow, -sRow, +sRow, +sRow, -sCol, -sCol, +sCol, +sCol};
    int dy[] = {-sCol, +sCol, -sCol, +sCol, -sRow, +sRow, +sRow, -sRow};

    while (!q.empty())
    {
        ii curr = q.front();
        q.pop();

        for (size_t i = 0; i < 8; i++)
            tryAdd(curr.first + dx[i], curr.second + dy[i], curr.first, curr.second, q);
    }

    if (chessBoard[n - 1][n - 1] != 0)
        ansMatrix[sRow - 1][sCol - 1] = chessBoard[n - 1][n - 1];
    else
        ansMatrix[sRow - 1][sCol - 1] = -1;

    chessBoard.clear();
    chessBoard.resize(n, vi(n, 0));
}

int main()
{

    cin >> n;
    ansMatrix.resize(n - 1, vi(n - 1, -1));
    chessBoard.resize(n, vi(n, 0));

    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - 1; j++)
        {
            bfs(i, j);
        }
    }

    for (int i = 0; i < ansMatrix.size(); i++)
    {
        for (int j = 0; j < ansMatrix[0].size(); j++)
        {
            cout << ansMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}