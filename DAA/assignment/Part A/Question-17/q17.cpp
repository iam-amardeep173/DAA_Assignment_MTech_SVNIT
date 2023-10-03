#include <bits/stdc++.h>
using namespace std;
 
void printdiff(int arr[], int n)
{
    int left ,right;  
    int temp = arr[5];
   for(int i=0;i<n-1;i++)
    {
          for(int j=i+1;j<n;j++)
        {
            if(abs(arr[j]-arr[i])<temp)
            {
                  left=i;
                  right=j;
                  temp=abs(arr[j]-arr[i]);
            }
        }
    }
 
    cout <<" The closest pair is " << arr[left] << " and " << arr[right];
}
int main()
{
    int arr[] =  {10, 22, 28, 29, 29, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    printdiff(arr, n);
    return 0;
}