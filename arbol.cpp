#include <iostream>
#inlude <string>
using namespace std;
struct estudiante{

string nombre;
int coddigo;
string fecha;
estudiante* derecha;
estudiante* izquierda;


    estudiante( string nombre,int codigo,string fecha,){

        izquierda=NULL;
        derecha=NULL;
    }
};
void registrarnodo(){


  if(nodo=NULL){
  estudiante nuevoestudiante= new estudiante(nombre,fecha,codigo);}
else{
if(codigo<nodo->codigo){

insertarnodo(nodo->izquierda,nombre,fecha,codigo )



}



}
}

void mostrarpreorden(nodo* estudiante){


    if(estudiante!=NULL){

cout<<"codigo"<<nodo->codigo<<"nombre"<<nodo->nombre<<"codigo"<<nodo->codigo;
preorden(nodo->izquierda)
preorden(nodo->derecha)

    }
}


void imprimir postorden(estudiante* nodo){



    if(nodo!=NULL){

postorden(nodo->izquierda)
postorden(nodo->derecha)

cout<<"codigo"<<nodo->codigo<<"nombre"<<nodo->nombre<<"codigo"<<nodo->codigo;

    }

}
void liberarbol(estudiante*& nodo){
liberararbol(nodo->izquierda)
liberararbol(nodo->derecha)
delete nodo;
nodo=NULL;}