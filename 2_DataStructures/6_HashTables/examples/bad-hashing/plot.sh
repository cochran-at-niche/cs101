#!/bin/bash

go install
bad-hashing | gnuplot -p -e "set datafile separator \"\t\"; set boxwidth 0.5; set style fill solid; plot '-' using 1:2 with boxes"
