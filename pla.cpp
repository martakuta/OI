//Marta Markocka
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define f first
#define s second

int T[500*1000+5][4]; //id - stacja; 0 - odl do dworca; 1 - odl do lotniska; 2 - roznica; 3 - suma;
int odp[500*1000+5][3]; //0, 1 - wierzcholki polaczenia; 2 - dlugosc polaczenia
pair < pair <int, int>, int> U[500*1000+5]; //stacje o najmniejszych sumach: 0 - do dworca; 1 - do lotniska; 2 - stacja

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, y=0, x=0;
	cin>> n;
	if (n == 2) {
		cout<< "TAK\n1 2 3";
		return 0;
	}
	for (int i=2; i<n; i++)
		cin>> T[i][0];
	for (int i=2; i<n; i++)
		cin>> T[i][1];
	int najm_suma=1000*1000*1000;
	for (int i=2; i<n; i++) {
		T[i][2] = T[i][0] - T[i][1];
		T[i][3] = T[i][0] + T[i][1];
		if (T[i][3] < najm_suma)
			najm_suma = T[i][3];
	}
	for (int i=2; i<n; i++) {
		if (T[i][3] == najm_suma) {
			U[y].f.f = T[i][0];
			U[y].f.s = T[i][1];
			U[y].s = i;
			y++;
		}
	}
	sort (U, U+y);
	for (int i=1; i<y; i++) {
		if (U[i].f.f == U[i-1].f.f && U[i].f.s == U[i-1].f.s) {
			cout<< "NIE\n";
			return 0;
		}
	}
	int pierwsza_roznica = T[2][2];
	bool takie_same_roznice = 1;
	for (int i=2; i<n; i++) {
		if (pierwsza_roznica != T[i][2] && pierwsza_roznica != -T[i][2]) {
			takie_same_roznice = 0;
			break;
		}
	}
	if (takie_same_roznice == 1 && pierwsza_roznica != 0) {
		odp[0][0] = 1;
		odp[0][1] = n; 
		odp[0][2] = abs(pierwsza_roznica);
		x++;
		for (int i=2; i<n; i++) {
			if (T[i][0] < T[i][1]) {
				odp[x][0] = 1;
				odp[x][1] = i;
				odp[x][2] = T[i][0];
				x++;
			} else {
				odp[x][0] = n;
				odp[x][1] = i;
				odp[x][2] = T[i][1];
				x++;
			}
		}
		cout<< "TAK\n";
		for (int i=0; i<x; i++)
			cout<< odp[i][0] << " " << odp[i][1] << " " << odp[i][2] << "\n";
		return 0;
	}
	odp[0][0] = 1;
	odp[0][1] = U[0].s;
	odp[0][2] = U[0].f.f;
	x++;
	int jak_daleko = odp[0][2];
	for (int i=1; i<y; i++) {
		int do_dworca = U[i].f.f;
		int do_lotniska = U[i].f.s;
		int stacja = U[i].s;
		odp[x][0] = odp[x-1][1]; //od poprzedniego
		odp[x][1] = stacja; //do obecnej stacji
		odp[x][2] = do_dworca - jak_daleko; //odleglosc pomniejszona o te juz zrobiona do stacji obok w strone lotniska
		jak_daleko += odp[x][2];
		x++;
	}
	odp[x][0] = odp[x-1][1];
	odp[x][1] = n;
	odp[x][2] = U[y-1].f.s;
	x++;
	for (int i=2; i<n; i++) {
		if (T[i][2] < najm_suma && T[i][3] != najm_suma) {
			int roz = T[i][2];
			for (int j=0; j<y; j++) {
				if (U[j].f.f - U[j].f.s == roz) {
					odp[x][0] = U[j].s;
					odp[x][1] = i;
					odp[x][2] = T[i][0] - T[U[j].s][0];
					x++;
				}
			}
		}
		if (T[i][2] == najm_suma) {
			odp[x][0] = n;
			odp[x][1] = i;
			odp[x][2] = T[i][1];
			x++;
		} else if (-T[i][2] == najm_suma) {
			odp[x][0] = 1;
			odp[x][1] = i;
			odp[x][2] = T[i][0];
			x++;
		}
	}
	if (x == n-1)
		cout<< "TAK\n";
	else {
		cout<< "NIE\n";
		return 0;
	}
	for (int i=0; i<x; i++)
		cout<< odp[i][0] << " " << odp[i][1] << " " << odp[i][2] << "\n";
	return 0;
}
