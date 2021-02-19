const int mxN = 1e5; // max number of factorials to compute
ll fact[mxN + 1];
ll inv[mxN + 1];

// a ^ b % MOD
ll pow(ll a, ll b)
{
    ll x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y);
            if (x > MOD)
                x %= MOD;
        }
        y = (y * y);
        if (y > MOD)
            y %= MOD;
        b /= 2;
    }
    return x;
}

// precomputes fact and inv arrays
void factorial()
{
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= mxN; i++)
    {
        fact[i] = ((fact[i - 1] % MOD) * (i % MOD)) % MOD;
        inv[i] = pow(fact[i], MOD - 2);
    }
}

// produces nCr % MOD
ll nCr(int n, int r)
{
    if (n < 0 || r < 0 || n < r)
        return 0;
    return (fact[n] * ((inv[n - r] * inv[r]) % MOD)) % MOD;
}