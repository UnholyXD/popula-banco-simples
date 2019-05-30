// basic file operations
#include <iostream>//padrão
#include <cstring>//para trabalhar com string
#include <fstream>//trabalhar com arquivos texto
#include <ctime>//para colocar o idioma do programa em PT_BR
#include <cstdlib>//para fazer a randomização e para zerar a seed

using namespace std;

string geraF();//função para gerar o nome feminino
string geraM();//função para gerar o nome masculino
string geraS();//função para gerar o sobrenome
string escolhenome();//função para gerar o se o nome é M ou F
string geraData();
/*
   CREATE TABLE `pessoas`(
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(60) NOT NULL,
  `email` varchar(100) NOT NULL,
  `nascimento` date NOT NULL,
  PRIMARY KEY (`Id`)
  );
*/

int main () {

    setlocale(LC_ALL, "portuguese");//coloca o sistema para a localização do BR, assim pode usar caracteres especias
    srand(time(NULL));//utiliza os mixrossegundos para a randomização, assim cada execução é única

    string t1, t2, email, nasc; //strings para receber os dados
    string num[10]={"1","2","3","4","5","6","7","8","9","0"};//string com nomes para ser randomizados
    int i, total=10;//variaveis de numeros inteiros
    ofstream meuarquivo;//serve para alocar o arquivo

    meuarquivo.open ("populaBanco.txt");//criando o arquivo

    cout<<"Deseja gerar quantas massas?"<<endl;//pedindo info pro usuário
    cin>>total;//defindo total de massas
    for(i=1; i<total+1;i++){//laço com limite definido pelo total de massas

        t1=escolhenome();//chama a função para definir se o nome será fem ou masc e retorna o resultado
        t2= geraS();//chama a função para gerar o sobrenome
        //formando o email da pessoa
        email+=t1;//adiciona o nome
        email+=t2;//adicona o sobrenome
        email+=num[rand()%10];//rand do primeiro número
        email+=num[rand()%10];//rand do segundo número
        email+="@email.com";//concatenação de string

        //escrevendo no arquivo a frase insert into pessoas values (ID, NOME, EMAIL, NASCIMENTO);
        meuarquivo << "insert into pessoas values ("<<i<<",\""<<t1<<" "<<t2<<"\",\""<<email<<"\",\""<<geraData()<<"\");"<<endl;

        email.clear();//esvazia a string de email
    }

    cout<<"Todas as massas foram geradas";//avisa que encerrou o processo de criação


    meuarquivo.close();//fecha e salva o arquivo

}

string escolhenome(){//esta função tem como objetivo unicamente randomizar entre 0 e 1 pra escolher se o nome será masc ou fem
    string batata;//string q vai receber o resultado
    int i;
    i= rand()%2;//rand entre 0 e 1

    if(i==0){// se for zero o resultado
        batata=geraM();//chama a função de nome masc
    }else{//caso não seja zero o resultado
        batata=geraF();//chama a função de nome fem
    }

    return batata;//retorna o resultado
}

string geraF(){//essa função tem como objetivo randomizar um nome feminino da lista
    string nomeF[39]={"Alice","Sofia","Helena","Valentina","Laura","Isabela","Manuela","Julia","Heloisa","Luiza","Lorena","Giovanna","Maria","Eduarda","Beatriz","Isadora","Mariana","Ana","Melissa","Yasmin","Esther","Antonella","Nicole","Marina","Matie","Isis","Rafaela","Rebeca","Agatha","Laura","Catarina","Clara","Beatriz","Olivia","Fernanda","Milena","Allana","Clarice","Pietra"};
    return nomeF[rand()%39];//randomiza entre 0 e 38
}

string geraM(){//essa função tem como objetivo randomizar um nome masculino da lista
    string nomeM[40]={"Miguel","Arthur","Bernardo","Heitor","Davi","Lorenzo","Pedro","Gabriel","Enzo","Matheus","Mateus","Lucas","Nicolau","Nicolas","Henrique","Samuel","Joaquim","Gustavo","Murilo","Pietro","Felipe","Issac","Eduardo","Vicente","Caleb","Emanuel","Francisco","Kaique","Otavio","Vinicius","Vitor","Victor","Davi","Luiz","Luis","Lucas","Raul","Carlos","Danilo","Daniel"};
    return nomeM[rand()%40];//randomiza entre 0 e 39
}

string geraS(){//essa função tem como objetivo randomizar um sobrenome  da lista
    string sobren[27]={"Silva","Santos","Oliveira","Sousa","Lima","Perreira","Ferreira","Costa","Rodrigues","Almeida","Souza","Rodrigues","Cardoso","Moraes","Duarte","Fagundes","Ferraz","Vargas","Andrade","Carvalho","Barros","Castro","Torres","Antunes","Novaes","Garcia","Moura"};
    return sobren[rand()%27];//randomiza entre 0 e 26
}


string geraData(){
    int dia, mes, ano;
    string data;
    dia=(rand()%27)+1;//randomiza o dia
    mes=(rand()%12)+1;//randomiza o mês
    ano=(rand()%(2008-1960+1))+1960;//Randomiza o ano utilizando uma faixa; rand()%(maxi-mini+1))+mini


        data=to_string(ano)+"\-";//converte e concatena o ano
        data+=to_string(mes)+"\-";//converte e concatena o mês
        data+=to_string(dia);//converte e concatena o dia

        return data;
}
