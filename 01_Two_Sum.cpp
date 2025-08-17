class Solution{
    public:
    vector<int> twoSum(vector<int> &nums, int target){//TC= O(n)

        unordered_map<int, int> map;

        for(int i=0; i<nums.size(); i++) {
            int first = nums[i]; //fix the first element in every iteration
            int second = target - first; //calculate the second element or complement to achieve target

            if(map.find(second) != map.end()){ //check if second value already exists in the map
                return {map[second],i};
            }
            map[nums[i]]=i; //just add the current array element to the map
        }
        return {};
    }
};
