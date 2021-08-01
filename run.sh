for k in {1..10..1}
do
   for j in {10000..10000000..10000}
   do
      for i in {10000..10000000..10000}
      do
         ./main $i $j saida.txt
      done
   done
done