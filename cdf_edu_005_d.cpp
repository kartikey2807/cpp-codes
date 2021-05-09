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
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      lld len = 0;
      map <lld, lld> mac;
      lld start = 0, end = n-1;
      for(lld i = 0; i < n; i += 1){
      	mac[A[i]]++;
      	if (mac[A[i]] == 1){
      		len++;
      	}
      	if (len > k){
      		mac[A[i]]--;
      		end = i-1;
      		len--;
      		break;
      	}
      }
      lld ans = end-start+1;
      pair <lld,lld> pos = make_pair(start,end);
      while(true){
      	mac[A[start]]--;
      	if (mac[A[start]]  ==  0){
      		len--;
      	}
      	start++;
      	while(true){
      		end++;
      		if (end == n){
      			end--;
      			break;
      		}
      		mac[A[end]]++;
      		if (mac[A[end]]==1){
      			len++;
      		}
      		if (len > k){
      			mac[A[end]]--;
      			len--;
      			end--;
      			break;
      		}
      	}
      	if ((end-start+1) > ans){
      		ans = end-start+1;
      		pos = make_pair(start,end);
      	}
      	if (start == n)
      		break;
      }
      cout << pos.first+1 << " " << pos.second+1;
      return 0;
}