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
void no () {cout << "NO\n";}
void yes() {cout << "YES\n";}
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
      lld A[n];
      map <lld, lld> cnt, mac, ans;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	cnt[A[i]]++;
      }
      for(map <lld, lld> :: iterator itr = cnt.begin(); itr != cnt.end(); itr++){
      	lld x = itr->second;
      	map <lld, lld> temp;
      	for(lld i = 1; i <= x; i += 1){
      		temp[x/i] = i;
      	}
      	lld r;
      	for(lld i = x; i >= 1; i -= 1){
      		if (temp.count(i))
      			r = temp[i];
      		else
      			temp[i] = r;
      	}
      	for(lld i = 1; i <= x; i += 1){
      		mac[i] += temp[i];
      	}
      }
      lld len = mac.size();
      lld a[len], b[len], j = 0;
      for(map <lld, lld> :: iterator itr = mac.begin(); itr != mac.end(); itr++){
      	a[j] = itr->first; b[j] = itr->second; j++;
      }
      psort(a,b,len);
      lld copy;
      for(lld i = len-1; i >= 0; i -= 1){
      	if (b[i] >= k)
      		{copy = a[i]; break;}
      }
      for(map <lld, lld> :: iterator itr = cnt.begin(); itr != cnt.end(); itr++){
      	lld x = itr->second;
      	for(lld i = 1; i <= x; i += 1){
      		if (i == copy){
      			lld y;
      			y = x/i;
      			if (k > y)
      				{ans[itr->first] = y; k-= y;}
      			else
      				{ans[itr->first] = k; k = 0;}
      		}
      	}
      	if (k == 0)
      		break;
      }
      for(map <lld, lld> :: iterator itr = ans.begin(); itr != ans.end(); itr++){
      	for(lld i = 0; i < itr->second; i += 1)
      		cout << itr->first << " ";
      }
      return 0;
}