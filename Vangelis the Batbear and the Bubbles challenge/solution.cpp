// Added solution to problem Vangelis the Batbear and the Bubbles challenge of IEEEXtreme-11.0

#include<bits/stdc++.h>
#include <iostream>

using namespace std;
int t,n,m,v1,v2,i;
bool isCycleUtil(int v, bool visited[], int parent,list<int> adj[])
{
    visited[v]=true;
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
        {
            if(isCycleUtil(*i,visited,v,adj))
                return true;
        }
        else if(*i!=parent)
            return true;
    }
    return false;
}
bool isCycle(list<int> adj[])
{
    bool *visited = new bool[n];
        for(i=0;i<n;i++)
            visited[i]=false;
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(isCycleUtil(i,visited,-1,adj))
                    return true;
            }
        }
        return false;
}
int main() {
    cin >> t;
    while(t--)
    {
        list<int> adj[1002];
        cin >> n >> m;
        for(i=0;i<m;i++)
        {
            cin >> v1 >> v2;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        if(isCycle(adj))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}
