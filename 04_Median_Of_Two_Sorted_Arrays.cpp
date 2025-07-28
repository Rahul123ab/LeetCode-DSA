class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> mergedArray;
        int m=nums1.size();
        int n=nums2.size();
        
        int i=0,j=0;

        while (i< m && j< n) {

            if(nums1[i] <= nums2[j]) {
                mergedArray.push_back(nums1[i]);
                i++;
            } else if(nums1[i] > nums2[j]) {
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }
        
        while (i < m) {
            mergedArray.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            mergedArray.push_back(nums2[j]);
            j++;
        }
        
        int len=mergedArray.size();
        double median = 0;

        if(len%2==0) {
            median=(double)(mergedArray[len/2] + mergedArray[(len/2)-1])/2;
        } else {
            median = mergedArray[len/2];
        }
        return median;
    }
};