.name "tes545454545454545454545454545454545454545454545554t"
.comment "nope"


#Have enemy skip  

or			%0,		%1,		r16
zjmp		%:endless
st			r2		,		-8	

#Turn start into load my player nb in your r1 

start:

	ld		%1,		r15
	st 		r15,	-4
	st		r1,		-10

#The goal is to achieve r8 forks before life signaling

init_imb:

	ld 		%5,		r8				#sets the number of forks
	add		r3,		r15,		r3	#incrementation of next loop nb
	st		r1,		6

alive:
	live	%42
	or		r8,		%0,			r16
	zjmp	%:alive

end_of_imb:	

	sub		r8,		r3,			r8 #decrementation of forks number
	fork	%:init_imb

loop_init:

	st		r3,		r4
	ld		%1,		r15
	st		r1,		6

#each process has to wait NB process turn to be able to fork

loop:

	live	%42
	sub		r4,		r15,		r4
	zjmp	%:alive
	and		%0,		%0,			r16
	zjmp	%:loop

end_of_champ:

endless:
	and 	%0,		%0,			r16
	zjmp	%:endless

end:
