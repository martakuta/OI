#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define f first
#define s second

int T[1000*1000+5][3];
pair <int, int> U[1000*1000+5];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin>> n >> k;
	for (int i=1; i<=n; i++) {
		cin>> T[i][0] >> T[i][1];
		U[i].f = T[i][0];
		U[i].s = i;
	}
	sort (U+1, U+n+1);
	int pocz=0, kon=0, wolni=0;
	pair <int, int> maxiczas = mp(0,0);
	T[U[1].s][2] = 1;
	while (kon <= n) {
		while (T[U[pocz+1].s] == 0)
			pocz ++;
		if (wolni < k) {
			kon ++;
			wolni ++;
			int nr = U[kon].s;
			T[nr][2] = 1;
			q.push(mp(T[nr][1],nr));
			while (q.top().f < U[kon].f) {
				T[q.top().s][2] = 0;
				q.pop();
				wolni --;
			}
		} else {
			int czas = q.top().f - U[kon].f;
			if (czas > maxiczas.f) {
				maxiczas.f = czas;
				maxiczas.s = U[kon].f;
			}
			T[q.top().s][2] = 0;
			q.pop();
			wolni --;
		}
	}
	cout<< maxiczas.f << "\n";
	int szuk_p = maxiczas.s;
	int szuk_k = szuk_p + maxiczas.f;
	int il_wypis = 0;
	for (int i=1; i<=n; i++) {
		if (T[i][0] <= szuk_p && T[i][1] >= szuk_k) {
			cout<< i << " ";
			il_wypis++;
		}
		if (il_wypis == k)
			break;	
	}
	return 0;
}
