//Marta Markocka
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define f first
#define s second

vector <pair <int, pair <int, int> > > G;
int rep[500*1000+5][2]; //w 0 wymiarze reprezentant; w 1 wymiarze wielkosc spojnej tego rep
long long wyn[500*1000+5][2]; //w 0 wymiarze wynik dla spojnej tego rep, w 1 wymiarze kiedy ostatnio bylo jakies liczenie dla spojnej tego rep
int poziom=1; //na ktorym obecnie poziomie licze
const long long mod = 1000*1000*1000+7;

bool comp (pair <int, pair <int, int> > a, pair <int, pair <int, int> > b) {
	return (a.f < b.f);
}

int fin (int v) {
	if (rep[v][0] == v)
		return v;
	else
		return rep[v][0] = fin(rep[v][0]);
}

void onion (int a, int b) {
		rep[fin(b)][0] = fin(a);
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, n, H;
	cin>> m >> n >> H;
	if (m == 1 && n == 1) {
		int wynik = H+1;
		cout<< wynik <<"\n";
		return 0;
	}
	if (n > 1) {
		for (int i=0; i<m; i++) {
			for (int j=1; j<n; j++) {
				int a;
				cin>> a;
				int nr1 = i*n + j;
				int nr2 = i*n + j + 1;
				G.push_back(mp(a, mp(nr1, nr2)));
			}
		}
	}
	if (m > 1) {
		for (int i=0; i<m-1; i++) {
			for (int j=1; j<=n; j++) {
				int a;
				cin>> a;
				int nr1 = i*n + j;
				int nr2 = (i+1)*n + j;
				G.push_back(mp(a, mp(nr1, nr2)));

			}
		}
	}
	sort (G.begin(), G.end(), comp); //sortuje rosnaco porownujac tylko wysokosc danej bariery
	for (int i=1; i<=m*n; i++) {
		wyn[i][0] = 1;
		rep[i][0] = i;
		rep[i][1] = 1;
	}
	for (int i=0; i<G.size(); i++) {
		int poz = G[i].f;
		int nr1 = G[i].s.f;
		int nr2 = G[i].s.s;
		if (rep[fin(nr1)][1] < rep[fin(nr2)][1]) //zawsze do wiekszej spojnej chce przyczepiac mniejsza
			swap(nr1, nr2);
		int a = fin(nr1);
		int b = fin(nr2);
		if (a != b) { //jesli nie sa jeszcze w jednej spojnej
			wyn[a][0] = wyn[a][0] + (poz - wyn[a][1]); //dodaje tyle o ile zwiekszyl sie poziom wody od ostatniego liczenia tutaj
			wyn[b][0] = wyn[b][0] + (poz - wyn[b][1]); //analogicznie dla drugiego
			wyn[a][1] = poz; //aktualizuje informacje poziomu ostatniego liczenia tutaj
			wyn[b][1] = poz; //analogicznie
			wyn[a][0] *= wyn[b][0];
			wyn[a][0] %= mod;
			rep[a][1] += rep[b][1]; //ile wierzcholkow bedzie teraz liczyc spojna
			poziom = poz;
			onion (nr1, nr2);
		}
	}
	long long wynik = wyn[fin(1)][0];
	if (poziom < H) {
		long long roznica = H - poziom;
		wynik += roznica;
	}
	wynik %= mod;
	cout<< wynik << "\n";
	return 0;
}
