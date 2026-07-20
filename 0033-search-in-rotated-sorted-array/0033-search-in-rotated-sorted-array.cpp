class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int n = nums.size();
        int end = n-1;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(nums[mid] == target) return mid;
            else if(nums[st] <= nums[mid]){ //Left array sorted
                if(nums[st] <= target && nums[mid] > target){
                    end = mid-1;
                }else{
                    st = mid+1;
                }
            }else if(nums[mid] <= nums[end]){ //Right Array sorted
                if(nums[mid] < target && nums[end] >= target){
                    st = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }

        return -1;
    }
};