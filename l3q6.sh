#lab3 question 6
cd ~
echo "Enter the path to the folder"
read path
cd $path
sed -i -e 's/^ex:/Example:/' *'txt'
sed -i -e 's/\.ex:/\.Example:/' *'txt'
echo "Successful"
