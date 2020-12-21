#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int t;
	cin >> t;
	for (int a = 0; a < t; a++){
		int n;
		cin >> n;
		ll arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		
		int atual;
		ll maior = arr[0];
		if (maior > 0)
			atual = 1;
		else
			atual = -1;
		ll soma = 0;
		for (int i = 1; i < n; i++){
			if (atual == 1){
				if (arr[i] < 0){
					atual = -1;
					soma += maior;
					maior = arr[i];
				}
				else{
					if(arr[i] > maior)
						maior = arr[i];
				}
			}
			else{
				if (arr[i] > 0){
					atual = 1;
					soma += maior;
					maior = arr[i];
				}
				else{
					if(arr[i] > maior)
						maior = arr[i];
				}
			}
		}
		soma += maior;
		cout << soma << endl;
	}
	exit(0);
}
