//
//  main.cpp
//  Proyecto final
//
//  Created by Guillermo Mayoral Mora on 29/04/24.
//

#include <iostream>
#include <stdlib.h>
using namespace std;


//juego
void tablaPuntos(int x);
int dado(int [], int tamDado);
int guardaDado(int [], int tam, int dadGuard[], int fin);
void puntos(int x, int player);

//llamados
void inicioTurno(int t);
void tirada(int [], int player, int turno);

//Herramientas
void craeArreglo(); //Creador de arreglos
void llamarArreglo(int [], int t);
int contarArreglo(int x[],int tam);
int copiarArreglo(int x[],int i);
void valorInicial();

//Variables globales
int dadoGlob=0, bandGlob=0, manoDadoGlob[6], puntosTabla[13], puntosTabla2[13], win1=0, win2=0;





int main() {
    
    int players, arrDado[6];
    
    valorInicial();
    
    do {
        cout<<"¿Cuantos jugadores seran? 1 o 2? ";   cin>>players;
        if (players >2) {
            cout<<"!ERROR¡ Solo puedes seleccionar entre 1 o 2 jugadores."<<endl;
        }
    } while (players >2);
    
    tablaPuntos(players);
    
    for (int i=0; i<13; i++) {
        cout<<endl<<endl<<"TURNO "<<i+1<<"/13"<<endl<<endl;
        
        if (players==1) {
            inicioTurno(1);
            tirada(arrDado, players, 1);
        }else if(players==2){
            inicioTurno(1);
            tirada(arrDado, players, 1);
            inicioTurno(2);
            tirada(arrDado, players, 2);
        }
    }
    cout<<endl<<"---------------------------------"<<endl;
    tablaPuntos(players);
    
    if (players==1) {
        cout<<"Tus puntos son: "<<win1;
    }else if (players==2){
        cout<<"El ganador es :";
        if (win1>win2) {
            cout<<"El jugador 1 con :"<<win1<<" puntos";
        }else if (win1<win2) {
            cout<<"El jugador 2 con :"<<win2<<" puntos";
        }
    }
    

    
    
}

void tablaPuntos(int x){
    int sumaUno1=0, sumaDos1=0,sumaUno2=0, sumaDos2=0, bonus1=0, bonus2=0;
    
    //jugador 1
    for (int i=0; i<6; i++) {
        sumaUno1+=puntosTabla[i];
    }
    
    for (int i=6; i<13; i++) {
        sumaDos1+=puntosTabla[i];
    }
    
    if (sumaUno1>=63) {
        bonus1=35;
    }
    
    //jugador 2
    for (int i=0; i<6; i++) {
        sumaUno2+=puntosTabla2[i];
    }
    
    for (int i=6; i<13; i++) {
        sumaDos2+=puntosTabla2[i];
    }
    
    if (sumaUno2>=63) {
        bonus2=35;
    }
    
    if (x==1) {
        
        win1=sumaUno1+sumaDos1+bonus1;
        
        cout<<"|-------------|----------|"<<endl;
        cout<<"| Seccion sup |  Puntos  |"<<endl;
        cout<<"|             |    p1    |"<<endl;
        cout<<"|-------------|----------|"<<endl;
        cout<<"|   Unos      |    "<<puntosTabla[0]<<"     |"<<endl;
        cout<<"|   Dos       |    "<<puntosTabla[1]<<"     |"<<endl;
        cout<<"|   Tres      |    "<<puntosTabla[2]<<"     |"<<endl;
        cout<<"|   Cuatros   |    "<<puntosTabla[3]<<"     |"<<endl;
        cout<<"|   Cincos    |    "<<puntosTabla[4]<<"     |"<<endl;
        cout<<"|   Seises    |    "<<puntosTabla[5]<<"     |"<<endl;
        cout<<"|-------------|----------|"<<endl;
        cout<<"|  Suma Secc. |    "<<sumaUno1<<"      |"<<endl;
        cout<<"|  Bonus      |    "<<bonus1<<"      |"<<endl;
        cout<<"|-------------|----------|"<<endl;
        cout<<"|  3 iguales  |    "<<puntosTabla[6]<<"     |"<<endl;
        cout<<"|  4 iguales  |    "<<puntosTabla[7]<<"     |"<<endl;
        cout<<"|  Full house |    "<<puntosTabla[8]<<"     |"<<endl;
        cout<<"|  4 seguidos |    "<<puntosTabla[9]<<"     |"<<endl;
        cout<<"|  5 seguidos |    "<<puntosTabla[10]<<"     |"<<endl;
        cout<<"|   Yahtzee   |    "<<puntosTabla[11]<<"     |"<<endl;
        cout<<"| Oportunidad |    "<<puntosTabla[12]<<"     |"<<endl;
        cout<<"|-------------|----------|"<<endl;
        cout<<"|  Suma Secc. |    "<<sumaDos1<<"      |"<<endl;
        cout<<"|-------------|----------|"<<endl;
        cout<<"|  Suma Total:|    "<<sumaUno1+sumaDos1+bonus1<<"      |"<<endl;
        cout<<"|-------------|----------|"<<endl<<endl<<endl;
    }else if(x==2){
        
        win1=sumaUno1+sumaDos1+bonus1;
        win2=sumaUno2+sumaDos2+bonus2;
        
        cout<<"|-------------|-----|-----|"<<endl;
        cout<<"| Seccion sup |   Puntos  |"<<endl;
        cout<<"|             |  p1 |  p2 |"<<endl;
        cout<<"|-------------|-----|-----|"<<endl;
        cout<<"|   Unos      |  "<<puntosTabla[0]<<"  |  "<<puntosTabla2[0]<<"  |"<<endl;
        cout<<"|   Dos       |  "<<puntosTabla[1]<<"  |  "<<puntosTabla2[1]<<"  |"<<endl;
        cout<<"|   Tres      |  "<<puntosTabla[2]<<"  |  "<<puntosTabla2[2]<<"  |"<<endl;
        cout<<"|   Cuatros   |  "<<puntosTabla[3]<<"  |  "<<puntosTabla2[3]<<"  |"<<endl;
        cout<<"|   Cincos    |  "<<puntosTabla[4]<<"  |  "<<puntosTabla2[4]<<"  |"<<endl;
        cout<<"|   Seises    |  "<<puntosTabla[5]<<"  |  "<<puntosTabla2[5]<<"  |"<<endl;
        cout<<"|-------------|-----|-----|"<<endl;
        cout<<"|  Suma Secc. |  "<<sumaUno1<<"   |  "<<sumaUno2<<"   |"<<endl;
        cout<<"|  Bonus      |     |     |"<<endl;
        cout<<"|-------------|-----|-----|"<<endl;
        cout<<"|  3 iguales  |  "<<puntosTabla[6]<<"  |  "<<puntosTabla2[6]<<"  |"<<endl;
        cout<<"|  4 iguales  |  "<<puntosTabla[7]<<"  |  "<<puntosTabla2[7]<<"  |"<<endl;
        cout<<"|  Full house |  "<<puntosTabla[8]<<"  |  "<<puntosTabla2[8]<<"  |"<<endl;
        cout<<"|  4 seguidos |  "<<puntosTabla[9]<<"  |  "<<puntosTabla2[9]<<"  |"<<endl;
        cout<<"|  5 seguidos |  "<<puntosTabla[10]<<"  |  "<<puntosTabla2[10]<<"  |"<<endl;
        cout<<"|   Yahtzee   |  "<<puntosTabla[11]<<"  |  "<<puntosTabla2[11]<<"  |"<<endl;
        cout<<"| Oportunidad |  "<<puntosTabla[12]<<"  |  "<<puntosTabla2[12]<<"  |"<<endl;
        cout<<"|-------------|-----|-----|"<<endl;
        cout<<"|  Suma Secc. |  "<<sumaDos1<<"   |  "<<sumaDos2<<"   |"<<endl;
        cout<<"|-------------|-----|-----|"<<endl;
        cout<<"|  Suma Total:|  "<<sumaUno1+sumaDos1+bonus1<<"   |  "<<sumaUno2+sumaDos2+bonus2<<"   |"<<endl;
        cout<<"|-------------|-----|-----|"<<endl<<endl<<endl;
    }
    
}

int dado(int arr[], int tamDado){
    srand((unsigned int)time(NULL));
        for (int i =0; i < tamDado; i++) {
            arr[i]= rand() %6 +1;
            cout<<"["<<arr[i]<<"] ";
        }
    return (arr[tamDado]);
}

int guardaDado(int arr[],int tam, int dadGuard[], int fin){
    int guardar, band, posit[6];
    do {
        
        if (fin == 3 || dadoGlob>4) {
            for (int i=0; i<5-dadoGlob; i++) {
                if (arr[i]>0) {
                    dadGuard[tam] =arr[i];
                    posit[tam]=i;
                    tam++;
                    arr[i]=0;
                    
                }
            }
        }else{
            
            cout<<"Escribe el dado que quieres guardar (Para eliminar dados o volver a tirar escribe '0'): "; cin>>guardar;
            
            if (guardar>6) {
                while (guardar>6) {
                    cout<<"los dados solo son de 1 a 6: ";
                    cin>>guardar;
                }
            }
            if(guardar>0){
                for (int i=0; i<6; i++) {
                    if (arr[i]==guardar) {
                        dadGuard[tam] =arr[i];
                        posit[tam]=i;
                        tam++;
                        arr[i]=0;
                        i=6;
                    }
                }
            }else{
                if (tam >=1) {
                    cout<<"\nQue dado quieres eliminar"<<endl;
                    llamarArreglo(dadGuard, tam);
                    cout<<" :"; cin>>guardar;
                    for (int i = 0; i<tam; i++) {
                        if (dadGuard[i]==guardar) {
                            arr[posit[i]]=dadGuard[i];
                            dadGuard[i]=0;
                            i=tam;
                            for (int e = 0; e<tam; e++) {
                                if(dadGuard[e]==0){
                                    dadGuard[e]=dadGuard[e+1];
                                }
                            }
                            tam--;
                        }
                    }
                }else{
                    cout<<"\nNo tines dados en tu mano para eliminar"<<endl;
                }
            }
            cout<<endl<<"dados en tablero: ";
            llamarArreglo(arr, (5-dadoGlob));
            if (tam <1) {
                cout<<endl<<"dados guardados: [0]"<<endl;
            }else{
                cout<<endl<<"dados guardados: ";
                llamarArreglo(manoDadoGlob, dadoGlob);
                llamarArreglo(dadGuard, tam);
            }
        }
        
            cout<<"\nQuieres guardar y/o eliminar otro dado? si='1'    no='0'  "; cin>>band;
            while (band > 1){
                cout<<"\nsolo puedes escoger: si='1' o no='0' ";   cin>>band;
            }
            
    } while (band==1);
    
    for (int e = 0; e<tam; e++) {
        if(arr[e]==0){
            arr[e]=arr[e+1];
        }
    }
    
    dadoGlob+=tam;
    
    return dadGuard[tam];
}

//                                                          ----Llamados
void inicioTurno(int t){
    if (t==1) {
        cout<<endl<<"Turno del Jugador 1:"<<endl;
    }else if(t==2){
        cout<<endl<<"Turno del Jugador 2:"<<endl;
    }
}

void tirada(int arr[], int player, int turno){
    int tamGuard=0,dadosGuard[tamGuard], dadoPoint;
    
    for (int i =1; i<4; i++) {
        int tamDado=5-dadoGlob, contDado = dadoGlob;
        cout<<endl<<"Tirada "<<i<<"/3"<<endl;
        dado(arr, tamDado);
        cout<<endl;
        guardaDado(arr, tamGuard, dadosGuard, i);
        
       // cout<<"LOS DADOS:";
       // llamarArreglo(dadosGuard, dadoGlob);
        
        copiarArreglo(dadosGuard, contDado);
        //cout<<"  ||  ";
        //llamarArreglo(manoDadoGlob, dadoGlob);
        //cout<<"  ||  ";
        
        //cout<<"EL TAMAÑO"<<dadoGlob;
    }
    cout<<endl<<"------------------------------------"<<endl;
    cout<<endl<<"Estos son tus dados: ";
    llamarArreglo(manoDadoGlob, dadoGlob);
    
    puntos(0, player);
    cout<<"Donde deseas colocar los puntos (escribe del 1 al 13): ";    cin>>dadoPoint;
    puntos(dadoPoint, turno);
    
    tablaPuntos(player);
    
    tamGuard=0;
    dadoGlob=0;
}

//                                                          ----herramientas
void craeArreglo(int arr[], int tam){
    for (int i =0; i < tam; i++) {
        cout<<"Dame el ";
    }
}

void llamarArreglo(int x[],int tam){
    for(int i=0;i<tam;i++){
        cout<<"["<<x[i]<<"]";
    }
}

int copiarArreglo(int x[],int i){
    for (int i=0; i<dadoGlob; i++) {
        manoDadoGlob[bandGlob]=x[i];
        
        //cout<<"--bandera: "<<bandGlob<<"--";
        
        bandGlob++;
    }
    bandGlob=dadoGlob;
        return i;
}

void valorInicial(){
    for (int i=0; i<13; i++) {
        puntosTabla[i]=0;
    }
    
    for (int i=0; i<13; i++) {
        puntosTabla2[i]=0;
    }
}






void puntos(int x, int player){
    int unos=0, dos=0, tres=0, cuatros=0, cincos=0, seises=0, numIguales=0;
    int igualTres=0, igualCuatro=0, igualCinco=0, seguida=0, bandSeg=1, bandArr=0, full=0;
    int arr[5];
    
    if(x==0){
        cout<<endl<<"Tus posibles jugadas son: \n";
        
        for (int i=0; i<5; i++) {
            for (int ib=0; ib<5; ib++) {
                if (manoDadoGlob[ib]==i+1) {
                    arr[bandArr]=manoDadoGlob[ib];
                    bandArr++;
                }
            }
        }
        
        
        for (int i=0; i<5; i++) {
            int band=0, bandFull=0;
            numIguales+=manoDadoGlob[i];
            
            if (manoDadoGlob[i]==1) {
                unos+=1;
            }
            if (manoDadoGlob[i]==2) {
                dos+=2;
            }
            if (manoDadoGlob[i]==3) {
                tres+=3;
            }
            if (manoDadoGlob[i]==4) {
                cuatros+=4;
            }
            if (manoDadoGlob[i]==5) {
                cincos+=5;
            }
            if (manoDadoGlob[i]==6) {
                seises+=6;
            }
            
            //para conseguir 3 iguales y 4 iguales
            for (int ib=0; ib<6; ib++) {
                if (arr[ib]==i+1) {
                    band++;
                    if (band==3) {
                        igualTres=1;
                    }
                    if (band==4) {
                        igualCuatro=1;
                    }
                    if (band==5) {
                        igualCinco=1;
                    }
                }
            }
            //para full house
            
            for (int ib=0; ib<6; ib++) {
                if (arr[ib]==i+1) {
                    bandFull++;
                    if (bandFull==3) {
                        full++;
                    }else if(bandFull==2){
                        full++;
                    }
                }
            }
            
            
            //para seguida
            if (arr[i]==bandSeg) {
                seguida++;
                bandSeg++;
            }
            if (i==0) {
                bandSeg=2;
            }
        }
        
        if (unos>0) {
            cout<<endl<<"para seleccionar Unos escribe 1";
            cout<<endl<<"unos: "<<unos<<endl;
        }
        if (dos>0) {
            cout<<endl<<"para seleccionar Dos escribe 2";
            cout<<endl<<"dos: "<<dos<<endl;
        }
        if (tres>0) {
            cout<<endl<<"para seleccionar Tres escribe 3";
            cout<<endl<<"tres: "<<tres<<endl;
        }
        if (cuatros>0) {
            cout<<endl<<"para seleccionar Cuatros escribe 4";
            cout<<endl<<"cuatros: "<<cuatros<<endl;
        }
        if (cincos>0) {
            cout<<endl<<"para seleccionar Cincos escribe 5";
            cout<<endl<<"cincos: "<<cincos<<endl;
        }
        if (seises>0) {
            cout<<endl<<"para seleccionar Seises escribe 6";
            cout<<endl<<"seises: "<<seises<<endl;
        }
        
        if (igualTres==1) {
            cout<<endl<<"para seleccionar Tres Iguales escribe 7";
            cout<<endl<<"3 iguales: "<<numIguales<<endl;
        }
        
        if (igualCuatro==1) {
            cout<<endl<<"para seleccionar Cuatro iguales escribe 8";
            cout<<endl<<"4 iguales: "<<numIguales<<endl;
        }
        
        if (full>=3) {
            cout<<endl<<"para seleccionar Full House escribe 9";
            cout<<endl<<"Full House: 25"<<endl;
        }
        
        if (seguida>=4) {
            cout<<endl<<"para seleccionar seguida de 4 escribe 10";
            cout<<endl<<"Seguida de 4: 30"<<endl;
        }
        
        if (seguida>=5) {
            cout<<endl<<"para seleccionar seguida de 5 escribe 11";
            cout<<endl<<"Seguida de 5: 40"<<endl;
        }
        
        if (igualCinco==1) {
            cout<<endl<<"para seleccionar YAHTZEE escribe 12";
            cout<<endl<<"YAHTZEE: 50"<<endl;
        }
        
        cout<<endl<<"para seleccionar Oportunidad escribe 13";
        cout<<endl<<"Oportunidad: "<<numIguales<<endl;
        
    }else if(x>0 && player==1){
        
        for (int i=0; i<5; i++) {
            for (int ib=0; ib<5; ib++) {
                if (manoDadoGlob[ib]==i+1) {
                    arr[bandArr]=manoDadoGlob[ib];
                    bandArr++;
                }
            }
        }
        
        
        for (int i=0; i<5; i++) {
            int band=0, bandFull=0;
            numIguales+=manoDadoGlob[i];
            
            if (manoDadoGlob[i]==1) {
                unos+=1;
            }
            if (manoDadoGlob[i]==2) {
                dos+=2;
            }
            if (manoDadoGlob[i]==3) {
                tres+=3;
            }
            if (manoDadoGlob[i]==4) {
                cuatros+=4;
            }
            if (manoDadoGlob[i]==5) {
                cincos+=5;
            }
            if (manoDadoGlob[i]==6) {
                seises+=6;
            }
            
            //para conseguir 3 iguales y 4 iguales
            for (int ib=0; ib<6; ib++) {
                if (manoDadoGlob[ib]==i+1) {
                    band++;
                    if (band==3) {
                        igualTres=1;
                    }
                    if (band==4) {
                        igualCuatro=1;
                    }
                    if (band==5) {
                        igualCinco=1;
                    }
                }
            }
            //para full house
            
            for (int ib=0; ib<6; ib++) {
                if (arr[ib]==i+1) {
                    bandFull++;
                    if (bandFull==3) {
                        full++;
                    }else if(bandFull==2){
                        full++;
                    }
                }
            }
            
            
            //para seguida
            if (arr[i]==bandSeg) {
                seguida++;
                bandSeg++;
            }
            if (i==0) {
                bandSeg=2;
            }
        }
        
        switch (x) {
            case 1:
                puntosTabla[0]=unos;
                break;
            case 2:
                puntosTabla[1]=dos;
                break;
            case 3:
                puntosTabla[2]=tres;
                break;
            case 4:
                puntosTabla[3]=cuatros;
                break;
            case 5:
                puntosTabla[4]=cincos;
                break;
            case 6:
                puntosTabla[5]=seises;
                break;
            case 7:
                puntosTabla[6]=numIguales;
                break;
            case 8:
                puntosTabla[7]=numIguales;
                break;
            case 9:
                puntosTabla[8]=25;
                break;
            case 10:
                puntosTabla[9]=30;
                break;
            case 11:
                puntosTabla[10]=40;
                break;
            case 12:
                puntosTabla[11]=50;
                break;
            case 13:
                puntosTabla[12]=numIguales;
                break;
                
            default:
                break;
        }
    }else if(x>0 && player==2){
        
        for (int i=0; i<5; i++) {
            for (int ib=0; ib<5; ib++) {
                if (manoDadoGlob[ib]==i+1) {
                    arr[bandArr]=manoDadoGlob[ib];
                    bandArr++;
                }
            }
        }
        
        
        for (int i=0; i<5; i++) {
            int band=0, bandFull=0;
            numIguales+=manoDadoGlob[i];
            
            if (manoDadoGlob[i]==1) {
                unos+=1;
            }
            if (manoDadoGlob[i]==2) {
                dos+=2;
            }
            if (manoDadoGlob[i]==3) {
                tres+=3;
            }
            if (manoDadoGlob[i]==4) {
                cuatros+=4;
            }
            if (manoDadoGlob[i]==5) {
                cincos+=5;
            }
            if (manoDadoGlob[i]==6) {
                seises+=6;
            }
            
            //para conseguir 3 iguales y 4 iguales
            for (int ib=0; ib<6; ib++) {
                if (manoDadoGlob[ib]==i+1) {
                    band++;
                    if (band==3) {
                        igualTres=1;
                    }
                    if (band==4) {
                        igualCuatro=1;
                    }
                    if (band==5) {
                        igualCinco=1;
                    }
                }
            }
            //para full house
            
            for (int ib=0; ib<6; ib++) {
                if (arr[ib]==i+1) {
                    bandFull++;
                    if (bandFull==3) {
                        full++;
                    }else if(bandFull==2){
                        full++;
                    }
                }
            }
            
            
            //para seguida
            if (arr[i]==bandSeg) {
                seguida++;
                bandSeg++;
            }
            if (i==0) {
                bandSeg=2;
            }
        }
        
        switch (x) {
            case 1:
                puntosTabla2[0]=unos;
                break;
            case 2:
                puntosTabla2[1]=dos;
                break;
            case 3:
                puntosTabla2[2]=tres;
                break;
            case 4:
                puntosTabla2[3]=cuatros;
                break;
            case 5:
                puntosTabla2[4]=cincos;
                break;
            case 6:
                puntosTabla2[5]=seises;
                break;
            case 7:
                puntosTabla2[6]=numIguales;
                break;
            case 8:
                puntosTabla2[7]=numIguales;
                break;
            case 9:
                puntosTabla2[8]=25;
                break;
            case 10:
                puntosTabla2[9]=30;
                break;
            case 11:
                puntosTabla2[10]=40;
                break;
            case 12:
                puntosTabla2[11]=50;
                break;
            case 13:
                puntosTabla2[12]=numIguales;
                break;
                
            default:
                break;
        }
    }
}
