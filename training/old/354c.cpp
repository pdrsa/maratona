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
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	int maior = 1, k2 = k, lc = 0, l = 0, r = 0;
	
	
	if (k == 0){
		int atual = 1;
		for (int i = 0; i < n-1; i++){
			if (atual > maior)
				maior = atual;
			if(s[i] == s[i+1])
				atual++;
			else
				atual = 1;
		}
		cout << maior << endl;
		exit(0);
	}
	
	
	while (r < n){
		if (s[r] == 'a'){
			if (k2 > 0){
				k2--;
				r++;
			}
			else{
				while(s[l] != 'a'){
					l++;
				}
				l++;
				k2++;
			}
		}
		else{
			r++;
		}

		if (r - l > maior){
			maior = r - l;
		}
	}
	
	l = 0;
	r = 0;
	k2 = k;
	lc = 0;
	
	while (r < n){
		if (s[r] == 'b'){
			if (k2 > 0){
				k2--;
				r++;
			}
			else{
				while(s[l] != 'b'){
					l++;
				}
				l++;
				k2++;
			}
		}
		else{
			r++;
		}

		if (r - l > maior){
			maior = r - l;
		}
	}

	cout << maior << endl;

	exit(0);
}
