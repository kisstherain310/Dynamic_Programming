#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
#define test() int t; cin >> t; while(t--)
 
int main(){
    faster();
    test(){
        ll n;
        cin >> n;
        ll arr[n + 5] = {};
        ll dp[n + 5] = {};
        for(int i = 1; i <= n; i++) cin >> arr[i];
        dp[2] = abs(arr[2] - arr[1]);
        for(int i = 3; i <= n; i++){
            dp[i] = min(dp[i - 2] + abs(arr[i] - arr[i - 2]), dp[i - 1] + abs(arr[i] - arr[i - 1]));
        }
        cout << dp[n] << endl;
    }
}