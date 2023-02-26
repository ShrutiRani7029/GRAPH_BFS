#include<bits/stdc++.h>
using namespace std;

vector<int> eventualsafenodes(int v, vector<int> adj[]) {
    vector<int>vec[v];
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++)
        {
            for(auto it:adj[i])
            {
                vec[it].push_back(i);
                cout<<i<<" "<<indegree[i]<<endl;
                indegree[i]++;
            }
        }
        vector<int>safenode;
        queue<int>q;
        for(int i=0;i<v;i++)
        {
        if(indegree[i]==0)q.push(i);
        }


        while(!q.empty())
        {
            int node=q.front();
            safenode.push_back(node);
            q.pop();
            for(auto it:vec[node])
            {
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
            }
        }
        sort(safenode.begin(),safenode.end());
        return safenode;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int v,e;
        cin>>v>>e;
        vector<int>adj[v];

        for(int i=0;i<e;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        vector<int>safenodes = eventualsafenodes(v,adj);
        for(auto i:safenodes)
        {
            cout<< i <<" ";
        }
        cout<<endl;
    }
}
