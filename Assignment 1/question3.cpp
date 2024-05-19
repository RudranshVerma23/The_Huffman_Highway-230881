#include <bits/stdc++.h>
using namespace std;
#define MAX 2147483647

void question3 (){
    cout << "Problem 3" << endl;
    cout << "Input 10 exam scores seperated by spaces: " << endl;
    int arr[10];
    for(int i = 0; i < 10; i++){
        cin >> arr[i];
    }
    int sum = 0, high = 0, low = MAX;
    for(int i = 0; i < 10; i++){
        sum += arr[i];
        if(high < arr[i]) high = arr[i];
        if(low > arr[i]) low = arr[i];
    }
    float avg = (float) sum/10;
    cout << "Average exam score = " << avg << endl
         << "Highest exam score = " << high << endl
         << "Lowest exam score = " << low << endl;
    int above = 0, below = 0;
    for(int i = 0; i < 10; i++){
        if(arr[i] > avg) above++;
        if(arr[i] < avg) below++;
    }
    cout << "Number of exam scores above the average = " << above << endl
         << "Number of exam scores below the average = " << below << endl;
}

int main(){
    question3();
}