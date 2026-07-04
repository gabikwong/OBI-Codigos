#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n, k; cin >> n >> k;
    vector<ll> v(n);

    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end(), greater<>());

    cout << v[k-1] << "\n";

    return 0;
}