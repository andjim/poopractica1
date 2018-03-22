#include <iostream>
#include <stdlib>
using namespace std;


int toFaren(float c){
	return (c*(9/5))+32;
}

int toCelsi(float f){
	return (f-32)*(5/9);
}

void convertor(){
	char opt;
	try{
		cout<<"============================================================\n";
		cout<<"=============== Conversor Farenheit - Celsius ==================\n";
		cout<<"============================================================\n"<<endl;
		cout<<"\t\t [a] Farenheit a Celsius"<<endl;
		cout<<"\t\t [b] Celsius a Farenheit"<<endl;
		cout<<"\t\t cualquier otra tecla [Salir]"<<endl;
		cout<<"Opcion: ";
		cin>>opt;
		cout<<endl;
		switch(opt){
			case "a":
					float t;
					cout<<"Ingrese Temp en grado Farenheit: ";
					cin>>t;
					cout<<endl;
					toFaren(t);
					
					
			break;
			case "b":
					float t;
					cout<<"Ingrese Temp en grado Celsius: ";
					cin>>t;
					cout<<endl;
					toCelsi(t);
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
}
