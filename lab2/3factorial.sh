read n;
i=1;
ans=1;
while [ $i -le `expr $n - 1` ]
do 
i=`expr $i + 1`;
ans=`expr $i \* $ans`;
done
echo $ans;

