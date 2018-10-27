clear
i="y"
while [ $i = "y" ]
do
echo "***MENU***"
echo "1.create the Data Base "
echo "2.view database "
echo "3.Add Records "
echo "4.View Specific Records "
echo "5.Delete Records "
echo "6.Exit "
echo "Enter your choice :"
read ch
    case $ch in
        1)echo "Enter the name of database :"
          read db
          touch $db;;
        2)echo "Your database :"
          cat $db;;
        3)echo "Enter new std id :"
          read tid
          echo "Enter new name :"
          read tnm
          echo "Enter designation :"
          read des
          echo "Enter college name :"
          read college
          echo "$tid    $tnm    $des    $college">>$db;;
        4)echo "Enter id :"
          read id
            grep -i "$id" $db;;
        
        5)echo "Enter Id :"
          read id
          grep -v "$id" $db >dbs1    
          echo "Record is deleted"
          mv dbs1 $db;;           
        6)exit;;
        *)echo "Invalid choice ";;
    esac
echo "Do u want to continue ?"
read i
if [ $i != "y" ]
then
    exit
fi
done   

