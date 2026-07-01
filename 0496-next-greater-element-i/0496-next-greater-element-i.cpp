class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> great (n,-1);
        great[n - 1] = -1;
        st.push(nums[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
                if (st.empty()) {
                    great[i] = -1;
                }

                else {
                    great[i] = st.top();
                }
            
            st.push(nums[i]);
        }
        vector<int> ans;
        for (int j = 0; j < nums1.size(); j++) {

            int i = 0;

            while (nums[i] != nums1[j]) {
                i++;
            }

            ans.push_back(great[i]);
        }

        return ans;
    }
};