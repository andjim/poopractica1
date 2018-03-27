/*MATERIA: PROGRAMCION ORIENTADA A OBJETOS;
  PROFESOR: RAMON JIMENEZ;
	Este programa fue hecho por los estudiante de la seccion 0407:
				*Anderson Jimenez Santana 17-EIST-1-118;
				*Alvaro Michell Castro 17-EIST-1-072;
				*Jean Garcia Rodriguez 17-EISN-1-124;
*/



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
	/*
		Esta funcion muestra la calificacion de los estudiantes y nota con la que pasan la materia;
		esta pide datos como nombre, seccion, matricula, materia y profesor; mas las puntuaciones 
		pertinentes a asistencia, trabajo practico, primer parcial y examen final.
	
	*/
	string nom, matri, sec, materia, prof;//inicializando la variables de texto;
	string* Pnom = &nom;//se crean los punteros de las variables de texto para luego almacenarlas
	string* Pmatri = &matri;
	string* Psec = &sec;
	string* Pmateria = &materia;
	string* Pprof = &prof;//hasta aqui los punteros de txt;
	int as,tp,pp,ef; //declarando variables numericas donde se guardaran las calificaciones;
	int* numCamp[] = {&as,&tp,&pp,&ef}; //se almacena los punteros de las var numericas en un array;
	string* txtCamp[] = {Pnom,Pmatri,Psec,Pmateria,Pprof};//se almacena los punteros de las var numericas en un array
	//este array de strings contiene la cadenas que seran mostradas en el <cout> al pedir los diferentes datos de txt;
	string txtToPrint[] = {"Nombre de estudiante","Matricula de estudiante (se aceptan -)","Seccion","Materia","Nombre del Profesor"};
	//en este se hace lo mismo que en el anterior pero para las numericas;
	string intTxtToPrint[] = {"Asistencia (0-10)","Trabajo practico(0-20)","Primer parcial(0-20)","Examen final(0-50)"};
	cout<<"================================================================================"<<endl;
	cout<<"============================ Calificaciones(La nota) ==========================="<<endl;
	cout<<"================================================================================"<<endl;
	
	for(int i =0; i < sizeof(txtCamp)/ sizeof(*txtCamp); i++ ){
		string lin;
		do{
			
			cout<<"Ingrese "<<txtToPrint[i]<<" : ";
			getline(cin, *txtCamp[i]);//se ingresa el dato pedido y se almacena en la dirrecion de memoria correspondiente;
			cout<<endl;
			lin = *txtCamp[i]; // <lin> se le da el valor que se acaba de introducir para poder validarlo en la funcion <onlySpace>
			
			if(onlySpace(lin)) cout<<"Campo Obligatorio*\n"<<endl;
			/*
				en el while se valida que los campos no sean llenados con espacios
				utilizando la funcion <onlySpace>;
			*/			
		}while(onlySpace(lin));
		/*
			el <for> tiene por limite la cantidad de elementos en el array <txtCamp>
			al hacer la opercaion de dividir el tamaño(bytes) del array entre el tamano asignado
			a su tipo de dato <string> que es 8; 
		*/
	};
	/*as < 0 or as > 10
	  tp < 0 or as > 20
	  pp < 0 or as > 20
	  ef < 0 or as > 50
	*/
	int limites[] = {10,20,20,50};// estos son lo maximos de los valores numericos se les puede asignar;
	cout<<"Ingrese las calificaciones del estudiante:"<<endl;
	for(int i = 0; i < sizeof(numCamp) / sizeof(*numCamp); i++ ){
		while(true){//se inicia un bucle infinito, que solo puede ser detenido con la sentencia <break>;
			cout<<"\t"<<intTxtToPrint[i]<<": ";
			cin>> *numCamp[i];//se asigna el valor en la dirrecion que el aputador corresponde;
			cout<<endl;
			
			if(cin.fail()){//si el valor introducido no corresponde con el tipo de variable, <cin.fail> retorna true que indica que fallo la entrada de datos;
				cout<<"*Eso no fue un numero entero.*"<<endl;
				cin.clear();//limpia el espacio en memoria <buffer> asignado a la entrada de datos;
				cin.ignore();//arregla el stream de datos;
				continue;//pasa a la sigte iteracion, ignorando el codigo de abajo;
			}else{
				if(*numCamp[i] < 0 or *numCamp[i] > limites[i]){//aqui se valida que el valor numerico este en el rango que corresponda ej: asistencia de 0 a 10;
					cout<<"*El Valor no esta dentro del rango. Vuelva ingresarlo.*"<<endl;
					continue;//pasa a la sigte iteracion, ignorando el break que terminara el bucle while;
				};
			};
			break;//solo se ejecutara si el dato entrado pasa la validaciones anteriores
		};
		/*
			este <for> hace el mismo proceso que el de los valores numnericos
		*/
	};
	
	int total = as+tp+pp+ef;//se hace una sumatoria de las calificaciones
	string NT;//nota en letra;
	
	if(total>=90){//de 90 en adelante una A
		NT = 'A';
	}else if(total <= 89 && total >=80){ //entre 89 - 80 B
		NT = 'B';
	}else if(total <=79 && total >= 75){//entre 79 - 75 C
		NT = 'C';
	}else if(total <= 74 && total >= 70){//entre 74 - 70 D
		NT = 'D';
	}else if(total <= 69 && total >= 60){//entre 69 - 60 FE
		NT = "FE";
	}else if(total <= 59 && total >= 50){//entre 59 - 50 FI
		NT = "FI";
	}else{//menor a 50 F
		NT = 'F'; 
	};
	
	//Se limpia la pantalla y se imprimen los datos obtenidos previamente;
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
	/*
		<moneda> nombre de la divisa a cambiar;
		<tc> tipo de cambio, si es de Dolar a Peso, cualquier otra opcion;
		<divisaFrom> codigo monetario de la divisa a cambiar ej: Dollar -> USD;
		<divisaTo> codigo monetario de la divisa que sera devuelta ej: Peso domincano -> DOP;
		<cliente> nombre del cliente;
		<nac> nacionalidad del cliente;
		<razonDecambio> razon con la cual una divisa incrementa en razon del incremento de la otra;
		<multiOrdiv> valor numerico que indica si para pasar de una moneda a otra es multiplicar o dividir;
	*/
	
	long double cant,cn,ct;//almacenaran cantidad a camniar, cambio neto y cambio total, correspondientemente;
	float interes = 0.03;// interes a cobrar 3%;
	
	while(true){
		cout<<"Ingrese la cantidad de "<<moneda<<": ";
		cin>>cant; //cantidad a cambiar
		cout<<endl;
		cin.clear();
		cin.ignore();
		
		if(cin.fail()){//este proceso es el mismo que vimos en la nota para validar los datos numericos;
			system("cls");
			cout<<"Eso no fue un numero. Vuelva ingresar"<<endl;
			system("pause");
			system("cls");
			continue;
		};
		break;
	}
	if(multiOrdiv == 0){//si <multiOrdiv> es igual a 0 se multiplica, de lo contrario se divide;
		cn = cant*razonDecambio;
	}else{
		cn = cant/razonDecambio;
	}
	
	ct = cn-(cn*interes);// se le resta el 3% a la cantidad cambiada;
	//se imprime el recibo
	cout<<"Cliente: "<<cliente<<"\tNacionalidad: "<<nac<<"\n"<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<"\n"<<"Tipo de cambio\t"<<"Cantidad\t"<<endl;
	cout<<tc<<"\t"<<cant<<" "<<divisaFrom<<"\n"<<endl;
	cout<<"Cambio Neto\t"<<"Cambio Total(-3%)"<<endl;
	cout<<cn<<divisaTo<<"\t"<<ct<<" "<<divisaTo<<"\n"<<endl;
	cout<<"*******************************************************************************"<<endl;
}

void casaDecambio(){
	
	double usdToeur = 0.80929;//razon de cambio del dolar respecto al euro;
	double usdToGbp = 0.70777;//razon de cambio del dolar respecto a la libra esterlina;
	double usdToDop = 49.536; //razon de cambio del dolar respecto al peso dom;	
	double eurToDop = 61.20917;//razon de cambio del euro respecto al peso dom;
	double eurToGbp = 0.87455;//razon de cambio del euro respecto a la libra esterlina;
	double GbpToDop = 69.989;//razon de cambio de la libra esterlina respecto al peso;
	string cliente;// nombre del cliente;
	string nac;// nacionalidad del cliente;
	
	int opt;// se almacena la opcion elegida;
	cout<<"================================================================================"<<endl;
	cout<<"=============================== Casa de cambio =================================="<<endl;
	cout<<"================================================================================"<<endl;
	
	do{
		cout<<"Nombre: ";
		getline(cin,cliente);
		cout<<endl;
		if(onlySpace(cliente)) cout<<"Campo obligatorio*"<<endl;
	}while(onlySpace(cliente));//se valida que el campo no sea llenado con espacios;
	
	do{
		cout<<"Nacionalidad: ";
		getline(cin,nac);
		cout<<endl;
		if(onlySpace(nac)) cout<<"Campo obligatorio*"<<endl;
	}while(onlySpace(nac));//se valida que el campo no sea llenado con espacios;
	
		cout<<"Seleccione tipo de cambio:"<<endl;
		cout<<"\t[1] Dolar a Peso"<<"\t[2] Dolar a Libra"<<"\t[3] Dolar a Euro\n"<<endl;
		cout<<"\t[4] Euro a Dolar"<<"\t[5] Euro a Peso"<<"\t\t[6] Euro a Libra\n"<<endl;
		cout<<"\t[7] Libra a Peso"<<"\t[8] Libra a Euro"<<"\t[9] Libra a Dolar\n"<<endl;
		cout<<"\t[10] Peso a Dolar"<<"\t[11] Peso a Euro"<<"\t[12] Peso a Libra\n"<<endl;
		cout<<"\t\t\t[Salir] cualquier otra tecla \n"<<endl;
		cout<<"Opcion: ";
		cin>>opt;
		cin.clear();//se limpia el buffer
		cin.ignore();//se repara la entrada de datos en caso de que el dato no sea numerico;
		
	

	switch(opt){
		case 1://Dolar-Peso
			recibo("dolares","Dolar - Peso","USD","DOP",cliente,nac,usdToDop,0);
			 
		break;
		case 2://Dolar-Libra
			recibo("dolares","Dolar - Libra","USD","GBP",cliente,nac,usdToGbp,0);
			 
		break;
		case 3://Dolar-euro
			recibo("dolares","Dolar - Euro","USD","EUR",cliente,nac,usdToeur,0);
			 
		break;
		case 4://Euro - Dolar
			recibo("euros","Euro - Dolar","EUR","USD",cliente,nac,usdToeur,1);
			 
		break;
		case 5://Euro - Peso
			recibo("euros","Euro - Peso","EUR","DOP",cliente,nac,eurToDop,0);
			 
		break;
		case 6://Euro - Libra
			recibo("euros","Euro - Libra","EUR","GBP",cliente,nac,eurToGbp,0);
		break;
		case 7://Libra - Peso
			recibo("libras","Libra - Peso","GBP","DOP",cliente,nac,GbpToDop,1);
			 
		break;
		case 8://Libra - Euro
			recibo("libras","Libra - Euro","GBP","EUR",cliente,nac,eurToGbp,1);
			 
		break;
		case 9:
			recibo("libras","Libra - Dolar","GBP","USD",cliente,nac,usdToGbp,1);
			 
		break;
		case 10://Peso - Euro
			recibo("pesos","Peso - Euro","DOP","EUR",cliente,nac,eurToDop,0);
			 
		break;
		case 11://Peso - Dolar
			recibo("pesos","Peso - Dolar","DOP","USD",cliente,nac,usdToDop,0);
			 
		break;
		case 12://Peso - Libra
			recibo("pesos","Peso - Libra","DOP","GBP",cliente,nac,GbpToDop,0);
			 
		break;
		default://cualquier valor que no corresponda con los del rango [1,12] terminara la ejecuccion de la funcion de cambio; 
		break;
	};
	system("pause");
	
}

//nominaDePago
void nominaDePago(){
	/*
		<pagoxh> almacena lo que se gana por hora;
		<horasTrabajadas> almacena las horas de trabajo normales;
		<horasExtras> almacena la s horas de trabajo extra;
		<totalDehoras> es la suma de las todas la horas trabajadas y extra;
		<sueldoLaboral> almacena lo que se gana al multiplicar <horasTrabajas> * <pagoxh>;
		<sueldoExtra> almacena lo que se gana al multiplicar <horasExtras> * <pagoxh + 35%>; 
		<sueldoBruto> almacena la sumatoria del <sueldoLaboral> + <sueldoExtra>;
		<afp> almacena lo que se saca del <sueldoBruto> para fondo de pension; 3%
		<ars> almacena lo que se sca del <sueldoBruto> para salud; 3%
		<sueldoTotal> almacena lo que resta del <sueldoBruto> al sacarle <afp> y <ars>;
	*/
	long double pagoxh,sueldoLaboral,sueldoExtra,sueldoBruto, afp, ars,sueldoTotal;
	float horasTrabajadas, horasExtras, totalDehoras;
	string empleado;// nombre del empleado
	
	cout<<"================================================================================"<<endl;
	cout<<"================================= Nomina de Pago =============================="<<endl;
	cout<<"================================================================================"<<endl;
	
	do{
		cout<<"Intoduzca Nombre: ";
		getline(cin,empleado);
		cout<<endl;
		if(onlySpace(empleado)) cout<<"Campo obligatorio*"<<endl;
	}while(onlySpace(empleado));//validacion de txt;

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
	}while(cin.fail());////validacion de campo numerico;
	
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
		}while(cin.fail());//validacion de campo numerico;
		
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
		}while(cin.fail());//validacion de campo numerico;
		
		totalDehoras = horasTrabajadas +  horasExtras;
		if(totalDehoras > 88){ //si el total de horas trabajadas es mayor a 88, que es la cantidad maxima laborable en una quincena debe introducir las horas de nuevo;
			cout<<"El total de horas laboradas exede el total que se puede laborar en una quincena.\n Por favor, se que ha trabajado mucho, pero vuelva a ingresar la horas que laboro."<<endl;
		};
		}while(totalDehoras > 88);
		
	sueldoLaboral = horasTrabajadas * pagoxh;
	sueldoExtra = horasExtras * (pagoxh + (pagoxh * 0.35));
	sueldoBruto = sueldoLaboral + sueldoExtra;
	ars = afp= sueldoBruto * 0.03;
	sueldoTotal = (sueldoBruto - ars) -afp;
	
	
	//muestra en pantalla la nomina;
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
	double PiesToPulg = 12;//cantidad de pulgadas en un pie;
	double mtsToCenti = 100;//cantidad de centimetros en un metro;
	double milTokilo = 1.609;//cantidad de kilometros en una milla;
	int opt;//opcion;
	double medida;//valor de la medida a cambiar;
	
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
			}while(cin.fail());//se valora que el input sea numerico.
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
			}while(cin.fail());//se valora que el input sea numerico.
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
			}while(cin.fail());//se valora que el input sea numerico.
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
			}while(cin.fail());//se valora que el input sea numerico.
			
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
			}while(cin.fail());//se valora que el input sea numerico.
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
			}while(cin.fail());;//se valora que el input sea numerico.
			cout<<medida<<" kilometros son: "<<medida/milTokilo<<" millas."<<endl;
		break;											
		default:break;
	}//si l aopcion no esta en el rango [1,6] termina la ejeccion de la funcion;
	system("pause");
};

//factorial

long int fact(long int n){//funcion recursiva que devuelve el factorial de un numero;
	if(n < 1) return 1;
	return n*fact(n-1);
}
void factorialDelpositivo(){
	long int num;//almacena numero a procesar;
	
	
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
		}while(cin.fail());//valida que se haya ingresado un numero entero;
		
		if(num < 1){//valida que el numero sea positivo
			system("cls");
			cout<<"El numero no es entero positivo o es cero. vuelva a introducirlo"<<endl;
			system("pause");
		}
	}while(num < 1);//hasta que el numero ingresado no sea un numero positivo no se sale del bucle;
	 
	 if(num % 2 == 0){//se comprueba que el numero sea par o impar para mostrarlo en pantalla;
	 	cout<<"\nEl numero "<<num<<" es par."<<endl;
	 }else{
	 	cout<<"\nEl numero "<<num<<" es impar."<<endl;
	 };
	
	cout<<"El Factorial del numero "<<num<<" es: "<<fact(num)<<endl;//se muestra el factorial del numero;
	system("pause");
	 
		
}

//conversor temp
float toFaren(float c){//devuelve temperatura en farenheit;
	return ((c*1.8)+32);
}
float toCelsi(float f){//devuelve temperatura ne celsius;
	return ((f-32)*0.555555556);
}
void convertor(){

	
	int opt;//opcion;

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
		case 1://Celsius a Faren
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
				}while(cin.fail());//se valida que sea numero;
				cout<<tempC<<" grados Celsius es igual a : "<<toFaren(tempC)<<" grados Farenheit."<<endl;//se muestra en pantalla la temperatura convertida;
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
				}while(cin.fail());//se valida que sea numero;
				cout<<tempF<<" grados Farenheit es igual a : "<<toCelsi(tempF)<<" grados Celsius."<<endl;//se muestra en pantalla la temperatura convertida;
		break;
		default:
			cout<<"Continuara al Menu principal..."<<endl;
			system("pause");

	};
	system("pause");//termina la ejeccion de la funcion;
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
		//si opt no se le ingreso un valor numerico, se le asigna 0 automaticamente;
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
				if(opt < 1 or opt > 6){//si el valor de opt no esta en el rango [1,6] termina el programa;
					flag = 0;//flag se igual a 0 o falso, por tanto termina el bucle;
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
