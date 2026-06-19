#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

const int FILAS = 15;
const int COLUMNAS = 30;
int posX = 2, posY = 2;
int metaX = 27, metaY = 12;

void gotoxy(int x, int y) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void Pared(int x, int y) {
    gotoxy(x, y);
    cout << "*";
}

void Bordes() {
    for (int i = 0; i < COLUMNAS; i++) {
        Pared(i, 0);
        Pared(i, FILAS-1);
    }
    for (int j = 0; j < FILAS; j++) {
        Pared(0, j);
        Pared(COLUMNAS-1, j);
    }
}

void Obstaculo1() {
    for (int i = 3; i <= 8; i++) {
        Pared(6, i);
    }
}

void Obstaculo2() {
    for (int j = 10; j <= 16; j++) {
        Pared(j, 7);
    }
}

void Obstaculo3() {
    Pared(20, 4);
    Pared(21, 4);
    for (int i = 4; i <= 9; i++) {
        Pared(21, i);
    }
}

void Laberinto() {
    Bordes();
    Obstaculo1();
    Obstaculo2();
    Obstaculo3();
}

void Personaje(int x, int y) {
    gotoxy(x, y);
    cout << "O";
}

void Meta(int x, int y) {
    gotoxy(x, y);
    cout << "M";
}

void MensajePerdida() {
    system("cls");
    gotoxy(5, FILAS/2 - 2);
    cout << "==========================================";
    gotoxy(5, FILAS/2 - 1);
    cout << "              HAS PERDIDO!                ";
    gotoxy(5, FILAS/2);
    cout << "    Chocaste con una pared o borde        ";
    gotoxy(5, FILAS/2 + 1);
    cout << "==========================================";
    gotoxy(5, FILAS/2 + 3);
    cout << "Presiona 1 para jugar de nuevo o ESC para salir...";
}

void MensajeVictoria() {
    system("cls");
    gotoxy(5, FILAS/2 - 2);
    cout << "==========================================";
    gotoxy(5, FILAS/2 - 1);
    cout << "      FELICITACIONES! HAS GANADO!         ";
    gotoxy(5, FILAS/2);
    cout << "      Llegaste a la meta exitosamente     ";
    gotoxy(5, FILAS/2 + 1);
    cout << "==========================================";
    gotoxy(5, FILAS/2 + 3);
    cout << "Presiona 1 para jugar de nuevo o ESC para salir...";
}

void reiniciarJuego() {
    posX = 2;
    posY = 2;
    metaX = 27;
    metaY = 12;
}

int main() {
    char tecla;
    bool reiniciar = false;
    
    do {
        if (reiniciar) {
            reiniciarJuego();
            reiniciar = false;
        }
        
        system("cls");
        
        Laberinto();
        Meta(metaX, metaY);
        Personaje(posX, posY);
        
        gotoxy(0, FILAS + 2);
        cout << "Usa WASD para moverte | ESC para salir";
        gotoxy(0, FILAS + 3);
        cout << "O = Personaje | M = Meta | * = Pared";
        
        if (posX == metaX && posY == metaY) {
            MensajeVictoria();
            tecla = getch();
            if (tecla == '1') {
                reiniciar = true;
                continue;
            } 
			
			else if (tecla == 27) {
                system("cls");
                gotoxy(5, 10);
                cout << "Programa finalizado" << endl;
                return 0;
            }
            continue;
        }
        
        tecla = getch();
        
        if (tecla == 27) {
            break;
        }
        
        int nuevaX = posX;
        int nuevaY = posY;
        
        switch (tecla) {
            case 'w': case 'W': nuevaY--; break;
            case 's': case 'S': nuevaY++; break;
            case 'a': case 'A': nuevaX--; break;
            case 'd': case 'D': nuevaX++; break;
        }
        
        bool colision = false;
        
        if (nuevaX < 1 || nuevaX >= COLUMNAS-1 || nuevaY < 1 || nuevaY >= FILAS-1) {
            colision = true;
        }
        
        if (nuevaY >= 3 && nuevaY <= 8 && nuevaX == 6) {
            colision = true;
        }
        
        if (nuevaY == 7 && nuevaX >= 10 && nuevaX <= 16) {
            colision = true;
        }
        
        if ((nuevaY == 4 && (nuevaX == 20 || nuevaX == 21)) ||
            (nuevaY >= 4 && nuevaY <= 9 && nuevaX == 21)) {
            colision = true;
        }
        
        if (colision) {
            MensajePerdida();
            tecla = getch();
            if (tecla == '1') {
                reiniciar = true;
                continue;
            } else if (tecla == 27) {
                system("cls");
                gotoxy(5, 10);
                cout << "Programa finalizado" << endl;
                return 0;
            }
            continue;
        }
        
        if (!colision) {
            posX = nuevaX;
            posY = nuevaY;
        }
        
    } while (true);
    
    system("cls");
    gotoxy(5, 10);
    cout << "Programa finalizado" << endl;
    return 0;
}