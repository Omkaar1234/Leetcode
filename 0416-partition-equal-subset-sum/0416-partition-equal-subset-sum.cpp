class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int x : nums){
            totalSum += x;
        }

        if(totalSum % 2 != 0 ) return false;
        int n = nums.size();

        int tar = totalSum / 2;
        vector<vector<int>> dp(tar+1 , vector<int>(n+1,0));

        for(int i=1; i<=tar; i++){
            for(int j=1; j<=n; j++){
                if(nums[j-1] <= i){
                    dp[i][j] = max(dp[i][j-1] , nums[j-1] + dp[i-nums[j-1]][j-1]);
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[tar][n] == tar ? true : false;

    }
};