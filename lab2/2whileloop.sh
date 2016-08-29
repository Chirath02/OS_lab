i=0;
while [ $i -le $# ]
do 
i=`expr $i + 1`;
done
echo `expr $i - 1`;
