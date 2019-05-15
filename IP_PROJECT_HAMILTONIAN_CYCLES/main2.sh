#author @vikrant
if [ -e temp.tmp ] ; then
rm temp.tmp
fi
for (( i=0; i<$(cat abc); i++ )) ;
do
new_input=$(zenity --text="Enter the person(s) known by Guest- $i"   --height=500 --width=500 --entry)
echo $new_input>>temp.tmp
echo ' -1996 '>>temp.tmp
done
rm abc
