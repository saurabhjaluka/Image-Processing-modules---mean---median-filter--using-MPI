#!/bin/sh

WINDOWS="3 5 8 13"
NPROCS="2 4 8 16"
FILTERS="mean median"

for FILTER in $FILTERS ; do 
   for WSIZE in $WINDOWS ; do
     for NPROC in $NPROCS ; do 
       OUT=moon_f${FILTER}_w${WSIZE}_n${NPROC}.tiff
       mpirun -np ${NPROC} pfilter input/moon_in.tiff ${OUT} ${FILTER} ${WSIZE}
     done
   done
done
 
