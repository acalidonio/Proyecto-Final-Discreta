#include <iostream>

using namespace std;

// Declarar estructura que guarda datos de paciente
struct Paciente
{
    string nombre;
    int edad;
    bool tieneDiabetes;
    bool tieneHipertension;
};

// Variables Globales
const int MAX_PACIENTES = 50;
// int prob_total = 1;

// Declarar funciones del programa
void Menu();
void ingresarPaciente(Paciente pacientes[], int &totalPacientes);
void mostrarRegistros(Paciente pacientes[], int totalPacientes);
double calculoProbabilidadOcurrencia();

// Función main
int main()
{
    // se declaran las variables a utilizar
    Paciente pacientes[MAX_PACIENTES];
    int totalPacientes = 0;
    int opcion;

    // se crea un menu de opciones
    do
    {
        // se llama a la función menu que muestra el texto de opciones y luego se pide seleccionar una opción
        Menu();
        cin >> opcion;
        // cout << "el total de pctes es igual a " << totalPacientes << "\n" << endl; // se muestra el total de pacientes (debug)

        switch (opcion)
        {
        case 1:
            ingresarPaciente(pacientes, totalPacientes);
            break;
        case 2:
            mostrarRegistros(pacientes, totalPacientes);
            break;
        case 3:
            cout << "\nGracias por utilizar el programa de estimacion de peligro para pacientes con Covid. \n";
            cout << "\nSiga las medidas de bioseguridad indicadas por su doctor y mantenga constante el uso de mascarilla. Gracias!\n\n"
                 << endl;
            break;
        default:
            cout << "\nOpcion no valida. Por favor, seleccione una opcion valida.\n"
                 << endl;
        }
    } while (opcion != 3);

    return 0;
}

// función menu
void Menu()
{
    cout << "Bienvenido a la estimacion de peligro de pacientes con Covid\n"
         << endl;
    cout << "1. Ingresar nuevo paciente" << endl;
    cout << "2. Mostrar registros y calcular tasa de mortalidad" << endl;
    cout << "3. Salir" << endl;
    cout << "\nSeleccione una opcion: ";
}

// Función ingresarPaciente
void ingresarPaciente(Paciente pacientes[], int &totalPacientes)
{
    // el if verifica si se ha llegado al límite de pacientes especificados al inicio (50)
    if (totalPacientes < MAX_PACIENTES)
    {
        Paciente nuevoPaciente;

        // se piden los datos del paciente
        cout << "\nIngrese el nombre del paciente: ";
        cin.ignore();
        getline(cin, nuevoPaciente.nombre);

        cout << "\nIngrese la edad del paciente: ";
        cin >> nuevoPaciente.edad;

        cout << "\nTiene diabetes (1: Si, 0: No): ";
        cin >> nuevoPaciente.tieneDiabetes;

        cout << "\nTiene hipertension? (1: Si, 0: No): ";
        cin >> nuevoPaciente.tieneHipertension;

        // se añade el paciente al arrelo de pacientes
        pacientes[totalPacientes++] = nuevoPaciente;
        cout << "\nRegistro ingresado correctamente.\n"
             << endl;
    }
    else
    {
        cout << "\nSe ha alcanzado el limite de registros (50). No se pueden ingresar mas pacientes." << endl;
    }
}

// Función mostrarRegistros
void mostrarRegistros(Paciente pacientes[], int totalPacientes)
{
    cout << "\nRegistros de pacientes:" << endl;

    for (int i = 0; i < totalPacientes; ++i)
    {
        // Mostrar los datos del paciente en orden en que se ingresaron
        cout << "\nNombre: " << pacientes[i].nombre << ", Edad: " << pacientes[i].edad
             << ", Diabetes: " << (pacientes[i].tieneDiabetes ? "Si" : "No")
             << ", Hipertension: " << (pacientes[i].tieneHipertension ? "Si" : "No") << endl;

        // Crear un double el cual representa la tasa de mortalidad, se le asigna el valor 0
        double tasaMortalidad = 0.0;

        // Calcular tasa de mortalidad segun la edad
        if (pacientes[i].edad >= 0 && pacientes[i].edad <= 5)
        {
            tasaMortalidad = 2.4;
        }
        else if (pacientes[i].edad >= 6 && pacientes[i].edad <= 49)
        {
            tasaMortalidad = 0.4;
        }
        else if (pacientes[i].edad >= 50 && pacientes[i].edad <= 59)
        {
            tasaMortalidad = 1.3;
        }
        else if (pacientes[i].edad >= 60 && pacientes[i].edad <= 69)
        {
            tasaMortalidad = 3.6;
        }
        else if (pacientes[i].edad >= 70 && pacientes[i].edad <= 79)
        {
            tasaMortalidad = 8.0;
        }
        else if (pacientes[i].edad >= 80)
        {
            tasaMortalidad = 14.8;
        }

        // Calcular la tasa de mortalidad según las enfermedades previas
        if (pacientes[i].tieneDiabetes)
        {
            tasaMortalidad += 2.5;
        }

        if (pacientes[i].tieneHipertension)
        {
            tasaMortalidad += 6.0;
        }

        cout << "\nTasa de mortalidad estimada: " << tasaMortalidad << "%\n"
             << endl;
        cout << "------------------------\n\n"
             << endl;
    }
}

/*double calculoProbabilidadOcurrencia()
{
    //CALCULANDO LA PROB QUE NO OCURRA UN EVENTO (1 - P(A))


}*/
