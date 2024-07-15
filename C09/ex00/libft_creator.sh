#!/bin/bash

# Compile all .c files into object files
# echo "Compiling .c files to .o files..."
find . -name "*.c" -type f -exec gcc -Wall -Werror -Wextra -c {} \;

# Create list of gcc made .o files -> save them as a list inside current_objects var
current_objects=$(find . -name "*.o" -type f)
# echo "Object files found:\n$current_objects"

# Create (c) or update (r) the library with current_objects (ar = archive)
# echo "Creating/updating libft.a with current objects..."
ar rc libft.a $current_objects

# Verify the library content
# echo "Contents of libft.a after adding current objects:"
# ar t libft.a

# Remove obsolete objects from the library
# For each object in the current_objects list (listing through the ar t command)
# if it's not in the current_objects list
# (grep -q " ./$obj "): check if the object exists in the current_objects list (quiet mode: no output to stdout)
# remove it (ar d name_obj)
# echo "Removing obsolete objects from libft.a..."
for obj in $(ar t libft.a); do
    if ! echo "$current_objects" | grep -q "./$obj"; then
        #echo "Removing obsolete object: $obj"
        ar d libft.a $obj
    fi
done

# Verify the library content again, after removing obsolete objects
# echo "Contents of libft.a after removing obsolete objects:"
#ar t libft.a

# echo "Cleaning up object files..."
find . -name "*.o" -type f -delete

#echo "Script execution completed."


# plus lisible, mais aussi plus bourrin ...
# delete si il existe
# rm -f libft.a
# trouve .c -> compile vers -o;
# find . -name "*.c" -type f -exec gcc -Wall -Werror -Wextra -c {} \;
# fait la librarie a partir des .o
# r -> remplacer les trucs si existe déjà (mais n'existe pas: ligne 1)
# c -> creer l'archive si elle n'existe pas (ligne 1 ...)
# ar rc libft.a .o
# delete tout les .o
# find . -name ".o" -type f -delete