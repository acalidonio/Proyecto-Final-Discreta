#include <iostream>

using namespace std;

struct Paciente {
    string nombre;
    int edad;
    bool tieneDiabetes;
    bool tieneHipertension;
};

const int MAX_PACIENTES = 50;

void Menu();
void ingresarPaciente(Paciente pacientes[], int& totalPacientes);
void mostrarRegistros(Paciente pacientes[], int totalPacientes);
double calcular_prob_no_ocurra();

//Variables Globales
//int prob_total = 1;

int main() {
    Paciente pacientes[MAX_PACIENTES];
    int totalPacientes = 0;

    int opcion;
    do {
        Menu();
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case 1:
                ingresarPaciente(pacientes, totalPacientes); break;
            case 2:
                mostrarRegistros(pacientes, totalPacientes); break;
            case 3:
                cout << "\nGracias por utilizar el programa de estimacion de peligro para pacientes con Covid. \n";
                cout << "\nSiga las medidas de bioseguridad indicadas por su doctor y mantenga constante el uso de mascarilla. Gracias\n\n" << endl;
                break;
            default:
                cout << "\nOpcion no valida. Por favor, seleccione una opcion valida." << endl;
        }
    } while (opcion != 3);

    return 0;
}

//-----------
void Menu() {
    system("cls");
    cout << "Bienvenido a la estimacion de peligro de pacientes con Covid\n" << endl;
    cout << "1. Ingresar nuevo paciente" << endl;
    cout << "2. Mostrar registros y calcular tasa de mortalidad" << endl;
    cout << "3. Salir" << endl;
}

//-----------
void ingresarPaciente(Paciente pacientes[], int& totalPacientes) {
    if (totalPacientes < MAX_PACIENTES) {
        Paciente nuevoPaciente;
        cout << "\nIngrese el nombre del paciente: ";
        cin.ignore();  // Ignorar el salto de linea pendiente
        getline(cin, nuevoPaciente.nombre);
        cout << "\nIngrese la edad del paciente: ";
        cin >> nuevoPaciente.edad;
        cout << "\nTiene diabetes (1: Si, 0: No): ";
        cin >> nuevoPaciente.tieneDiabetes;
        cout << "\nTiene hipertension? (1: Si, 0: No): ";
        cin >> nuevoPaciente.tieneHipertension;

        pacientes[totalPacientes++] = nuevoPaciente;
        cout << "\nRegistro ingresado correctamente." << endl;
    } else {
        cout << "\nSe ha alcanzado el limite de registros (50). No se pueden ingresar mas pacientes." << endl;
    }
}

//---------------------
void mostrarRegistros(Paciente pacientes[], int totalPacientes) {
    cout << "\nRegistros de pacientes:" << endl;

    for (int i = 0; i < totalPacientes; ++i) {
        cout << "\nNombre: " << pacientes[i].nombre << ", Edad: " << pacientes[i].edad << ", Diabetes: ";
        cout << (pacientes[i].tieneDiabetes ? "Si" : "No") << ", Hipertension: ";
        cout << (pacientes[i].tieneHipertension ? "Si" : "No") << endl;

        // Calcular tasa de mortalidad segun las condiciones dadas
        double tasaMortalidad = 0.0;
        if (pacientes[i].edad >= 0 && pacientes[i].edad <= 5) {
            tasaMortalidad = 2.4;
        }else if  (pacientes[i].edad >= 6 && pacientes[i].edad <= 9)   {
            tasaMortalidad = 0.4;
        }else if  (pacientes[i].edad >= 10 && pacientes[i].edad <= 39) {
            tasaMortalidad = 0.4;
        } else if (pacientes[i].edad >= 40 && pacientes[i].edad <= 49) {
            tasaMortalidad = 0.4;
        } else if (pacientes[i].edad >= 50 && pacientes[i].edad <= 59) {
            tasaMortalidad = 1.3;
        } else if (pacientes[i].edad >= 60 && pacientes[i].edad <= 69) {
            tasaMortalidad = 3.6;
        } else if (pacientes[i].edad >= 70 && pacientes[i].edad <= 79) {
            tasaMortalidad = 8.0;
        } else if (pacientes[i].edad >= 80) {
            tasaMortalidad = 14.8;
        }

        if (pacientes[i].tieneDiabetes) {
            tasaMortalidad += 2.5;
        }

        if (pacientes[i].tieneHipertension) {
            tasaMortalidad += 6.0;
        }

        cout << "\nTasa de mortalidad estimada: " << tasaMortalidad << "%\n" << endl;
        cout << "------------------------\n\n" << endl;
    }
}

double calcular_prob_no_ocurra()
{
    //CALCULANDO LA PROB QUE NO OCURRA UN EVENTO (1 - P(A))
    

}





    










