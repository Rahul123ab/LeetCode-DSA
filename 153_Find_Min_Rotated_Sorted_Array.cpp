class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {

            int mid = start + (end - start)/2;
            cout << "st=" << start << " mid=" << mid << " end=" << end << endl;
            if(nums[mid] > nums[end]) {
                start = mid + 1; 
            } else {
                end = mid;
            }
        }
        return nums[start];
    }
};