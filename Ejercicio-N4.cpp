#include <stdio.h>  
#include <windows.h>  
#include<iostream>
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
 	for(int i=0 ; i<10 ; i++){
 		for(int j=0 ; j<10; j++){
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
 
  
 void triangulo(int x, int y){
 	for(int i=0 ; i<10 ; i++){
 		for(int j=0 ; j<5; j++){
 			if()
		 }
		 cout<<endl;
	 }
 }
 
 int main(){
 	int x=0,y=0;
 	
 	triangulo(x,y);
 	
 }
