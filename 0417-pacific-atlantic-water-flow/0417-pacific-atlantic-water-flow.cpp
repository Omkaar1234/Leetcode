class Solution {
public:
    void dfs(vector<vector<int>>&heights, vector<vector<bool>>&vis,int i,int j){
        vis[i][j] = true;

        if(i-1 >= 0 && heights[i][j] <= heights[i-1][j] && !vis[i-1][j]){
            dfs(heights,vis,i-1,j);
        }

        if(i+1 < heights.size() && heights[i][j] <= heights[i+1][j] && !vis[i+1][j]){
            dfs(heights,vis,i+1,j);
        }

        if(j-1 >= 0 && heights[i][j] <= heights[i][j-1] && !vis[i][j-1]){
            dfs(heights,vis,i,j-1);
        }

        if(j+1 < heights[0].size() && heights[i][j] <= heights[i][j+1] && !vis[i][j+1]){
            dfs(heights,vis,i,j+1);
        }

        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));

        for(int j=0; j<m; j++){
            if(!pacific[0][j]){
                dfs(heights,pacific,0,j);
            }
        }

        for(int i=0; i<n; i++){
            if(!pacific[i][0]){
                dfs(heights,pacific,i,0);
            }
        }

        for(int j=m-1; j>=0; j--){
            if(!atlantic[n-1][j]){
                dfs(heights,atlantic,n-1,j);
            }
        }

        for(int i=n-1; i>=0; i--){
            if(!atlantic[i][m-1]){
                dfs(heights,atlantic,i,m-1);
            }
        }

        vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};