#lab 3 question 3
cd ~
echo "Enter path to folder"
read path
cd $path
for file in *.txt; do
mv "$file" "${file%.txt}.text"
done
