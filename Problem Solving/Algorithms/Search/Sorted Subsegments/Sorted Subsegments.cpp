#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define rer(i, l, u) for (int(i) = (int)(l); (i) <= (int)(u); ++(i))
#define reu(i, l, u) for (int(i) = (int)(l); (i) < (int)(u); ++(i))
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef long long ll;
template <typename T, typename U>
static void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
template <typename T, typename U>
static void amax(T &x, U y)
{
    if (x < y)
        x = y;
}

typedef char Val;
struct Sum
{
    int cnt;
    Sum() : cnt(0) {}
    Sum(const Val &val, int pos) : cnt(val) {}
    Sum &operator+=(const Sum &that)
    {
        cnt += that.cnt;
        return *this;
    }
    Sum operator+(const Sum &that) const { return Sum(*this) += that; }
};
struct Add
{
    int assign;
    Add() : assign(-1) {}
    explicit Add(int a) : assign(a) {}
    Add &operator+=(const Add &that)
    {
        if (that.assign != -1)
            assign = that.assign;
        return *this;
    }
    void addToVal(Val &val, int pos) const
    {
        if (assign != -1)
            val = assign != 0;
    }
    void addToSum(Sum &sum, int left, int right) const
    {
        if (assign != -1)
            sum.cnt = assign != 0 ? right - left : 0;
    }
};

struct SegmentTree
{
    vector<Val> leafs;
    vector<Sum> nodes;
    vector<Add> add;
    vector<int> leftpos, rightpos;
    int n, n2;
    void init(int n_, const Val &v = Val()) { init(vector<Val>(n_, v)); }
    void init(const vector<Val> &u)
    {
        n = 1;
        while (n < (int)u.size())
            n *= 2;
        n2 = (n - 1) / 2 + 1;
        leafs = u;
        leafs.resize(n, Val());
        nodes.resize(n);
        for (int i = n - 1; i >= n2; --i)
            nodes[i] = Sum(leafs[i * 2 - n], i * 2 - n) + Sum(leafs[i * 2 + 1 - n], i * 2 + 1 - n);
        for (int i = n2 - 1; i > 0; --i)
            nodes[i] = nodes[i * 2] + nodes[i * 2 + 1];
        add.assign(n, Add());

        leftpos.resize(n);
        rightpos.resize(n);
        for (int i = n - 1; i >= n2; --i)
        {
            leftpos[i] = i * 2 - n;
            rightpos[i] = (i * 2 + 1 - n) + 1;
        }
        for (int i = n2 - 1; i > 0; --i)
        {
            leftpos[i] = leftpos[i * 2];
            rightpos[i] = rightpos[i * 2 + 1];
        }
    }
    Val get(int i)
    {
        int indices[128];
        int k = getIndices(indices, i, i + 1);
        propagateRange(indices, k);
        return leafs[i];
    }
    Sum getRangeCommutative(int i, int j)
    {
        int indices[128];
        int k = getIndices(indices, i, j);
        propagateRange(indices, k);
        Sum res = Sum();
        for (int l = i + n, r = j + n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res += sum(l++);
            if (r & 1)
                res += sum(--r);
        }
        return res;
    }
    Sum getRange(int i, int j)
    {
        int indices[128];
        int k = getIndices(indices, i, j);
        propagateRange(indices, k);
        Sum res = Sum();
        for (; i && i + (i & -i) <= j; i += i & -i)
            res += sum((n + i) / (i & -i));
        for (k = 0; i < j; j -= j & -j)
            indices[k++] = (n + j) / (j & -j) - 1;
        while (--k >= 0)
            res += sum(indices[k]);
        return res;
    }
    void set(int i, const Val &x)
    {
        int indices[128];
        int k = getIndices(indices, i, i + 1);
        propagateRange(indices, k);
        leafs[i] = x;
        mergeRange(indices, k);
    }
    void addToRange(int i, int j, const Add &x)
    {
        if (i >= j)
            return;
        int indices[128];
        int k = getIndices(indices, i, j);
        propagateRange(indices, k);
        int l = i + n, r = j + n;
        if (l & 1)
        {
            int p = (l++) - n;
            x.addToVal(leafs[p], p);
        }
        if (r & 1)
        {
            int p = (--r) - n;
            x.addToVal(leafs[p], p);
        }
        for (l >>= 1, r >>= 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                add[l++] += x;
            if (r & 1)
                add[--r] += x;
        }
        mergeRange(indices, k);
    }

private:
    int getIndices(int indices[], int i, int j) const
    {
        int k = 0, l, r;
        if (i >= j)
            return 0;
        for (l = (n + i) >> 1, r = (n + j - 1) >> 1; l != r; l >>= 1, r >>= 1)
        {
            indices[k++] = l;
            indices[k++] = r;
        }
        for (; l; l >>= 1)
            indices[k++] = l;
        return k;
    }
    void propagateRange(int indices[], int k)
    {
        for (int i = k - 1; i >= 0; --i)
            propagate(indices[i]);
    }
    void mergeRange(int indices[], int k)
    {
        for (int i = 0; i < k; ++i)
            merge(indices[i]);
    }
    inline void propagate(int i)
    {
        if (i >= n)
            return;
        add[i].addToSum(nodes[i], leftpos[i], rightpos[i]);
        if (i * 2 < n)
        {
            add[i * 2] += add[i];
            add[i * 2 + 1] += add[i];
        }
        else
        {
            add[i].addToVal(leafs[i * 2 - n], i * 2 - n);
            add[i].addToVal(leafs[i * 2 + 1 - n], i * 2 + 1 - n);
        }
        add[i] = Add();
    }
    inline void merge(int i)
    {
        if (i >= n)
            return;
        nodes[i] = sum(i * 2) + sum(i * 2 + 1);
    }
    inline Sum sum(int i)
    {
        propagate(i);
        return i < n ? nodes[i] : Sum(leafs[i - n], i - n);
    }
};

int main()
{
    int n;
    int q;
    int k;
    while (~scanf("%d%d%d", &n, &q, &k))
    {
        vector<int> A(n);
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        vector<int> l(q), r(q);
        for (int i = 0; i < q; ++i)
            cin >> l[i] >> r[i], ++r[i];
        vi values = A;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        int lo = 0, up = (int)values.size() - 1;
        while (up - lo > 0)
        {
            int mid = (lo + up + 1) / 2;
            vector<Val> initvals(n);
            rep(i, n)
                initvals[i] = values[mid] <= A[i];
            SegmentTree segt;
            segt.init(initvals);
            rep(i, q)
            {
                int cnt0 = r[i] - l[i] - segt.getRangeCommutative(l[i], r[i]).cnt;
                segt.addToRange(l[i], l[i] + cnt0, Add(0));
                segt.addToRange(l[i] + cnt0, r[i], Add(1));
            }
            if (segt.get(k))
                lo = mid;
            else
                up = mid - 1;
        }
        cout << values[lo] << endl;
    }
}