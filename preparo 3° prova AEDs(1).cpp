#include <iostream>
#include <vector>
using namespace std;
const int mq=3;
struct Pessoa
{
int idade;
};
struct Aluno
{
string nome;
int idade;
double media;
};
struct carro
{
string marca;
int ano;
double preco;
};
struct Aluno2
{
string nome;
int idade;
int nota;
};
int somaA(int a[5])
{
  int soma=0;
  for(int i=0;i<5;i++)
    {
      soma+=a[i];
    }
  return soma;
}
int somaB(int b[][3])
{
  int soma=0;
  for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
        {
          soma+=b[i][j];
        }
    }
  return soma;
}
int somaC(Pessoa p[][3])
{
  int soma=0;
  for(int i=0; i<3; i++)
    {
      for(int j=0; j<3;j++)
        {
          soma+=p[i][j].idade;
        }
    }
  return soma;
}
int MaiorNum(int c[][3])
{
  int maior=c[0][0]; // inicia com 1° elemento da matriz
  for(int i=0; i<3; i++)
    {
      for(int j=0; j<3;j++)
        {
          if(c[i][i]>maior)
          {
            maior=c[i][j]; // atualiza valor encontrado
          }
        }
    }
  return maior;
}
int MenorNum(int d[][3])
{
  int menor=d[0][0];
  for(int i=0; i<3; i++)
    {
      for(int j=0; j<3;j++)
        {
          if(d[i][i]<menor)
          {
            menor=d[i][j]; // atualiza valor encontrado
          }
        }
    }
  return menor;
}
bool MaTr(int e[][3])
{
  bool ok = true;
  for(int i=0; i<3; i++)
    {
      for(int j=0; j<3; j++)
        {
          if(e[i][j]!=e[j][i])
          {
            ok = false;
          }
        }
    }
  return ok;
}
vector<string> AMVC(Aluno f[][3],int a, int b) // b=col
{
  vector<string> amv(b);
  for(int j=0; j<3; j++)
    {
      int maior=f[0][j].idade;
      string nomeAlunoMaisVelho = f[0][j].nome;
      // começa do 1° da matriz
      for (int i = 1; i <3; i++) 
      {
        if (f[i][j].idade>maior) 
        // percorre toda a matriz
        {
          maior =f[i][j].idade;
          nomeAlunoMaisVelho = f[i][j].nome;
        }
      }
      amv[j] = nomeAlunoMaisVelho;
    }
  return amv;
}
double PrecoMedio(carro carro[mq])
{
  double soma=0;
  double media=0;
  for(int i=0; i<mq; i++)
    {
      soma+=carro[i].preco;
    }
  media=soma/mq;
  return media;
}
double MediaAlunos2(Aluno2 aluno2[][2])
{
  int soma=0;
  int media=0;
  for(int i=0; i<2; i++)
    {
      for(int j=0; j<2; j++)
        {
          soma+=aluno2[i][j].nota;
        }
    }
  media = static_cast<double>(soma) / 4.0;
  return media;
}
int main() 
{
  int a[5]={5,8,9,6,4};
  int resultado =somaA(a);
  cout<<"a soma é: "<<resultado<<endl;
  int b[3][3]={5,8,9,6,4,3,5,2,1};
  int resultado2=somaB(b);
  cout<<"a somaB é: "<<resultado2<<endl;
  Pessoa p[3][3]={5,8,9,6,4,3,5,2,1};
  int resultado3=somaC(p);
  cout<<"a somaC é: "<<resultado3<<endl;
  int c[3][3]={9,8,7,6,5,4,3,2,1};
  int resultado4=MaiorNum(c);
  cout<<"o maior número da matriz é: "<<resultado4<<endl;
  int d[3][3]={9,8,7,6,5,4,3,2,1};
  int resultado5=MenorNum(d);
  cout<<"o maior número da matriz é: "<<resultado5<<endl;
  int e[3][3]={1,2,3,2,4,5,3,5,6};
  int resultado6=MaTr(e);
  if(resultado)
  {
    cout<<"a matriz é simétrica transposta"<<endl;
  }
  else
  {
    cout<<"a matriz não é simétrica transposta"<<endl;
  }
  Aluno f[3][3]=
  {
        {{"João", 20, 7.5}, {"Maria", 18, 8.2}, {"Carlos", 21, 6.8}},
        {{"Ana", 19, 7.9}, {"Pedro", 22, 8.7}, {"Mariana", 20, 9.1}},
        {{"Lucas", 23, 6.5}, {"Juliana", 21, 8.3}, {"Rafael", 19, 7.2}}
  };
  vector<string> resultado7=AMVC(f,3,3); // linhas e colunas
  for (int i = 0; i < resultado7.size(); i++) 
  {
    cout << "Aluno mais velho na coluna " << i+1 << ": " << resultado7[i] << endl;
    }
  carro carro[mq];
  carro[0] = {"Toyota", 2018, 25000.0};
  carro[1] = {"Honda", 2019, 28000.0};
  carro[2] = {"Ford", 2020, 30000.0};
  double resultado8=PrecoMedio(carro);
  cout<<"O preço médio é de: "<<resultado8<<endl;
  Aluno2 aluno2[2][2];
  for(int i=0; i<2; i++)
    {
      for(int j=0; j<2; j++)
        {
          cout<<"Coloque o aluno["<<i+1<<"]["<<j+1<<"]"<<endl;
          cout<<"nome: ";
          cin>>aluno2[i][j].nome;
          cout<<"idade: ";
          cin>>aluno2[i][j].idade;
          cout<<"nota: ";
          cin>>aluno2[i][j].nota;
        }
    }
  double resultado9=MediaAlunos2(aluno2);
  cout<<"a médias dos alunos é: "<<resultado9<<endl;
}