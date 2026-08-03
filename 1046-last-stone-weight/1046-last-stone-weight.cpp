class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq ;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        int second =0;
        while(pq.size()>1){
            int first = pq.top();
            pq.pop();
            if(!pq.empty()){
                second = pq.top();
                pq.pop();
            }
            if(first == second) continue ;
            else{
                first = first - second ;
                pq.push(first);
            }
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};