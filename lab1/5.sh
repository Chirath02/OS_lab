#!/bin/bash
echo "Enter first string"
read a
echo "Enter second string"
read b
echo $a $b  >1.txt 
wc -m 1.txt