class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s(nums.begin(), nums.end());
        int pow = 1;

        while(true){
            int n = k * pow;
            if(s.find(n) == s.end()){
                return n;
            }

            pow++;
        }
        return -1;
    }
};