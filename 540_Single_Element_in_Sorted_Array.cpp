class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int start = 0;
        int end = nums.size()-1;

        if(nums.size() == 1) return nums[0]; //case with only one element in an array

        while (start <=end) {
            int mid = start + (end - start)/2;

            if(mid == 0 && nums[0] != nums[1]) {//case where single element is at 1st index
                return nums[mid];
            }
            if(mid == (nums.size()-1) && nums[(nums.size())-2] != nums[(nums.size())-1]) {//case where single element is at last index
                return nums[mid];
            }
            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            } 

            if(mid%2 == 0) { //even no of elements on left and right of mid
                if(nums[mid-1] == nums[mid]) { //mid forms pair with left element //left
                    end = mid - 1;
                } else { //right
                    start = mid + 1;
                }
            } else {//odd no of elements on left and right of mid
                if(nums[mid-1] == nums[mid]) {//mid forms pair with right element //right
                    start = mid + 1;
                } else {//left
                    end = end - 1;
                }
            }
        }
        return -1;
    }
};