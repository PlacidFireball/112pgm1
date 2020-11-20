#ifndef FUNCTION_H
#define FUNCTION_H

// sorts the array of IPs using Bubble Sort
void sort(unsigned char arr[][4], int n);
// Reads in the data
void readIPs(unsigned char arr[][4], int size);
// analyze.c does have helper functions that aren't used outside of analyze.c,
// I didn´t include them here.
void analyze(unsigned char arr[][4], int size, char _class, unsigned char largest_ip[4], int* largest_count, int* unique_ips);
// Displays analyze's data
void display(unsigned char largest_ip[4], int largest_count, int unique_ips, char _class);

#endif
