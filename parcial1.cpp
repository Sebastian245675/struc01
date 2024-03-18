#include <string>
#include <iostream>

using namespace std;

struct cabe {
    string nombre;
    int id;
    int cantidad;
    double precio;
    cabe* siguiente;
};

cabe* frente = nullptr;
cabe* final = nullptr;

void registrarProducto() {
    cabe* nuevoProducto = new cabe;
    cout << "Ingrese el nombre del producto: ";
    cin >> nuevoProducto->nombre;
    cout << "Ingrese el ID del producto: ";
    cin >> nuevoProducto->id;
    cout << "Ingrese la cantidad del producto: ";
    cin >> nuevoProducto->cantidad;
    cout << "Ingrese el precio del producto: ";
    cin >> nuevoProducto->precio;
    nuevoProducto->siguiente = nullptr;

    if (final == nullptr) {
        frente = final = nuevoProducto;
    } else {
        final->siguiente = nuevoProducto;
        final = nuevoProducto;
    }
    cout << "Producto registrado exitosamente." << endl;
}

void mostrarInventario() {
    if (frente == nullptr) {
        cout << "El inventario está vacío." << endl;
    } else {
        int i = 1;
        cabe* auxiliar = frente;
        cout << "Inventario:" << endl;
        while (auxiliar != nullptr) {
            cout << i << ". Nombre: " << auxiliar->nombre << ", ID: " << auxiliar->id << ", Cantidad: " << auxiliar->cantidad << ", Precio: $" << auxiliar->precio << endl;
            auxiliar = auxiliar->siguiente;
            i++;
        }
    }
}

void buscarProductoPorId(int id) {
    cabe* auxiliar = frente;
    while (auxiliar != nullptr) {
        if (auxiliar->id == id) {
            cout << "Información del producto:" << endl;
            cout << "Nombre: " << auxiliar->nombre << ", Cantidad: " << auxiliar->cantidad << ", Precio: $" << auxiliar->precio << endl;
            return;
        }
        auxiliar = auxiliar->siguiente;
    }
    cout << "Producto no encontrado." << endl;
}

void eliminarProducto(int id) {
    if (frente == nullptr) {
        cout << "El inventario está vacío." << endl;
        return;
    }
    if (frente->id == id) {
        cabe* temp = frente;
        frente = frente->siguiente;
        delete temp;
        cout << "Producto eliminado exitosamente." << endl;
        return;
    }
    cabe* anterior = frente;
    cabe* actual = frente->siguiente;
    while (actual != nullptr) {
        if (actual->id == id) {
            anterior->siguiente = actual->siguiente;
            if (actual == final) {
                final = anterior;
            }
            delete actual;
            cout << "Producto eliminado exitosamente." << endl;
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    cout << "Producto no encontrado." << endl;
}

double calcularValorTotal() {
    double total = 0.0;
    cabe* auxiliar = frente;
    while (auxiliar != nullptr) {
        total += auxiliar->cantidad * auxiliar->precio;
        auxiliar = auxiliar->siguiente;
    }
    return total;
}

double calcularPromedioPrecios() {
    if (frente == nullptr) {
        return 0.0;
    }
    double sumaPrecios = 0.0;
    int cantidadProductos = 0;
    cabe* auxiliar = frente;
    while (auxiliar != nullptr) {
        sumaPrecios += auxiliar->precio;
        cantidadProductos++;
        auxiliar = auxiliar->siguiente;
    }
    return sumaPrecios / cantidadProductos;
}

void venderProducto(int id, int cantidad) {
    cabe* auxiliar = frente;
    while (auxiliar != nullptr) {
        if (auxiliar->id == id) {
            if (auxiliar->cantidad < cantidad) {
                cout << "No hay suficientes existencias del producto para completar la venta." << endl;
                return;
            }
            double totalPagar = cantidad * auxiliar->precio;
            auxiliar->cantidad -= cantidad;
            cout << "Venta exitosa. Total a pagar: $" << totalPagar << endl;
            return;
        }
        auxiliar = auxiliar->siguiente;
    }
    cout << "Producto no encontrado." << endl;
}

int main() {
    int opcion;

    do {
        cout << "\n1. Registrar producto\n2. Mostrar inventario\n3. Buscar producto por ID\n4. Eliminar producto\n5. Calcular valor total del inventario\n6. Calcular promedio de precios\n7. Vender producto\n8. Salir\n";
        cout << "ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarProducto();
                break;
            case 2:
                mostrarInventario();
                break;
            case 3: {
                int id;
                cout << "Ingrese el ID del producto a buscar: ";
                cin >> id;
                buscarProductoPorId(id);
                break;
            }
            case 4: {
                int id;
                cout << "Ingrese el ID del producto a eliminar: ";
                cin >> id;
                eliminarProducto(id);
                break;
            }
            case 5:
                cout << "Valor total del inventario: $" << calcularValorTotal() << endl;
                break;
            case 6:
                cout << "Promedio de precios: $" << calcularPromedioPrecios() << endl;
                break;
            case 7: {
                int id, cantidad;
                cout << "Ingrese el ID del producto a vender: ";
                cin >> id;
                cout << "Ingrese la cantidad de unidades a vender: ";
                cin >> cantidad;
                venderProducto(id, cantidad);
                break;
            }
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 8);

    cabe* auxiliar;
    while (frente != nullptr) {
        auxiliar = frente;
        frente = frente->siguiente;
        delete auxiliar;
    }

    return 0;
}