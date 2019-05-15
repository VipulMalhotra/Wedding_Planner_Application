#Author @vikrant
start=$(zenity  --list --width=500 --height=500 --text "How do you wish the program to proceed?" --radiolist  --column "Pick" --column "Opinion" TRUE "Take Input From File- Hamilton_Cycle_500_Input.txt" FALSE "Take Input Manually")
#This is Option 1
if [[ $start == 'Take Input From File- Hamilton_Cycle_500_Input.txt' ]] ; then
if [ -e "temp.cpp" ] ; then
rm temp.cpp
fi
holder=500
echo '#define V' $holder>>temp.cpp
holder=1
echo '#define USER_OPINION' $holder>>temp.cpp
ITER=$(zenity  --list --width=500 --height=500 --text "How many solutions do you want the program to produce?" --radiolist  --column "Pick" --column "Opinion" TRUE "Single Solution" FALSE "Attempt Multiple Solutions")
if [[ $ITER == 'Single Solution' ]] ; then
holder=1
echo '#define MAX_ITER' $holder>>temp.cpp
fi
if [[ $ITER == 'Attempt Multiple Solutions' ]] ; then
holder=0
echo '#define MAX_ITER' $holder>>temp.cpp
fi
cat Hamilton_Cycle.cpp>>temp.cpp
g++ temp.cpp -o main
clear
rm temp.cpp
./main
fi
#This is Option 2
if [[ $start == 'Take Input Manually' ]] ; then
if [ -e "temp.cpp" ] ; then
rm temp.cpp
fi
if [ -e "abc" ] ; then
rm abc
fi
size=$(zenity --text="Enter the number of people to be invited in the party-" --entry)
echo '#define V' $size>>temp.cpp
echo '#define USER_OPINION 2'>>temp.cpp
echo $size>abc
ITER=$(zenity  --list --width=500 --height=500 --text "How many solutions do you want the program to produce?" --radiolist  --column "Pick" --column "Opinion" TRUE "Single Solution" FALSE "Attempt Multiple Solutions")
if [[ $ITER == 'Single Solution' ]] ; then
echo '#define MAX_ITER 1'>>temp.cpp
fi
if [[ $ITER == 'Attempt Multiple Solutions' ]] ; then
echo '#define MAX_ITER 0'>>temp.cpp
fi
cat Hamilton_Cycle.cpp>>temp.cpp
g++ temp.cpp -o main
clear
rm temp.cpp
./main
fi
echo Program Terminated Successfully.
echo Press Any Key To Continue...
read just_for_fun
zenity --info --text="Thanks For Using Our Program.\nCredits-\nVikramjit Singh(1410991672)\nVikrant(1410991673)\nVipul Malhotra(1410991677)\nYugansh Goyal(1410991697)\nCSE 4J-02\nChitkara University\nPunjab"
rm main
if [ -e "temp.tmp" ] ; then
rm temp.tmp
fi





