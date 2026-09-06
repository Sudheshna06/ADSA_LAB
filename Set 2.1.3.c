#include<stdio.h>
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minidx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minidx]){
                minidx=j;
            }
        }
        int temp=arr[minidx];
        arr[minidx]=arr[i];
        arr[i]=temp;
    }
}
int main(){
    int arr[]={2,4,3,5,7,6,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,n);
    printf("After Sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
} 