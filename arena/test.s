.name "tes545454545454545454545454545454545454545454545554t"
.comment "nope"


zjmp %:end
ld %1, r15
st r15, -4
st r1, -10
ld %1, r3
alive:
	st r1, 6
	live %42
	add r3, r15 ,r3
	fork %:alive
	sub r3, r15  ,r3
loop_init:
	st r3, r4
	ld %1, r15
	st r1, 6
loop:
	live %42
	sub r4, r15, r4
	zjmp %:alive
	and %0, %0, r12
	zjmp %:loop
end:
