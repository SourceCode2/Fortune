#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <termios.h>

#define FIGLET "figlet " // stringa per avviare figlet
using namespace std;

/// Inizializzazione delle variabili

/* La struttura CLASSE per creare il vettore di record della lista o della 1D */
struct CLASSE {
string nome;
bool chiamato;
};

/* Le strutture old_tio e new_tio appartenenti alla libreria <termios> per il buffer*/
struct termios old_tio, new_tio;

/* Altre variabili */
int estratto; // Int con il numero estratto con rand()
string stringa; // Stringa temporanea per assegare la parola letta dalla lista e metterla nel vettore di record
int i; int index=0;int indice;int u; // Valori per i cicli
int alunni; // Int per vedere il numero di elementi da assegnare al vettore di record della lista


/// Definizioni delle funzioni per gestire il buffer da tastiera

/* Funzione per togliere il buffer */
void unbuffered () {
    // Setting
    tcgetattr(STDIN_FILENO,&old_tio);

    // Salvare le vecchie impostazioni
    new_tio=old_tio;

    // Modalita unbuffer
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    // Applicare la modalita
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
}

/* Funzione per fare tornare presente il buffer da tastiera */
void buffered () {
    // Settare di nuovo la modalita normale con buffer
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
}


/// Definizione della Funzione per far eseguire dal sistema una stringa

/* Funzione modificata di system */
int esegui (string comando) {
    // Trasforma la stringa in una costante di char (puntatore)
    const char* exe = comando.c_str();
    // Esegue la costante
    system(exe);
    return 0;
}

/// Funzione per l'estrazione degli elementi di un file

void estrazione_da_lista (string lista) // Lista è la directory del file
{
    ifstream file(lista.c_str); // Apertura dello stream del file

    if (file) { // Se lo stream è vero ed funziona
        file >> alunni; // estrazione con ">>" da file dentro la variabile int alunni
        CLASSE lista[alunni]; // creazione dell vettore di array

        while (file >> stringa) { /// Ciclo fino a quando finiscono le stringe dello stream
            lista[i].nome = stringa;
            lista[i].chiamato = false;
            i++;
            }
        srand(time(NULL)); // impostare un seme "casuale" per rand
        while (true){ /// Ciclo loop
            estratto = rand()%alunni; // estrarre un numero casuale
               if (!lista[estratto].chiamato){ // se l'elemento non e stato chiamato
                stringa = FIGLET + lista[estratto].nome; // stringa da eseguire
                system("clear"); // pulire lo schermo
                cout << "\033[32;1m+------------------------------------------------------------------------------+\033[36;1m";
                esegui(stringa); // printare l'elemento chiamato
                lista[estratto].chiamato = true;
                cout << "Premi enter per estrarre ancora \033[0m" << endl;
                i= getchar(); // Premere per continuare con il ciclo
                }
        }
    }
    else { // se lo stream e errato
        cout << "\033[31;1m*** ERRORE il file selezionato non esiste ***\033[0m\n";
        file.close(); // chiudere lo stream
        file.clear(); // pulire lo stream
    }
}


/// estrazione dalla lista degli alunni della 1D

void estrazione ()
{
    srand(time(NULL)); // impostare un seme "casuale" per rand
    alunni = 31; // numero di elementi
    CLASSE Classe1D[alunni]; // creare il vettore di record
    Classe1D[0].nome = "Antonini Emma"; /// IMPOSTARE IL RECORD
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

    while (true){ /// Ciclo loop
        estratto = rand()%alunni;
        if (!Classe1D[estratto].chiamato){ // se l'elemento non è stato chiamato
            stringa = FIGLET + Classe1D[estratto].nome; // stringa da eseguire
            system("clear"); // pulire lo schermo
            cout << "\033[32;1m+------------------------------------------------------------------------------+\033[36;1m";
            esegui(stringa); // printare l'elemento scelto
            Classe1D[estratto].chiamato = true;
            cout << "Premi enter per estrarre ancora \033[0m" << endl;
            i= getchar(); // Premere per continuare il ciclo
        }
    }
}


/// FUNZIONE MAIN
int main(int argc, char *argv[])
{
    unbuffered(); // attivare l'unbuffer
    if (argv[argc-1]==argv[0]) // se non ci sono argomenti fai estrazione
        estrazione();
    else // altrimenti usa l'argomento in piu per eseguire estrazione_da_lista
        estrazione_da_lista(argv[1]);
    return 0; /// THE END
}
