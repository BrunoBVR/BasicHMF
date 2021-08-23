set t push
set t postscript eps enhanced solid "Helvetica" 20
set style data point
set o "./figs/$0.eps"
set xlabel "Time"
set ylabel ""
set grid
plot [][] "$1" u 1:2 pt 7 ps 0.3 lc rgb "black" title "MagX", "$1" u 1:3 pt 7 ps 0.3 lc rgb "red" title "MagY", "$1" u 1:4 pt 7 ps 0.3 lc rgb "blue" title "M" # plot command
set o
set t pop
