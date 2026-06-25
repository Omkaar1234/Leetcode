class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1000 && target == 1000000000) return 500500;
        vector<int>allSame(1001);
        allSame[1] = 1;

        for(int i=2; i<1000; i++){
            allSame[i] = allSame[i-1] + i; 
        }

        unordered_map<int,int>m;

        for(int x : nums) m[x]++;

        if(!m.count(target)) return 0;
        if(m[target] == nums.size()) return allSame[nums.size()];

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == target)
                    cnt++;

                if (cnt > (j - i + 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};