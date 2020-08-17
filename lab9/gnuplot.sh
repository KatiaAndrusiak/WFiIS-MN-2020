set terminal post enhanced colour solid font 21 
set encoding iso_8859_2

set key spacing 2 samplen 3 center bottom
set xlabel "x" 
set ylabel "f(x)"
set grid
set xrange [-8:8]
set yrange [-2:2]


x_min = -2*3.14
x_max = 2*3.14
g(x) = sin(x)
l_width = 5
p_size = 1.3
set xtics -10,4

set style line 1 lt rgb "gray30" lw 6 pt 7 ps p_size*1.15
set style line 2 lt rgb "red" lw l_width pt 7 ps p_size
set style line 3 lt rgb "royalblue" lw l_width*2.4 pt 7 ps p_size*1.2


set output "app3.eps"
plot [x_min:x_max] g(x) ls 3 t "sin(x)",\
 "wyn.dat" i 0 w l ls 2 t "Aproksymacja n=m=7"


