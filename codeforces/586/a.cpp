#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    string letters;
    cin >> letters;
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (letters[i] == 'n')
        {
            counter++;
        }
    }
    n = n - counter*3;
    for (int i = 0; i < counter; i++)
    {
        cout << 1 << " ";
    }
    for (int i = 0; i < n/4; i++)
    {
        cout << 0 << " ";
    }

    cout << endl;

   return 0;
}