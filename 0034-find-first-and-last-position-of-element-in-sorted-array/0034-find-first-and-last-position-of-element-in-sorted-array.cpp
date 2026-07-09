class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        int start = 0;
        int end = nums.size()-1;
        int first = INT_MAX;
        int second = -1;
        vector<int> ans;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == tar) {
                first = min(first, mid);
                end = mid - 1;
            } else if (nums[mid] > tar) {
               end = mid - 1; 
            } else {
                start = mid + 1;
            }
        }
        int start1 = 0;
        int end1 = nums.size()-1;
        while (start1 <= end1) {
            int mid = start1 + (end1 - start1) / 2;
            if (nums[mid] == tar) {
                second = max(second, mid);
                start1 = mid + 1;
            } else if (nums[mid] > tar) {
                end1 = mid - 1;
            } else {
               start1 = mid + 1; 
            }
        }
        if(first == INT_MAX){
            first =-1;
        }
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};