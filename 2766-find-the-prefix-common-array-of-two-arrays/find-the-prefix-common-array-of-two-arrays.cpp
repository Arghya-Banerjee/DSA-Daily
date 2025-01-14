class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int, int> mpp;
        int n = A.size();
        int cnt = 0;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            mpp[A[i]]++;
            if(mpp[A[i]] == 2) cnt++;
            mpp[B[i]]++;
            if(mpp[B[i]] == 2) cnt++;
            ans[i] = cnt;
        }
        return ans;
    }
};