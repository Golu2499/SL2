#! /bin/sh

while (true)
do

     echo "Menu\n"
     echo "1.Create Portfolio\n\t"
     echo "2. Enter Stock\n\t" 
     echo "3.Delete (sell ) stock\n\t4 .Search\n\t5.Display Portfolio\n\t6.Modify Portfolio\n\t7.Exit\n"
     echo "Enter you choice\t"
   read choice
     case "$choice" in
           1) echo " Portfolio "
                echo > portfolio ;;

           2)
              echo " Enter stock name"
              read stock_name
              echo "Enter id"
              read id
              echo "Enter quantity"
              read quantity

			  grep ^$id portfolio
			  if [ $? -ne 0];
             	    then record="$id\t\t$stock_name\t\t$quantity"
            	    echo $record >> portfolio
                	sort -o portfolio portfolio

              else
					echo "Stock already present"

			  fi ;;

           3)

              echo " Enter the id for the stock "
              read iden
              grep ^$iden portfolio
              if [ $? -ne 0 ]; then
              	echo "stock does not exist or is already sold " 
              else

             grep -v ^$iden portfolio>bin

             cp bin portfolio
             rm bin
             echo "Stock has been sold " 
             fi ;;

          4)
             echo "Enter id for the stock to be searched:"

             read temporary_id
             grep ^$temporary_id portfolio
             if [ $? -ne 0 ]; then
 
                  echo " stock not found or has been sold"
 
             fi ;;

          5)
              echo "ID \t Company \t Quantity"
              cat portfolio
              ;;

          6)

	          echo "Enter id for asset reallocation"
              read identity
              grep ^$identity portfolio
              if [ $? -ne 0 ]; then
                  echo "stock not found or may be sold"
              else

              grep -v $identity portfolio>bin
              cp bin portfolio
              rm bin
           echo "Change of asset or quantity "
           echo "Name of stock :"
           read stock_name
           echo "Buying quantity : "
           read quantity
           record="$identity\t\t$stock_name\t\t$quantity"
           echo $record >> portfolio
           sort -o portfolio portfolio
           fi ;;

        7)
              exit 0
              ;;
        *)
             echo "Enter valid coice"
             ;;

   esac
done
