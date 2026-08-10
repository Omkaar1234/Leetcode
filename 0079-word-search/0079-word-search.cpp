class Solution {
public:
    bool dfs(int i,int j, vector<vector<char>>&board ,string word, vector<vector<bool>>&vis, int idx){
        int n = board.size();
        int m = board[0].size();
        vis[i][j] = true;

        if(idx == word.size()) return true;

        if(i+1 < n && board[i+1][j] == word[idx] && !vis[i+1][j]){
            if(dfs(i+1,j,board,word,vis,idx+1)) return true;
        }

        if(i-1 >= 0 && board[i-1][j] == word[idx] && !vis[i-1][j]){
            if(dfs(i-1,j,board,word,vis,idx+1)) return true;
        }

        if(j+1 < m && board[i][j+1] == word[idx] && !vis[i][j+1]){
            if(dfs(i,j+1,board,word,vis,idx+1)) return true;
        }

        if(j-1 >= 0 && board[i][j-1] == word[idx] && !vis[i][j-1]){
            if(dfs(i,j-1,board,word,vis,idx+1)) return true;
        }

        vis[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>>vis(n, vector<bool>(m,false));
                    if(dfs(i,j,board,word,vis,1)) return true;
                }
            }
        }

        return false;
    }
};