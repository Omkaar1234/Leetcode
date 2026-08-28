class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<char>>&grid, int n, int m){
        vis[i][j] = true;

        if(i+1 < n && grid[i+1][j] == '1' && !vis[i+1][j]){
            dfs(i+1,j,vis,grid,n,m);
        }

        if(i-1 >=0 && grid[i-1][j] == '1' && !vis[i-1][j]){
            dfs(i-1,j,vis,grid,n,m);
        }

        if(j+1 < m && grid[i][j+1] == '1' && !vis[i][j+1]){
            dfs(i,j+1,vis,grid,n,m);
        }

        if(j-1 >= 0 && grid[i][j-1] == '1' && !vis[i][j-1]){
            dfs(i,j-1,vis,grid,n,m);
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int island = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    island++;
                    dfs(i,j,vis,grid,n,m);
                }
            }
        }

        return island;
    }
};