#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll e, d; cin >> e >> d;
    
    if(e > d){
        cout << e + d << "\n";
    }
    else{
        cout << 2*(d-e) << "\n";
    }

    return 0;
}