/*Q111: Write a program to take an integer array arr and an integer k as inputs. The task is to find the first negative integer in each subarray of size k moving from left to right. If no negative exists in a window, print "0" for that window. Print the results separated by spaces as output.

/*
Sample Test Cases:
Input 1:
arr[] = [-8, 2, 3, -6, 10], k = 2
Output 1:
-8 0 -6 -6

Input 2:
arr[] = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
Output 2:
-1 -1 -7 -15 -15 0

Input 3:
arr[] = [12, 1, 3, 5], k = 3
Output 3:
0 0

*/

#include <stdio.h>

void firstNegativeInWindow(int arr[], int n, int k) {
    int start = 0, end = 0;
    int negatives[k];  // To store indices of negative numbers in current window
    int negCount = 0;

    for (end = 0; end < n; end++) {
        // If current element is negative, store its index
        if (arr[end] < 0) {
            negatives[negCount++] = end;
        }

        // When window size hits k
        if (end - start + 1 == k) {
            // If there is a negative number in the current window
            if (negCount > 0 && negatives[0] >= start) {
                printf("%d ", arr[negatives[0]]);
            } else {
                printf("0 ");
            }
            // Remove indices out of the current window
            if (negatives[0] == start) {
                // Shift the negatives array
                for (int i = 1; i < negCount; i++) {
                    negatives[i - 1] = negatives[i];
                }
                negCount--;
            }
            start++;
        }
    }
    printf("\n");
}

int main() {
    int n, k;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter window size k: ");
    scanf("%d", &k);

    firstNegativeInWindow(arr, n, k);

    return 0;
}
