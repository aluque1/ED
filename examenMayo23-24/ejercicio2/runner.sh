g++ -Wall -g $1 -o $2 && ./"$2" < datos.txt > e.out && cat e.out && rm "$2"
