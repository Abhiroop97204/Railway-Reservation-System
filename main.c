#include <stdio.h>
#include <stdlib.h>
#include "rlyres.h"
#include "conio2.h"
int main()
{
    int choice, ticket_no, result;
    Passenger *ptr;
    char *pmob_no, *ptrain_no;
    int pticket_no;
    add_trains();
   while(1)
    {
        choice=enterchoice();
        if(choice==9)
            exit(0);
        switch(choice)
        {
                        case 1:
                                    view_trains();
                                    getch();
                                    clrscr();
                                    break;
                       case 2:
                                    //book_ticket();
                                    ptr=get_passenger_details();
                                    clrscr();
                                    if(ptr!=NULL)
                                    {
                                        ticket_no=book_ticket(*ptr);
                                        if(ticket_no==-1)
                                        {
                                            textcolor(LIGHTRED);
                                            printf("Booking has failed");
                                        }
                                        else
                                        {
                                            textcolor(LIGHTGREEN);
                                            printf("Ticket successfully booked\nYour Ticket Number is %d",ticket_no);

                                        }
                                        textcolor(WHITE);
                                        printf("\nPress any key to go MAIN SCREEN");
                                        getch();
                                        clrscr();
                                    }

                                    break;
                       case 3:
                                    //view_ticket();
                                    clrscr();
                                    ticket_no=accept_ticket_no();
                                    if(ticket_no!=0)
                                        view_ticket(ticket_no);
                                    textcolor(WHITE);
                                    printf("\nPress any key to go MAIN SCREEN");
                                    //clrscr();
                                    getch();
                                    clrscr();
                                    break;
                       case 4:
                                    clrscr();
                                    pmob_no=accept_mob_no();
                                    printf("%s",pmob_no);
                                    if (pmob_no!=NULL)
                                    {
                                        pticket_no=get_ticket_no(pmob_no);
                                        view_all_tickets(pmob_no,pticket_no);
                                    }
                                    clrscr();
                                    break;
                       case 5:
                                    //view_all_bookings();
                                    clrscr();
                                    view_all_bookings();
                                    //clrscr();
                                    getch();
                                    clrscr();
                                    break;
                      case 6:
                                    clrscr();
                                    ptrain_no=accept_train_no();
                                    if(ptrain_no!=NULL)
                                    {
                                        view_booking(ptrain_no);
                                    }
                                    clrscr();
                                    break;
                      case 7:
                                    //cancel_ticket();
                                    clrscr();
                                    ticket_no=accept_ticket_no();
                                    if(ticket_no!=0)
                                    {
                                        result=cancel_ticket(ticket_no);
                                        if(result==0)
                                        {
                                            textcolor(LIGHTRED);
                                            printf("Sorry no tickets booked against ticket number %d",ticket_no);

                                        }
                                        else if(result==1)
                                        {
                                            textcolor(LIGHTGREEN);
                                            printf("Ticket number %d successfully cancelled",ticket_no);
                                        }
                                        else if(result==2)
                                        {
                                            textcolor(LIGHTRED);
                                            printf("\n\nSorry error in cancellation, Try Again !");
                                        }
                                        textcolor(WHITE);
                                        printf("\nPress any key to go MAIN SCREEN");
                                     }
                                    getch();
                                    clrscr();
                                    break;
                      case 8:
                                    //cancel_train();
                                    clrscr();
                                    ptrain_no=accept_train_no();
                                    if(ptrain_no!=0)
                                    {
                                        result=cancel_train(ptrain_no);
                                        if(result==0)
                                        {
                                            textcolor(LIGHTRED);
                                            printf("Sorry no tickets booked against this train number %s",ptrain_no);

                                        }
                                        else if(result==1)
                                        {
                                            textcolor(LIGHTGREEN);
                                            printf("Train number %s successfully cancelled",ptrain_no);
                                        }
                                        else if(result==2)
                                        {
                                            textcolor(LIGHTRED);
                                            printf("\n\nSorry error in cancellation, Try Again !");
                                        }
                                        textcolor(WHITE);
                                        printf("\nPress any key to go MAIN SCREEN");
                                     }
                                    getch();
                                    clrscr();
                                    break;
                      default:
                                      textcolor(LIGHTRED);
                                      printf("Wrong Choice! Try Again\n");
                                      getch();
                                      clrscr();
        }
    }

    return 0;
}
