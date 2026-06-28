class Solution {
public:
    int find(int num){
        int sum =0;
        while(num>0){
            int last = num%10;
            sum += last*last;
            num /=10;
        }
        return sum ;
    }
    bool isHappy(int num) {
       int slow = num ;
       int fast = num ;
       while(true){
        fast= find(find(fast));
        slow= find(slow);
        if(fast ==1){
            return true ;
        }
        if(slow==fast){
            return false ;
        }
       }
       return true ;   
    }
};