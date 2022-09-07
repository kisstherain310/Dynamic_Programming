#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
int main(){
    faster();
    int t;
    cin >> t;
    while(t--){
        ll n, k; 
        cin >> n >> k;
        ll dp[n + 5] = {};
        dp[0] = 1;
        dp[1] = 1; 
        ll Max = 1e9 + 7;
        for(int i = 2; i <= n; i++){
            for(int j = i - k; j < i; j++){
                if(j < 0) continue;
                else dp[i] += dp[j];
                if(dp[i] >= Max) dp[i] = dp[i] % Max;
            }
        }
        cout << dp[n] << endl;
    }
}