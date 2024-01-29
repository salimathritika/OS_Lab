#lab 4 question 2 working
echo "Enter path to folder"
read path
cd ~
cd $path
for i in "$@"; do
   rm -i "$i"
done
