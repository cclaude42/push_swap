#!/bin/bash

if [[ "$OSTYPE" == "darwin"* ]]
then
	os=macos
else
	os=linux
fi

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
		if ./push_swap ${test[@]} | ./checker_$os ${test[@]} | grep -q "OK"
		then
			n=$(./push_swap ${test[@]} | wc -l)
			exec 4>&2
			t=$( { time -p ./push_swap ${test[@]} 1>/dev/null 2>&4; } 2>&1 | tr '\n' '  ')
			exec 4>&-
			total=$((total+n))
			i=$((i+1))
			echo "✅ Test passed in $n moves !"
			echo "   Time : $t"
		else
			echo "❌ Test failed..."
		fi
	done
	echo
	echo "Total : $total (average $((total/i)))"
	echo "================================="
done

make fclean
