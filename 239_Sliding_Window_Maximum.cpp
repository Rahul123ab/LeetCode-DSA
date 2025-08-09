class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        //first window
        for(int i = 0; i < k; i++) {
            //remove the smaller elements from the back if we get any larger element in the window
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int j = k; j < nums.size(); j++) {
            //populate the result from the front of the dq
            result.push_back(nums[dq.front()]);

            //remove the element which is no longer part of the sliding window
            while(dq.size() > 0 && dq.front() <= j-k) {
                dq.pop_front();
            }

            //remove the smaller elements from the back of the dq
            while(dq.size() > 0 && nums[dq.back()] <= nums[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
        }
        //push the last element from the dq to the result
        result.push_back(nums[dq.front()]);
        return result;
    }
};