#include <bits/stdc++.h>
using namespace std;

// range update
// point query
class bit
{
private:
    int n_;
    vector<int> t;

    void update(int idx, int val)
    {
        for (; idx < n_; idx = idx | (idx + 1)) {
            t[idx] += val;
        }
    }

public:
    bit(int n) : n_(n), t(vector<int>(n, 0)) {}

    bit(vector<int> a) : bit(a.size())
    {
        for (int i = 0; i < n_; ++i) {
            update(i, i, a[i]);
        }
    }

    void update(int l, int r, int val)
    {
        update(l, val);
        update(r + 1, -val);
    }

    int get(int idx)
    {
        int ans = 0;
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
            ans += t[idx];
        }
        return ans;
    }
};

// range query
// point update
class bit
{
private:
    int n_;
    vector<int> t;

    int sum(int idx)
    {
        int ans = 0;
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
            ans += t[idx];
        }
        return ans;
    }

public:
    bit(int n) : n_(n), t(vector<int>(n, 0)) {}

    bit(vector<int> a) : bit(a.size())
    {
        for (int i = 0; i < n_; ++i) {
            update(i, a[i]);
        }
    }

    void update(int idx, int val)
    {
        for (; idx < n_; idx = idx | (idx + 1)) {
            t[idx] += val;
        }
    }

    int sum(int l, int r)
    {
        if (l == 0) {
            return sum(r);
        }
        return sum(r) - sum(l - 1);
    }
};