class Solution {
public:
    int find(vector <int> arr){
        int maxc = INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxc= max(maxc,arr[i]);
        }
        return maxc;
    }
    int characterReplacement(string str, int k) {
        int low =0;
        int maxlen =INT_MIN;
        vector<int> arr(256,0);
        for(int high=0;high<str.size();high++){
            arr[str[high]]++;
            int len = high-low+1;
            int Maxc = find(arr);
            int diff = len-Maxc;
            while(diff>k){
              arr[str[low]]--;  
              low++;
              len = high-low+1;
              Maxc = find(arr);
              diff = len- Maxc ;
            }
            len = high-low+1;
            maxlen = max(maxlen,len);
        }
        return maxlen ;
    }
};