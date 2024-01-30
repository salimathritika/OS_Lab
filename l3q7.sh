#lab3 question 7
cd ~
echo "Enter the path to the folder"
read path
cd $path
echo "Enter file name"
read name
sed -i '2~2d' "$name"
