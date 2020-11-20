#include "functions.h"
#include <string.h>

// Method that checks if two ip's networks are the same
int comp(unsigned char arr1[4], unsigned char arr2[4], char _class) {
	// set size to something different based on what class of IP we are dealing with
	int size = (_class == 'a') ? 1 : (_class == 'b') ? 2 : (_class == 'c') ? 3 : -1;
	for(int i = 0; i < size; i++) {
		if(arr1[i] != arr2[i]) { return 0; } // if the arrays are different at any point return false
	}
	return 1; // otherwise return true
}

// Function to count how many times a value occurs in an array
int count(unsigned char arr[][4], unsigned char val[4], int start, int size, char _class) {
	int total = 0;
	for (int i = start; i < size; i++) {
		// if val and the array at index i are the same, add one to the total
		if(_class == 'a' && comp(arr[i], val, _class)) { total++; }
		else if(_class == 'b' && comp(arr[i], val, _class)) { total++; }
		else if(_class == 'c' && comp(arr[i], val, _class)) { total++; }
	}
	return total; // return the total
}

// Function that determines the largest network within a given range of the array of IPs
int largest(unsigned char arr[][4], unsigned char* _largest, int start, int size, char _class) {
	memcpy(_largest, arr[start], 4); // set a default value for the largest
	int end = start+size;            // calculate our range, had to do this
					 // because of the way the function is writen, too lazy to change it lol
	int new_count = 0;
	int largest_count = count(arr, arr[start], start, end, _class); // calculate largest count
	for (int k = start; k < end; k++) {
		// calculate new count if largest is not equal to the array at index k
		// otherwise set it to 0 (just to save calculation time)
		new_count = !comp(_largest, arr[k], _class) ? count(arr, arr[k], start, end, _class) : 0;
		if(new_count > largest_count) { // if the new count is bigger than the largest count
			memcpy(_largest, arr[k], 4); // change largest
			largest_count = new_count;   // change largest count
		}
	}
	return largest_count; // return the largest count
}

int isUnique(unsigned char val[4], unsigned char arr[][4], int lower, int upper, char _class) {
	for(int i = lower; i < upper; i++) {
		if(comp(val, arr[i], _class)) return 0; // if the value is in the sub-array, return false (not unique)
	}
	return 1; // otherwise return true (it's unique)
}

void analyze(unsigned char arr[][4], int size, char _class, unsigned char largest_ip[4], int* largest_count, int* unique_ips) {
	// Setup
	int i = 0, j = 0, k = 0; // index variables
	int unique = 0;		 // keeping track of how many unique networks there are

	// Figure out what our range of IPs are, ex: if we are looking for class A ips, range is 0 <= x < 128
	unsigned char lower_bound = (_class == 'a') ? 0 : (_class == 'b') ? 128 : 192;
	unsigned char upper_bound = (_class == 'a') ? 128 : (_class == 'b') ? 192 : 224;


	// Determine the lower bound index (where the 'sub-array' starts)
	while(1) {
		if(arr[i][0] >= lower_bound) break;
		i++;
	}
	// Determine the upper bound index (where the 'sub-array' ends)
	while(arr[j][0] < upper_bound) {
		j++;
	}

	// Determine how many unique networks there are
	k = i;
	int len = j - i;
	while(arr[k][0] < upper_bound) {
		// check for arr[k] in the sub array from i to k - 1
		// (because for loop increments up to but not including k)
		// if it's not in the sub array, then increment unique
		if(isUnique(arr[k], arr, i, k, _class)) unique++;
		k++;
	}
	// Set how many unique IPs we found
	*unique_ips = unique;
	// Set the largest count and also change largest_ip to be the largest network
	*largest_count = largest(arr, largest_ip, i, len, _class);
}
