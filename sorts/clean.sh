#!/bin/bash
# clean all the files such as, a.out, xx.orig etc.

for file in $(find . -type f -name '*.cpp' -or -name '*.c' -or -name '*.h')
do
	astyle $file
done
for file in $(find . -type f -name '*.out' -or -name '*.orig')
do
	rm -f $file
done

