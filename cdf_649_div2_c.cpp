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
#define l 100010
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld A[n],B[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      if (A[0] == 1){
      	B[0] = 0;
      	set <lld> vis;
      	for(lld i = 1; i < l; i += 1){
      		vis.insert(i);
      	}
      	for(lld i = 0; i < n; i += 1){
      		vis.erase(A[i]);
      	}
      	for(lld i = 1; i < n; i += 1){
      		if (A[i] == A[i-1]){
      			vis.insert(A[i]);
      			set <lld> :: iterator itr = vis.find(A[i]);
      			itr++;
      			B[i] = (*itr);
      			vis.erase(*itr);
      			vis.erase(A[i]);
      		}
      		else 
      			B[i] = A[i-1];
      	}
      	for(lld i = 0; i < n; i += 1)
      		cout << B[i] << " ";
      }
      else{
      	set <lld> vis;
      	for(lld i = 1; i < l; i += 1){
      		vis.insert(i);
      	}
      	for(lld i = 0; i < n; i += 1){
      		vis.erase(A[i]);
      	}
      	set <lld> :: iterator itr = vis.begin();
      	B[0] = *itr;
      	vis.erase(*itr);
      	for(lld i = 1; i < n; i += 1){
      		if (A[i] == A[i-1]){
      			vis.insert(A[i]);
      			set <lld> :: iterator itr = vis.find(A[i]);
      			itr++;
      			B[i] = (*itr);
      			vis.erase(*itr);
      			vis.erase(A[i]);
      		}
      		else
      			B[i] = A[i-1];
      	}
      	for(lld i = 0; i < n; i += 1)
      		cout << B[i] << " ";
      }
      return 0;
}