class Solution {
public:
    bool canConstruct(string rans, string mag) {
        unordered_map<char, int> need;
        for (int i = 0; i < rans.size(); i++) {
            need[rans[i]]++;
        }
        unordered_map<char, int> have;
        for (int i = 0; i < mag.size(); i++) {
            have[mag[i]]++;
        }
        for (auto i : need) {
            char c = i.first;
            int ranfreq = i.second;
            int magfreq = have[c];
            if (ranfreq > magfreq) {
                return false;
            }
        }
        return true;
    }
};