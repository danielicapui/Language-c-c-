#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
typedef struct
{
    std::string data,projeto,membro1,membro2,membro3;
    int hora;
}Banca;
bool isWorking(Banca aux,std::string nome,std::vector<Banca>& banca)
{
    if (banca.empty()==true)
    {
            return false;
    }
    for(int i=0;i<banca.size();i++)
    {
        if ((strcasecmp(banca[i].membro1.c_str(),nome.c_str())==0 || strcasecmp(banca[i].membro2.c_str(),nome.c_str())==0 || strcasecmp(banca[i].membro3.c_str(),nome.c_str())==0) && (banca[i].data==aux.data && banca[i].hora==aux.hora))
        {
            std::cout<<"Esse membro está ocupado em outra banca, com o nome de projeto: "<<banca[i].projeto<<std::endl;
            std::cout<<"Digite outro nome, por favor!"<<std::endl;
            return true;
        }
    }
    return false;
}
std::string addMembro(Banca aux,std::vector<Banca>& banca)
{
    std::string membro;
    do{
        std::cout<<"Digite um membro válido:"<<std::endl;
        std::cin>>membro;
    }while(isWorking(aux,membro,banca)!=false);
    return membro;
}
Banca criarBanca(std::vector<Banca>& banca)
{
    Banca aux;
    std::cout<<"Formato de data 'dd//mm//yyyy' de horário inteiros '0 a 23', membros 'nome',projeto 'nome'"<<std::endl;
    std::cout<<"Digite a data:"<<std::endl;
    std::cin>>aux.data;
    std::cout<<"Digite a hora:"<<std::endl;
    std::cin>>aux.hora;
    std::cout<<"Digite o nome do projeto:"<<std::endl;
    std::cin>>aux.projeto;
    aux.membro1=addMembro(aux,banca);
    aux.membro2=addMembro(aux,banca);
    aux.membro3=addMembro(aux,banca);
    return aux;
}
void bancaId(int id,Banca banca)
{
    std::cout<<"-------------------------------"<<std::endl;
    std::cout<<"Mostrando as informações para a banca!"<<std::endl;
    std::cout<<"Banca id:"<<id<<std::endl;
    std::cout<<"projeto nome:"<<banca.projeto<<std::endl;
    std::cout<<"Data:"<<banca.data<<std::endl;
    std::cout<<"Hora:"<<banca.hora<<std::endl;
    std::cout<<"Membro1:"<<banca.membro1<<std::endl;
    std::cout<<"Membro2:"<<banca.membro2<<std::endl;
    std::cout<<"Membro3:"<<banca.membro3<<std::endl;
    std::cout<<"------------------------"<<std::endl;
}
void mostrarBancas(std::vector<Banca>& banca)
{
    std::cout<<banca.size()<<"Bancas cadastradas!"<<std::endl;
    for(int i=0;i<banca.size();i++)
    {
       bancaId(i,banca[i]);
    }
}
int getId(std::string projeto,std::vector<Banca>& banca)
{
    if(!banca.empty())
    {
        for(int i=0;i<banca.size();i++)
        {
            if (strcasecmp(banca[i].projeto.c_str(),projeto.c_str())==0)
            {
                return i;
            }
        }
        std::cout<<"Projeto não encontrado!"<<std::endl;
    }
    return -1;
}
bool isValid(Banca aux,std::vector<Banca>& banca)
{
    bool a=isWorking(aux,aux.membro1,banca);
    bool b=isWorking(aux,aux.membro2,banca);
    bool c=isWorking(aux,aux.membro3,banca);
    if (a==false && b==false && c==false)
    {
        return true;
    }
    else
    {
        std::cout<<"Algum membro está trabalhando nessa data e horário"<<std::endl;
        return false;
    }
}
Banca modificarBanca(int id,std::vector<Banca>& banca)
{
    bancaId(id,banca[id]);
    int op;
    Banca aux=banca[id];
    std::cout<<"O que deseja alterar?\n"<<"1 projeto_nome.\n"<<"2 membros\n"<<"3 data e hora"<<std::endl;
    switch (op)
    {
        case 1:
            std::cout<<"Digite o novo nome do projeto:"<<std::endl;
            std::cin>>aux.projeto;
            std::cout<<"Nome mudado com sucesso"<<std::endl;
            break;
        case 2:
            std::cout<<"Digite o novo nome do membro1:"<<std::endl;
            aux.membro1=addMembro(aux,banca);
            std::cout<<"Digite o novo nome do membro2:"<<std::endl;
            aux.membro2=addMembro(aux,banca);
            std::cout<<"Digite o novo nome do membro3:"<<std::endl;
            aux.membro3=addMembro(aux,banca);
            std::cout<<"Membros mudado com sucesso!"<<std::endl;
            break;
        case 3:
            do{
                std::cout<<"Digite a data:"<<std::endl;
                std::cin>>aux.data;
                std::cout<<"Digite a hora:"<<std::endl;
                std::cin>>aux.hora;
            }while(isValid(aux,banca)!=true);
            break;
    }
    return aux;
}
int menu(std::vector<Banca>& banca)
{
    int op,id;
    std::string inu;
    while(true)
    {
        std::cout<<"Digite 1 para cadastrar uma banca:\n"<<"Digite 2 para remover uma banca por nome de projeto ou id:\n"<<"Digite 3 para mostrar as bancas\n"<<"Digite 4 para modificar uma banca por id:\n"<<"Digite 5 para remover uma banca por id:\n"<<"Digite 666 para terminar o programa:\n"<<std::endl;
        std::cin>>op;
        switch (op)
        {
            case 1:
                banca.push_back(criarBanca(banca));
                break;
            case 2:
                std::cout<<"Digite o nome do projeto que deseja remover:"<<std::endl;
                std::cin>>inu;
                id=getId(inu,banca);
                if (!banca.empty() && id!=-1)
                {
                    banca.erase(banca.begin()+id);
                }
                break;
            case 3:
                mostrarBancas(banca);
                break;
            case 4:
                std::cout<<"Digite o id que deseja modificar:"<<std::endl;
                std::cin>>id;
                banca[id]=modificarBanca(id,banca);
                break;
            case 5:
                std::cout<<"Digite o id que deseja remover:"<<std::endl;
                std::cin>>id;
                if (banca.empty()!=true && (id>=0) && (id<=banca.size()-1))
                {
                    banca.erase(banca.begin()+id);
                    std::cout<<"Banca excluída com sucesso!"<<std::endl;
                }
                break;
            case 666:
                std::cout<<"Obrigado por utilizar o software!"<<std::endl;
                return 0;

        }
    }
}
int main()
{

    std::vector<Banca>banca;
    menu(banca);
    return 0;
}
