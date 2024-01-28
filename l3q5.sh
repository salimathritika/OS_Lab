#lab 3 question 5 working
echo "Enter the extension and the folder name"
read ext fol
mkdir -p $fol
mv *"$ext" "$fol"
echo "Successful"

