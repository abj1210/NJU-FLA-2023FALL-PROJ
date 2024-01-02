; accept w=ucu u={a,b}*
#Q = {copy,reset,cmp,accept,accept2,accept3,accept4,ah,clear,reject,reject2,reject3,reject4,reject5,rh}
#S = {a,b,c}
#G = {a,b,c,_,t,u,r,e,f,l,s}
#q0 = copy
#B = _
#F = {ah}
#N = 2

copy a_ _a rr copy
copy b_ _b rr copy
copy c_ __ *l reset
copy __ __ ll clear

reset _* _* *l reset
reset __ __ rr cmp

cmp aa __ rr cmp
cmp bb __ rr cmp
cmp *_ *_ *l clear
cmp _* _* l* clear
cmp ab ab ** clear
cmp ba ba ** clear
cmp c* c* ** clear
cmp *c *c ** clear
cmp __ __ ** accept

accept __ t_ r* accept2
accept2 __ r_ r* accept3
accept3 __ u_ r* accept4
accept4 __ e_ r* ah

clear ** ** ll clear
clear *_ *_ l* clear
clear _* _* *l clear
clear __ __ rr reject

reject ** __ rr reject
reject *_ __ r* reject
reject _* __ *r reject
reject __ f_ r* reject2
reject2 __ a_ r* reject3
reject3 __ l_ r* reject4
reject4 __ s_ r* reject5
reject5 __ e_ r* rh
