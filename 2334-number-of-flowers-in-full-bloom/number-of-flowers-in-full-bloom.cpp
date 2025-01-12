class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> mpp;
        for(auto it: flowers){
            mpp[it[0]]++;
            mpp[it[1]+1]--;
        }
        int sum = 0;
        for(auto &it: mpp){
            sum += it.second;
            it.second = sum;
        }
        int n = people.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            auto it = mpp.upper_bound(people[i]);
            if(it != mpp.begin()){
                it--;
                ans[i] = it->second;
            }
        }
        return ans;

    }
};