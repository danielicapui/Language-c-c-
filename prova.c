#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <math.h>
//estrutura aluno com os campos:Estado,Idade,Sexo.
typedef struct
{
    char estado[50];
    int idade;
    char sexo[3];
}Pessoa;

typedef struct 
{
    int max;
    int min;
    int vizinhos_maior;
}Dados;

typedef struct 
{
    char nome[50];
    int pontuacoes;
}Time;

typedef struct 
{
    Time time1;
    Time time2;
    int gols1;
    int gols2;
}Partida;



Dados setDados(int max,int min, int vizinhos_maior)
{
    Dados dados;
    dados.max=max;
    dados.min=min;
    dados.vizinhos_maior=vizinhos_maior;
    return dados; 
}

//1)b)
int matchPessoa(int tam,Pessoa pessoa[tam])
{
    char state[] ="Bahia";
    char sex[]="F";
    int years=18, match=0;
    for(int i=0;i<tam;i++)
    {
        //função que compara o conteudo da string e retorna 0 se forem iguais.
        if(strcmp(pessoa[i].estado,state)==0 && pessoa[i].idade>years && strcmp(pessoa[i].sexo,sex)==0)
        {
            match++;
        }
    }
    return match;
}

//Questão 1)a)
bool isMaior(int a,int b)
{
    if (a>b)
    {
        return true;
    }   
    else
    {
        return false;
    }
}
bool isMenor(int num,int min)
{
    if (num<min)
        return true;
    else
        return false;
}
void mostrarVetor(int tam,int vetor[tam])
{
    for (int i=0;i<tam;i++)
    {
        printf("numero %d: %d\n",i,vetor[i]);
    }
}
void procurarVetor (int tam,int vetor[tam],Dados *dados)
{
    mostrarVetor(tam,vetor);
    for(int i=0;i<tam;i++)
    {
        if (isMaior(vetor[i],dados->max)==true)
        {
            dados->max=vetor[i];
        }
        else
        {
            dados->max=dados->max;
        }
        if (isMenor(vetor[i],dados->min)==true)
        {
            dados->min=vetor[i];
        }
        else
        {
            dados->min=dados->min;
        }
        if (i!=tam-1)
            if (vetor[i]<vetor[i+1])
                dados->vizinhos_maior++;
    }
}
//Função para preencher os vetores de struct
void criarPessoa(int tam,Pessoa pessoa[tam])
{
    for(int i=0;i<tam;i++)
    {
        printf("Digite o estado do Pessoa:\n");
        scanf("%s",pessoa[i].estado);
        printf("Digite a idade do Pessoa:\n");
        scanf("%d",&pessoa[i].idade);
        printf("Digite o sexo,F ou M, para a Pessoa:\n");
        scanf("%s",pessoa[i].sexo);
    }
}
//preencher o vetor
void criarVetor(int tam,int vetor[tam])
{
    for(int i=0;i<tam;i++)
    {
        printf("Digite um número inteiro:\n");
        scanf("%d",&vetor[i]);
    }
}
void mostrarDados(Dados dados)
{
    printf("Maximo valor: %d\nMenor valor: %d\nVizinhos maiores: %d\n",dados.max,dados.min,dados.vizinhos_maior);
}
//ordenar vetor
void insertSort(int tam,int vetor[tam])
{
    int t=-1;
    for(int elem=0;elem<tam;elem++)
    {
        int elem_inserido=vetor[elem];
        while (elem>0 && vetor[t+elem]>elem_inserido)
        {
            vetor[elem]=vetor[elem+t];
            elem=elem+t;
        }
        vetor[elem]=elem_inserido;
    }
}

int contarRepetidos(int tam, int vetor[tam])
{
    int repetidos=0;
    for (int i=0;i<tam;i++)
    {
        if (i!=tam-1)
        {
            if (vetor[i]==vetor[i+1])
            {
                repetidos++;
            }
        }
    }
    return repetidos;
}
//Questão 2b
//Função para preencher os vetores de struct
void criarPartida(int tam,Partida partida[tam])
{
    for(int i=0;i<tam;i++)
    {
        Time time1;
        Time time2;
        time1.pontuacoes=0;
        time2.pontuacoes=0;
        printf("Digite o nome do time1:\n");
        scanf("%s",time1.nome);
        partida[i].time1=time1;
        printf("Digite o número de gols do time1:\n");
        scanf("%d",&partida[i].gols1);
        printf("Digite o nome do time2:\n");
        scanf("%s",time2.nome);
        partida[i].time2=time2;
        printf("Digite o número de gols do time2:\n");
        scanf("%d",&partida[i].gols2);
    }
}


bool isWin(int gols1,int gols2)
{
    if (gols1>gols2)
    {
        return true;
    }
    else{
        return false;
    }
}


bool notIn(int tam1,Time time[],char nome[])
{
    for(int i=0;i<tam1;i++)
    {
        if (strcmp(time[i].nome,nome)==0)
        {
            return true;
        }
    }
    return false;   
}
void copiaArray(char nome[50],char nome1[50])
{
    for(int i=0;i<50;i++)
    {
      nome[i]=nome1[i];  
    }
}
void mostrarResultado(int tam,Time time[tam])
{
    int i=tam;
    while(i--)
    {
        printf("Nome: %s Pontos:%d\n",time[i].nome,time[i].pontuacoes);
    }
}

void timeSort(int tam,Time *time)
{
    int i,j;
    Time aux;
    for(i=1;i<tam;i++)
    {
        aux=time[i];
        for(j=i;(j>0) && (aux.pontuacoes<time[j-1].pontuacoes);j--)
        {
            time[j]=time[j-1];
        }
        time[j]=aux;
    }
}
void analiseCampeonato(int tam,Partida partida[tam],int tam1,Time time[tam1])
{
    int pontos=0;
    for(int i=0;i<tam;i++)
    {
        partida[i].time2.pontuacoes;
        if (notIn(tam1,time,partida[i].time1.nome)==false)
        {
            copiaArray(time[i].nome,partida[i].time1.nome);
            time[i].pontuacoes=0;
        }
        if (notIn(tam1,time,partida[i].time2.nome)==false)
        {
            copiaArray(time[i].nome,partida[i].time2.nome);
            time[i].pontuacoes=0;
        }
        
        if(partida[i].gols1==partida[i].gols2)
        {
            pontos=1;
            partida[i].time1.pontuacoes=partida[i].time1.pontuacoes+pontos;
            partida[i].time2.pontuacoes=partida[i].time2.pontuacoes+pontos;
        }
        else
        {
            if (isWin(partida[i].gols1,partida[i].gols2)==true)
            {
                pontos=3;
                partida[i].time1.pontuacoes=partida[i].time1.pontuacoes+pontos;
                printf("%d\n",partida[i].time1.pontuacoes);
            }
            else
            {
                pontos=3;
                partida[i].time2.pontuacoes=partida[i].time2.pontuacoes+pontos;
            }
        }
    }
    for(int i=0;i<tam;i++)
    {
        printf("pontos:%d\npontos2:%d\n",partida[i].time1.pontuacoes,partida[i].time2.pontuacoes);
    }
    //verificar os pontos
    for(int i=0;i<tam1;i++)
    {

        for (int j=0;j<tam;j++)
        {
            if(strcmp(time[i].nome,partida[j].time1.nome)==0)
            {
                time[i].pontuacoes=time[i].pontuacoes+partida[j].time1.pontuacoes;
            }
            if(strcmp(time[i].nome,partida[j].time2.nome)==0)
            {
                time[i].pontuacoes=time[i].pontuacoes+partida[j].time2.pontuacoes;
            }
        }
    }
    timeSort(tam1,time);
    mostrarResultado(tam1,time);
}

void questao1a()
{
    //questão a
    int tam=10;
    int vetor[tam];
    Dados dados=setDados(0,9999999,0);
    criarVetor(tam,vetor);
    procurarVetor(tam,vetor,&dados);
    mostrarDados(dados);
}
void questao1b()
{
    int tam=3;
    Pessoa pessoa[tam];
    criarPessoa(tam,pessoa);
    int match=matchPessoa(tam,pessoa);
    printf("Casos: %d\n",match);
}

void questao2a()
{
    int tam=1000;
    int vetor[tam];
    criarVetor(tam,vetor);
    //mostrarVetor(tam,vetor);
    insertSort(tam,vetor);
    int repetidos=contarRepetidos(tam,vetor);
    //mostrarVetor(tam,vetor);
    printf("Números de números repetidos: %d",repetidos);
}
void questao2b()
{
    int tam=2;
    Partida partida[tam];
    int tam1=4;
    Time time[tam1];
    //teste depois comente.
    char nome[50]="ana";
    char nome1[50]="lucas";
    char nome2[50]="caio";
    char nome3[50]="lucas";
    copiaArray(partida[0].time1.nome,nome);
    partida[0].gols1=0;
    copiaArray(partida[0].time2.nome,nome1);
    partida[0].gols2=1;
    copiaArray(partida[1].time1.nome,nome2);
    partida[1].gols1=4;
    copiaArray(partida[1].time2.nome,nome3);
    partida[1].gols2=5;
    partida[0].time1.pontuacoes=0;
    partida[0].time2.pontuacoes=0;
    partida[1].time1.pontuacoes=0;
    partida[1].time2.pontuacoes=0;
    //fim de teste
    //criarPartida(tam,partida);
    analiseCampeonato(tam,partida,tam1,time);
}
int main()
{
    int q;
    printf("digite numero letra para mostrar resolução da questão: \n");
    scanf("%d",&q);
    if (q==1)
    {
       questao1a();
    }
    else if (q==2)
    {
        questao1b();
    }
    else if (q==3)
    {
        questao2a();
    }
    else if (q==4)
    {
        questao2b();
    }
    return 0;  
   //use prova.c<entrada.in>saida.txt
   //para salvar os dados de saida no arquivo de texto 
}
