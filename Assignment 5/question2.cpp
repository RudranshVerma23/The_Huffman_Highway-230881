#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> fileSize = {4,3,2,6}; //or take input
    int minCost = 0;
    priority_queue<int,vector<int>,greater<int> > heap (fileSize.begin(),fileSize.end());
    while(heap.size() > 1){
        int first = heap.top(); heap.pop();
        int second = heap.top(); heap.pop();
        int temp = first+second;
        minCost += temp;
        heap.push(temp);
    }
    cout << "Minimum Cost = " << minCost;
}