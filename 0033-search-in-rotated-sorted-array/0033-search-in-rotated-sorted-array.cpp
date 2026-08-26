class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int n = nums.size();
        int end = n-1;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] <= nums[end]){
                if(nums[mid] < target && target <= nums[end]){
                    st = mid+1;
                }else{
                    end = mid-1;
                }
            }else if(nums[mid] >= nums[st]){
                if(nums[st] <= target && target < nums[mid]){
                    end = mid-1;
                }else{
                    st = mid+1;
                }
            }
        }

        return -1;
    }
};