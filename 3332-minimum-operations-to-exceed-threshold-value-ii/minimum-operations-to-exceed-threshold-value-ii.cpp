#define ll long long

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(ll it: nums) pq.push(it);
        int cnt = 0;
        while(pq.top() < k && pq.size() >= 2){
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            ll temp = min(a, b) * 2 + max(a, b);
            pq.push(temp);
            cnt++;
        }
        return cnt;
    }
};