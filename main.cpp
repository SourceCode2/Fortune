#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <ctime>
#include "header"
using namespace std;


/// Definizione delle variabili
// La struttura CLASSE
struct CLASSE {
string nome;
bool chiamato;
};
bool da_lista= false;
int estratto;
string stringa;
int i;
int alunni;
int index = 0;
int indice;
void estrazione_da_lista (string lista)
{
    ifstream file(lista);
    string stringa;
    if (file) {
        file >> alunni;
        CLASSE lista[alunni];

        while (file >> stringa) {
            lista[index].nome = stringa;
            lista[index].chiamato = false;
            cout << stringa << "  " << index << endl;
            index++;

            }
        srand(time(NULL));
        int u;

        while (true){
            estratto = rand()%alunni;
               if (!lista[estratto].chiamato){
                stringa = "figlet " + lista[estratto].nome;

                system("clear");

                cout << "\033[32;1m+------------------------------------------------------------------------------+\033[36;1m";
                esegui(stringa);
                lista[estratto].chiamato = true;
                cout << "Premi enter per estrarre ancora \033[0m" << endl;

                i= getchar();

                u++;

            }

    }
    }
    else {
        cout << "non esiste\n";
        file.close();
        file.clear();
    }

}

void estrazione ()
{
    srand(time(NULL));
    CLASSE Classe1D[31];
Classe1D[0].nome = "Antonini Emma";
Classe1D[0].chiamato = false;
Classe1D[1].nome = "Bassan Matteo";
Classe1D[1].chiamato = false;
Classe1D[2].nome = "Benelli Alessio";
Classe1D[2].chiamato = false;
Classe1D[3].nome = "Blasi Francesco";
Classe1D[3].chiamato = false;
Classe1D[4].nome = "Cavini Greta";
Classe1D[4].chiamato = false;
Classe1D[5].nome = "Centioli Mattia";
Classe1D[5].chiamato = false;
Classe1D[6].nome = "Costa Michele";
Classe1D[6].chiamato = false;
Classe1D[7].nome = "De Marchi Francesco";
Classe1D[7].chiamato = false;
Classe1D[8].nome = "Di Giovanni Carlotta";
Classe1D[8].chiamato = false;
Classe1D[9].nome = "Gobbini Giulia";
Classe1D[9].chiamato = false;
Classe1D[10].nome = "Grussu Simone";
Classe1D[10].chiamato = false;
Classe1D[11].nome = "Guagliano Lorenzo";
Classe1D[11].chiamato = false;
Classe1D[12].nome = "Innocenzi Giorgio";
Classe1D[12].chiamato = false;
Classe1D[13].nome = "Lico Lawrence";
Classe1D[13].chiamato = false;
Classe1D[14].nome = "Martelli Niccolo";
Classe1D[14].chiamato = false;
Classe1D[15].nome = "Mensitieri Vincenzo";
Classe1D[15].chiamato = false;
Classe1D[16].nome = "Miracola Davide";
Classe1D[16].chiamato = false;
Classe1D[17].nome = "Moschini Javier";
Classe1D[17].chiamato = false;
Classe1D[18].nome = "Napolitano Matteo";
Classe1D[18].chiamato = false;
Classe1D[19].nome = "Opice Luca";
Classe1D[19].chiamato = false;
Classe1D[20].nome = "Pes Emanuele";
Classe1D[20].chiamato = false;
Classe1D[21].nome = "Pezzopane Valerio";
Classe1D[21].chiamato = false;
Classe1D[22].nome = "Puicea Sergio";
Classe1D[22].chiamato = false;
Classe1D[23].nome = "Ridolfi Francesco";
Classe1D[23].chiamato = false;
Classe1D[24].nome = "Rocca Matteo";
Classe1D[24].chiamato = false;
Classe1D[25].nome = "Saba Mario";
Classe1D[25].chiamato = false;
Classe1D[26].nome = "Salvati Alessandro";
Classe1D[26].chiamato = false;
Classe1D[27].nome = "Scirocchi Nicolas";
Classe1D[27].chiamato = false;
Classe1D[28].nome = "Seminara";
Classe1D[28].chiamato = false;
Classe1D[29].nome = "Sofronia Davide";
Classe1D[29].chiamato = false;
Classe1D[30].nome = "Trani Massimo";
Classe1D[30].chiamato = false;
    int u;
    time_t now = time(0);
    while (true){

        estratto = rand()*now%31;
        if (!Classe1D[estratto].chiamato){
            stringa = "figlet " + Classe1D[estratto].nome;
            system("clear");

            cout << "\033[32;1m+------------------------------------------------------------------------------+\033[36;1m";
            esegui(stringa);
            Classe1D[estratto].chiamato = true;
            cout << "Premi enter per estrarre ancora \033[0m" << endl;
            i= getchar();
            u++;

       }
       if (u==31){
        break;
       }
    }

}




int main(int argc, char *argv[])
{
    unbuffered();

    if (argv[argc-1]==argv[0])
        estrazione();
    else
        da_lista = true;
        estrazione_da_lista(argv[1]);


    return 0;
}
