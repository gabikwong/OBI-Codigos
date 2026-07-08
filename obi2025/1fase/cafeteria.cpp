
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int maxi = c - a, mini = c - b;
    if ((maxi / d) * d >= mini)
        cout << "S";
    else
        cout << "N";
}