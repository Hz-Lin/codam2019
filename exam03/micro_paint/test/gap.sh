gcc -Wall -Werror -Wextra ../micro_paint.c -o micro
gcc -Wall -Werror -Wextra our_micro_paint.c -o reference
./micro ex0 > m0
./micro ex1 > m1
./micro ex2 > m2
./micro ex3 > m3
./micro ex4 > m4
./micro ex5 > m5
./micro ex6 > m6
./micro ex7 > m7
./micro ex8 > m8
./micro ex9 > m9
./micro ex10 > m10
cat -e m0 > mm0
cat -e m1 > mm1
cat -e m2 > mm2
cat -e m3 > mm3
cat -e m4 > mm4
cat -e m5 > mm5
cat -e m6 > mm6
cat -e m7 > mm7
cat -e m8 > mm8
cat -e m9 > mm9
cat -e m10 > mm10
./reference ex0 > r0
./reference ex1 > r1
./reference ex2 > r2
./reference ex3 > r3
./reference ex4 > r4
./reference ex5 > r5
./reference ex6 > r6
./reference ex7 > r7
./reference ex8 > r8
./reference ex9 > r9
./reference ex10 > r10
cat -e r0 > rr0
cat -e r1 > rr1
cat -e r2 > rr2
cat -e r3 > rr3
cat -e r4 > rr4
cat -e r5 > rr5
cat -e r6 > rr6
cat -e r7 > rr7
cat -e r8 > rr8
cat -e r9 > rr9
cat -e r10 > rr10
diff -y --suppress-common-lines rr0 mm0
diff -y --suppress-common-lines rr1 mm1
diff -y --suppress-common-lines rr2 mm2
diff -y --suppress-common-lines rr3 mm3
diff -y --suppress-common-lines rr4 mm4
diff -y --suppress-common-lines rr5 mm5
diff -y --suppress-common-lines rr6 mm6
diff -y --suppress-common-lines rr7 mm7
diff -y --suppress-common-lines rr8 mm8
diff -y --suppress-common-lines rr9 mm9
diff -y --suppress-common-lines rr10 mm10
rm -rf m0 m1 m2 m3 m4 m5 m6 m7 m8 m9 m10 micro reference
rm -rf mm0 mm1 mm2 mm3 mm4 mm5 mm6 mm7 mm8 mm9 mm10
rm -rf r0 r1 r2 r3 r4 r5 r6 r7 r8 r9 r10
rm -rf rr0 rr1 rr2 rr3 rr4 rr5 rr6 rr7 rr8 rr9 rr10