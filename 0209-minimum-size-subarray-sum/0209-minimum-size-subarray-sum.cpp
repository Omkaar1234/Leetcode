class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;

        int n = nums.size();
        int currSum = 0;
        int minLen = INT_MAX;

        while(r < n){
            currSum += nums[r];

            if(currSum >= target){
                while(l <= r && currSum >= target){
                    int len = r-l+1;
                    minLen = min(minLen, len);
                    currSum -= nums[l];
                    l++;
                }
            }

            r++;
        }

        return minLen == INT_MAX ? 0 : minLen; 
    }
};