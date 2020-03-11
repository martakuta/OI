#include <iostream>
#include <algorithm>
using namespace std;
long long T[200];
pair < int, pair <int, int> > roznice [1600];
int main () {
	T[1]=1;
	T[2]=2;
	T[3]=4;
	int roznica = 4;
	for (int i=4; i<100; i += 2) {
		T[i] = T[i-1] + roznica;
		T[i+1] = 2 * T[i];
		for (int j=i+1; j>0; j--) {
			for (int k=j-1; k>0; k--) {
//				cout<< "\n" << i << " " << j << " " << k << " ";
//				cout<< T[j] << " " << T[k] << " " << T[j]-T[k] << " ";
				if (T[j] - T[k] == roznica+1) {
					roznica++;
					j=i+1;
					k=i-1;
//					cout << roznica << " ";
				}
			}
		}
		roznica++;
//		cout<< roznica << " ";
	}
	cout<< "\n";
	int znacznik=0;
	for (int i=0; i<100; i++)
		cout << T[i] << ", ";
	cout<< "\n\n";
	for (int i=56; i>0; i--) {
		for (int j=i-1; j>0; j--) {
			roznice[znacznik].first = T[i] - T[j];
			roznice[znacznik].second.first = i;
			roznice[znacznik].second.second = j;
			znacznik ++;
		}
	}
	sort (roznice, roznice+1540);
	for (int i=0; i<1540; i++)
		cout<< roznice[i].first << ", ";
	cout<< "\n\n";
	for (int i=0; i<1540; i++)
		cout<< roznice[i].second.first << ", ";
	cout<< "\n\n";
	for (int i=0; i<1540; i++)
		cout<< roznice[i].second.second << ", ";
	
}
