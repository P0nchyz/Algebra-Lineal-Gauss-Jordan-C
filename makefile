linux: main.c lib/matrices.c lib/aumMatrices.c lib/opElementales.c
	gcc -o gauss_jordan.out $^
windows: main.c lib/matrices.c lib/aumMatrices.c lib/opElementales.c
	gcc -o gauss_jordan.exe $^