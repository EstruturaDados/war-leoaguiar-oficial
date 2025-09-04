/* ==============================================
     PROJETO WAR - NÍVEL BASÍCO

    ===== OBJETIVO =====
    +Criar 5  espaços (Territórios)
    +Criar um Vetor (Armazenamento)
    +Usuário inserir os dados
    +Exibir a lista completa de Territórios +inf
    ===== NESCESSÁRIO CONTER =====
    +Nome
    +Cor
    +Tropa
   ============================================== */ 

   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h> /* + Para strcspn() + */

/* ====== CONSTANTES GLOBAIS ====== */

#define MAX_TERRITORIOS 5
#define TAM_STRING 100

/* ====== ESTRUTURA ====== */
struct War
{
    char nome[30], cor[10];
    int tropas;
};

/* ====== LIMPEZA DO BUFFER DE ENTRADA ====== */

void limparBufferEntrada(){
    int c;
    while ((c = getchar())!= '\n' && c != EOF);
}

/* ====== FUNÇÃO PRINCIPAL (main) ====== */

int main(){

    struct War biblioteca[MAX_TERRITORIOS];
    int totalTerritorios = 0, opcao;

    /* ====== MENU DO GAME ====== */

    do{
        printf("=========================================\n");
        printf("               WAR GAME\n");
        printf("=========================================\n");
        printf("1 - Cadastar novo território.\n");
        printf("2 - Listar todos territórios.\n");
        printf("0 - Sair.\n");
        printf("=========================================\n");
        printf("Escolha: ");

    /* ====== LEITURA DA OPÇÃO DO USUÁRIO ====== */
    scanf("%d", &opcao);
    limparBufferEntrada(); /* LIMPA O '\n' DEIXADO PELO SCANF */

    /* ====== PROCESSAMENTO DA OPÇÃO ======*/

    switch (opcao)
    {
    case 1: /* ====== CADASTRO TERRITORIAL ======*/
    for (; totalTerritorios < MAX_TERRITORIOS; totalTerritorios++)
    {
    
        printf(" + CADASTRO DE TERRITÓRIO +\n\n");

        if (totalTerritorios < MAX_TERRITORIOS){
            printf("Digite o nome do território: ");
            fgets(biblioteca[totalTerritorios].nome, TAM_STRING, stdin);

            printf("Digite o nome da cor: ");
            fgets(biblioteca[totalTerritorios].cor, TAM_STRING, stdin);

            biblioteca[totalTerritorios].nome[strcspn(biblioteca[totalTerritorios].nome, "\n")] = '0';
            biblioteca[totalTerritorios].cor[strcspn(biblioteca[totalTerritorios].cor, "\n")] = '0';

            printf("Digite as tropas: ");
            scanf("%d", &biblioteca[totalTerritorios].tropas);
            limparBufferEntrada();

            printf("\nTerritório cadastrado com sucesso!\n");
        }else{
                printf("Biblioteca cheia! Não é possível cadastrar mais livros.\n");
            }
            
            printf("\nPressione 'Enter' para continuar.\n");
            getchar();
        }
        break;

        case 2: /* ====== LISTAGEM DE TERRITÓRIOS ======*/

        printf(" + LISTA DE TERRITÓRIO +\n\n");

        if (totalTerritorios == 0){
            printf("Nenhum território cadastrado ainda.\n");
        } else {
            for (int i = 0; i < totalTerritorios; i++){
                 printf("=========================================\n");
                 printf("Território %d\n", i + 1);
                 printf("Nome: %s\n", biblioteca[i].nome);
                 printf("Cor: %s\n", biblioteca[i].cor);
                 printf("Tropas: %d\n", biblioteca[i].tropas);
            }
            
            printf("=========================================\n");
        }

        printf("Pressione 'Enter' para continuar.");
        getchar();

        case 0: /* ====== SAIR DO SISTEMA ======*/
        printf("\nFechando o sistema.");
        break;
        
    
    default:/* ====== OPÇÃO INVÁLIDA ====== */
        printf("\nOpção inválida! Tente novamente.");
        printf("\nPressione 'Enter' para continuar.");
        break;
    
    }

    } while (opcao != 0);

    return 0;
}

 