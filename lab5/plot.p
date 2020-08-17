set term jpeg size 800,600

set xlabel 'm-ilosc iteracji'
set ylabel 'lambda'

set out 'wynik_lin.jpg'

#set linetype 1 lc rgb "red"

set xtics 1
set ytics 2

set yrange [0:28]

plot 'wyniki1.dat' u 2:3 w l t 'przyblizenia wartosci wlasnych'
