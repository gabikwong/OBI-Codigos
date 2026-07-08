#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k; cin >> n >> k;
    ++k;

    vector<int> a(n+10), b(n+10);
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];

    int resp = 0;
    vector<int> v1, v2;
    for(int i=1; i<=n; ++i){
        if(a[i]>=b[i]) resp+=a[i], resp-=b[i], v1.pb(b[i]);
        else v2.pb(a[i]);
    }

    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());

    int i=0, j=0;
    while(true){
        if(k==0) break;
        if(i==v1.size() && j==v2.size()) break;
        if(j==v2.size() || (i<v1.size() && v1[i]>=v2[j])) resp += v1[i], ++i;
        else if(i==v1.size() || (j<v2.size() && v1[i]<=v2[j])) resp += v2[j], ++j;
        --k;
    }

    cout << resp << "\n";
}