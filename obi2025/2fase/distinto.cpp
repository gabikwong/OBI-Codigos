
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p;
    cin >> p;
    while (p--)
    {
        int l, a, b;
        cin >> l >> a >> b;
        if ((b - a + 1) * (b + a) / 2 <= l)
            cout << b - a + 1 << endl;
        else
        {
            int e = a, d = b;
            int resp = -1;
            while (e <= d)
            {
                int m = e + (d - e) / 2;
                if ((m - a + 1) * (m + a) / 2 >= l)
                {
                    resp = m;
                    d = m - 1;
                }
                else
                    e = m + 1;
            }
            cout << resp - a + 1 << endl;
        }
    }
}