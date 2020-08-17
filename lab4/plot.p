set term jpeg
set xlabel 'alfa'
set ylabel 'ω'
set yrange [0:0.25]

set out 'pierw.jpg'

plot 	'wyniki1.dat' u 1:2 w l t 'ω 1',\
		'wyniki1.dat' u 1:3 w l t 'ω 2',\
		'wyniki1.dat' u 1:4 w l t 'ω 3',\
		'wyniki1.dat' u 1:5 w l t 'ω 4',\
		'wyniki1.dat' u 1:6 w l t 'ω 5',\
		'wyniki1.dat' u 1:7 w l t 'ω 6',\
