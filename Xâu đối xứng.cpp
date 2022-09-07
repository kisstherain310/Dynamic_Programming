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
        string s; 
        cin >> s;
        string ss = "";
        int n = s.size();
        for(int i = n - 1; i >= 0; i--){
            ss.push_back(s[i]);
        }
        s = '0' + s;
        ss = '0' + ss;
        int dp[105][105] = {};
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i] == ss[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        cout << n - dp[n][n] << endl;
    }
}