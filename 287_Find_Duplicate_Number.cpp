class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*unordered_set<int> set;  TC= O(n), SC= O(n)

        for(int val: nums) {

            if(set.find(val) != set.end()) {
                return val;
            }
            set.insert(val);
        }
        return -1;
        */

        //slow-fast pointer approach    TC= O(n), SC= O(1)
        int slow=nums[0], fast=nums[0];
        do {
            slow = nums[slow]; //+1 increase by 1
            fast = nums[nums[fast]]; //+2 increase by 2

        } while (slow != fast);

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow]; //+1 increase by 1
            fast = nums[fast]; //+1 increase by 1
        }
        return slow;
    }
};