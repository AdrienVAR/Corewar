.name "test"
.comment "nope"


alive: 
live %42
zjmp %:end
and %0, %0, r16
fork %:alive
wat: live %42
fork %:wat
end:
