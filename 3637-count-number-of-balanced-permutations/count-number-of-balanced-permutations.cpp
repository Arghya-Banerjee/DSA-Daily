constexpr long long mod=1e9+7;

int dp[10][41][361];
static constexpr auto Pascal_triangle() {
    array<array<long long, 41>, 41> a{};
    for (int i=0; i<41; i++) {
        a[i][0]=a[i][i]=1;
        for (int j=1; j<=i/2; j++) {
            long long x=a[i-1][j-1]+a[i-1][j];
            if (x>=mod) x-=mod;
            a[i][j]=a[i][i-j] = x;
        }
    }
    return a;
}

class Solution {
public:
    int sum=0, n;
    array<int, 10> freq{};
    static constexpr auto comb = Pascal_triangle();
    int f(int i, int even, int odd, int remain) {
        if (even==0 && odd==0 && remain==0)
            return 1;
        if (i<0 || even<0 || odd<0 || remain<0)
            return 0;
 
        if (dp[i][even][remain] != -1)
            return dp[i][even][remain];

        long long ans = 0;
        int max_j=min(freq[i], even);
        
        for (int j=0; j<=max_j; j++) {
            int odd_rem=freq[i]-j;
            if (odd_rem<=odd && remain >= i*j) {
                // Additional prune: check if remaining achievable sum is valid
                if (remain-i*j > (even-j+odd-odd_rem)*(i-1)) 
                    continue;

                ans=(ans+comb[even][j]*comb[odd][odd_rem]%mod*
                       f(i-1, even-j, odd-odd_rem, remain-i*j)%mod)%mod;
            }
        }
        return dp[i][even][remain]=ans;
    }

    int countBalancedPermutations(string& num) {
        n=num.size();
        for (char c : num) {
            int x=c-'0';
            freq[x]++;
            sum+=x;
        }
        if (sum&1)
            return 0;
        sum/=2;
        int oddLen=n/2, evenLen=n-oddLen;

        memset(dp, -1, sizeof(dp));
        return f(9, evenLen, oddLen, sum);
    }
};
