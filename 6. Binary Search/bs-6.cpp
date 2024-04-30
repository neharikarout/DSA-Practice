#include<bits/stdc++.h>
using namespace std;

//  Kth Missing Positive Number
int missingK(vector < int > arr, int n, int k) {
    int low = 0 ; int high= n-1;
    while(low<=high)
    {
        int mid=(low + high) / 2;
        int  missing = arr[mid] - (mid+1);
        if(missing < k){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return k+high+1 ;
}

//aggressive cows
#include<bits/stdc++.h>
bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}


int main()
{
    return 0;
}