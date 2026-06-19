#include <iostream>
#include <string>
#include <windows.h> 

using namespace std;


void gotoxy(int x, int y) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}


bool esNombreValido(string str) {
    for (int i=0 ; i <str.length() ; i++) {
    	char c= str[i];
       
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            return false; 
        }
    }
    return true;
}

int main() {
    int repetir=0;
    string nombre;
    bool entradaValida = false;
    int columnas_consola = 80;
    int filas_consola = 25;
        
          
    do {
        system("cls"); 

        cout << "==================== GRAFICAR NOMBRE ====================" << endl;

       
        while (!entradaValida) {
            cout << "\nIngrese un nombre (Min: 5 caracteres, Max: 8 caracteres): ";
            cin >> nombre;

           
            if (nombre.length() < 5 || nombre.length() > 8) {
                cout << "Error: El nombre debe tener entre 5 y 8 caracteres." << endl;
            } 
           
            else if (!esNombreValido(nombre)) {
                cout << "Error: No se permiten caracteres especiales, espacios o n\243meros." << endl;
            } 
            else {
                entradaValida = true; 
            }
        }

        int x = (columnas_consola - nombre.length()) / 2;
        
        int y = filas_consola / 2;

        system("cls"); 

        gotoxy(x, y);
        cout << nombre;
        
        gotoxy(0, filas_consola - 4); 
        
        cout << "========================================================" << endl;
        cout << "Desea repetir el programa con otro nombre? : "<<endl;
        cout << "1...si: "<<endl;
        cout << "2...no "<<endl;
        cin >> repetir;

    } while (repetir != 1);
     system("cls");
    cout << "Programa finalizado " << endl;
    return 0;
}
