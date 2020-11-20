#!/bin/bash

for num in 17 2000 5000 8000
do
	echo Running with $num ips...
	./pgm1 $num < inp$num.txt
	echo " "
done

echo "Finished"
