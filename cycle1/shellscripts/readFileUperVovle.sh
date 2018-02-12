printf "Enter source file name :"
read source
printf "Enter destination file name :"
read dest
cat $source | sed 'y/aeiou/AEIOU/' > $dest
