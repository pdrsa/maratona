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

string s;
int pos;

void stop(){ // Mentiu
	cout << "NO" << endl;
	exit(0);
}

void go(){ // Anda e pula espaço em branco
	if(pos == s.size()) stop();
	pos++;
	if(s[pos] == ' ') go();
}

void M();
void I();
void T();
void F();
void H();

void T(){
	if(s[pos] == '{'){ // Se abre chave
		go(); M();
		if(s[pos] != '}') stop(); // Tem que fechar chave
		go();
	} else I(); // Se não abre chave T é I
}

void I(){ // Anda até o fim de um dígito
	if(s[pos] < '0' or s[pos] > '9') stop(); // Se não for dígito é mentira
	while(s[pos] >= '0' and s[pos] <= '9') pos++; // Se achei um digito tá safe
	go();
}

void P(){ // P tem que achar T enquanto achar ':'
	if(s[pos] == ':'){ go(); T(); P();};
}

void F(){ // Tipo First sla
	if(s[pos] == '|'){
		go(); T(); P(); F();
	}
}

void H(){
	go();
	if(s[pos] != '|') stop();
	go();
	T(); P(); F();
}

void M(){ // Esse aqui é o bicho inteiro
	if(s[pos] == '$') H();
	else if(s[pos] == '|'){
		go(); M(); F();
	}
	else{
		P(); F();
	}
}

int main(){ _
	cin >> s; s.pb('*');
	pos = 0;
	M();
	if(pos != s.size() - 1) stop();
	cout << "YES" << endl;
	exit(0);
}
