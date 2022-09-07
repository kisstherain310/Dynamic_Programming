#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
#define test() int t; cin >> t; while(t--)
 
int main(){
    faster();
    test(){
        ll n, k; 
        cin >> n >> k;
        int W[n + 5] = {}, X[n + 5] = {};
        for(int i = 1; i <= n; i++){
            cin >> W[i] >> X[i];
        }
        int dp[n + 5][k + 5] = {};
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                if(j >= W[i]) dp[i][j] = max(dp[i - 1][j - W[i]] + X[i], dp[i - 1][j]);
                else dp[i][j] = dp[i - 1][j];
            }
        }
        cout << dp[n][k] << endl;
    }
}