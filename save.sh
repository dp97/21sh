#!/bin/bash

if [ ! -z "$1" ]
then
	git add .
	git commit -m "$1"
	if [ $2 = "y" ]
	then
		git push
	fi
	echo "SUCCESS!";
else
	echo "Usage:\n\tsave.sh 'message' [y]\n\ty - for pushing.";
fi
