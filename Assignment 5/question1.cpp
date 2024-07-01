#include<bits/stdc++.h>
using namespace std;

int main(){
    int noOfArrivals; cout << "Input number of arrivals and departures: "; cin >> noOfArrivals;
    int arr[noOfArrivals],dep[noOfArrivals];
    cout<< "Input arrival and departure time of a train in railway station one by one: ";
    for(int i=0; i<noOfArrivals; i++){
        cin >> arr[i] >> dep[i];
    }
    int curr=1,max=1,currMaxArr=0,prevMaxDep=0;
    for(int i = 1; i < noOfArrivals; i++){
        if(arr[i]<dep[prevMaxDep]){
            curr++;
            if(max<curr) max=curr;
        }
        if(arr[i]>=dep[prevMaxDep]){
            curr--;
            prevMaxDep++; i--;
        }
    }
    cout << "Minimum number of platforms required = " << max;
}