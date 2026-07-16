class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        map<pair<int,int>,int>mNum;
        unordered_map<int,pair<int,int>>mIdx;

        int currPos = 1;
        bool isEven = false;

        for(int i=n-1; i>=0 ; i--){
            if(isEven){
                for(int j=n-1; j>=0; j--){
                    mNum[{i,j}] = currPos;
                    mIdx[currPos] = {i,j};
                    currPos++;
                }
            }else{
                for(int j=0; j<n; j++){
                    mNum[{i,j}] = currPos;
                    mIdx[currPos] = {i,j};
                    currPos++;
                }
            }
            isEven = !isEven;
        }

        queue<int>q;
        vector<bool> vis(n*n+1, false);
        q.push(1);
        q.push(-1);

        vis[1] = true;

        int moves = 0;

        while(!q.empty()){
            int pos = q.front();
            q.pop();

            if(pos == -1){
                moves++;
                if(!q.empty()){
                    q.push(-1);
                }
                continue;
            }

            if(pos == n*n){ // Reached target
                return moves;
            }

            for(int nxt = pos+1; nxt <= min(n*n, pos+6); nxt++){
                auto [r,c] = mIdx[nxt];

                int dst = nxt;

                if(board[r][c] != -1){
                    dst = board[r][c];
                }

                if(!vis[dst]){
                    vis[dst] = true;
                    q.push(dst);
                }
            }
        }

        return -1 ;
    }
};