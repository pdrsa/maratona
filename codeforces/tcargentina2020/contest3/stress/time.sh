#!/bin/bash

make d d2 gen || exit 1
for ((i = 1; ; i++)) do
	./gen $i > in
	time ./d < in
done

