#include<stdio.h>
int main(){
    int arr[]={45,90,23,56,12,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int comp=0;
    int swap=0;
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j;
        for(j=i-1;j>=0 && arr[j]>key;j--){
            arr[j+1]=arr[j];
        }
         arr[j+1]=key;
   }
   printf("Sorted array:");
   for(int k=0;k<size;k++){
    printf("%d\n",arr[k]);
   }
}