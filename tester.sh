#!/bin/bash

make re

for testsize in $(ls tests)
do
	echo "=== Running tests of size $(echo $testsize | tr -d -c 0-9) ==="
	echo
	IFS=$'\n'
	i=0
	total=0
	for test in $(cat tests/$testsize)
	do
		IFS=$' '
		if ./push_swap ${test[@]} | ./checker_linux ${test[@]} | grep -q "OK"
		then
			n=$(./push_swap ${test[@]} | wc -l)
			total=$((total+n))
			i=$((i+1))
			echo "✅ Test passed in $n moves !"
		else
			echo "❌ Test failed..."
		fi
	done
	echo
	echo "Total : $total (average $((total/i)))"
	echo "================================="
done

make fclean
