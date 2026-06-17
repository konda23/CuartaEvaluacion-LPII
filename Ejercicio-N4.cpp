#include <iostream>  
#include <windows.h>  
using namespace std;
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 
 void cuadrado(int x, int y){
 	for(int i=0 ; i<6 ; i++){
 		for(int j=0 ; j<6; j++){
 			cout<<"*";
			 
		 }
		 cout<<endl;
	 }
 }
 
  void rectangulo(int x, int y){
 	for(int i=0 ; i<10 ; i++){
 		for(int j=0 ; j<20; j++){
 			cout<<"*";
			 
		 }
		 cout<<endl;
	 }
 }
 
  
 void triangulo(int x, int y, int n){
 	for(int i=0 ; i<n ; i++){
 		for(int j=0 ; j<n; j++){
 			if(i==j || j==0 || i==n-1){
 				gotoxy(x+j,y+i);
				 cout<<"*";
			 }
		 }
	 }
 }
 
 int main(){
 	int x=0,y=0,n=10;
 	int figura=0;
 	int selec= 0;
 	
 	do{
 		
 	cout<<"Seleccione la figura que desea ver:"<<endl;
 	cout<<"----------------------------------"<<endl;
 	cout<<"1. cuadrado"<<endl;
 	cout<<"2. Triangulo"<<endl;
 	cout<<"3. Rectangulo"<<endl;
 	cin>>figura;
 	
 	system("cls");
 	switch(figura){
 		case 1:
 			cuadrado(x,y);
 			break;
 		case 2:
 			triangulo(x,y,n);
 			cout<<""<<endl;
 			break;
 		case 3:
 			rectangulo(x,y);
 			break;
 		default:
 			cout<<"Error, opcion no disponible"<<endl;
			break;
	 }
	 
	 cout<<"Desea ver otra figura?"<<endl;
	 cout<<"Si (1)"<<endl;
	 cout<<"No (2)"<<endl;
	 cin>>selec;
	 system("cls");
	 
	 }while(selec !=2);
	 
	 return 0;
 }
