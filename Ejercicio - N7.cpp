#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

const int FILAS = 25;
const int COLUMNAS = 80;

void gotoxy(int x, int y) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

bool esNumeroValido(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

void dibujarCero(int x, int y) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || i == 9 || j == 0 || j == 9) {
                gotoxy(x + j, y + i);
                cout << "#";
            }
        }
    }
}

void dibujarUno(int x, int y) {
    for (int i = 0; i < 10; i++) {
        gotoxy(x + 4, y + i);
        cout << "#";
    }
}

void dibujarDos(int x, int y) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || i == 4 || i == 9 || (i >= 1 && i <= 3 && j == 9) || (i >= 5 && i <= 8 && j == 0)) {
                gotoxy(x + j, y + i);
                cout << "#";
            }
        }
    }
}

void dibujarTres(int x, int y) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || i == 4 || i == 9 || (i >= 1 && i <= 3 && j == 9) || (i >= 5 && i <= 8 && j == 9)) {
                gotoxy(x + j, y + i);
                cout << "#";
            }
        }
    }
}

void dibujarCuatro(int x, int y) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {     
            if ((j == 8) || (i == 4 && j > 0 && j < 8) || (j == 1 && i < 4)) {
                gotoxy(x + j, y + i);
                cout << "#";
            }
        }
    }
}

void dibujarCinco(int x, int y) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || i == 4 || i == 9 || (i >= 1 && i <= 3 && j == 0) || (i >= 5 && i <= 8 && j == 9)) {
                gotoxy(x + j, y + i);
                cout << "#";
            }
        }
    }
}

void dibujarSeis(int x, int y) {
    for (int i = 0; i < 10; i++) {
        gotoxy(x, y + i);
        
        for (int j = 0; j < 10; j++) {
            
            if (j == 0 && (i > 0 && i < 9)) {
                cout << "#";
            }

            else if ((i == 0 || i == 4 || i == 9) && (j > 0 && j < 8)) {
                cout << "#";
            }

            else if (j == 8 && (i > 4 && i < 9)) {
                cout << "#";
            }

            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void dibujarSiete(int x, int y) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || (i == 1 && j == 9) || (i == 2 && j == 8) || (i == 3 && j == 7) || 
                (i == 4 && j == 6) || (i == 5 && j == 5) || (i == 6 && j == 4) || 
                (i == 7 && j == 3) || (i == 8 && j == 2) || (i == 9 && j == 1)) {
                gotoxy(x + j, y + i);
                cout << "#";
            }
        }
    }
}

void dibujarOcho(int x, int y) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || i == 4 || i == 9 || j == 0 || j == 9) {
                gotoxy(x + j, y + i);
                cout << "#";
            }
        }
    }
}

void dibujarNueve(int x, int y) {
    for (int i = 0; i < 10; i++) {
        gotoxy(x, y + i);
        
        for (int j = 0; j < 10; j++) {
            
            if ((i == 0 || i == 4) && (j > 0 && j < 9)) {
            cout<<"#";
            } else if ((i > 0 && i < 4) && (j == 0 || j == 8)) {
			cout<<"#";
            } else if ((i > 4) && (j == 8)) {
            cout<<"#";
            } else {
            cout<<" ";
            }
        }
        cout<<endl;
    }
}
void dibujarDigito(char digito, int x, int y) {
    switch (digito) {
        case '0': 
		dibujarCero(x, y); 
		break;
        case '1': 
		dibujarUno(x, y); 
		break;
        case '2': 
		dibujarDos(x, y); 
		break;
        case '3': 
		dibujarTres(x, y); 
		break;
        case '4': 
		dibujarCuatro(x, y); 
		break;
        case '5': 
		dibujarCinco(x, y); 
		break;
        case '6': 
		dibujarSeis(x, y); 
		break;
        case '7': 
		dibujarSiete(x, y); 
		break;
        case '8': 
		dibujarOcho(x, y);
		break;
        case '9':
		dibujarNueve(x, y); 
		break;
    }
}

void dibujarNumero(int numero) {
    string numStr = to_string(numero);
    int longitud = numStr.length();
    int anchoTotal = longitud * 12;
    int inicioX = (COLUMNAS - anchoTotal) / 2;
    int inicioY = FILAS / 2 - 5;
    
    for (int i = 0; i < longitud; i++) {
        dibujarDigito(numStr[i], inicioX + (i * 12), inicioY);
    }
}

int main() {
    string input;
    int numero;
    int repetir;
    
    do {
        system("cls");
        gotoxy(0, 0);
        cout << "========================================" << endl;
        cout << "     Grafica de Numeros (1-9999)     " << endl;
        cout << "========================================" << endl;
        
        bool entradaValida = false;
        
        while (!entradaValida) {
            gotoxy(0, 4);
            cout << "Ingrese un numero entre 1 y 9999: ";
            cin >> input;
            
            if (!esNumeroValido(input)) {
                gotoxy(0, 6);
                cout << "Error: Solo se permiten numeros.          ";
                continue;
            }
            
            numero = stoi(input);
            
            if (numero < 1 || numero > 9999) {
                gotoxy(0, 6);
                cout << "Error: El numero debe estar entre 1 y 9999. ";
            } else {
                entradaValida = true;
            }
        }
        
        system("cls");
        dibujarNumero(numero);
        
        gotoxy(0, FILAS - 2);
        cout << "========================================" << endl;
        cout << "Desea graficar otro numero?" << endl;
        cout << "1...Si" << endl;
        cout << "2...No" << endl;
        cin >> repetir;
        
    } while (repetir != 2);
    
    system("cls");
    gotoxy(5, 10);
    cout << "Programa finalizado" << endl;
    return 0;
}