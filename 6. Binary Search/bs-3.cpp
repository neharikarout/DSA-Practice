#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr , int n , int k)
{
    int l = 0 , h = n-1;
    int ans = n;
    while(l<=h)
    {
        int mid = l + (h-l)/2;
        if(arr[mid] >= k)
        {
            ans = mid;
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int> &arr , int n , int k)
{
    int l = 0 , h = n-1;
    int ans = n;
    while(l<=h)
    {
        int mid = l + (h-l)/2;
        if(arr[mid] > k)
        {
            ans = mid;
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;    
}



pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int lb = lowerBound(arr,n,k);
    int ub = upperBound(arr,n,k);

    // edge case
    if(lb == n || arr[lb] != k) return {-1,-1};

    return{lb,ub-1};
}


// using binary search
int firstOccurence(vector<int> &arr , int n , int k)
{
    int l = 0 , h = n-1;
    int first = -1;

    while(l <= h)
    {
        int mid = (l + h)/2;
        if(arr[mid] == k)
        {
            first = mid;
            h = mid -1;
        }
        else if(arr[mid] < k)
        {
            l = mid +1;
        }
        else {
            h = mid -1;
        }
    }
    return first;
}
int lastOccurence(vector<int> &arr , int n , int k)
{
    int l = 0 , h = n-1;
    int last = -1;

    while(l <= h)
    {
        int mid = (l + h)/2;
        if(arr[mid] == k)
        {
            last = mid;
            l = mid + 1;
        }
        else if(arr[mid] < k)
        {
            l = mid +1;
        }
        else {
            h = mid -1;
        }
    }
    return last;
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first = firstOccurence(arr, n, k);
    if(first == -1) return {-1,-1};

    int last = lastOccurence(arr, n, k);

    return {first , last};
}


// search in a sorted array

int search(vector<int>& arr, int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return mid;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}



int main()
{
    return 0;
}