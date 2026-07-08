#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin >> n;
    vector<int> a(n + 3), idx;
    a[0] = 0;
    a[n + 1] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i <= n + 1; i++)
        if (a[i] != -1)
            idx.push_back(i);
    for (int i = 1; i < idx.size(); i++)
    {
        int l = idx[i - 1], r = idx[i];
        if (l == 0)
        {
            for (int j = r - 1; j > 0; j--)
                a[j] = a[j + 1] + 1;
            continue;
        }
        if (r == n + 1)
        {
            for (int j = l + 1; j < r; j++)
                a[j] = a[j - 1] + 1;
            continue;
        }

        while (r > l && a[l] > a[r])
        {
            a[r - 1] = a[r] + 1;
            r--;
        }
        while (r > l && a[l] < a[r])
        {
            a[l + 1] = a[l] + 1;
            l++;
        }
        while (r - l > 1)
        {
            a[l + 1] = a[l] + 1;
            a[r - 1] = a[r] + 1;
            r--;
            l++;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}