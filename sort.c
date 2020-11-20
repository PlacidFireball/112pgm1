#include <string.h>

/*
Sorts the array of IPs using Bubble Sort
References used:
Notes from CSCI 132
https://geeksforgeeds.org/bubble-sort/
*/
void sort(unsigned char arr[][4], int n) {
	int i, j;
	unsigned char temp[4];
	for(i = 0; i < n-1; i++) {
		for(j = 0; j < n-i-1; j++) {
			// sorts the array totally, not just by the fist octet
			if((arr[j][0] > arr[j+1][0]) ||
			(arr[j][0] == arr[j+1][0] && arr[j][1] > arr[j+1][1]) ||
			(arr[j][0] == arr[j+1][0] && arr[j][1] == arr[j+1][1] && arr[j][2] > arr[j+1][2]) ||
			(arr[j][0] == arr[j+1][0] && arr[j][1] == arr[j+1][1] && arr[j][2] == arr[j+1][2] && arr[j][3] > arr[j+1][3])) {
				memcpy(temp, arr[j], 4);
				memcpy(arr[j], arr[j+1], 4);
				memcpy(arr[j+1], temp, 4);
			}
		}
	}
}
