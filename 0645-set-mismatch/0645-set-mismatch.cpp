class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int>s;
        int setXOR = 0;
        vector<int>ans(2);

        for(int x : nums){
            if(s.find(x) == s.end()){
                s.insert(x);
                setXOR = setXOR ^ x;
            }else{
                ans[0] = x;
            }
        }

        for(int i=1; i<=nums.size(); i++){
            setXOR = setXOR ^ i;
        }

        ans[1] = setXOR;

        return ans;
    }
};