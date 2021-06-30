/*
----------------------------------------------
Author: Jerin Ignatious
Problem: Quicksort
Date: 06/30/2021
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

//Function to swap two numbers on the array

void swap(ll first, ll second){
    if(a[first] != a[second]){
        a[first] = a[first] + a[second];
        a[second] = a[first] - a[second];
        a[first] = a[first] - a[second];
    }
}

//Function to set the pivot element to its original location
//and create a partition in the array

ll partition(ll l, ll h){
    ll pivot = a[l];
    ll i = l;
    ll j = h;
    while(i < j){
        while(a[i] <= pivot and i < h) i++;
        while(a[j] > pivot) j--;
        if(i < j){
            swap(i, j);
        }
    }
    swap(l, j);
    return j;
}

//quicksort driver function

void quicksort(ll l, ll h){
    if(l < h){
        ll p_point = partition(l, h);
        quicksort(l, p_point-1);
        quicksort(p_point+1, h);
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
    quicksort(0,t-1);
    for(ll i = 0; i < t; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
