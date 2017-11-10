#include <iostream>
int menu();
using namespace std;
void comenzar(int tablero[][20],int tamaño);
void mostrarTablero(int tablero[][20], int tamaño);
void VerTablero(int tablero[][20], int tamaño);
void restablecerTablero(int tablero[][20], int tamaño);
int main(int argc, const char * argv[]) {
    int opc, tamaño=20;
    int tablero[20][20]{{0}};
    cout << "Pintar la Tortuga\n";
    
    do {
        opc = menu();

        if (opc==1)
            comenzar(tablero, tamaño);
        else if (opc==2)
        { 
            
        }
        else if (opc==3)
            restablecerTablero(tablero,tamaño);
        
        else if (opc==0)
            cout<<"nos vemos! :)\n";
        else
            cout<<"opcion no valida\n";
        mostrarTablero(tablero, tamaño);
        VerTablero(tablero, tamaño);
    } while (opc!=0);
   
    return 0;
}
int menu()
{
    int opc;
    cout<<"1.-comenzar el juego\n";
    cout<<"2.-ver instrucciones\n";
    cout<<"3.-volver a intentarlo\n";
    cout<<"0.-Salir\n";
    cin>>opc;
    return opc;
}
void comenzar(int tablero[][20],int tamaño)
{
    int opc,pasos = 0,pluma=0,girarDerecha = 0;
    int posicionY=0,posicionX=0;
    cout<<"***INSTRUCCIONES**** \n";
    cout<<"1.SUBIR PLUMA\n"
    <<"2. BAJAR PLUMA\n"
    <<"3. GIRO A LA DERECHA\n"
    <<"4. GIRO A LA IZQUIERDA\n"
    <<"5. AVANZA \n"
    <<"6  EXIT\n";
    do {
        
        cin>>opc;
        if (opc==1)
        {
            pluma=0;
            cout<<"Subir pluma\n";
        }
        else if (opc==2)
        {
            pluma=1;
            cout<<"bajar pluma\n";
        }
        else if(opc==3){
            girarDerecha += 1;
            if(girarDerecha==4)
                girarDerecha=0;
            cout<<girarDerecha<<"Giro derecha\n";
        }
        else if(opc==4)
        {  girarDerecha -= 1;
        if(girarDerecha<0)
            girarDerecha=3;
        cout<<girarDerecha<<"Giro izquierdo \n";
        }
        else if (opc==5) {
            cout<<"ingresa cuanto quieres avanzar: \n";
            cin>>pasos;
            if (girarDerecha==0)
                for (int j=posicionX, i=posicionY, k=pasos; k>0; j++,k--) {
                    if (j>=tamaño-1){
                        k=0;
                        tablero[i][j]=pluma;
                    }
                    tablero[i][j]=pluma;
                    
                    posicionX=j;
                   
                }
            else if (girarDerecha==1)
                for (int k=pasos,i=posicionY, j=posicionX; k>0; k--,i++) {
                    if (pluma==1){
                    if (i>=tamaño-1){
                        k=0;
                        tablero[i][j]=pluma;
                    }
                    tablero[i][j]=pluma;
                    posicionY=i;
                    }

                }
            else if (girarDerecha==2)
                for (int k=posicionX, i=posicionY, j=pasos; j>0; j--,k--) {
                    if (pluma==1){
                    if (k==0){
                        j=0;
                        tablero[i][k]=pluma;
                    }
                    tablero[i][k]=pluma;
                    posicionX=k;
                    cout<<posicionX<<"x\n";
                }
                }
            else if (girarDerecha==3)
                for (int k=posicionY,j=posicionX, i=pasos; i>0; i--,k--) {
                    if (pluma==1){
                    if (k==0){
                        i=0;
                        tablero[k][j]=pluma;
                    }
                    tablero[k][j]=pluma;
                    posicionY=k;
                    
                }
                }
            
        }

    } while (opc!=6);
}
void mostrarTablero(int tablero[][20], int tamaño)
{
    for (int i=0; i<tamaño; i++) {
        for (int j=0; j<tamaño; j++){
            if (tablero[i][j]==1) {
                cout<<"*";
            }
            else
                cout<<" ";
        }
        cout<<"\n";
    }
}
void VerTablero(int tablero[][20], int tamaño)
{
        for (int i=0; i<tamaño; i++) {
          for (int j=0; j<tamaño; j++)
              cout<<" "<<tablero[i][j];
          cout<<"\n";
          }
}
void restablecerTablero(int tablero[][20],int tamaño)
{
    for (int i=0; i<tamaño; i++)
        for (int j=0; j<tamaño; j++)
            tablero[i][j]=0;
}
