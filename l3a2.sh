#lab 3 additional 2

echo "input a number"
read num
i=$num
fac=1
for((i=$num;i > 0;i--)); do
fac=`expr $fac \* $i`
done
echo "factorial of $num is $fac"
