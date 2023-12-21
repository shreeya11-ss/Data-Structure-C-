#include<stdio.h>
int main(){
    int n;
    printf("enter size:");
    scanf("%d",&n);
    int arr[n];
    printf("insert elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("sorted array is:");
    for(int k=0;k<n;k++){
        printf("%d\n",arr[k]);
    }
}