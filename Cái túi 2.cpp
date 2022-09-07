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
    ll W[n + 5] = {}, X[n + 5] = {};
    ll S = 0;
    for(ll i = 1; i <= n; i++){
        cin >> W[i] >> X[i];
        S += X[i];
    }
    ll dp[S + 5] = {};
    for(ll i = 1; i <= n; i++){
        for(ll j = S; j >= X[i]; j--){
            if(j - X[i] == 0 || dp[j - X[i]] > 0){
                if(dp[j] == 0) dp[j] = dp[j - X[i]] + W[i];
                else dp[j] = min(dp[j], dp[j - X[i]] + W[i]);
            }
        }
    }   
    int check = 0;;
    for(ll i = S; i >= 0; i--){
        if(dp[i] > 0 && dp[i] <= k){
            cout << i;
            check = 1;
            break;
        }
    }
}