#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

//conversor temp
float toFaren(float c){
	return (c*(9/5))+32;
}

float toCelsi(float f){
	return (f-32)*(5/9);
}

void convertor(){
	int opt;
	try{
		cout<<"================================================================================"<<endl;
		cout<<"====================== Conversor Farenheit - Celsius ==========================="<<endl;
		cout<<"================================================================================"<<endl;
		cout<<"\t\t [1] Celsius a Farenheit\n"<<endl;
		cout<<"\t\t [2] Farenheit a Celsius\n"<<endl;
		cout<<"\t\t [Salir] cualquier otra tecla \n"<<endl;
		cout<<"Opcion: ";
		cin>>opt;
		cout<<endl;
		switch(opt){
			case 1:
					float tempC;
					cout<<"Ingrese Temp en grado Celsius: ";
					cin>>tempC;
					cout<<endl;
					cout<<tempC<<" grados Celsius es igual a : "<<toFaren(tempC)<<" grados Farenheit."<<endl;

					
					
			break;
			case 2:
					float tempF;
					cout<<"Ingrese Temp en grado Farenheit: ";
					cin>>tempF;
					cout<<endl;
					cout<<tempF<<" grados Farenheit es igual a : "<<toCelsi(tempF)<<" grados Celsius."<<endl;
			break;
			default:
				cout<<"Continuara al Menu principal..."<<endl;
				system("pause");

		};
	}
	catch(int e){
		cout<<e<<endl;
	}
}

//la nota
void nota(){
	string nom, matri, sec, materia, prof;
	int as,tp,pp,ef;
	int numCamp[] = {as,tp,pp,ef}; 
	string txtCamp[] = {nom,matri,sec,materia,prof};
	string txtToPrint[] = {"Nombre de estudiante","Matricula de estudiante (se aceptan -)","Seccion","Materia","Nombre del Profesor"};
	string intTxtToPrint[] = {'Asistencia',"Trabajo practico","Primer parcial","Examen final"};
	cout<<"================================================================================"<<endl;
	cout<<"====================== Calificaciones(La nota) =========================="<<endl;
	cout<<"================================================================================"<<endl;
	
	for(int i =0; i < sizeof(txtCamp)/ sizeof(*txtCamp); i++ ){
		cout<<"Ingrese "<<txtToPrint[i]<<" : ";
		cin>> txtCamp[i];
		cout<<endl;
		
	};
	
	cout<<"Ingrese las calificaciones del estudiante:"<<endl;
	for(int i = 0; i < sizeof(numCamp) / sizeof(*numCapm); i++ ){
		cout<<"\t"<<intTxtToPrint[i]<<": ";
		cin>>numCamp[i];
		cout<<endl;
	}
	
	
	
	
	
}

int main (){
	convertor();
	return 0;
}
