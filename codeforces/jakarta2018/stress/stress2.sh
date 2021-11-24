make a2 gen || exit 1
for ((i = 1; ; i++)) do
	./gen $i > in
	echo $i
	cat in
	./a2 < in > out2
done

