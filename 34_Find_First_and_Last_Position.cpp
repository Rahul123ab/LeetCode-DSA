class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size()-1;

        while (start <= end) {
            int mid = start + (end - start)/2;

            if(target < nums[mid]) {
                end = mid - 1;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                int first=mid;
                int last=mid;
                while(first > 0 && (nums[first-1] == nums[first])) {
                    first--;
                }
                while((last < nums.size() - 1) && (nums[last+1] == nums[last])) {
                    last++;
                }
                return {first,last};
            }
        }
        return {-1,-1};
    }
};