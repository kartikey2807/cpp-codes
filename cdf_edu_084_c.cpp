// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA.
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
#define pb push_back
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m, k;
      cin >> n >> m >> k;
      pair <lld, lld> s[k], d[k];
      for(lld i = 0; i < k; i += 1){
      	cin >> s[i].first >> s[i].second;
      }
      for(lld i = 0; i < k; i += 1){
      	cin >> d[i].first >> d[i].second;
      }
      if (n > 1 && m > 1){
      	for(lld i = 0; i < k; i += 1)
      		s[i].second = 0;
      	for(lld i = 0; i < k; i += 1)
      		s[i].first  = 0;
      	cout << (n+m+(n*m)) << "\n";
      	for(lld i = 0; i < m; i += 1)
      		cout << "L";
      	for(lld i = 0; i < n; i += 1)
      		cout << "U";
      	for(lld i = 0; i < n; i += 1){
      		if (i % 2 == 0){
      			for(lld j = 0; j < m-1; j += 1)
      				cout << "R";
      		}
      		else{
      			for(lld j = m-1; j > 0; j -= 1)
      				cout << "L";
      		}
      		cout << "D";
      	}
      }
      else{
      	if (m == 1){
      		cout << (2*n) << "\n";
      		for(lld i = 0; i < n; i += 1)
      			cout << "U";
      		for(lld i = 0; i < n; i += 1)
      			cout << "D";
      	}
      	else{
      		cout << (2*m) << "\n";
      		for(lld i = 0; i < m; i += 1)
      			cout << "L";
      		for(lld i = 0; i < m; i += 1)
      			cout << "R";
      	}
      }
      return 0;
}