class Solution {
private:
    int helper(string s){
        int n = s.size();
        char c1 = s[0];
        char c2 = s[n-1];
        if((c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u') && (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u')) return 1;
        return 0;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pre (n, 0);
        pre[0] = helper(words[0]);
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + helper(words[i]);
        }
        vector<int> ans;
        for(auto q: queries){
            int left = q[0];
            int right = q[1];
            if(left == 0){
                ans.push_back(pre[right]);
            }
            else ans.push_back(pre[right] - pre[left-1]);
        }
        return ans;
    }
};

// 1 2 4 5 2
// 1 3 7 12 14