#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;
struct viaje {
    //precio
    double precio;
int contador;
     //destino
    char destino [20];

    //matricula
    int matricula;

    //nombre
    char  nm[20];

    //fecha
    int ano;
    int mes;
    int dia;

    //capacidad
    int capacidad;
     
    //identificador unico
    int id;   
    
    //izquierda y derecha del n
    viaje *izq;
    viaje *der;

    //AVL
    int altura;
};

struct pasajero{
    char nombre[10];
    char apellido[10];
    int edad;
    int idso;
    pasajero *sig;
};

struct viaje*raiz, *aux;
struct pasajero *aux1, *cab, *aux2;
int crearviaje();
struct viaje* insertar(struct viaje* raiz, struct viaje*viaje);
int obtenerAltura(struct viaje *n);
int mayor(int a, int b);
struct viaje* rotarDerecha(struct viaje *y);
struct viaje* rotarIzquierda(struct viaje *x);
int obtenerBalance(struct viaje *n);
void preOrden(struct viaje *viaje);                                                

int crearviaje() {
    aux = ((struct viaje *) malloc(sizeof(struct viaje)));
    
    cout << "Ingrese la matricula: ";
        cin >> aux->matricula;
        
    cout << "Ingrsese el nombre de la embarcacion: ";
        cin >>aux->nm;
        
    cout << "Cual es el destino del viaje: ";
        cin >>aux->destino;
        
    cout << "Fecha del viaje: ";
    cout << "Año / mes / dia"<<endl;
    cout << "Año: ",cin >> aux->ano,cout << "Mes: ", cin>>aux->mes, cout << "Dia:", cin>>aux->dia; 
    
    cout << "Ingrese la capacidad: ";
    cin>>aux->capacidad;
       aux->contador=0;
   
    
    cout << " "<< endl;
    cout << "Ingrese el precio: $";
        cin >> aux-> precio;
        
    aux->izq = NULL;
    aux->der = NULL;
    aux->altura = 1;
    
    
    string matricula_str = to_string(aux->matricula); 
    string doscaracteres = matricula_str.substr(0, 2); 
    int sumamatricula = stoi(doscaracteres); 
    aux->id = sumamatricula + aux->ano + aux->mes + aux->dia; 

return 0;
}

/*
int generaridentificador(viaje* aux) {
    char dato_uno = 0;
    char dato_dos = 0;

    for (int i = 0; i < 2; ++i) {
        dato_uno = aux->matricula[i]; 
        dato_dos = aux->matricula[i + 1]; 
    }

    aux->id = dato_uno, dato_dos,  aux->ano + aux->mes + aux->dia; 
    return aux->id;
    o
    podemos cambiar el tipo de dato de la matricula a char y luego solo usar un for bro.
    ponemos char matricula en el struct; 
    luego un for (int i=0; i < 2; i++){
        aux->matricula[o]= aqui una variable que guarde el primer caracter.
        aux->matricula[1]= aqui una variable que guarde el 2do caracter.
        luego se usan esa variables que pueden ser locales para hacer las vainas.
        es una idea toca implementarla, solo es que me diga
    }
    bro abjo lo intente implementar pero da error, creo va tocar dejarlo asi.
}
algo asi bro
*/

viaje* buscarporid(int id, viaje* aux) {
    if (aux == NULL) {
        cout << "La embarcacion no existe" << endl;
        return NULL;
    } else if (aux->id == id) {
        cout << "\tDATOS" << endl;
        cout << "matricula: " << aux->matricula << endl;
        cout << "Nombre: " << aux->nm << endl;
        cout << "Destino: " << aux->destino << endl;
        cout << "Año: " << aux->ano << endl;
        cout << "Mes: " << aux->mes << endl;
        cout << "Dia: " << aux->dia << endl;
        cout << "Precio: $" << aux->precio << endl;
        cout << "Capacidad: " << aux->capacidad << endl;
        cout << " " << endl;
        return aux;
    } else if (id < aux->id) {
        return buscarporid(id, aux->izq);
    } else {
        return buscarporid(id, aux->der);
    }
}
int obtenerAltura(struct viaje *n) {
    if (n == NULL) {
        return 0;
    }
    return n->altura;
}

int mayor(int a, int b) {
    return (a > b) ? a : b;
}

struct viaje* rotarDerecha(struct viaje *y) {
    struct viaje *x = y->izq;
    struct viaje *T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = mayor(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;
    x->altura = mayor(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;

    return x;
}

struct viaje* rotarIzquierda(struct viaje *x) {
    struct viaje *y = x->der;
    struct viaje *T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = mayor(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;
    y->altura = mayor(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;

    return y;
}

int obtenerBalance(struct viaje *n) {
    if (n == NULL) {
        return 0;
    }
    return obtenerAltura(n->izq) - obtenerAltura(n->der);
}

struct viaje* insertar(struct viaje* viaje) {
    if (viaje== NULL) {
        return aux;
    }

    if (aux->id < viaje->id) {
        viaje->izq = insertar(viaje->izq);
    } else if (aux->id >= viaje->id) {
        viaje->der = insertar(viaje->der);
    } else {
        return viaje;
    }

    viaje->altura = 1 + mayor(obtenerAltura(viaje->izq), obtenerAltura(viaje->der));

    int balance = obtenerBalance(viaje);

    if (balance > 1 && aux->id < viaje->izq->id) {
        return rotarDerecha(viaje);
    }

    if (balance < -1 && aux->id> viaje->der->id) {
        return rotarIzquierda(viaje);
    }

    if (balance > 1 && aux->id > viaje->izq->id) {
        viaje->izq = rotarIzquierda(viaje->izq);
        return rotarDerecha(viaje);
    }

    if (balance < -1 && aux->id < viaje->der->id) {
        viaje->der = rotarDerecha(viaje->der);
        return rotarIzquierda(viaje);
    }

    return viaje;
}

void preOrden(struct viaje *nodo) {
    if (nodo != NULL) {
        cout <<"ID: " <<nodo->id<<endl;
        cout<<"matricula: "<< aux->matricula<<endl;
        cout<<"Nombre: "<< aux->nm<<endl;
        cout<<"Destino: "<< aux->destino<<endl;
        cout<<"Año: "<< aux->ano<<endl;
        cout<<"Mes: "<< aux->mes<<endl;
        cout<<"Dia: "<< aux->dia<<endl;
        cout<<"Precio: $"<< aux->precio<<endl;
        cout<<" "<<endl;
        
        preOrden(nodo->izq);
        preOrden(nodo->der);
    }
}

int Registrarpas() {
    cout << "Digite el ID de la embarcación para registrar un pasajero: ";
    int id;
    cin >> id;

    viaje* viajeEncontrado = buscarporid(id, raiz);
    if (viajeEncontrado != NULL) {
        
        if(viajeEncontrado->contador < viajeEncontrado->capacidad){
        
            if (cab == NULL) {
                cab = (struct pasajero*)malloc(sizeof(struct pasajero));
               
                cout << "Ingrese el nombre del pasajero: ";
                cin >> cab->nombre;
                cout << "Ingrese el apellido del pasajero: ";
                cin >> cab->apellido;
                cout << "Ingrese la edad: ";
                cin >> cab->edad;
                cab->idso=id;
                
                cab->sig = NULL;
            } else {
                aux1 = (struct pasajero*)malloc(sizeof(struct pasajero));
                
                cout << "Ingrese el nombre del pasajero: ";
                cin >> aux1->nombre;
                cout << "Ingrese el apellido del pasajero: ";
                cin >> aux1->apellido;
                cout << "Ingrese la edad: ";
                cin >> aux1->edad;
                aux1->idso=id;
                aux1->sig = NULL;
                aux2 = cab;
                while (aux2->sig != NULL) {
                    aux2 = aux2->sig;
                }
                aux2->sig = aux1;
            } 
            viajeEncontrado->contador++;
            cout << "Pasajero registrado con éxito. Numero actual de pasajeros: " << viajeEncontrado->contador << endl;
        } else {
            cout << "La embarcación ha alcanzado el máximo de pasajeros." << endl;
        }
    } else {
        cout << "El viaje con ID " << id << " no existe." << endl;
    }

    return 0;
}
    


void inOrden(struct viaje* nodo) {
    if (nodo != NULL) {
        inOrden(nodo->izq);
        cout << "ID: " << nodo->id << ", Matrícula: " << nodo->matricula << ", Nombre: " << nodo->nm 
             << ", Destino: " << nodo->destino << ", Fecha: " << nodo->ano << "/" << nodo->mes << "/" << nodo->dia 
             << ", Precio: " << nodo->precio << endl;
        inOrden(nodo->der);
    }
}
struct viaje* minnimovalor(struct viaje* nodo) {
    struct viaje* aux= nodo;

    while (aux->izq != NULL) {
        aux = aux->izq;
    }

    return aux;
}
viaje* eliminarNodo(viaje* raiz, int id) {
    if (raiz == NULL) {
        return raiz;
    }
    if (id < raiz->id) {
        raiz->izq = eliminarNodo(raiz->izq, id);
    }
   
    else if (id > raiz->id) {
        raiz->der = eliminarNodo(raiz->der, id);
    }
   
    else {
       
        if (raiz->izq == NULL) {
            viaje* aux= raiz->der;
            free(raiz);
            return aux;
        } else if (raiz->der == NULL) {
            viaje* aux= raiz->izq;
            free(raiz);
            return aux;
        }

        viaje* aux = minnimovalor(raiz->der);

       
        raiz->id = aux->id;

      
        raiz->der = eliminarNodo(raiz->der, aux->id);
    }


    raiz->altura = 1 + mayor(obtenerAltura(raiz->izq), obtenerAltura(raiz->der));

    int balance = obtenerBalance(raiz);

    if (balance > 1 && obtenerBalance(raiz->izq) >= 0) {
        return rotarDerecha(raiz);
    }
    if (balance > 1 && obtenerBalance(raiz->izq) < 0) {
        raiz->izq = rotarIzquierda(raiz->izq);
        return rotarDerecha(raiz);
    }
    if (balance < -1 && obtenerBalance(raiz->der) <= 0) {
        return rotarIzquierda(raiz);
    }
    if (balance < -1 && obtenerBalance(raiz->der) > 0) {
        raiz->der = rotarDerecha(raiz->der);
        return rotarIzquierda(raiz);
    }

    return raiz;
}

viaje* eliminar(viaje* raiz) {
    int id;
    cout << "Ingrese el ID de la embarcacion que desea eliminar: ";
    cin >> id;

    
    if (raiz == NULL) {
        cout << "El árbol está vacío." << endl;
        return raiz;
    }

    if (!buscarporid(id, raiz)) {
        cout << "El ID a eliminar no pertenece a ninguna embarcacion." << endl;
        return raiz;
    }

    raiz = eliminarNodo(raiz, id);
    cout << "Embarcacion eliminada correctamente" << endl;

    return raiz;
}

int listpas(int id){
    
    for (aux1 = cab; aux1 != NULL; aux1 = aux1->sig){
        
    if(aux1->idso == id){
        cout<< "Nombre: " << aux1->nombre<< ", Apellido: " << aux1->apellido << ", Edad: " << aux1->edad << endl;
    }
    }
if (cab==NULL){
        cout<<"No hay pasajeros en la embarcacion"<<endl;
    }
    return 0;
}






int main() {
    raiz = NULL;
    int opc = 0;
    do {
        cout << "-------------------------------" << endl;
        cout << "\tMenu de opciones" << endl;
        cout << "-------------------------------" << endl;
        cout << "    " << endl;
        cout << "1. Registrar un nuevo viaje." << endl;
        cout << "2. Listar todos los viajes." << endl;
        cout << "3. Buscar un viaje por identificador" << endl;
        cout << "4. Eliminar un viaje por identificador." << endl;
        cout << "5. Registrar un pasajero en un viaje." << endl;
        cout << "6. Listar todos los pasajeros de un viaje." << endl;
        cout << "7. Salir" << endl;
        cout << "Digite su opcion: ";
        cin >> opc;
        cout << " "<<endl;
        
        switch (opc) {
            case 1:
                crearviaje();
                raiz = insertar(raiz);
                break;  
            
            case 2:
               inOrden(raiz);
                break;


            case 3 :
             cout << "Digite su ID: ";
                int id;
                cin>> id;
                buscarporid(id, raiz);
                
                break;
          
            case 4:eliminar(raiz);
                break;
            case 5:
                Registrarpas();
                break;
            
            case 6:
                cout << "Digite el ID de la embarcacion: ";
                int idse;
                cin>> idse;
                listpas(idse);
                break;
            default :
                cout<<"La opcion digitada no pertenece a ninguna funcion en nuestro software."<<endl;
                break;
            case 7:
                cout<<"Hasta luego..."<<endl;
                break;
        }
    } while (opc != 7);
    return 0;
}