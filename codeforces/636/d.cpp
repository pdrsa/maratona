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
		int n, k;
		cin >> n >> k;
		int menor = k;
		int maior = 0;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int aux;

		for (int i = 0; i < n/2; i++){
			aux = max(arr[i], arr[n-i-1]);
			if (aux < menor)
				menor = aux;
			aux = min(arr[i], arr[n-i-1]);
			if (aux > maior)
				maior = aux;
		}
		
		int maxValue = k + menor;
		int minValue = maior + 1;
		map<int, int> sums;
		
		for (int i = 0; i < n/2; i++){
			aux = arr[i] + arr[n-i-1];
			if (aux > maxValue)
				continue;
			if (aux < minValue)
				continue;
			if (sums.find(aux) == sums.end())
				sums[aux] = 1;
			else{
				sums[aux] += 1;
			}
		}
		
		maior = 0;
		auto it = sums.begin();

		while(it != sums.end()){
			if ((it -> s) > maior){
				maior = it -> s;
			}
			it++;
		}

		cout << (n/2) - maior << endl; 

		
	}
	exit(0);
}
