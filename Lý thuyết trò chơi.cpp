#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
#define test() int t; cin >> t; while(t--)
 
int main(){
    faster();
    ll n, k;
    cin >> n >> k;
    ll arr[n + 5] = {};
    ll min = 1e9;
    ll dp[k + 5] = {};
    for(ll i = 1; i <= n; i++) cin >> arr[i];
    dp[0] = 1;
    for(ll i = 1; i <= k; i++){
        ll check = 0;
        for(ll j = 1; j <= n; j++){
            if(i < arr[j]) continue;
            if(dp[i - arr[j]] == 1) check = 1;
        }
        if(check == 0) dp[i] = 1;
    }
    if(dp[k] == 0) cout << "Kent";
    else cout << "Bent";
}