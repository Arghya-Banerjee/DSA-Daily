class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> ans;
        for(string s: strs){
            vector<int> f(26, 0);
            for(char c: s) f[c-'a']++;
            string key = "";
            for(int i = 0; i < 26; i++){
                key += to_string(f[i]) + ",";
            }
            mpp[key].push_back(s);
        }
        for(auto it: mpp) ans.push_back(it.second);
        return ans;
    }
};