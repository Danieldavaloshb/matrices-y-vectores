#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define valormax 3

void opciones(int &a);
void mostrarvector(int *ptr_v, char l);
void mostrarvector(float *ptr_v, char l);
void leervector(int *ptr_v, char l);
void sumarvector(int *ptr_a, int *ptr_b, int *ptr_c);
void restarvector(int *ptr_a, int *ptr_b, int *ptr_c);
void productopunto(int *ptr_a, int *ptr_b, int &r);
void productoescalar(int *ptr_a, int *ptr_b, int *ptr_c, int &r);
void norma(int *ptr_a, float &r);
void vectorunitario(int *ptr_a, float *ptr_c);
void determinante(int *ptr_a, int *ptr_b, int val, int &ret);
void repetir(char &re);
void limpiarvector(int *ptr_n);
void limpiarvector(float *ptr_n);
void limpiar(int &ptr_n);
void limpiar(float &ptr_n);
 
int main(void){
	int VecA[valormax], VecB[valormax], VecC[valormax], *ptrA, *ptrB, *ptrC, ptr_res, opcion, cas = 7;
 	float pr, *ptrdec, Vecdec[valormax];
 	char rep;
	ptrA = &VecA[0];
	ptrB = &VecB[0];
	ptrC = &VecC[0];
 	ptrdec = &Vecdec[0];
 
 	do{   
        rep = ' ';
        
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
			        printf("\n\n---SUMA DE VECTORES-----------------------\n");
			        leervector(ptrA, 'A');
			        leervector(ptrB, 'B');
			        sumarvector(ptrA, ptrB, ptrC);
					printf("\n\n---RESULTADO------------------------------\n");
			        mostrarvector(ptrC, 'R');
		        break;
		        
		        case 2:
			        printf("\n\n---RESTA DE VECTORES----------------------\n");
			        leervector(ptrA, 'A');
			        leervector(ptrB, 'B');
			        restarvector(ptrA, ptrB, ptrC);
			 		printf("\n\n---RESULTADO------------------------------\n");
			        mostrarvector(ptrC, 'R');
		        break;
		        
		        case 3:
			        printf("\n\n---PRODUCTO PUNTO-------------------------\n");
			        leervector(ptrA, 'A');
			        leervector(ptrB, 'B');
			        productopunto(ptrA, ptrB, ptr_res);
			        printf("\nEl producto punto de los vectores A y B es: %d", ptr_res);
		        break;
		        
		        case 4:
			        printf("\n\n---PRODUCTO ESCALAR-----------------------\n");
			        leervector(ptrA, 'A');
			        leervector(ptrB, 'B');
			        productoescalar(ptrA, ptrB, ptrC, ptr_res);
			        printf("\nEl producto escalar de los vectores A y B es:\n");
			        mostrarvector(ptrC, 'R');
		        break;       
		        
		        case 5:  printf("\n\n---NORMA----------------------------------\n");
			        leervector(ptrA, 'A');
			        norma(ptrA, pr);
			        printf("\nLa norma del vector A es: %0.3f", pr);
		        break;
		     
		        case 6:
			        printf("\n\n---VECTOR UNITARIO------------------------\n");
			        leervector(ptrA, 'A');
			        vectorunitario(ptrA, ptrdec);               
					printf("\n\n---RESULTADO------------------------------\n");               
					mostrarvector(ptrdec, 'R');
		        break;
		    }    
	    repetir(rep);
	            if(rep == 's' || rep == 'S'){
	                limpiarvector(ptrA);
	                limpiarvector(ptrB);
	                limpiarvector(ptrC);
	                limpiarvector(ptrdec);
	                limpiar(ptr_res);
	                limpiar(pr);
	                printf("\n\n");
	            }
	    }
	}while(rep == 's' || rep == 'S');
}

void opciones(int &a){
	printf("1. sumarvector\n");
	printf("2. restarvector\n");
	printf("3. Producto punto\n");
	printf("4. Producto escalar\n");
	printf("5. norma\n");
	printf("6. Vector unitario\n");
	printf("7. Salir\n");
	printf("\nSeleccione una opcion: ");
	scanf("%d", &a);
}

void mostrarvector(int *ptr_v, char l){
    for(int i = 0; i<valormax; i++){
        printf("\nVec_%c[%d]: %d\n", l, i, *(ptr_v + i));
    }
}

void mostrarvector(float *ptr_v, char l){
    for(int i = 0; i<valormax; i++){
        printf("\nVec_%c[%d]: %.3f\n", l, i, *(ptr_v + i));
    }
}

void leervector(int *ptr_v, char l){
	 printf("\n------------------------------------------\n");
	 printf("Leyendo valores del vector %c: \n",l);
		 for(int i = 0; i<valormax ; i++){
	    	printf("\nIntroduce el valor de Vec_%c[%d]: ",l ,i);
		   	scanf("%d",ptr_v + i);
		 }	
}

void sumarvector(int *ptr_a, int *ptr_b, int*ptr_c){
	for(int i = 0; i<valormax; i++){
		*(ptr_c + i) = *(ptr_a + i) + *(ptr_b + i);
	}
}

void restarvector(int *ptr_a, int *ptr_b, int*ptr_c){
	for(int i = 0; i<valormax; i++){
		*(ptr_c + i) = *(ptr_a + i) - *(ptr_b + i);
	}
}

void productopunto(int *ptr_a, int *ptr_b, int &r){
    for(int i = 0; i<valormax; i++){
        r += (*(ptr_a + i)) * (*(ptr_b + i));
    }
}

void productoescalar(int *ptr_a, int *ptr_b, int *ptr_c, int &r){
    for(int i = 0; i<valormax; i++){
        determinante(ptr_a, ptr_b, i, r);
        *(ptr_c + i) = r;
    }
}

void norma(int *ptr_a, float &r){
    r = 0;
    for(int i = 0; i<valormax; i++){
        r += pow(*(ptr_a + i),2);
    }
    r = sqrt(r);
}

void vectorunitario(int *ptr_a, float *ptr_c){
    float pT;
    norma(ptr_a, pT);
    for(int i = 0; i<valormax; i++){
        *(ptr_c + i) = *(ptr_a + i) / pT;
    }
}

void determinante(int *ptr_a, int *ptr_b, int val, int &ret){
int Mat[2][2], x = 0, y = 0;
    for(int i = 0; i<2 ; i++){
        for(int j = 0; j<valormax; j++){
            if(i == 0 && j != val){
                Mat[x][y] = *(ptr_a + j);
                y++;
                if(y >= 2){
                    x++;
                    y = 0;
                }
            }
            if(i == 1 && j != val){
                Mat[x][y] = *(ptr_b + j);
                y++;
            }
        }
    }
    
ret = ((Mat[0][0])*(Mat[1][1])) - ((Mat[0][1])*(Mat[1][0]));
}

void repetir(char &re){
    printf("\n\n    [S] [N]\nDesea hacer otra operacion: ");
    scanf("%s", &re);
}

void limpiarvector(int *ptr_n){
    for(int i = 0; i<valormax; i++){
        *(ptr_n + i) = 0;
    }
}

void limpiar(int &ptr_n){
    ptr_n = 0;
}

void limpiarvector(float *ptr_n){
    for(int i = 0; i<valormax; i++){
        *(ptr_n + i) = 0;
    }
}

void limpiar(float &ptr_n){
    ptr_n = 0;
}
