#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "Prototipos.h"

///  ----------------------------------------------------  CARGAR CADENA  ----------------------------------------------------  ///

void cargarCadena(char *palabra, int tam){

    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
    palabra[i] = cin.get();
    if(palabra[i] == '\n') break;
}
    palabra[i] = '\0';
    fflush(stdin);
}

///  ----------------------------------------------------  RESTAURAR DATOS DE INICIO  ----------------------------------------------------  ///

bool restaurarDatosInicioDeporte(){

    Deporte reg ;
    FILE *p =fopen("DeportesINICIO.bak","rb");
    if(p==NULL){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        fclose(p);
        return false ;
    }

    FILE *pcopia = fopen("Deportes.dat" ,"wb") ;
    if(pcopia==NULL){
         cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
         fclose(pcopia);
        return false ;
    }

    while(fread(&reg,sizeof reg,1,p)==1){
       fwrite(&reg,sizeof reg,1,pcopia) ;
    }
    fclose(p);
    fclose(pcopia);
    cout<<"RESTAURACION DEPORTES INICIO EXITOSA. " <<endl ;
    return true ;

}

bool restaurarDatosInicioJugadores(){

    Deporte reg ;
    FILE *p =fopen("JugadoresINICIO.bak","rb");
    if(p==NULL){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        fclose(p);
        return false ;
    }

    FILE *pcopia = fopen("Jugadores.dat" ,"wb") ;
    if(pcopia==NULL){
         cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
         fclose(pcopia);
        return false ;
    }

    while(fread(&reg,sizeof reg,1,p)==1){
       fwrite(&reg,sizeof reg,1,pcopia) ;
    }
    fclose(p);
    fclose(pcopia);
    cout<<"RESTAURACION JUGADORES INICIO EXITOSA. " <<endl ;
    return true ;

}

bool restaurarDatosInicio (){

    if(restaurarDatosInicioDeporte()==true && restaurarDatosInicioJugadores()==true){
        return true;
    }else return false;

}

///  ----------------------------------------------------  FUNCIONES PARA EQUIPOS  ----------------------------------------------------  ///

bool agregarEquipos(){

    Equipos reg;
    FILE *p;
    p=fopen("equipos.dat","ab");
    reg.Cargar();
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

Equipos leerRegistroEquipo (int pos){

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

bool listarEquiposPorId (){

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

bool listarTodosEquipo (){ //ListarTodosEquipo

        Equipos reg;
        FILE *p;

        p=fopen("equipos.dat", "rb");
        if (p==NULL){
            cout << "Error de archivo.";
            return false;
        }

        while (fread(&reg, sizeof(Equipos), 1, p)==1){
            cout << endl;
            if (reg.getEstado()==true) reg.Mostrar();
            cout << endl;
            cout << "------------------------------------" << endl;
        }
        fclose(p);
        return true;
}

int BuscarEquiposPorID (int id){ ///BsucarPorId() buscarla

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

void escribirRegistroEquipo(Equipos reg, int pos) {

    FILE* p;
    p = fopen("equipos.dat", "rb+");
    if (p == NULL) {
        cout << "Error de archivo." << endl;
        return;
    }
    fseek(p, sizeof(Equipos) * pos, 0);
    fwrite(&reg, sizeof(Equipos), 1, p);
    fclose(p);
}

bool modificarRegistroEquipo (){

    int id;

    cout << "Ingrese el ID del Equipo para modificar el Nombre: ";
    cin >> id;
    int pos = BuscarEquiposPorID(id);
    if (pos==-1){

        cout << "No existe un registro con ese ID" << endl;

        }else{

            Equipos reg;
            reg=leerRegistroEquipo (pos);
            char nuevoNombre[30];
            // Solicitar el nuevo nombre
            cout << "Ingrese el nuevo Nombre:" << endl;
            cin >> nuevoNombre;

            reg.setNombre(nuevoNombre);
            escribirRegistroEquipo(reg, pos);

            return true ;
    }
}

bool eliminarRegistroEquipo(){

    int id;
    cout << "Ingresar el ID del Equipo a dar de baja: ";
    cin >> id;
    int pos = BuscarEquiposPorID(id);

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

///  ----------------------------------------------------  FUNCIONES PARA TIPOS DE DEPORTES  ----------------------------------------------------  ///

bool agregarTipoDeporte(){

        TipodeDeporte reg;
        archivoTipodeDeporte archi("TipodeDeporte.dat");
        reg.Cargar();

        if (archi.agregaRegistro(reg)==true){

            return true;

        }else {
            cout << "No se pudo agregar." << endl;
    }

    return false;
}

bool listarTipoPorID(){

        TipodeDeporte reg;
        int aux=0; //para validar que el tuvo baja lógica.
        FILE *pTipoDeporte;
        int id;
        bool Estado = false;
        cout << "Ingrese el ID del Tipo de deporte: ";
        cin >> id;

        pTipoDeporte=fopen("TipodeDeporte.dat", "rb");
        if (pTipoDeporte==NULL){
            cout << "Error de archivo.";
            return false;
        }

        while (fread(&reg, sizeof(TipodeDeporte), 1, pTipoDeporte)==1){
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
        fclose(pTipoDeporte);
        if(Estado==false && aux>0) cout << "El deporte fue dado de baja." << endl;
        else if(Estado==false && aux==0) cout << "No hay registros con ese ID." << endl;
        return true;
}

bool listarTodosTipos(){

        TipodeDeporte reg;
        FILE *p;

        p=fopen("TipodeDeporte.dat", "rb");
        if (p==NULL){
            cout << "Error de archivo.";
            return false;
        }

        while (fread(&reg, sizeof(TipodeDeporte), 1, p)==1){
            cout << endl;
            if (reg.getEstado()==true) reg.Mostrar();
            cout << endl;
            cout << "------------------------------------" << endl;
        }
        fclose(p);
        return true;
}

bool modificarRegistroTipodeDeporte (TipodeDeporte reg, int pos){

        FILE *p;
        p=fopen("TipodeDeporte.dat", "rb+");
        if(p==NULL){
            cout << "Error de archivo.";
            fclose(p);
            return false;
        }
        fseek(p, sizeof reg*pos, 0);
        bool escribio = fwrite(&reg, sizeof(TipodeDeporte), 1, p);
        fclose(p);
        return escribio;
}

bool modificarNivelDificultad(){

    int id, nuevaDificultad;
    cout << "Ingrese ID del tipo de Deporte para modificar la dificultad: ";
    cin >> id;
    int pos = buscarPorIDTipo(id);
    if (pos==-1){
        cout << "No existe un registro con ese DNI" << endl;
        return false;
    }
    TipodeDeporte reg;
    reg=leeRegistroTipo(pos);


    cout << "Ingrese la nueva dificultad:" << endl;
    cin >> nuevaDificultad;

    reg.setNivelDificultad(nuevaDificultad);

    bool exito = modificarRegistroTipodeDeporte(reg, pos);

    return exito;

}

int buscarPorIDTipo (int id){

        TipodeDeporte reg;
        FILE *p;
        p=fopen("TipodeDeporte.dat", "rb");
        if (p==NULL){
            cout << "Error de archivo.";
            return -2; //si es -2 es que hubo un error.
        }
        int cuentaRegistros=0;
        while (fread(&reg, sizeof(TipodeDeporte), 1, p)==1){

            if (reg.getID()==id){
                fclose(p); //siempre cierro el archivo.
                return cuentaRegistros; //devuelvo porque encontro
            }
            cuentaRegistros++;
        }
        fclose(p);
        return -1; //si devuelve -1 es que no encontro un registro.
}

TipodeDeporte leeRegistroTipo (int pos){

        TipodeDeporte reg;
        FILE *p;
        reg.setIDTipo(-1);

        p=fopen("TipodeDeporte.dat", "rb");
        if (p==NULL){
            cout << "Error de archivo.";
            return reg; //Aca reg tiene ID -1
        }

        fseek(p, sizeof reg*pos, 0);
        int leyo=fread(&reg, sizeof(TipodeDeporte), 1, p);

        fclose(p);
        if(leyo==0) reg.setIDTipo(-1); //Acá no leyó el registro
        return reg; //si devuelve reg ID-1 es que no encontro un registro.
}



bool bajaLogicaTipo(){

    int id;
    cout << "Ingresar el ID del tipo de deporte a dar de baja.";
    cin >> id;
    int pos = buscarPorIDTipo(id);
    if (pos==-1){
        cout << "No existe un registro con ese ID" << endl;
        return false;
    }
    TipodeDeporte reg;
    reg=leeRegistroTipo(pos); // hacer leerRegistro
    reg.setEstado(false);
    bool quePaso= modificarRegistroTipodeDeporte(reg, pos);//hacer modificarRegistroTipodeDeporte(reg, pos)
    return quePaso;

}

///  ----------------------------------------------------  FUNCIONES PARA ARCHIVO DEPORTES  ----------------------------------------------------  ///

bool agregarDeporte(){

        Deporte reg;
        archivoDeporte archi("Deportes.dat");
        reg.Cargar();

        if (archi.agregaRegistro(reg)==true){

            return true;
        }else {
            cout << "No se pudo agregar." << endl;
        }

        return false;
}

void mostrarDeportes (){

        archivoDeporte archi("Deportes.dat");
        archi.listarRegistros();

}

bool listarDeportePorId (){

        Deporte reg;
        int aux=0; //para validar que el tuvo baja lógica.
        FILE *pDeporte;
        int id;
        bool Estado = false;
        cout << "Ingrese el ID del deporte: ";
        cin >> id;

        pDeporte=fopen("Deportes.dat", "rb");
        if (pDeporte==NULL){
            cout << "Error de archivo.";
            return false;
        }

        while (fread(&reg, sizeof(Deporte), 1, pDeporte)==1){
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
        fclose(pDeporte);
        if(Estado==false && aux>0) cout << "El deporte fue dado de baja." << endl;
        else if(Estado==false && aux==0) cout << "No hay registros con ese ID." << endl;
        return true;
}

Deporte leeRegistro (int pos){

        Deporte reg;
        FILE *p;
        reg.setID(-1);
        p=fopen("Deportes.dat", "rb");
        if (p==NULL){
            cout << "Error de archivo.";
            return reg; //Aca reg tiene ID -1
        }
        fseek(p, sizeof reg*pos, 0);
        int leyo=fread(&reg, sizeof(Deporte), 1, p);

        fclose(p);
        if(leyo==0) reg.setID(-1); //Acá no leyó el registro
        return reg; //si devuelve reg ID-1 es que no encontro un registro.
}

bool modificarAnioDeOrigen(){

    int id;
    cout << "Ingrese el ID del deporte para modificar el anio: ";
    cin >> id;
    int pos = buscarPorID(id);
    if (pos==-1){
        cout << "No existe un registro con ese ID" << endl;
        return false;
    }
    Deporte reg;
    reg=leeRegistro (pos);
    int nuevoAnio;
      // Solicitar la nueva fecha de inscripción
    cout << "Ingrese el nuevo anio:" << endl;
    cin >> nuevoAnio;

    reg.setAnio(nuevoAnio);


    // Modificar el registro en el archivo
    bool exito = modificarRegistroDeporte(reg, pos);

    return exito;

}

int buscarPorID (int id){

       Deporte reg;
       FILE *p;
        p=fopen("Deportes.dat", "rb");
        if (p==NULL){
            cout << "Error de archivo.";
            return -2; //si es -2 es que hubo un error.
        }
        int cuentaRegistros=0;
        while (fread(&reg, sizeof reg, 1, p)==1){

            if (reg.getID()==id){
                fclose(p); //siempre cierro el archivo.
                return cuentaRegistros; //devuelvo porque encontro
            }
            cuentaRegistros++;
        }
        fclose(p);
        return -1; //si devuelve -1 es que no encontro un registro.
}

bool eliminarRegistroDeporte(){

    int id;
    cout << "Ingresar el ID del deporte a dar de baja.";
    cin >> id;
    int pos = buscarPorID(id);
    if (pos==-1){
        cout << "No existe un registro con ese ID" << endl;
        return false;
    }
    Deporte reg;
    reg=leeRegistro(pos);
    reg.setEstado(false);
    bool quePaso= modificarRegistroDeporte(reg, pos);
    return quePaso;

}

bool modificarRegistroDeporte (Deporte reg, int pos){

        FILE *p;
        p=fopen("Deportes.dat", "rb+");
        if(p==NULL){
            cout << "Error de archivo.";
            return false;
        }
        fseek(p, sizeof reg*pos, 0);
        bool escribio = fwrite(&reg, sizeof(Deporte), 1, p);
        fclose(p);
        return escribio;
}

bool copiaSeguridadDeportes(){

    Deporte reg ;
    FILE *p =fopen("Deportes.dat","rb");
    if(p==NULL){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
         fclose(p);
        return false ;
    }

    FILE *pcopia = fopen("Deportes.bak" ,"wb") ;
    if(pcopia==NULL){
         cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        fclose(pcopia);
        return false ;
    }

    while(fread(&reg,sizeof reg,1,p)==1){
       fwrite(&reg,sizeof reg,1,pcopia) ;
    }

    fclose(p);
    fclose(pcopia);
    cout<<"COPIA DE SEGURIDAD CREADA. " <<endl ;
    return true ;
}

bool restaurarArchDeportes(){

    Deporte reg ;
    FILE *p =fopen("Deportes.bak","rb");
    if(p==NULL){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        fclose(p);
        return false ;
    }

    FILE *pcopia = fopen("Deportes.dat" ,"wb") ;
    if(pcopia==NULL){
         cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
         fclose(pcopia);
        return false ;
    }

    while(fread(&reg,sizeof reg,1,p)==1){
       fwrite(&reg,sizeof reg,1,pcopia) ;
    }

    fclose(p);
    fclose(pcopia);
    cout<<"COPIA DE SEGURIDAD CREADA. " <<endl ;
    return true ;

}

///  ----------------------------------------------------  FUNCIONES PARA ARCHIVO JUGADORES  ----------------------------------------------------  ///

bool agregarJugador(){

    Jugadores reg;
    FILE *pJugador;

    pJugador=fopen("Jugadores.dat", "ab");
        if (pJugador==NULL){
            cout << "Error de archivo.";
            return false;
        }
       if(reg.Cargar()){
        int pos=buscarPorDni(reg.getDni());
        if(pos==-1){
            bool escribio = fwrite(&reg, sizeof(Jugadores), 1, pJugador);
        fclose(pJugador);
        return escribio;
        }
        fclose(pJugador);

    } else return false;
}

bool agregarJugadorValidado(){

    Jugadores reg;
    FILE *pJugador;

    pJugador=fopen("Jugadores.dat", "ab");
        if (pJugador==NULL){
            cout << "Error de archivo.";
            return false;
        }

        int dni;
        cout << "DNI: ";
        cin >> dni;
        int pos = buscarPorDni(dni);

        if(pos==-1){
       bool escribir = reg.Cargar(dni);
       if(escribir==true){
        bool escribio = fwrite(&reg, sizeof(Jugadores), 1, pJugador);
        fclose(pJugador);
        return escribio;
        }
    }else {
        fclose(pJugador);
        return false;
    }
}

bool listarTodos (){

        Jugadores reg;
        FILE *pJugador;

        pJugador=fopen("Jugadores.dat", "rb");
        if (pJugador==NULL){
            cout << "Error de archivo.";
            return false;
        }

        while (fread(&reg, sizeof(Jugadores), 1, pJugador)==1){
            cout << endl;
            reg.Mostrar();
            cout << endl;
            cout << "------------------------------------" << endl;
        }
        fclose(pJugador);
        return true;
}

bool listarPorDni (){

        Jugadores reg;
        FILE *pJugador;
        int dni;
        int aux=0;
        bool existe = false;
        cout << "Ingrese el dni del jugador: ";
        cin >> dni;

        pJugador=fopen("Jugadores.dat", "rb");
        if (pJugador==NULL){
            cout << "Error de archivo.";
            return false;
        }

        while (fread(&reg, sizeof(Jugadores), 1, pJugador)==1){
            if(reg.getEstado()==false){
                aux++;
            }else if (reg.getEstado()==true){
            if(reg.getDni()==dni){
                cout << endl;
                reg.Mostrar();
                cout << "------------------------------------" << endl;
                existe = true;
                cout << endl;
            }
          }
        }
        fclose(pJugador);
        if(existe==false && aux>0) cout << "El jugador fue dado de baja." << endl;
        else if(existe==false && aux==0)    cout << "No hay registros con ese DNI." << endl;
        return true;
}

bool modificarFechaInscripcion (){

    int dni;
    cout << "Ingrese el DNI del jugador para modificar la fecha de inscripcion: ";
    cin >> dni;
    int pos = buscarPorDni(dni);
    if (pos==-1){
        cout << "No existe un registro con ese DNI" << endl;
        return false;
    }
    Jugadores reg;
    reg=leerRegistro(pos);


    cout << "Ingrese la nueva fecha de inscripcion:" << endl;
    cout << "DIA: ";
    int nuevoDia;
    cin >> nuevoDia;
    cout << "MES: ";
    int nuevoMes;
    cin >> nuevoMes;
    cout << "ANIO: ";
    int nuevoAnio;
    cin >> nuevoAnio;

    reg.setFechaInscripcion(nuevoDia, nuevoMes, nuevoAnio);

    bool exito = modificarRegistro(reg, pos);

    return exito;

}

bool bajaLogica(){

    int dni;
    cout << "Ingresar el DNI del jugador a dar de baja.";
    cin >> dni;
    int pos = buscarPorDni(dni);
    if (pos==-1){
        cout << "No existe un registro con ese DNI" << endl;
        return false;
    }

    Jugadores reg;
    reg=leerRegistro(pos);
    reg.setEstado(false);
    bool quePaso= modificarRegistro(reg, pos);
    return quePaso;
}

bool buscarPorNombre (){

    char nombre [30];
    Jugadores reg;
    FILE *pJugador;
    bool existe =  false;

    pJugador=fopen("Jugadores.dat", "rb");
        if (pJugador==NULL){
            cout << "Error de archivo.";
            return false;
        }
        cout << "Ingrese el nombre: ";
        cargarCadena(nombre, 29);

        while (fread(&reg, sizeof(Jugadores), 1, pJugador)==1){

            if(strcmp(reg.getNombre(), nombre)==0){
                cout << "------------------------------------" << endl;
                reg.Mostrar();
                existe = true;
                cout << endl;
            }

        }
        fclose(pJugador);
        if(existe==false) cout << "No hay registros con ese nombre." << endl;
        return true;

}

int buscarPorDni (int dni){

        Jugadores reg;
        FILE *pJugador;
        pJugador=fopen("Jugadores.dat", "rb");
        if (pJugador==NULL){
            cout << "Error de archivo.";
            return -2; //si es -2 es que hubo un error.
        }
        int cuentaRegistros=0;
        while (fread(&reg, sizeof(Jugadores), 1, pJugador)==1){

            if (reg.getDni()==dni){
                fclose(pJugador); //siempre cierro el archivo.
                return cuentaRegistros; //devuelvo porque encontro
            }
            cuentaRegistros++;
        }
        fclose(pJugador);
        return -1; //si devuelve -1 es que no encontro un registro.
}

Jugadores leerRegistro (int pos){

        Jugadores reg;
        FILE *pJugador;
        reg.setDNI(-1);
        pJugador=fopen("Jugadores.dat", "rb");
        if (pJugador==NULL){
            cout << "Error de archivo.";
            return reg; //Aca reg tiene dni -1
        }
        fseek(pJugador, sizeof reg*pos, 0);
        int leyo=fread(&reg, sizeof(Jugadores), 1, pJugador);

        fclose(pJugador);
        if(leyo==0) reg.setDNI(-1);
        return reg; //si devuelve reg dni-1 es que no encontro un registro.

}

bool modificarRegistro (Jugadores reg, int pos){

        FILE *pJugador;
        pJugador=fopen("Jugadores.dat", "rb+");
        if(pJugador==NULL){
            cout << "Error de archivo.";
            fclose(pJugador);
            return false;
        }
        fseek(pJugador, sizeof reg*pos, 0);
        bool escribio = fwrite(&reg, sizeof(Jugadores), 1, pJugador);
        fclose(pJugador);
        return escribio;
}

bool copiaSeguridadJugadores(){

    Jugadores reg ;
    FILE *p =fopen("Jugadores.dat","rb");
    if(p==NULL){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        fclose(p);
        return false ;
    }

    FILE *pcopia = fopen("Jugadores.bak" ,"wb") ;
    if(pcopia==NULL){
         cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
         fclose(pcopia);
        return false ;
    }

    while(fread(&reg,sizeof reg,1,p)==1){
       fwrite(&reg,sizeof reg,1,pcopia) ;
    }
    fclose(p);
    fclose(pcopia);
    cout<<"COPIA DE SEGURIDAD CREADA. " <<endl ;
    return true ;
}

bool restaurarArchJugadores(){

    Jugadores reg ;
    FILE *p =fopen("Jugadores.bak","rb");
    if(p==NULL){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        fclose(p);
        return false ;
    }

    FILE *pcopia = fopen("Jugadores.dat" ,"wb" ) ;
    if(pcopia==NULL){
         cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
         fclose(pcopia);
        return false ;
    }

    while(fread(&reg,sizeof reg,1,p)==1){
       fwrite(&reg,sizeof reg,1,pcopia) ;
    }
    fclose(p);
    fclose(pcopia);
    cout<<"RESTAURACION CORRECTA. " <<endl ;
    return true ;

}

///  ----------------------------------------------------  SUBMENUES  ----------------------------------------------------  ///

void subMenuTiposDeDeporte(){

    int opc;
    TipodeDeporte obj;

    while(true){
    system ("cls");
    cout <<"       MENU TIPOS DE DEPORTE      "<< endl;
    cout <<"----------------------------------"<< endl;
    cout <<"1) AGREGAR TIPO                   "<< endl;
    cout <<"2) LISTAR TIPO POR ID             "<< endl;
    cout <<"3) LISTAR TODO                    "<< endl;
    cout <<"4) MODIFICAR NIVEL DE DIFICULTAD  "<< endl;
    cout <<"5) ELIMINAR REGISTRO              "<< endl;
    cout <<"----------------------------------"<< endl;
    cout <<"0) VOLVER AL MENU PRINCIPAL       "<< endl;

    cout << "Ingrese una opcion: ";
    cin >> opc;

    system("cls");

    switch(opc){

    case 1: if(agregarTipoDeporte()) cout <<"REGISTRO AGREGADO"<<endl;
            else cout <<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        break;
    case 2: if(!listarTipoPorID()) cout <<"ERROR AL LEER EL ARCHIVO."<<endl;
        break;
    case 3: if(!listarTodosTipos()) cout <<"ERROR AL LEER EL ARCHIVO."<<endl;
        break;
    case 4: if(modificarNivelDificultad()) cout <<"NIVEL MODIFICADO." << endl;
            else cout <<"ERROR AL MODIFICAR." << endl;
        break;
    case 5: if (bajaLogicaTipo()) cout << "Registro dado de baja."<<endl;
            else cout << "No se pudo dar de baja"<<endl;
        break;

    case 0: return ;
        break;

    }
    system("pause");
        }

}

void subMenuJugadores(){

    int opc;
    Jugadores obj;

    while(true){
    system ("cls");
    cout <<"       MENU JUGADORES             "<< endl;
    cout <<"----------------------------------"<< endl;
    cout <<"1) AGREGAR JUGADOR                "<< endl;
    cout <<"2) LISTAR JUGADOR POR DNI         "<< endl;
    cout <<"3) LISTAR TODOS LOS JUGADORES     "<< endl;
    cout <<"4) MODIFICAR FECHA DE INSCRIPCION "<< endl;
    cout <<"5) ELIMINAR REGISTRO DE JUGADOR   "<< endl;
    cout <<"----------------------------------"<< endl;
    cout <<"0) VOLVER AL MENU PRINCIPAL                         "<< endl;

    cout << "Ingrese una opcion: ";
    cin >> opc;

    system("cls");

    switch(opc){

    case 1: if(agregarJugador()) cout <<"REGISTRO AGREGADO"<<endl; //cambio para agrergar
            else cout <<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        break;
    case 2: if(!listarPorDni()) cout <<"ERROR AL LEER EL ARCHIVO."<<endl;
        break;
    case 3: if(!listarTodos()) cout <<"ERROR AL LEER EL ARCHIVO."<<endl;
        break;
    case 4: if(modificarFechaInscripcion()) cout <<"FECHA MODIFICADA." << endl;
            else cout <<"ERROR AL MODIFICAR." << endl;
        break;
    case 5: if (bajaLogica()) cout << "Registro dado de baja."<<endl;
            else cout << "No se pudo dar de baja"<<endl;
        break;

    case 0: return ;
        break;

    }
    system("pause");
        }

}

void subMenuDeportes(){

    int opc;
    Deporte obj;

    while(true){
    system ("cls");
    cout <<"       MENU DEPORTES              "<< endl;
    cout <<"----------------------------------"<< endl;
    cout <<"1) AGREGAR DEPORTE                "<< endl;
    cout <<"2) LISTAR DEPORTE POR ID          "<< endl;
    cout <<"3) LISTAR TODO                    "<< endl;
    cout <<"4) MODIFICAR ANIO DE ORIGEN       "<< endl;
    cout <<"5) ELIMINAR REGISTRO              "<< endl;
    cout <<"----------------------------------"<< endl;
    cout <<"0) VOLVER AL MENU PRINCIPAL       "<< endl;

    cout << "Ingrese una opcion: ";
    cin >> opc;

    system("cls");

    switch(opc){

    case 1: if(agregarDeporte()) cout <<"REGISTRO AGREGADO"<<endl;
            else cout <<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        break;

    case 2: listarDeportePorId();
        break;

    case 3: mostrarDeportes();
        break;

    case 4: if(modificarAnioDeOrigen()) cout <<"ANIO MODIFICADO." << endl;
            else cout <<"ERROR AL MODIFICAR." << endl;
        break;

    case 5: if (eliminarRegistroDeporte()) cout << "Registro dado de baja."<<endl;
            else cout << "No se pudo dar de baja"<<endl;
        break;

    case 0: return ;
        break;

    }
    system("pause");
        }

}

void subMenuEquipos(){

    int opc;
    Equipos obj;

    while(true){
    system ("cls");
    cout <<"       MENU EQUIPOS             "<< endl;
    cout <<"----------------------------------"<< endl;
    cout <<"1) AGREGAR EQUIPO                "<< endl;
    cout <<"2) LISTAR EQUIPO POR ID          "<< endl;
    cout <<"3) LISTAR TODO                    "<< endl;
    cout <<"4) MODIFICAR NOMBRE       "<< endl;
    cout <<"5) ELIMINAR REGISTRO              "<< endl;
    cout <<"----------------------------------"<< endl;
    cout <<"0) VOLVER AL MENU PRINCIPAL       "<< endl;

    cout << "Ingrese una opcion: ";
    cin >> opc;

    system("cls");

    switch(opc){

    case 1: if(agregarEquipos()) cout <<"REGISTRO AGREGADO"<<endl;
            else cout <<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        break;

    case 2: listarEquiposPorId();
        break;

    case 3: listarTodosEquipo();
        break;

    case 4: if(modificarRegistroEquipo()) cout <<"NOMBRE MODIFICADO." << endl;
            else cout <<"ERROR AL MODIFICAR." << endl;
        break;

    case 5: if (eliminarRegistroEquipo()==true) cout << "Registro dado de baja."<<endl;
            else cout << "No se pudo dar de baja"<<endl;
        break;

    case 0: return ;
        break;

    }
    system("pause");
        }

}

void subMenuConfiguracion(){

    int opc;

    while(true){
    system ("cls");

    cout <<"       MENU CONFIGURACION                       "<< endl;
    cout <<"------------------------------------------------"<< endl;
    cout <<"1)  COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES "<< endl;
    cout <<"2)  COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES  "<< endl;
    cout <<"3)  RESTAURAR EL ARCHIVO DE JUGADORES           "<< endl;
    cout <<"4)  RESTAURAR EL ARCHIVO DE DEPORTES            "<< endl;
    cout <<"5)  ESTABLECER DATOS DE INICIO                  " <<endl;
    cout <<"------------------------------------------------"<< endl;
    cout <<"0) VOLVER AL MENU PRINCIPAL                     "<< endl;

    cout << "Ingrese una opcion: ";
    cin >> opc;

    system("cls");

    switch(opc){

    case 1:copiaSeguridadJugadores();
        break;
    case 2:copiaSeguridadDeportes();
        break;
    case 3:restaurarArchJugadores();
        break;
    case 4:restaurarArchDeportes();
        break;
    case 5:if(restaurarDatosInicio()) cout << "Datos de inicio restaurados !" << endl;
            else cout << "No se pudo restaurar los datos de inicio!" << endl;
        break;
    case 0: return ;
        break;

        }

        system("pause");
    }
}



#endif // FUNCIONES_H_INCLUDED
