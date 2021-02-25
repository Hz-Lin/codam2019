gcc -Wall -Wextra -Werror ../micro_paint.c -o micro
gcc -Wall -Wextra -Werror our_micro_paint.c -o reference
echo ""
echo "TEST - <ex0>"
echo ""
echo "My Answer"
./micro ex0
echo ""
echo "Reference"
./reference ex0
echo ""
echo ""
echo "TEST - <ex1>"
echo ""
echo "My Answer"
./micro ex1
echo ""
echo "Reference"
./reference ex1
echo ""
echo ""
echo "TEST - <ex2>"
echo ""
echo "My Answer"
./micro ex2
echo ""
echo "Reference"
./reference ex2
echo ""
echo ""
echo "TEST - <ex3>"
echo ""
echo "My Answer"
./micro ex3
echo ""
echo "Reference"
./reference ex3
echo ""
echo ""
echo "TEST - <ex4>"
echo ""
echo "My Answer"
./micro ex4
echo ""
echo "Reference"
./reference ex4
echo ""
echo ""
echo "TEST - <ex5>"
echo ""
echo "My Answer"
./micro ex5
echo ""
echo "Reference"
./reference ex5
echo ""
echo ""
echo "TEST - <ex6>"
echo ""
echo "My Answer"
./micro ex6
echo ""
echo "Reference"
./reference ex6
echo ""
echo ""
echo "TEST - <ex7>"
echo ""
echo "My Answer"
./micro ex7
echo ""
echo "Reference"
./reference ex7
echo ""
echo ""
echo "TEST - <ex8>"
echo ""
echo "My Answer"
./micro ex8
echo ""
echo "Reference"
./reference ex8
echo ""
echo ""
echo "TEST - <ex9>"
echo ""
echo "My Answer"
./micro ex9
echo ""
echo "Reference"
./reference ex9
echo ""
echo ""
echo "TEST - <ex10>"
echo ""
echo "My Answer"
./micro ex10
echo ""
echo "Reference"
./reference ex10
echo ""
echo ""
echo "TEST - <error No background >"
echo ""
echo "My Answer"
echo ""
./micro ex_e1
echo ""
echo "Reference"
./reference ex_e1
echo ""
echo ""
echo "TEST - <error Missing parameter in draw rectangle>"
echo ""
echo "My Answer"
./micro ex_e2
echo ""
echo "Reference"
./reference ex_e2
echo ""
echo ""
echo "TEST - <NULL>"
echo ""
echo "My Answer"
./micro
echo ""
echo "Reference"
./reference
echo ""
echo ""
echo "TEST - <Error name file>"
echo ""
echo "My Answer"
./micro ex
echo ""
echo "Reference"
./reference ex
rm micro
rm reference