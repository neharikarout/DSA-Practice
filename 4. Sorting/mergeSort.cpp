#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

     //remaining left elements
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //remaining right elements
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    //copying temp in original
    for(int i=low;i<=high;i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr,int low,int high)
{
    if(low >= high) return;
    int mid = (low+high)/2; 
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}



int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    int element;
    for(int i= 0;i<n;i++)
    {
        cin>>element;
        arr.push_back(element);
    }

mergeSort(arr,0,n-1);

for(int i = 0;i<n;i++){
    cout<<arr[i]<<" ";
}

return 0;
}
