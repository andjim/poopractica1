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

//casa de cambio
void recibo(string moneda,string tc,string divisaFrom, string divisaTo,string cliente,string nac,float razonDecambio,int multiOrdiv){
	long double cant,cn,ct;
	float interes = 0.03;
	
	cout<<"Ingrese la cantidad de "<<moneda<<": ";
	cin>>cant;
	cout<<endl;
	if(multiOrdiv == 0){
		cn = cant*razonDecambio;
	}else{
		cn = cant/razonDecambio;
	}
	
	ct = cn-(cn*interes);
	cout<<"Cliente: "<<cliente<<"\tNacionalidad: "<<nac<<"\n"<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<"\n"<<"Tipo de cambio\t"<<"Cantidad\t"<<endl;
	cout<<tc<<"\t"<<cant<<" "<<divisaFrom<<"\n"<<endl;
	cout<<"Cambio Neto\t"<<"Cambio Total(-3%)"<<endl;
	cout<<cn<<divisaTo<<"\t"<<ct<<" "<<divisaTo<<"\n"<<endl;
	cout<<"*******************************************************************************"<<endl;
}

void casaDecambio(){
	
	double usdToeur = 0.80929;
	double usdToGbp = 0.70777;
	double usdToDop = 49.536;	
	double eurToDop = 61.20917;
	double eurToGbp = 0.87455;
	double GbpToDop = 69.989;
	string cliente;
	string nac;
	
	int opt;
	cout<<"================================================================================"<<endl;
	cout<<"=============================== Casa de cambio =================================="<<endl;
	cout<<"================================================================================"<<endl;
	
	cout<<"Nombre: ";
	getline(cin,cliente);
	cout<<endl;
	
	cout<<"Nacionalidad: ";
	getline(cin,nac);
	cout<<endl;
	
	cout<<"Seleccione tipo de cambio:"<<endl;
	cout<<"\t[1] Dolar a Peso"<<"\t[2] Dolar a Libra"<<"\t[3] Dolar a Euro\n"<<endl;
	cout<<"\t[4] Euro a Dolar"<<"\t[5] Euro a Peso"<<"\t\t[6] Euro a Libra\n"<<endl;
	cout<<"\t[7] Libra a Peso"<<"\t[8] Libra a Euro"<<"\t[9] Libra a Dolar\n"<<endl;
	cout<<"\t[10] Peso a Dolar"<<"\t[11] Peso a Euro"<<"\t[12] Peso a Libra\n"<<endl;
	cout<<"\t\t\t[Salir] cualquier otra tecla \n"<<endl;
	cout<<"Opcion: ";
	cin>>opt;
	

	switch(opt){
		case 1:
			recibo("dolares","Dolar - Peso","USD","DOP",cliente,nac,usdToDop,0);
			 
		break;
		case 2:
			recibo("dolares","Dolar - Libra","USD","GBP",cliente,nac,usdToGbp,0);
			 
		break;
		case 3:
			recibo("dolares","Dolar - Euro","USD","EUR",cliente,nac,usdToeur,0);
			 
		break;
		case 4:
			recibo("euros","Euro - Dolar","EUR","USD",cliente,nac,usdToeur,1);
			 
		break;
		case 5:
			recibo("euros","Euro - Peso","EUR","DOP",cliente,nac,eurToDop,0);
			 
		break;
		case 6:
			recibo("euros","Euro - Libra","EUR","GBP",cliente,nac,eurToGbp,0);
		break;
		case 7:
			recibo("libras","Libra - Peso","GBP","DOP",cliente,nac,GbpToDop,1);
			 
		break;
		case 8:
			recibo("libras","Libra - Euro","GBP","EUR",cliente,nac,eurToGbp,1);
			 
		break;
		case 9:
			recibo("libras","Libra - Dolar","GBP","USD",cliente,nac,usdToGbp,1);
			 
		break;
		case 10:
			recibo("pesos","Peso - Euro","DOP","EUR",cliente,nac,eurToDop,0);
			 
		break;
		case 11:
			recibo("pesos","Peso - Dolar","DOP","USD",cliente,nac,usdToDop,0);
			 
		break;
		case 12:
			recibo("pesos","Peso - Libra","DOP","GBP",cliente,nac,GbpToDop,0);
			 
		break;
		default:
		break;
	};
	system("pause");
	
}
int main (){
	casaDecambio();
	return 0;
}
