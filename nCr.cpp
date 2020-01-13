// to use nCr -> ans = binomial_coefficient(n, r)%MOD

ll MOD = 1000000007;
ll fact[100001];
fact[0] = 1;

void factorial()
{
    for(int i = 1;i < 100001;i++)
    {
        fact[i] = ((fact[i-1]%MOD)*(i%MOD))%MOD;
    }	
}

ll pow(ll a, ll b)
{
    ll x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}
 

ll inv(ll n)
{
    return pow(n,MOD-2);
}


long long binomial_coefficient(int n, int k) {
    if(k == 0) return 1;
    return fact[n] * inv(fact[k]) % MOD * inv(fact[n - k]) % MOD;
}
