class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,queue<int>>m;
        int n = nums.size();
        int l = 0;
        int maxL = INT_MIN;

        for(int r=0; r<n; r++){
            if(m[nums[r]].size() == k){
                int idx = m[nums[r]].front();
                m[nums[r]].pop();
                l = max(l,idx+1);
            }

            int len = r-l+1;
            maxL = max(maxL,len);
            m[nums[r]].push(r);
        }

        return maxL;
    }
};