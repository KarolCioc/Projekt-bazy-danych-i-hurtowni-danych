#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int random(int min_num, int max_num){
   int result=0,low_num=0,hi_num=0;
   if(min_num <max_num){
        low_num = min_num;
        hi_num = max_num+1;
   }else{
        low_num = max_num+1;
        hi_num=min_num;
   }
   result = (rand()%(hi_num-low_num)+low_num);
   return result;
}

char *imiona[]={"Karol","Filip","Lukasz","Pawel","Piotr","Mateusz","Jakub","Bartosz","Joachim","Gabriel","Konrad","Denis","Jaroslaw","Grzegorz","Michal"};
char *nazwiska[]={"Nowak","Wojcik","Kowalczyk","Wozniak","Kaczmarek","Mazur","Krawczyk","Labryga","Adamczyk","Dudek","Zalecki","Banabak","Pazurek"};
char *komb[]={"DAT","PAT","SND","TGH","DGH","POD","FDW","LGS","GVN","YHQ","KJF","IUY","YTH","CVX","VXZ","AZL","SXI"};

void klient(){
    FILE *plik = fopen("klient.csv","w");
    for(int i=1;i<=500;i++){
            char* imie = imiona[random(0,sizeof(imiona)/sizeof(imiona[0])-1)];
            char* nazwisko = nazwiska[random(0,sizeof(nazwiska)/sizeof(nazwiska[0])-1)];
            char* kombinacja = komb[random(0,sizeof(komb)/sizeof(komb[0])-1)];
            fprintf(plik,"%d,'%s','%s',%d,%s%d,%d\n",i,imie,nazwisko,random(500000000,800000000),kombinacja,random(100000,999999),random(1,100));
    }
    fclose(plik);
}

char *kolor[] = {"Czarny","Srebrny","Gwiezdzisty","Teczowy","Czerwony","Fioletowy"};

void color(){
    FILE *plik = fopen("kolor.csv","w");

    for(int i=1; i<=6; i++){
        fprintf(plik,"%d,'%s'\n",i,kolor[i-1]);
    }
    fclose(plik);
}

void magazyn(){
	FILE* plik = fopen("magazyn.csv","w");

    int i;
    for(i=1;i<=100;i++){
          fprintf(plik,"%d,%d,%d,%d\n",i,random(50,100),random(1,360),i);
    }
    fclose(plik);
}

char *marka[] = {"iPhone","Samsung","Xiaomi","Huawei","Sony"};
char *modelIphone[] = {"11 Mini","11 Pro","11 Max","12 Mini","12 Pro","12 Max","13 Mini","13 Pro","13 Max","14 Mini","14 Pro","14 Max"};
char *modelSamsung[] = {"M36","S23 Pro","A54","S22","S23","A34","M23","S20","A14","M13","M33","S20"};
char *modelXiaomi[] = {"12S","12","12 P","12C","13","A1","12 Pro+","X5","F5","10","M5","M4 Pro"};
char *modelHuawei[] = {"P60 Pro","Nova 11i","Mate X3","Nova 10 SE","Mate 50 Pro","Nova Y70","Nova 10 Pro","P60","Nova Y90","Nova Y61","P50 Pocket","Nova 8i"};
char *modelSony[] = {"Xperia 10 IV","Xperia 1","Xperia Pro-I","Xperia 5","Xperia 1 IV","Xperia 1 III","Xperia 5 III","Xperia VII","Xperia SE","Xperia Pro IX","Xperia II Max","Xperia OG"};

void nazwa_marka(){
    FILE *plik = fopen("marka.csv","w");
    for(int i = 1; i<=5; i++){
        fprintf(plik,"%d,'%s'\n",i,marka[i-1]);
    }
    fclose(plik);
}

char *nazwy[] = {"Orange","Play","T-Mobile","Nju-mobile","Plus"};

void salon(){
    FILE *plik = fopen("salon.csv","w");
    for(int i=1;i<=100;i++){
            char *nazwa =  nazwy[random(0,sizeof(nazwy)/sizeof(nazwy[0])-1)];
            fprintf(plik,"%d,'%s',%d\n",i,nazwa,random(1,100));
    }
    fclose(plik);
}
char* ulice[] = {"Polna","Wodna","Kreski","Okrzei Stefana","Nowaki","Malikowa","Czysta","Stawowa","Komandorska",
                "Jana Matejki","Zielenista","Wolna","Parkowa","Drukarska","Gimnazjalna","Legionow","Chopina","Jablonskiego",
                "Papierowa","Bankowa","Stawki","Gminna","Graniczna","Ochotnicza","Liniowa","Strumykowa","Bukowa","Pocztowa",
                "Waleczna","Marcinkowskiego","Ciosa","Paryska","Zlota","Zwirasa","Pokoju","Kolejowa",
                "Lubelska","Licha","Rzeczna","Mickiewicza","Klikowska","Graniczna","Szkolna","Zgoda","Przeskok","Grodzka",
                "Jachowicza","Kolejowa","Krupnicza","Rynek","Zamkowa","Filtrowa","Jasna","Dobra","Obszar Kolei","Unii Lubelskiej",
                "Reformacka","Krawcowa","Poniatowskiego","Jana Pawla II","Popkowa","Ogrodowa","Dawna","Klonowa","Noniewicza","Paca",
                "Mochnackiego","Westerplatte","Mieszka I","Marynarki Polskiej","Prosow","Orzechowa","Bankowa","Dworcowa",
                "Mariacka","Grabowa","Draski","Bracka","Barbary","Piastowska","Polna","Kajki","Kielecka","Nowowiejska",
                "Ostatnia","Osiecka","Lewa","Chrobrego","Sikorskiego","Barki","Wysoka","Sierpowa","Kaliny","Wyspianskiego",
                "Sloneczna","Podrygu","Oslow","Konia","Wiewiora","Pasikonika"};

char* miasta[] = {"Ostrowiec Swietokrzyski","Wroclaw","Bydgoszcz","Lublin","Zielona Gora","Lodz","Krakow",
                    "Warszawa","Opole","Rzeszow","Bialystok","Gdansk","Katowice","Olsztyn",
                    "Poznan","Szczecin"};
char* wojewodztwa[]={"Swietokrzyskie","Dolnoslaskie","Kujawsko-pomorskie","Lubelskie","Lubuskie","Lodzkie","Malopolskie",
                     "Mazowieckie","Opolskie","Podkarpacie","Podlaskie","Pomorskie","Slaskie","Warminsko-mazurskie",
                     "Wielkopolskie","Zachodniopomorskie"};





void ulica(){
    FILE *plik = fopen("ulica.csv","w");
    for(int i=1;i<=100;i++){
            char *ulica =  ulice[random(0,sizeof(ulice)/sizeof(ulice[0])-1)];
            fprintf(plik,"%d,%d,'%s'\n",random(1,16),i,ulica);
    }
    fclose(plik);
}

void wojewodztwo(){
    FILE *plik = fopen("wojewodztwo.csv","w");
    for(int i=1;i<=16;i++){
            fprintf(plik,"%d,'%s'\n",i,wojewodztwa[i-1]);
    }
    fclose(plik);
}

void miasto(){
    FILE *plik = fopen("miasto.csv","w");
    for(int i=1;i<=16;i++){
            fprintf(plik,"%d,'%s',%d\n",i,miasta[i-1],i);
    }
    fclose(plik);
}



void pracownik(){
    FILE *plik = fopen("pracownik.csv","w");
    for(int i=1;i<=500;i++){
            char* imie = imiona[random(0,sizeof(imiona)/sizeof(imiona[0])-1)];
            char* nazwisko = nazwiska[random(0,sizeof(nazwiska)/sizeof(nazwiska[0])-1)];
            fprintf(plik,"%d,'%s',%d,%d,'%s'\n",i,imie,random(1,100),random(1,5),nazwisko);
    }
    fclose(plik);
}

char *stanowiska[] = {"Doradca","Sprzedawca","Specjalista marketingu","Prezes","Konsultant"};

void stanowisko(){
    FILE *plik = fopen("stanowisko.csv","w");
    for(int i=1;i<=5;i++){
            fprintf(plik,"%d,'%s',%d\n",i,stanowiska[i-1],random(4500,9000));
    }
    fclose(plik);
}

void model(){
    FILE *plik4 = fopen("model.csv","w");
    int i;
    int k=1;
    for(i=1;i<=12;i++){
        fprintf(plik4,"%d,'%s',%d\n",k,modelIphone[i-1],1);
        k++;
    }
    for(i=1;i<=12;i++){
        fprintf(plik4,"%d,'%s',%d\n",k,modelSamsung[i-1],2);
        k++;
    }
    for(i=1;i<=12;i++){
        fprintf(plik4,"%d,'%s',%d\n",k,modelXiaomi[i-1],3);
        k++;
    }
    for(i=1;i<=12;i++){
        fprintf(plik4,"%d,'%s',%d\n",k,modelHuawei[i-1],4);
        k++;
    }
    for(i=1;i<=12;i++){
        fprintf(plik4,"%d,'%s',%d\n",k,modelSony[i-1],5);
        k++;
    }
    cout<<"dodano"<<endl;
    fclose(plik4);
}

void telefony(){
    FILE *plik = fopen("telefony.csv","w");
    int k=1;
    for(int i=1; i<=60; i++){
        for(int j=1;j<=6;j++){
            fprintf(plik,"%d,%d,%d\n",k,j,i);
            k++;
        }
}
    //k=13;
    /*for(int i=1; i<=12; i++){
        for(int j=1;j<=6;j++){
            fprintf(plik,"%d,%d,%d\n",k,j,i);
            k++;
        }
}
    //k=25;
    for(int i=1; i<=12; i++){
        for(int j=1;j<=6;j++){
            fprintf(plik,"%d,%d,%d\n",k,j,i);
            k++;
        }
}
    //k=37;
    for(int i=1; i<=12; i++){
        for(int j=1;j<=6;j++){
            fprintf(plik,"%d,%d,%d\n",k,j,i);
            k++;
        }
}
    //k=49;
    for(int i=1; i<=12; i++){
        for(int j=1;j<=6;j++){
            fprintf(plik,"%d,%d,%d\n",k,j,i);
            k++;
        }

}*/
    cout<<"ilosc tel:"<<k<<endl;

    fclose(plik);
}
void umowa(){
    FILE *plik = fopen("umowa.csv","w");
    int k=1;
    int o=1;
    for(int i=1; i<=900; i++){
        fprintf(plik,"%d,%d-%d-%d,%d,%d,%d,%d,%d\n",o,random(1,31),1,random(2010,2022),random(1,500),random(1,500),random(1000,5000),random(1,4),random(1,100));
        o++;
    }
    for(int h=1;h<=900;h++){
        fprintf(plik,"%d,%d-%d-%d,%d,%d,%d,%d,%d\n",o,random(1,28),2,random(2010,2022),random(1,500),random(1,500),random(1000,5000),random(1,4),random(1,100));
        o++;
    }
    for(int i=1; i<=1500; i++){
    for(int j=3;j<=8;j++){
        if(j%2==0){
        fprintf(plik,"%d,%d-%d-%d,%d,%d,%d,%d,%d\n",o,random(1,30),j,random(2010,2022),random(250,500),random(250,500),random(1000,5000),random(1,4),random(1,100));
        o++;
    }else{
        fprintf(plik,"%d,%d-%d-%d,%d,%d,%d,%d,%d\n",o,random(1,31),j,random(2010,2022),random(1,250),random(1,250),random(1000,5000),random(1,4),random(1,100));
        o++;
    }
    }
    }
    fclose(plik);
}

int main()
{
    srand(time(NULL));
    color();
    telefony();
    umowa();
    magazyn();
    model();
    nazwa_marka();
    pracownik();
    klient();
    miasto();
    ulica();
    wojewodztwo();
    salon();
    stanowisko();
    return 0;
}
