set term jpeg

set out 'log.jpg'

set logscale y 10

plot	'f_zl.dat' u 1:5 w l t 'Zloty podzial',\
		'f_3.dat' u 1:5 w l t 'Podzial na 3',\

set out 'x6.jpg'

plot	'g_zl.dat' u 1:5 w l t 'Zloty podzial',\
		'g_3.dat' u 1:5 w l t 'Podzial na 3',\
