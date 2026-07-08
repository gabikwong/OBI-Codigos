
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n, m;
    cin >> n >> m;
    if (m >= n + (n - 1) * 4)
        cout << "S";
    else
        cout << "N";
}