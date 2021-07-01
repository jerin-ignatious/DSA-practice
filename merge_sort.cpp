/*
----------------------------------------------
Author: Jerin Ignatious
Problem: Merge sort
Date: 7/1/2021
----------------------------------------------
*/
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define nl "\n"
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define vull vector<ull>
#define sll set<ll>
#define sull set<ull>
#define pll pair<ll,ll>
#define NIL -1  
using namespace std;
ll a[1000];
ll b[1000];

//function to merge the two sorted arrays

void merge(ll l, ll mid, ll r){
    ll i = l;
    ll j = mid+1;
    ll k = l;
    while(i <= mid and j <= r){
        if(a[i] < a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        while(j <= r)
            b[k++] = a[j++];
    }
    else{
        while(i <= mid)
            b[k++] = a[i++];
    }
    for(ll i = l; i <= r; i++){
        a[i] = b[i];
    }
}

//driver function to break the array from mid and merge then merge the two

void mergesort(ll l, ll r){
    if(l < r){
        ll mid = (l + r) / 2;
        mergesort(l, mid);
        mergesort(mid+1, r);
        merge(l, mid, r);
    }
}

//main function

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    for(ll i = 0; i < t; i++){
        cin>>a[i];
    }
    mergesort(0,t-1);
    for(ll i = 0; i < t; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
