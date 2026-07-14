class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> arr;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            } else {
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()) {
            arr.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) {
            arr.push_back(nums2[j]);
            j++;
        }
        int start = 0;
        int end = arr.size()-1;
        double ans = -1;
        double med = start + (end - start) / 2;
        if (arr.size() % 2 == 0) {
            ans = (arr[med] + arr[med + 1])/2;
        } else {
            ans =arr[med] ;
        }
        return ans;
    }
};