//Marta Markocka
#include <iostream>
using namespace std;
long long liczba[1000*1000+5];
long long B;
long long binsearch (long long x) {
	long long p=-1, k=B;
	while (p+1<k) {
		long long sr = (p+k)/2;
		if (liczba[sr] < x)
			p= sr;
		else
			k= sr;
	}
	return k;
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	long long q, zap;
	cin>> B >> q;
	for (long long i=0; i<B; i++)
		cin>> liczba[i];
	long long suma=0;
	for (long long i=1; i<B; i++) {
		suma += i*liczba[i];
		suma = suma%(B-1);
	}
	if (suma != 0)
		liczba[suma]--;
	liczba[0]--;
	for (long long i=1; i<B; i++)
		liczba[i] += liczba[i-1];
        for (long long i=0; i<q; i++) {
		cin>> zap;
		if (zap > liczba[B-1])
			cout<< "-1\n";
		else
			cout<< binsearch(zap) << "\n";
	}
	return 0;
}
