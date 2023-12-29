#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct voyageur
{
    int cin;
    char nom[50];
    char prenom[50];
    char email[60];
};

char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
char ch[10][130]={"Zina bus","Aziza bus","Aphrodite bus","Achille bus","Atalante bus"};
int bus_num;

void read_name(int bus_num);
void booking();
void welcome();
void create_account();
void bus();
void status_1();
void annuler();
void name_number(int booking,char numstr[100]);
int read_number(int bus_num);
void booking_status();

int main()
{
	welcome();
    int num;
    do{
    system("cls");
    printf("\n\n\n");
    printf("====================================== SYSTEME RESERVATION DES BUS ======================================\n\n\n");
    printf("\t\t\t\t\t[1]=> Creer un nouveau compte\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> Nouvelle reservation\n");
    printf("\n");
    printf("\t\t\t\t\t[3]=> Afficher les details des bus\n");
    printf("\n");
    printf("\t\t\t\t\t[4]=> Afficher les details des reservation\n");
    printf("\n");
    printf("\t\t\t\t\t[5]=> Annuler une reservation\n");
    printf("\n");
    printf("\t\t\t\t\t[6]=> Exit\n\n");
    printf("===============================================================================================================\n\n");
    while (1)
    {
        printf("\t\t\tTapez votre choix ici:: ");
        scanf("%d",&num);
        if(num>=1 && num<=6) break;
        else {
            printf("\t\t\tChoix non valide!");
        }
    }
    switch(num)
    {
    case 1:
        create_account();//pour creer un compte
        break;
    case 2:
        booking();//reservation
        break;
    case 3:
       bus();//pour les details des bus
        break;
    case 4:
        booking_status();
        break;
    case 5:
        annuler();
        break;
    
    }
    getch();
    }
    while(num != 6);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tMerci pour Utiliser E-Bus-Travel\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    getch();
    return 0;
}
void booking_status(){
    system("cls");
    printf("=========================================== DETAILS RESERVATION ============================================\n\n\n");
    int i,bus_num,index=0,j;
    printf("Entrez le nombre de bus:---->");
    scanf("%d",&bus_num);
    j=read_number(bus_num);
    read_name(bus_num);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n",bus_num,ch[bus_num-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}

void read_name(int bus_num)//pour mettre la valeur numerique dans le tableau
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(bus_num,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//pour ouvrir le fichier et ecrire le nom 
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

void name_number(int booking,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");
   b = fopen(tempstr2,"a");
for(i=0; i<booking; i++)
{
    printf("============================Enter les details de ticket no %d============================\n\n\n",i+1);
      printf("\t\t\t\tEntrez le nombre de place:--->");
      scanf("%d",&number);
      printf("\t\t\t\tEntrez le nom de la personne:--->");
      scanf("%s",name[number-1]);
    printf("\n======================================================================================================\n\n");
    printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}


int read_number(int bus_num)//pour mettre la valeur numerique dans le tableau
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(bus_num,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//pour ouvrir le fichier et ecrire le nom
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}

void annuler(){int seat_no,i,j;
 char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
 printf("Entrez le nombre se bus:---->");
 scanf("%d",&bus_num);
 itoa(bus_num,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 read_number(bus_num);
 read_name(bus_num);
 status_1(bus_num);
 printf("Entrez le nombre de place--->");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempstr1,"w+");
 b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"vide ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\tVotre argent a ete rembourse\t\t\t\n");
    printf("======================================================================================================\n");
}

void status_1(int bus_num)
{
    printf("votre nombre de bus est %d ********** %s",bus_num,ch[bus_num-1]);
    system("cls");
    printf("=========================================== RESERVATION ============================================\n\n\n");
    int i,index=0,j;
    j=read_number(bus_num);
    read_name(bus_num);
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
        {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
        }
        printf("\n");
    }
}

void booking(){
    
int i=0;
char numstr[100];
system("cls");
printf("=========================================== RESERVATION ============================================\n\n\n");
bus();
printf("Entrez le numero de bus:--->");
scanf("%d",&bus_num);
system("cls");
printf("=========================================== RESERVATION ============================================\n\n\n");
printf("votre numero de bus est %d ********** %s",bus_num,ch[bus_num-1]);
status_1(bus_num);
 FILE *f1, *fopen();
 char str1[80]="32",str2[4],str3[4];
 int seat1,seat2,booking=0;
if(bus_num == 1)
{
 f1 = fopen("tr1.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(bus_num == 2)
{
 f1 = fopen("tr2.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(bus_num == 3)
{
 f1 = fopen("tr3.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(bus_num == 4)
{
 f1 = fopen("tr4.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(bus_num == 5)
{
 f1 = fopen("tr5.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
seat1=atoi(str1);
if(seat1 <= 0)
{
 printf("Il n'y a pas de place! ");
}else
{
printf("\n\n\n\t\t\t\tPlaces valables:------>%d\n",seat1);
printf("\n\t\t\t\tNombre des Tickets:----->");
scanf("%d",&booking);
printf("\n");

seat1=seat1-booking;
itoa(bus_num,numstr,10);
name_number(booking,numstr);
printf("\n\t\t\t\tLe montant total de reservation est %d",2*booking);
itoa(seat1, str1, 10);
//pour lire les places 
if(bus_num == 1)
{
 f1 = fopen("tr1.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
else if(bus_num == 2)
{
 f1 = fopen("tr2.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(bus_num == 3)
{
 f1 = fopen("tr3.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(bus_num == 4)
{
 f1 = fopen("tr4.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(bus_num == 5)
{
 f1 = fopen("tr5.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
}

}

void welcome()
{
	system("cls");
    printf("\n  =========================  BIENVENUE CHEZ E-Bus-Travel ^o^ =========================  ");
	printf("\n\n\n\n\n\n\t\t\t\t        Appuyez sur n'importe quelle touche pour continuer...");
	getch();//holds the screen
	
}

void create_account(){
    
    struct voyageur v;
    FILE *file;

    system("cls");
    printf("\n\n\n");
    printf("=========================================== Compte ============================================\n\n\n");
    printf("\n\n\n");
    printf("\t\t\t\t\tDonnez votre C.I.N : ");
    scanf("%d",&v.cin);
    printf("\n\n");
    printf("\t\t\t\t\tDonnez votre Nom : ");
    scanf("%s",&v.nom);
    printf("\n\n");
    printf("\t\t\t\t\tDonnez votre Prenom : ");
    scanf("%s",&v.prenom);
    printf("\n\n");
    printf("\t\t\t\t\tDonnez votre Adresse E-mail : ");
    scanf("%s",&v.email);

    file = fopen("compte.txt","a");
    fwrite(&v , sizeof(v),1,file);
    if(fwrite) printf("\n\n\t\t\t\t\tcompte cree avec succes!!");
    fclose(file);


}

void bus()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================== Liste des BUS ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n"); 
	printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n"); 
	printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n"); 
	printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);
    printf("\nTous les bus ont une capacite de 32 places en total, offrant un confort optimal\n\n\n\t\t\t\t ");
}