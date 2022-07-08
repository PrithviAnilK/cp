#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18 + 1;

// ref: last 2 problems of
// https://codeforces.com/edu/course/2/lesson/9/2

// for min, max
class stack
{
private:
    std::stack<ll> s, smin, smax;

public:
    stack()
    {
        smin.push(INF);
        smax.push(-INF);
    }

    void push(ll x)
    {
        s.push(x);
        smin.push(std::min(smin.top(), x));
        smax.push(std::max(smax.top(), x));
    }

    void pop()
    {
        s.pop();
        smin.pop();
        smax.pop();
    }

    ll top() { return s.top(); }

    ll max() { return smax.top(); }

    ll min() { return smin.top(); }

    bool empty() { return s.empty(); }
};

// for gcd
class stack
{
    std::stack<ll> s, sgcd;

public:
    stack() { sgcd.push(0); }

    void push(ll x)
    {
        s.push(x);
        sgcd.push(__gcd(sgcd.top(), x));
    }

    void pop()
    {
        s.pop();
        sgcd.pop();
    }

    ll gcd() { return sgcd.top(); }

    ll top() { return s.top(); }

    bool empty() { return s.empty(); }
};

// maintain two stacks for your segment/range [l, r]
// s1 contains all from l..i
// s2 from i + 1 .. r
// each could be empty

// when pushing, push into s2
// when popping, pop from s1
// if s1 is empty, pop all from s2 and add to s1
// then pop

// s1 and s2 will contain all elements of l..r
// any function f from l..r will be f(s1.f(), s2.f())
// like this
ll f(::stack s1, ::stack s2) { return min(s1.min(), s2.min()); }
// this works for min, max, gcd.

// example
int main()
{
    int n;
    vector<ll> a(n);
    ::stack s1, s2;
    for (int l = 0, r = 0; r < n; ++r) {
        s2.push(a[r]);
        while (...) {
            if (s1.empty()) {
                while (!s2.empty()) {
                    s1.push(s2.top());
                    s2.pop();
                }
            }
            s1.pop();
            ++l;
        }
    }
    return 0;
}