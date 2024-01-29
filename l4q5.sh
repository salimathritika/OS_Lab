#lab 4 question 5 is working
cd ~
echo "Enter the path to the folder"
read path
cd $path
echo "Input file name"
read file
echo "a)"
for i in "$@"; do
grep $i $file
done
echo "b)"
for i in "$@"; do
grep -v $i $file>temp && mv temp $file
done
cat $file
echo "c)Exiting"
exit

