//Daniel Steve Montaño A.
//Sebastian Salazar.
#include <iostream>
#include <malloc.h>
using namespace std;

struct DatosEst {
    // Identificación intrínseca del individuo.
    char nombre[20];
    char apellido[20];
    int codigo;

    // Fecha de nacimiento
    int ano;
    int mes;
    int dia;

    // Variable para identificar si una fecha es mayor o menor que otra.
    int cont;

    // Apuntadores
    DatosEst *izq, *der;
};

DatosEst *raiz_codigo = NULL;
DatosEst *raiz_fecha = NULL;

void pocisionar(DatosEst *nuevo, DatosEst *&raiz) {
    if (raiz == NULL) {
        raiz = nuevo;
    } else {
        if (nuevo->codigo < raiz->codigo) {
            pocisionar(nuevo, raiz->izq);
        } else if (nuevo->codigo > raiz->codigo) {
            pocisionar(nuevo, raiz->der);
        } else {
            if (nuevo->cont > raiz->cont) {
                pocisionar(nuevo, raiz->der);
            } else {
                pocisionar(nuevo, raiz->izq);
            }
        }
    }
}

void pocisionar_fecha(DatosEst *nuevo, DatosEst *&raiz) {
    if (raiz == NULL) {
        raiz = nuevo;
    } else {
        if (nuevo->cont < raiz->cont) {
            pocisionar_fecha(nuevo, raiz->izq);
        } else if (nuevo->cont > raiz->cont) {
            pocisionar_fecha(nuevo, raiz->der);
        } else {
            pocisionar(nuevo, raiz->der);
        }
    }
}

void registrar() {
    DatosEst *aux = new DatosEst;

    cout << "\tBienvenido querido usuario" << endl;
    cout << "Este software cumple con todas las especificaciones dadas" << endl;
    cout << "\tDisfrútalo" << endl;
    cout << "    " << endl;
    cout << "    " << endl;

    cout << "Ingrese su nombre: ";
    cin >> aux->nombre;

    cout << "Ingrese su apellido: ";
    cin >> aux->apellido;

    cout << "\t¡DATO IMPORTANTE!" << endl;
    cout << "\tLa fecha debe estar en formato AÑO-MES-DIA" << endl;
    cout << "\tEjemplo -> 2024-05-12" << endl;
    cout << "\tSe debe indexar la fecha tal cual la muestra el ejemplo" << endl;
    cout << "\tEjemplo -> 2024-05-12" << endl;
    cout << "Ingresando la fecha..... "<<endl;
    cout << "Ingrese el AÑO: ";
    cin >> aux->ano;
    cout << "Ingrese el MES: ";
    cin >> aux->mes;
    cout << "Ingrese el DIA: ";
    cin >> aux->dia;
    cout << "Fecha ingresada adecuadamente."<<endl;
    cout << "     "<<endl;

    cout << "Ingrese el código: ";
    cin >> aux->codigo;

    aux->cont = aux->ano + aux->mes + aux->dia;
    aux->izq = aux->der = NULL;

    pocisionar(aux, raiz_codigo);
    pocisionar_fecha(aux, raiz_fecha);
}

void mostrarPreOr_Codigo(DatosEst *nodo) {
    if (nodo != NULL) {
        cout << "Código: " << nodo->codigo << ", Nombre: " << nodo->nombre << " " << nodo->apellido << ", Fecha de Nacimiento: " << nodo->ano << "-" << nodo->mes << "-" << nodo->dia << endl;
        mostrarPreOr_Codigo(nodo->izq);
        mostrarPreOr_Codigo(nodo->der);
    }
}

void mostrarInOr_Codigo(DatosEst *nodo) {
    if (nodo != NULL) {
        mostrarInOr_Codigo(nodo->izq);
        cout << "Código: " << nodo->codigo << ", Nombre: " << nodo->nombre << " " << nodo->apellido << ", Fecha de Nacimiento: " << nodo->ano << "-" << nodo->mes << "-" << nodo->dia << endl;
        mostrarInOr_Codigo(nodo->der);
    }
}

void mostrarPostOr_Codigo(DatosEst *nodo) {
    if (nodo != NULL) {
        mostrarPostOr_Codigo(nodo->izq);
        mostrarPostOr_Codigo(nodo->der);
        cout << "Código: " << nodo->codigo << ", Nombre: " << nodo->nombre << " " << nodo->apellido << ", Fecha de Nacimiento: " << nodo->ano << "-" << nodo->mes << "-" << nodo->dia << endl;
    }
}

void mostrarPreOr_Fecha(DatosEst *nodo) {
    if (nodo != NULL) {
        cout << "Código: " << nodo->codigo << ", Nombre: " << nodo->nombre << " " << nodo->apellido << ", Fecha de Nacimiento: " << nodo->ano << "-" << nodo->mes << "-" << nodo->dia << endl;
        mostrarPreOr_Fecha(nodo->izq);
        mostrarPreOr_Fecha(nodo->der);
    }
}

void mostrarInOr_Fecha(DatosEst *nodo) {
    if (nodo != NULL) {
        mostrarInOr_Fecha(nodo->izq);
        cout << "Código: " << nodo->codigo << ", Nombre: " << nodo->nombre << " " << nodo->apellido << ", Fecha de Nacimiento: " << nodo->ano << "-" << nodo->mes << "-" << nodo->dia << endl;
        mostrarInOr_Fecha(nodo->der);
    }
}

void mostrarPostOr_Fecha(DatosEst *nodo) {
    if (nodo != NULL) {
        mostrarPostOr_Fecha(nodo->izq);
        mostrarPostOr_Fecha(nodo->der);
        cout << "Código: " << nodo->codigo << ", Nombre: " << nodo->nombre << " " << nodo->apellido << ", Fecha de Nacimiento: " << nodo->ano << "-" << nodo->mes << "-" << nodo->dia << endl;
    }
}

DatosEst *buscar_codigo(DatosEst *raiz, int codigo) {
    if (raiz == NULL || raiz->codigo == codigo) {
        return raiz;
    }

    if (raiz->codigo < codigo) {
        return buscar_codigo(raiz->der, codigo);
    }

    return buscar_codigo(raiz->izq, codigo);
}

DatosEst *buscar_fecha(DatosEst *raiz, int cont) {
    if (raiz == NULL || raiz->cont == cont) {
        return raiz;
    }

    if (raiz->cont < cont) {
        return buscar_fecha(raiz->der, cont);
    }

    return buscar_fecha(raiz->izq, cont);
}

DatosEst *minimoValorNodo(DatosEst *nodo) {
    DatosEst *actual = nodo;
    while (actual && actual->izq != NULL) {
        actual = actual->izq;
    }
    return actual;
}

DatosEst *eliminarNodo(DatosEst *raiz, int codigo) {
    if (raiz == NULL) {
        return raiz;
    }

    // Buscar en el subárbol derecho para eliminar
    if (codigo > raiz->codigo) {
        raiz->der = eliminarNodo(raiz->der, codigo);
    }
    // Buscar en el subárbol izquierdo para eliminar
    else if (codigo < raiz->codigo) {
        raiz->izq = eliminarNodo(raiz->izq, codigo);
    }
    // Si el nodo tiene solo un hijo o no tiene hijos
    else {
        // Nodo con solo un hijo o sin hijos
        if (raiz->izq == NULL) {
            DatosEst *temp = raiz->der;
            free(raiz);
            return temp;
        } else if (raiz->der == NULL) {
            DatosEst *temp = raiz->izq;
            free(raiz);
            return temp;
        }

        // Nodo con dos hijos: obtener sucesor inorden
        DatosEst *temp = minimoValorNodo(raiz->der);

        // Copiar el contenido del sucesor inorden al nodo actual
        raiz->codigo = temp->codigo;
        raiz->ano = temp->ano;
        raiz->mes = temp->mes;
        raiz->dia = temp->dia;
        raiz->cont = temp->cont;

        // Eliminar el sucesor inorden
        raiz->der = eliminarNodo(raiz->der, temp->codigo);
    }
    return raiz;
}

void eliminar() {
    int codigo;
    cout << "Ingrese el código del estudiante que desea eliminar: ";
    cin >> codigo;

    raiz_codigo = eliminarNodo(raiz_codigo, codigo);
    // Asegúrate de eliminar el nodo en el árbol ordenado por fecha también
    // raiz_fecha = eliminarNodo(raiz_fecha, codigo);
}

void salir() {
    cout << "\tQuerido usuario." << endl;
    cout << "Muchas gracias por usar los servicios de nuestro software." << endl;
    cout << "\tHasta luego." << endl;
}

int main() {
    int opc;
    do {
        cout << "\t MENU" << endl;
        cout << "1. Registrar Estudiante" << endl;
        cout << "2. Mostrar en Pre-Orden el Org_Código" << endl;
        cout << "3. Mostrar en Post-Orden el Org_Código" << endl;
        cout << "4. Mostrar en In-Orden el Org_Código" << endl;
        cout << "5. Mostrar en Pre-Orden el Org_Fecha" << endl;
        cout << "6. Mostrar en Post-Orden el Org_Fecha" << endl;
        cout << "7. Mostrar en In-Orden el Org_Fecha" << endl;
        cout << "8. Buscar por Código" << endl;
        cout << "9. Buscar por Fecha" << endl;
        cout << "10. Eliminar Registro" << endl;
        cout << "11. Salir" << endl;
        cout << "Digite la opción que desea: ";
        cin >> opc;

        switch (opc) {
            case 1:
                registrar();
                break;
            case 2:
                mostrarPreOr_Codigo(raiz_codigo);
                break;
            case 3:
                mostrarPostOr_Codigo(raiz_codigo);
                break;
            case 4:
                mostrarInOr_Codigo(raiz_codigo);
                break;
            case 5:
                mostrarPreOr_Fecha(raiz_fecha);
                break;
            case 6:
                mostrarPostOr_Fecha(raiz_fecha);
                break;
            case 7:
                mostrarInOr_Fecha(raiz_fecha);
                break;
            case 8: {
                int codigo;
                cout << "Ingrese el código a buscar: ";
                cin >> codigo;
                DatosEst *encontrado = buscar_codigo(raiz_codigo, codigo);
                if (encontrado != NULL) {
                    cout << "Estudiante encontrado: " << encontrado->nombre << " " << encontrado->apellido << endl;
                } else {
                    cout << "Estudiante no encontrado." << endl;
                }
                break;
            }
            case 9: {
                int cont;
                cout << "Ingrese la fecha a buscar (AÑO-MES-DIA): ";
                cin >> cont;
                DatosEst *encontrado = buscar_fecha(raiz_fecha, cont);
                if (encontrado != NULL) {
                    cout << "Estudiante encontrado: " << encontrado->nombre << " " << encontrado->apellido << endl;
                } else {
                    cout << "Estudiante no encontrado." << endl;
                }
                break;
            }
            case 10:
                eliminar();
                break;
            case 11:
                salir();
                break;
            default:
                cout << "\tQuerido usuario." << endl;
                cout << "La opción digitada no pertenece a ninguna función de los servicios de nuestro software." << endl;
                cout << "\tIntenta de nuevo." << endl;
                break;
        }
    } while (opc != 11);

    return 0;
}