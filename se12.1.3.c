#include<stdio.h>
void selectionsort(int arr[],int n){
for(int i=0;i<n-1;i++){
int minindex=i;
for(int j=i+1; j<n; j++){
    if(arr[j]<arr[minindex]){
    minindex=j;
}
}

int temp=arr[i];
arr[i]=arr[minindex];
arr[minindex]=temp;
}
}
int main(){
int arr[]={4,5,3,2,1,7,8};
int n=sizeof(arr)/sizeof(arr[0]);
selectionsort(arr,n);
printf("sorted array:");
for(int i=0;i<n;i++){
printf("%d ",arr[i]);
}

return 0;
}


