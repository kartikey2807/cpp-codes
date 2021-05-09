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
      lld n;
      cin >> n;
      lld A[n];
      set <lld> vis;
      map <lld, lld> mac;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	mac[A[i]] = i;
      	vis.insert(A[i]);
      }
      lld m;
      cin >> m;
      lld w, h;
      lld pos = -1;
      for(lld i = 0; i < m; i += 1){
      	cin >> w >> h;
      	w--;
      	lld new_height;
      	if (w <= pos){
      		cout <<A[pos]<< "\n";
      		new_height=A[pos]+h;
      	}
      	else{
      		cout << A[w] << "\n";
      		new_height = A[w]+h;
      	}
      	if (vis.count(new_height)){
      		pos=mac[new_height];
      	}
      	else{
      		vis.insert(new_height);
      		set <lld> :: iterator itr = vis.find(new_height);
      		itr--;
      		pos = mac[*itr];
      	}
      	A[pos] = new_height;
      	mac[new_height]=pos;
      }
      return 0;
}