#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <limits>
using namespace std;
int cont=0;
int quantA=0;
class Data
{
private:
int dia;
int mes;
int ano;
public:
void setDia(int dia)
{
  this->dia=dia;
}
void setMes(int mes)
{
  this->mes=mes;
}
void setAno(int ano)
{
  this->ano=ano;
}
int getDia()
{
  return dia;
}
int getMes()
{
  return mes;
}
int getAno()
{
  return ano;
}
bool dataValida(int dia, int mes, int ano)
{
  // ver se a data colocada pode ser colocada
  if (ano < 0 || mes < 1 || mes > 12 || dia < 1) 
    {
      return false; 
    }
    int diasNoMes;
    if (mes == 2) 
    {
       if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) 
        {
          diasNoMes = 29;
        } 
       else 
        {
          diasNoMes = 28;
        }
    } 
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) 
      {
        diasNoMes = 30;
      }
      else 
      {
        diasNoMes = 31;
      }
    return dia <= diasNoMes;
}
void lerData()
{
  // tipo printf(cout) e scanf(cin) paar vc colocar 
  bool ehvalida=false;
  while(!ehvalida)
    {
      cout<<"Digite o dia: ";
      cin>>dia;
      cout<<"Digite o mes: ";
      cin>>mes;
      cout<<"Digite o ano: ";
      cin>>ano;
      if (dataValida(dia, mes, ano))
        {
          ehvalida=true;
        }
      else
      {
        cout << "Data invalida!" << endl;
      }
    }
}
void escreveData()
{
  //printf da data e escreve na tela
  cout<<dia<<"/"<<mes<<"/"<<ano<<endl;
}
};

class Pessoa
{
private:
string nome;
Data nascimento; // nascimento utiliza os dados de data

public:
Pessoa(){}
~Pessoa(){}
void setNome(string nome)
{
  this->nome=nome;
}
string getNome()
{
  return nome;
}
void lerNome()
{
  // pede para a pessoa colocar o nome
  cout<<"Digite o nome: ";
  cin.ignore(); // buffer
  getline(cin,nome); // armazena o nome da pessoa
}
void escreverNome()
{
  // printa o nome da pessoa
  cout<<"Nome: "<<nome<<endl;
}
void lerPessoa()
{
  lerNome(); // chama a função para vc colocar o nome da pessoa
  cout<<"Digite a data de nascimento"<<endl;
  nascimento.lerData(); // chama a função lerdata da 1° superclasse
}
Data getNascimento()
{
  return this->nascimento;
}
static int getcont()
{
  return cont; // ve qunatas pessoas foram criadas
}
int getMesNascimento()
{
  return this-> getNascimento().getMes();
}
virtual void escrevePessoa()
{
  cout<<"Nome: "<<this->getNome()<<endl;
  cout<<"Data de nascimento: ";
  this->getNascimento().escreveData();
  cout<<"nada"<<this->getOrigem()<<endl;
}
virtual void setOrigem()=0;
virtual string getOrigem()=0;
};

class Aluno: public Pessoa
{
private: 
int matricula;
string classe;
public:
Aluno(){}
~Aluno(){}
Aluno(string nome, int matricula):Pessoa()
{
  this->matricula=matricula;
}
void setmatricula(int matricula)
{
  this->matricula=matricula;
}
void setClasse(string classe)
{
  this->classe=classe;
}
int getmatricula()
{
  return matricula;
}
string getClasse()
{
  return classe;
}
void setOrigem()
{
  cout<<"Coloque a matríclua: ";
  cin>>matricula;
  cout<<"Coloque a classe: ";
  cin>>classe;
}
string getOrigem()
{
  return this->getClasse()+"\nMatrícula: " +std::to_string(this->getmatricula());
}
void leAluno()
{
  lerPessoa();
  setOrigem();
}
void escrevePessoa()
{
  cout<<"Nome: "<<this->getNome()<<endl;
  cout<<"Data de nascimento: ";
  this->getNascimento().escreveData();
  cout<<"Classe: "<<this->getOrigem()<<endl;
}
};

class Professor: public Pessoa
{
private:
string titulacao;
public:
Professor(){}
~Professor(){}
void settitulacao(string titulacao)
{
  this->titulacao=titulacao;
}
string gettitulacao()
{
  return titulacao;
}
void setOrigem()
{
  cout<<"Coloque a titulação: ";
  cin.ignore();
  getline(cin,titulacao);
}
string getOrigem()
{
  return this->gettitulacao();
}
void leProfessor()
{
  lerPessoa();
  setOrigem();
}
void escrevePessoa()
{
  cout<<"Nome: "<<this->getNome()<<endl;
  cout<<"Data de nascimento: ";
  this->getNascimento().escreveData();
  cout<<"Titulação: "<<this->getOrigem()<<endl;
}
};

void cadastrarAluno(Pessoa* p[])
{
  if(cont<100)
  {
    p[cont]= new Aluno();
    p[cont]->lerPessoa();
    p[cont]->setOrigem();
    cont++;
    quantA++;
  }
}

void cadastrarProfessor(Pessoa* p[])
{
  if(cont<100)
  {
    p[cont]= new Professor();
    p[cont]->lerPessoa();
    p[cont]->setOrigem();
    cont++;
  }
}
void escrevePessoa(Pessoa* p)
{
  p->escrevePessoa();
}

void listaPessoa(Pessoa* p[])
{
  for(int i=0; i<cont; i++)
    {
      escrevePessoa(p[i]);
    }
}

void listarAlunos(Pessoa* p[])
{
  for(int i=0; i<quantA; i++)
    {
      escrevePessoa(p[i]);
    }
}

void listarProfessor(Pessoa* p[])
{
  for(int i=quantA; i<cont; i++) // cadastra professores depois de aluno
    {
      escrevePessoa(p[i]);
    }
}

void aniversariantesMes(Pessoa* p[])
{
  int chave;
  cout<<"Coloque o mes: ";
  cin>>chave;
  for(int i=0; i<cont; i++)
    {
      if(p[i]->getMesNascimento()==chave)
      {
        p[i]->escrevePessoa();
      }
    }
}

int Menu()
{
  int op;
  cout<<"Menu de opções: "<<endl;
  cout<<"0 - Sair"<<endl;
  cout<<"1 - Cadastrar aluno"<<endl;
  cout<<"2 - Cadastrar professor"<<endl;
  cout<<"3 - Listar alunos"<<endl;
  cout<<"4 - Listar professores"<<endl;
  cout<<"5 - Listar aniversáriantes do mes"<<endl;
  cout<<"Escolha uma opção: ";
  cin>>op;
  if (cin.fail()|| op < 0 || op > 5) 
  {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw std::runtime_error("Entrada inválida. Retornando ao menu principal. Clique enter");
  }
  return op;
}

int main() 
{
  Pessoa* p[100];
  int op;
  do
    {
      try
        {
          op=Menu();
          switch(op)
          {
            case 0: cout<<"Obrigada por utilizar o programa"<<endl;
            break;
            case 1: cadastrarAluno(p);
            break;
            case 2: cadastrarProfessor(p);
            break;
            case 3: listarAlunos(p);
            break;
            case 4: listarProfessor(p);
            break;
            case 5: aniversariantesMes(p);
            break;
            default: cout<<"Opção inválida"<<endl;
          }
          cout<<endl;
        }
      catch(const std::exception& e)
        {
          cout << "Ocorreu um erro: " << e.what()<< endl;
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while(op!=0);
  return 0;
}