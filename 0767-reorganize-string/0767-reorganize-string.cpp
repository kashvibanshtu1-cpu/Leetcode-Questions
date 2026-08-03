class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto p : mp) {
            char first = p.first;
            int second = p.second;
            pq.push({second, first});
        }
        string ans = "";
        int curr = 0;
        while (!pq.empty()) {
            pair<int, char> t = pq.top();
            int freq = t.first;
            pq.pop();
             if (curr == 0 || ans[curr - 1] != t.second) {
                ans.push_back(t.second);
                freq -= 1;
                if (freq != 0)
                    pq.push({freq, t.second});
            }
            else {
                if (pq.empty())
                    return "";
                if (!pq.empty()) {
                    pair<int, char> snd = pq.top();
                    int freq = snd.first;
                    pq.pop();
                    ans.push_back(snd.second);
                    freq -= 1;
                    if (freq != 0)
                        pq.push({freq, snd.second});
                    pq.push(t);
                }
            }
            curr++;
        }
        return ans;
    }
};