class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> pre(n, 0), suf(n, 0);
        int cnt = 0;
        pre[0] = 0;
        for(int i = 1; i < n; i++){
            if(boxes[i-1] == '1') cnt++;
            pre[i] = pre[i-1] + cnt;
        }
        cnt = 0;
        suf[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            if(boxes[i+1] == '1') cnt++;
            suf[i] = suf[i+1] + cnt;
        }
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            ans[i] = pre[i] + suf[i];
        }
        return ans;
    }
};