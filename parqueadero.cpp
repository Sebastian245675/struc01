//creadores juan sebastian salazar aguirre
// stive montaño*//



#include <iostream>
#include <malloc.h>

using namespace std;

struct nodoc {      
    int id; 
    int valor;
    nodoc* sig; 
};

struct nodoM {      
    int id; 
    int valor;
    nodoM* sig; 
};

nodoc *top = NULL;
nodoM *top2 = NULL;

int registraCA() {
    nodoc* nuevo_nodo = (nodoc*)malloc(sizeof(nodoc));
    if (nuevo_nodo == NULL) {
        cout << "Error al asignar memoria." << endl;
        return -1;
    }
    nuevo_nodo->valor = 1000;
    nuevo_nodo->sig = top;
    if (top == NULL) {
        nuevo_nodo->id = 1;
    } else {
        nuevo_nodo->id = top->id + 1;
    }
    cout << "\t Un carro ha sido registrado." << endl;
    top = nuevo_nodo;
    return 0;
}

int mostrarCA() {
    cout << "Carros:" << endl;
    nodoc* auxcarro = top;
    int movimientosC = 0;
    while (auxcarro != NULL) {
        cout << "ID: " << auxcarro->id << ", Valor a pagar: " << auxcarro->valor + (movimientosC * 100) << " pesos" << endl;
        auxcarro = auxcarro->sig;
        movimientosC++;
    }
    return 0;
}

int eliminarCA() {
    int opc;
    mostrarCA();
    cout << "Digite el Id del carro que quiere eliminar: ";
    cin >> opc;
    if (top == NULL) {
        cout << "La lista de carros está vacía." << endl;
        return 0;
    }
    nodoc* actual = top;
    nodoc* anterior = NULL;
    while (actual != NULL && actual->id != opc) {
        anterior = actual;
        actual = actual->sig;
    }
    if (actual == NULL) {
        cout << "Carro no encontrado." << endl;
        return 0;
    }
    if (anterior == NULL) {
        top = actual->sig;
    } else {
        anterior->sig = actual->sig;
    }
    cout << "Carro eliminado: ID " << actual->id << endl;
    free(actual);
    return 0;
}

int registraMO() {
    nodoM* nuevo_nodo = (nodoM*)malloc(sizeof(nodoM));
    if (nuevo_nodo == NULL) {
        cout << "Error al asignar memoria." << endl;
        return -1;
    }
    nuevo_nodo->valor = 500;
    nuevo_nodo->sig = top2;
    if (top2 == NULL) {
        nuevo_nodo->id = 1;
    } else {
        nuevo_nodo->id = top2->id + 1;
    }
    cout << "\t Una moto ha sido registrada." << endl;
    top2 = nuevo_nodo;
    return 0;
}

int mostrarMO() {
    cout << "Motos:" << endl;
    nodoM* auxmoto = top2;
    int movimientosM = 0;
    while (auxmoto != NULL) {
        cout << "ID: " << auxmoto->id << ", Valor a pagar: " << auxmoto->valor + (movimientosM * 50) << " pesos" << endl;
        auxmoto = auxmoto->sig;
        movimientosM++;
    }
    return 0;
}

int eliminarMO() {
    int opc;
    mostrarMO();
    cout << "Digite el Id de la moto que quiere eliminar: ";
    cin >> opc;
    if (top2 == NULL) {
        cout << "La lista de motos está vacía." << endl;
        return 0;
    }
    nodoM* actual = top2;
    nodoM* anterior = NULL;
    while (actual != NULL && actual->id != opc) {
        anterior = actual;
        actual = actual->sig;
    }
    if (actual == NULL) {
        cout << "Moto no encontrada." << endl;
        return 0;
    }
    if (anterior == NULL) {
        top2 = actual->sig;
    } else {
        anterior->sig = actual->sig;
    }
    cout << "Moto eliminada: ID " << actual->id << endl;
    free(actual);
    return 0;
}

int defa() {
    cout << "La opción digitada no hace parte de ninguna función en nuestro software." << endl;
    return 0;
}

int main() {
    int opc;
    do {
        cout << "       " << endl;
        cout << "       " << endl;
        cout << "\t MENU" << endl;
        cout << "1. Registrar Carro" << endl;
        cout << "2. Registrar Moto" << endl;
        cout << "3. Mostrar Carros" << endl;
        cout << "4. Mostrar Motos" << endl;
        cout << "5. Eliminar Carro" << endl;
        cout << "6. Eliminar Moto" << endl;
        cout << "7. Salir" << endl;
        cout << "Digite su opción: ";
        cin >> opc;

        switch (opc) {
            case 1: 
                registraCA(); 
                break;
            case 2: 
                registraMO(); 
                break;
            case 3: 
                mostrarCA(); 
                break;
            case 4: 
                mostrarMO(); 
                break;
            case 5: 
                eliminarCA(); 
                break;
            case 6: 
                eliminarMO(); 
                break;
            default:
                defa(); 
                break;    
        }
    } while(opc != 7);
    return 0;
}