set t push
set t postscript eps enhanced solid "Helvetica" 20
set style data point
set o "./evol/$0.eps"
set xlabel "q"
set ylabel "p"
set grid
plot [-3.15:3.15][] "$1" pt 7 ps 0.2 lc rgb "black" notitle "Kinetic"
set o
set t pop
