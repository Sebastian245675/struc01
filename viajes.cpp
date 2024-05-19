#include <iostream>

using namespace std;

struct viaje {
    int id;
    string matricula;
    string nombredembarcacion;
    string destino;
    double precio;
    int capacidad;
    viaje *izq;
    viaje *der;
    int altura;
    int año;
    int mes;
    int dia;
};
struct viaje*raiz, *aux;
int crearviaje();
struct viaje* insertar(struct viaje* viaje);
int obtenerAltura(struct viaje *n);
int mayor(int a, int b);
struct vaiaje* rotarDerecha(struct viaje *y);
struct viaje* rotarIzquierda(struct viaje *x);
int obtenerBalance(struct viaje *n);
void preOrden(struct viaje *viaje);                                                

int crearviaje() {
    aux = ((struct viaje *) malloc(sizeof(struct viaje)));
    cout << "ingrese la matricula: ";
    cin >> aux->matricula;
     cout << "ingrsese el nombre de la embarcacion ";
    cin >> aux-> nombredembarcacion;
      cout << "¡cual es el destino del viaje? ";
    cin >> aux-> destino;
     cout << "¡fechad del viaje? ";
    cin >> aux-> destino;
     cout << "ingrese el precio ";
    cin >> aux-> precio;
    aux->izq = NULL;
    aux->der = NULL;
    aux->altura = 1;
    return 0;
}
int buscarporid(){




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
    if (nodo == NULL) {
        return aux;
    }

    if (aux->value < viaje->value) {
        nodo->izq = insertar(viaje->izq);
    } else if (aux->value > viaje->value) {
        viaje->der = insertar(viaje->der);
    } else {
        return viaje;
    }

    viaje->altura = 1 + mayor(obtenerAltura(viaje->izq), obtenerAltura(viaje->der));

    int balance = obtenerBalance(viaje);

    if (balance > 1 && aux->value < viaje->izq->value) {
        return rotarDerecha(viaje);
    }

    if (balance < -1 && aux->value > viaje->der->value) {
        return rotarIzquierda(viaje);
    }

    if (balance > 1 && aux->value > nodo->izq->value) {
        viaje->izq = rotarIzquierda(viaje->izq);
        return rotarDerecha(viaje);
    }

    if (balance < -1 && aux->value < viaje->der->value) {
        nodo->der = rotarDerecha(viaje->der);
        return rotarIzquierda(viaje);
    }

    return viaje;
}

void preOrden(struct viaje *nodo) {
    if (nodo != NULL) {
        cout << nodo->value << " ";
        preOrden(nodo->izq);
        preOrden(nodo->der);
    }
}

int main() {
    raiz = NULL;
    int opc = 0;
    do {
        cout << "Menu de opciones" << endl;
        cout << "1. Registrar un nodo" << endl;
        cout << "2. Mostrar Arbol" << endl;
        cout << "3. Salir" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                crearviaje();
                raiz = insertar(raiz);
                break;
            case 2:
                buscarporid();
                break;
        }
    } while (opc != 3);
    return 0;
}