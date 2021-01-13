#include <iostream>
#include<algorithms>
using namespace std;

void merge(int *array,int low,int mid,int high )
{
	int temp[high];
	int i = low;
	int j = mid +1 ;
	int k = low ;

	while( (i <= mid) && (j <=high) )
	{
		if(array[i] <= array[j])
		temp[k++] = array[i++] ;
		else
			temp[k++] = array[j++] ;
	}/*End of while*/
	
	while( i <= mid )
		temp[k++]=array[i++];
	
	while( j <= high )
		temp[k++]=array[j++];

	for(i= low; i <= high ; i++)
		array[i]=temp[i];
	
}
void mergeSort(int a[], int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
    {
        return;
    }
    int mid = (startIndex + endIndex) / 2;
    mergeSort(a, startIndex, mid);
    mergeSort(a, mid + 1, endIndex);
    merge(a,startIndex,mid,endIndex);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a,0,n-1);
     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
