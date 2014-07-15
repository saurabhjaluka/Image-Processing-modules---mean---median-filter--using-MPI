#!/bin/sh

echo "run this script from your tiff-3.8.2/libtiff directory"

LIBRARY=libtiff.a
make
ar q $LIBRARY `\ls *.o | grep -v mkg3states`
