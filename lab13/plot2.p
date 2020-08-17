set term jpeg size 800,600
p_size = 1.3
set style line 1 lt rgb "blue" lw 3 pt 7 ps p_size
set grid
set xlabel "x" 
set ylabel "f(x)"


    set output "f1.eps" 
     plot "fun1.dat" u 1:2 w l ls 1 t "ln(x)·1"

    set output "f2.eps" 
     plot "fun2.dat" u 1:2 w l ls 1 t "(x − 10)^2sin(4x)·e^−^x"

    set output "f3.eps" 
     plot "fun3.dat" u 1:2 w l ls 1 t "x^72^(^-^x^^2^+^x^+^4^)·e^−^x^^2"
