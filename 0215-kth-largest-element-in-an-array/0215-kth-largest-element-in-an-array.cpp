class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < arr.size(); i++) {
            if(k != 0) {
                pq.push(arr[i]);
                k--;
                continue;
            }
            int smallest = pq.top();
            if (arr[i] <= smallest) {
                continue;
            }
            pq.pop();
            pq.push(arr[i]);
        }
        return pq.top();
    }
};