// solution to the problem Shuffle in IEEEXtreme-11.0 

#include <iostream>
#include <string.h>
using namespace std;
#define M 200
#define N 200

bool bpm(bool bpGraph[M][N], int u, bool seen[], int matchR[])
{
    for (int v = 0; v < N; v++)
    {
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true; 
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
int maxBPM(bool bpGraph[M][N])
{
    int matchR[N];
 
    memset(matchR, -1, sizeof(matchR));
 
    int result = 0; 
    for (int u = 0; u < M; u++)
    {
        bool seen[N];
        memset(seen, 0, sizeof(seen));
 
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}
int main()
{
    int n,i,j,a;
    char temp;
    cin>>n;
    bool bpGraph[200][200] = {0};
    for(i=0;i<n;i++)
    {
        int hash[n] = {0};
        do
        {
            scanf("%d%c", &a, &temp); 
            hash[a] = 1; 
        } while(temp!= '\n');
        for(j=0;j<n;j++)
        {
            if(hash[j]==0&&j!=i)
                bpGraph[i][j] = 1;
        }
    }
    cout<<n - maxBPM(bpGraph);
    return 0;
}
