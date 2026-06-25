class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<bool>&vis, int src){
        vis[src] = true;

        for(int v : adj[src]){
            if(!vis[v]){
                dfs(adj,vis,v);
            }
        }

        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1 > connections.size()) return -1;

        int unConnected = -1;
        vector<vector<int>> adj(n);

        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n,false);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                unConnected++;
            }
        }

        return unConnected;
    }
};