class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int size = arr.size();
        vector<int> ans(size);
        int n = 1, p = 0;
        for (int i : arr) {
            if (i < 0) {
                ans[n] = i;
                n += 2;
            } else {
                ans[p] = i;
                p += 2;
            }
        }
        return ans;
    }
};