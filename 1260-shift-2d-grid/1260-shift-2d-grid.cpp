class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int el = n * m;
        k = k % el;

        vector<vector<int>>ans(n,vector<int>(m));

        vector<int>store;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                store.push_back(grid[i][j]);
            }
        }

        int r = 0;
        int c = 0;

        int idx = store.size()-k;

        for(int i=idx; i<store.size(); i++){
            if(c > m-1){
                r++;
                c = 0;
            }
            ans[r][c] = store[i];
            c++;
        }

        for(int i=0; i<idx; i++){
            if(c > m-1){
                r++;
                c = 0;
            }
            ans[r][c] = store[i];
            c++;
        }

        return ans;
    }
};