/*Q118: Write a program to take an input array of size n. The array should contain all the integers between 0 to n except for one. Print that missing number

/*
Sample Test Cases:
Input 1:
nums1 = [0,3,2,4]
Output 1:
1

Input 2:
nums1 = [1,2,3]
Output 2:
0

Input 3:
nums1 = [0,4,3,1,5]
Output 3:
2

*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n-1];
    int sum = 0;

    for(int i = 0; i < n-1; i++) {
        scanf("%d", &nums[i]);
        sum += nums[i];
    }
    
    // Sum of first n numbers from 0 to n
    int totalSum = n * (n + 1) / 2;
    
    // Missing number is difference
    int missing = totalSum - sum;
    
    printf("%d\n", missing);
    
    return 0;
}
