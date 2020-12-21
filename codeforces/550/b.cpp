#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    int imp=0, par=0;
    int a;
    vector <int> v;
    for(int i=0; i<n; i++){
        cin >> a;
        v.push_back(a);
        if(a%2==0)
            par++;
        else
            imp++;
    }
    sort(v.begin(), v.end());
    int soma = 0;
    int nimp=0, npar = 0;
    if(imp>par){
        nimp = imp - par-1;
    }
    if(par>imp)
        npar = par - imp - 1;
    int c=0;
    par = npar;
    imp = nimp;
    while((par!=0 or imp!=0) and c<n){
        if(v[c]%2==0 and par!=0){
            par--;
            soma+=v[c];
        }
        else if (v[c]%2!=0 and imp!=0){
            imp--;
            soma+=v[c];
        }
        c++;
    }
    cout << soma << endl; 
   return 0;
}