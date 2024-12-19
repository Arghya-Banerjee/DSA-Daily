class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt = 0;
        int maxi = -1;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            maxi = max(arr[i], maxi);
            if(maxi == i){
                cnt++;
                maxi = -1;
            }
        }
        return cnt;
    }
};