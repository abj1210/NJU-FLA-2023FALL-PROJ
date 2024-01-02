#Q = {printh,printe,printl1,printl2,printo1,print_,printw,printo2,printr,printl3,printd,print,accept}
#S = {0}
#G = {H,e,l,o,_,w,r,d,!}
#q0 = printh
#B = _
#F = {accept}
#N = 1

printh _ H r printe
printe _ e r printl1
printl1 _ l r printl2
printl2 _ l r printo1
printo1 _ o r print_
print_ _ _ r printw
printw _ w r printo2
printo2 _ o r printr
printr _ r r printl3
printl3 _ l r printd
printd _ d r print
print _ ! r accept
