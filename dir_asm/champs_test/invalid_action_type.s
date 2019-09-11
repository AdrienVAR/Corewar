.name "Barriere"
.comment "Envoie des torpilles a l'avant et se protege avec des barrieres a l'avant et a l'arriere"

		and	r6, %0, r6
		zjmp %:init

# On bombarde derriere notre programme

arriere:	ld	r5, r5
