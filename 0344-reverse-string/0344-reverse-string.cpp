class Solution {
public:
    void reverseString(vector<char>& s) {
        // stack<char> st ;
        // for(int i=0;i<s.size();i++){
        //     st.push(s[i]);
        // }
        // for(int i=0;i<s.size();i++){
        //     char ch = st.top();
        //     st.pop();
        //     s[i]= ch;
        // }

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
