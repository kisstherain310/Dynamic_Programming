#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
int main(){
    faster();
        int n; 
        cin >> n;
        int arr[n + 5] = {};
        for(int i = 0; i < n; i++) cin >> arr[i];
        int dp[n + 5] = {};
        for(int i = 0; i < n; i++) dp[i] = 1;
        int Max = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] >= arr[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if(dp[i] > Max) Max = dp[i];
        }
        cout << n - Max;
}