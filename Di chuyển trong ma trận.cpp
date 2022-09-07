#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
#define test() int t; cin >> t; while(t--)
 
int main(){
    faster();
    test(){
        ll n, m;
        ll MOD = 1e9 + 7;
        cin >> n >> m;
        ll arr[n + 5][m + 5] = {};
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= m; j++) cin >> arr[i][j];
        ll dp[n + 5][m + 5] = {};
        if(arr[1][2] == 0) dp[1][2] = 1;
        if(arr[2][1] == 0) dp[2][1] = 1;
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= m; j++){
                if(arr[i][j] == 0){
                    if(arr[i - 1][j] == 0) dp[i][j] += dp[i - 1][j];
                    dp[i][j] = dp[i][j] % MOD;
                    if(arr[i][j - 1] == 0) dp[i][j] += dp[i][j - 1];
                    dp[i][j] = dp[i][j] % MOD;
                }
            }
        cout << dp[n][m] << endl;
    }
}