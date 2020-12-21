#include <bits/stdc++.h>

using namespace std;

int main()
{
    int z;
    cin >> z;
    for (; z > 0; z--)
    {
        int n, a, b, c, r = 0, p = 0, s = 0, aW = 0;
        string bob;
        cin >> n >> a >> b >> c;
        cin >> bob;
        for (int i = 0; i < bob.length(); i++)
        {
            if (bob[i] == 'R')
            r++;
            if (bob[i] == 'S')
            s++;
            if (bob[i] == 'P')
            p++;
        }
        aW = min(a, s) + min(b, r) + min(c, p);
        float win = float(n)/2;



        int vp, vr, vs;
        vp = min(b, r);
        vr = min(a, s);
        vs = min(c, p);
        a = a - min(a,s);
        b = b - min(b,r);
        c = c - min(c, p);

        if (aW >= ceil(win))
        {
            cout << "YES\n";
            for (int i = 0; i < bob.length(); i++)
            {
                if (bob[i] == 'R')
                {
                    if (vp > 0)
                    {
                        cout << "P";
                        vp--;
                    }
                    else if (a > 0)
                    {
                        cout << "R";
                        a--;
                    }
                    else if (c > 0)
                    {
                        cout << "S";
                        c--;
                    }
                }
                if (bob[i] == 'P')
                {
                    if (vs > 0)
                    {
                        cout << "S";
                        vs--;
                    }
                    else if (a > 0)
                    {
                        cout << "R";
                        a--;
                    }
                    else if (b > 0)
                    {
                        cout << "P";
                        b--;
                    }
                }
                if (bob[i] == 'S')
                {
                    if (vr > 0)
                    {
                        cout << "R";
                        vr--;
                    }
                    else if (b > 0)
                    {
                        cout << "P";
                        b--;
                    }
                    else if (c > 0)
                    {
                        cout << "S";
                        c--;
                    }
                }
            }
            cout << "\n";
        }
        else
            cout << "NO\n";
        
    }
    

    return 0;
}