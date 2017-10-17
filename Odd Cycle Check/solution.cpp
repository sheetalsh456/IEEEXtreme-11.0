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

vector<int> adjList[10005];
bool visited[10005], color[10005];

int a[10005],s[10005];

int root(int i)
{
    while(a[i]!=i)
    {
        a[i] = a[a[i]];
        i = a[i];
    }
    return i;
}

void _union(int p, int q)
{
    int x = root(p);
    int y = root(q);

    if(s[x]<s[y])
    {
        a[x] = y;
        s[y] += s[x];
    }
    else
    {
        a[y] = x;
        s[x] += s[y];
    }
}

bool _find(int p,int q)
{
    if(root(p)==root(q))
        return true;
    return false;
}

int dfs(int i)
{
	stack<int> s;
    s.push(i);
    color[i] = true;
    visited[i] = true;
    while(!s.empty())
    {
        int k = s.top();
        s.pop();
        for(int j=0;j<adjList[k].size();j++)
        {
            if(!visited[adjList[k][j]])
            {
                visited[adjList[k][j]]=true;
                color[adjList[k][j]] = !color[k];
                s.push(adjList[k][j]);
            } 
            else if(color[adjList[k][j]] == color[k])
            {
            	return 0;
            }
        }
    }
    return 1;
}

// use this to set your answer
void SetAnswer(int s) {
    pd(s);
    pn;
    fflush(stdout);
    if (s == 0) {
        exit(0);
    }
}

int main() {
    // use this to pass the first example
    int n, i; 
    sd(n);
    fin(i,1,n)
    {
        adjList[i].clear();
        a[i] = i;
        s[i] = 1;
        //cout << adjList[i].size();
    }
    while(1)
    {
    	int a, b; 
   	    sd(a);
   	    sd(b);
   	    adjList[a].push_back(b);
        adjList[b].push_back(a);
        if(!_find(a, b))
        {
        	_union(a,b);
        	SetAnswer(1);
        }
        else
        {
	    	memset(visited,false,sizeof(visited));
		    memset(color,false,sizeof(color));
	        int answer = dfs(root(a));
	    	SetAnswer(answer);
	    }
    }
    return 0;
}
