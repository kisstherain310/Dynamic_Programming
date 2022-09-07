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
        for(ll i = 1; i <= n; i++) cin >> arr[i];
            arr[n + 1] = 1e9;
        ll dem = 0, MAX = 0;
        for(ll i = 1; i <= n; i++){
            dem++;
            if(arr[i - 1] > arr[i] and arr[i] < arr[i + 1]) {
                if(dem > MAX) MAX = dem;
                dem = 1;
            }
            if(i == n) {
                if(dem > MAX) MAX = dem;
            }
            if(arr[i] == arr[i + 1]){
                if(dem > MAX) MAX = dem;
                dem = 0;
            }
        }
        cout<< MAX << endl;
    }
}