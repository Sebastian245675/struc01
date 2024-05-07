
}// Juan Sebastian Salazar Aguirre
// stiven montaño


#include <iostream>

#include <malloc.h>
using namespace std;

struct Estudiante {
    char nombre[20];
    char apellido[20];
    int codigo;
    int ano;
    int mes;
    int dia;
    int cont;
    Estudiante *izq, *der;
};

Estudiante *raiz_por_codigo = NULL;
Estudiante *raiz_por_fecha = NULL;

// Variables globales para buscar por fecha
int buscar_ano;
int buscar_mes;
int buscar_dia;

Estudiante *minimoValorNodo(Estudiante *nodo) {
    Estudiante *actual = nodo;
    while (actual && actual->izq != NULL) {
        actual = actual->izq;
    }
    return actual;
}

void posicionar(Estudiante *nuevo, Estudiante *&raiz) {
    if (raiz == NULL) {
        raiz = nuevo;
    } else {
        if (nuevo->codigo < raiz->codigo) {
            posicionar(nuevo, raiz->izq);
        } else if (nuevo->codigo >= raiz->codigo) {
            posicionar(nuevo, raiz->der);
        }
    }
}

void posicionar_fecha(Estudiante *nuevo, Estudiante *&raiz) {
    if (raiz == NULL) {
        raiz = nuevo;
    } else {
        if (nuevo->cont < raiz->cont) {
            posicionar_fecha(nuevo, raiz->izq);
        } else if (nuevo->cont >= raiz->cont) {
            posicionar_fecha(nuevo, raiz->der);
        }
    }
}

void registrar_fecha(Estudiante *aux) {
    Estudiante *aux1 = new Estudiante;
    for (int i = 0; i < 20; ++i) {
        aux1->nombre[i] = aux->nombre[i];
        aux1->apellido[i] = aux->apellido[i];
    }
    aux1->ano = aux->ano;
    aux1->mes = aux->mes;
    aux1->dia = aux->dia;
    aux1->codigo = aux->codigo;
    aux1->cont = aux->cont;

    posicionar_fecha(aux1, raiz_por_fecha);
}

void registrar() {
    Estudiante *aux = new Estudiante;

    cout << "\tBienvenido querido usuario" << endl;
    cout << "Este software cumple con todas las especificaciones dadas" << endl;
    cout << "\tDisfrútalo" << endl;
    cout << "    " << endl;
    cout << "    " << endl;

    cout << "Ingrese su nombre: ";
    cin >> aux->nombre;

    cout << "Ingrese su apellido: ";
    cin >> aux->apellido;

    cout << "Ingrese el año: ";
    cin >> aux->ano;

    cout << "Ingrese el mes: ";
    cin >> aux->mes;

    cout << "Ingrese el dia: ";
    cin >> aux->dia;

    cout << "Ingrese el código: ";
    cin >> aux->codigo;

    aux->cont = aux->ano + aux->mes + aux->dia;
    aux->izq = aux->der = NULL;

    posicionar(aux, raiz_por_codigo);
    registrar_fecha(aux);
}

void mostrarPreOr_Codigo(Estudiante *nodo) {
    if (nodo != NULL) {
        cout << "Código: " << nodo->codigo << ", Nombre: " << nodo->nombre << " " << nodo->apellido << ", Fecha de Nacimiento: " << nodo->ano << "-" << nodo->mes << "-" << nodo->dia << endl;
        mostrarPreOr_Codigo(nodo->izq);
        mostrarPreOr_Codigo(nodo->der);
    }
}

void mostrarInOr_Codigo(Estudiante *nodo) {
    if (nodo != NULL) {
        mostrarInOr_Codigo(nodo->izq);
        cout << "Código: " << nodo->codigo << ", Nombre: " << nodo->nombre << " " << nodo->apellido << ", Fecha de Nacimiento: " << nodo->ano << "-" << nodo->mes << "-" << nodo->dia << endl;
        mostrarInOr_Codigo(nodo->der);
    }
}

void mostrarPostOr_Codigo(Estudiante *nodo) {
    if (nodo != NULL) {
        mostrarPostOr_Codigo(nodo->izq);
        mostrarPostOr_Codigo(nodo->der);
        cout << "Código: " << nodo->codigo << ", Nombre: " << nodo->nombre << " " << nodo->apellido << ", Fecha de Nacimiento: " << nodo->ano << "-" << nodo->mes << "-" << nodo->dia << endl;
    }
}

void mostrarPreOr_Fecha(Estudiante *nodo) {
    if (nodo != NULL) {
        cout << "Código: "<< nodo->codigo << ", Nombre: " << nodo->nombre << " " << nodo->apellido << ", Fecha de Nacimiento: " << nodo->ano << "-" << nodo->mes << "-" << nodo->dia << endl;
        mostrarPreOr_Fecha(nodo->izq);
        mostrarPreOr_Fecha(nodo->der);
    }
}

void mostrarInOr_Fecha(Estudiante *nodo) {
    if (nodo != NULL) {
        mostrarInOr_Fecha(nodo->izq);
        cout << "Código: " << nodo->codigo << ", Nombre: " << nodo->nombre << " " << nodo->apellido << ", Fecha de Nacimiento: " << nodo->ano << "-" << nodo->mes << "-" << nodo->dia << endl;
        mostrarInOr_Fecha(nodo->der);
    }
}

void mostrarPostOr_Fecha(Estudiante *nodo) {
    if (nodo != NULL) {
        mostrarPostOr_Fecha(nodo->izq);
        mostrarPostOr_Fecha(nodo->der);
        cout << "Código: " << nodo->codigo << ", Nombre: " << nodo->nombre << " " << nodo->apellido << ", Fecha de Nacimiento: " << nodo->ano << "-" << nodo->mes << "-" << nodo->dia << endl;
    }
}

Estudiante *buscar_codigo(Estudiante *raiz, int codigo) {
    if (raiz == NULL || raiz->codigo == codigo) {
        return raiz;
    }

    if (raiz->codigo < codigo) {
        return buscar_codigo(raiz->der, codigo);
    }

    return buscar_codigo(raiz->izq, codigo);
}

Estudiante *buscar_fecha(Estudiante *raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    if (raiz->ano == buscar_ano && raiz->mes == buscar_mes && raiz->dia == buscar_dia) {
        return raiz;
    }

    if (raiz->ano < buscar_ano || (raiz->ano == buscar_ano && raiz->mes < buscar_mes) || (raiz->ano == buscar_ano && raiz->mes == buscar_mes&& raiz->dia < buscar_dia)) {
        return buscar_fecha(raiz->der);
    }

    return buscar_fecha(raiz->izq);
}

Estudiante *eliminarNodo(Estudiante *raiz, int codigo) {
    if (raiz == NULL) {
        return raiz;
    }

    if (raiz->codigo > codigo) {
        raiz->izq = eliminarNodo(raiz->izq, codigo);
    } else if (raiz->codigo < codigo) {
        raiz->der = eliminarNodo(raiz->der, codigo);
    } else {
        if (raiz->izq == NULL) {
            Estudiante *temp = raiz->der;
            delete raiz;
            return temp;
        } else if (raiz->der == NULL) {
            Estudiante *temp = raiz->izq;
            delete raiz;
            return temp;
        }

        Estudiante *temp = minimoValorNodo(raiz->der);

        raiz->codigo = temp->codigo;
        raiz->ano = temp->ano;
        raiz->mes = temp->mes;
        raiz->dia = temp->dia;
        raiz->cont = temp->cont;

        raiz->der = eliminarNodo(raiz->der, temp->codigo);
    }
    return raiz;
}

void eliminar() {
    int codigo;
    cout << "Ingrese el código del estudiante que desea eliminar: ";
    cin >> codigo;

    raiz_por_codigo = eliminarNodo(raiz_por_codigo, codigo);

    cout << "Se eliminó al estudiante." << endl;
}

void salir() {
    cout << "\tQuerido usuario." << endl;
    cout << "Muchas gracias por usar los servicios de nuestro software." << endl;
    cout << "\tHasta luego." << endl;
}

int main() {
    int opcion;
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
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrar();
                break;
            case 2:
                mostrarPreOr_Codigo(raiz_por_codigo);
                break;
            case 3:
                mostrarPostOr_Codigo(raiz_por_codigo);
                break;
            case 4:
                mostrarInOr_Codigo(raiz_por_codigo);
                break;
            case 5:
                mostrarPreOr_Fecha(raiz_por_fecha);
                break;
            case 6:
                mostrarPostOr_Fecha(raiz_por_fecha);
                break;
            case 7:
                mostrarInOr_Fecha(raiz_por_fecha);
                break;
            case 8: {
                int codigo;
                cout << "Ingrese el código a buscar: ";
                cin >> codigo;
                Estudiante *encontrado = buscar_codigo(raiz_por_codigo, codigo);
                if (encontrado != NULL) {
                    cout << "Estudiante encontrado: " << encontrado->nombre << " " << encontrado->apellido << endl;
                } else {
                    cout << "Estudiante no encontrado." << endl;
                }
                break;
            }
            case 9: {
                cout << "Ingrese la fecha a buscar (AÑO MES DIA): "<<endl;
                cout << "Ingrese el AÑO: ";
                cin >> buscar_ano;
                cout << "Ingrese el MES: ";
                cin >> buscar_mes;
                cout << "Ingrese el DIA: ";
                cin >> buscar_dia;
                Estudiante *encontrado = buscar_fecha(raiz_por_fecha);
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
    } while (opcion != 11);

    return 0;
}