; a+b -> c
#Q = {copy,reset,add,adc,accept}
#S = {0,1,2,3,4,5,6,7,8,9,+}
#G = {0,1,2,3,4,5,6,7,8,9,x,+,_}
#q0 = copy
#B = _
#F = {accept}
#N = 2

copy 0_ _0 rr copy
copy 1_ _1 rr copy
copy 2_ _2 rr copy
copy 3_ _3 rr copy
copy 4_ _4 rr copy
copy 5_ _5 rr copy
copy 6_ _6 rr copy
copy 7_ _7 rr copy
copy 8_ _8 rr copy
copy 9_ _9 rr copy
copy +_ __ rl reset

reset ** ** r* reset
reset _* _* l* add

add *_ *0 ** add
add _* 0* ** add
add __ __ ** accept

add 00 0_ ll add
add 01 1_ ll add
add 02 2_ ll add
add 03 3_ ll add
add 04 4_ ll add
add 05 5_ ll add
add 06 6_ ll add
add 07 7_ ll add
add 08 8_ ll add
add 09 9_ ll add
add 0x 0_ ll adc

add 10 1_ ll add
add 11 2_ ll add
add 12 3_ ll add
add 13 4_ ll add
add 14 5_ ll add
add 15 6_ ll add
add 16 7_ ll add
add 17 8_ ll add
add 18 9_ ll add
add 19 0_ ll adc
add 1x 1_ ll adc

add 20 2_ ll add
add 21 3_ ll add
add 22 4_ ll add
add 23 5_ ll add
add 24 6_ ll add
add 25 7_ ll add
add 26 8_ ll add
add 27 9_ ll add
add 28 0_ ll adc
add 29 1_ ll adc
add 2x 2_ ll adc

add 30 3_ ll add
add 31 4_ ll add
add 32 5_ ll add
add 33 6_ ll add
add 34 7_ ll add
add 35 8_ ll add
add 36 9_ ll add
add 37 0_ ll adc
add 38 1_ ll adc
add 39 2_ ll adc
add 3x 3_ ll adc

add 40 4_ ll add
add 41 5_ ll add
add 42 6_ ll add
add 43 7_ ll add
add 44 8_ ll add
add 45 9_ ll add
add 46 0_ ll adc
add 47 1_ ll adc
add 48 2_ ll adc
add 49 3_ ll adc
add 4x 4_ ll adc

add 50 5_ ll add
add 51 6_ ll add
add 52 7_ ll add
add 53 8_ ll add
add 54 9_ ll add
add 55 0_ ll adc
add 56 1_ ll adc
add 57 2_ ll adc
add 58 3_ ll adc
add 59 4_ ll adc
add 5x 5_ ll adc

add 60 6_ ll add
add 61 7_ ll add
add 62 8_ ll add
add 63 9_ ll add
add 64 0_ ll adc
add 65 1_ ll adc
add 66 2_ ll adc
add 67 3_ ll adc
add 68 4_ ll adc
add 69 5_ ll adc
add 6x 6_ ll adc

add 70 7_ ll add
add 71 8_ ll add
add 72 9_ ll add
add 73 0_ ll adc
add 74 1_ ll adc
add 75 2_ ll adc
add 76 3_ ll adc
add 77 4_ ll adc
add 78 5_ ll adc
add 79 6_ ll adc
add 7x 7_ ll adc

add 80 8_ ll add
add 81 9_ ll add
add 82 0_ ll adc
add 83 1_ ll adc
add 84 2_ ll adc
add 85 3_ ll adc
add 86 4_ ll adc
add 87 5_ ll adc
add 88 6_ ll adc
add 89 7_ ll adc
add 8x 8_ ll adc

add 90 9_ ll add
add 91 0_ ll adc
add 92 1_ ll adc
add 93 2_ ll adc
add 94 3_ ll adc
add 95 4_ ll adc
add 96 5_ ll adc
add 97 6_ ll adc
add 98 7_ ll adc
add 99 8_ ll adc
add 9x 9_ ll adc

adc *0 *1 ** add
adc *1 *2 ** add
adc *2 *3 ** add
adc *3 *4 ** add
adc *4 *5 ** add
adc *5 *6 ** add
adc *6 *7 ** add
adc *7 *8 ** add
adc *8 *9 ** add
adc *9 *x ** add
adc _* 0* ** adc
adc *_ *1 ** add
adc __ 01 ** add
