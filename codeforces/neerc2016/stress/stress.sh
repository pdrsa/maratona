make c c2 gen || exit 1
for ((i = 10; ; i++)) do
	./gen $i > in
	./c < in > out
	./c2 < in > out2
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

