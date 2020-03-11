//Marta Markocka
#include <bits/stdc++.h>
using namespace std;

int T[3005][3005];
map <int, int> my;
map <int, int>::iterator it;
map <int, int> m2;
int najw=0;
long long suma=0;


void licz () {
	int rozm = my.size();
	if (rozm > najw)
		najw = rozm;
	suma += rozm;
//	cout<< "licz " << rozm << "\n";
//	cout<< "najw=" << najw << " suma=" << suma <<"\n";
}

void dodaj (int x) {
	it = my.find(x);
	if (it == my.end())
		my[x] = 1;
	else {
		int w = my[x];
		w++;
		my[x] = w;
	}
}

void dodaj2 (int x) {
	it = m2.find(x);
	if (it == m2.end())
		m2[x] = 1;
	else {
		int w = m2[x];
		w++;
		m2[x] = w;
	}

}

void usun (int x) {
	if (my[x] == 1)
		my.erase(x);
	else {
		int w = my[x];
		w--;
		my[x] = w;
	}
}

void usun2 (int x) {
	if (m2[x] == 1)
		m2.erase(x);
	else {
		int w = m2[x];
		w--;
		m2[x] = w;
	}
}

void przepisz () {
	for (it=m2.begin(); it != m2.end(); it++) {
		int klucz = (*it).first;
		int wartosc = (*it).second;
		my[klucz] = wartosc;
	}
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, n, k;
	cin>> m >> n >> k;
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			cin>> T[i][j];
		}
	}
	for (int i=0; i<k; i++) {
		for (int j=0; j<k; j++) {
			int x = T[i][j];
			dodaj2(x);
		}
	}
	for (int i=k-1; i<m; i++) {
//		cout<< "i=" << i << "\n";
		if (i > k-1) {
			for (int a=0; a<k; a++) {
				int x = T[i-k][a];
				usun2(x);
			}
			for (int a=0; a<k; a++) {
				int x = T[i][a];
				dodaj2(x);
			}
		}
		przepisz();
		licz();
		for (int j=k; j<n; j++) {
//			cout<< "j=" << j << "\n";
			for (int a=i-k+1; a<=i; a++) {
				int x = T[a][j-k];
//				cout<< "a=" << a << " x=" << x << "\n";
				usun(x);
			}
			for (int a=i-k+1; a<=i; a++) {
				int x = T[a][j];
//				cout<< "a=" << a << " x=" << x << "\n";
				dodaj(x);
			}
			licz();
		}
		my.clear();
	}
	cout<< najw << " " << suma << "\n";
	return 0;
}
