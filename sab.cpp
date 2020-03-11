//Marta Markocka
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

double podwladni[500*1000+5];
double morale[500*1000+5];
vector <int> G[500*1000+5];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, a;
	double k;
	cin>> n >> k;
	for (int i=2; i<=n; i++) {
		cin>> a;
		G[a].push_back(i);
	}
	podwladni[0] = n;
	//licze ilosc podwladnych dla danego wierzcholka
	for (int i=n; i>0; i--) {
		for (int j=0; j<G[i].size(); j++)
			podwladni[i] += podwladni[G[i][j]] +1;
	}
	//licze najwieksze morale przy ktorym mimo wszystko wierzcholek moze sie zbuntowac
	for (int i=n; i>0; i--) {
		for (int j=0; j<G[i].size(); j++) {
			int syn= G[i][j];
			double czesc = (podwladni[syn]+1)/(podwladni[i]);
			double nowe = min (morale[syn], czesc);
			if (nowe > morale[i])
				morale[i] = nowe;
		}
		if (morale[i]==0) // czyli i nie ma synow
			morale[i]=1;
	}
	// znajduje szukane morale
	double szukanemorale=0;
	for (int i=1; i<=n; i++) {
		if (podwladni[i] >= k) {
			if (morale[i] > szukanemorale)
				szukanemorale = morale[i];
		}
	}
	cout<< setprecision(10) << fixed << szukanemorale;
	return 0;
}
