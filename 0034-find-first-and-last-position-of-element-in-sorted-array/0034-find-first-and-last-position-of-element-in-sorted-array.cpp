class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        int start =0;
        int end = nums.size()-1;
        int first = INT_MAX ;
        vector<int> ans;
        while(start<=end){
            int mid = start +(end-start)/2 ;
            if(nums[mid]== tar){
                first = min(first,mid);
                end = mid-1;
            }
            else if(nums[mid]>tar){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        int star = 0;
        int ed = nums.size()-1 ;
        int second = INT_MIN ;
        while(star <= ed){
            int med = star +(ed-star)/2 ;
           if(nums[med]== tar){
                second = max(second,med);
                star = med+1;
            }
            else if(nums[med]>tar){
                ed = med-1;
            }
            else{
                star = med+1;
            }
        }
        if(first == INT_MAX && second == INT_MIN ){
            ans.push_back(-1);
            ans.push_back(-1);
        }else{
        ans.push_back(first);
        ans.push_back(second);
        }
        return ans ;
    }
};