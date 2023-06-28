#include <stdio.h>
#include <time.h>

int main() {
    int o;
    // Mostrar menu
    printf("\nEscoga una opcion:\n1\tBuscar un valor específico en un arreglo de 100 elementos llenado aleatoriamente.\n2\tBuscar un valor específico en una matriz de 50x50 llenada aleatoriamente.\n3\tLLenar tres arreglos de 5 elementos y luego mostrar una matriz de 5x3 y 3x5 con los arreglos brindados.\n4\tCambiar valores de una matriz de 5x5 llenada aleatoriamente.\n5\tSumar dos matrices del mismo tamaño.\n6\tSalir\n");
    do {
        scanf("%d", &o);
        if (o<1 || o>6)
            printf("\nOpción no válida. Ingrese otra opción:\t");
    } while(o<1 || o>6);
    
    switch(o) {
        // problema 1
        case 1:
            int a,c=0, x;
            int arr[100];
           
            srand(time(NULL));
            // llenar arreglo aleatoriamente
            for (int i=0; i<100; i++) {
                arr[i]= rand()%200;
                
            }
            // asegurar que se ingreso un numero valido
            do {
                printf ("\nINGRESA EL NUMERO A BUSCAR:\t");
                scanf("%d",&a);
                if (a<0 || a>200)
                    printf("\nValor no válido");
            } while(a<0 || a>200);
            
            printf("\nLas posiciones donde aparece %d son:\n", a);
            // imprimir las posiciones donde se encontro el numero y contar las apariciones
            for (int j=0; j<100; j++){
                if (arr[j]==a) {
                    c++;
                    printf("\n%d", j);
                }
            }
            
            printf ("\n%d apareció %d veces", a, c);
            // permitir opcion de mostrar el valor de las posiciones indicadas
            do {
                printf("\nDesea verificar?\n1\tSi\n2\tNo\n");
                scanf("%d", &x);
                // pedir posicion y mostrar el contenido en el arreglo
                if (x==1) {
                    printf("\nIngrese la posicion a buscar en el arreglo:\t");
                    scanf("%d", &a);
                    printf("\narr[%d]=%d", a, arr[a]);
                }
                
                else if (x==2)
                    continue;
                else
                    printf("\nOpcion no valida\n");
            } while(x!=2);
            
            break;
        // problema 2
        case 2:
            int a2,c2=0,y;
            int arr2[50][50];
           
            srand(time(NULL));
            // llenar aleatoriamente la matriz
            for (int i=0; i<50; i++) {
                for (int j=0; j<50; j++) {
                   arr2[i][j]= rand()%200; 
                }
            }
            // asegurar que se ingreso un numero valido
            do {
                printf ("\nINGRESA EL NUMERO A BUSCAR:\t");
                scanf("%d",&a2);
                if (a2<0 || a2>200)
                    printf("\nValor no válido");
            } while(a2<0 || a2>200);
            printf("Las coordenadas donde aparece %d son:\n", a2);
            // buscar e imprimir las posiciones donde se encuentre dicho valor
            for (int j=0; j<50; j++){
                for (int i=0; i<50; i++) {
                    if (arr2[j][i]==a2) {
                    c2++;
                    printf("\n(%d, %d)", j, i);
                    }
                }
            }
            
            printf ("\n%d apareció %d veces", a2, c2);
            // permitir si desean verificar
            do {
                printf("\n\nDesea verificar?\n1\tSi\n2\tNo\n");
                scanf("%d", &y);
                /// pedir coordenada a comprobar e imprimir lo que esta en la matriz
                if (y==1) {
                    printf("\nIngrese la coordenada a buscar en el arreglo:\t");
                    scanf("%d %d", &a2, &c2);
                    printf("\narr[%d][%d]=%d", a2, c2, arr2[a2][c2]);
                }
                
                else if (y==2)
                    continue;
                
                else
                    printf("Opcion no valida");
            } while(y!=2);
            break;
        // problema 3
        case 3:
            int c3;
            int a31[5], a32[5], a33[5];
            int b31[5][3], b32[3][5];
            // pedir llenar el primer arreglo
            printf("\nLLena el primer arreglo\n");
            for (int i=0; i<5; i++) {
                scanf("%d", &c3);
                a31[i]=c3;
            }
            // pedir llenar el segundo arreglo
            printf("\nLLena el segundo arreglo\n");
            for (int i=0; i<5; i++) {
                scanf("%d", &c3);
                a32[i]=c3;
            }
            // pedir llenar el tercer arreglo
            printf("\nLLena el tercer arreglo\n");
            for (int i=0; i<5; i++) {
                scanf("%d", &c3);
                a33[i]=c3;
            }
            // llenar la matriz de 5x3
            for (int i=0; i<3; i++) {
                for (int j=0; j<5; j++) {
                    if (i==0)
                        b31[j][i]=a31[j];
                    else if (i==1)
                        b31[j][i]=a32[j];
                    else
                        b31[j][i]=a33[j];
                }
            }
            // llenar la matriz de 3x5 girando en invirtiendo la de 5x3
            for (int i=0; i<3; i++) {
                for (int j=0; j<5; j++) {
                    b32[i][j]=b31[j][i];
                }
            }
            // imprimir arreglos y matrices
            printf("\nArreglo 1\n");
            for (int i=0; i<5; i++) {
                printf("[%d]\t", a31[i]);
            }
            printf("\n\nArreglo 2\n");
            for (int i=0; i<5; i++) {
                printf("[%d]\t", a32[i]);
            }
            printf("\n\nArreglo 3\n");
            for (int i=0; i<5; i++) {
                printf("[%d]\t", a33[i]);
            }
            printf("\n\nArreglo 5x3\n");
            for (int i=0; i<5; i++) {
                for (int j=0; j<3; j++) {
                    printf("[%d]\t", b31[i][j]);
                }
                printf("\n");
            }
            printf("\nArreglo 3x5\n");
            for (int i=0; i<3; i++) {
                for (int j=0; j<5; j++) {
                    printf("[%d]\t", b32[i][j]);
                }
                printf("\n");
            }
            break;
        // problema 4
        case 4:
            int c4, a4, b4, d4;
            int arr4[5][5];
            srand(time(NULL));
            // llenar la matriz aleatoriamente
            for (int i=0; i<5; i++) {
                for (int j=0; j<5; j++) {
                    arr4[i][j]=rand()%100;
                }
            }
            // mostrar la matriz
            printf("\n");
            for (int i=0; i<5; i++) {
                for (int j=0; j<5; j++) {
                    printf("(%d, %d)-[%d]\t", i, j, arr4[i][j]);
                }
                printf("\n");
            }
            
            printf("\nCuantos valores deseas cambiar:\t");
            // descartar opciones sin sentido como negativos
            do {
                scanf("%d", &c4);
                if (c4<0)
                    printf("\nValor no valido. Ingrese otro:\t");
                else
                    continue;
            } while(c4<0);
            // si elige 0 no hay cambios, si escoge otro preguntamos y cambiamos uno por uno
            switch(c4) {
                case 0:
                    printf("\nSin cambios\n");
                    break;
                default:
                    for (int i=0; i<c4; i++) {
                    printf("\nIngrese la coordenada a cambiar:\t");
                    scanf("%d %d", &a4, &b4);
                    printf("\nIngrese el nuevo valor:\t");
                    scanf("%d", &d4);
                    arr4[a4][b4]=d4;
                }
                
                printf("\nMatriz cambiada\n");
                // mostrar matriz nueva
                for (int i=0; i<5; i++) {
                    for (int j=0; j<5; j++) {
                        printf("(%d, %d)-[%d]\t", i, j, arr4[i][j]);
                    }
                    printf("\n");
                }
            }
            break;
        // problema 5
        case 5:
            int s5, t5;
    
            srand(time(NULL));
            // pedir tamano de las matrices
            printf("\nIngresa el numero de filas de las matrices:\t");
            scanf("%d", &s5);
            
            printf("\nIngresa el numero de columnas de las matrices:\t");
            scanf("%d", &t5);
            
            int A[s5][t5], B[s5][t5], C[s5][t5];
            // llenar matrices aleatoriamente
            for (int i=0; i<s5; i++) {
                for (int j=0; j<t5; j++) {
                    A[i][j]=rand()%100;
                }
            }
            
            for (int i=0; i<s5; i++) {
                for (int j=0; j<t5; j++) {
                    B[i][j]=rand()%100;
                }
            }
            // matriz suma de A con B
            for (int i=0; i<s5; i++) {
                for (int j=0; j<t5; j++) {
                    C[i][j]=A[i][j]+B[i][j];
                }
            }
            // imprimir A, B y C
            printf("\n\nMatriz A\n");
            for (int i=0; i<s5; i++) {
                for (int j=0; j<t5; j++) {
                    printf("[%d]\t", A[i][j]);
                }
                printf("\n");
            }
            printf("\n\nMatriz B\n");
            for (int i=0; i<s5; i++) {
                for (int j=0; j<t5; j++) {
                    printf("[%d]\t", B[i][j]);
                }
                printf("\n");
            }
            printf("\n\nMatriz C\n");
            for (int i=0; i<s5; i++) {
                for (int j=0; j<t5; j++) {
                    printf("[%d]\t", C[i][j]);
                }
                printf("\n");
            }
            break;
        // salir
    }
    
    return 0;
}
