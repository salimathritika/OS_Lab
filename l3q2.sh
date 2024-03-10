#lab 3 question 2 working
echo "Enter the path of the folder in which to be searched"
read path
cd ~
cd $path
#ls -l
echo "Enter the file name"
read name
ls *$name*

#OR

cd ~
echo "Enter directory"
read path
cd $path
echo "Enter pattern"
read a
grep -lr $a| xargs echo $xargs
