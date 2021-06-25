#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
typedef struct
{
    char nome[50];
    float peso;

}Pessoa;
void copiaArray(char nome[50],char nome1[50])
{
    for(int i=0;i<50;i++)
    {
      nome[i]=nome1[i];  
    }
}
Pessoa setPessoa(char nome[50],float peso)
{ 
    Pessoa p;
    copiaArray(p.nome,nome);
    p.peso=peso;   
    return p; // retorna a struct contendo os dados passados por parâmetro
}
float mediaPeso(int tam,Pessoa pessoa[tam])
{
    float soma=0;
    for(int i=0;i<tam;i++)
    {
        soma=soma+pessoa[i].peso;
    }
    return (soma/tam);
}
void imprimePessoa(Pessoa P) // declara o parâmetro como uma struct
{
  printf("Nome: %s\nPeso: %.2f\n", P.nome, P.peso);
}
void pessoaAcima(int tam,Pessoa pessoa[tam],int c,int index[c])
{
    for(int i=0;i<c;i++)
    {
        imprimePessoa(pessoa[index[i]]);
    }
}
void pesoAcima(float media,int tam, Pessoa pessoa[tam])
{
    int peso_acima=0;
    int index[tam];
    int c=0;
    for(int i=0;i<tam;i++)
    {
        if(pessoa[i].peso>media)
        {
            peso_acima++;
            index[c]=i;
            c++;
        }
    }
    printf("Numeros de pessoas acima do peso: %d\n",peso_acima);
    pessoaAcima(tam,pessoa,c,index);
}

void criarPessoa(int tam,Pessoa pessoa[tam])
{
    float peso;
    char nome[50];
    for(int i=0;i<tam;i++)
    {
        printf("Digite o nome da pessoa:\n");
        scanf("%s",nome);
        printf("Digite o peso da pessoa:\n");
        scanf("%f",&peso);
        pessoa[i]=setPessoa(nome,peso);
    }
}

int main()
{
    //altere tam para mudar o número de pessoas;
    int tam=5;
    Pessoa pessoa[tam];
    criarPessoa(tam,pessoa);
    float media=mediaPeso(tam,pessoa);
    pesoAcima(media,tam,pessoa);
    return 0;
}