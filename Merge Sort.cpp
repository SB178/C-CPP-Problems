#include <bits/stdc++.h>
using namespace std;

void merge(int array[], int begin,int mid, int end)
{
	int l1 = mid-begin+1;
	int l2 = end-mid;
	int left[l1],right[l2];
	for(int i=0;i<l1;i++)
		left[i]=array[i+begin];

	for(int j=0;j<l2;j++)
		right[j]=array[j+mid+1];
		
	int i=0,j=0,k=begin;
	while(i < l1 && j < l2 )
	{
		if(left[i]<right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
		
	}
	while(i<l1)
	{
		array[k++] = left[i++];
	}
	while(j<l2)
	{
		array[k++] = right[j++];
	}

}

void mergesort(int array[], int begin, int end)
{
	if(begin>=end)
		return; 
	int mid = (begin + end) / 2;
	mergesort(array,begin,mid);
	mergesort(array,mid+1,end);
	merge(array,begin,mid,end);
}




int main()
{
	int arr[] = { -2, 3, -1, -4, -2, 56, 69, 96, 1};
	mergesort(arr,0,9);

	for(int i=0;i<9;i++)
	{
		cout<<arr[i]<<" ";
	}
}