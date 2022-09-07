#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
#define test() int t; cin >> t; while(t--)
 
int main(){
    faster();
        ll n, m;
        cin >> n >> m;
        ll arr[n + 5] = {};
        for(ll i = 1; i <= n; i++) cin >> arr[i];
        ll dp[m + 5][n + 5] = {};
        for(ll i = 1; i <= n; i++){
            // khi nghỉ 
            ll MAX = 0;
            for(ll j = 1; j <= min(i, m); j++){
                if(dp[m - j][i - j] > MAX) MAX = dp[m - j][i - j];
            }
            dp[m][i] = max(MAX, dp[m][i - 1]);
            // k nghỉ mà chạy 
            for(ll j = m - 1; j >= 0; j--){
                if(m - j > i) continue;
                dp[j][i] = dp[j + 1][i - 1] + arr[i];
            }
        }
        cout << dp[m][n] << endl;
}