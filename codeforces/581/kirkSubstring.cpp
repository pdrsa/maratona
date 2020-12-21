#include <bits/stdc++.h>

using namespace std;

int main()
{
    string bString, resposta;
    cin >> bString;
    int maior = 1, atual = 1;

    for (int i = 1; i < bString.length(); i++)
    {
        if (bString[i] >= bString[i-1])
        {
            atual++;
        }
        if (atual > maior)
        {
            maior = atual;
        }
        if (bString[i] < bString[i-1])
        {
            atual = 1;
        }
    }

    int i = 0;

    cout << maior;

    while (i < bString.length())
    {
        for (int j = 0; j < maior-1; j++)
        {
            if (i < bString.length())
            {
                resposta.push_back('0');
                i++;
            }
        }
        if (i < bString.length())
        {
            if (i == bString.length()-1)
            {
                resposta.push_back('0');
                i++;
            }
            else
            {
                resposta.push_back('1');
                i++;
            }
        }
    }

    cout << "\n" << resposta << "\n";
}