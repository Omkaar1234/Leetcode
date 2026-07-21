class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums.size();
        unordered_set<int>s;

        for(int x : nums){
            s.insert(x);
        }

        int maxLen = 1;
        for(auto &n : s){
            int num = n;

            if(s.find(num-1) == s.end()){
                int st = num;
                int len = 1;
                while(s.find(st+1) != s.end()){
                    st++;
                    len++;
                }
                maxLen = max(maxLen,len);
            }
        }

        return maxLen;
    }
};