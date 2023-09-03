#include<iostream>
//operadores: ==, !=, >>, <<, +, < y >,
using namespace std;

class Empleado{
	private:
		int ClaveEmpleado;
		string Nombre;
		string Domicilio;
		float Sueldo;
		string ReportaA;
	public:
		Empleado(int C, string N, string D, float S, string R): ClaveEmpleado(C), Nombre(N), Domicilio(D), Sueldo(S), ReportaA(R){}
		
	friend Empleado operator +(Empleado& e1, Empleado& e2){
    	return Empleado(e1.ClaveEmpleado+e2.ClaveEmpleado, e1.Nombre+e2.Nombre, e1.Domicilio+e2.Domicilio, e1.Sueldo+e2.Sueldo, e1.ReportaA+e2.ReportaA);
    }
    	
    friend bool operator ==(Empleado& e1, Empleado& e2){
        return (e1.ClaveEmpleado == e2.ClaveEmpleado &&
            e1.Nombre == e2.Nombre &&
            e1.Domicilio == e2.Domicilio &&
            e1.Sueldo == e2.Sueldo &&
            e1.ReportaA == e2.ReportaA);
    }

    friend bool operator !=(Empleado& e1, Empleado& e2){
        return !(e1 == e2);
    }

    friend istream& operator >>(istream& input, Empleado& e){
	    cout << "\nIngrese la clave del empleado: ";
	    input >> e.ClaveEmpleado;
	    cout << "\nIngrese el nombre del empleado: ";
	    input >> e.Nombre;
	    cout << "\nIngrese el domicilio del empleado: ";
	    input >> e.Domicilio;
	    cout << "\nIngrese el sueldo del empleado: ";
	    input >> e.Sueldo;
	    cout << "\nIngrese a quien reporta el empleado: ";
	    input >> e.ReportaA;
	    return input;
	}

    friend ostream& operator <<(ostream& out, Empleado& e){
        out<<"Clave: "<<e.ClaveEmpleado<<"\n";
        out<<"Nombre: "<<e.Nombre<<"\n";
        out<<"Domicilio: "<<e.Domicilio<<"\n";
        out<<"Sueldo: "<<e.Sueldo<<"\n";
        out<<"Reporta a: "<<e.ReportaA<<"\n";
        return out;
    }

    friend bool operator <(Empleado& e1, Empleado& e2) {
        return e1.ClaveEmpleado < e2.ClaveEmpleado;
    }
    
    friend bool operator >(Empleado& e1, Empleado& e2) {
        return e1.ClaveEmpleado > e2.ClaveEmpleado;
    }
    
    int clave(){
    	return ClaveEmpleado;
	}
	
	void ActualSueldo(float Incremento){
		Sueldo = Sueldo + ((Sueldo*Incremento)/100);
	}
	
	void CambiaDomicilio(string domicilio){
		Domicilio = domicilio;
	}
	void CambiaReportaA(string nombre){
		ReportaA = nombre;
	}
};

int main(){
	Empleado JefePlanta(1, "Pancracio", "Calle Imaginaria", 5500, "Amigue"), JefePersonal(2, "Patroclo", "Grecia", 10000, "Menecio");
	
	int opcion, clave;
	string Domicilio, Reporta;
	float Sueldo;
	
	while(opcion != 5){
		cout<<"*****Menu*****"<<endl;
		cout<<"1.- Cambiar Domicilio"<<endl;
		cout<<"2.- Cambiar Reportar A"<<endl;
		cout<<"3.- Incrementar Sueldo"<<endl;
		cout<<"4.- Mostrar Empleado"<<endl;
		cout<<"5.- Salir"<<endl;
		cout<<"Ingrese su opcion: ";
		cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"Ingrese la clave: ";
				cin>>clave;
				if(clave == JefePlanta.clave()){
					cout<<"Ingrese el nuevo domicilio: ";
					cin.ignore();
					getline(cin, Domicilio);
					JefePlanta.CambiaDomicilio(Domicilio);
				}else if(clave == JefePersonal.clave()){
					cout<<"Ingrese el nuevo domicilio: ";
					cin.ignore();
					getline(cin, Domicilio);
					JefePersonal.CambiaDomicilio(Domicilio);
				}else
					cout<<"No se encontro la clave"<<endl;
				break;
			case 2:
				cout<<"Ingrese la clave: ";
				cin>>clave;
				if(clave == JefePlanta.clave()){
					cout<<"Ingrese el nuevo Reporta A: ";
					cin>>Reporta;
					JefePlanta.CambiaReportaA(Reporta);
				}else if(clave == JefePersonal.clave()){
					cout<<"Ingrese el nuevo Reporta A: ";
					cin>>Reporta;
					JefePersonal.CambiaReportaA(Reporta);
				}else
					cout<<"No se encontro la clave"<<endl;
				break;
			case 3:
				cout<<"Ingrese la clave: ";
				cin>>clave;
				if(clave == JefePlanta.clave()){
					cout<<"Ingrese el incremento: ";
					cin>>Sueldo;
					JefePlanta.ActualSueldo(Sueldo);
				}else if(clave == JefePersonal.clave()){
					cout<<"Ingrese el incremento: ";
					cin>>Sueldo;
					JefePersonal.ActualSueldo(Sueldo);
				}else
					cout<<"No se encontro la clave"<<endl;
				break;
			case 4:
				cout<<"Ingrese la clave: ";
				cin>>clave;
				if(clave == JefePlanta.clave()){
					cout<<JefePlanta;
				}else if(clave == JefePersonal.clave()){
					cout<<JefePersonal;
				}else
					cout<<"No se encontro la clave"<<endl;
				break;
			case 5:
				cout<<"Saliendo"<<endl;
				break;
			default:
				cout<<"Elija una opcion valida "<<endl;
				break;
		}
	}
	
	return 0;
}