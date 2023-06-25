#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void AlgDiv(int, int, int*, int*);
void caseI(int*, int*);
void caseII(int, int, int*, int*);
void caseIII(int, int, int*, int*);

int main() {
	int o, a, b, q, r, *p1=NULL, *p2=NULL;
	p1 = &q;
	p2 = &r;

	do {
	    printf("Selecciona una opción:\n0\tSalir\n1\tAlgoritmo de la división\n2\tMáximo común divisor\n3\tCambio de base\n");
	    scanf("%d", &o);
		if (o==0)
			printf("\nSaliendo...\n");
			
		else if (o==1) {
			printf("\nIngresa dos enteros a y b:\t");
    		scanf("%d %d", &a, &b);
			AlgDiv(a, b, p1, p2);
			printf("\n%d = %d(%d) +%d\n\n", a, b, q, r);
		}

		else if (o==2) {
			int a1, b1, m, c;

			printf("\nIngrese dos enteros a y b:\t");
    		scanf("%d %d", &a, &b);
    		a1=a;
    		b1=b;
			// Si alguno es 0, el mcd es 0
    		if (a==0)
        		printf("\nEl máximo común divisor de %d y %d es: %d\n\n", a1, b1, abs(b));

    		else if (b==0)
        		printf("\nEl máximo común divisor de %d y %d es: %d\n\n", a1, b1, abs(a));
    		// El mcd de dos números es igual al mcd de sus valores absolutos y el orden no importa    
    		else {
        		if (abs(a)>=abs(b)) {
            		a=abs(a);
            		b=abs(b);
        		}
        
        		else {
            		c=a;
            		a=abs(b);
            		b=abs(c);
        		}
        		// Obtenemos el mcd mediante el algoritmo de Euclides
        		for (int i=0; i<i+1; i++) {
            		AlgDiv(a, b, p1, p2);
            
            		if (*p2==0) {
            		    m=b;
                		break;
            		}
            
            		else {
                		a=b;
                		b=(*p2);
            		}
        		}
        
        		printf("\nEl máximo común divisor de %d y %d es: %d\n\n", a1, b1, m);
        
    		}
		}

		else if (o==3) {
			int a2, s, i=-1;

			a2=a;
			p1=&q;
			p2=&r;

			printf("\nIngresa el número en decimal:\t");
    		scanf("%d", &a);
    
			printf("\nIngresa la base a cambiar:\t");
			scanf("%d", &b);
    
			// Obtener el tamaño del número cambiado
			s=0;
		    while(s<a) {
			    i++;
			    s=pow(b, i);
			}
			s=i;
			i=0;
			    
			// Iniciar arr donde se guardaran los residuos
			int arr[s];
			    
			// Ejecutar algoritmo de la división y guardar los residuos
			do {
			    AlgDiv(a, b, p1, p2);
			    arr[s-1-i] = r;
			    a=q;
			    i++;
			} while(q);
			    
			// Imprimir cada dígito por separado
			printf("\n");
			for (int j=0; j<s; j++) {
			    switch (arr[j]) {
			            case 10:
			                printf("A");
			                //printf("%X", arr[j]);
			                break;
			            case 11:
			                printf("B");
			                break;
			            case 12:
			                printf("C");
			                break;
			            case 13:
			                printf("D");
			                break;
			            case 14:
			                printf("E");
			                break;
			            case 15:
			                printf("F");
			                break;
			            default:
			                printf("%d", arr[j]);
			                break;
			        }
			}
			    
			printf(" representa al entero %d en base %d\n\n", a2, b);
		}
		
	    else
			printf("\nOpción no válida\n\n");
				
	} while(o);

	return 0;
}
// Algoritmo de la división
void AlgDiv(int a, int b, int *p1, int *p2) {
	if (b>0) {
		if (a==0)
			caseI(p1, p2);
		else if (a>0)
			caseII(a, b, p1, p2);
		else
			caseIII(a, b, p1, p2);
	}

	else {
		if (a==0)
			caseI(p1, p2);
		else if (a>0) {
			caseII(a, -b, p1, p2);
			(*p1)*=-1;
		}
		else {
			caseIII(a, -b, p1, p2);
			(*p1)*=-1;
		}
	}
}
// Si a=0, b>0
void caseI(int *p1, int *p2) {
    *p1=0;
    *p2=0;
}
// Si a>0, b>0
void caseII(int a, int b, int *p1, int *p2) {
    if (a<b) {
        *p1=0;
        *p2=a;
    }
        
    else {
        *p1 = 1;
        while (a>=b*(*p1)) {
            (*p1)++;
        }
        (*p1)--;
        *p2=a-b*(*p1);
    }
}
// Si a<0, b>0
void caseIII(int a, int b, int *p1, int *p2) {
    caseII(-a, b, p1, p2);
    if (*p2>0) {
        *p1 = -(*p1 + 1);
        *p2 = b - (*p2);
    }
    else
        *p1 = -(*p1);
}
