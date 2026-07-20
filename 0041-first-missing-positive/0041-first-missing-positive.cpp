class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1;
        unordered_set<int>s;
        int n = nums.size();

        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }

        while(s.find(ans) != s.end()){
            ans++;
        }

        return ans;
    }
};