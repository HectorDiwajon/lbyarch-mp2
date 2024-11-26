nasm -f win64 lbyarch-mco2.asm
gcc -c cfile.c -o cfile.obj -m64
gcc cfile.obj lbyarch-mco2.obj -o cfile.exe -m64
cfile.exe