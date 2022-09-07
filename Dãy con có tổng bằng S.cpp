#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
#define test() int t; cin >> t; while(t--)
 
int main(){
    faster();
    test(){
        ll n, S;
        cin >> n >> S;
        ll arr[n + 5] = {};
        ll dp[S + 5] = {};
        dp[0] = 1;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        for(int i = 1; i <= n; i++){
            for(int j = S; j >= arr[i]; j--){
                if(dp[j - arr[i]] == 1) dp[j] = 1;
            }
        }
        if(dp[S] == 1)   cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
