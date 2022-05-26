
/* 
    Estudiantes:
        Francisco Labrin 
        Tomás Vera
        Luciano Espinosa
        Sebastian Cuevas   

*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


int exhaustiveSearch(vector<char> T, vector<char> P);

int main(int argc,char **argv){


    FILE *archivo  = fopen("dna.50MB","r"); // se abre el archivo 
    vector <char> T;  // vector que contendra el texto
    vector <char> P = {'C','T','T','G','T','A'} ;//vector de la clave  a buscar

    int c;
    while ( (c=fgetc(archivo)) != EOF ){  //mientras el caracter no sea el fin de linea añade al vector t el caracter
        T.push_back(c);
    }

    cout << exhaustiveSearch(T,P);

    //P.push_back(p)

    return EXIT_SUCCESS;
}


/* 
funcion que recive dos vectores de char T y P ,(T siendo el texto y P la clave),luego hara una busqueda exaustiva de la clave en el texto
*/
int exhaustiveSearch(vector<char> T, vector<char> P){
    unsigned int g, c;
    g = c = 0;
    for(unsigned int i=0; i<(T.size()-P.size()) ; i++){ 
        while(T[i+g]==P[g])
            g++;
        if(g==P.size()) // si el contador g es igual al tamaño del vector clave entonces aumenta c
            c++;
        g=0;
    }
    return c; //se retona la ocurrencia de la clave en vector del texto de input
}