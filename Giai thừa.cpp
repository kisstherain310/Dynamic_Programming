#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
#define test() int t; cin >> t; while(t--)
 
ll mod = 1000033;
 
ll divide(ll x, ll k){
    ll res = x, K = k;
    vector<ll> m; m.push_back(K);
    while(k > 1){
        m.push_back(k / 2);
        k /= 2;
    }
    for(int i = m.size() - 1; i >= 1; i--){
        if(m[i] * 2 == m[i - 1]) res = (res * res) % mod;
        else res = (res * res * x) % mod;
    }
    return res;
}
 
int main(){
    faster();
    vector<ll> vl;
    vl.push_back(1);
    vl.push_back(1);
    for(int i = 2; i <= 1000022; i++) vl.push_back(vl[i - 1] * i % mod);
    for(int i = 2; i <= 1000022; i++) vl[i] = (vl[i] * vl[i - 1]) % mod; // prefix 
 
    test(){
        ll l, r, k;
        cin >> l >> r >> k;
        if(r >= mod) cout << 0 << endl;
        else {
            ll x = (vl[r] * divide(vl[l - 1], mod - 2)) % mod;
            cout << divide(x, k) << endl;
        }
    }
}   