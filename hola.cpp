#include <iostream>
#include <string>

using namespace std;

struct Paciente {
    string nombre;
    int Documento;
    Paciente* siguiente;
};

Paciente* cabe = nullptr;

void registrarPaciente() {
    Paciente* nuevoPaciente = new Paciente;
    cout << "Ingrese el nombre del paciente: ";
    cin >> nuevoPaciente->nombre;
    cout << "Ingrese el número de documento del paciente: ";
    cin >> nuevoPaciente->Documento;
    nuevoPaciente->siguiente = nullptr;

    if (cabe == nullptr) {
        cabe= nuevoPaciente;
    } else {
        Paciente* auxiliar = cabe;
        while (auxiliar->siguiente != nullptr) {
            auxiliar = auxiliar->siguiente;
        }
        auxiliar->siguiente = nuevoPaciente;
    }
    cout << "Paciente registrado exitosamente." << endl;
}

void mostrarPacientes() {
    if (cabe == nullptr) {
        cout << "No hay pacientes registrados." << endl;
    } else {
        int i = 1;
        Paciente* auxiliar = cabe;
        cout << "Pacientes registrados:" << endl;
        while (auxiliar != nullptr) {
            cout << i << ". Nombre: " << auxiliar->nombre << ", Documento: " << auxiliar->Documento << endl;
            auxiliar = auxiliar->siguiente;
            i++;
        }
    }
}

int main() {
    int opcion;

    do {
        cout << "\n1. Registrar paciente\n2. Mostrar pacientes\n3. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarPaciente();
                break;
            case 2:
                mostrarPacientes();
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 3);

    
    Paciente* auxiliar;
    while (cabe!= nullptr) {
        auxiliar = cabe;
        cabe = cabe->siguiente;
        delete auxiliar;
    }

    return 0;
}