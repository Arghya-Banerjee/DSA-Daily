class Solution {
public:
    string answerString(string word, int k) {
        if(k == 1) return word;
        int n = word.size();
        char temp = 'a';
        for(int i = 0; i < n; i++) {
            if(word[i] > temp) {
                temp = word[i];
            }
        }
        vector<int> ind;
        for(int i = 0; i < n; i++) {
            if(word[i] == temp) ind.push_back(i);
        }
        int maxLen = n - k + 1;
        string ans = "";
        for(auto it: ind) {
            string s = word.substr(it, maxLen);
            if(s > ans) ans = s;
        }
        return ans;
    }
};

// dbddac