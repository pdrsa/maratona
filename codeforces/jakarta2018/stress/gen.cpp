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
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int rand(int a, int b){ // Random on [a, b]
	return rand()%(b-a+1) + a;
}

int main(int argc, char** argv){ _
	srand(atoi(argv[1])); // Seed for rand()
	int n = rand(1, 2000);
	while(n--) cout << rand(0, 1);
	cout << endl;
	exit(0);
}
