#include <bits/stdc++.h>

using namespace std;

int main()
{
    int round;
    cin >> round;
    unsigned long long int answers[round];
    for (int a = 0; a < round; a++)
    {
        unsigned long long int n, m, numberOfD, total, sobra,  ldm, atual, bla, soma = 0;
        vector <int> lNs;
        cin >> n;
        cin >> m;
        if (n < m)
        {
            answers[a] = 0;
            continue;
        }
        numberOfD = n / m;
        ldm = m % 10;
        atual = ldm;

        while(atual != 0)
        {
            lNs.push_back(atual);
            atual = atual + ldm;
            atual = atual % 10;
        }
        lNs.push_back(atual);

        for (int i = 0; i < lNs.size(); i++)
        {
            soma += lNs[i];
        }

        bla = numberOfD / lNs.size();
        total = bla * soma;
        sobra = numberOfD % lNs.size();
        
        for (int j = 0; j < sobra; j++)
        {
            total = total + lNs[j];
        }

        answers[a] = total;
    }

    for (int i = 0; i < round; i++)
    {
        cout << answers[i] << endl;
    }

    return 0;
}