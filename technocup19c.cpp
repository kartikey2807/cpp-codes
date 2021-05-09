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
#define auth set <pair <lld, lld> > :: iterator
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
      lld A[3], B[3];
      for(lld i = 0; i < 3; i += 1){
      	cin >> A[i] >> B[i];
      }
      psort(B,A,3);
      psort(A,B,3);
      set <pair <lld, lld> > ans;
      if ((A[1] >= A[0] && A[1] <= A[2]) && (B[1] >= min(B[0],B[2]) && B[1] <= max(B[0],B[2]))){
      	for(lld i = A[0]; i <= A[1]; i += 1)
      		ans.insert(make_pair(i,B[0]));
      	for(lld j = min(B[0],B[1]); j <= max(B[0],B[1]); j += 1)
      		ans.insert(make_pair(A[1],j));
      	for(lld i = A[1]; i <= A[2]; i += 1)
      		ans.insert(make_pair(i,B[1]));
      	for(lld j = min(B[1],B[2]); j <= max(B[1],B[2]); j += 1)
      		ans.insert(make_pair(A[2],j));
      }
      else{
      	if (B[1] > max(B[0],B[2])){

      		for(lld j = B[0]; j <= max(B[0],B[2]); j += 1)
      			ans.insert(make_pair(A[0],j));
      		for(lld i = A[0]; i <= A[2]; i += 1)
      			ans.insert(make_pair(i,max(B[0], B[2])));
      		for(lld j = B[2]; j <= max(B[0],B[2]); j += 1)
      			ans.insert(make_pair(A[2],j));

      		for(lld j = B[1]; j >= max(B[0],B[2]); j -= 1)
      			ans.insert(make_pair(A[1],j));
      	}
      	else{
      		for(lld j = B[0]; j >= min(B[0],B[2]); j -= 1)
      			ans.insert(make_pair(A[0],j));
      		for(lld i = A[0]; i <= A[2]; i += 1)
      			ans.insert(make_pair(i,min(B[0], B[2])));
      		for(lld j = B[2]; j >= min(B[0],B[2]); j -= 1)
      			ans.insert(make_pair(A[2],j));

      		for(lld j = B[1]; j <= min(B[0],B[2]); j += 1)
      			ans.insert(make_pair(A[1],j));
      	}
      }
      cout << ans.size() << "\n";
      for(auth itr = ans.begin(); itr != ans.end(); itr++)
      	cout << (*itr).first << " " << (*itr).second << "\n";
      return 0;
}