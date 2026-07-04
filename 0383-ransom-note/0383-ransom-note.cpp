class Solution {
public:
    bool canConstruct(string ransom, string mag) {
        unordered_map<char, int> ransom_mp;
        for (int i = 0; i < ransom.size(); i++) {
            ransom_mp[ransom[i]]++;
        }
        unordered_map<char, int> mag_mp;
        for (int i = 0; i < mag.size(); i++) {
            mag_mp[mag[i]]++;
        }
        for (auto p : ransom_mp) {
            char c = p.first;
            int ransomFreq = p.second;
            int magFreq = mag_mp[c];
            if (ransomFreq > magFreq) {
                return false;
            }
        }
        return true;
    }
};