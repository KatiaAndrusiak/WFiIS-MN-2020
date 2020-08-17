set terminal post enhanced colour solid font 21

set key spacing 2 samplen 3
set samples 200
set xlabel "Ilosc wezlow" 
set ylabel "Modul roznicy"
set grid
l_width = 5
p_size = 1.3
#set logscale y


set style line 1 lt rgb "red" lw 2 pt 7 ps p_size
set style line 2 lt rgb "blue" lw 5 pt 7 ps p_size
set style line 3 lt rgb "gray30" lw 4 pt 7 ps 0.5

    
    
    set yrange [-0.00001:]
    set output "2a.eps" 
     plot "daneSimpson1.dat" u 1:3 w l ls 2 t "|C-I|"
    
    set yrange [-0.00001:]
    set output "2b.eps" 
     plot "daneSimpson2.dat" u 1:3 w l ls 2 t "|C-I|"

    set yrange [-0.2:]
    set output "2c.eps" 
     plot "daneSimpson3.dat" u 1:3 w l ls 2 t "|C-I|"



    set yrange [-0.5:]
    set output "1a.eps" 
     plot "dane1.dat" u 1:3 w l ls 2 t "|C-I|"

    set yrange [-1:]
    set output "1b.eps" 
     plot "dane2.dat" u 1:3 w l ls 2 t "|C-I|"

    set yrange [-1000000:17000000]
    set output "1c.eps" 
     plot "dane3.dat" u 1:3 w l ls 2 t "|C-I|"







