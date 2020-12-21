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
	int t; cin >> t;
	while(t--){
		int count = 0;
		string n; cin >> n;
		for (int i = n.size() - 1;i >= 0; i--){
			if (n[i] != '0') count++;
		}
	
		cout << count << endl;

		for (int i = 0; i < n.size(); i++){
			if (n[i] != '0'){
				cout << n[i];
				for (int j = 0; j < (n.size() - 1 - i); j++) cout << '0';
				cout << " ";
			}
		}
		cout << endl;
	}
	exit(0);
}
