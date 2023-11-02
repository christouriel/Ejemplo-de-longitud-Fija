#include <iostream>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string.h>

using namespace std;

class Usuario
{
public:
    char id_user[15],username[35],mail_user[35],password[25],date_access[25],date_admission[25];
    void Agregar();
    void Mostrar();
    void Modificar();
    void Buscar();
    void Eliminar();
} OrdCom;
void Usuario::Agregar()
{
    cout<<"GENERATE USER LIST"<<endl;
    cout<<"User ID: ";
    cin.getline(id_user,15);
    cin.getline(id_user,15);
    cout<<"Name: ";
    cin.getline(username,35);
    cout<<"Mail: ";
    cin.getline(mail_user,35);
    cout<<"Password: ";
    cin.getline(password,25);
    cout<<"Date access: ";
    cin.getline(date_access,25);
    cout<<"Date admission: ";
    cin.getline(date_admission,25);
    ofstream archivo("Users.txt",ios::app);
    archivo.write((char*)&OrdCom,sizeof(OrdCom));
    archivo.close();
}
void Usuario::Mostrar()
{
    char usuario2[10], password2[10];
    int band=0;
    ifstream archivo("Users.txt");
    if(!archivo.good())
    {
        cout<<"\n The file does not exists....."<<endl;
    }
    else
    {
        cout<<"User List"<<endl;
        while(!archivo.eof())
        {
            archivo.read((char*)&OrdCom,sizeof(OrdCom));
            if(archivo.eof())
            {
                break;
            }
            cout<<"User ID: "<<id_user<<endl;
            cout<<"Name "<<username<<endl;
            cout<<"Mail: "<<mail_user<<endl;
            cout<<"Password: "<<password<<endl;
            cout<<"Date Access: "<<date_access<<endl;
            cout<<"Date Admission:"<<date_admission<<endl;
            cout<<""<<endl;
        }
        archivo.close();
    }
}
void Usuario::Modificar()
{
    char valor[4];
    ifstream archivo("Users.txt");
    if(!archivo.good())
    {
        cout<<"\n The file does not exists...."<<endl;
    }
    else
    {
        cout<<"MODIFY USER LIST"<<endl;
        cout<<"I Typed user ID: ";
        cin.getline(valor,15);
        cin.getline(valor,15);
        ofstream archivo2("TEMPORARY.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&OrdCom,sizeof(OrdCom));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(id_user,valor)==0)
            {
                cout<<""<<endl;
                cout<<"New ID User: ";
                cin.getline(id_user,15);
                cout<<"New Name: ";
                cin.getline(username,35);
                cout<<"New Mail: ";
                cin.getline(mail_user,35);
                cout<<"New Password: ";
                cin.getline(password,25);
                cout<<"New Date Access: ";
                cin.getline(date_access,25);
                cout<<"New Date Admission: ";
                cin.getline(date_admission,25);
                ofstream archivo("Users.txt",ios::app);
                archivo2.write((char*)&OrdCom,sizeof(OrdCom));
            }
            else
            {
                archivo2.write((char*)&OrdCom,sizeof(OrdCom));
            }

        }
        archivo.close();
        archivo2.close();
        remove("Users.txt");
        char oldname[] ="TEMPORARY.txt";
        char newname[] ="Users.txt";
        rename(oldname,newname);
    }
}
void Usuario::Eliminar()
{
    char valor[15];
    int opcion=0;
    ifstream archivo("Users.txt");
    if(!archivo.good())
    {
        cout<<"\n The file does not exists...."<<endl;
    }
    else
    {
        cout<<"REMOVE USER FROM LIST"<<endl;
        cout<<"Type user Id to Delete: ";
        cin.getline(valor,15);
        cin.getline(valor,15);
        ofstream archivo2("TEMPORARY.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&OrdCom,sizeof(OrdCom));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(id_user,valor)==0)
            {
                cout<<"\tID Found"<<endl;
                cout<<"User ID: "<<id_user<<endl;
                cout<<"Name "<<username<<endl;
                cout<<"Mail: "<<mail_user<<endl;
                cout<<"Password: "<<password<<endl;
                cout<<"Date Access: "<<date_access<<endl;
                cout<<"Date Admission:"<<date_admission<<endl;
                cout<<"Sure you want to delete the user?\n1.- YES\n0.- NOT\n>: ";
                cin>>opcion;
                if(opcion==1)
                {

                }
                else
                {
                    archivo2.write((char*)&OrdCom,sizeof(OrdCom));
                }
            }
            else
            {
                archivo2.write((char*)&OrdCom,sizeof(OrdCom));
            }
        }
        archivo.close();
        archivo2.close();
        remove("Users.txt");
        char oldname[] ="TEMPORARY.txt";
        char newname[] ="Users.txt";
        rename(oldname,newname);
    }

}
void Usuario::Buscar()
{
    char valor[15];
    ifstream archivo("Users.txt");
    if(!archivo.good())
    {
        cout<<"\n The file does not exists...."<<endl;
    }
    else
    {
        cout<<"Look up user ID"<<endl;
        cout<<"Enter the ID of the user to search: ";
        cin.getline(valor,15);
        cin.getline(valor,15);
        archivo.read((char*)&OrdCom,sizeof(OrdCom));
        if(strcmp(id_user,valor)==0)
        {
            cout<<"\tFound user"<<endl;
            cout<<"User ID: "<<id_user<<endl;
            cout<<"Name "<<username<<endl;
            cout<<"Mail: "<<mail_user<<endl;
            cout<<"Password: "<<password<<endl;
            cout<<"Date Access: "<<date_access<<endl;
            cout<<"Date Admission:"<<date_admission<<endl;
           
        }
        else
        {
            cout << "ID not Found..." << endl;
        }
    }
    archivo.close();
}
void Pausar()
{
    cin.get();
    cout << "Pres enter to continue..." << endl;
    cin.get();
    system("cls");
}
int main()
{
    int op;
    do
    {
        system("cls");
        cout<<"LIST OF USERS"<<endl;
        cout<<"1.-Capture" <<endl;
        cout<<"2.-Show list" <<endl;
        cout<<"3.-Modify "<<endl;
        cout<<"4.-Remove" <<endl;
        cout<<"5.-Search "<<endl;
        cout<<"6.-Exit "<<endl;
        cout<<"Select an option->";
        cin>>op;
        switch(op)
        {
        case 1:
            system("cls");
            OrdCom.Agregar();
            Pausar();
            break;
        case 2:
            system("cls");
            OrdCom.Mostrar();
            Pausar();
            break;
        case 3:
            system("cls");
            OrdCom.Modificar();
            Pausar();
            break;
        case 4:
            system("cls");
            OrdCom.Eliminar();
            Pausar();
            break;
        case 5:
            system("cls");
            OrdCom.Buscar();
            Pausar();
            break;
        case 6:
            op=6;
            break;
        }
    }
    while(op!=6);
    return 0;
}
