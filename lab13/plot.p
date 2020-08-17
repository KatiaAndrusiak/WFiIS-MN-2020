set term jpeg size 800,600

#set key spacing 2 samplen 3
#set samples 200
set xlabel "Ilosc wezlow" 
set ylabel "|C-Cnum|"
set grid
l_width = 5
p_size = 1.3
set logscale y


set style line 1 lt rgb "red" lw 3 pt 7 ps p_size
set style line 2 lt rgb "blue" lw 3 pt 7 ps p_size
  
    set output "1.eps" 
     plot "dane1.dat" u 1:3 w l ls 2 t "Legendre"
    
    #set yrange [-0.00000001:]
    set output "2.eps" 
     plot "dane2a.dat" u 1:3 w l ls 1 t "Laguerre",\
            "dane2b.dat" u 1:3 w l ls 2 t "Legendre"

    #set yrange [-0.00000001:]
    set output "3.eps" 
     plot "dane3a.dat" u 1:3 w l ls 1 t "Hermite",\
            "dane3b.dat" u 1:3 w l ls 2 t "Legendre"



   
    


 







