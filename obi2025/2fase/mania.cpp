
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n, m;
    cin >> n >> m;
    int mat[n][m];
    int resp1 = 0, resp2 = 0; // caso (0,0) seja impar ou par respectivamente
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    // caso em que (0,0)sera impar
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] % 2 == (i + j) % 2)
                resp1++;
        }
    }
    // caso que (0,0) é par
    resp2 = (m * n) - resp1;
    int melhor = (resp1 <= resp2) ? 0 : 1;
    cout << min(resp1, resp2) << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!melhor)
                mat[i][j] += mat[i][j] % 2 == (i + j) % 2;
            else
                mat[i][j] += mat[i][j] % 2 != (i + j) % 2;
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}