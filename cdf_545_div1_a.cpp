// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA. Double cannot be used
// for comparisons use div and mod instead. 
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define auth set <lld> :: iterator
#define pb push_back
void psort (lld A[], lld B[], lld n)
{
	pair <lld, lld> P[n];
	for(lld i = 0; i < n; i += 1){
		P[i].first  = A[i];
		P[i].second = B[i];
	}
	sort(P,P+n);
	for(lld i = 0; i < n; i += 1){
		A[i] = P[i].first;
		B[i] = P[i].second;
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      lld dda[n][m];
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < m; j += 1){
      		cin >> dda[i][j];
      	}
      }
      lld a[n][m];
      for(lld i = 0; i < n; i += 1){
      	lld A[m],B[m];
      	for(lld j = 0; j < m; j += 1){
      		A[j] = dda[i][j];
      		B[j] = j;
      	}
      	psort(A,B,m);
      	a[i][B[0]]= 1;
      	for(lld j = 1; j < m; j += 1){
      		if (A[j] == A[j-1])
      			a[i][B[j]] = a[i][B[j-1]]+0;
      		else
      			a[i][B[j]] = a[i][B[j-1]]+1;
      	}
      }
      lld b[n][m];
      for(lld j = 0; j < m; j += 1){
      	lld A[n],B[n];
      	for(lld i = 0; i < n; i += 1){
      		A[i] = dda[i][j];
      		B[i] = i;
      	}
      	psort(A,B,n);
      	b[B[0]][j]= 1;
      	for(lld i = 1; i < n; i += 1){
      		if (A[i] == A[i-1])
      			b[B[i]][j] = b[B[i-1]][j]+0;
      		else
      			b[B[i]][j] = b[B[i-1]][j]+1;
      	}
      }
      lld a_max[n];
      for(lld i = 0; i < n; i += 1){
      	lld ans = MIN;
      	for(lld j = 0; j < m; j += 1){
      		ans = max(ans, a[i][j]);
      	}
      	a_max[i] = ans;
      }
      lld b_max[m];
      for(lld j = 0; j < m; j += 1){
      	lld ans = MIN;
      	for(lld i = 0; i < n; i += 1){
      		ans = max(ans, b[i][j]);
      	}
      	b_max[j] = ans;
      }
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < m; j += 1){
      		if (a[i][j] >= b[i][j]){
      			lld df = a[i][j]-b[i][j];
      			cout << max(a_max[i], df+b_max[j]) << " ";
      		}
      		else{
      			lld df = b[i][j]-a[i][j];
      			cout << max(df+a_max[i], b_max[j]) << " ";
      		}
      	}
      	cout << "\n";
      }
      return 0;
}