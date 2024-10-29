linux: main.c lib/matrices.c lib/aumMatrices.c lib/opElementales.c gaussJordan.c pasoAPaso.c determinante.c SEL.c inversa.c
	gcc -o gauss_jordan.out $^ -lm
windows: main.c lib/matrices.c lib/aumMatrices.c lib/opElementales.c gaussJordan.c pasoAPaso.c determinante.c SEL.c inversa.c
	gcc -o gauss_jordan.exe $^