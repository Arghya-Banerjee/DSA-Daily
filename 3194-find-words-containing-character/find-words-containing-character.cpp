class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int ind = 0;
        for(string s: words) {
            for(char c: s) {
                if(c == x) {
                    ans.push_back(ind);
                    break;
                }
            }
            ind++;
        }
        return ans;
    }
};