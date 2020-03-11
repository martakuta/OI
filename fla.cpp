//Marta Markocka
#include <iostream>
using namespace std;
int T[500*1000+5][4];
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, k, x, a, b, iloscklik=0;
	cin>> n >> k;
	T[0][0]=0;
	T[0][1]=0;
	T[0][2]=0;
	T[0][3]=0;
	T[n+1][0]=k;
	T[n+1][1]=-1000*1000*1000-5;
	T[n+1][2]=1000*1000*1000+5;
	for (int i=1; i<=n; i++) {
		cin>> x >> a  >> b;
		T[i][0]=x;
		T[i][1]=a+1;
		T[i][2]=b-1;
	}
	for (int i=1; i<=n; i++) {
		T[i][1] = max (T[i-1][1]-T[i][0]+T[i-1][0], T[i][1]);
		T[i][2] = min (T[i-1][2]+T[i][0]-T[i-1][0], T[i][2]);
	}
	for (int i=n; i>=1; i--) {
		T[i][1] = max (T[i+1][1]-T[i+1][0]+T[i][0], T[i][1]);
		T[i][2] = min (T[i+1][2]+T[i+1][0]-T[i][0], T[i][2]);
	}
	for (int i=1; i<=n; i++) {
		if (T[i][0]%2 - T[i][1]%2 == 0 || T[i][0]%2 + T[i][1]%2 == 0)
			T[i][3]=T[i][1];
		else T[i][3]=T[i][1]+1;
		if (T[i][3] > T[i][2]) {
			cout<< "NIE";
			//for (int s=1; s<=n; s++)
			//	cout<< T[s][0]<<" "<<T[s][1]<<" "<<T[s][2]<<" "<<T[s][3]<<"\n";
			return 0;
		}
		int rozwys = T[i][3] - T[i-1][3];
		int klik = (T[i][0] - T[i-1][0] + rozwys)/2;
		iloscklik += klik;
	}
	//for (int i=1; i<=n+1; i++)
		//cout<< T[i][0] << " " << T[i][1] << " " << T[i][2] << " " << T[i][3] << "\n";
	if (iloscklik < 0)
		cout<< "0";
	else
		cout<< iloscklik;
	return 0;
}
