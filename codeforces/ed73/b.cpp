#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(count % 2 == 0)
                cout << "W";
            else
            {
                cout << "B";
            }
            count++;
        }
        cout << endl;
    }

   return 0;
}