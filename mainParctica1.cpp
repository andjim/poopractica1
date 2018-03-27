#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

//funciones de utilidad
bool onlySpace(string line){
	string espacio = " ";
	for(int i = 0; i <line.size();i++) if(line[i] != espacio[0]) return false; return true;
	/*
		Recorre una cadena <line> en busqueda de caracteres diferentes a un espacio,
		si lo encuentra, entontes devolvera falso, sino encuentra caracteres diferentes a un espacio
		devolvera true;
		
		true, si la cadena tiene solo espacios
		false, si es tiene aunque sea una letra;
	*/
}

int letterCount(string line){
	int count = 0;
	string espacio = " ";
	for(int i = 0; i <line.size();i++) if(line[i] != espacio[0]) count++;
	return count;
		/*
		Recorre una cadena <line> en busqueda de caracteres diferentes a un espacio,
		si lo encuentra, entontes incrementa la variable <count> en 1, y al terminar de recorrer
		la variable devuelve el valor contenido en <cout>;
	
	*/
}


//la nota
void nota(){
	string nom, matri, sec, materia, prof;
	string* Pnom = &nom;
	string* Pmatri = &matri;
	string* Psec = &sec;
	string* Pmateria = &materia;
	string* Pprof = &prof;
	int as,tp,pp,ef;
	int* numCamp[] = {&as,&tp,&pp,&ef}; 
	string* txtCamp[] = {Pnom,Pmatri,Psec,Pmateria,Pprof};
	string txtToPrint[] = {"Nombre de estudiante","Matricula de estudiante (se aceptan -)","Seccion","Materia","Nombre del Profesor"};
	string intTxtToPrint[] = {"Asistencia (0-10)","Trabajo practico(0-20)","Primer parcial(0-20)","Examen final(0-50)"};
	cout<<"================================================================================"<<endl;
	cout<<"============================ Calificaciones(La nota) ==========================="<<endl;
	cout<<"================================================================================"<<endl;
	
	for(int i =0; i < sizeof(txtCamp)/ sizeof(*txtCamp); i++ ){
		string lin;
		do{
			
			cout<<"Ingrese "<<txtToPrint[i]<<" : ";
			getline(cin, *txtCamp[i]);
			cout<<endl;
			lin = *txtCamp[i];
			
			if(onlySpace(lin)) cout<<"Campo Obligatorio*\n"<<endl;
		}while(onlySpace(lin));
		
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
			
			if(cin.fail()){
				cout<<"*Eso no fue un numero.*"<<endl;
				cin.clear();
				cin.ignore();
				continue;
			}else{
				if(*numCamp[i] < 0 or *numCamp[i] > limites[i]){
					cout<<"*El Valor no esta dentro del rango. Vuelva ingresarlo.*"<<endl;
					continue;
				};
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
	
	while(true){
		cout<<"Ingrese la cantidad de "<<moneda<<": ";
		cin>>cant; //validar cant sea numero
		cout<<endl;
		cin.clear();
		cin.ignore();
		
		if(cin.fail()){
			system("cls");
			cout<<"Eso no fue un numero. Vuelva ingresar"<<endl;
			system("pause");
			system("cls");
			continue;
		};
		break;
	}
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
	
	do{
		cout<<"Nombre: ";
		getline(cin,cliente);
		cout<<endl;
		if(onlySpace(cliente)) cout<<"Campo obligatorio*"<<endl;
	}while(onlySpace(cliente));
	
	do{
		cout<<"Nacionalidad: ";
		getline(cin,nac);
		cout<<endl;
		if(onlySpace(nac)) cout<<"Campo obligatorio*"<<endl;
	}while(onlySpace(nac));
	
		cout<<"Seleccione tipo de cambio:"<<endl;
		cout<<"\t[1] Dolar a Peso"<<"\t[2] Dolar a Libra"<<"\t[3] Dolar a Euro\n"<<endl;
		cout<<"\t[4] Euro a Dolar"<<"\t[5] Euro a Peso"<<"\t\t[6] Euro a Libra\n"<<endl;
		cout<<"\t[7] Libra a Peso"<<"\t[8] Libra a Euro"<<"\t[9] Libra a Dolar\n"<<endl;
		cout<<"\t[10] Peso a Dolar"<<"\t[11] Peso a Euro"<<"\t[12] Peso a Libra\n"<<endl;
		cout<<"\t\t\t[Salir] cualquier otra tecla \n"<<endl;
		cout<<"Opcion: ";
		cin>>opt;
		cin.clear();
		cin.ignore();
		
	

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

//nominaDePago
void nominaDePago(){
	long double pagoxh,sueldoLaboral,sueldoExtra,sueldoBruto, afp, ars,sueldoTotal;
	float horasTrabajadas, horasExtras, totalDehoras;
	string empleado;
	
	cout<<"================================================================================"<<endl;
	cout<<"================================= Nomina de Pago =============================="<<endl;
	cout<<"================================================================================"<<endl;
	
	do{
		cout<<"Intoduzca Nombre: ";
		getline(cin,empleado);
		cout<<endl;
		if(onlySpace(empleado)) cout<<"Campo obligatorio*"<<endl;
	}while(onlySpace(empleado));

	do{
		cout<<"Cuanto gana por hora ($DOP): ";
		cin>>pagoxh;
		cout<<endl;
		cin.clear();
		cin.ignore();
		if(cin.fail()){
			system("cls");
			cout<<"El valor no fue numerico."<<endl;
			system("pause");
			system("cls");
		}
	}while(cin.fail());
	
	do{
		do{
			cout<<"Cantidad de horas laborables: ";
			cin>>horasTrabajadas;
			cout<<endl;
			cin.clear();
			cin.ignore();
			if(cin.fail()){
				system("cls");
				cout<<"El valor no fue numerico."<<endl;
				system("pause");
				system("cls");
			};
		}while(cin.fail());
		
		do{
			cout<<"Cantidad de horas extra: ";
			cin>>horasExtras;
			cout<<endl;
			cin.clear();
			cin.ignore();
			if(cin.fail()){
				system("cls");
				cout<<"El valor no fue numerico."<<endl;
				system("pause");
				system("cls");
			};
		}while(cin.fail());
		
		totalDehoras = horasTrabajadas +  horasExtras;
		if(totalDehoras > 88){
			cout<<"El total de horas laboradas exede el total que se puede laborar en una quincena.\n Por favor, se que ha trabajado mucho, pero vuelva a ingresar la horas que laboro."<<endl;
		};
		}while(totalDehoras > 88);
		
	sueldoLaboral = horasTrabajadas * pagoxh;
	sueldoExtra = horasExtras * (pagoxh + (pagoxh * 0.35));
	sueldoBruto = sueldoLaboral + sueldoExtra;
	ars = afp= sueldoBruto * 0.03;
	sueldoTotal = (sueldoBruto - ars) -afp;
	
	
	
	cout<<"================================================================================"<<endl;
	cout<<"=========================  Nomina de "<<empleado<<"  =============================="<<endl;
	cout<<"=================================================================================\n\n"<<endl;
	cout<<"Pago por hora: $"<<pagoxh<<" DOP\t\t"<<"Horas laboradas: "<<horasTrabajadas<<"\n"<<endl;
	cout<<"Horas extra: "<<horasExtras<<"\t\t"<<"Total de horas laboradas: "<<totalDehoras<<endl;
	cout<<"\n"<<endl;
	cout<<"Sueldo Bruto: $"<<sueldoBruto<<" DOP\t\t"<<"Ars: $"<<ars<<" DOP"<<"\n"<<endl;
	cout<<"Afp: $"<<afp<<"DOP \t\t"<<"Sueldo total: $"<<sueldoTotal<<" DOP"<<endl;
	cout<<"\n\n"<<endl;
	cout<<"==============================================================================="<<endl;
	system("pause");
}	

//Conversor de unidades
void ConversorUnidades(){
	double PiesToPulg = 12;
	double mtsToCenti = 100;
	double milTokilo = 1.609;
	int opt;
	double medida;
	
	cout<<"================================================================================"<<endl;
	cout<<"============================= Cambio de Unidades ================================="<<endl;
	cout<<"================================================================================"<<endl;
	
	cout<<"Seleccione tipo de cambio:"<<endl;
	cout<<"\t[1] Pies a Pulgada"<<"\t\t[2] Pulgadas a Pies\n"<<endl;
	cout<<"\t[3] Metros a Centimetros"<<"\t\t[4] Centimetros a Metros\n"<<endl;
	cout<<"\t[5] Millas a Kilometros"<<"\t\t[6] Kilometros a Millas\n"<<endl;
	cout<<"\t\t\t[Salir] cualquier otra tecla \n"<<endl;
	cout<<"Opcion: ";
	cin>>opt;
	cout<<endl;
	cin.clear();
	cin.ignore();
	switch(opt){
		case 1:
			do{
				cout<<"Pies: ";
				cin>>medida;
				cout<<endl;
				cin.clear();
				cin.ignore();
				if(cin.fail()){
					system("cls");
					cout<<"El valor no fue numerico."<<endl;
					system("pause");
					system("cls");
					continue;
				};
				break;
			}while(cin.fail());
			cout<<medida<<" pies son: "<<medida*PiesToPulg<<" pulgadas."<<endl;
		break;
		case 2:
			do{
				cout<<"Pulgadas: ";
				cin>>medida;
				cout<<endl;
				cin.clear();
				cin.ignore();
				if(cin.fail()){
					system("cls");
					cout<<"El valor no fue numerico."<<endl;
					system("pause");
					system("cls");
					continue;
				};
				break;
			}while(cin.fail());
			cout<<medida<<" pulgadas son: "<<medida/PiesToPulg<<" pies."<<endl;
		break;
		case 3:
			do{
				cout<<"Metros: ";
				cin>>medida;
				cout<<endl;
				cin.clear();
				cin.ignore();
				if(cin.fail()){
					system("cls");
					cout<<"El valor no fue numerico."<<endl;
					system("pause");
					system("cls");
					continue;
				};
				break;
			}while(cin.fail());
			cout<<medida<<" metros son: "<<medida*mtsToCenti<<" centimetros."<<endl;
		break;
		case 4:
			do{
				cout<<"Centimetros: ";
				cin>>medida;
				cout<<endl;
				cin.clear();
				cin.ignore();
				if(cin.fail()){
					system("cls");
					cout<<"El valor no fue numerico."<<endl;
					system("pause");
					system("cls");
					continue;
				};
				break;
			}while(cin.fail());
			
			cout<<medida<<" centimetros son: "<<medida/mtsToCenti<<" metros."<<endl;
		break;
		case 5:
			do{
				cout<<"Millas: ";
				cin>>medida;
				cout<<endl;
				cin.clear();
				cin.ignore();
				if(cin.fail()){
					system("cls");
					cout<<"El valor no fue numerico."<<endl;
					system("pause");
					system("cls");
					continue;
				};
				break;
			}while(cin.fail());
			cout<<medida<<" millas son: "<<medida*milTokilo<<" kilometros."<<endl;
		break;
		case 6:
			do{
				cout<<"Kilometros: ";
				cin>>medida;
				cout<<endl;
				cin.clear();
				cin.ignore();
				if(cin.fail()){
					system("cls");
					cout<<"El valor no fue numerico."<<endl;
					system("pause");
					system("cls");
					continue;
				};
				break;
			}while(cin.fail());;
			cout<<medida<<" kilometros son: "<<medida/milTokilo<<" millas."<<endl;
		break;											
		default:break;
	}
	system("pause");
};

//factorial

long int fact(long int n){
	if(n < 1) return 1;
	return n*fact(n-1);
}
void factorialDelpositivo(){
	long int num;
	
	
	do{
		system("cls");
		do{
			cout<<"================================================================================"<<endl;
			cout<<"============================= Factorial ================================="<<endl;
			cout<<"================================================================================"<<endl;
			cout<<"\nIngrese numero entero positivo: ";
			cin>>num;
			cout<<endl;
			cin.clear();
			cin.ignore();
			if(cin.fail()){
				system("cls");
				cout<<"El valor no fue numerico."<<endl;
				system("pause");
				system("cls");
				continue;
			};
			break;
		}while(cin.fail());
		
		if(num < 1){
			system("cls");
			cout<<"El numero no es entero positivo o es cero. vuelva a introducirlo"<<endl;
			system("pause");
		}
	}while(num < 1);
	 
	 if(num % 2 == 0){
	 	cout<<"\nEl numero "<<num<<" es par."<<endl;
	 }else{
	 	cout<<"\nEl numero "<<num<<" es impar."<<endl;
	 };
	
	cout<<"El Factorial del numero "<<num<<" es: "<<fact(num)<<endl;
	system("pause");
	 
		
}

//conversor temp
float toFaren(float c){
	return ((c*1.8)+32);
}
float toCelsi(float f){
	return ((f-32)*0.555555556);
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
		cin.clear();
		cin.ignore();
		switch(opt){
			case 1:
					float tempC;
					do{
						cout<<"Ingrese Temp en grado Celsius: ";
						cin>>tempC;
						cout<<endl;
						cin.clear();
						cin.ignore();
						if(cin.fail()){
							system("cls");
							cout<<"El valor no fue numerico."<<endl;
							system("pause");
							system("cls");
							continue;
						};
						break;
					}while(cin.fail());
					cout<<tempC<<" grados Celsius es igual a : "<<toFaren(tempC)<<" grados Farenheit."<<endl;
			break;
			case 2:
					float tempF;
					do{
						cout<<"Ingrese Temp en grado Farenheit: ";
						cin>>tempF;
						cout<<endl;
						cin.clear();
						cin.ignore();
						if(cin.fail()){
							system("cls");
							cout<<"El valor no fue numerico."<<endl;
							system("pause");
							system("cls");
							continue;
						};
						break;
					}while(cin.fail());
					cout<<tempF<<" grados Farenheit es igual a : "<<toCelsi(tempF)<<" grados Celsius."<<endl;
			break;
			default:
				cout<<"Continuara al Menu principal..."<<endl;
				system("pause");

		};
		system("pause");
	}
	catch(int e){
		cout<<e<<endl;
	}
}

//MAIN
int main (){
	int opt;
	bool flag = 1;
	while(flag){
		cout<<"================================================================================"<<endl;
		cout<<"================== Bienvenido Profesor Ramon Jimenez ==========================="<<endl;
		cout<<"================================================================================"<<endl;
		cout<<"Este Programa contiene todas funcionalidades pedidas en practica.\n"<<endl;
		cout<<"El siguinte fue hecho por los Estudiantes de las seccion 0407:\n"<<endl;
		cout<<"\t\t*Anderson Jimenez Santana  17-EIST-1-118\n\n\t\t*Alvaro Michell Castro 17-EIST-1-072\n\n\t\t*Jean Garcia Rodriguez 17-EISN-1-124\n"<<endl;
		
		cout<<"Seleccione la funcion:"<<endl;
		cout<<"\t[1] Impresion de Nota"<<"\t\t[2] Casa de cambio\n"<<endl;
		cout<<"\t[3] Nomina de pago"<<"\t\t[4] Conversor de unidades\n"<<endl;
		cout<<"\t[5] Factorial de entero positivo"<<"\t[6] Conversor de temperatura\n"<<endl;
		cout<<"\t\t\t[Salir] cualquier otra tecla \n"<<endl;
		cout<<"Opcion: ";
		cin>>opt;
		cout<<endl;
		cin.clear();
		cin.ignore();
		
		switch(opt){
			case 1:
				nota();
			break;
			case 2:
				casaDecambio();
			break;
			case 3:
				nominaDePago();
			break;
			case 4:
				ConversorUnidades();
			break;
			case 5:
				factorialDelpositivo();
			break;
			case 6:
				convertor();
			break;											
			default:
				flag = cin.fail();
				if(opt < 1 or opt > 6){
					flag = 0;
				};	
		};
	};
	system("cls");
	cout<<"Gracias por usar el programa."<<endl;
	cout<<"Este Programa contiene todas funcionalidades pedidas en practica.\n"<<endl;
	cout<<"El siguinte fue hecho por los Estudiantes de las seccion 0407:"<<endl;
	cout<<"\t\t*Anderson Jimenez Santana  17-EIST-1-118\n\n\t\t*Alvaro Michell Castro 17-EIST-1-072\n\n\t\t*Jean Garcia Rodriguez 17-EISN-1-124"<<endl;
	system("pause");
	return 0;
}
