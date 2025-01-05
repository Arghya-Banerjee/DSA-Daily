class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n+1, 0);
        for(auto it: shifts){
            if(it[2] == 1){
                diff[it[0]]++;
                diff[it[1]+1]--;
            }
            else{
                diff[it[0]]--;
                diff[it[1]+1]++;
            }
        }

        for(int i = 1; i <= n; i++){
            diff[i] += diff[i-1];
        }

        string res;
        for(int i = 0; i < n; i++){
            int count = diff[i]%26;
            if(count < 0){
                count = count + 26; // getting in positive shift value
            }
            char curr = char((s[i]-'a'+count)%26 + 97);
            res.push_back(curr);
        }
        return res;
    }
};