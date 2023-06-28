///cycle detection---
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
bool vis[N];
vector<int>g[N];

bool dfs(int vertex,int par)
{
    vis[vertex]=true;
    bool isloopexist=false;
    for(auto child:g[vertex])
    {
        if(vis[child] && child==par)continue;
        if(vis[child])return true;

        isloopexist |=dfs(child,vertex);
    }
    return isloopexist;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bool isloopexist=false;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        if(dfs(i,0))
        {
            isloopexist=true;
            break;
        }

    }
    if(isloopexist)cout<<"YES CYCLE EXIST"<<endl;
    else cout<<"NO CYCLE EXIST"<<endl;
    }
}
