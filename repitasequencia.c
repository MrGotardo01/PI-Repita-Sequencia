#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>


#define CONTROL_LINHA 30  // Constante de controle do numero de linhas do menu
#define CONTROL_LINHA2 35 // Constante de controle do numero de linhas do menu

#define C_RED       "\033[31m" // Constante que faz os caracteres serem vermelho
#define C_GREEN     "\033[32m" // Constante que faz os caracteres serem verde
#define C_YELLOW    "\033[33m" // Constante que faz os caracteres serem amarelo
#define C_BLUE      "\033[34m" // Constante que faz os caracteres serem azul
#define C_MAGENTA   "\033[35m" // Constante que faz os caracteres serem roxo
#define C_RESET  "\033[0m" // Constante que faz os caracteres voltarem para a coloração padrão do CMD;

//variaveis globais
int cont = 1, flag = 0, tempo = 2000; //cont é o contador de rodadas do jogo, tempo é o que define a velocidade de aparecimento e desparecimento das cores
int melhorMarca[3]; //vetor para guardar a maior pontuacao do jogador
char cores[5][10] ={"VERMELHO", "AMARELO", "ROXO", "VERDE", "AZUL"}; //matriz que define o nome das cores
char respJog[5], respSeq[5]; //string respJog armazena as respostas do jogador e string respSeq armazena as respostas da sequencia
char respJN;
//prototipo de funcoes
void jogo();
void sequencia();

int tecla(){ // função que verifica se alguma tecla esta sendo precionada
    int varTecla;
    while (1){
        if (kbhit()){            // caso alguma tecla esteja sendo precionada a função irar armanezar o valor da tecla na variavel
            varTecla = getch(); // getch captura um caractere da entrada
            return varTecla;
        }
    }
}

void linha_Superior_Menu(){ // função que cria linha superior do menu
    int i;
    printf("\t\t%c", 201);
    for (i = 0; i < CONTROL_LINHA; i++){
        printf("%c", 205);
    }
    printf("%c\n", 187);
}

void linha_Rodape_Menu(){ // função que cria linha rodape do menu
    int i;
    printf("\t\t%c", 200);
    for (i = 0; i < CONTROL_LINHA; i++){
        printf("%c", 205);
    }
    printf("%c\n", 188);
}

void linha_Central_Menu(){ // função que cria linha do meio do menu
    int i;
    printf("\t\t%c", 204);
    for (i = 0; i < CONTROL_LINHA; i++){
        printf("%c", 205);
    }
    printf("%c\n", 185);
}

void jNovamente_Linha_Cima(){ // função que cria linha superior do menu de jogar novamente
    int i;
    printf("\t%c", 218);
    for (i = 0; i < CONTROL_LINHA2; i++){
        printf("%c", 196);
    }
    printf("%c\n", 191);
}

void jNovamente_Linha_Baixo(){ // função que cria linha inferior do menu de jogar novamente
    int i;
    printf("\t%c", 192);
    for (i = 0; i < CONTROL_LINHA2; i++){
        printf("%c", 196);
    }
    printf("%c\n", 217);
}

void menu(){ // função que faz o menu princial do jogo
    int c;
    int lugar = 0;
    system("cls");            // limpa tela do console
    linha_Superior_Menu();
    printf("\t\t%c       REPITA A SEQUENCIA     %c\n", 186, 186);
    linha_Central_Menu();
    printf("\t\t%c          -> Jogar            %c\n", 186, 186);
    printf("\t\t%c             Sair             %c\n", 186, 186);
    linha_Rodape_Menu();
    printf("\n\n\n\t*Use as setas do teclado para movimentacao das opcoes\n");
    printf("\t*Utilize o Enter para escolher uma das opcoes\n");

    while (1){ // laço de repetição infinito
        if (kbhit()){ // se alguma tecla for precionada ele entrar dentro do if
            system("cls");
            c = tecla();   // variavel c recebe função criada anteriormente

            if (c == 80){ //apertou para baixo
                lugar++;       // variavel receber +1 no seu valor
                if (lugar > 1){ // se o lugar for maior que 2
                    lugar = 0; // ele volta para posição inicial menu
                }
            }
            if (c == 72){//apertou para cima
                lugar--;       // variavel recebe -1 no seu valor
                if (lugar < 0){ // se o lugar for menor que 0
                    lugar = 1; // ele volta para ultima posição do menu
                }
            }
            if (c == 75){//apertou para direita
                lugar++;       // variavel receber +1 no seu valor
                if (lugar > 1){ // se o lugar for maior que 2
                    lugar = 0; // ele volta para posição inicial menu
                }
            }
            if (c == 77){//apertou para esquerda
                lugar--;       // variavel recebe -1 no seu valor
                if (lugar < 0){ // se o lugar for menor que 0
                    lugar = 1; // ele volta para ultima posição do menu
                }
            }
            if (c == 13) {//apertou [enter]
                if (lugar == 0){// se o enter(opçao de escolha) for apertado quando o menu estiver em "jogar" -  inicia o jogo
                    linha_Superior_Menu();
                    printf("\t\t%c       INICIANDO O JOGO!      %C\n", 186, 186);
                    linha_Rodape_Menu();
                    Sleep(500);            // sistema espera 2,8s antes de continuar
                    system("cls");
                    jogo();
                    break;
                }

                else if (lugar == 1){// se o enter(opçao de escolha) for apertado quando o menu estiver em "sair" - inicia a função de sair
                    system("cls");
                    linha_Superior_Menu();
                    printf("\t\t%c       SAINDO DO PROGRAMA!    %C\n", 186, 186);
                    linha_Rodape_Menu();
                    Sleep(500);            // espera 1 s
                    exit(0);                // fecha o programa
                }
            }
            if (lugar == 0){ // apos detectar a tecla apertada o programa imprime o local aonde a seta que demonstra a opçao de escolha esta
                linha_Superior_Menu();
                printf("\t\t%c       REPITA A SEQUENCIA     %c\n", 186, 186);
                linha_Central_Menu();
                printf("\t\t%c          -> Jogar            %c\n", 186, 186);
                printf("\t\t%c             Sair             %c\n", 186, 186);
                linha_Rodape_Menu();
                printf("\n\n\n\t*Use as setas do teclado para movimentacao das opcoes\n");
                printf("\t*Utilize o Enter para escolher uma das opcoes\n");
            }
            if (lugar == 1){// apos detectar a tecla apertada o programa imprime o local aonde a seta que demonstra a opçao de escolha esta
                linha_Superior_Menu();
                printf("\t\t%c       REPITA A SEQUENCIA     %c\n", 186, 186);
                linha_Central_Menu();
                printf("\t\t%c             Jogar            %c\n", 186, 186);
                printf("\t\t%c          -> Sair             %c\n", 186, 186);
                linha_Rodape_Menu();
                printf("\n\n\n\t*Use as setas do teclado para movimentacao das opcoes\n");
                printf("\t*Utilize o Enter para escolher uma das opcoes\n");
            }
        }
    }
}

void opcaoE(){ // função que mostra as opções de escolha de cores do jogo.

    printf("\tDigite a sequencia de cores que apareceram, sendo:\n ");
    printf("\tV - VERMELHO\n");
    printf("\tA - AMARELO\n");
    printf("\tR - ROXO\n");
    printf("\tD - VERDE\n");
    printf("\tZ - AZUL\n");
}

void sequencia(){ //funcao que gera aleatoriamente as cores do jogo

	int i;
	int op; //variavel usada para ser o meio de geração das cores aleatoriamente
    char letra; //variavel que define a opção de escolha sendo a respectiva letra para confrontar com a resposta do usuario

    for(i=0; i<5; i++){

        respSeq[5] = '\0';
        srand(time(NULL));
        op = (rand()%5);

        switch(op){
            //cor vermelha
        case 0:
            printf(C_RED "\t\t\t:::: %s :::: " C_RESET, cores[0]);
            Beep(500,1000);
            tempo;
            system("cls");
            printf("Rodada %d\n", cont);
            linha_Superior_Menu();
            printf("\t\t%c       REPITA A SEQUENCIA     %c\n", 186, 186);
            linha_Rodape_Menu();
            letra = 'V';
            respSeq[i] = letra;
        break;
            //cor amarela
        case 1:
            printf(C_YELLOW  "\t\t\t:::: %s :::: " C_RESET , cores[1]);
            Beep(1000,1000);
            tempo;
            system("cls");
            printf("Rodada %d\n", cont);
            linha_Superior_Menu();
            printf("\t\t%c       REPITA A SEQUENCIA     %c\n", 186, 186);
            linha_Rodape_Menu();
            letra = 'A';
            respSeq[i] = letra;
        break;
            //cor roxo
        case 2:
            printf(C_MAGENTA  "\t\t\t:::: %s :::: " C_RESET , cores[2]);
            Beep(1500,1000);
            tempo;
            system("cls");
            printf("Rodada %d\n", cont);
            linha_Superior_Menu();
            printf("\t\t%c       REPITA A SEQUENCIA     %c\n", 186, 186);
            linha_Rodape_Menu();
            letra = 'R';
            respSeq[i] = letra;
        break;
            //cor verde
        case 3:
            printf(C_GREEN "\t\t\t:::: %s :::: " C_RESET , cores[3]);
            Beep(2000,1000);
            tempo;
            system("cls");
            printf("Rodada %d\n", cont);
            linha_Superior_Menu();
            printf("\t\t%c       REPITA A SEQUENCIA     %c\n", 186, 186);
            linha_Rodape_Menu();
            letra = 'D';
            respSeq[i] = letra;
        break;
        //cor azul
        case 4:
            printf(C_BLUE "\t\t\t:::: %s :::: " C_RESET , cores[4]);
            Beep(2500,1000);
            tempo;
            system("cls");
            printf("Rodada %d\n", cont);
            linha_Superior_Menu();
            printf("\t\t%c       REPITA A SEQUENCIA     %c\n", 186, 186);
            linha_Rodape_Menu();
            letra = 'Z';
            respSeq[i] = letra;
        break;
        }
        fflush(stdin);
    }
    system("cls");
}

void jogo(){ //funcao que opera o jogo

    int i, j;

    for(cont; flag !=1; cont++){

        while(respJN == 'S'){

            if(melhorMarca[0] >= melhorMarca[1]){
                printf("Sua melhor marca foi: Rodada %d", melhorMarca[0]);
                printf("\n");
            }
            else if(melhorMarca[0] < melhorMarca[1]){
                printf("Sua melhor marca foi: Rodada %d", melhorMarca[1]);
                printf("\n");
            }
            melhorMarca[1] = melhorMarca[0];

            break;
        }
        melhorMarca[0] = cont;

        printf("Rodada %d\n", cont); // contador do numero de rodadas
        linha_Superior_Menu();
        printf("\t\t%c       REPITA A SEQUENCIA     %c\n", 186, 186);
        linha_Rodape_Menu();

        sequencia();

        printf("Rodada %d\n", cont);
        linha_Superior_Menu();
        printf("\t\t%c       REPITA A SEQUENCIA     %c\n", 186, 186);
        linha_Rodape_Menu();
        opcaoE();

        for(i = 0; i<5; i++){
            printf("\t%da cor: ", i+1,  respJog[i]);
            scanf("%c", &respJog[i]);
            respJog[i] = toupper(respJog[i]); //transforma a resposta do jogador para uma letra maiuscula
            fflush(stdin);

            if(respJog[i] != respSeq[i]){
                Beep(900,2000);
                printf("\tVoce errou! \n");
                printf("\tA resposta correta era: \n");

                for(j = 0 ; respSeq[j]!='\0'; j++){
                    switch(respSeq[j]){
                    //cor vermelha
                    case 'V':
                        printf(C_RED ":::: %s :::: " C_RESET, cores[0]);
                        Beep(500,1000);
                    break;
                    //cor amarela
                    case 'A':
                        printf(C_YELLOW  ":::: %s :::: " C_RESET , cores[1]);
                        Beep(1000,1000);
                    break;
                    //cor roxo
                    case 'R':
                        printf(C_MAGENTA  ":::: %s :::: " C_RESET , cores[2]);
                        Beep(1500,1000);
                    break;
                    //cor verde
                    case 'D':
                        printf(C_GREEN ":::: %s :::: " C_RESET , cores[3]);
                        Beep(2000,1000);
                    break;
                    //cor azul
                    case 'Z':
                        printf(C_BLUE ":::: %s :::: " C_RESET , cores[4]);
                        Beep(2500,1000);
                    break;
                    }
                    tempo;
                }
                printf("\n\n");
                printf("\tPontuacao: Voce foi ate a rodada %d", cont);

                Sleep(3000);
                flag = 1;
                break;
            }

            if(respJog[i]=='V' || respJog[i]=='v'){
                Beep(500,1000);
                printf(C_RED "\t%s " C_RESET, cores[0]);
            }
            else if(respJog[i]=='A' || respJog[i]=='a'){
                Beep(1000,1000);
                printf(C_YELLOW  "\t%s " C_RESET , cores[1]);
            }
            else if(respJog[i]=='R' || respJog[i]=='r'){
                Beep(1500,1000);
                printf(C_MAGENTA  "\t%s " C_RESET , cores[2]);
            }
            else if(respJog[i]=='D' || respJog[i]=='d'){
                Beep(2000,1000);
                printf(C_GREEN "\t%s " C_RESET , cores[3]);
            }
            else if(respJog[i]=='Z' || respJog[i]=='z'){
                Beep(2500,1000);
                printf(C_BLUE "\t%s " C_RESET , cores[4]);
            }
            printf("\n");
        }
    while(respJog[i] == respSeq[i]){
        Beep(2200,2500);
        break;
    }

    system("cls");
    tempo = tempo - 100;
    }
}

void jogar_Novamente(){ // função para jogar novamente
    jNovamente_Linha_Cima();
    printf("\t%c   Deseja jogar novamente ? [S/N]  %c\n", 179, 179);
    jNovamente_Linha_Baixo();
    respJN = getch();
    respJN = toupper(respJN);      // transforma a resposta para uma letra maiúscula

    Sleep(600);
    if (respJN != 'S' && respJN != 'N'){
        system("cls");
        jNovamente_Linha_Cima();
        printf("\t%c         Resposta invalida         %c\n", 179, 179);
        jNovamente_Linha_Baixo();
        jogar_Novamente();        //chama a função jogar_Novamente caso a resposta seja invalida para fazer uma nova escolha
    }
}


int main(){ //função principal

    do{ //entrar em loop se o jogador escolher jogar novamente

        system("cls");    // limpa a tela do console
        menu();           // função menu é iniciada tendo inicio a cadeia de eventos que leva ao jogo
        flag = 0;
        tempo = 500;
        cont = 1;
        Sleep(500);       // progama esperar 0,5s antes de motrar o resultado

        jogar_Novamente(); // função de jogar novamente
    }while (respJN == 'S'); // se a resposta for sim ele entrar em loop iniciando o menu novamente

    system("cls");
    linha_Superior_Menu();
    printf("\t\t%c       SAINDO DO PROGRAMA!!   %C\n", 186, 186);
    linha_Rodape_Menu();
    Sleep(500);             // programa espera 0,5s antes de continuar
    exit(0);                // programa fecha

    return 0;
}
