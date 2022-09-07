#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
#define test() int t; cin >> t; while(t--)
 
int main(){
    faster();
    test(){
        string a, b;
        cin >> a >> b;
        ll szA = a.size(), szB = b.size();
        a = '0' + a;
        b = '0' + b;
        ll dp[szA + 5][szB + 5] = {};
        for(ll i = 0; i <= szA; i++) dp[i][0] = i;
        for(ll i = 0; i <= szB; i++) dp[0][i] = i;
        for(ll i = 1; i <= szA; i++){
            for(ll j = 1; j <= szB; j++){
                if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
        }
        cout << dp[szA][szB] << endl;
    }
}
