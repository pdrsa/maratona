//JP - Not in Kansas Anymore
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
	int n; cin >> n;
	set<string> sys;
	while(n--){
		string s; cin >> s;
		int li = 1, ri = sys.size();
		if(sys.count(s)){
			string news = s;
			
			while(li < ri){
				int mi = (li+ri)/2;
				news = s;
				news.append(to_string(mi));
				if(sys.count(news)) li = mi+1;
				else ri = mi;
			}

			news = s; news.append(to_string(li));
			sys.insert(news); cout << news << endl;
		}

		else{
			sys.insert(s);
			cout << "OK" << endl;
		}
	}
	exit(0);
}
