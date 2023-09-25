10 REM Test for the forth main development iteration (version 0.0.4 - 0.0.6)
20 PRINT "Test Series 4"
40 REM DIM X#(4)
100 PRINT "Testing PRINT with square brackets: A$ = TEST, A$[1] = E, Concatenated = TESTE"
110 A$ = "TEST"
120 PRINT "Result: Should be TESTE: ", A$, A$[1]
130 PRINT "Second Result: Should be TESTES: ", A$, A$[1 , 2]
140 B$(1,1) = "Array Test"
150 A$(1,1,1) = "3 dimensions"
160 A$(1,1,1,1) = " or 4?"
170 PRINT "This is the ", B$(1,1), " in ", A$(1,1,1);
180 PRINT A$(1,1,1,1)
200 D% = 1
210 C$(1) = "One"
220 C$(2) = "Two"
230 C$(3) = "Three"
250 FOR D% = 1 TO 3 STEP 1
260 PRINT D%, ": ", C$(D%)
270 NEXT
300 PRINT "Testing REAL array with loop: Adding 3 fields"
310 A# = 0
320 A#(1) = 4
330 A#(2) = 5
340 A#(3) = 6
350 FOR D% = 1 TO 3 STEP 1
360 PRINT "In field ", D%, ": ", A#(D%)
370 A# = A# + A#(D%)
380 NEXT
390 PRINT "Sum of above (should be 15): ", A#
400 PRINT "Testing REAL array with loop: Adding 3 fields - multi-dimensional field"
410 A# = 0
420 A#(1,1) = 4
430 A#(2,1) = 5
440 A#(3,1) = 6
450 FOR D% = 1 TO 3 STEP 1
460 PRINT "In field ", D%, ": ", A#(D%,1)
470 A# = A# + A#(D%,1)
480 NEXT
490 PRINT "Sum of above (should be 15): ", A#
999 END
