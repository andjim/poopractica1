#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

//conversor temp


void convertor(){
	float toFaren(float c){
		return (c*(9/5))+32;
	}

	float toCelsi(float f){
		return (f-32)*(5/9);
	}
	
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
	string intTxtToPrint[] = {"Asistencia (0-10)","Trabajo practico(0-20)","Primer parcial(0-20)","Examen final(0-50)"};
	cout<<"================================================================================"<<endl;
	cout<<"============================ Calificaciones(La nota) ==========================="<<endl;
	cout<<"================================================================================"<<endl;
	
	for(int i =0; i < sizeof(txtCamp)/ sizeof(*txtCamp); i++ ){
		cout<<"Ingrese "<<txtToPrint[i]<<" : ";
		getline(cin, *txtCamp[i]);
		cout<<endl;
		
	};
	/*as < 0 or as > 10
	  tp < 0 or as > 20
	  pp < 0 or as > 20
	  ef < 0 or as > 50
	*/
	int limites[] = {10,20,20,50};
	cout<<"Ingrese las calificaciones del estudiante:"<<endl;
	for(int i = 0; i < sizeof(numCamp) / sizeof(*numCamp); i++ ){
		while(true){
			cout<<"\t"<<intTxtToPrint[i]<<": ";
			cin>> *numCamp[i];
			cout<<endl;
			if(*numCamp[i] < 0 or *numCamp[i] > limites[i]){
				cout<<"*El Valor no esta dentro del rango. Vuelva ingresarlo.*"<<endl;
				continue;
			};
			break;
		};
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
		NT = "FE";
	}else if(total <= 59 && total >= 50){
		NT = "FI";
	}else{
		NT = 'F';
	};
	system("cls");
	cout<<'\n'<<endl;
	cout<<"============================ Calificaciones(La nota) ==========================="<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<"Estudiante: "<<nom<<"\t"<<"Matricula: "<<matri<<"\n"<<endl;
	cout<<endl;
	cout<<"Seccion: "<<sec<<"\t\t"<<"Materia: "<<materia<<"\n"<<endl;
	cout<<endl;
	cout<<"\tAs\t"<<"Tp\t"<<"Pp\t"<<"Ef\t"<<"Sum F\t\t"<<"Nt"<<endl;
	cout<<"\n"<<endl;
	cout<<"\t"<<as<<"\t"<<tp<<"\t"<<pp<<"\t"<<ef<<"\t"<< total<<"\t\t"<<NT<<endl;
	cout<<"*******************************************************************************"<<endl;
	system("pause");
};

int main (){
	nota();
	return 0;
}
