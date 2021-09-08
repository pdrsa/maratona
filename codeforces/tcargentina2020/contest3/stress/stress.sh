#!/bin/bash

make d d2 gen || exit 1
for ((i = 1; ; i++)) do
	./gen $i > in
	./d < in > out
	./d2 < in > out2
	if (! cmp -s out out2) then
		echo "Input:"
		cat in
		echo "Code Output:"
		cat out
		echo "True Output:"
		cat out2
		break;
	fi
	echo $i
done

