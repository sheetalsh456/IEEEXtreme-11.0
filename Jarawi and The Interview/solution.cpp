#include <bits/stdc++.h>
using namespace std;

#define ll long long
//#define l long

#define MAX 1000005
#define MOD 1000007

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

string s, p;
vector<int> v[26];

int main()
{
	cin >> s;
	int q, i;
	fin(i, 0, s.size()-1)
	{
		v[s[i]-'a'].pb(i);
	}
	sd(q);
	while(q--)
	{
		cin >> p;
		int last_index = s.size();
		vector<int>::iterator last_it;
		for(i = p.size() - 1; i >= 0; i--)
		{
			last_it = upper_bound(v[p[i] - 'a'].begin(), v[p[i] - 'a'].end(), last_index - 1);
			if(last_it == v[p[i]-'a'].begin())
				break;
			last_it--;
			last_index = *last_it;
			//cout << last_index << " ";
		}
		//cout << endl;
		cout << p.size() - i - 1 << endl;
	}
}
