.name "Just a test"
.comment "I probably can count to ten wait..."

#T
ld %84, r7
#E
ld %69, r6
#S
ld %83, r5
#SPACE
ld %32, r4
#9
ld %57, r3
#0
ld %48, r10 
#running nb
ld %1, r12
reset:
	st r10, r11
	and %0, %0, r16
	st r1, 6
start:
	live %42
	add r11, r12, r11
	aff r7
	aff r6
	aff r5
	aff r7
	aff r4
	aff r11
	sub r11, r3, r16
	aff r4
	zjmp %:reset
	and %0, %0, r16
	zjmp %:start
