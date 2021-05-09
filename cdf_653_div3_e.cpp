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
set <lld> alice, bobie;
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
      lld n, k;
      cin >> n >> k;
      lld A[n], T[n];
      map <lld, lld> mac;
      for(lld i = 0; i < n; i += 1){
      	lld a, b;
      	A[i] = i;
      	cin >> T[i] >> a >> b;
      	if (a == 1)
      		alice.insert(i);
      	if (b == 1)
      		bobie.insert(i);
      	mac[A[i]] = T[i];
      }
      if (alice.size() < k || bobie.size() < k){
      	cout << "-1";
      }
      else{
      	psort(T,A,n);
      	vector <lld> a, b, x;
      	for(lld i = 0; i < n; i += 1){
      		if (alice.count(A[i]) && bobie.count(A[i])){
      			x.pb(A[i]);
      		}
      		else{
      			if (alice.count(A[i]))
      				a.pb(A[i]);
      			if (bobie.count(A[i]))
      				b.pb(A[i]);
      		}
      	}
      	lld sum = 0;
      	lld i = 0, j = 0, l = 0;
      	lld cnt_a = 0,cnt_b = 0;
      	while(cnt_a < k && cnt_b < k){
      		if (j < a.size() && l < b.size() && i < x.size()){
      			if (mac[a[j]]+mac[b[l]] < mac[x[i]]){
      				sum+= mac[a[j]] + mac[b[l]];
      				j++;
      				l++;
      			}
      			else{
      				sum+= mac[x[i]];
      				i++;
      			}
      		}
      		else{
      			if (i < x.size()){
      				sum+= mac[x[i]];
      				i++;
      			}
      			else{
      				sum+= mac[a[j]] + mac[b[l]];
      				j++;
      				l++;
      			}
      		}
      		cnt_a++;
      		cnt_b++;
      	}
      	cout << sum;
      }
      return 0;
}