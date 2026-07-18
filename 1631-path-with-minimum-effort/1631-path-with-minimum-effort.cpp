class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        if(n == 1 && m == 1) return 0;

        vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
        effort[0][0] = 0;

        priority_queue<tuple<int,int,int> ,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});

        while(!pq.empty()){
            auto [currEffort, i, j] = pq.top();
            pq.pop();

            if(i-1 >= 0 && effort[i-1][j] > max(currEffort,abs(heights[i-1][j] - heights[i][j]))){
                effort[i-1][j] = max(currEffort, abs(heights[i-1][j] - heights[i][j]));
                pq.push({effort[i-1][j], i-1, j});
            }

            if(i+1 < n && effort[i+1][j] > max(currEffort, abs(heights[i+1][j] - heights[i][j]))){
                effort[i+1][j] = max(currEffort ,abs(heights[i+1][j] - heights[i][j]));
                pq.push({effort[i+1][j], i+1, j});
            }

            if(j-1 >= 0 && effort[i][j-1] > max(currEffort, abs(heights[i][j-1] - heights[i][j]))){
                effort[i][j-1] = max(currEffort, abs(heights[i][j-1] - heights[i][j]));
                pq.push({effort[i][j-1], i, j-1});
            }

            if(j+1 < m && effort[i][j+1] > max(currEffort, abs(heights[i][j+1] - heights[i][j]))){
                effort[i][j+1] = max(currEffort, abs(heights[i][j+1] - heights[i][j]));
                pq.push({effort[i][j+1], i, j+1});
            }
        }

        return effort[n-1][m-1];
    }
};