#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED


void subMenuReportes(){

    int opc;

        while(true){

        system ("cls");

            cout <<"       MENU REPORTES              "<< endl;
            cout <<"----------------------------------"<< endl;
            cout <<"1)                                "<< endl;
            cout <<"2)                                "<< endl;
            cout <<"3)                                "<< endl;
            cout <<"4)                                "<< endl;
            cout <<"----------------------------------"<< endl;
            cout <<"0)VOLVER AL MENU PRINCIPAL        "<< endl;

            cout << "Ingrese una opcion: ";
            cin >> opc;

            system("cls");

            switch(opc){

            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0: return ;
                break;

            }

        system("pause");
    }
}


#endif // REPORTES_H_INCLUDED
