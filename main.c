#include <stdio.h>
#include <stdlib.h>
typedef struct datum{
    char dan[3],mesec[3],godina[5];
}datum;
typedef struct adresa{
    char ulica[30];
    int broj;
}adresa;
typedef struct ocena{
    int vrednost;
    char tip[15];
    datum docene;
}ocena;
typedef struct ucenik{
    char ime[20];
    char prezime[20];
    datum rodjenje;
    char jmbg[14];
    adresa stanovanje;
    char brojTelefona[20];
}ucenik;
int meni(){
char n;
printf("Izaberite opciju:\n1. Dodavanje novog ucenika\n2. Prikaz svih ucenika\n3. Pretraga naloga ucenika\n4. Izmena naloga ucenika\n5. Brisanje ucenickog naloga\n6. Ocenjivanje ucenika\n7. Preporuka zakljucne ocene\n8. Kraj rada programa!\n");
fflush(stdin);
scanf("%c",&n);
if(n<'1' || n>'8')
    printf("Nepostojeca opcija!Pokusajte ponovo...\n");
return (n-'0');
}
int uporedjivanjeStringa(char string[20],char stringg[20]){
        int l=0,d=0;
        int lenj=strlen(string);
        int lend=strlen(stringg)-1;
        if(lenj!=lend)
            ++d;
        while(string[l]!='\0'){
            if(string[l]!=stringg[l])
                ++d;
            ++l;
            }
            if(d==0)
                return 1; //Ako su isti stringovi
            else
                return 0;
}
int proveraJMBG(FILE*ucenici,int r,char jmbg[20],datum Datum){
     int n=0;
     int i=0;
     if(r!=0){
     ucenici=fopen("ucenici.txt","r");
     char lajna[50];
     for(;i<r*10;++i){
        fgets(lajna,50,ucenici);
        if(i%10==4){
            if(uporedjivanjeStringa(lajna,jmbg)){
                ++n;
                break;
            }
        }
     }
     fclose(ucenici);
     }
     for(i=0;i<13;++i){
        if(jmbg[i]<'0' || jmbg[i]>'9' || jmbg[13]!=NULL){
            ++n;
            break;
        }
     }
     if(Datum.dan[1]==NULL){
        if(jmbg[0]!='0' || jmbg[1]!=Datum.dan[0]){
            ++n;
        }
     }
     if(Datum.dan[1]!=NULL){
        if(jmbg[0]!=Datum.dan[0] || jmbg[1]!=Datum.dan[1]){
                ++n;
        }
     }
     if(Datum.mesec[1]==NULL){
        if(jmbg[2]!='0' || jmbg[3]!=Datum.mesec[0]){
            ++n;
        }
     }
     if(Datum.mesec[1]!=NULL){
        if(jmbg[2]!=Datum.mesec[0] || jmbg[3]!=Datum.mesec[1]){
            ++n;
        }
     }
     if(Datum.godina[1]!=jmbg[4] || Datum.godina[2]!=jmbg[5] || Datum.godina[3]!=jmbg[6]){
            ++n;
     }
     if(n!=0)
        return 0;
     if(n==0)
        return 1;
}
int proveraDatum(datum Datum){
    if(Datum.dan[1]==NULL){
    Datum.dan[1]=Datum.dan[0];
    Datum.dan[0]='0';
    }
    if(Datum.mesec[1]==NULL){
    Datum.mesec[1]=Datum.mesec[0];
    Datum.mesec[0]='0';
    }
    int n=0;
    if(Datum.dan[0]<'0' || Datum.dan[1]<'0' || Datum.mesec[0]<'0' || Datum.mesec[1]<'0')
        n++;
    if(Datum.godina[0]<'0' || Datum.godina[1]<'0' || Datum.godina[2]<'0' || Datum.godina[3]<'0')
        n++;
    if(Datum.dan[0]>'3')
        n++;
    if(Datum.mesec[0]>'1')
        n++;
    if(Datum.godina[0]>'2')
        n++;
    if(Datum.dan[0]=='3' && Datum.dan[1]>'1')
        n++;
    if(Datum.mesec[0]=='1' && Datum.mesec[1]>'2')
        n++;
    if(Datum.godina[0]<'2')
        n++;
    if(Datum.godina[0]=='2' && Datum.godina[1]>'0')
        n++;
    if(Datum.godina[0]=='2' && Datum.godina[1]=='0' && Datum.godina[2]>'1')
        n++;
    if(Datum.godina[0]=='2' && Datum.godina[1]=='0' && Datum.godina[2]=='1' && Datum.godina[3]>'3')
        n++;
    if(Datum.mesec[0]=='0' && Datum.mesec[1]=='2' && Datum.dan[0]=='2' && Datum.dan[1]>'8')
        n++;
    if(Datum.mesec[1]=='4' || Datum.mesec[1]=='6' || Datum.mesec[1]=='9' || (Datum.mesec[0]=='1' && Datum.mesec[1]=='1')){
        if(Datum.dan[0]=='3' && Datum.dan[1]>'0')
            n++;
    }
    if(n==0)
        return 1;
    else
        return 0;
}
int proveraDatumaOcene(datum Datum){
    if(Datum.dan[1]==NULL){
    Datum.dan[1]=Datum.dan[0];
    Datum.dan[0]='0';
    }
    if(Datum.mesec[1]==NULL){
    Datum.mesec[1]=Datum.mesec[0];
    Datum.mesec[0]='0';
    }
    int n=0;
    if(Datum.dan[0]<'0' || Datum.dan[1]<'0' || Datum.mesec[0]<'0' || Datum.mesec[1]<'0')
        n++;
    if(Datum.godina[0]<'0' || Datum.godina[1]<'0' || Datum.godina[2]<'0' || Datum.godina[3]<'0')
        n++;
    if(Datum.dan[0]>'3')
        n++;
    if(Datum.mesec[0]>'1')
        n++;
    if(Datum.godina[0]>'2')
        n++;
    if(Datum.dan[0]=='3' && Datum.dan[1]>'1')
        n++;
    if(Datum.mesec[0]=='1' && Datum.mesec[1]>'2')
        n++;
    if(Datum.godina[0]<'2')
        n++;
    if(Datum.godina[0]=='2' && Datum.godina[1]>'0')
        n++;
    if(Datum.godina[0]=='2' && Datum.godina[1]=='0' && Datum.godina[2]>'1')
        n++;
    if(Datum.godina[0]=='2' && Datum.godina[1]=='0' && Datum.godina[2]=='1' && Datum.godina[3]<'9')
        n++;
    if(Datum.mesec[0]=='0' && Datum.mesec[1]=='2' && Datum.dan[0]=='2' && Datum.dan[1]>'8')
        n++;
    if(Datum.mesec[1]=='4' || Datum.mesec[1]=='6' || Datum.mesec[1]=='9' || (Datum.mesec[0]=='1' && Datum.mesec[1]=='1')){
        if(Datum.dan[0]=='3' && Datum.dan[1]>'0')
            n++;
    }
    if(Datum.mesec[1]=='7' || Datum.mesec[1]=='8')
        ++n;
    if(n==0)
        return 1;
    else
        return 0;
}
int proveraTelefon(char tel[20]){
    int n=0;
    int i=0;
    while(tel[i]!='\0'){
        if(tel[i]<'0' || tel[i]>'9'){
            n++;
        }
        if(tel[i]==32)  //Ovo je space
            --n;
        ++i;
    }
    if(n==0)
        return 1;
    else
        return 0;
}
int izborUcenika(){
    int izbor;
    do{
    printf("Ako zelite da pretrazite ucenika po imenu pritisnite 1, a ako zelite po jmbgu, pritisnite 2:");
    scanf("%i",&izbor);
    if(izbor<1 || izbor>2)
        printf("Nepostojeca opcija! Pokusajte ponovo:\n");
    }while(izbor<1 || izbor>2);
    return izbor;
}
int brojUcenika(FILE*ucenici,int r,char ime[30],int n,int j){
        char linija[50];
        int broj=0;
        int i=1,l=0,d=0,s=0,k=0;
        fseek(ucenici,0,SEEK_SET);
        while(i<r*10){
            fgets(linija,50,ucenici);
            if(j!=0 && (j-1)*10+2==i){
                ++i;
                continue;
            }
            if(i%10==1){
                    l=0;
                if(s==1)
                    s=0;
            }
            if(i%10==n){
                    d=0;
                if(uporedjivanjeStringa(ime,linija))
                   d=0;
                else
                   d=5;
                 if(s>=1)
                    s=0;
                 if(d==0)
                    s=1;
            }
            if(d==0 && s==1){
                    broj=((i-2)/10)+1;
                    return broj;
            }
            ++i;
        }
        if(broj==0)
            return 0;
}
int istoIme(FILE*ucenici,int r){
    ucenici=fopen("ucenici.txt","r");
    FILE*izmena=fopen("izmenica.txt","w");
    char linija[50],lajna[50];
    int g=1,n=1,k=0,d=0;
    char ime[20];
    while(g<=r*10){
        fgets(linija,50,ucenici);
        if(g%10==2)
        fputs(linija,izmena);
        ++g;
    }
    g=1;
    fclose(izmena);
    izmena=fopen("izmenica.txt","r");
    fseek(ucenici,0,SEEK_SET);
    while(g<=r*10){
        fgets(linija,50,ucenici);
        if(g%10==2){
            while(n<=r){
                fgets(lajna,50,izmena);
                if((n-1)!=(g/10)){
                int i=0;
                d=0;
                while(lajna[i]!='\0'){
                    if(lajna[i]!=linija[i])
                        ++d;
                    ++i;
                }
                if(d==0)
                    k=1;
                }
                ++n;
            }
            fseek(izmena,0,SEEK_SET);
            n=1;
        }
        ++g;
    }
    return k;
    fclose(ucenici);
    fclose(izmena);
    remove("izmenica.txt");
}
void dodavanje(FILE*ucenici, int*r){
    ucenik neko;
    printf("Dodajte ucenika:\n");
     printf("Unesite ime ucenika: ");
     fflush(stdin);
     gets(neko.ime);
     printf("Unesite prezime ucenika: ");
     gets(neko.prezime);
     do{
     printf("Unesite broj telefona ucenika: ");
     gets(neko.brojTelefona);
     if(proveraTelefon(neko.brojTelefona)==0)
        printf("Uneseni karakteri nisu cifre! Pokusajte ponovo:\n");
     }while(!(proveraTelefon(neko.brojTelefona)));
     do{
     printf("Unesite datum rodjenja ucenika:\n");
     printf("Dan: ");
     gets(neko.rodjenje.dan);
     printf("Mesec: ");
     gets(neko.rodjenje.mesec);
     printf("Godina: ");
     gets(neko.rodjenje.godina);
     if(proveraDatum(neko.rodjenje)==0)
        printf("Nepostojeci datum ili ucenik nije u uzrastu u kom moze da ide u skolu! Pokusajte ponovo:\n");
     }while(!(proveraDatum(neko.rodjenje)));
     do{
        printf("Unesite JMBG ucenika: ");
        gets(neko.jmbg);
        if(proveraJMBG(ucenici,*r,neko.jmbg,neko.rodjenje)==0)
            printf("Netacan JMBG! Pokusajte ponovo:\n");
     }while(!(proveraJMBG(ucenici,*r,neko.jmbg,neko.rodjenje)));
     printf("Unesite adresu stanovanja:\n");
     printf("Pun naziv ulice: ");
     gets(neko.stanovanje.ulica);
     printf("Broj ulice: ");
     scanf("%i",&neko.stanovanje.broj);
     ucenici=fopen("ucenici.txt","a");
     fprintf(ucenici,"%i.\n%s %s\n%s.%s.%s\n%s\n%s %i\n%s\n\n\n\n\n",*r+1,neko.ime,neko.prezime,neko.rodjenje.dan,neko.rodjenje.mesec,neko.rodjenje.godina,neko.jmbg,neko.stanovanje.ulica,neko.stanovanje.broj,neko.brojTelefona);
     fclose(ucenici);
     *r+=1;
}
void prikazSvih(FILE*ucenici, int r){
     char linija[60];
     ucenici=fopen("ucenici.txt","r");
     int i=1;
     if(r==0){
        printf("Nema ubelezenih ucenika!");
     }
     while(i<=r*10){
        fgets(linija,60,ucenici);
        printf("%s",linija);
        ++i;
     }
     fclose(ucenici);
}
void pretragaNaloga(FILE*ucenici, int r){
    int izbor=izborUcenika();
    int n=0;
    ucenici=fopen("ucenici.txt","r");
    int broj=0;
    char ime[30];
    int bru=istoIme(ucenici,r);
    if(izbor==1){
        n=2;
        printf("Unesite ime i prezime ucenika:");
        fflush(stdin);
        gets(ime);
        broj=brojUcenika(ucenici,r,ime,n,0);
    }
    if(izbor==2){
        n=4;
        printf("Unesite jmbg ucenika:");
        fflush(stdin);
        gets(ime);
        broj=brojUcenika(ucenici,r,ime,n,0);
    }
    if(broj>0){
        fseek(ucenici,0,SEEK_SET);
        char lajna[50];
        int i=1;
        while(i<r*10){
        fgets(lajna,50,ucenici);
        if(i>(broj-1)*10 && i<=broj*10)
            printf("%s",lajna);
        ++i;
     }
     }
    else
        printf("Ne postoji takav ucenik!");
    if(bru){
        broj=brojUcenika(ucenici,r,ime,n,broj);
        fseek(ucenici,0,SEEK_SET);
        char lajna[50];
        int i=1;
        while(i<r*10){
        fgets(lajna,50,ucenici);
        if(i>(broj-1)*10 && i<=broj*10)
            printf("%s",lajna);
        ++i;
     }
    }
     fclose(ucenici);
}
void izmenaNaloga(FILE*ucenici, int r){
    int izbor=izborUcenika();
    int n=0;
    ucenici=fopen("ucenici.txt","r");
    int broj=0;
    if(izbor==1){
        n=2;
        char ime[30];
        printf("Unesite ime i prezime ucenika:");
        fflush(stdin);
        gets(ime);
        broj=brojUcenika(ucenici,r,ime,n,0);
    }
    if(izbor==2){
        n=4;
        char ime[30];
        printf("Unesite jmbg ucenika:");
        fflush(stdin);
        gets(ime);
        broj=brojUcenika(ucenici,r,ime,n,0);
    }
    if(broj>0){
        printf("Unesite sta zelite da izmenite kod ucenika(1-Ime i prezime,2-Datum rodjenja,3-JMBG,4-Adresa stanovanja,5-Broj telefona)");
        int iz,q;
        datum Datum;
        char novo[50];
        FILE*izmena=fopen("nebitno.txt","w+");
        scanf("%i",&iz);
        fseek(ucenici,0,SEEK_SET);
        char lajna[50];
        switch(iz){
        case 1:
        printf("Unesite novo ime i prezime:");
        fflush(stdin);
        gets(novo);
        int g=1;
        while(g<=r*10){
            fgets(lajna,50,ucenici);
            if(g==(((broj-1)*10)+2)){
                fprintf(izmena,"%s\n",novo);
            }
            else{
            fputs(lajna,izmena);
            }
            ++g;
        }
        fclose(izmena);
        break;
        case 2:
        do{
        printf("Unesite nov datum rodjenja:\n");
        printf("Unesite dan:");
        fflush(stdin);
        gets(Datum.dan);
        printf("Unesite mesec:");
        gets(Datum.mesec);
        printf("Unesite godinu:");
        gets(Datum.godina);
        if(proveraDatum(Datum)==0)
        printf("Nepostojeci datum ili ucenik nije u uzrastu u kom moze da ide u skolu! Pokusajte ponovo:\n");
        }while(!(proveraDatum(Datum)));
        g=1;
        while(g<=r*10){
            fgets(lajna,50,ucenici);
            if(g==(((broj-1)*10)+3)){
                fprintf(izmena,"%s.%s.%s\n",Datum.dan,Datum.mesec,Datum.godina);
            }
            else{
            fputs(lajna,izmena);
            }
            ++g;
        }
        fclose(izmena);
        break;
        case 3:
        g=1;
        while(g<=r*10){
            fgets(lajna,50,ucenici);
            if(g==((broj-1)*10+3)){
            int cc=0;
            Datum.dan[0]=lajna[cc];
            cc+=1;
            Datum.dan[1]=lajna[cc];
            if(lajna[cc]=='.'){
                Datum.dan[1]=Datum.dan[0];
                Datum.dan[0]='0';
                cc+=1;
            }
            else
            cc+=2;
            Datum.mesec[0]=lajna[cc];
            cc+=1;
            Datum.mesec[1]=lajna[cc];
            if(lajna[cc]=='.'){
                Datum.mesec[1]=Datum.mesec[0];
                Datum.mesec[0]='0';
                cc+=1;
            }
            else
            cc+=2;
            Datum.godina[0]=lajna[cc];
            cc+=1;
            Datum.godina[1]=lajna[cc];
            cc+=1;
            Datum.godina[2]=lajna[cc];
            cc+=1;
            Datum.godina[3]=lajna[cc];
            }
            ++g;
        }
        g=1;
        do{
        printf("Unesite nov JMBG:");
        fflush(stdin);
        gets(novo);
        if(proveraJMBG(ucenici,r,novo,Datum)==0)
            printf("Netacan JMBG! Pokusajte ponovo:\n");
        }while(!(proveraJMBG(ucenici,r,novo,Datum)));
        fseek(ucenici,0,SEEK_SET);
        while(g<=r*10){
            fgets(lajna,50,ucenici);
            if(g==(((broj-1)*10)+4)){
                fprintf(izmena,"%s\n",novo);
            }
            else{
            fputs(lajna,izmena);
            }
            ++g;
        }
        fclose(izmena);
        break;
        case 4:
        printf("Unesite novu adresu stanovanja:\n");
        printf("Unesite pun naziv ulice:");
        fflush(stdin);
        gets(novo);
        printf("Unesite broj:");
        scanf("%i",&q);
        g=1;
        while(g<=r*10){
            fgets(lajna,50,ucenici);
            if(g==(((broj-1)*10)+5)){
                fprintf(izmena,"%s %i\n",novo,q);
            }
            else{
            fputs(lajna,izmena);
            }
            ++g;
        }
        fclose(izmena);
        break;
        case 5:
        printf("Unesite nov broj telefona:");
        fflush(stdin);
        gets(novo);
        g=1;
        while(g<=r*10){
            fgets(lajna,50,ucenici);
            if(g==(((broj-1)*10)+6)){
                fprintf(izmena,"%s\n",novo);
            }
            else{
            fputs(lajna,izmena);
            }
            ++g;
        }
        fclose(izmena);
     }
    }
    else
        printf("Ne postoji takav ucenik!");
     fclose(ucenici);
     remove("ucenici.txt");
     rename("nebitno.txt","ucenici.txt");
}
void brisanjeNaloga(FILE*ucenici, int*r){
    int izbor=izborUcenika();
    int n=0;
    ucenici=fopen("ucenici.txt","r");
    int broj=0;
    if(izbor==1){
        n=2;
        char ime[30];
        printf("Unesite ime i prezime ucenika:");
        fflush(stdin);
        gets(ime);
        broj=brojUcenika(ucenici,*r,ime,n,0);
    }
    if(izbor==2){
        n=4;
        char ime[30];
        printf("Unesite jmbg ucenika:");
        fflush(stdin);
        gets(ime);
        broj=brojUcenika(ucenici,*r,ime,n,0);
    }
    if(broj>0){
            char linija[50];
            fseek(ucenici,0,SEEK_SET);
            FILE*izmena=fopen("izmena.txt","w");
            int g=1,o=*r;
            while(g<=*r*10){
                fgets(linija,50,ucenici);
                if(g<=(broj-1)*10 || g>broj*10){
                    if(g>=broj*10 && g%10==1){
                            if(g==1){
                                fprintf(izmena,"\n");
                            }
                            fprintf(izmena,"%i.\n",o);
                    }
                    else
                    fputs(linija,izmena);
                }
                if(g==broj*10){
                        --o;
                    }
                ++g;
            }
            fclose(ucenici);
            g=1;
            fclose(ucenici);
            fclose(izmena);
            remove("ucenici.txt");
            rename("izmena.txt","ucenici.txt");
            *r-=1;
    }
    else{
        printf("Ne postoji takav ucenik!");
        fclose(ucenici);
}
}
void ocenjivanje(FILE*ucenici, int r){
    int izbor=izborUcenika();
    int n=0;
    ucenici=fopen("ucenici.txt","r");
    int broj=0;
    FILE*izmena=fopen("izmena.txt","w");
    if(izbor==1){
        n=2;
        char ime[30];
        printf("Unesite ime i prezime ucenika:");
        fflush(stdin);
        gets(ime);
        broj=brojUcenika(ucenici,r,ime,n,0);
    }
    if(izbor==2){
        n=4;
        char ime[30];
        printf("Unesite jmbg ucenika:");
        fflush(stdin);
        gets(ime);
        broj=brojUcenika(ucenici,r,ime,n,0);
    }
    if(broj>0){
        ocena Ocena;
        do{
        printf("Unesite vrednost ocene: ");
        scanf("%i",&Ocena.vrednost);
        if(Ocena.vrednost>5 || Ocena.vrednost<1)
            printf("Nepostojeca vrednost(vrednosti mogu biti od 1 do 5)! Pokusajte ponovo:\n");
        }while(Ocena.vrednost>5 || Ocena.vrednost<1);
        int ni=1;
        do{
        printf("Unesite tip ocene(usmeni, pismeni ili aktivnost): ");
        scanf("%s",Ocena.tip);
        int ji=0,ko=0;
        char usmeni[15]="usmeni";
        while(usmeni[ji]!='\0'){
            if(Ocena.tip[ji]!=usmeni[ji])
                ++ko;
                ++ji;
        }
        if(ko==0)
            ni=0;
        ji=0,ko=0;
        char pismeni[15]="pismeni";
        while(pismeni[ji]!='\0'){
            if(Ocena.tip[ji]!=pismeni[ji])
                ++ko;
                ++ji;
        }
        if(ko==0)
            ni=0;
        ji=0,ko=0;
        char aktivnost[15]="aktivnost";
        while(aktivnost[ji]!='\0'){
            if(Ocena.tip[ji]!=aktivnost[ji])
                ++ko;
                ++ji;
        }
        if(ko==0)
            ni=0;
        if(ni==1)
            printf("Nepostojeci tip! Pokusajte ponovo:\n");
        }while(ni==1);
        do{
        printf("Unesite datum ocene:\n");
        printf("Dan:");
        scanf("%s",Ocena.docene.dan);
        printf("Mesec: ");
        scanf("%s",Ocena.docene.mesec);
        printf("Godina: ");
        scanf("%s",Ocena.docene.godina);
        if(proveraDatumaOcene(Ocena.docene)==0)
            printf("Nepostojeci datum! Pokusajte ponovo:\n");
        }while(!proveraDatumaOcene(Ocena.docene));
        fseek(ucenici,0,SEEK_SET);
        int pr=1;
        char linijica[50];
        while(pr<=r*10){
            fgets(linijica,50,ucenici);
            if(pr==(((broj-1)*10)+7))
                fprintf(izmena,"%i %s",Ocena.vrednost,linijica);
            else if(pr==(((broj-1)*10)+8))
                fprintf(izmena,"%s %s",Ocena.tip,linijica);
            else if(pr==(((broj-1)*10)+9))
                fprintf(izmena,"%s.%s.%s %s",Ocena.docene.dan,Ocena.docene.mesec,Ocena.docene.godina,linijica);
            else
                fputs(linijica,izmena);
            ++pr;
        }
    }
    else
        printf("Ne postoji takav ucenik!");
    fclose(izmena);
    fclose(ucenici);
    remove("ucenici.txt");
    rename("izmena.txt","ucenici.txt");
}
void preporuka(FILE*ucenici, int r){
    int izbor=izborUcenika();
    int n=0;
    ucenici=fopen("ucenici.txt","r");
    int broj=0;
    if(izbor==1){
        n=2;
        char ime[30];
        printf("Unesite ime i prezime ucenika:");
        fflush(stdin);
        gets(ime);
        broj=brojUcenika(ucenici,r,ime,n,0);
    }
    if(izbor==2){
        n=4;
        char ime[30];
        printf("Unesite jmbg ucenika:");
        fflush(stdin);
        gets(ime);
        broj=brojUcenika(ucenici,r,ime,n,0);
    }
    if(broj>0){
        fseek(ucenici,0,SEEK_SET);
        int pr=1;
        char linijica[50];
        float brojOcena=0,ukupno=0,pism=0;
        while(pr<=r*10){
            fgets(linijica,50,ucenici);
            if(pr==(((broj-1)*10)+7)){
                int oi=0;
                while(linijica[oi+1]!='\0'){
                        if(oi%2==0){
                            ukupno+=linijica[oi]-'0';
                            brojOcena+=1;
                        }
                        ++oi;
                }
            }
            if(pr==(((broj-1)*10)+8)){
                int oi=0;
                while(linijica[oi]!='\0'){
                    if(linijica[oi]=='p')
                        pism=1;
                    ++oi;
                }
            }
            ++pr;
        }
        if(pism==1 && brojOcena>=3){
            int zakljucnaOcena=1;
            if(ukupno/brojOcena>=1.5)
                zakljucnaOcena=2;
            if(ukupno/brojOcena>=2.5)
                zakljucnaOcena=3;
            if(ukupno/brojOcena>=3.5)
                zakljucnaOcena=4;
            if(ukupno/brojOcena>=4.5)
                zakljucnaOcena=5;
            printf("Predlog zakljucne ocene je: %i\n",zakljucnaOcena);
        }
        else
            printf("Ucenik ne zadovoljava uslove potrebne za zakljucnu ocenu!\n");
    }
    else
        printf("Ne postoji takav ucenik!");
    fclose(ucenici);
}

int main()
{
    FILE*ucenici;
    FILE*uk;
    int c;
    uk=fopen("ukupno.txt","r");
    fscanf(uk,"%i",&c);
    fclose(uk);
    if(c>10000)
        c=0;
    printf("Dobro dosli u elektronski dnevnik!\n");
    int n=0;
    do{
        n=meni();
        switch(n){
    case 1:
        dodavanje(ucenici,&c);
        break;
    case 2:
        prikazSvih(ucenici,c);
        break;
    case 3:
        pretragaNaloga(ucenici,c);
        break;
    case 4:
        izmenaNaloga(ucenici,c);
        break;
    case 5:
        brisanjeNaloga(ucenici,&c);
        break;
    case 6:
        ocenjivanje(ucenici,c);
        break;
    case 7:
        preporuka(ucenici,c);
        break;
    printf("%i",c);
        }
    }while(n!=8);
        uk=fopen("ukupno.txt","w");
        fprintf(uk,"%i",c);
        fclose(uk);
    printf("Hvala na koriscenju! Nadam se da sam bio koristan :)");
    return 0;
}
