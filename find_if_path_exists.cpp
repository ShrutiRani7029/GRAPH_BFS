#include<bits/stdc++.h>
using namespace std;
bool bfs(int n, vector<vector<int>>&g,int source,int dest){


 queue<int>q;
 vector<int>vis(n+1,0);
 q.push(source);
 while(!q.empty())
 {
     int s=q.size();

     for(int i=0;i<s;i++){
        int x=q.front();
        if(x==dest)return true;
        q.pop();
        vis[x]=1;

        for(auto k:g[x]){
            q.push(k);
            vis[k]=1;
        }


     }
 }
 return false;
}

///first make it bidirectional,
bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> graph(n);
    for (auto edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    return bfs(n,graph, source, destination);
}


int main()

{

    int t,e;
    cin>>t>>e;
    vector<vector<int>>g(t+1);
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    int source,dest;
    cin>>source>>dest;
    bool isPath = bfs(t, g, source, dest);

    if (isPath) {
        cout << "There is a path from " << source << " to " << dest << endl;
    } else {
        cout << "There is no path from " << source << " to " << dest << endl;
    }
}
