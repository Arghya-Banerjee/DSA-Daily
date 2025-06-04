class Solution {
public:
    string answerString(string word, int k) {
        if(k == 1) return word;
        int n = word.size();
        int maxLen = n - k + 1;
        string ans = "";
        for(int it = 0; it < n; it++) {
            string s = word.substr(it, maxLen);
            if(s > ans) ans = s;
        }
        return ans;
    }
};