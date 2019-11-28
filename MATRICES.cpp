#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define valormax 50

void opciones(int &a);
void imprimir(int *ptr_m, int &o, char l);
void lee(int *ptr_m, int &o, char l);
void sumar(int *ptr_a, int *ptr_b, int *ptr_c, int &o);
void restar(int *ptr_a, int *ptr_b, int *ptr_c,  int &o);
void multiplicar(int *ptr_a, int *ptr_b, int *ptr_c, int &o);
void factor(int *ptr_a, int *ptr_b, int f, int c, int &fil, int col, int comp, int &ret);
void repet(char &re);
void limpiarpuntero(int *ptr_n);
void limpiar(int &ptr_n);

int main(void){
 	int matrizA[valormax][valormax], matrizB[valormax][valormax], matrizC[valormax][valormax], *ptrA, *ptrB, *ptrC, opcion, res, orden = 0, cas = 4;
	char repetir;
		ptrA = &matrizA[0][0];
		ptrB = &matrizB[0][0];
		ptrC = &matrizC[0][0];
	 
	 	do{   
	    	repetir = ' ';
	        
		    do{  
				opciones(opcion);
			        if(opcion < 1 || opcion > cas){
			            printf("\n*** Opcion incorrecta, intente de nuevo ***\n");
		                limpiar(opcion);
			        }
		    }while(opcion < 1 || opcion > cas);
		    
		    if(opcion != cas){
		        switch(opcion){
			        case 1:
						    lee(ptrA, orden, 'A');
						    printf("\n\n***** Ingrese otra matriz de orden %d *****\n\n",orden);
						    lee(ptrB, orden, 'B');
						    sumar(ptrA, ptrB, ptrC, orden);
						    imprimir(ptrC, orden, 'C');
			                break;
			                
			        case 2:
							lee(ptrA, orden, 'A');
						    printf("\n\n***** Ingrese otra matriz de orden %d *****\n\n",orden);
						    lee(ptrB, orden, 'B');
						    restar(ptrA, ptrB, ptrC, orden);
						    imprimir(ptrC, orden, 'C');
			                break;
			                
			        case 3:
		                    lee(ptrA, orden, 'A');
			                printf("\n\n***** Ingrese otra matriz de orden %d *****\n\n",orden);
			                lee(ptrB, orden, 'B');
			                multiplicar(ptrA, ptrB, ptrC, orden);
			                imprimir(ptrC, orden, 'C');
		                	break;
		        }
			repet(repetir);
			if(repetir == 's' || repetir == 'S'){
			    limpiarpuntero(ptrA);
			    limpiarpuntero(ptrB);
			    limpiarpuntero(ptrC);
		 	    limpiar(orden);
			    printf("\n\n");
			}
	    	}
		}while(repetir == 's' || repetir == 'S');
}

void opciones(int &a){
	printf("1. sumar\n");
	printf("2. restar\n");
	printf("3. multiplicacion\n");
	printf("4. salir\n");
	printf("\nelija una opcion: ");
	scanf("%d", &a);
}

void imprimir(int *ptr_m, int &o, char l){
    printf("\n---Matriz %c--------------------------------\n\n", l);
    for(int i = 0; i<o; i++){
        printf("    ");
        for(int j = 0; j<o; j++){
        printf(" %d ", *(ptr_m + j + (i*o)));
        }
    }
}

void lee(int *ptr_m, int &o, char l){
    if(o == 0){
	    do{
		printf("\nIngrese el orden de la matriz [%c] (1 - %d): ", l, valormax);
	    scanf("%d", &o);
	    if(o < 1 || o > valormax){
	    	printf("\n+++RANGO EQUIVOCADO+++\n");
	    	printf("El orden de la matriz debe ser entre 1 y %d\n", valormax);
	    	printf("Intente de nuevo\n\n");
	    	limpiar(o);
		}
		}while(o < 1 || o > valormax);
    }
    printf("\n---MATRIZ [%c] %d x %d ----------------------\n", l, o, o);
    printf("Leyendo valores de la matriz %c: \n",l);
	 for(int i = 0; i<o; i++){
        for(int j = 0; j< o; j++){
    printf("\nIntroduce el valor de Mat_%c[%d][%d]: ",l , i, j);
	   scanf("%d",ptr_m + (j + (i*o)));
            }
	 }	
}

void sumar(int *ptr_a, int *ptr_b, int*ptr_c, int &o){
	for(int i = 0; i<o; i++){
        for(int j = 0; j<o; j++){
		*(ptr_c + j + (i*o)) = *(ptr_a + j + (i*o)) + *(ptr_b + j + (i*o));
        }
	}
}

void restar(int *ptr_a, int *ptr_b, int*ptr_c, int &o){
	for(int i = 0; i<o; i++){
        for(int j = 0; j<o; j++){
		*(ptr_c + j + (i*o)) = *(ptr_a + j + (i*o)) - *(ptr_b + j + (i*o));
        }
	}
}

void multiplicar(int *ptr_a, int *ptr_b, int *ptr_c, int &o){
    int v = 0;
    for(int i = 0; i<o; i++){
        for(int j = 0; j<o; j++){
            factor(ptr_a, ptr_b, i, j, o, 0, 0, v);
            *(ptr_c + j + (i*o)) = v;
        }
    }
}

void factor(int *ptr_a, int *ptr_b, int f, int c, int &fil, int col, int comp, int &ret){
    limpiar(ret);
    if(col == 0 && comp == 0){
        col = fil;
        comp = fil;
    }
    for(int i = 0; i<comp; i++){
        ret += (*(ptr_a + i +(f*fil))) * (*(ptr_b + c + (i*comp)));
    }
}

void repet(char &re){
    printf("\n\n             [S] [N]\nDesea hacer otra operacion: ");
    scanf("%s", &re);
}

void limpiarpuntero(int *ptr_n){
    for(int i = 0; i<valormax; i++){
        *(ptr_n + i) = 0;
    }
}

void limpiar(int &ptr_n){
    ptr_n = 0;
}
