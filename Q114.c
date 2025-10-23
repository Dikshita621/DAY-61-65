/*Q114: Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.

/*
Sample Test Cases:
Input 1:
s = "abcabcbb"
Output 1:
3

Input 2:
s = "bbbbb"
Output 2:
1

Input 3:
s = "pwwkew"
Output 3:
3

*/

#include <stdio.h>
#include <string.h>

int longestUniqueSubstringLength(char s[]) {
    int lastIndex[256];  
    for (int i = 0; i < 256; i++)
        lastIndex[i] = -1;

    int maxLen = 0, start = 0;
    
    for (int end = 0; s[end] != '\0'; end++) {
        if (lastIndex[(unsigned char)s[end]] >= start)
            start = lastIndex[(unsigned char)s[end]] + 1;
        
        lastIndex[(unsigned char)s[end]] = end;
        int currLen = end - start + 1;
        if (currLen > maxLen)
            maxLen = currLen;
    }
    
    return maxLen;
}

int main() {
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);
    
    printf("Length of longest substring without repeating characters: %d\n", longestUniqueSubstringLength(s));
    return 0;
}
