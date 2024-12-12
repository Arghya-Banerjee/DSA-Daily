class Solution {
private:
    int getParent(int el, vector<int> &dsu){
        if(dsu[el] == el) return el;
        return getParent(dsu[el], dsu);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> dsu(n+1);
        for(int i = 0; i <= n; i++){
            dsu[i] = i;
        }
        for(vector<int> it: edges){
            int el1 = it[0];
            int el2 = it[1];
            int p1 = getParent(el1, dsu);
            int p2 = getParent(el2, dsu);
            if(p1 == p2) return it;
            else{
                dsu[p2] = p1;
            } 
        }
        return {};
    }
};