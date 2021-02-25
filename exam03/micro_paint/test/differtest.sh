gcc -Wall -Wextra -Werror ../micro_paint.c -o micro
gcc -Wall -Wextra -Werror our_micro_paint.c -o reference
echo ""
echo "TEST - <ex0>"
echo ""
./micro ex0 > test_res
./reference ex0 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <ex1>"
echo ""
./micro ex1 > test_res
./reference ex1 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <ex2>"
echo ""
./micro ex2 > test_res
./reference ex2 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <ex3>"
echo ""
./micro ex3 > test_res
./reference ex3 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <ex4>"
echo ""
./micro ex4 > test_res
./reference ex4 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <ex5>"
echo ""
./micro ex5 > test_res
./reference ex5 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <ex6>"
echo ""
./micro ex6 > test_res
./reference ex6 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <ex7>"
echo ""
./micro ex7 > test_res
./reference ex7 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <ex8>"
echo ""
./micro ex8 > test_res
./reference ex8 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <ex9>"
echo ""
./micro ex9 > test_res
./reference ex9 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <ex10>"
echo ""
./micro ex10 > test_res
./reference ex10 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <error No background >"
echo ""
./micro ex_e1 > test_res
./reference ex_e1 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <error Missing parameter in draw rectangle>"
echo ""
./micro ex_e2 > test_res
./reference ex_e2 > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <NULL>"
echo ""
./micro > test_res
./reference > ref_res
diff test_res ref_res
echo ""
echo ""
echo "TEST - <Error name file>"
echo ""
./micro ex > test_res
./reference ex > ref_res
diff test_res ref_res
rm micro
rm reference
rm ref_res
rm test_res