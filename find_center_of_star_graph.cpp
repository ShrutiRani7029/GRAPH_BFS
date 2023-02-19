#include<bits/stdc++.h>
using namespace std;
int fun(vector<vector<int>>&edges)
{
    int n=0;
    for(int i=0;i<edges.size();i++)
    {
        n=max(n,max(edges[i][0],edges[i][1]));
    }
    //cout<<n;
    vector<int>indegree(n+1);
    for(int i=0;i<edges.size();i++)
    {
        indegree[edges[i][0]]++;
        indegree[edges[i][1]]++;

    }
    int result=0;
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==n-1)
        {
            result=i;
            break;
        }
    }
    return result;
}
int main()
{
    vector<vector<int>>edges{{1,2},{5,1},{1,3},{1,4}};
    cout<<fun(edges);
}
