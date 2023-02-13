///finding connected components in graph
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
bool vis[N];
vector<int>g[N];

void dfs(int vertex)
{

    vis[vertex]=true;
    for(int child:g[vertex])
    {
        if(vis[child])continue;
        dfs(child);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int ct=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        dfs(i);
        ct++;
    }
    cout<<ct<<endl;
    return 0;


}*/
///storing connected components in graph
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
bool vis[N];
vector<int>g[N];
vector<vector<int>>store;
vector<int>medium;

void dfs(int vertex)
{
    vis[vertex]=true;
    medium.push_back(vertex);
    for(auto child:g[vertex])
    {
        if(!vis[child])dfs(child);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        medium.clear();
        dfs(i);
        store.push_back(medium);
    }
    cout<<store.size()<<endl;
    for(auto it:store)
    {
        for(int vertex:it)
        {
            cout<<vertex<<" ";
        }
        cout<<endl;
    }
}
