class Solution {
public:
    bool isCycle(vector<vector<int>>&adj, vector<bool>&vis, vector<bool>&recPath, int src){
        vis[src] = true;
        recPath[src] = true;

        for(int v : adj[src]){
            if(!vis[v]){
                if(isCycle(adj,vis,recPath,v)) return true;
            }else{
                if(recPath[v]){
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<bool>vis(numCourses,false);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                vector<bool>recPath(numCourses,false);
                if(isCycle(adj,vis,recPath,i)) return false;
            }
        }

        return true;
    }
};