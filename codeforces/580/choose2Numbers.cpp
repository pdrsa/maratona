#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, contador, respostaA = 0, respostaB = 0;

    cin >> a;
    int va[a];

    for (int i = 0; i < a; i++)
    {
        cin >> va[i];
    }

    cin >> b;
    int vb[b];

    for (int i = 0; i < b; i++)
    {
        cin >> vb[i];
    }


    for (int i = 0; i < a; i++)
    {
        if (respostaA != 0)
            break;

        for (int j = 0; j < b; j++)
        {
            contador = 0;

            for (int k = 0; k < a; k++)
            {
                if ((va[i] + vb[j]) == va[k])
                {
                    contador++;
                }
            }

            for (int k = 0; k < b; k++)
            {
                if ((va[i] + vb[j]) == vb[k])
                {
                    contador++;
                }
            }
            
            if (contador == 0)
            {
                respostaA = va[i];
                respostaB = vb[j];
                break;
            }

        }
    }

    cout << respostaA << " " << respostaB;
    return 0;
}