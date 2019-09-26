.name "I don't fancy seeing other people"
.comment "It's true that i might be a champion but i am at least a sophisticated eraser"


#registre
# r1 player nb
# r3 process nb
# r8 number of forks
# r15 1
# r4 loop value
# r10 explorator code
# r11 explorator process step
# r12 explorator limit
# r13explorator limit


#Turn start into load my player nb in your r1 

start:

	ld		%1,		r15
	st 		r15,	-4
	st		r1,		-10


#Have enemy skip  

ld			%51,			r12
ld			%28,			r13
or			%0,		%1,		r16
zjmp		%:explorator_adverse
st			r2,		-8
st			r9,		6
live		%42
crushed:	st			r1,			r9
st			r15, 	:crushed
fork		%:explorator


#The goal is to achieve r8 forks before life signaling

init_imb:

	ld 		%4,		r8				#sets the number of forks
	add		r3,		r15,		r3	#incrementation of next loop nb
	st		r9,		6

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
	st		r9,		6

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

#explorator

explorator:
	
	sti		r9,		%:buffer_copy,		%1
	sti		r9,		%:l3,				%1
	sti		r9,		%:l2,				%1
	sti		r9,		%:l1,				%1

explorator_adverse:
	and		%0,		%0,					r16
	zjmp	%:first_process

buffer_copy:
	
			live	%42
			sti     r10,   r12,		r11
replaced:	zjmp    %45
			l1:	live	%42
			l2: live	%42
			l3:	live	%42

	first_process:
		st		r9,		6
		live	%42
		fork %:second_process	
		st		r9,		6
		live	%42
		fork %:third_process
		st		r9,		6
		live	%42
		fork %:fifth_process	
		st		r9,		6
		live	%42
		ld		%0,		r11
		and		%0,		%0,		r16
		zjmp	%:exit


	second_process:
		st		r9,		6
		live	%42
		fork %:forth_process		
		st		r9,		6
		live	%42
		fork %:sixth_process	
		st		r9,		6
		live	%42
		ld		%4,		r11
		and		%0,		%0,		r16
		zjmp	%:exit

	third_process:
		st		r9,		6
		live	%42
		fork %:seventh_process		
		st		r9,		6
		live	%42
		ld		%8,		r11
		and		%0,		%0,		r16
		zjmp	%:exit

	forth_process:
		st		r9,		6
		live	%42
		fork 	%:eigth_process		
		st		r9,		6
		live	%42
		ld		%12,	r11
		and		%0,		%0,		r16
		zjmp	%:exit

	fifth_process:
		st		r9,		6
		live	%42
		ld		%16,		r11
		and		%0,		%0,		r16
		zjmp	%:exit

	sixth_process:
		st		r9,		6
		live	%42
		ld		%20,	r11
		and		%0,		%0,		r16
		zjmp	%:exit
	
	seventh_process:
		st		r9,		6
		live	%42
		ld		%24,	r11
		and		%0,		%0,		r16
		zjmp	%:exit

	eigth_process:
		st		r9,		6
		live	%42
		sub		r12,		r13, 	r12
		sub		r12, 	r12, r16
		zjmp	%:explorator

exit:
	ldi		%:buffer_copy,		r11,	r10
	sti		r10,				%:end,	r11
end:

