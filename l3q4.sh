#lab 3 question 4 working

echo "enter basics and ta"
read b t
echo "gross value is:"
g=$(echo "scale=2;($b + $t + 0.1 * $b)"| bc)
echo $g


