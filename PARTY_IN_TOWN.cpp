
class Solution{
public:

    

    int bfs(vector<vector<int>>&adj,int src,int N){
        //1:0, 2:1, 3:2, 4:2
          queue<int>q;
        
        vector<int>dist(N+1, INT_MAX);
        ///sbse phle wala src ka distance zero hona chahiye
        dist[src]=0;
      
        q.push(src);
        int ans=INT_MIN;
        while(q.size()>0){
            
            int curr=q.front();
            q.pop();
            
            for(auto child: adj[curr]){
                 
                if(dist[child]==INT_MAX)
                
                {
                q.push(child);   
                dist[child]=dist[curr]+1;
                ans=max(dist[child],ans);
               
                }
            }
        }
        return ans;
    }


    int partyHouse(int N, vector<vector<int>> &adj){
        // code here
        int ans=INT_MAX;
        for(int i=1;i<=N;i++){
            ans=min(ans,bfs(adj,i,N));
        }
        return ans;
        
        
    }
};
