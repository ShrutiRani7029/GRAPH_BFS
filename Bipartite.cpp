#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>adj[N];


bool check(int n,vector<int>&visited,int src)
{
    queue<int>q;
    q.push(src);
    visited[src]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        int color=visited[x];
        //vector<int>v=adj[x];

        for(auto neighbour:adj[x])
        {
            if(visited[neighbour]!=-1)//already coloured
            {
                if(visited[neighbour]==color)return false;
            }
            else
            {
                if(color==0)
                {
                    visited[neighbour]=1;
                }
                else visited[neighbour]=0;
                q.push(neighbour);
            }
        }

    }
     return true;

}
bool checkbp(int n)
{
    vector<int>colorvis(n,-1);
    for(int i=0;i<n;i++)
    {
        if(colorvis[i]==-1)
        {
            if(check(n,colorvis,i)==false)return false;
        }
    }
    return true;
}
int main()
{

    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool ans=checkbp(v);
    if(ans)cout<<"1\n"<<endl;
    else cout<<"0\n"<<endl;
}
