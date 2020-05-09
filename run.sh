rm -rf *.o
gcc -c *.c
gcc -o main *.o && ./main
rm -rf *.o main