class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int>s;

        for(int x : nums) s.insert(x);
        int maxLen = 1;

        for(int x : s){
            if(s.count(x+1)) continue;

            int currLen = 1;
            int find = x;

            while(s.find(find-1) != s.end()){
                currLen++;
                find--;
            }

            maxLen = max(maxLen, currLen);
        }

        return maxLen ;
    }
};