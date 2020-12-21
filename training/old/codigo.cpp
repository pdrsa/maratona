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
	int n;
	int a1 = 2, a2 = 2, a3 = 2;
	int contador = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		a3 = a2;
		a2 = a1;
		cin >> a1;
		if (a3 == 1 && a2 == 0 && a1 == 0)
			contador++;
	}
	cout << contador;
	exit(0);
}
