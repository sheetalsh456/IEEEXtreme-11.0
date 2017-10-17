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

char grid[1005][1005];
bool visited[1005][1005];
int w, h;

void dfs(int i, int j, char op)
{
	if(i<0 || i>=h || j<0 || j>=w)
		return;

	if(visited[i][j])
		return;

	if(grid[i][j] == '0')
		return;

	visited[i][j] = true;

	if(op == '+')
	{
		dfs(i, j+1, op);
		dfs(i, j-1, op);
		dfs(i+1, j, op);
		dfs(i-1, j, op);
	}
	else if(op == 'x')
	{
		dfs(i-1, j+1, op);
		dfs(i-1, j-1, op);
		dfs(i+1, j+1, op);
		dfs(i+1, j-1, op);
	}
	else
	{
		dfs(i, j+1, op);
		dfs(i, j-1, op);
		dfs(i+1, j, op);
		dfs(i-1, j, op);
		dfs(i-1, j+1, op);
		dfs(i-1, j-1, op);
		dfs(i+1, j+1, op);
		dfs(i+1, j-1, op);
	}
	return;
}

int components(char op)
{
	memset(visited, false, sizeof(visited));
	int i, j, result = 0;
	fin(i, 0, h-1)
		fin(j, 0, w-1)
		{
			if(grid[i][j] == '1' && !visited[i][j])
			{
				dfs(i, j, op);
				result++;
			}
		}
	return result;
}

int main()
{
	int t, i, j;
	sd(t);
	while(t--)
	{
		sd(w);
		sd(h);
		fin(i, 0, h-1)
			scanf(" %s", grid[i]);
		printf("%d %d %d\n", components('+'), components('x'), components('*'));
	}
	return 0;
}
