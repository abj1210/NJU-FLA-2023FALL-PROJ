; (a^i)(b^j) -> c^(i*j)
#Q = {reada,leapa,readb,reset,output,accept,clear,reject,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,rh}
#S = {a,b}
#G = {a,b,c,I,l,e,g,l,n,p,u,t,_}
#q0 = reada
#B = _
#F = {accept}
#N = 2

reada a_ __ r* leapa
reada b_ b_ *l output
reada __ __ ** accept

leapa a_ a_ r* leapa
leapa b_ b_ ** readb
leapa __ __ ** readb

readb b_ bc rr readb
readb a_ a_ *l clear
readb __ __ l* reset

reset *_ *_ l* reset
reset __ __ r* reada

output bc c_ rl output
output b_ __ r* output
output __ __ ** accept
output _c c_ rl output
output a* a* ** clear
output a_ a_ *r clear

clear ** ** ll clear
clear *_ *_ l* clear
clear _* _* *l clear
clear __ __ rr reject


reject ** __ rr reject
reject *_ __ r* reject
reject _* __ *r reject
reject __ __ ** r1

r1 __ I_ r* r2
r2 __ l_ r* r3
r3 __ l_ r* r4
r4 __ e_ r* r5
r5 __ g_ r* r6
r6 __ a_ r* r7
r7 __ l_ r* r8
r8 __ __ r* r9
r9 __ I_ r* r10
r10 __ n_ r* r11
r11 __ p_ r* r12
r12 __ u_ r* r13
r13 __ t_ r* rh
