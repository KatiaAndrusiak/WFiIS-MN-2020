set term jpeg
set xlabel 'x'
set ylabel 'u(x)'

set out 'a0.jpg'

plot 	'wyniki2.dat' u 1:2 w l t 'u 1',\
		'wyniki2.dat' u 1:3 w l t 'u 2',\
		'wyniki2.dat' u 1:4 w l t 'u 3',\
		'wyniki2.dat' u 1:5 w l t 'u 4',\
		'wyniki2.dat' u 1:6 w l t 'u 5',\
		'wyniki2.dat' u 1:7 w l t 'u 6',\

set out 'a100.jpg'

plot 	'wyniki3.dat' u 1:2 w l t 'u 1',\
		'wyniki3.dat' u 1:3 w l t 'u 2',\
		'wyniki3.dat' u 1:4 w l t 'u 3',\
		'wyniki3.dat' u 1:5 w l t 'u 4',\
		'wyniki3.dat' u 1:6 w l t 'u 5',\
		'wyniki3.dat' u 1:7 w l t 'u 6',\
		

