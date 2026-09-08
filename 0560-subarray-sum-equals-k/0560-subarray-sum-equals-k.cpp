class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int prefixSum = 0;
        m[0] = 1;
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            
            int need = prefixSum - k;
            if(m.count(need)){
                count += m[need];
            }

            m[prefixSum]++;
        }

        return count;
    }
};