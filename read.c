#include "functions.h"
#include <stdio.h>

void readIPs(unsigned char arr[][4], int size) {
	int i = 0;
	// read in IPs while scanf is getting 4 unsigned chars
	while(scanf("%hhu.%hhu.%hhu.%hhu\n", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]) == 4) {
		if(i++ > size-1) // if i is greater than the size,
			break;   // break out of the while
	}
	// that's all folks
}
