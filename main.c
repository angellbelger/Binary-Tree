#include<stdio.h>
#include<stdlib.h>

struct no
{
    int chave;
    struct no *esquerda;
    struct no *direita;
};

//retorna um novo nó com o valor dado
struct no *getNo(int val)
{
    struct no *novoNo;

    novoNo = malloc(sizeof(struct no));

    novoNo->chave = val;
    novoNo->esquerda  = NULL;
    novoNo->direita = NULL;

    return novoNo;
}

//insere nós na árvore de busca binária
struct no *insertNo(struct no *root, int val)
{
     if(root == NULL)
         return getNo(val);

     if(root->chave < val)
         root->direita = insertNo(root->direita,val);

     if(root->chave > val)
         root->esquerda = insertNo(root->esquerda,val);

     return root;
}

//percurso de pré-ordem da árvore binária
void preordem(struct no *root)
{
    if(root == NULL)
        return;

    printf("%d ",root->chave);

    preordem(root->esquerda);

    preordem(root->direita);
}

int main()
{
   struct no *root = NULL;
   int data;
   char option;

   printf("Hello, world.");

   do
   {
       printf("\n---------------------------\n");
       printf("\nDigite um numero: ");
       scanf("%i", &data);
       root = insertNo(root, data);
       printf("\nDigite \033[36m'Y'\033[m para continuar ou \033[31m'N'\033[m para encerrar e ver o resultado.");
       printf("\nDigite: [ \033[36mY\033[34m\033[m | \033[31mN\033[34m\033[m ]: ");
       scanf(" %c", &option);
   } while ( option != 'n');

    printf("\nResultado em Pre-ordem:\033[36m ");
    preordem(root);
    printf("\n\033[m\033[31mPrograma finalizado.\033[m\n"); 

   return 0;
}