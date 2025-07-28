class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int start=0;
        int end=height.size()-1;
        int maxWater=0;
        while (start < end) {
            int width=end-start;
            int ht=min(height[start],height[end]);
            maxWater=max(maxWater,width*ht);

            if(height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }
        return maxWater;
    }
};