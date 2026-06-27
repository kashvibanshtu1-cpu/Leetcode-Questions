class Solution { 
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> ans;
        int head = 0;
        int tail = n - 1;
        while (head < tail) {
            if (arr[head] + arr[tail] == target) {
                head++;
                tail++;
                ans.push_back(head);
                ans.push_back(tail);
                break;
            } else if (arr[head] + arr[tail] < target) {
                head++;
            } else {
                tail--;
            }
        }
        return ans;
    }
};