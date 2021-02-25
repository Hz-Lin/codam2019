gcc -Wall -Wextra -Werror ../mini_paint.c -o mini
gcc -Wall -Wextra -Werror our_mini_paint.c -o reference
echo ""
echo "TEST - <ex_1>"
echo ""
echo "My Answer"
./mini ex1
echo ""
echo "Reference"
./reference ex1
echo ""
echo ""
echo "TEST - <ex_2>"
echo ""
echo "My Answer"
./mini ex2
echo ""
echo "Reference"
./reference ex2
echo ""
echo ""
echo "TEST - <ex_3>"
echo ""
echo "My Answer"
./mini ex3
echo ""
echo "Reference"
./reference ex3
echo ""
echo ""
echo "TEST - <NULL>"
echo ""
echo "My Answer"
./mini
echo ""
echo "Reference"
./reference
echo ""
echo ""
echo "TEST - <Error name file>"
echo ""
echo "My Answer"
./mini ex
echo ""
echo "Reference"
./reference ex
rm mini
rm reference