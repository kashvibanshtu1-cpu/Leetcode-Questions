class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordlist) {
       unordered_map<string,int> mp ;
       for(int i=0;i<wordlist.size();i++){
          mp[wordlist[i]]++;
       }
       if(mp.find(endword)==mp.end()){
        return 0;
       } 
       queue<pair<string,int>> q;
       q.push({beginword,0});
       while(!q.empty()){
        string t = q.front().first;
        int val = q.front().second;
        if(t==endword){
            return val+1;
        }
        q.pop();
        for(int i=0;i<t.size();i++){
            char ch = t[i];
            for(int j=97;j<123;j++){
                if(j==ch){
                    continue ;
                }
                t[i]=j;
                if(mp.find(t)!=mp.end()){
                    q.push({t,val+1});
                    mp.erase(t);
                }
            }
            t[i]=ch;
        }
       }
       return 0;
    }
};