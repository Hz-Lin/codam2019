gcc -Wall -Werror -Wextra ../mini_paint.c -o mini
gcc -Wall -Werror -Wextra our_mini_paint.c -o reference
./mini ex1 > m1
./mini ex2 > m2
./mini ex3 > m3
cat -e m1 > mm1
cat -e m2 > mm2
cat -e m3 > mm3
./reference ex1 > r1
./reference ex2 > r2
./reference ex3 > r3
cat -e r1 > rr1
cat -e r2 > rr2
cat -e r3 > rr3
diff -y --suppress-common-lines rr1 mm1
diff -y --suppress-common-lines rr2 mm2
diff -y --suppress-common-lines rr3 mm3
rm -rf mini reference m1 m2 m3
rm -rf mm1 mm2 mm3
rm -rf r1 r2 r3
rm -rf rr1 rr2 rr3