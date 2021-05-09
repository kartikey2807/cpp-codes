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
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld n;
      	cin >> n;
      	if (n == 1 || n == 2 || n == 4)
      		{cout<<"-1\n"; continue;}
      	lld c5 = n/5;
      	lld rem = n%5;
      	switch(rem){
      		case 0 : cout << "0 " << c5 << " 0\n"; break;
      		case 1 : cout << "2 " << c5-1<<" 0\n"; break;
      		case 2 : cout << "0 " << c5-1<<" 1\n"; break;
      		case 3 : cout << "1 " << c5 << " 0\n"; break;
      		case 4 : cout << "3 " << c5-1<<" 0\n"; break;
      	}
      }
      return 0;
}