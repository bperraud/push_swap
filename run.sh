#!/bin/bash
if [ $# -eq 0 ]
then
	echo "No arguments supplied"
else
	git add src include Makefile
	git commit -m $1
	git push	
fi
