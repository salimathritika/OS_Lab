#lab 1 question 1 working
echo "Enter file/directory name to be checked"
cd ~
read name
if [ -d $name ]; then
   echo "It is a directory"
elif ! [ -d $name ]; then
    echo "It is a regular file"
fi
