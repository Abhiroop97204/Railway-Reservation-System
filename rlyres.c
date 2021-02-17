#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include "conio2.h"
#include "rlyres.h"
int enterchoice()
{

    int choice,i;
    textcolor(LIGHTCYAN);
    gotoxy(28,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("-");
    printf("\nSelect an option");
    printf("\n\n1 --> View Trains");
    printf("\n2 --> Book Ticket");
    printf("\n3 --> View Ticket");
    printf("\n4 --> Search Ticket No");
    printf("\n5 --> View All Bookings");
    printf("\n6 --> View Train Bookings");
    printf("\n7 --> Cancel Ticket");
    printf("\n8 --> Cancel Train");
    printf("\n9 --> Quit");
    printf("\n\nEnter choice:");
    scanf("%d",&choice);
    return choice;

}
void add_trains()
{
    Train alltrains[4]={
              {"123","BPL","GWA",2100,1500},
              {"546","BPL","DEL",3500,2240},
              {"345","HBJ","AGR",1560,1135},
              {"896","HBJ","MUM",4500,3360},
              };
    FILE *fp=fopen("D:\\data drive e\\MyProjectFiles\\alltrains.dat","rb");
    if(fp==NULL)
    {
        fp=fopen("D:\\data drive e\\MyProjectFiles\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
        //printf("File created and saved!\n");

    }
    else
        //printf("File already present\n");
        fclose(fp);

}
void view_trains()
{
    int i;
    printf("\n\nTRAIN NO\tFROM\tTO\tFIRST AC FARE\tSECOND AC FARE\n");
     for(i=1;i<=80;i++)
        printf("-");
    FILE *fp=fopen("D:\\data drive e\\MyProjectFiles\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        printf("\n%s\t\t%s\t%s\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);

    }
    printf("\n\n\n\n");
    fclose(fp);
}
int check_train_no(char *trainno)
{
    FILE *fp=fopen("D:\\data drive e\\MyProjectFiles\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
          if(strcmp(tr.train_no,trainno)==0)
          {
                  fclose(fp);
                  return 1;
          }

    }
fclose(fp);
return 0;
}
int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
    {
        return 0;
    }
    while(*p_mob!='\0')
    {
        if(isdigit(*p_mob)==0)
            return 0;
        p_mob++;
    }
    return 1;
}
Passenger *get_passenger_details()
{
    clrscr();
    gotoxy(61,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit !");
    gotoxy(1,1);
    textcolor(LIGHTCYAN);
    static Passenger psn;
    printf("Enter passenger name:");
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Reservation cancelled !");
        getch();
        textcolor(LIGHTCYAN);
        clrscr();
        return NULL;

    }
    int valid;
    printf("Enter gender(M/F):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
        {
             textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation cancelled !");
            getch();
            textcolor(CYAN);
            clrscr();
            return NULL;
        }
        if(psn.gender!='M'&&psn.gender!='F')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Gender should be M or F (in uppercase) !");
            valid=0;
            getch();
            gotoxy(19,2);
            printf(" \b");
            textcolor(CYAN);

        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,3);
    printf("Enter train number:");
    do
    {
        fflush(stdin);
        scanf("%s",psn.train_no);
        if(strcmp(psn.train_no,"0")==0)
       {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation cancelled !");
        getch();
        textcolor(CYAN);
        clrscr();
        return NULL;
        }
     valid=check_train_no(psn.train_no);
     if(valid==0)
           {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("invalid Train Number !");
            getch();
            gotoxy(20,3);
            printf(" \t\t\t\t\t\t");
            gotoxy(20,3);
            textcolor(CYAN);

            }
     }while (valid==0);
     gotoxy(1,25);
     printf(" \t\t\t\t\t\t");
     gotoxy(1,4);
     printf("Enter travelling class(First AC:F, Second AC:S):");
     do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.p_class);
        if(psn.p_class=='0')
        {
             textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation cancelled !");
            getch();
            textcolor(CYAN);
            //clrscr();
            return NULL;
        }
        if(psn.p_class!='F' && psn.p_class!='S')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("It should F or S!");
            valid=0;
            getch();
            gotoxy(49,4);
            printf(" \b");
            textcolor(CYAN);
            //return NULL;

         }
    }
     while (valid==0);
     gotoxy(1,25);
     printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
     gotoxy(1,5);
     printf("Enter Address:");
     fflush(stdin);
     fgets(psn.address,20,stdin);
     pos=strchr(psn.address,'\n');
     *pos='\0';
     if(strcmp(psn.address,"0")==0)
       {
        textcolor(LIGHTRED);
         gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Invalid Address, booking cannot be done!");
        getch();
        textcolor(CYAN);
        //clrscr();
        return NULL;
       }
    printf("Enter age:");
    do
    {
            valid=1;
            fflush(stdin);
            scanf("%d",&psn.age);
            if(psn.age==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled! Entered Zero");
                getch();
                textcolor(CYAN);
                return NULL;
            }



         if(psn.age<=0)
            {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error! Age should be positive");
            valid=0;
            getch();
            gotoxy(11,6);
            printf("\t\t\t\t\t\t\t");
            gotoxy(11,6);
            textcolor(CYAN);
            return NULL;
            }
    }       while(valid==0);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,7);
            printf("Enter mobile number:");
            do
            {
                fflush(stdin);
                fgets(psn.mob_no,12,stdin);
                pos=strchr(psn.mob_no,'\n');
                if(pos!=NULL)
                    *pos='\0';
                if (strcmp(psn.mob_no,"0")==0)
                {
                    textcolor(LIGHTRED);
                    gotoxy(1,25);
                    printf("\t\t\t\t\t\t\t");
                    gotoxy(1,25);
                    printf("Reservation Cancelled! Entered Zero");
                    getch();
                    textcolor(CYAN);
                    return NULL;
                 }
                 valid=check_mob_no(psn.mob_no);
                 if(valid==0)
                 {
                        textcolor(LIGHTRED);
                        gotoxy(1,25);
                        printf("invalid Mobile Number !");
                        getch();
                        gotoxy(21,7);
                        printf(" \t\t\t\t\t\t\t\t\t\t");
                        gotoxy(21,7);
                        textcolor(CYAN);
                        return NULL;

                 }

             }while(valid==0);
             return &psn;
}
int get_booked_ticket_count(char *train_no, char tc)
{
    FILE *fp=fopen("D:\\data drive e\\MyProjectFiles\\allbookings.dat","rb");
    if(fp==NULL)
        return 0;
    Passenger pr;
    int count = 0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no, train_no)==0 && pr.p_class==tc)
            ++count;

    }
    fclose(fp);
    return count;
}
int last_ticket()
{
    FILE *fp=fopen("D:\\data drive e\\MyProjectFiles\\allbookings.dat","rb");
    if(fp==NULL)
        return 0;
    Passenger pr;
    fseek(fp,-1L*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;
}
int book_ticket(Passenger p)
{
    int ticket_count=get_booked_ticket_count(p.train_no, p.p_class);
    if(ticket_count==30)
    {
        textcolor(LIGHTRED);
        printf("All seats in train number %s in class %c are full",p.train_no,p.p_class);
        return -1;
    }
    int ticket_no=last_ticket()+1;
    p.ticketno=ticket_no;
    FILE *fp=fopen("D:\\data drive e\\MyProjectFiles\\allbookings.dat","ab");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("File cannot be open");
        return -1;

    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}

int accept_ticket_no()
{
    //printf("Enter ticket number:");
    int valid;
    int ticket_no;
    printf("Enter ticket number:");
    do
    {
        valid=1;
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Cancelling Input !");
            getch();
            textcolor(CYAN);
            clrscr();
            return NULL;
        }
        if(ticket_no<0)
        {
                        textcolor(LIGHTRED);
                        gotoxy(1,25);
                        printf("invalid Ticket Number !");
                        getch();
                        valid=0;
                        gotoxy(24,1);
                        printf(" \t\t\t\t\t\t\t\t\t\t");
                        gotoxy(24,1);
                        textcolor(CYAN);
                        return NULL;
        }

    }
    while(valid==0);
    return ticket_no;
}

void view_ticket(int ticket_no)
{
    FILE *fp=fopen("D:\\data drive e\\MyProjectFiles\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("File cannot be open");
        return;
    }
    Passenger pr;
    int found = 0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticketno==ticket_no)
        {
            printf("\nNAME      :%s\nGENDER    :%c\nTRAIN NO  :%s\nCLASS     :%c\nADDRRESS  :%s\nAGE       :%d\nMOBILE NO :%s\nTICKET NO :%d\n",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticketno);
            found =1;
            break;
        }
    }
    if(!found)
    {
        textcolor(LIGHTRED);
        printf("\nNo details found");
        return NULL;

    }
    fclose(fp);
}

char *accept_mob_no()
{
    static char mob_no[13];
    char *pos;
    int valid;
    printf("Enter valid mobile number:");
    do
    {
        fflush(stdin);
        fgets(mob_no,13,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        if(strcmp(mob_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Cancelling Input....");
            getch();
            textcolor(CYAN);
            clrscr();
            return NULL;
        }
        valid=check_mob_no(mob_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Invalid Mobile Number !");
            getch();
            gotoxy(27,7);
            printf(" \t\t\t\t\t\t\t\t\t\t");
            gotoxy(27,7);
            textcolor(CYAN);
            return NULL;
        }
    }
    while(valid==0);
    clrscr();
    return mob_no;
}
int *get_ticket_no(char *p_mob_no)
{
    int count = 0;
    FILE *fp=fopen("D:\\data drive e\\MyProjectFiles\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("File cannot be open");
        return NULL;
    }
    Passenger pr;
   while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
            ++count;
   }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int *p=(int*)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
      {
          *(p+i)=pr.ticketno;
            i++;
      }
    }
        *(p+i)=-1;
        fclose(fp);
        return p;
}

void view_all_tickets(char *pmob_no,int *pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! No tickets booked against mobile no %s",pmob_no);
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the main screen");
        textcolor(CYAN);
        getch();
        return;
    }
    printf("Following are tickets booked for mobile no %s",pmob_no);
    int i;
    printf("\n\nTICKET NO\n");
    for(i=1;i<=80;i++)
        printf("-");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));
textcolor(WHITE);
printf("\n\nPress any key to go back to the main screen");
textcolor(CYAN);
getch();
}
char* accept_train_no()
{
    static train_no[10];
    int valid;
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(LIGHTCYAN);
    printf("Enter train number:");
    do
    {
        fflush(stdin);
        scanf("%s",train_no);
        if(strcmp(train_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Canceling Input");
            getch();
            textcolor(LIGHTBLUE);
            return NULL;
        }
        valid=check_train_no(train_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Invalid Train Number !");
            getch();
            gotoxy(20,1);
            printf(" \t\t\t\t\t\t\t\t\t\t");
            gotoxy(20,1);
            textcolor(LIGHTCYAN);
            return NULL;
        }
    }while (valid==0);
    clrscr();
    return train_no;
}

void view_booking(char* train_no)
{
    int found = 0;
    FILE *fp=fopen("D:\\data drive e\\MyProjectFiles\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("File cannot be open");
        return;
    }
    Passenger pr;
    printf("TICKET NUMBER\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NUMBER");
    printf("\n--------------------------------------------------------------------------------");
    int row = 3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no, train_no)==0)
        {
            printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
            row++;
            found=1;
        }
    }
    if(!found)
    {
        clrscr();
        textcolor(LIGHTRED);
        printf("\nNo train details found");


    }
    textcolor(WHITE);
    printf("Press any key to return main");
    textcolor(LIGHTCYAN);
    getch();
    fclose(fp);


}

int cancel_ticket(int ticket_no)
{
    FILE *fp1=fopen("D:\\data drive e\\MyProjectFiles\\allbookings.dat","rb");
    if (fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet!");
        return -1;

    }
    FILE *fp2=fopen("D:\\data drive e\\MyProjectFiles\\temp.dat","wb");
    Passenger pr;
    int found = 0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticketno==ticket_no)
        {
            found=1;

        }
        else
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("D:\\data drive e\\MyProjectFiles\\temp.dat");

    }
    else
    {
         remove("D:\\data drive e\\MyProjectFiles\\allbookings.dat");
         rename("D:\\data drive e\\MyProjectFiles\\temp.dat","D:\\data drive e\\MyProjectFiles\\allbookings.dat");
    }
    return found;
}

void view_all_bookings()
{
    printf("TICKET NUMBER\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NUMBER");
    printf("\n--------------------------------------------------------------------------------");

    Passenger pr;
    FILE *fp=fopen("D:\\data drive e\\MyProjectFiles\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("File cannot be open");
        return;
    }
    int row = 3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
            printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
            row++;
    }
    return;
}

int cancel_train(char* ptrain_no)
{
    FILE *fp3=fopen("D:\\data drive e\\MyProjectFiles\\allbookings.dat","rb");
    if (fp3==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet!");
        return -1;

    }
    FILE *fp4=fopen("D:\\data drive e\\MyProjectFiles\\tempp.dat","wb");
    Passenger pr;
    int fd = 0;
    int rs;
    while(fread(&pr,sizeof(pr),1,fp3)==1)
    {
        if(strcmp(pr.train_no, ptrain_no))
        {
            fd=1;
        }
        else
        {
            fwrite(&pr,sizeof(pr),1,fp4);
        }
    }
    fclose(fp3);
    fclose(fp4);
    if(fd==0)
    {
        remove("D:\\data drive e\\MyProjectFiles\\tempp.dat");

    }
    else
    {
         remove("D:\\data drive e\\MyProjectFiles\\allbookings.dat");
         rename("D:\\data drive e\\MyProjectFiles\\tempp.dat","D:\\data drive e\\MyProjectFiles\\allbookings.dat");
    }
    //printf("%d",fd);
    return fd;
}








