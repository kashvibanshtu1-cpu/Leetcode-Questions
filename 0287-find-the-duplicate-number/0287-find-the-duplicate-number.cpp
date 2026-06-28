class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow = 0;
        int fast = 0;
        while (true) {
            slow = arr[slow];
            fast = arr[arr[fast]];
            if (slow == fast) {
                slow = 0;
                while (true) {
                    slow = arr[slow];
                    fast = arr[fast];
                    if (slow == fast) {
                        return slow;
                    }
                }
            }
        }
        return -1;
    }
};