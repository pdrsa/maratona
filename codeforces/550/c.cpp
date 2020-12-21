#include <bits/stdc++.h>
using namespace std;

int main ()
{   
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());


    for (int i = 0; i < n-2; i++)
    {
        if (a[i] == a[i+2])
        {
            cout << "NO" << endl;
            exit(0);
        }
    }

    vector<int> dec;
    vector<int> cre;

    if (n == 1)
    {
        cout << "YES" << endl;
        cout << 0 << endl;
        cout << endl;
        cout << 1 << endl;
        cout << a[0] << endl;
        exit(0);
    }

    for (int i = 0; i < n-1; i++)
    {
        if (a[i] == a[i+1])
        {
            cre.push_back(a[i]);
        }
        else
        {
            dec.push_back(a[i]);
        }
        
    }

    dec.push_back(a[n-1]);

    cout << "YES" << endl;

    cout << cre.size() << endl;

    for (int i = 0; i < cre.size(); i++)
    {
        cout << cre[i] << " ";
    }
    cout << endl;
    
    cout << dec.size() << endl;

    reverse(dec.begin(), dec.end());

    for (int i = 0; i < dec.size(); i++)
    {
        cout << dec[i] << " ";
    }
    cout << endl;

    

   return 0;
}