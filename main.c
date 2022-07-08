#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

//retorna um novo nó com o valor dado
struct node *getNode(int val)
{
    struct node *newNode;

    newNode = malloc(sizeof(struct node));

    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

//insere nós na árvore de busca binária
struct node *insertNode(struct node *root, int val)
{
     if(root == NULL)
         return getNode(val);

     if(root->key < val)
         root->right = insertNode(root->right,val);

     if(root->key > val)
         root->left = insertNode(root->left,val);

     return root;
}

//percurso de pré-ordem da árvore binária
void preorder(struct node *root)
{
    if(root == NULL)
        return;

    printf("%d ",root->key);

    preorder(root->left);

    preorder(root->right);
}

int main()
{
   struct node *root = NULL;
   int data;
   char option;

   printf("Hello, world.");

   do
   {
       printf("\n---------------------------\n");
       printf("\nDigite um numero: ");
       scanf("%i", &data);
       root = insertNode(root, data);
       printf("\nDigite \033[36m'Y'\033[m para continuar ou \033[31m'N'\033[m para encerrar e ver o resultado.");
       printf("\nDigite: [ \033[36mY\033[34m\033[m | \033[31mN\033[34m\033[m ]: ");
       scanf(" %c", &option);
   } while ( option != 'n');

    printf("\nResultado em Pre-ordem:\033[36m ");
    preorder(root);
    printf("\n\033[m\033[31mPrograma finalizado.\033[m\n"); 

   return 0;
}