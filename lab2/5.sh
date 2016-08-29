#!/bin/sh
echo "The largest number:"
cat 1.txt|sort|tail -1
echo "Smallest number:"
cat 1.txt|sort|head -1
