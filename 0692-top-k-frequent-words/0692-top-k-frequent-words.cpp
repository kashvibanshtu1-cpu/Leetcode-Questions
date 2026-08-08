class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }
        priority_queue<pair<int, string>,vector<pair<int,string>>, cmp> pq;
        for (auto p : mp) {
            int frequency = p.second;
            string letter = p.first;
            pq.push({frequency, letter});
        }
        while (k-- && !pq.empty()) {
            auto t = pq.top();
            pq.pop();
            ans.push_back(t.second);
        }
        return ans;
    }
};