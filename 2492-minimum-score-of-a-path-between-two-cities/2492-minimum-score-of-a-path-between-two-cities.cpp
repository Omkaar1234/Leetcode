class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][2],roads[i][1]});
            adj[roads[i][1]].push_back({roads[i][2],roads[i][0]});
        }

        vector<bool>vis(n+1,false);
        vector<bool>isComponent(n+1,false);

        queue<int>q;
        q.push(1);
        vis[1] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto v : adj[curr]){
                if(!vis[v.second]){
                    vis[v.second] = true;
                    q.push(v.second);
                }
            }
        }

        int score = INT_MAX;
        for(int i=1; i<=n; i++){
            if(vis[i]){
                for(auto v : adj[i]){
                    score = min(score,v.first);
                }
            }
        }

        return score;
    }
};