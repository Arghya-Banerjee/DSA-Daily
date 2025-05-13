class Solution {
private:
    void f(string &d, int ind, string &s, vector<string> &ans, unordered_map<char, string> &mpp) {
        if(s.size() == d.size()) {
            ans.push_back(s);
        }
        for(int i = 0; i < mpp[d[ind]].size(); i++) {
            s += mpp[d[ind]][i];
            f(d, ind+1, s, ans, mpp);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        string s = "";
        f(digits, 0, s, ans, mpp);
        return ans;
    }
};