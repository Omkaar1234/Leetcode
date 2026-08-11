class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefix = 0;
        prefix += nums[0];
        int n = nums.size();

        unordered_set<int>s(nums.begin(), nums.end());

        for(int i = 1; i<n; i++){
            if(nums[i] == nums[i-1] + 1){
                prefix += nums[i];
            }else{
                break;
            }
        }

        while(true){
            if(s.find(prefix) != s.end()){
                prefix++;
            }else{
                break;
            }
        }

        return prefix;
    }
};