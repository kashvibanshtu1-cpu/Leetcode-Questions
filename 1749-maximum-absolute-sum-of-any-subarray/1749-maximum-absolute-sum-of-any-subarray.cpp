class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minsum = nums[0];
        int maxsum = nums[0];
        int Minans = nums[0];
        int Maxans =nums[0];
        for(int i=1;i<nums.size();i++){
            int v1= nums[i];
            int v2= minsum +nums[i];
            int v3= maxsum + nums[i];
            minsum = min(v1,v2);
            maxsum = max(v1,v3);
            Minans = min(minsum,Minans);
            Maxans = max(Maxans,maxsum);
        }
        return max(abs(Minans),Maxans);
    }
};