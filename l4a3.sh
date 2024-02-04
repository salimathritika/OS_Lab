#lab 4 additional 3
cd ..
if [ "$2" -gt "$3" ]; then
    echo "Invalid start and end line."
    exit 1
fi
if [ ! -f "$1" ]; then
    echo "File '$1' does not exist."
    exit 1
fi
sed -n "$2,${3}p" "$1"

