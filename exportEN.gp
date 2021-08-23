set t push							# save the current terminal settings
set t postscript eps enhanced solid "Helvetica" 20		# change terminal to PNG, taking additional options from second argument
set style data point
set o "./figs/$0.eps"						# set the output filename to the first option
set xlabel "Time"
set ylabel ""
set grid
plot [][] "$1" u 1:2 pt 7 ps 0.3 lc rgb "black" title "Kinetic", "$1" u 1:3 pt 7 ps 0.3 lc rgb "red" title "Potential" # plot command
set o								# restore output to interactive mode
set t pop							# restore the terminal
