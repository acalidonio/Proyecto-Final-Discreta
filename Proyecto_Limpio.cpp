#include <iostream>
#include <string>
// #include
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
const int MAX_PACIENTES = 50; // Constante -- Nunca sera cambiado el valor

// Prototipos de funciones del programa
void Menu();
void ingresarPaciente(Paciente pacientes[], int &totalPacientes); // Funciones void, No retornan un valor.
void mostrarRegistros(Paciente pacientes[], int totalPacientes);

// Función main
int main()
{   
    // se declaran las variables a utilizar
    Paciente pacientes[MAX_PACIENTES]; // Variable tipo paciente de tamano 50 (MAX_PACIENTES)
    int totalPacientes = 0;            // Inicializando a 0
    int opcion;

    // se crea un menu de opciones
    do
    {
        // se llama a la función menu que muestra el texto de opciones y luego se pide seleccionar una opción
        Menu();
        cin >> opcion;
        // cout << "el total de pctes es igual a " << totalPacientes << "\n" << endl; // se muestra el total de pacientes

        switch (opcion)
        { // OPCION ES 1
        case 1:
            ingresarPaciente(pacientes, totalPacientes);
            break;
        case 2: // OPCION ES 2
            mostrarRegistros(pacientes, totalPacientes);
            system("pause");
            break;
        case 3: // OPCION ES 3
            system("cls");
            cout << "\nGracias por utilizar el programa de estimacion de peligro para pacientes con Covid. \n";
            cout << "\nSiga las medidas de bioseguridad indicadas por su doctor y mantenga constante el uso de mascarilla. Gracias!\n\n" << endl;
            cout << "Saliendo..." << endl;
            system("pause");
            break;
        default: //Si ingresa otro dato que no sea 1-2-3
                    system("cls");
            cout << "\nOpcion no valida. Por favor, seleccione una opcion valida.\n\n";
                    system("pause");
        }
    } while (opcion != 3); //Todo lo anterior se repite mientras la opcion sea diferente de 3 --> (SALIR)

    return 0;
}

// función menu
void Menu()
{   system("cls");
    cout << "Bienvenido a la Estimacion de Peligro de Pacientes con Covid (EPPC)\n" << endl;  //Mensaje de Bienvenida
    cout << "1. Ingresar nuevo paciente" << endl;
    cout << "2. Mostrar registros y calcular tasa de mortalidad" << endl;
    cout << "3. Salir" << endl;
    cout << "\nSeleccione una opcion: ";
}

// Función ingresarPaciente
void ingresarPaciente(Paciente pacientes[], int &totalPacientes) //Pasamos por ref, ya que va cambiar constantemente.
{
    // el if verifica si se ha llegado al límite de pacientes especificados al inicio (50)
    if (totalPacientes < MAX_PACIENTES)
    {
        Paciente nuevoPaciente; //Declarando variable tipo struct paciente (Contiene los datos necesarios del paciente)

        // se piden los datos del paciente
        system("cls");
        cout << "\nIngrese el nombre del paciente: ";
        cin.ignore(); //Para leer todos los caracteres de la cadena hasta el primer salto o espacio.
        getline(cin, nuevoPaciente.nombre); 

        system("cls");
        cout << "\nIngrese la edad del paciente: ";
        cin >> nuevoPaciente.edad;

        system("cls");
        cout << "\nTiene diabetes [ (1) Si || (0) No ]: ";
        cin >> nuevoPaciente.tieneDiabetes;

        system("cls");
        cout << "\nTiene hipertension? [ (1) Si || (0) No ]: ";
        cin >> nuevoPaciente.tieneHipertension;

        // se añade el paciente al arrelo de pacientes
        pacientes[totalPacientes++] = nuevoPaciente; 
        cout << "\nIngreso al paciente correctamente" << endl;
        system("pause");
    }

    else //Si ya se llego al limite de pacientes (50)
    {
        cout << "\nSe ha alcanzado el limite de registros permitidos (50). No se pueden ingresar mas pacientes." << endl;
        system("pause");
    }
}

// Función mostrarRegistros
void mostrarRegistros(Paciente pacientes[], int totalPacientes)
{   
    system("cls");
    cout << "\nRegistros de pacientes:" << endl;

    for (int i = 0; i < totalPacientes; ++i) //desde 0 hasta la cantidad de pacientes ingresados
    {
        // Mostrar los datos del paciente en orden en que se ingresaron
        cout << "\nNombre: " << pacientes[i].nombre << "\nEdad: " << pacientes[i].edad
             << "\nDiabetes: " << (pacientes[i].tieneDiabetes ? "Si" : "No")
             << "\nHipertension: " << (pacientes[i].tieneHipertension ? "Si" : "No") << endl;

        // Crear un double el cual representa la tasa de mortalidad, se le asigna el valor 0
        double tasaMortalidad = 0.0;

        // Calcular tasa de mortalidad segun la edad
        if (pacientes[i].edad >= 0 && pacientes[i].edad <= 5) //DE 0 A 5
        {
            tasaMortalidad = 2.4;
        }
        else if (pacientes[i].edad >= 6 && pacientes[i].edad <= 49) //DE 6 A 49
        {
            tasaMortalidad = 0.4;
        }
        else if (pacientes[i].edad >= 50 && pacientes[i].edad <= 59) //DE 50 A 59
        {
            tasaMortalidad = 1.3;
        }
        else if (pacientes[i].edad >= 60 && pacientes[i].edad <= 69) //DE 60 A 69
        {
            tasaMortalidad = 3.6;
        }
        else if (pacientes[i].edad >= 70 && pacientes[i].edad <= 79) //DE 70 A 79
        {
            tasaMortalidad = 8.0;
        }
        else if (pacientes[i].edad >= 80) //DE 80 A MAS
        {
            tasaMortalidad = 14.8;
        }

        // Calcular la tasa de mortalidad según las enfermedades previas
        //Usamos Diabetes e Hipertension ya que son las que mas afectan cuando se presenta covid.
        if (pacientes[i].tieneDiabetes)
        {
            tasaMortalidad += 2.5; 
        }

        if (pacientes[i].tieneHipertension)
        {
            tasaMortalidad += 6.0;
        }

        cout << "\nTasa de mortalidad estimada: " << tasaMortalidad << "%\n" << endl;
        cout << "_____________________________________________\n\n" << endl;
    }
}