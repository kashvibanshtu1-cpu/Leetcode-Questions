class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> mp;

        for (char ch : s)
            mp[ch]++;

        priority_queue<pair<int, char>> pq;

        for (auto p : mp) {
            pq.push({p.second, p.first});
        }

        string ans = "";
        int curr = 0;

        while (!pq.empty()) {

            pair<int, char> t = pq.top();
            pq.pop();

            int freq = t.first;

            if (curr == 0 || ans[curr - 1] != t.second) {

                ans.push_back(t.second);
                freq--;

                if (freq > 0)
                    pq.push({freq, t.second});

            } else {

                if (pq.empty())
                    return "";

                pair<int, char> snd = pq.top();
                pq.pop();

                int freq2 = snd.first;

                ans.push_back(snd.second);
                freq2--;

                if (freq2 > 0)
                    pq.push({freq2, snd.second});

                // Push the skipped character back
                pq.push({freq, t.second});
            }

            curr++;
        }

        return ans;
    }
};