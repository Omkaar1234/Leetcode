class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            while(i < nums.size() && nums[i] != 0) i++;
            if(i == nums.size()) return;

            int j = i+1;
            while(j < nums.size() && nums[j] == 0) j++;
            if(j == nums.size()) return;

            swap(nums[i],nums[j]);
        }

        return;
    }
};