#include<bits/stdc++.h>
using namespace std;
vector<int> bfsg(int V, vector<int> adj[]) {
        // Code here
        vector<int>bfs;
        vector<bool>visited(V,true);

        queue<int>q;
        q.push(0);

                while(!q.empty())
                {
                    int node=q.front();
                    cout<<node<<endl;
                    q.pop();

                    if(visited[node])
                    {
                         bfs.push_back(node);
                    visited[node]=false;

                    for(auto it:adj[node])
                    {
                            q.push(it);

                    }
                    }

            }
        return bfs;

    }
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector<int>adj[V];

        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        vector<int>ans=bfsg(V,adj);
        for(int i=0;i<ans.size();i++)
        {
            cout<< ans[i] <<" ";
        }
        cout<<endl;
    }
}
