class Solution {
public:
    int leastInterval(vector<char>& tasks, int m) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;

        for (char ch : tasks) {
            mp[ch]++;
            mp2[ch] = 0;
        }

        priority_queue<pair<int, char>> pq;

        for (auto &p : mp) {
            pq.push({p.second, p.first});
        }

        vector<pair<int, char>> stall;
        int curr = 0;

        while (!pq.empty() || !stall.empty()) {

            // Move ready tasks back to heap
            vector<pair<int, char>> temp;
            for (auto &p : stall) {
                if (mp2[p.second] <= curr)
                    pq.push(p);
                else
                    temp.push_back(p);
            }
            stall = temp;

            if (!pq.empty()) {
                auto top = pq.top();
                pq.pop();

                int freq = top.first;
                char ch = top.second;

                freq--;

                if (freq > 0) {
                    mp2[ch] = curr + m + 1;
                    stall.push_back({freq, ch});
                }
            }

            curr++;
        }

        return curr;
    }
};