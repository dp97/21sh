#!/bin/bash

if [ -n $1 ]
then
	git add .
	git commit -m $1
	echo "SUCCESS!";
else
	echo "ERROR: please supply a message!";
fi
