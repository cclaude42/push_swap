#!/bin/bash

b=$(tput setaf 5)$(tput bold)
r=$(tput sgr0)

make re


if [[ "$OSTYPE" == "darwin"* ]]
then
	os=_macos
else
	os=_linux
fi

if [[ $1 == "-mine" ]]
then
	make bonus
	os=""
fi


for testsize in $(ls tests)
do
	echo "=== Running tests of size ${b}$(echo $testsize | tr -d -c 0-9)${r} ==="
	echo
	IFS=$'\n'
	i=0
	total=0
	max=0
	for test in $(cat tests/$testsize)
	do
		IFS=$' '
		if ./push_swap ${test[@]} | checkers/checker$os ${test[@]} | grep -q "OK"
		then
			n=$(./push_swap ${test[@]} | wc -l)
			if ((n > max))
			then
				max=$n
			fi
			total=$((total+n))
			i=$((i+1))
			echo "✅ Test passed in ${b}$n${r} moves !"
			# exec 4>&2
			# t=$( { time -p ./push_swap ${test[@]} 1>/dev/null 2>&4; } 2>&1 | tr '\n' '  ')
			# exec 4>&-
			# echo "   Time : $t"
		else
			echo "❌ Test failed..."
		fi
	done
	echo
	echo "   Average ${b}$((total/i))${r}   (max ${b}$max${r})"
	echo "================================="
done

make fclean
