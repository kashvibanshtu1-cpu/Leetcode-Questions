class Solution {
public:
    int totalFruit(vector<int>& nums) {
       int low =0;
       int maxlen = INT_MIN;
        unordered_map <int,int> mp ;
        for(int high =0;high<nums.size();high++){
            mp[nums[high]]++;
            while(mp.size()>2){
                mp[nums[low]]--;
                if(mp[nums[low]]==0){
                    mp.erase(nums[low]);
                }
                low++;
            }
            int len = high-low+1;
            maxlen = max(maxlen,len);
        }
        return maxlen; 
    }
};