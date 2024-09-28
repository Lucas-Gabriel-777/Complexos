/*Autor: Lucas Gabriel dos Santos Lima
  Data:26-09-2024 
  Objetivo: Criar um programa com metodos variados para calculo da aera de figuras geometricas
  usando ponteiros e variaveis dinamicas*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <math.h>

void gotoxy(int x, int y){
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void tela(){
    int lin;
    system("cls");
    for (lin=1 ; lin<25 ; lin++){
        gotoxy(01,lin);
        printf("|");
        gotoxy(79,lin);
        printf("|");
    }
    gotoxy(01,01);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(01,05);
    printf("+-----------------------------------------------------------------------------+");
     gotoxy(01,22);
    printf("+-----------------------------------------------------------------------------+");
     gotoxy(01,25);
    printf("+-----------------------------------------------------------------------------+");

    gotoxy(02,02);
    printf("UNICV");
    gotoxy(61,02);
    printf("Estrutura de dados");
    gotoxy(02,04);
    printf("Calculo de area");
    gotoxy(74,04);
    printf("Lucas");
}

void circulo(){
    float *raio,*area;
    int *op; 
    do {
        raio = (float *) malloc (sizeof(float));
        area = (float *) malloc (sizeof(float));
        op = (int *) malloc (sizeof(int));

        system("Cls"); 
        tela(); 
        gotoxy(02,06);
        printf("Digite 1 para calcular ou 2 para cancelar: ");
        gotoxy(45,06);
        scanf("%d", op);

        if (*op == 2){
            printf("Encerrando programa");
            break;
        }

        else if (*op == 1){
            
            gotoxy(02,07);
            printf("Digite o valor do raio: ");
            gotoxy(26,07);
            scanf("%f", raio);

            if (*raio < 0.00){
                do{
                    gotoxy(02,24);
                    printf("O raio deve ser maior que ZERO. Tecle enter para tentar novamente");
                    getch();
                    
                    gotoxy(02,24);
                    printf("                                                                  ");
                    gotoxy(26,07);
                    printf("                 ");
                    gotoxy(26,07);
                    scanf("%f", raio);
                } while (*raio < 0.00);
                
            } 

            *area = pow((3.1416 * (*raio)), 2); 

            gotoxy(2,8);
            printf("Valor da area do criculo: ");
            gotoxy(28,8);
            printf("%.2f", *area);
            getch();
        }

    } while (*op !=1  || *op  != 2);

    free(raio);
    free(op);
    free(area);
}

void retangulo(){
    float *area, *lado,*altura;
    int *op;
    do {

        area = (float *) malloc (sizeof(float));
        lado = (float *) malloc (sizeof(float));
        altura = (float *) malloc (sizeof(float));
        op = (int *) malloc (sizeof(int));

        system("Cls");
        tela(); 
        gotoxy(02,06);
        printf("Digite 1 para calcular ou 2 para cancelar: ");
        gotoxy(45,06);
        scanf("%d", op);

        if (*op ==2){
            printf("Encerrando programa");
            break;
        }

        else if (*op == 1){
            
            gotoxy(02,07);
            printf("Digite o valor do lado: ");
            gotoxy(26,07);
            scanf("%f", lado);

            if (*lado <= 0.00){ 
                do{
                    gotoxy(02,24);
                    printf("O lado deve ser maior que ZERO. Tecle enter para tentar novamente");
                    getch();
                    
                    gotoxy(02,24);
                    printf("                                                                  ");
                    gotoxy(26,07);
                    printf("                 ");
                    gotoxy(26,07);
                    scanf("%f", lado);
                } while (*lado <= 0.00); 
            } 

            gotoxy(02,8);
            printf("Digite o valor da altura: ");
            gotoxy(28,8);
            scanf("%f", altura);
            if (*altura <= 0.00){
                do{
                    gotoxy(02,24);
                    printf("A altura deve ser maior que ZERO. Tecle enter para tentar novamente");
                    getch();
                    
                    gotoxy(02,24);
                    printf("                                                                    ");
                    gotoxy(26,07);
                    printf("                 ");
                    gotoxy(28,8);
                    scanf("%f", altura);
                } while (*altura <= 0.00);
            }

            *area = *lado * *altura; 

            gotoxy(2,9);
            printf("Valor da area do retangulo: ");
            gotoxy(30,9);
            printf("%.2f", *area);
            getch();
        }

    } while (*op !=1  || *op  != 2);
    free(area);
    free(lado);
    free(altura);
    free(op);
}

void trapezio(){
    float *area, *bma, *bme, *altura;
    int *op; 
    do {
        area = (float *) malloc (sizeof(float));
        bme = (float *) malloc (sizeof(float));
        bma = (float *) malloc (sizeof(float));
        altura = (float *) malloc (sizeof(float));
        op = (int *) malloc (sizeof(int));

        system("Cls"); 
        tela(); 
        gotoxy(02,06);
        printf("Digite 1 para calcular ou 2 para cancelar: ");
        gotoxy(45,06);
        scanf("%d", op);

        if (*op ==2){ 
            printf("Encerrando programa");
            break;
        }

        else if (*op == 1){ 
            
            gotoxy(02,07);
            printf("Digite o valor da menor base: ");
            gotoxy(32,07);
            scanf("%f", bme);

            if (*bme <= 0.00){ 
                do{
                    gotoxy(02,24);
                    printf("A menor base deve ser maior que ZERO. Tecle enter para tentar novamente");
                    getch();
                    
                    gotoxy(02,24);
                    printf("                                                                        ");
                    gotoxy(32,07);
                    printf("                 ");
                    gotoxy(32,07);
                    scanf("%f", bme);
                } while (*bme <= 0); 
            } 

            gotoxy(02,8);
            printf("Digite o valor da maior base: ");
            gotoxy(32,8);
            scanf("%f", bma);
            if (*bma <= 0.00){ 
                do{
                    gotoxy(02,24);
                    printf("A maior base deve ser maior que ZERO. Tecle enter para tentar novamente");
                    getch();
                    
                    gotoxy(02,24);
                    printf("                                                                        ");
                    gotoxy(32,8);
                    printf("                 ");
                    gotoxy(32,8);
                    scanf("%f", bma);
                } while (*bma <= 0);
            }
            gotoxy(02,9);
            printf("Digite o valor da altura: ");
            gotoxy(28,9);
            scanf("%f", altura);

            if (*altura <= 0.00){ 
                do{
                    gotoxy(02,24);
                    printf("A menor base deve ser maior que ZERO. Tecle enter para tentar novamente");
                    getch();
                    
                    gotoxy(02,24);
                    printf("                                                                        ");
                    gotoxy(28,9);
                    printf("                 ");
                    gotoxy(28,9);
                    scanf("%f", altura);
                } while (*altura <= 0);
            }

            *area = ((*bma + *bme) * *altura) / 2; 

            gotoxy(2,10);
            printf("Valor da area do retangulo: ");
            gotoxy(30,10);
            printf("%.2f", *area);
            getch(); 
            

        } 
    } while (*op !=1  || *op  != 2);
    free(area);
    free(bma);
    free(bme);
    free(altura);
    free(op);
}

void triangulo(){
    float *area, *base, *altura;
    int *op; 
    do {

        area = (float *) malloc (sizeof(float));
        base = (float *) malloc (sizeof(float));
        altura = (float *) malloc (sizeof(float));
        op = (int *) malloc (sizeof(int)); 

        system("Cls");
        tela(); 
        gotoxy(02,06);
        printf("Digite 1 para calcular ou 2 para cancelar: ");
        gotoxy(45,06);
        scanf("%d", op);

        if (*op ==2){
            printf("Encerrando programa");
            break;
        }

        else if (*op == 1){ 
            
            gotoxy(02,07);
            printf("Digite o valor do lado: ");
            gotoxy(26,07);
            scanf("%f", base);

            if (*base <= 0.00){ 
                do{
                    gotoxy(02,24);
                    printf("O lado deve ser maior que ZERO. Tecle enter para tentar novamente");
                    getch();
                    
                    gotoxy(02,24);
                    printf("                                                                  ");
                    gotoxy(26,07);
                    printf("                 ");
                    gotoxy(26,07);
                    scanf("%f", base);
                } while (*base <= 0); 
            } 

            gotoxy(02,8);
            printf("Digite o valor da altura: ");
            gotoxy(28,8);
            scanf("%f", altura);
            if (*altura <= 0.00){ 
                do{
                    gotoxy(02,24);
                    printf("A altura deve ser maior que ZERO. Tecle enter para tentar novamente");
                    getch();
                    
                    gotoxy(02,24);
                    printf("                                                                    ");
                    gotoxy(26,07);
                    printf("                 ");
                    gotoxy(28,8);
                    scanf("%f", altura);
                } while (*altura <= 0.00);
            }

            *area = (*base * *altura) /2; 

            gotoxy(2,9);
            printf("Valor da area do retangulo: ");
            gotoxy(30,9);
            printf("%.2f", *area); 
            getch();
        }

    } while (*op !=1  || *op  != 2);

    free(area);
    free(base);
    free(altura);
    free(op);
}
int main (){
    int *op; 
    do {
        op = (int *) malloc (sizeof(int)); 

        system("Cls");
        tela();

        gotoxy(28,8);
        printf("Oque voce quer fazer? ");
        gotoxy(28,10);
        printf("1-Calcular area de um circulo"); 
        gotoxy(28,11);
        printf("2-Calcular area de um retangulo");
        gotoxy(28,12);
        printf("3-Calcular area de um trapezio");
        gotoxy(28,13);
        printf("4-Calcular area do triangulo");
        gotoxy(28,14);
        printf("5-Encerrar o programa");

        gotoxy(28,15);
        printf("Opcao: ");
        gotoxy(35,15);
        scanf("%d", op); 

        if (*op <0.00){ a
            do {
                gotoxy(02,24);
                printf("Resposta invalida, tecle Enter para continuar");
                getch();
                gotoxy(02,24);
                printf("                                             ");
                gotoxy(35,15);
                printf("           ");
                gotoxy(35,15);
                scanf("%d", op);
            } while (*op < 0.00);
        }

        switch(*op){ 
            case 1:
            gotoxy(02,24);
            printf("Calculadora de area circular, tecle C para continuar");
            getch();
            gotoxy(02,24);
            printf("                                                    ");
            break;

            case 2:
            gotoxy(02,24);
            printf("Calculadora de area retangular, pressione C para continuar");
            getch();
            gotoxy(02,24);
            printf("                                                          ");
            break;
            
            case 3:
            gotoxy(02,24);
            printf("Calculadora de area do trapezio, pressione C para continuar");
            getch();
            gotoxy(02,24);
            printf("                                                          ");
            break;

            case 4:
            gotoxy(02,24);
            printf("Calculadora de area triangular, pressione C para continuar");
            getch();
            gotoxy(02,24);
            printf("                                                          ");
            break;

            case 5:
            gotoxy(02,24);
            printf("Encerrando programa, pressione C para continuar");
            getch();
            gotoxy(02,24);
            printf("                                               ");
            break;
        }

        if (*op == 1){
            circulo();
        }
        else if ( *op == 2){
            retangulo();
        } else if (*op ==3 ){
            trapezio();
        } else if (*op == 4){
            triangulo();
        }
    }while ( *op > 0 && *op < 5);

    return 0; 
} 
