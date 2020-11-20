#include "functions.h"
#include <stdio.h>

void display(unsigned char largest_ip[4], int largest_count, int unique_ips, char _class) {
	// turn _class into a capital letter
	char caps = (_class == 'a') ? 'A' : (_class == 'b') ? 'B' : 'C';
	// Print off the unique IPs in the class
	printf("Class %c has %d networks.\n", caps, unique_ips);
	// If the largest count is one, print it off
	if(largest_count == 1) printf("All %c networks have only 1 host.\n", caps);
	// otherwise print off the necessary case
	else if(largest_count > 1 && _class == 'a') printf("Largest A network is %hhu with %d hosts.\n",
							    largest_ip[0], largest_count);
	else if(largest_count > 1 && _class == 'b') printf("Largest B network is %hhu.%hhu with %d hosts.\n",
							    largest_ip[0], largest_ip[1], largest_count);
	else if(largest_count > 1 && _class == 'c') printf("Largest C network is %hhu.%hhu.%hhu with %d hosts.\n",
							    largest_ip[0], largest_ip[1], largest_ip[2], largest_count);
}
