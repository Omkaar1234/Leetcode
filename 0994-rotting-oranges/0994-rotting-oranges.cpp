class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        q.push({-1,-1});
        int minute = -1;

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            if(i == -1 && j == -1){
                minute++;
                if(q.empty()){
                    break;
                }
                q.push({-1,-1});
                continue;
            }

            if(i-1 >= 0 && grid[i-1][j] == 1){
                grid[i-1][j] = 2;
                q.push({i-1,j});
            }

            if(i+1 < n && grid[i+1][j] == 1){
                grid[i+1][j] = 2;
                q.push({i+1,j});
            }

            if(j-1 >= 0 && grid[i][j-1] == 1){
                grid[i][j-1] = 2;
                q.push({i,j-1});
            }

            if(j+1 < m && grid[i][j+1] == 1){
                grid[i][j+1] = 2;
                q.push({i,j+1});
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return minute;
    }
};