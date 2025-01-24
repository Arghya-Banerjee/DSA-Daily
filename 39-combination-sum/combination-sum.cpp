class Solution {
private:
    void f(vector<int> &a, int ind, int target, vector<int> &temp, vector<vector<int>> &ans, int sum){
        if(ind == a.size()){
            if(sum == target){
                ans.push_back(temp);
            }
            return;
        }
        if(target - sum >= a[ind]){
            temp.push_back(a[ind]);
            f(a, ind, target, temp, ans, sum+a[ind]);
            temp.pop_back();
        }
        f(a, ind+1, target, temp, ans, sum);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        f(candidates, 0, target, temp, ans, 0);
        return ans;
    }
};