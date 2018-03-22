#include <iostream>
#include <stdlib.h>
using namespace std;


int toFaren(float c){
	return (c*(9/5))+32;
}

int toCelsi(float f){
	return (f-32)*(5/9);
}

void convertor(){
	int opt;
	try{
		cout<<"================================================================================"<<endl;
		cout<<"====================== Conversor Farenheit - Celsius ==========================="<<endl;
		cout<<"================================================================================"<<endl;
		cout<<"\t\t [1] Farenheit a Celsius\n"<<endl;
		cout<<"\t\t [2] Celsius a Farenheit\n"<<endl;
		cout<<"\t\t [Salir] cualquier otra tecla \n"<<endl;
		cout<<"Opcion: ";
		cin>>opt;
		cout<<endl;
		switch(opt){
			case 1:
					float t;
					cout<<"Ingrese Temp en grado Farenheit: ";
					cin>>t;
					cout<<endl;
					toFaren(t);
					
					
			break;
			case 2:
					float temp;
					cout<<"Ingrese Temp en grado Celsius: ";
					cin>>t;
					cout<<endl;
					toCelsi(temp);
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

int main (){
	convertor();
	return 0;
}
