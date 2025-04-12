/*Autor: Lucas Gabriel dos Santos Lima
  Data:12-04-2025
  Objetivo: Criar uma tela interativa para usuario que registre informacoes */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

void gotoxy(int x, int y){
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

typedef struct{
    int salario;
    int idade;
    char sexo;
} reg_user;

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
    printf("Cadastro de Clientes");
    gotoxy(74,04);
    printf("Lucas");
}

void opcao(){
    int op;
    gotoxy(28,8);
    printf("Oque voce quer fazer? ");
    gotoxy(28,9);
    printf("1-Cadastrar"); 
    gotoxy(28,10);
    printf("2-Consultar");
    gotoxy(28,11);
    printf("3-Sair");

    gotoxy(28,12);
    printf("Opcao: ");
    gotoxy(38,12);
    scanf("%d",&op);

    switch(op){
        case 1:
        gotoxy(28,12);
        printf("Iniciando cadastro, pressione C para continuar");
        getch();
        break;

        case 2:
        gotoxy(28,12);
        printf("Iniciando consulta, pressione C para continuar");
        getch();
        break;
    }
}


int main () { 
    reg_user User[6];
    int i = 0;
    int j = 0;
    int resp,op;
    do{
        
        system("Cls");
        tela();
        gotoxy(28,8);
        printf("Oque voce quer fazer? ");
        gotoxy(28,9);
        printf("1-Cadastrar"); 
        gotoxy(28,10);
        printf("2-Consultar");
        gotoxy(28,11);
        printf("3-Sair");

        gotoxy(28,12);
        printf("Opcao: ");
        gotoxy(38,12);
        scanf("%d",&op);

        if(op>3 || op<1){ 
            do{
                gotoxy(28,13);
                printf("Opcao invalida, tente novamente!");
                getch();
                gotoxy(38,12);
                printf("        ");
                gotoxy(38,12);
                scanf("%d",&op);        
            } while(op<1 || op>3);
        }
        
        switch(op){
            case 1:
            gotoxy(28,12);
            printf("Iniciando cadastro, pressione C para continuar");
            getch();
            break;

            case 2:
            gotoxy(28,12);
            printf("Iniciando consulta, pressione C para continuar");
            getch();
            break;
        }

        if (op == 1){
            do{
                for (i=1;i<6;i++){
                    system("Cls");
                    tela();

                    gotoxy(02,06);
                    printf("Cadastro Numero %d", i);

                    gotoxy(02,8);
                    printf("1-Idade(Minimo 18 - Maximo 140): ");
                    
                    gotoxy(02,10);
                    printf("2-Salario(minimo 1.200,00): ");
                    
                    gotoxy(02,12);
                    printf("3-Sexo (M ou F): ");

                    gotoxy(02,14);
                    printf("4-Cancelar");
                    
                    gotoxy(35,8);
                    scanf("%d", &User[i].idade);
                    if (User[i].idade==4){
                        break;
                    }
                    
                    if (User[i].idade<18 || User[i].idade>140 ){                       
                        do{
                            gotoxy(02,24);
                            printf("Informacao (Idade) invalida, pressione enter para continuar");
                            getch();
                            gotoxy(02,24);
                            printf("                                                            ");
                            gotoxy(35,8);
                            printf("                                            ");
                            gotoxy(35,8);
                            scanf("%d", &User[i].idade);
                        } while (User[i].idade<18 || User[i].idade>140);
                    }
                
                    gotoxy(30,10);
                    scanf("%d", &User[i].salario);
                    if(User[i].salario ==4){
                        break;
                    }

                    if (User[i].salario < 1200){                       
                        do {
                            gotoxy(02,24);
                            printf("Informacao (Salario) invalida, pressione enter para continuar");
                            getch();
                            gotoxy(02,24);
                            printf("                                                             ");
                            gotoxy(30,10);
                            printf("                                                 ");
                            gotoxy(30,10);
                            scanf("%d", &User[i].salario);
                        } while( User[i].salario<1200);
                    }
                
                    gotoxy(19,12);
                    scanf(" %c", &User[i].sexo);
                    if(User[i].sexo ==4){
                        break;
                    }
                    if (User[i].sexo != 'M' && User[i].sexo != 'F'){                       
                        do {                           
                            gotoxy(02,24);
                            printf("Informacao (Sexo) invalida, pressione enter para continuar");
                            getch();
                            gotoxy(02,24);
                            printf("                                                          ");
                            gotoxy(19,12);
                            printf("                                                          ");
                            gotoxy(19,12);
                            scanf(" %c", &User[i].sexo);
                        }while(User[i].sexo != 'M' && User[i].sexo != 'F');
                    }

                    gotoxy(02,24);
                    printf("Deseja cadastrar mais pessoas? (1-SIM  2-Nao): ");
                    gotoxy(50,24);
                    scanf("%d",&resp);
                    
                    if (resp != 1 && resp != 2){
                        gotoxy(02,24);
                        printf("Resposta invalida, digite 1 para continuar, ou 2 para sair");
                        getch();
                        gotoxy(50,24);
                        printf("       ");
                        gotoxy(50,24);
                        scanf("%d",&resp);
                    } else if (resp == 2){
                        break;
                    }
                }
                
            } while (resp == 1 && i<5);   
        
        }

        if (op == 2){
            do{
                system("Cls");
                tela();
                gotoxy(02,06);
                printf("Qual cadastro voce deseja consultar? ");
                gotoxy(02,07);
                printf("0-Cancelar");
                gotoxy(39,06);
                scanf("%d", &j);
                i = j;
                
                gotoxy(02,8);
                printf("Cadastro %d\n",i);
                gotoxy(02,9);
                printf("Idade: %d\n",User[i].idade);
                gotoxy(02,10);
                printf("Salario: %d\n",User[i].salario);
                gotoxy(02,11);
                printf("sexo: %c\n",User[i].sexo);
                gotoxy(02,12);
                getch();
            } while (j != 0);
        }

        if (op == 3){
            gotoxy(28,12);
            printf("Encerrando programa, pressione C");
            getch();
            break;
        }

    }while(op !=3);
    gotoxy(00,27);
}


    }while(op !=3);
    gotoxy(00,27);
}
