#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int z;
    cin >> z;
    for (int y = 0; y < z; y++){
        long long int v[3];
        long long int total = 0;
        cin >> v[0] >> v[1] >> v[2];
        long long int menor = 100000000;
        long long int maior;
        for (int i = 0; i < 3; i++)
        {
            if (v[i] < menor)
                menor = v[i];
        }
        total = total + menor;
        v[0] = v[0] - menor;
        v[1] = v[1] - menor;

        if (v[0] < v[1]){        
            menor = v[0];
            maior = v[1];
        }
        else{
            menor = v[1];
            maior = v[0];
        }

        int aux;

        if (maior >= 2 * menor){
            total += menor;
            menor = 0;
        }
        else{
            total += int((maior + menor)/3);
        }

        cout << total << endl;
    }

   return 0;
}