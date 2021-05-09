#include <bits/stdc++.h>
#include <set>
#include <limits>
#include <string>
using namespace std;
typedef long long int lld;
#define MAXN std::numeric_limits<lld>::max()
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
double getComb (double n, double x){
    if (x > n){
        return 0;
    }
    else{
        double r = 1.0;
        for(double i = 1.0; i<=x; i += 1){
            double a = n-i+1;
            double b = a / i;
            r*=b;
        }
        return r;
    }
}
void merge(lld crr[], lld brr[], lld arr[], lld l, lld m, lld r){
    lld i , j ,  k;
    lld n1 = m-l+1; 
    lld n2 = r - m;
    lld L1[n1],L2[n1],L3[n1];
    lld R1[n2],R2[n2],R3[n2];
    for (i = 0; i < n1; i++){
        L1[i] = arr[l + i];
        L2[i] = brr[l + i];
        L3[i] = crr[l + i];
    }
    for (j = 0; j < n2; j++){
        R1[j] = arr[m+1+j];
        R2[j] = brr[m+1+j];
        R3[j] = crr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L1[i] <= R1[j]){
            arr[k] = L1[i];
            brr[k] = L2[i];
            crr[k] = L3[i];
            i++;
        }
        else{
            arr[k] = R1[j];
            brr[k] = R2[j];
            crr[k] = R3[j];
            j++;
        }
        k++;
    }
        while (i   <   n1){
            arr[k] = L1[i];
            brr[k] = L2[i];
            crr[k] = L3[i];
            i++;
            k++;
        }
        while (j   <   n2){
            arr[k] = R1[j];
            brr[k] = R2[j];
            crr[k] = R3[j];
            j++;
            k++;
        }
}
void mergeSort(lld crr[], lld brr[], lld arr[], lld l, lld r){
    if (l < r)
    {
        lld m = l+(r-l)/2;
        mergeSort(crr, brr, arr,l , m);
        mergeSort(crr, brr,arr,m+1 ,r);
        merge(crr, brr, arr, l, m , r);
    } 
}
lld f;
set <lld> my;
void xyz (lld A[], string S[], string s, lld sum,lld j,lld n){
    set <char>  c;
    for(lld i = 0; i < s.length();i++){
        c.insert(s[i]);
    }
    if (c.size() == 3){
        my.insert(sum);
        f  = 1;
        return;
    }
    if (j >= n){
        return;
    }
    for(lld i = j+1; i < n; i = i + 1){
        xyz(A,S,s+S[i],sum+A[i], i, n);
    }
}
int main () {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("inputf.in",  "r",  stdin);
    // for writing output to output.txt
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld n, i;
    cin >> n;
    lld A[n];
    lld a[n];
    lld m[7];
    string s[n];
    string S[n];
    for(i = 0; i < n; i += 1){
        cin >>  A[i];
        cin >>  S[i];
    }
    for(i = 0; i < 7; i += 1){
        m[i] =  MAXN;
    }
    for(i = 0; i < n; i += 1){
        if (S[i] == "A"){
        if (A[i] < m[0])
            m[0] = A[i];
        }
        if (S[i] == "B"){
        if (A[i] < m[1])
            m[1] = A[i];
        }
        if (S[i] == "C"){
        if (A[i] < m[2])
            m[2] = A[i];
        }
        if (S[i] == "AB" || S[i] == "BA"){
        if (A[i] < m[3])
            m[3] = A[i];
        }
        if (S[i] == "BC" || S[i] == "CB"){
        if (A[i] < m[4])
            m[4] = A[i];
        }
        if (S[i] == "CA" || S[i] == "AC"){
        if (A[i] < m[5])
            m[5] = A[i];
        }
        if (S[i] == "ABC"||S[i] == "ACB"||
            S[i] == "BAC"||S[i] == "BCA"||
            S[i] == "CAB"||S[i] == "CBA"){
        if (A[i] < m[6])
            m[6] = A[i];
        }
    }
    lld k = 0;
    if (m[0] != MAXN){
        a[k]  = m[0];
        s[k]  = "A" ;
        k++;
    }
    if (m[1] != MAXN){
        a[k]  = m[1];
        s[k]  = "B" ;
        k++;
    }
    if (m[2] != MAXN){
        a[k]  = m[2];
        s[k]  = "C" ;
        k++;
    }
    if (m[3] != MAXN){
        a[k]  = m[3];
        s[k]  = "AB";
        k++;
    }
    if (m[4] != MAXN){
        a[k]  = m[4];
        s[k]  = "BC";
        k++;
    }
    if (m[5] != MAXN){
        a[k]  = m[5];
        s[k]  = "CA";
        k++;
    }
    if (m[6] != MAXN){
        a[k]  = m[6];
        s[k]  ="ABC";
        k++;
    }
    f = 0;
    for(i = 0; i < k; i += 1){
    xyz(a,s,s[i], a[i], i, k);
    }
    set <lld> :: iterator itr;
    if (f == 0){
        cout << "-1" <<  "\n";
    }
    else{
        itr = my.begin();
        cout << *itr <<  "\n";
    }
    return 0;
}