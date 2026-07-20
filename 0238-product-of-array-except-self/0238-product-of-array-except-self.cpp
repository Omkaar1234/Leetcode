class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n);
        int leftP = 1;

        for(int i=0; i<n; i++){
            left[i] = leftP;
            leftP *= nums[i];
        }

        vector<int>ans(n);
        int rightP = 1;

        for(int i=n-1; i>=0; i--){
            ans[i] = left[i] * rightP;
            rightP *= nums[i];
        }

        return ans;
    }
};