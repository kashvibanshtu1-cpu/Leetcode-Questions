class Solution {
public:
    long long speed(vector<int>& piles, int guess){
        long long hours =0;
        for(int i=0;i<piles.size();i++){
           hours += piles[i]/guess ;
           if (piles[i] % guess != 0) {
                hours++;
            }
        }
        return hours ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start =1 ;
        int end = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX ;
        while(start<=end){
            int guess = start+(end-start)/2 ;
            long long hours = speed(piles,guess);
            if(hours >h){
                start = guess +1; 
            }
            else{
                ans = min(ans ,guess);
                end = guess-1 ;
            }
        }
        if(ans == INT_MAX ) return -1 ;
        return ans ;
    }
};