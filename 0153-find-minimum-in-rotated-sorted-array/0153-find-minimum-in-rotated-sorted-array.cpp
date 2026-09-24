class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int n = nums.size();
        int end = n-1;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(nums[mid] >= nums[st] && nums[mid] >= nums[end]){
                if(nums[end] >= nums[st]){
                    end = mid-1;
                }else{
                    st = mid + 1;
                }
            }else if(nums[mid] >= nums[st] && nums[end] >= nums[mid]){
                end = mid - 1;
            }else if(nums[mid] >= nums[end] && nums[st] >= nums[mid]){
                st = mid + 1;
            }else{
                st++;
                end--;
            }
        }

        return nums[st];
    }
};