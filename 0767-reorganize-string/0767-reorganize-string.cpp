class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> mp;
        string ans = "";

        // Count frequency
        for (char c : s) {
            mp[c]++;
        }

        // Max heap
        priority_queue<pair<int, char>> pq;

        for (auto p : mp) {
            pq.push({p.second, p.first});
        }

        for (int i = 0; i < s.size(); i++) {

            auto t = pq.top();
            pq.pop();

            int freq = t.first;
            char val = t.second;

            // If different from previous character
            if (ans.empty() || ans.back() != val) {

                ans.push_back(val);

                freq--;

                if (freq > 0) {
                    pq.push({freq, val});
                }

            }

            // If same as previous character
            else {

                // No alternative character
                if (pq.empty()) {
                    return "";
                }

                auto t2 = pq.top();
                pq.pop();

                int freq2 = t2.first;
                char val2 = t2.second;

                // Use second character
                ans.push_back(val2);

                freq2--;

                if (freq2 > 0) {
                    pq.push({freq2, val2});
                }

                // We did NOT use val, so put it back unchanged
                pq.push({freq, val});
            }
        }

        return ans;
    }
};