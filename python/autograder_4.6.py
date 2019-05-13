def comp( h , r ) :
	return ( h * r)

h = float ( input ( " Enter hours : "))

r = float( input ( " Enter rate per hour : "))

print (" amount to be paid is ",  comp( ( h%40),( 1.5 * r)) + comp( ( h - ( h%40) ), r) )	
	
