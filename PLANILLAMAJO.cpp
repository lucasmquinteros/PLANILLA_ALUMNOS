#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void guardarDatos(const vector<string>& apellidos, const vector<vector<float>>& calificaciones) {
    ofstream archivo("datos_alumnos.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < apellidos.size(); ++i) {
            archivo << apellidos[i];
            for (size_t j = 0; j < calificaciones[i].size(); ++j) {
                archivo << ' ' << calificaciones[i][j];
            }
            archivo << '\n';
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo para guardar los datos." << endl;
    }
}

void cargarDatos(vector<string>& apellidos, vector<vector<float>>& calificaciones) {
    ifstream archivo("datos_alumnos.txt");
    if (archivo.is_open()) {
        string apellido;
        float calificacion;
        while (archivo >> apellido) {
            apellidos.push_back(apellido);
            vector<float> notas;
            while (archivo.peek() != '\n' && archivo >> calificacion) {
                notas.push_back(calificacion);
            }
            calificaciones.push_back(notas);
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo para cargar los datos." << endl;
    }
}

void mostrarDatos(const vector<string>& apellidos, const vector<vector<float>>& calificaciones) {
    for (size_t i = 0; i < apellidos.size(); ++i) {
        cout << apellidos[i] << ": ";
        for (size_t j = 0; j < calificaciones[i].size(); ++j) {
            cout << ' ' << calificaciones[i][j];
        }
        cout << '\n';
    }
}

void ingresarDatosAlumnos(vector<string>& apellidos, vector<vector<float>>& calificaciones) {
    string apellido;
    for(int i = 0; i < 24; ++i) {
        cout << "Ingrese el apellido del alumno " << i + 1 << ": ";
        cin >> apellido;
        apellidos.push_back(apellido);
        calificaciones.push_back(vector<float>());
    }
}

void ingresarNotas(vector<vector<float>>& calificaciones, const vector<string>& apellidos) {
    int notas, cantidadNotas;
        cout << "Ingrese la cantidad de notas para cada alumno ";
        cin >> cantidadNotas;
    for (size_t i = 0; i < apellidos.size(); ++i) {
        for (int j = 0; j < cantidadNotas; ++j) {
            cout << "Ingrese la calificacion del alumno " << apellidos[i] << ": ";
            cin >> notas;
            calificaciones[i].push_back(notas);
        }
    }
}

int main() {
    vector<vector<float>> calificaciones;
    vector<string> apellidos;

    cargarDatos(apellidos, calificaciones);

    cout << "Por favor si va a ingresar alumnos que lo haga por unica vez\n";
    cout << "Que quiere ingresar? \n 1. Alumnos \n 2. Notas \n 3. Mostrar calificaciones \n 4. Salir \n";
    int opcion;
    cin >> opcion;
    while (opcion != 4){
        switch(opcion) {
            case 1:
                ingresarDatosAlumnos(apellidos, calificaciones);
                guardarDatos(apellidos, calificaciones);
                break;
            case 2:
                ingresarNotas(calificaciones, apellidos);
                guardarDatos(apellidos, calificaciones);
                break;
            case 3:
                mostrarDatos(apellidos, calificaciones);
                break;
        }
        cout << "\nQue quiere ingresar? \n 1. Alumnos \n 2. Notas \n 3. Mostrar calificaciones \n 4. Salir \n";
        cin >> opcion;
    }

    return 0;
}
