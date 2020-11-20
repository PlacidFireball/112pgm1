/*
CSCI 112  Program 1
Code written by Jared Weiss
Finished on October 3, 2020

Source Files:
 - pgm1.c
 - read.c
 - sort.c
 - analyze.c
 - sort.c

Header File:
 - functions.h

Makefile and bash script included in submission.

Resources used:
geeksforgeeks articles
 - BubbleSort
 - memcpy()
*/


#include "functions.h"
#include <stdio.h>

// Debugging method to see if the array is sorted
/*void disp(unsigned char arr[][4], int size) {
	if( size > 20 ) return;
	for(int i = 0; i < size; i++)
		printf("%d. %hhu.%hhu.%hhu.%hhu\n", i, arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
}*/

// Main
int main(int argc, char *argv[]) {
	int size = 0; // size variable
	// If there is an, argument to read, read it in as an int, otherwise report an error
	argc == 2 ? sscanf(argv[1], "%d", &size) : printf("No arguments supplied, aborting\n");
	if(argc != 2) return 1;
	unsigned char ips[size][4]; // initialize the ip array with the size we read in
	readIPs(ips, size); 	    // read in the ips
	sort(ips, size);
	/* disp(ips, size); */
	// array of ip classes
	char class_arr[3] = {'a', 'b', 'c'};
	// analyze variables
	int largest_count = 0, unique_ips = 0;
	unsigned char largest_ip[4];
	for(int i = 0; i < 3; i++) {
		// pass the necessary data to analyze
		analyze(ips, size, class_arr[i], largest_ip, &largest_count, &unique_ips);
		// display the data
		display(largest_ip, largest_count, unique_ips, class_arr[i]);
		// start with a clean slate for the next run
		largest_count = 0;
		unique_ips = 0;
	}
	return 0;
}
