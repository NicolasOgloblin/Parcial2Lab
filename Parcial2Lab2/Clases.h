#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

#include <ctime>
void cargarCadena(char *, int);

///  ----------------------------------------------------  CLASS EQUIPOS  ----------------------------------------------------  ///

class Equipos{
    private :
int ID ;
char nombre[30] ;
int nivel ;
bool estado ;
static int contEquipos;
    public :
      Equipos(int id=-1 , const char *n="Ninguno"  , int N=1,bool e=true){
      ID=id ;
      strcpy(nombre,n);
      nivel=N ;
      estado = e ;
      }

void setID(int id){ID=id;}
void setNombre(const char *n){
strcpy(nombre,n);
}
void setNivel(int N){if(nivel>0 && nivel<=3)nivel=N;
      else {
            cout << "Nivel Incorrecto." << endl;
            cout << "Ingrese Nuevamente 1-3 : " << endl;
            cin >> nivel;
            setNivel(nivel);
        }
        }
void setEstado(bool e){estado=e;}
int getID() {return ID ;}
const char *getNombre(){return nombre ;}
int getNivel(){return nivel; }
bool getEstado(){return estado ;}
    void Cargar();
    void Mostrar();
    void contarregistrosEquipos();


int contarRegistrosEquipos() {
        FILE* p = fopen("equipos.dat", "rb");

        if (p==NULL) {
            // Si no se pudo abrir el archivo
            if (contEquipos > 0) {
                cout << "Error de archivo." << endl;
                return -2;
            } else {
                // Si es la primera vez y el archivo está vacío
                return 0;
            }
        }

        fseek(p, 0, SEEK_END);
        int tam = ftell(p);

        fclose(p);

        if (tam == 0) {
            // Si el archivo está vacío
            return 0;
        }

        return tam / sizeof(Equipos);
    }


};

int Equipos::contEquipos = 0;

void Equipos::Cargar(){

     ID = contarRegistrosEquipos()+1;
     cout <<"NOMBRE: ";
    cargarCadena(nombre, 29);
    cout<<"NIVEL ENTRE 1 Y 3:  ";
    cin>>nivel;
    setNivel(nivel);

}

void Equipos::Mostrar(){

    cout << "ID: ";
    cout << ID << endl;
    cout <<"NOMBRE: ";
    cout << nombre << endl;
    cout <<"NIVEL: ";
    cout << nivel << endl;}
/*
void Equipos::contarregistrosEquipos(){ //vreo que hay que eliminarla. Era para comprobar que compile declarando un reg de Equipo.
    Equipos reg;
}*/

///  ----------------------------------------------------  CLASS TIPO DE DEPORTE  ----------------------------------------------------  ///

class TipodeDeporte {

    private:
        int IDTipo;
        char nombre [30];
        int nivelDificultad;
        bool estado = true;
        static int contTiposDeporte;

    public:
        TipodeDeporte ( int id=0, const char *n="Ninguno", int nivel=0, bool e=true){
             IDTipo=id;
             strcpy(nombre, n);
             nivelDificultad=nivel;
             estado=e;
        }

    void Cargar();
    void Mostrar();
    void setIDTipo(int id){IDTipo=id;}
    void setNombre (const char *n){ strcpy(nombre,n);}
    void setNivelDificultad (int n){

        if(nivelDificultad>=1 && nivelDificultad<=8) nivelDificultad =n;
        else {
            cout << "Nivel de dificultad incorrecto." << endl;
            cout << "Ingrese nuevamente: " << endl;
            cin >> nivelDificultad;
            setNivelDificultad(nivelDificultad);
        }

    }

    void setEstado (bool e){estado=e;}

    int contarRegistrosTiposdeDeporte() {
        FILE* p = fopen("TipodeDeporte.dat", "rb");

        if (p==NULL) {
            // Si no se pudo abrir el archivo
            if (contTiposDeporte > 0) {
                cout << "Error de archivo." << endl;
                return -2;
            } else {
                // Si es la primera vez y el archivo está vacío
                return 0;
            }
        }

        fseek(p, 0, SEEK_END);
        int tam = ftell(p);

        fclose(p);

        if (tam == 0) {
            // Si el archivo está vacío
            return 0;
        }

        return tam / sizeof(TipodeDeporte);
    }

    int getID(){return IDTipo;}
    const char *getNombre (){return nombre;}
    int getNiveldeDificultad (){return nivelDificultad;}
    bool getEstado (){return estado;}

};

int TipodeDeporte::contTiposDeporte = 0;

void TipodeDeporte::Cargar(){

    if (IDTipo<22) IDTipo = contarRegistrosTiposdeDeporte()+1;
    else cout << "Supero el limite.";

    cout <<"NOMBRE: ";
    cargarCadena(nombre, 29);
    cout <<"Nivel de dificultad (entre 1 y 8) : ";
    cin >> nivelDificultad;
    setNivelDificultad(nivelDificultad);

}

void TipodeDeporte::Mostrar(){

    cout << "ID: ";
    cout << IDTipo << endl;
    cout <<"NOMBRE: ";
    cout << nombre << endl;
    cout << "NIVEL DE DIFICULTAD: ";
    cout << nivelDificultad << endl;


}

///  ----------------------------------------------------  CLASS DEPORTE  ----------------------------------------------------  ///


class Deporte {

    private:
        int ID;
        char nombre [30];
        int tipo;
        int anio;
        bool estado = true;
        static int contArchivos;

    public:
        Deporte ( int id=0, const char *n="Ninguno", int t=0, int a=1800, bool e=true){
             ID=id;
             strcpy(nombre, n);
             tipo=t;
             anio=a;
             estado=e;
        }

    void Cargar();
    void Mostrar();
    void setID(int id){ID=id;}
    void setNombre (const char *n){ strcpy(nombre,n);}
    void setTipo (int t){

        if(tipo>=1 && tipo<=21) tipo=t;
        else {
            cout << "Tipo incorrecto." << endl;
            cout << "Ingrese nuevamente: " << endl;
            cin >> tipo;
            setTipo(tipo);
        }

    }
    void setAnio (int a){
        time_t tiempo = time(nullptr);
        tm *fecha = localtime(&tiempo);
        int year;
        year=fecha->tm_year+1900;           //validacion para que sea un año igual o anterior al actual.

        if(a>=1800 && a<=year) anio=a;
        else {
            cout << "ANIO INCORRECTO. INGRESE NUEVAMENTE ! :";
            cin>>anio;
            setAnio(anio);
        }
    }

    void setEstado (bool e){estado=e;}

    int contarRegistrosDeporte() {
        FILE* p = fopen("Deportes.dat", "rb");

        if (p==NULL) {
            // Si no se pudo abrir el archivo
            if (contArchivos > 0) {
                cout << "Error de archivo." << endl;
                return -2;
            } else {
                // Si es la primera vez y el archivo está vacío
                return 0;
            }
        }

        fseek(p, 0, SEEK_END);
        int tam = ftell(p);

        fclose(p);

        if (tam == 0) {
            // Si el archivo está vacío
            return 0;
        }

        return tam / sizeof(Deporte);
    }

    int getID(){return ID;}
    const char *getNombre (){return nombre;}
    int getTipo(){return tipo;}
    int getAnio (){return anio;}
    bool getEstado (){return estado;}

};

int Deporte::contArchivos = 0;

void Deporte::Cargar(){

    ID = contarRegistrosDeporte()+1;

    cout <<"NOMBRE: ";
    cargarCadena(nombre, 29);
    cout <<"TIPO (entre 1 y 21) : ";
    cin >> tipo;
    setTipo(tipo);
    cout << "ANIO (entre 1800 y el anio acutal) : ";
    cin >> anio;
    setAnio(anio);

}

void Deporte::Mostrar(){

    cout << "ID: ";
    cout << ID << endl;
    cout <<"NOMBRE: ";
    cout << nombre << endl;
    cout <<"TIPO: ";
    cout << tipo << endl;
    cout << "ANIO: ";
    cout << anio << endl;


}

///  ----------------------------------------------------  CLASS ARCHIVO DEPORTE  ----------------------------------------------------  ///

class archivoDeporte{

    private:
        char nombre [30];
    public:
        archivoDeporte (const char *n){
            strcpy(nombre,n);
        }
        const char *getNombre (){return nombre;}

        bool listarRegistros();
        bool buscarDeporte(int);

        bool agregaRegistro(Deporte reg){
             FILE *p=fopen(nombre, "ab");
            if(p==NULL){
                cout << "Error de archivo."<<endl;
                fclose(p);
                return false;
            }
            bool escribio = fwrite(&reg,sizeof reg,1, p );
            fclose(p);
            return escribio;
        }


};

bool buscarDeporte(int nroDeporte){

        Deporte reg;
        FILE *p;
        p=fopen("Deportes.dat", "rb");
        if (p==NULL){
            cout << "Error de archivo.";
            return false;
        }

        while (fread(&reg, sizeof reg, 1, p)==1){

            if (reg.getTipo()==nroDeporte){
                fclose(p);
                return true;
            }
        }
        fclose(p);
        return false;
}

bool archivoDeporte::listarRegistros(){

        Deporte reg;
        FILE *p=fopen(nombre, "rb");
        if(p==NULL){
            cout << "Error de archivo."<<endl;
            return false;
        }
        while (fread(&reg,sizeof reg,1, p )==1){
            if(reg.getEstado()==true){
            reg.Mostrar();
            cout << endl;
            }

        }
        fclose(p);
        return true;
}

///  ----------------------------------------------------  CLASS ARCHIVO TIPO DE DEPORTE  ----------------------------------------------------  ///
class archivoTipodeDeporte{

    private:
        char nombre [30];
    public:
        archivoTipodeDeporte (const char *n){
            strcpy(nombre,n);
        }

    const char *getNombre (){return nombre;}
    bool listarRegistros();
    bool buscarPorIDTipo(int);

    bool agregaRegistro(TipodeDeporte reg){
         FILE *p=fopen(nombre, "ab");
        if(p==NULL){
            cout << "Error de archivo."<<endl;
            fclose(p);
            return false;
        }
        bool escribio = fwrite(&reg,sizeof reg,1, p );
        fclose(p);
        return escribio;
    }


};

bool archivoTipodeDeporte::buscarPorIDTipo(int id){

        TipodeDeporte reg;
        FILE *p;
        p=fopen("TipodeDeporte.dat", "rb");
        if (p==NULL){
            cout << "Error de archivo.";
            return false;
        }

        while (fread(&reg, sizeof reg, 1, p)==1){

            if (reg.getID()==id){
                fclose(p);
                return true;
            }
        }
        fclose(p);
        return false;
}

//haciendo
bool archivoTipodeDeporte::listarRegistros(){

        TipodeDeporte reg;
        FILE *p=fopen(nombre, "rb");
        if(p==NULL){
            cout << "Error de archivo."<<endl;
            return false;
        }
        while (fread(&reg,sizeof reg,1, p )==1){
            if(reg.getEstado()==true){
            reg.Mostrar();
            cout << endl;
            }

        }
        fclose(p);
        return true;
}

///  ----------------------------------------------------  CLASS FECHA  ----------------------------------------------------  ///
class Fecha{

    private:
        int dia, mes, anio;

    public:

        Fecha (int d=0, int m=0, int a=0){
            dia=d;
            mes=m;
            anio=a;
        }

        void Cargar(){

            cout<<"DIA: ";
            cin>>dia;
            setDia(dia);
            cout<<"MES: ";
            cin>>mes;
            setMes(mes);
            cout<<"ANIO: ";
            cin>>anio;
            setAnio(anio);

        }
        void CargarJugador(){

            cout<<"ANIO: ";
            cin>>anio;
            setAnioJugador(anio);

            cout<<"DIA: ";
            cin>>dia;
            setDiaJugador(dia);
            cout<<"MES: ";
            cin>>mes;
            setMesJugador(mes);

        }

        void obtenerFechaActual(){

            time_t tiempo = time(nullptr);
            tm *fecha = localtime(&tiempo);

            cout << "Time: " << tiempo << endl;
            cout << "ANIO: " << fecha->tm_year+1900 << endl;
            cout << "MES: " << fecha ->tm_mon+1 << endl;
            cout << "DIA: " << fecha ->tm_mday << endl;

            cout << "------------------------------------" << endl;

        }

        void Mostrar(){
            cout<<"DIA: "<<dia<<endl;
            cout<<"MES: "<<mes<<endl;
            cout<<"ANIO: "<<anio<<endl;
        }

        void mostrarEnLinea(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }

        void setDiaJugador(int d){

            if(d>=1 && d<=31) dia=d;
            else {
                cout << "DIA INCORRECTO. INGRESE NUEVAMENTE ! :";
                cin>>d;
                setDiaJugador(d);
            }

        }
        void setMesJugador(int m){

            if(m>=1 && m<=12) mes=m;
            else {
                cout << "MES INCORRECTO. INGRESE NUEVAMENTE ! :";
                cin>>m;
                setMesJugador(m);
            }

        }
        void setAnioJugador(int a){
           time_t tiempo = time(nullptr);
            tm *fecha = localtime(&tiempo);
            int year;
            year=fecha->tm_year+1900;           //validacion para que sea un año igual o anterior al actual.

            if(a>=1900 && a<=year) anio=a;
            else {
                cout << "ANIO INCORRECTO. INGRESE NUEVAMENTE ! :";
                cin>>a;
                setAnioJugador (a);
            }

        }
        void setDia(int d){

            if(d>=1 && d<=31) dia=d;
            else {
                cout << "DIA INCORRECTO. INGRESE NUEVAMENTE ! :";
                cin>>d;
                setDia(d);
            }
        }

        void setMes (int m){

            if(m>=1 && m<=12) mes=m;
            else {
                cout << "MES INCORRECTO. INGRESE NUEVAMENTE ! :";
                cin>>m;
                setMes(m);
            }
        }

         void setAnio (int a){

            time_t tiempo = time(nullptr);
            tm *fecha = localtime(&tiempo);
            int year;
            year=fecha->tm_year+1900;

            if(a>=1900 && a<=year) anio=a;
            else {
                cout << "ANIO INCORRECTO. INGRESE NUEVAMENTE ! :";
                cin>>a;
                setAnio (a);
            }
        }

        int getDia(){return dia;}
        int getMes (){return mes;}
        int getAnio (){return anio;}
};

///  ----------------------------------------------------  CLASS PERSONA  ----------------------------------------------------  ///

class Persona{

    protected:

     int DNI;
     char nombre [30];
     char apellido [30];
     char email [30];
     char telefono [30];
     Fecha fechaNacimiento;

    public:

        Persona (int dni=0, const char *n="Nadie", const char *a="Ninguno", const char *e="No tiene", const char *t="0000"){ ///Constructor
            DNI=dni;
            strcpy(nombre, n);
            strcpy(apellido, a);
            strcpy(email, e);
            strcpy(telefono, t);

        }

      void Cargar(int);
      void Mostrar();
      ///sets()
      void setDNI (int d){DNI=d;}
      void setNombre(const char *n){strcpy(nombre, n);}
      void setApellido (const char *a){strcpy (apellido, a);}
      void setEmail (const char *e){ strcpy(email, e);}
      void setTelefono (const char *t){ strcpy(telefono, t);}
      ///gets()
      int getDni (){return DNI;}
      const char *getNombre (){return nombre;}
      const char *getApellido (){return apellido;}
      const char *getEmail (){return email;}
      const char *getTelefono (){ return telefono;}

      void cambiarDNI(int d){
        DNI=d;
        setDNI(d);
    }

};

void Persona::Cargar (int d=-1){

    if(d==-1){
        cout << "DNI: ";
        cin >> DNI;
    }
    else {
        DNI=d;
    }
    cout <<"NOMBRE: ";
    cargarCadena(nombre, 29);
    cout <<"APELLIDO: ";
    cargarCadena(apellido, 29);
    cout << "EMAIL: ";
    cargarCadena(email, 29);
    cout << "TELEFONO: ";
    cargarCadena(telefono, 29);
    cout << "FECHA DE NACIMIENTO: " << endl;
    fechaNacimiento.Cargar();
}


void Persona::Mostrar(){

    cout << "DNI: ";
    cout << DNI << endl;
    cout << "NOMBRE: ";
    cout << nombre << endl;
    cout << "APELLIDO: ";
    cout << apellido << endl;
    cout << "EMAIL: ";
    cout << email << endl;
    cout << "TELEFONO: ";
    cout << telefono << endl;
    cout << "FECHA DE NACIMIENTO: ";
    fechaNacimiento.mostrarEnLinea();

}

///  ----------------------------------------------------  CLASS JUGADORES  ----------------------------------------------------  ///

class Jugadores:public Persona {

    private:

     int claustro ;
     int deporte;
     int nroEquipo;
     Fecha fechaInscripcion;
     float matricula;
     bool estado;

    public:

        Jugadores (int c=0, int de=1, int nro=0, float m=0, bool e=true){

            claustro=c;
            deporte=de;
            nroEquipo=nro;
            matricula=m;
            estado = e;
        }

    bool Cargar(int);
    void Mostrar();

    void setClaustro (int c){
        if(c>0 && c<5) claustro=c;
        else {
        cout << "Numero de claustro incorrecto. (1: docente; 2 alumno; 3 no docente; 4 graduado). "<< endl;
        cout << "INGRESE NUEVAMENTE : ";
        cin >> c;
        setClaustro (c);

        }
    }

    void setDeporte (int de){
        if (de>0 && de<11) deporte=de;
        else {
        cout << "Numero de deporte incorrecto. (numero entre 1 y 10)." << endl;
        cout << "INGRESE NUEVAMENTE : ";
        cin >> de;
        setDeporte (de);
        }
    }

    void setNroEquipo (int nro){nroEquipo=nro;}
    void setMatricula (float m){
        if(m>=0)matricula=m;
        else {
        cout << "Matricula incorrecta. Debe ser mayor a cero. " << endl;
        cout << "INGRESE NUEVAMENTE : $";
        cin >> m;
        setMatricula(m);
        }

    }
    void setEstado (bool e){ estado=e;}
    void setFechaInscripcion (int d, int m, int a){
            fechaInscripcion.setDia(d);
            fechaInscripcion.setMes(m);
            fechaInscripcion.setAnio(a);
    }

    int getClaustro (){ return claustro;}
    int getDeporte (){ return deporte;}
    int getNroEquipo (){ return nroEquipo;}
    float getMatricula (){ return matricula;}
    bool getEstado (){ return estado;}


};

bool Jugadores::Cargar (int d=-1){

        int dni=d;

        cout << "ID DEPORTE (numero entre 1 y 10) : ";
        cin >> deporte;

        if(buscarDeporte(deporte)==true){

        Persona::Cargar(dni);
        cout << "CLAUSTRO (1: docente; 2 alumno; 3 no docente; 4 graduado): ";
        cin >> claustro;
        setClaustro(claustro);
        //aca seteamos el nro de deporte ingrersado antes de la validacion.
        setDeporte (deporte);
        cout << "NUMERO DE EQUIPO: ";
        cin >> nroEquipo;
        setNroEquipo(nroEquipo);
        cout << "FECHA DE INSCRIPCION: ";
        cout << endl;
        fechaInscripcion.CargarJugador();
        cout << "MATRICULA (para valores con decimales usar el punto ): $";
        cin >> matricula;
        setMatricula (matricula);
        estado=true;
        return true;
        }else {
            cout << "No hay registros con ese numero de deporte." << endl;
            return false;
    }
}

void Jugadores::Mostrar (){

    if(estado==true){
    Persona::Mostrar();
    cout << "CLAUSTRO: ";
    cout <<  claustro << endl;
    cout << "ID DEPORTE: ";
    cout << deporte << endl;
    cout << "NUMERO DE EQUIPO: ";
    cout << nroEquipo << endl;
    cout << "FECHA DE INSCRIPCION   : ";
    fechaInscripcion.mostrarEnLinea();
    cout << "MATRICULA: $";
    cout << matricula << endl;
    }
}

///  ----------------------------------------------------  CLASS ARCHIVO JUGADORES  ----------------------------------------------------  ///

class ArchivoJugadores{

    private:
        char nombre[30];
    public:
        ArchivoJugadores(const char *n){
            strcpy(nombre,n);
        }

    bool listarRegistrosJ();
    bool grabarRegistroJ(Jugadores);
    Jugadores leerRegistroJ(int pos);
    bool sobreEscribirRegistroJ(Jugadores reg, int pos);
    int contarRegistrosActivosJ();
    int contarRegistrosJ();
};

bool ArchivoJugadores::listarRegistrosJ(){

    Jugadores reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return false;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
}

bool ArchivoJugadores::grabarRegistroJ(Jugadores reg){

    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

Jugadores ArchivoJugadores::leerRegistroJ(int pos){

    Jugadores reg;
    reg.setEstado(false);
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return reg;
    }
    fseek(p,sizeof reg*pos,0);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    return reg;
}

bool ArchivoJugadores::sobreEscribirRegistroJ(Jugadores reg, int pos){

    FILE *p;
    p=fopen(nombre, "rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

int ArchivoJugadores::contarRegistrosJ(){

    int cantReg=0;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    cantReg=cantBytes/sizeof(Jugadores);
    return cantReg;
}

int ArchivoJugadores::contarRegistrosActivosJ(){

    Jugadores reg;
    int cuentaReg=0;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return -1;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getEstado()) cuentaReg++;
    }
    fclose(p);
    return cuentaReg;
}

///  ----------------------------------------------------  PUNTO A  ----------------------------------------------------  ///
/* se puede sacar. Era solo para el parcial.
void puntoA(){

    int deporte, cantJugadores=0;
    ArchivoJugadores archi("jugadores.dat");
    Jugadores reg;

    cout<<"INGRESE UN NUMERO DE DEPORTE ";
    cin>>deporte;
    int cantReg=archi.contarRegistrosJ();
    for(int i=0;i<cantReg;i++){
        reg=archi.leerRegistroJ(i);
        if(reg.getDeporte()==deporte){
            cantJugadores++;
        }
    }
    cout<<"CANTIDAD DE JUGADORES "<<cantJugadores<<endl;
  }
*/
///  ----------------------------------------------------  CLASS ARCHIVO EQUIPOS  ----------------------------------------------------  ///

class ArchivoEquipos{

    private :
        char nombre[30] ;
    public :
        ArchivoEquipos(const char *n){
        strcpy(nombre,n);
        }
 const char *getNombre (){return nombre;}

    bool agregarEquipos(ArchivoEquipos);
    bool listarEquiposPorId ();
    bool listarTodos ();
    bool modificarRegistroEquipo (Equipos,int);
    bool eliminarRegistroEquipo();

    int BuscarPorID(int);
    Equipos leerRegistro(int);

};

/*
bool ArchivoEquipos::agregarEquipos(ArchivoEquipos reg){

    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

Equipos ArchivoEquipos::leerRegistro (int pos){

        Equipos reg ;
        FILE *p;
        reg.setID(-1);
        p=fopen("equipos.dat", "rb");
        if (p==NULL){
            cout << "Error de archivo.";
            return reg; //Aca reg tiene dni -1
        }
        fseek(p, sizeof reg*pos, 0);
        int leyo=fread(&reg, sizeof(Equipos), 1, p);

        fclose(p);
        if(leyo==0) reg.setID(-1);
        return reg; //si devuelve reg dni-1 es que no encontro un registro.
}

bool ArchivoEquipos::listarEquiposPorId (){

        int id;
        Equipos reg;
        int aux=0;
        FILE *p;

        bool Estado = false;
        cout << "Ingrese el ID del deporte: ";
        cin >> id;

        p=fopen("equipos.dat", "rb");
        if (p==NULL){
            cout << "Error de archivo.";
            return false;
        }

        while (fread(&reg, sizeof(Equipos), 1, p)==1){
            if(reg.getEstado()==false){
                aux++;
            }else if (reg.getEstado()==true){
            if(reg.getID()==id){
                cout << "------------------------------------" << endl;
                reg.Mostrar();
                Estado = true;
                cout << endl;
            }
          }
        }
        fclose(p);
        if(Estado==false && aux > 0) cout << "El Equipo fue dado de baja." << endl;
        else if(Estado==false && aux ==0) cout << "No hay registros con ese ID." << endl;
        return true;
}

bool ArchivoEquipos:: listarTodos (){

        Equipos reg;
        FILE *p;

        p=fopen("equipos.dat", "rb");
        if (p==NULL){
            cout << "Error de archivo.";
            return false;
        }

        while (fread(&reg, sizeof(Equipos), 1, p)==1){
            cout << "------------------------------------" << endl;
            reg.Mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
}

bool ArchivoEquipos::modificarRegistroEquipo (Equipos reg, int pos){

    int id;
    cout << "Ingrese el ID del Equipo para modificar el Nombre: ";
    cin >> id;
     pos = BuscarPorID(id);
    if (pos==-1){
        cout << "No existe un registro con ese ID" << endl;
        return false;
    }
    reg=leerRegistro (pos);
    char nuevoNombre[30];
      // Solicitar el nuevo nombre
    cout << "Ingrese el nuevo Nombre:" << endl;
    cin >> nuevoNombre;

    reg.setNombre(nuevoNombre);


    // Modificar el registro en el archivo
    bool exito = modificarRegistroEquipo(reg, pos);

    return exito;


}

int ArchivoEquipos:: BuscarPorID (int id){

       Equipos reg;
       FILE *p;
        p=fopen("equipos.dat", "rb");
        if (p==NULL){
            cout << "Error de archivo.";
            return -2; //si es -2 es que hubo un error.
        }
        int cuentaRegistros=0;
        while (fread(&reg, sizeof (Equipos), 1, p)==1){

            if (reg.getID()==id){
                fclose(p); //siempre cierro el archivo.
                return cuentaRegistros; //devuelvo porque encontro
            }
            cuentaRegistros++;
        }
        fclose(p);
        return -1; //si devuelve -1 es que no encontro un registro.
}

bool ArchivoEquipos::eliminarRegistroEquipo(){

    int id;
    cout << "Ingresar el ID del Equipo a dar de baja: ";
    cin >> id;
    int pos = BuscarPorID(id);
    if (pos == -1) {
        cout << "No existe un registro con ese ID" << endl;
        return false;
    }

    FILE *p = fopen("equipos.dat", "rb+");
    if (p == NULL) {
        cout << "Error de archivo." << endl;
        return false;
    }

    Equipos reg;
    fseek(p, pos * sizeof(Equipos), 0);
    fread(&reg, sizeof(Equipos), 1, p);
    reg.setEstado(false);

    fseek(p, pos * sizeof(Equipos), 0);
    bool escribio = fwrite(&reg, sizeof(Equipos), 1, p);

    fclose(p);
    return escribio;
}

*/
#endif // CLASES_H_INCLUDED
