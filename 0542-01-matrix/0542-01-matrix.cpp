class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            if(i+1 < n && dist[i+1][j] > dist[i][j] + 1){
                dist[i+1][j] = dist[i][j] + 1;
                q.push({i+1,j});
            }

            if(i-1 >= 0 && dist[i-1][j] > dist[i][j] + 1){
                dist[i-1][j] = dist[i][j] + 1;
                q.push({i-1,j});
            }

            if(j+1 < m && dist[i][j+1] > dist[i][j] + 1){
                dist[i][j+1] = dist[i][j] + 1;
                q.push({i,j+1});
            }

            if(j-1 >= 0 && dist[i][j-1] > dist[i][j] + 1){
                dist[i][j-1] = dist[i][j] + 1;
                q.push({i,j-1});
            }
        }

        return dist;
    }
};