#include<iostream>

using namespace std;

class Materia{
	private:
		int Clave;
		string Nombre;
		string ProfesorTit;
		string LibroTexto;
	public:
		Materia(int C, string N, string P, string L): Clave(C), Nombre(N), ProfesorTit(P), LibroTexto(L){};
		
	friend Materia operator +(Materia& m1, Materia& m2){
        return Materia(m1.Clave+m2.Clave, m1.Nombre+m2.Nombre, m1.ProfesorTit+m2.ProfesorTit, m1.LibroTexto+m2.LibroTexto);
    }
    	
    friend bool operator ==(Materia& m1, Materia& m2){
        return (m1.Clave == m2.Clave &&
            m1.Nombre == m2.Nombre &&
            m1.ProfesorTit == m2.ProfesorTit &&
            m1.LibroTexto == m2.LibroTexto);
    }

    friend bool operator !=(Materia& m1, Materia& m2){
        return !(m1 == m2);
    }

    friend istream& operator >>(istream& input, Materia& m){
	    cout << "\nIngrese la clave de la Materia: ";
	    input >> m.Clave;
	    cout << "\nIngrese el nombre de la Materia: ";
	    input >> m.Nombre;
	    cout << "\nIngrese el ProfesorTit de la Materia: ";
	    input >> m.ProfesorTit;
	    cout << "\nIngrese el Nombre del Libro: ";
	    input >> m.LibroTexto;
	    return input;
	}

    friend ostream& operator <<(ostream& out, Materia& m){
        out<<"Clave: "<<m.Clave<<"\n";
        out<<"Nombre: "<<m.Nombre<<"\n";
        out<<"ProfesorTit: "<<m.ProfesorTit<<"\n";
        out<<"Libro de Texto: "<<m.LibroTexto<<"\n";
        return out;
    }

    friend bool operator <(Materia& m1, Materia& m2) {
        return m1.Clave < m2.Clave;
    }
    
    friend bool operator >(Materia& m1, Materia& m2) {
        return m1.Clave > m2.Clave;
    }
		
	void CambiaClave(int clave){
		Clave = clave;
	}
	void CambiaProfe(string profe){
		ProfesorTit = profe;
	}
};

int main(){
	Materia Programacion(1, "Programacion", "Cain", "Como Programar"), BasesDatos(2, "Bases De Datos", "Francisco", "Bases de datos Relacionales");
	int opcion, clave;
	string nombre;
	
	while(opcion != 4){
		cout<<"*****Menu*****"<<endl;
		cout<<"1.- Cambiar la clave de la materia Programacion"<<endl;
		cout<<"2.- Cambiar el nombre del maestro de Bases de Datos"<<endl;
		cout<<"3.- Mostrar todos los datos de la materia DB"<<endl;
		cout<<"4.- Salir"<<endl;
		cout<<"Ingrese su opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"Ingrese la nueva clave: ";
				cin>>clave;
				Programacion.CambiaClave(clave);
				break;
			case 2:
				cout<<"Ingresa el nuevo nombre del maestro para DB: ";
				cin.ignore();
				getline(cin, nombre);
				BasesDatos.CambiaProfe(nombre);
				break;
			case 3:
				cout<<BasesDatos;
				break;
			case 4:
				cout<<"Saliendo...";
				break;
			default:
				cout<<"Ingrese una opcion valida"<<endl;
				break;
		}
	}
	return 0;
}