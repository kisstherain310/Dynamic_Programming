#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
#define test() int t; cin >> t; while(t--)
 
int main(){
    faster();
    test(){
        ll n, k, S = 0;
        cin >> n >> k;
        ll arr[n + 5] = {};
        for(ll i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i] = arr[i] % k;
            S += arr[i];
        }
        ll dp[S + 5] = {};
        for(ll i = 1; i <= n; i++){
            for(ll j = S; j >= arr[i]; j--){
                if(j - arr[i] == 0 || dp[j - arr[i]] > 0){
                    if(dp[j] == 0) dp[j] = dp[j - arr[i]] + 1;
                    else
                    dp[j] = max(dp[j - arr[i]] + 1, dp[j]);
                }
            }
        }
        int MAX = 0;
        for(ll i = (S / k) * k; i >= 0; i-=k){
            if(dp[i] > 0 && i % k == 0){
                if(dp[i] > MAX) MAX = dp[i];
            }
        }
        cout << MAX << endl;
    }
}