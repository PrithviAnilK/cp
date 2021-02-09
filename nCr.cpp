// to use nCr -> ans = binomial_coefficient(n, r)%MOD

long long MOD = 1000000007;
long long fact[100001];
fact[0] = 1;

void factorial()
{
    for (int i = 1; i < 100001; i++)
    {
        fact[i] = ((fact[i - 1] % MOD) * (i % MOD)) % MOD;
    }
}

long long pow(long long a, long long b)
{
    long long x = 1, y = a;
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

long long inv(long long n)
{
    return pow(n, MOD - 2);
}

long long binomial_coefficient(int n, int k)
{
    if (k == 0)
        return 1;
    return fact[n] * inv(fact[k]) % MOD * inv(fact[n - k]) % MOD;
}
