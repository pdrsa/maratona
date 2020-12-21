#include <bits/stdc++.h>

using namespace std;

int main()
{
    int round;
    cin >> round;
    int answers[round];
    for (int a = 0; a < round; a++)
    {
        int n, bad=0, menor = 1000000;
        cin >> n;
        int days[n];
        
        for (int i = 0; i < n; i++)
        {
            cin >> days[i];
        }

        for (int i = n-1; i >= 0; i--)
        {
            if (days[i] <= menor)
            {
                menor = days[i];
            }
            else
            {
                bad++;
            }
            

        }

        answers[a] = bad;
    }
    
    for (int i = 0; i < round; i++)
    {
        cout << answers[i] << endl;
    }

    return 0;
}