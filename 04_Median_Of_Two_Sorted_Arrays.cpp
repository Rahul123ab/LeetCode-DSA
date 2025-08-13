class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //added to ensure nums1 is always smaller then nums2 so that mid2 doesn't go out of bounds
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size(); //size of 1st vector
        int n2 = nums2.size(); //size of second vector
        int totalSize = n1 + n2;

        double median = 0;
        int left = 0, right = n1;

        while (left <= right) {
            int mid1 = left + (right - left)/2;
            int mid2 = totalSize/2 - mid1;

            int l1 = (mid1==0) ? INT_MIN : nums1[mid1-1];
            int r1 = (mid1==n1) ? INT_MAX : nums1[mid1];

            int l2 = (mid2==0) ? INT_MIN : nums2[mid2-1];
            int r2 = (mid2==n2) ? INT_MAX : nums2[mid2];

            if(l1 > r2) {
                right = mid1 - 1;
            } else if (l2 > r1) {
                left = mid1 + 1;
            } else {
                return (totalSize % 2 == 0) ? median = (double)(max(l1, l2)+ min(r1, r2))/2 :
                median = (double)min(r1, r2);
            }
        }
        return median;
    }
};