class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {//TC=O(logn) as binary search at every level
        int start=1; //1st and last element can't be the peak as it will not form the mountain then
        int end=arr.size()-2;

        while (start <= end) {
            int mid = start + (end-start)/2;

            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1] ) { //mid is the peak element
                return mid;
            } else if(arr[mid] < arr[mid+1]) { //peak in right
                start = mid +1;
            } else { //peak in left
                end = mid -1;
            }
        }
        return -1; //no peak exists for the given array
    }
};