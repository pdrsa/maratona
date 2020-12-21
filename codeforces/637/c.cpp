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
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		map<int,int> pos;
		int ponta = n-1;
		int pontaAn;
		for (int i = 0; i < n; i++){
			cin >> arr[i];
			pos[arr[i]] = i;
		}
		int num = 1;
		bool flag = true;

		while(num < n){
			if (pos[num] == ponta){
				num++;
				ponta--;
			}
			else{
				pontaAn = ponta;
				ponta = pos[num]-1;
				while(pos[num] != pontaAn){
					if(pos[num+1] != (pos[num]+1)){
						flag = false;
						break;
					}
					num++;
				}
				num++;
				pontaAn = ponta;
				if (!flag){
					cout << "No" << endl;
					break;
				}
			}
		}
		if (flag) cout << "Yes" << endl;


	}
	exit(0);
}
