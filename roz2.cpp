//Marta Markocka
#include <bits/stdc++.h>
using namespace std;

int T[3005][3005];
map <int, int> my;
map <int, int>::iterator it;
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

void usun (int x) {
	if (my[x] == 1)
		my.erase(x);
	else {
		int w = my[x];
		w--;
		my[x] = w;
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
	for (int i=k-1; i<m; i++) {
//		cout<< "i=" << i << "\n";
		for (int a=i-k+1; a<=i; a++) {
//			cout<< "a=" << a << "\n";
			for (int b=0; b<k; b++) {
				int x = T[a][b];
//				cout<< "b=" << b << " x=" << x << "\n";
				dodaj(x);
			}
		}
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
