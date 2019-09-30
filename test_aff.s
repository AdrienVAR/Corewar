.name "Test AFF"
.comment "Show me"

#T
ld %84, r7
#E
ld %69, r6
#S
ld %83, r5
#SPACE
ld %32, r4
and %0, %0, r16
st r1, 6
start:
	live %42
	aff r7
	aff r6
	aff r5
	aff r7
	aff r4
	zjmp %:start
