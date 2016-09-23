#!/bin/bash

libroot=$SHCF_PLATFORM_ROOT/repo
docsroot=$SHCF_PLATFORM_ROOT/docs

docfile=$docsroot/lib.txt

rm $docfile
for each_libdir in xx1 xx2 xx3; do
  for each_libfile in $(ls -1 $libroot/$each_libdir/*.bash.inc); do
      echo "Library file: lib/$each_libdir/$(basename $each_libfile)"
      echo
      grep ^##\| $each_libfile | sed 's/##| //g'
      echo '---------- END ------------------'
      echo
  done  >> $docsroot/lib.txt
done
