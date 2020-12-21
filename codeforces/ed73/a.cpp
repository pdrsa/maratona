#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int z;
    cin >> z;
    for (int y = 0; y < z; y++)
    {
        int n;
        cin >> n;
        vector<long long int> v(n);
        long long int aux;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        long long int sum = 0;
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            sum = 0;
            for (int i = j; i < n; i++)
            {
                sum += v[i];
                if (sum == 2048)
                {
                    cout << "Yes" << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }

        if (sum != 2048)
            cout << "No" << endl;
    }

   return 0;
}