#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
#define test() int t; cin >> t; while(t--)
 
int main(){
    faster();
    test(){
        int n;
        cin >> n;
        int arr[n + 5] = {};
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        ll dp[n] = {};
        dp[1] = arr[1];
        dp[2] = max(arr[1], arr[2]);
        for(int i = 3; i <= n; i++){
            dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
        }
        cout << dp[n] << endl;
    }
}