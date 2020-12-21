#include <bits/stdc++.h>
using namespace std;

int main ()
{
    char a[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string s;
    cin >> s;
    int menor = 26;
    // char ans[s.size()];
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (s[i] == a[j])
            {
                if (j <= menor)
                {
                    menor = j;
                    cout << "Mike" << endl;
                }
                else{
                    cout << "Ann" << endl;
                }
            }            
        }
    }

   return 0;
}