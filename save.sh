#!/bin/bash

if [ -n $1 ]
then
	git add .
	git commit -m $1
	if [ $2 = "y" ]
	then
		git push
	fi
	echo "SUCCESS!";
else
	echo "ERROR: please supply a message!";
fi
