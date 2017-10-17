#include <bits/stdc++.h>
using namespace std;

#define ll long long
//#define l long

#define MAX 1000005
//#define MOD 1000000007

#define fin(i,a,n) for(i=a;i<=n;i++)
#define fde(i,a,n) for(i=n;i>=a;i--)

#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%ld",&a)
#define slld(a) scanf("%lld",&a)

#define pd(a) printf("%d",a)
#define pld(a) printf("%ld",a)
#define plld(a) printf("%lld",a)
#define pn printf("\n")
#define ps printf(" ")

#define mp make_pair
#define pb push_back

using namespace std;

ll power(ll x, ll y, ll MOD)
{
    ll res = 1; 
    x %= MOD;  
    while (y)
    {
       	if (y & 1)
            res = (res*x) % MOD;
  
        y = y>>1; 
        x = (x*x) % MOD;
    }
    return res;
}

ll mmi(ll x, ll MOD)
{
	return power(x, MOD-2, MOD);
}

ll factorial(ll n, ll MOD)
{
	ll result = 1, i;
	fin(i, 2, n)
	{
		result *= i;
		if (result >= MOD)
			result %= MOD;
	}
	return result;
}

ll nCr(ll n, ll r, ll MOD)
{
	ll result = factorial(n, MOD);
	result *= mmi(factorial(r, MOD), MOD);
	if (result >= MOD)
		result %= MOD;
	result *= mmi(factorial(n-r, MOD), MOD);
	if (result >= MOD)
		result %= MOD;
	return result;
}

ll nCr2(ll n, ll r)
{
	while(r)
	{
		if( (r&1) && (!(n&1)) )
			return 0;
		n >>= 1;
		r >>= 1;
	}
	return 1;
}

ll CRT(ll n, ll r)
{
    ll prod = 1000000006;
 
    ll result = 0;
    ll num[2] = {2, 500000003};
    ll rem[2] = {nCr2(n, r), nCr(n, r, 500000003)};
    for (int i = 0; i < 2; i++)
    {
        ll pp = prod / num[i];
        result = result + ( ( ( ( rem[i] * mmi(pp, num[i]) ) % prod) * pp) % prod );
        if (result >= prod)
		 result %= prod;
    }
    return result % prod;
}

int main()
{
	ll t, a, b, c;
	slld(t);
	while(t--)
	{
		slld(a);
		slld(b);
		slld(c);
		ll d = CRT(b, c);
		ll result = power(a, d, 1000000007);
		plld(result);
		pn;
	}
}