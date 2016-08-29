#!/bin/sh
echo "Enter the length and breadth of rectangle"
read l
read b
area=`expr $l \* $b`
p=`expr $l + $b`
perimetre=`expr 2 \* $p `
echo "Area = $area"
echo "Perimetre = $perimetre"
echo "Enter radius"
read r
areac=`expr 2 \* 3 \* $r`
echo "Area of Circle = $areac"
