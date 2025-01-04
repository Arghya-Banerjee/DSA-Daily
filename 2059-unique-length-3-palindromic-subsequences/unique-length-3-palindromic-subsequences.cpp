class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> st;
        unordered_map<char, int> mpp;
        set<pair<char, char>> ans; //mid, border
        int n = s.size();
        st.insert(s[0]);
        for(int i = 1; i < n; i++) mpp[s[i]]++;
        for(int i = 1; i < n-1; i++){
            char mid = s[i];
            mpp[mid]--;
            if(mpp[mid] == 0) mpp.erase(mid);
            for(char ch = 'a'; ch <= 'z'; ch++){
                if(st.find(ch) != st.end() && mpp.count(ch) > 0) ans.insert({mid, ch});
            }
            st.insert(s[i]);
        }
        for(auto it: ans){
            cout << it.second << it.first << it.second << endl;
        }
        return ans.size();
    }
};