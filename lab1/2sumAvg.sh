echo "Enter 4 numbers"
read a 
read b
read c
read d

sum=`expr $a + $b + $c + $d`

avg=`expr $sum / 4`

product=`expr $a \* $b \* $c \* $d`

echo "sum : $sum"

echo "average : $avg"

echo "product : $product"



