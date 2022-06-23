#include <bits/stdc++.h>
using namespace std;

long long const MOD = 1e9 + 7;

long long multiply(long long a, long long b)
{
    long long mod = MOD;
    long long res = 0;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res + a) % mod;
        }
        a = (a * 2) % mod;
        b /= 2;
    }
    return res % mod;
}