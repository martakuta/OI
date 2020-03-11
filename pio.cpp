//Marta Markocka
#include <bits/stdc++.h>
using namespace std;

struct ruch {
	int x, y, tg, cw;
};

ruch T[400*1000+5];

bool comp (ruch a, ruch b) {
	if (a.cw < b.cw)
		return true;
	else if (a.cw == b.cw && a.tg < b.tg)
		return true;
	else
		return false;
}

int main () {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>> n;
	for (int i=0; i<n; i++) {
		int xx, yy;
		cin>> xx >> yy;
		T[i].x = xx;
		T[i].y = yy;
		if (xx > 0 && yy >= 0) { // I cwiartka
			T[i].cw = 1;
			T[i].tg = (yy*100000)/xx;
		} else if (xx <= 0 && yy > 0) { // II cwiartka
			T[i].cw = 2;
			if (xx == 0)
				T[i].tg = 0;
			else 
				T[i].tg = -(xx*100000)/yy;
		} else if (xx < 0 && yy <= 0) { // III cwiartka
			T[i].cw = 3;
			T[i].tg = (yy*100000)/xx;
		} else if (xx >= 0 && yy < 0) { // IV cwiartka
			T[i].cw = 4;
			if (xx == 0)
				T[i].tg = 0;
			else
				T[i].tg = -(xx*100000)/yy;
		}
	}
	sort (T, T+n, comp);
	for (int i=0; i<n; i++) {
		T[n+i].x = T[i].x;
		T[n+i].y = T[i].y;
		T[n+i].tg = T[i].tg;
		T[n+i].cw = T[i].cw;
	}
	int p=0, k=0, wx=T[0].x, wy=T[0].y, w=wx*wx + wy*wy;
	int najw = w;
	while (k < 2*n) {
//		cout<<"w0: " << p << " " << k << " " << w << "\n";
		int nowy = (wx+T[k+1].x)*(wx+T[k+1].x) + (wy+T[k+1].y)*(wy+T[k+1].y);
		while (nowy > w) {
			wx += T[k+1].x;
			wy += T[k+1].y;
			w = nowy;
			if (w > najw)
				najw = w;
			k++;
			nowy = (wx+T[k+1].x)*(wx+T[k+1].x) + (wy+T[k+1].y)*(wy+T[k+1].y);
		}
//		cout<< "po k: " << p << " " << k << " " << w << "\n";
		wx -= T[p].x;
		wy -= T[p].y;
		w = wx*wx + wy*wy;
		if (w > najw)
			najw = w;
		p++;
		if (k < p) {
			k = p;
			wx = T[p].x;
			wy = T[p].y;
			w = wx*wx + wy*wy;
		}
//		cout<< "po p: " << p << " " << k << " " << w << "\n";
	}
	cout<< najw << "\n";
	
	return 0;
}
