#!/bin/sh

if [ "$#" -lt 3 ] || [ "$#" -gt 4 ]
then
	printf "\nusage: test.sh [-checker] arg1 arg2 arg3\n"
	printf "       arg1  - start number (random value from .. ).\n"
	printf "       arg2  - finish number ( .. random value to).\n"
	printf "       arg3  - how many times run a test.\n"
	printf "       -checker - compare the resulte of bonus checker to the stardard checker\n\n"

	exit
fi

if [ "$1" = "-checker" ]
then
    check=1
    from=$2
    to=$3
    count=$4
else
	check=0
    from=$1
    to=$2
    count=$3
fi

NC='\033[0m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'

for ((i = 0; i < $count; i++))
do
ARG=`ruby -e "puts ($from..$to).to_a.shuffle.join(' ')"` ; moves=$(./push_swap $ARG | wc -l)
checkerm=$(./push_swap $ARG | ./checker_Mac $ARG)
echo "=============================================="
echo "moves count: ${CYAN}${moves}${NC}"
echo "checker_Mac: ${PURPLE}${checkerm}${NC}"
if [ "$check" -eq 1 ]
then
	checkerb=$(./push_swap $ARG | ./checker $ARG)
	echo "checker:     ${BLUE}${checkerb}${NC}"
fi
echo "=============================================="
done