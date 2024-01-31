#lab 4 q3
# Sort the command-line arguments
sorted_args=$(printf "%s\n" "$@" | sort)

# Print the sorted strings
echo "Sorted strings:"
echo "$sorted_args"
