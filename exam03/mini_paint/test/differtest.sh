gcc -Wall -Wextra -Werror ../mini_paint.c -o mini
gcc -Wall -Wextra -Werror our_mini_paint.c -o reference
echo ""
echo "TEST - <ex1>"
echo ""
./mini ex1 > test_res
./reference ex1 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <ex2>"
echo ""
./mini ex2 > test_res
./reference ex2 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <ex3>"
echo ""
./mini ex3 > test_res
./reference ex3 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <NULL>"
echo ""
./mini > test_res
./reference > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <Error name file>"
echo ""
./mini ex > test_res
./reference ex > ref_res
diff test_res ref_res
rm mini
rm reference
rm ref_res
rm test_res