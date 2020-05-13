#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
#include <type_traits>

using namespace std;

template< typename T > constexpr size_t countof( const T & ) noexcept {
  return sizeof( T ) / sizeof( typename remove_all_extents< T >::type );
}

struct ninio{
    string nombre;
    char sexo;
    int edad;
    string guarderia;
    string ubicacion;
};

struct departamento {string nombre;};

void mp();
void agregar();
void reportePorcentaje();
void reporteGrupo();
void reporteMayor();

int main(){
	mp();
}

void mp(){
	MenuPrincipal:
			int i;
			system("CLS");
			cout<<"--------------------"<<endl;
			cout<<"------ UNICEF ------"<<endl;
			cout<<"   Menu Principal   "<<endl;
			cout<<"--------------------"<<endl;
			cout<<"1 - Agregar registro"<<endl;
			cout<<"2 - Reporte porcentaje"<<endl;
			cout<<"3 - Reporte grupo"<<endl;
			cout<<"4 - Reporte mayor"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"5 - Salir"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;

			switch(i){
				case 1:
					{agregar();}
					system("cls");
					goto MenuPrincipal;
					break;
				case 2:
					{reportePorcentaje();}
					system("cls");
					goto MenuPrincipal;
					break;
                case 3:
                    {reporteGrupo();}
					system("cls");
					goto MenuPrincipal;
					break;
                case 4:
                    {reporteMayor();}
					system("cls");
					goto MenuPrincipal;
					break;
				case 5:
					break;
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar. "<<endl;
					system("Pause");
					goto MenuPrincipal;
					break;
			}
}

void agregar(){
	Agregar:
		ofstream archivo;
		string nombreArchivo;
		fflush(stdin);
		system("CLS");
		cout<<"Indique nombre de archivo: ";
		getline(cin,nombreArchivo);
		archivo.open(nombreArchivo.c_str(),ios::app);

		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		archivo.close();

		fflush(stdin);
		system("CLS");

		string nombre;
		string guarderia;
		string descripcion;
		string ubicacion;
		int edad = 0;
		int dep = 0;
		char sexo;

		departamento listaDepartamento[22];
		listaDepartamento[0].nombre = "Alta Verapaz";
		listaDepartamento[1].nombre = "Baja Verapaz";
		listaDepartamento[2].nombre = "Chimaltenango";
		listaDepartamento[3].nombre = "Chiquimula";
		listaDepartamento[4].nombre = "El Progreso";
		listaDepartamento[5].nombre = "Escuintla";
		listaDepartamento[6].nombre = "Guatemala";
		listaDepartamento[7].nombre = "Huehuetenango";
		listaDepartamento[8].nombre = "Izabal";
		listaDepartamento[9].nombre = "Jalapa";
		listaDepartamento[10].nombre = "Jutiapa";
		listaDepartamento[11].nombre = "Peten";
		listaDepartamento[12].nombre = "Quetzaltenango";
		listaDepartamento[13].nombre = "Quiche";
		listaDepartamento[14].nombre = "Retalhuleu";
		listaDepartamento[15].nombre = "Sacatepequez";
		listaDepartamento[16].nombre = "San Marcos";
		listaDepartamento[17].nombre = "Santa Rosa";
		listaDepartamento[18].nombre = "Solola";
		listaDepartamento[19].nombre = "Suchitepequez";
		listaDepartamento[20].nombre = "Totonicapan";
		listaDepartamento[21].nombre = "Zacapa";

		int x = countof(listaDepartamento);
        cout<<"--- Listado de departamentos ---"<<endl;
        for(int i = 0; i < x; i++){
            cout<<i+1<<" - "<<listaDepartamento[i].nombre<<endl;
        }
        cout<<"Ingrese departamento [1-22]: ";
        cin>>dep;

        if(dep < 1){
            cout<<"Opcion seleccionada no existe. Intente de nuevo."<<endl;
            system("Pause");
            goto Agregar;
        }

        if(dep > x){
            cout<<"Opcion seleccionada no existe. Intente de nuevo."<<endl;
            system("Pause");
            goto Agregar;
        }

        ubicacion = listaDepartamento[dep-1].nombre;

        cin.ignore();
		cout<<"Ingrese nombre del ninio: ";
		getline(cin, nombre);

		cout<<"Ingrese edad del ninio: ";
		cin>>edad;

		if(edad < 1 ){
			cout<<"Debe ingresar una edad valida [0-12 anios]. Intente de nuevo."<<endl;
			system("Pause");
			goto Agregar;
		}

		cout<<"Ingrese sexo del ninio [m - masculino / f - femenino, ingrese letra]: ";
		cin>>sexo;

		sexo = toupper(sexo);

		switch(sexo){
            case 'M':
                descripcion = "Masculino";
                break;
            case 'F':
                descripcion = "Femenino";
                break;
            default:
                system("CLS");
                cout<<"Opcion seleccionada no existe. Intente de nuevo."<<endl;
                system("Pause");
                goto Agregar;
                break;
		}
        cin.ignore();
        cout<<"Ingrese nombre de la guarderia: ";
		getline(cin, guarderia);

		cout<<endl;

        nombre = regex_replace(nombre, regex("\\s+"), "_");
        nombre = regex_replace(nombre, regex("\\W+"), "");

        guarderia = regex_replace(guarderia, regex("\\s+"), "_");
        guarderia = regex_replace(guarderia, regex("\\W+"), "");

        ubicacion = regex_replace(ubicacion, regex("\\s+"), "_");
        ubicacion = regex_replace(ubicacion, regex("\\W+"), "");

		ninio lista[1];

		lista[0].nombre = nombre;
        lista[0].sexo = sexo;
        lista[0].edad = edad;
        lista[0].guarderia = guarderia;
        lista[0].ubicacion = ubicacion;

		archivo.open(nombreArchivo.c_str(),ios::app);
		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		system("CLS");

        archivo<<lista[0].nombre<<'\t'
            <<lista[0].sexo<<'\t'
            <<lista[0].edad<<'\t'
            <<lista[0].guarderia<<'\t'
            <<lista[0].ubicacion<<endl;

		archivo.close();
		cout<<"Registros almacenados exitosamente."<<endl;
		system("Pause");
};

void reportePorcentaje(){
     ifstream archivo;
	 string nombreArchivo,s, nombre;

	 fflush(stdin);
	 system("CLS");

	 cout<<"Ingrese nombre del archivo: ";
	 getline(cin, nombreArchivo);

	 archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 int lineas=0;
	 while(getline(archivo, s))
		lineas++;

     archivo.close();
     system("CLS");

     ninio lista[lineas];

     archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 for(int i = 0; i < lineas; i++){
		 archivo>>lista[i].nombre
                >>lista[i].sexo
                >>lista[i].edad
                >>lista[i].guarderia
                >>lista[i].ubicacion;
	 }
	 archivo.close();

	 int totalGT = 0;
	 float porcentaje;
	 string ubicacion;

	 for(int i = 0; i < lineas; i++){
        ubicacion = regex_replace(lista[i].ubicacion, regex("_"), " ");
        if(ubicacion == "Guatemala"){
            totalGT++;
        }
	 }

	 porcentaje = ((float)totalGT/(float)lineas)*100;

	 system("CLS");
	 cout<<"        Reporte         "<<endl;
     cout<<"------------------------"<<endl;
     cout<<"- % ninos en el departamento de Guatemala: "<<porcentaje<<"%"<<endl;
	 cout<<"- % ninos en el resto del pais: "<<(100-porcentaje)<<"%"<<endl;
	 system("Pause");
};

void reporteGrupo(){
     ifstream archivo;
	 string nombreArchivo,s, nombre;

	 fflush(stdin);
	 system("CLS");

	 cout<<"Ingrese nombre del archivo: ";
	 getline(cin, nombreArchivo);

	 archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 int lineas=0;
	 while(getline(archivo, s))
		lineas++;

     archivo.close();
     system("CLS");

     ninio lista[lineas];

     archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 for(int i = 0; i < lineas; i++){
		 archivo>>lista[i].nombre
                >>lista[i].sexo
                >>lista[i].edad
                >>lista[i].guarderia
                >>lista[i].ubicacion;
	 }
	 archivo.close();

	 int grupo01 = 0;
	 int grupo02 = 0;
	 int grupo03 = 0;
	 int grupo04 = 0;

	 for(int i = 0; i < lineas; i++){
        if(lista[i].edad < 1){
            grupo01++;
        }
        if(lista[i].edad >= 1 && lista[i].edad <= 3){
            grupo02++;
        }
        if(lista[i].edad >= 4 && lista[i].edad <= 6){
            grupo03++;
        }
        if(lista[i].edad > 6){
            grupo04++;
        }
	 }

	 system("CLS");
	 cout<<"        Reporte         "<<endl;
     cout<<"------------------------"<<endl;
     cout<<"Ninios por grupo: "<<endl;
     cout<<"- Grupo 1 (< 1 anio): "<<grupo01<<endl;
	 cout<<"- Grupo 2 ( 1 - 3 anios): "<<grupo02<<endl;
	 cout<<"- Grupo 3 (4 - 6 anios): "<<grupo03<<endl;
	 cout<<"- Grupo 4 (> 6 anios): "<<grupo04<<endl;
	 system("Pause");
};

void reporteMayor(){
     ifstream archivo;
	 string nombreArchivo,s, nombre;

	 fflush(stdin);
	 system("CLS");

	 cout<<"Ingrese nombre del archivo: ";
	 getline(cin, nombreArchivo);

	 archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 int lineas=0;
	 while(getline(archivo, s))
		lineas++;

     archivo.close();
     system("CLS");

     ninio lista[lineas];

     archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 for(int i = 0; i < lineas; i++){
		 archivo>>lista[i].nombre
                >>lista[i].sexo
                >>lista[i].edad
                >>lista[i].guarderia
                >>lista[i].ubicacion;
	 }
	 archivo.close();

	 int grupo01 = 0;
	 int grupo02 = 0;
	 int grupo03 = 0;
	 int grupo04 = 0;
	 int total = 0;
	 string mensaje;

	 for(int i = 0; i < lineas; i++){
        if(lista[i].edad < 1){
            grupo01++;
        }
        if(lista[i].edad >= 1 && lista[i].edad <= 3){
            grupo02++;
        }
        if(lista[i].edad >= 4 && lista[i].edad <= 6){
            grupo03++;
        }
        if(lista[i].edad > 6){
            grupo04++;
        }
	 }

	 total = grupo01;
	 mensaje = "Grupo 1";
	 if(grupo02 > total){
        total = grupo02;
        mensaje = "Grupo 2";
	 }
	 if(grupo03 > total){
        total = grupo03;
        mensaje = "Grupo 3";
	 }
	 if(grupo04 > total){
        total = grupo04;
        mensaje = "Grupo 4";
	 }

	 system("CLS");
	 cout<<"        Reporte         "<<endl;
     cout<<"------------------------"<<endl;
     cout<<"Ninios por grupo: "<<endl;
     cout<<"- Grupo 1 (< 1 anio): "<<grupo01<<endl;
	 cout<<"- Grupo 2 ( 1 - 3 anios): "<<grupo02<<endl;
	 cout<<"- Grupo 3 (4 - 6 anios): "<<grupo03<<endl;
	 cout<<"- Grupo 4 (> 6 anios): "<<grupo04<<endl;
	 cout<<"------------------------"<<endl;
	 cout<<"Grupo con mayor cantidad de ninios es: "<<mensaje<<", con un total de: "<<total<<" ninios."<<endl;
	 system("Pause");
};
