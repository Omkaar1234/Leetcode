class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int maxProd = nums[0];

        for(int i=1; i<nums.size(); i++){
            int prevMax = currMax;
            int prevMin = currMin;
            currMax = max({nums[i], prevMax*nums[i], prevMin*nums[i]});
            currMin = min({nums[i], prevMax*nums[i], prevMin*nums[i]});
            maxProd = max(currMax,maxProd);
        }

        return maxProd;
    }
};