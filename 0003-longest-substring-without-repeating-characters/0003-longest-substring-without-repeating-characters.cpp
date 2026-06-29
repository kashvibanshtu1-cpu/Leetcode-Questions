class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int low =0;
        int maxlen = INT_MIN;
        unordered_map <char,int> mp;
        for(int high=0;high<str.size();high++){
            mp[str[high]]++;
            int len = high-low+1;
            if(mp.size()==len){
                maxlen = max(maxlen,len);
            }
            else{
                mp[str[low]]--;
                if( mp[str[low]]==0){
                    mp.erase(str[low]);
                }
                low++;
            }
        }
        if(maxlen == INT_MIN){
            return 0;
        }
        return maxlen;

    }
};