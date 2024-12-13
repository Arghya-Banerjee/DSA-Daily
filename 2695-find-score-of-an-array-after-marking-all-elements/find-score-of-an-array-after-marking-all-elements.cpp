class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long sum = 0;
        set<pair<int, int>> st;
        for(int i = 0; i < nums.size(); i++) st.insert({nums[i], i});
        while(!st.empty()){
            pair<int, int> temp = *st.begin();
            int el = temp.first;
            int ind = temp.second;
            st.erase({el, ind});
            sum += el;
            if(ind > 0 && st.find({nums[ind-1], ind-1}) != st.end()) st.erase({nums[ind-1], ind-1});
            if(ind < nums.size()-1 && st.find({nums[ind+1], ind+1}) != st.end()) st.erase({nums[ind+1], ind+1});
        }
        return sum;
    }
};