class Solution {
public:
    void nextPermutation(vector<int>& nums) {//TC= O(n), SC= O(1)
        //step1. Find the pivot by traversing backwards

        int pivot=-1;

        for(int i=nums.size()-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                pivot=i;
                break;
            }
        }
        if(pivot==-1) {
            reverse(nums.begin(),nums.end());
            return;
        }

        //step2. find the rightmost element and swap
        for(int i=nums.size()-1; i>pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i],nums[pivot]);
                break;
            }
        }

        //step3. Reverse the remaining element (pivot+1) to n-1;

        reverse(nums.begin()+(pivot+1), nums.end());
    }
};