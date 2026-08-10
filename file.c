#include <stdio.h>
#include <limits.h>
int main(){
int n,i;
printf("enter the size of array:");
scanf("%d",&n);
int arr[n];
printf("enter the number:\n");
for (i=0;i<n;i++){
scanf("%d",&arr[i]);
}
int largest = INT_MIN;
int secondLargest = INT_MIN;
for (int i = 0; i < n; i++) {
if (arr[i] > largest) {
secondLargest = largest;
largest = arr[i];
}
else if (arr[i] > secondLargest && arr[i] != largest) {
secondLargest = arr[i];
}
}
printf("Second largest number = %d\n", secondLargest);
return 0;
}

