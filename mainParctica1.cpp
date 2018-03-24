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
	int* numCamp[] = {&as,&tp,&pp,&ef}; 
	string* txtCamp[] = {&nom,&matri,&sec,&materia,&prof};
	string txtToPrint[] = {"Nombre de estudiante","Matricula de estudiante (se aceptan -)","Seccion","Materia","Nombre del Profesor"};
	string intTxtToPrint[] = {"Asistencia","Trabajo practico","Primer parcial","Examen final"};
	cout<<"================================================================================"<<endl;
	cout<<"====================== Calificaciones(La nota) =========================="<<endl;
	cout<<"================================================================================"<<endl;
	
	for(int i =0; i < sizeof(txtCamp)/ sizeof(*txtCamp); i++ ){
		cout<<"Ingrese "<<txtToPrint[i]<<" : ";
		cin>> *txtCamp[i];
		cout<<endl;
		
	};
	
	cout<<"Ingrese las calificaciones del estudiante:"<<endl;
	for(int i = 0; i < sizeof(numCamp) / sizeof(*numCamp); i++ ){
		cout<<"\t"<<intTxtToPrint[i]<<": ";
		cin>> *numCamp[i];
		cout<<endl;
	};
	
	int total = as+tp+pp+ef;
	string NT;
	
	if(total>=90){
		NT = 'A';
	}else if(total <= 89 && total >=80){
		NT = 'B';
	}else if(total <=79 && total >= 75){
		NT = 'C';
	}else if(total <= 74 && total >= 70){
		NT = 'D';
	}else if(total <= 69 && total >= 60){
		NT = 'FE';
	}else if(total <= 59 && total >= 50){
		NT = 'FI';
	}else{
		NT = 'F';
	};
	cout<<"Estudiante: "<<nom<<"\t"<<"Matricula: "<<matri<<"\n"<<endl;
	cout<<endl;
	cout<<"Seccion: "<<sec<<"\t"<<"Materia: "<<materia<<"\n"<<endl;
	cout<<endl;
	cout<<"As\t"<<"Tp\t"<<"Pp\t"<<"Ef\t"<<"Sum F\t\t"<<"Nt"<<endl;
	cout<<"\n"<<endl;
	cout<<as<<"\t"<<tp<<"\t"<<pp<<"\t"<<ef<<"\t"<< total<<"\t\t"<<NT<<endl;
};

int main (){
	nota();
	return 0;
}
