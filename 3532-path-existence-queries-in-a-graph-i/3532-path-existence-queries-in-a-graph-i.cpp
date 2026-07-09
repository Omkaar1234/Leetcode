class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>comp(n);
        int component = 0;
        comp[0] = 0;

        for(int i=0; i<nums.size()-1; i++){
            if(abs(nums[i] - nums[i+1]) > maxDiff) component++;

            comp[i+1] = component; 
        }

        vector<bool>ans;

        for(int i=0; i<queries.size(); i++){
            ans.push_back(comp[queries[i][0]] == comp[queries[i][1]]);
        }

        return ans;
    }
};