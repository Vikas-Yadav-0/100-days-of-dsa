#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int absVal(int x){
    return x < 0 ? -x : x;
}

int main(){

    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    // sort array
    qsort(arr,n,sizeof(int),compare);

    int left=0, right=n-1;
    int minSum = INT_MAX;
    int a=0,b=0;

    while(left<right){

        int sum = arr[left] + arr[right];

        if(absVal(sum) < absVal(minSum)){
            minSum = sum;
            a = arr[left];
            b = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d",a,b);

    return 0;
}
