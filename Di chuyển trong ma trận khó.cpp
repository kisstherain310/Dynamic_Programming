#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
#define test() int t; cin >> t; while(t--)
 
int main(){
    faster();
    test(){
        ll a, b;
        cin >> a >> b;
        ll arr[a + 5][b + 5] = {}, dp[a + 5][b + 5] = {};
        for(ll i = 1; i <= a; i++)
            for(ll j = 1; j <= b; j++){
                cin >> arr[i][j];
                dp[i][j] = -1;
            }
        for(int i = 0; i <= a; i++) dp[i][0] = -1;
        for(int i = 0; i <= b; i++) dp[0][i] = -1;
        dp[1][1] = arr[1][1];
        for(ll i = 1; i <= a; i++){
            for(ll j = 1; j <= b; j++){
                if(arr[i][j] != -1){
                    if(arr[i - 1][j] != -1 && dp[i - 1][j] != -1) dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
                    if(arr[i][j - 1] != -1 && dp[i][j - 1] != -1) dp[i][j] = max(dp[i][j], dp[i][j - 1] + arr[i][j]);
                }
            }
        }
        cout << dp[a][b] << endl;
    }
}