class Solution {
public:
    void dfs(vector<set<int>>&adj, vector<bool>&vis, vector<bool>&comp, int src){
        vis[src] = true;
        comp[src] = true;

        for(int v : adj[src]){
            if(!vis[v]){
                dfs(adj,vis,comp,v);
            }
        }

        return;
    }

    bool isComplete(vector<set<int>>&adj, vector<bool>&comp){
        vector<int>curr;

        for(int i=0; i<comp.size(); i++){
            if(comp[i]) curr.push_back(i);
        }

        for(int i=0; i<curr.size(); i++){
            for(int j=0; j<curr.size(); j++){
                if(i == j) continue;
                if(adj[curr[i]].find(curr[j]) == adj[curr[i]].end()) return false;
            }
        }

        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<set<int>>adj(n);
        vector<bool>vis(n,false);

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].insert(v);
            adj[v].insert(u);
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                vector<bool>comp(n,false);
                dfs(adj,vis,comp,i);
                int noComp = 0;
                for(int j=0; j<comp.size(); j++){
                    if(comp[j]) noComp++;
                }

                if(noComp == 1 || noComp == 2){
                    count++;
                    continue;
                }

                if(isComplete(adj,comp)) count++; 
            }
        }

        return count;
    }
};