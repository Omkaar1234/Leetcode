class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s(nums.begin(), nums.end());
        vector<int>copy(s.begin(), s.end());
        sort(copy.begin() , copy.end());

        int m = copy.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(copy[i-1] == nums[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};