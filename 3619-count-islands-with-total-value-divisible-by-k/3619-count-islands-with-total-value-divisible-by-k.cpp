class Solution {
public:
    void dfs(vector<vector<int>>&grid, vector<vector<bool>>&vis,int i, int j, long long &val){
        vis[i][j] = true;
        val += grid[i][j];

        if(i + 1 < grid.size() && !vis[i+1][j] && grid[i+1][j] != 0){
            dfs(grid,vis,i+1,j,val);
        }

        if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] != 0){
            dfs(grid,vis,i-1,j,val);
        }

        if(j + 1 < grid[0].size() && !vis[i][j+1] && grid[i][j+1] != 0){
            dfs(grid,vis,i,j+1,val);
        }

        if(j - 1 >= 0 && !vis[i][j-1] && grid[i][j-1] != 0){
            dfs(grid,vis,i,j-1,val);
        }

        return;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<vector<bool>>vis(n, vector<bool>(m,false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    long long val = 0;
                    dfs(grid,vis,i,j,val);
                    if(val % k == 0) count++;
                }
            }
        }

        return count;
    }
};