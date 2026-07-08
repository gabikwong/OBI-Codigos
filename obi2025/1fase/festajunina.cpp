#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int p[3];
    cin >> p[0] >> p[1] >> p[2];
    sort(p, p + 3);
    cout << (p[2] - p[0]) * 2;
}