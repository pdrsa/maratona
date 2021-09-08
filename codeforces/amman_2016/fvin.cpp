// V
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define f first
#define s second

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n; cin >> n;

	while(n--) {
		string str; cin >> str;
		string os = str;

		sort(os.begin(), os.end());

		char a = '@', c = '@';

		for(int i = 0; i < (int) str.size(); i++) {
			if(str[i] != os[i]) {
				c = str[i];

				for(int j = i; j < (int) str.size(); j++) {
					if(j == 0 || os[j] != os[j-1]) {
						a = os[j];
						break;
					}
				}

				break;
			}
		}

		for(int i = 0; i < (int) str.size(); i++) {
			if(str[i] == a){
				str[i] = c;
			} else if(str[i] == c) {
				str[i] = a;
			}
		}

		cout << str << endl;
	}

	return 0;
}
