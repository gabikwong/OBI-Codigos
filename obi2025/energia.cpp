#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back

// conta quantos valores existem entre l e r no vetor v
int query(vector<int> &v, int l, int r){
    int ret = (--upper_bound(v.begin(), v.end(), r) - --lower_bound(v.begin(), v.end(), l));
    return ret;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q, k; cin >> n >> q >> k;
    vector<int> a(n+10);
    for(int i=1; i<=n; ++i) cin >> a[i];

    unordered_map<int, vector<int>> mp_soma, mp_sub;
    for(int i=1; i<=n; ++i){
        mp_soma[i+a[i]].pb(i);
        mp_sub[i-a[i]].pb(i);
    }

    int resp = 0;
    for(int j=1; j<=n; ++j){
        int l1 = max(1LL, j-k), r1 = j-1;
        if(l1<=r1) resp += query(mp_soma[j+a[j]-k], l1, r1);

        int l2 = max(1LL, j-k+1), r2 = j-1;
        if(l2<=r2) resp += query(mp_sub[j-a[j]-k], l2, r2);
    }

    cout << resp << "\n";

    set<pii> s; //intervalos disjuntos atuais
    s.insert({1, n});
    while(q--){
        int m; cin >> m;
        auto it = --s.upper_bound({m, n+1});
        int l = it->first, r = it->second, L = m-l, R = r-m, cur = 0;
        if(L<=R){
            for(int j=l; j<=m; ++j){
                int l1 = m, r1 = min(r, j+k-1);
                if(l1<=r1) cur += query(mp_soma[j+a[j]+k], l1, r1);

                int l2 = m, r2 = min(r, j+k);
                if(l2<=r2) cur += query(mp_sub[j-a[j]+k], l2, r2);
            }
        }else{
            for(int j=m; j<=r; ++j){
                int l1 = max(l, j-k), r1 = m;
                if(l1<=r1) cur += query(mp_soma[j+a[j]-k], l1, r1);

                int l2 = max(l, j-k+1), r2 = m;
                if(l2<=r2) cur += query(mp_sub[j-a[j]-k], l2, r2);
            }
        }

        resp -= cur;
        cout << resp << "\n";

        pii novo1 = {it->first, m-1}, novo2 = {m+1, it->second};
        s.erase(it);
        if(novo1.first<=novo1.second) s.insert(novo1);
        if(novo2.first<=novo2.second) s.insert(novo2);
    }
}