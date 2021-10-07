#!/bin/sh

if [ "$#" -ne 2 ]
then
	printf "\nusage: test_visualizer.sh arg1 arg2\n"
	printf "       arg1  - start number (random value from .. ).\n"
	printf "       arg2  - finish number ( .. random value to).\n"

	exit
fi

from=$1
to=$2

python3 pyviz.py `ruby -e "puts ($from..$to).to_a.shuffle.join(' ')"`
