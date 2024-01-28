#lab 3 additional 1 not working
echo "Enter a number"
read num
flag=0
for((i=2;i<num;i++));do
if [ $(expr $num % $i) == 0 ]; then
   flag=1
fi
done

if [ $flag == 0 ]; then
   echo "$num is a prime number"
else
echo "$num is not a prime number"
fi
