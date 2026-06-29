class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int nodel = arr[0];
        int onedel = INT_MIN;
        int ans = arr[0] ;

        for(int i =1;i<n;i++){
            int preNodel = nodel;
            nodel = max(nodel+arr[i],arr[i]);
            if(onedel == INT_MIN){
                onedel = preNodel;
            }else{
            onedel= max(preNodel , onedel +arr[i]);
            }
            ans = max(ans,max(nodel,onedel));
        } 
        return ans;
    }
};