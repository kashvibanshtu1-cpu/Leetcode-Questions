class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int head=0;
        int tail=n-1;
        int indx=n-1;
        vector<int> ans(n) ;
        while (head<=tail){
            if(abs(nums[head])<= abs(nums[tail])){
               ans[indx] = nums[tail]* nums[tail];
               tail--;
            }
            else{
                ans[indx]= nums[head]*nums[head];
                head++;
            }
            indx--;
        }
        return ans ;
    }
};