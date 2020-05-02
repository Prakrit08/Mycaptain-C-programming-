#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <stdbool.h>
int i,j,mexit;
struct date
{
    int mon,day,year;
};
struct
{
    char name[60];
    int accn,age;
    char addr[60];
    char citizen[15];
    double phone;
    char acct[10];
    float amt;
    struct date dob,deposit,withdraw;
}add,upd,check,rem,transaction;
float interest(float t,float p,int r)
{
    return ((r*t*p)/100.0);
}
void fordelay(int j)
{   
    for(i=0;i<j;)
    	i++;
}
void new_acc()
{
    int choice;
    FILE *pt;
    pt=fopen("<ENTER FILE NAME WITH .dat EXTENSION CONTAINING THE RECORDS>","a+");// PLEASE ENTER YOUR .dat FILE NAME HERE BEFORE RUNNING THE PROGRAM
    account_no:
    system("cls");
    printf("\t\t\t\t==== ADD RECORD  ====");
    printf("\n\n\nEnter today's date(mm/dd/yyyy): ");
    scanf("%d/%d/%d",&add.deposit.mon,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number: ");
    scanf("%d",&check.accn);
    while(fscanf(pt,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.accn,add.name,&add.dob.mon,&add.dob.day,&add.dob.year,&add.age,add.addr,add.citizen,&add.phone,add.acct,&add.amt,&add.deposit.mon,&add.deposit.day,&add.deposit.year)!=EOF)
        if (check.accn==add.accn)
        {
        	printf("Account no. already in use!");
            fordelay(1000000000);
            goto account_no;
        }
    add.accn=check.accn;
    printf("\nEnter the Name: ");
    scanf("%s",add.name);
    printf("\nEnter the DOB(mm/dd/yyyy): ");
    scanf("%d/%d/%d",&add.dob.mon,&add.dob.day,&add.dob.year);
    printf("\nEnter the Age: ");
    scanf("%d",&add.age);
    printf("\nEnter the Address: ");
    scanf("%s",add.addr);
    printf("\nEnter the Citizenship: ");
    scanf("%s",add.citizen);
    printf("\nEnter the Phone Number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to Deposit: $ ");
    scanf("%f",&add.amt);
    printf("\nType of Account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice: ");
    scanf("%s",add.acct);
	fprintf(pt,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accn,add.name,add.dob.mon,add.dob.day,add.dob.year,add.age,add.addr,add.citizen,add.phone,add.acct,add.amt,add.deposit.mon,add.deposit.day,add.deposit.year);
    fclose(pt);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
    scanf("%d",&mexit);
    system("cls");
    if (mexit==1)
        menu();
    else if(mexit==0)
        close();
    else
    {
        printf("\nInvalid Choice!\a");
        goto add_invalid;
    }
}
void view_list()
{
    FILE *view;
    view=fopen("<ENTER FILE NAME WITH .dat EXTENSION CONTAINING THE RECORDS>","r");// PLEASE ENTER YOUR .dat FILE NAME HERE BEFORE RUNNING THE PROGRAM
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\taddr\t\t\tPHONE\n");
    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accn,add.name,&add.dob.mon,&add.dob.day,&add.dob.year,&add.age,add.addr,add.citizen,&add.phone,add.acct,&add.amt,&add.deposit.mon,&add.deposit.day,&add.deposit.year)!=EOF)
	{
        printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.accn,add.name,add.addr,add.phone);
        test++;
    }
    fclose(view);
    if (test==0)
    {   
    	system("cls");
        printf("\nNO RECORDS!!\n");
    }
    view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit: ");
    scanf("%d",&mexit);
    system("cls");
    if (mexit==1)
        menu();
    else if(mexit==0)
        close();
    else
    {
        printf("\nInvalid Choice!\a");
        goto view_list_invalid;
    }
}
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("<ENTER FILE NAME WITH .dat EXTENSION CONTAINING THE RECORDS>","r");// PLEASE ENTER YOUR .dat FILE NAME HERE BEFORE RUNNING THE PROGRAM
    newrec=fopen("<ENTER FILE NAME WITH .dat EXTENSION CONTAINING THE NEW RECORDS>","w");// PLEASE ENTER YOUR .dat FILE NAME HERE BEFORE RUNNING THE PROGRAM
    printf("\nEnter the account no. of the customer whose info you want to change: ");
    scanf("%d",&upd.accn);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accn,add.name,&add.dob.mon,&add.dob.day,&add.dob.year,&add.age,add.addr,add.citizen,&add.phone,add.acct,&add.amt,&add.deposit.mon,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.accn==upd.accn)
        {   
        	test=1;
            printf("\nWhich information do you want to change?\n1.addr\n2.Phone\n\nEnter your choice(1 for addr and 2 for phone): ");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
            {	
            	printf("Enter the new addr: ");
                scanf("%s",upd.addr);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accn,add.name,add.dob.mon,add.dob.day,add.dob.year,add.age,upd.addr,add.citizen,add.phone,add.acct,add.amt,add.deposit.mon,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
            }
            else if(choice==2)
            {
                printf("Enter the new phone number: ");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accn,add.name,add.dob.mon,add.dob.day,add.dob.year,add.age,add.addr,add.citizen,upd.phone,add.acct,add.amt,add.deposit.mon,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
            }
        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accn,add.name,add.dob.mon,add.dob.day,add.dob.year,add.age,add.addr,add.citizen,add.phone,add.acct,add.amt,add.deposit.mon,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
	if(test!=1)
    {   system("cls");
        printf("\nRecord not found!!\a\a\a");
        edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
        scanf("%d",&mexit);
        system("cls");
        if (mexit==1)
            menu();
        else if (mexit==2)
            close();
        else if(mexit==0)
            edit();
        else
        {
        	printf("\nInvalid!\a");
            goto edit_invalid;}
        }
    else
    {	
    	printf("\n\n\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&mexit);
        system("cls");
        if (mexit==1)
            menu();
        else
            close();
    }
}
void transact(void)
{   
	int choice,test=0;
    FILE *old,*newrec;
    old=fopen("<ENTER FILE NAME WITH .dat EXTENSION CONTAINING THE RECORDS>","r");// PLEASE ENTER YOUR .dat FILE NAME HERE BEFORE RUNNING THE PROGRAM
    newrec=fopen("<ENTER FILE NAME WITH .dat EXTENSION CONTAINING THE NEW RECORDS>","w");// PLEASE ENTER YOUR .dat FILE NAME HERE BEFORE RUNNING THE PROGRAM
	printf("Enter the account no. of the customer: ");
    scanf("%d",&transaction.accn);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accn,add.name,&add.dob.mon,&add.dob.day,&add.dob.year,&add.age,add.addr,add.citizen,&add.phone,add.acct,&add.amt,&add.deposit.mon,&add.deposit.day,&add.deposit.year)!=EOF)
	{
        if(add.accn==transaction.accn)
        {   
        	test=1;
            if(strcmpi(add.acct,"fixed1")==0||strcmpi(add.acct,"fixed2")==0||strcmpi(add.acct,"fixed3")==0)
            {
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                fordelay(1000000000);
                system("cls");
                menu();
            }
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw): ");
            scanf("%d",&choice);
            if (choice==1)
            {
                printf("Enter the amount you want to deposit: $ ");
                scanf("%f",&transaction.amt);
                add.amt+=transaction.amt;
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accn,add.name,add.dob.mon,add.dob.day,add.dob.year,add.age,add.addr,add.citizen,add.phone,add.acct,add.amt,add.deposit.mon,add.deposit.day,add.deposit.year);
                printf("\n\nDeposited successfully!");
            }
            else
            {
                printf("Enter the amount you want to withdraw: $ ");
                scanf("%f",&transaction.amt);
                add.amt-=transaction.amt;
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accn,add.name,add.dob.mon,add.dob.day,add.dob.year,add.age,add.addr,add.citizen,add.phone,add.acct,add.amt,add.deposit.mon,add.deposit.day,add.deposit.year);
                printf("\n\nWithdrawn successfully!");
            }
        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accn,add.name,add.dob.mon,add.dob.day,add.dob.year,add.age,add.addr,add.citizen,add.phone,add.acct,add.amt,add.deposit.mon,add.deposit.day,add.deposit.year);
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
    	printf("\n\nRecord not found!!");
    	transact_invalid:
    	printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
    	scanf("%d",&mexit);
    	system("cls");
    	if (mexit==0)
    	    transact();
    	else if (mexit==1)
    	    menu();
    	else if (mexit==2)
    	    close();
    	else
    	{
    	    printf("\nInvalid!");
    	    goto transact_invalid;
    	}
    }
    else
    {
    	printf("\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&mexit);
        system("cls");
        if (mexit==1)
            menu();
        else
            close();
    }
}
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("<ENTER FILE NAME WITH .dat EXTENSION CONTAINING THE RECORDS>","r");// PLEASE ENTER YOUR .dat FILE NAME HERE BEFORE RUNNING THE PROGRAM
    newrec=fopen("<ENTER FILE NAME WITH .dat EXTENSION CONTAINING THE NEW RECORDS>","w");// PLEASE ENTER YOUR .dat FILE NAME HERE BEFORE RUNNING THE PROGRAM
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.accn);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accn,add.name,&add.dob.mon,&add.dob.day,&add.dob.year,&add.age,add.addr,add.citizen,&add.phone,add.acct,&add.amt,&add.deposit.mon,&add.deposit.day,&add.deposit.year)!=EOF)
   	{
        if(add.accn!=rem.accn)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accn,add.name,add.dob.mon,add.dob.day,add.dob.year,add.age,add.addr,add.citizen,add.phone,add.acct,add.amt,add.deposit.mon,add.deposit.day,add.deposit.year);
        else
        {	
        	test++;
            printf("\nRecord deleted successfully!\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test==0)
    {
        printf("\nRecord not found!!\a\a\a");
        erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
        scanf("%d",&mexit);
        if (mexit==1)
            menu();
        else if (mexit==2)
            close();
        else if(mexit==0)
            erase();
        else
        {
        	printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {	
       	printf("\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&mexit);
        system("cls");
        if (mexit==1)
            menu();
        else
            close();
    }
}
void see(void)
{
    FILE *pt;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    pt=fopen("<ENTER FILE NAME WITH .dat EXTENSION CONTAINING THE RECORDS>","r");// PLEASE ENTER YOUR .dat FILE NAME HERE BEFORE RUNNING THE PROGRAM
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice: ");
    scanf("%d",&choice);
    if (choice==1)
    {   
    	printf("Enter the account number: ");
        scanf("%d",&check.accn);
        while (fscanf(pt,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accn,add.name,&add.dob.mon,&add.dob.day,&add.dob.year,&add.age,add.addr,add.citizen,&add.phone,add.acct,&add.amt,&add.deposit.mon,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.accn==check.accn)
            {   system("cls");
                test=1;
                printf("\nAccount NO.: %d\nName: %s \nDOB: %d/%d/%d \nAge: %d \naddr: %s \nCitizenship: %s \nPhone number: %.0lf \nType Of Account: %s \nAmount deposited: $ %.2f \nDate Of Deposit: %d/%d/%d\n\n",add.accn,add.name,add.dob.mon,add.dob.day,add.dob.year,add.age,add.addr,add.citizen,add.phone,
                add.acct,add.amt,add.deposit.mon,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acct,"fixed1")==0)
                {
                    time=1.0;
                    rate=9;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.mon,add.deposit.day,add.deposit.year+1);
                }
                else if(strcmpi(add.acct,"fixed2")==0)
                {
                    time=2.0;
                    rate=11;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.mon,add.deposit.day,add.deposit.year+2);
                }
                else if(strcmpi(add.acct,"fixed3")==0)
                {
                    time=3.0;
                    rate=13;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.mon,add.deposit.day,add.deposit.year+3);
                }
                else if(strcmpi(add.acct,"saving")==0)
                {
                    time=(1.0/12.0);
                    rate=8;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get $.%.2f as interest on %d of every mon",intrst,add.deposit.day);
                }
                else if(strcmpi(add.acct,"current")==0)
                    printf("\n\nYou will get no interest\a\a");
            }
        }
    }
    else if (choice==2)
    {   
    	printf("Enter the name: ");
        scanf("%s",&check.name);
        while (fscanf(pt,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accn,add.name,&add.dob.mon,&add.dob.day,&add.dob.year,&add.age,add.addr,add.citizen,&add.phone,add.acct,&add.amt,&add.deposit.mon,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   
            	system("cls");
                test=1;
                printf("\nAccount No.: %d\nName: %s \nDOB: %d/%d/%d \nAge: %d \naddr: %s \nCitizenship: %s \nPhone number: %.0lf \nType Of Account: %s \nAmount deposited: $ %.2f \nDate Of Deposit: %d/%d/%d\n\n",add.accn,add.name,add.dob.mon,add.dob.day,add.dob.year,add.age,add.addr,add.citizen,add.phone,
                add.acct,add.amt,add.deposit.mon,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acct,"fixed1")==0)
                {
                    time=1.0;
                    rate=9;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.mon,add.deposit.day,add.deposit.year+1);
                }
                else if(strcmpi(add.acct,"fixed2")==0)
                {
                    time=2.0;
                    rate=11;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.mon,add.deposit.day,add.deposit.year+2);
                }
                else if(strcmpi(add.acct,"fixed3")==0)
                {
                    time=3.0;
                    rate=13;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.mon,add.deposit.day,add.deposit.year+3);
                }
                else if(strcmpi(add.acct,"saving")==0)
                {
                    time=(1.0/12.0);
                    rate=8;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get $.%.2f as interest on %d of every mon",intrst,add.deposit.day);
                }
                else if(strcmpi(add.acct,"current")==0)
                    printf("\n\nYou will get no interest\a\a");
            }
        }
    }
    fclose(pt);
    if(test!=1)
    {   
    	system("cls");
        printf("\nRecord not found!!\a\a\a");
        see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
        scanf("%d",&mexit);
        system("cls");
        if (mexit==1)
            menu();
        else if (mexit==2)
            close();
        else if(mexit==0)
            see();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;}
        }
    else
    {
    	printf("\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&mexit);}
        if (mexit==1)
        {
            system("cls");
            menu();
        }
        else
        {
            system("cls");
            close();
        }
}
int close(void)
{
	return 0;
}
void menu(void)
{   
	int choice;
    system("cls");
    system("color 7");
    printf("\n\n\t\t\t       BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t[1] Create a new account\n\t\t[2] Update information of existing account\n\t\t[3] Transactions\n\t\t[4] Check the details of existing account\n\t\t[5] Remove existing account\n\t\t[6] View customer's list\n\t\t[7] ATM Feature\n\t\t[8] Exit\n\n\n\t\t Enter your choice: ");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1: new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:atm();
        break;
        case 8:close();
        break;
    }
}
int atm()
{
	void mainMenu();
	void checkBalance(float balance);
	float moneyDeposit(float balance);
	float moneyWithdraw(float balance);
	void menuExit();
	void errorMessage();
	int login(void)
	{
		float number = 1234;//CHANGE YOUR ATM PIN HERE BEFORE EXECUTION
		int pass;
		printf("\n\n\t\t\tEnter the PIN No: ");
		scanf("%d", &pass);
		if (pass == number)
    	{
    		printf("\n\nPIN Matched!\nLOADING");
        	for(i=0;i<=6;i++)
        	{
        	    fordelay(100000000);
        	    printf(".");
        	}
        	system("cls");
      		mainMenu();
    	}
  		else
    	{
    		printf("Invalid\n Try Again");
    		login();
    	}
    return 0;
	}
    int option;
    float balance = 15000.00;
    int choose;
    bool again = true;
    login();
    while (again) 
    {
    	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    	printf("Your Selection: \t");
    	scanf("%d", &option);
    	system("cls"); 
        switch (option) 
        {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = moneyDeposit(balance);
                break;
            case 3:
                balance = moneyWithdraw(balance);
                break;
            case 4:
                menuExit();
                return 0;   
            default:
                errorMessage();
                break;
        }
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Would you like to do another transaction: \n");
        printf("< 1 > Yes\n");
        printf("< 2 > No\n");
        scanf("%d", &choose);
        system("cls"); 
        if (choose == 2) 
        {
            again = false;
            menuExit();
        }
        else
        	mainMenu();  
	}
}
void mainMenu() 
{ 
    printf("\n\n\t\t==========Welcome to ATM Feature==========\n\n");
    printf("\n\t\t----Please choose one of the options below----\n");
    printf("\n\t\t< 1 >  Check Balance\n");
    printf("\n\t\t< 2 >  Deposit\n");
    printf("\n\t\t< 3 >  Withdraw\n");
    printf("\n\t\t< 4 >  Exit\n\n"); 
}
void checkBalance(float balance) 
{
    printf("You Choose to See your Balance\n");
    printf("****Your Available Balance is:   $%.2f\n\n", balance);  
}
float moneyDeposit(float balance) 
{
    float deposit;
    printf("You choose to Deposit a money\n");
    printf("$$$$Your Balance is: $%.2f\n\n", balance);
    printf("****Enter your amount to Deposit\n");
    scanf("%f", &deposit);
    balance += deposit;
    printf("****Your New Balance is:   $%.2f\n\n", balance);
    return balance;   
}
float moneyWithdraw(float balance) 
{
    float withdraw;
    bool back = true;    
    printf("You choose to Withdraw a money\n");
    printf("$$$$Your Balance is: $%.2f\n\n", balance);
    while (back)
    {
    	printf("Enter your amount to withdraw: \n");
    	scanf("%f", &withdraw); 
	    if (withdraw < balance)
	    {
        	back = false;
        	balance -= withdraw;
        	printf("$$$$Your withdrawing money is:  $%.2f\n", withdraw);
        	printf("****Your New Balance is:   $%.2f\n\n", balance);
        }
        else
        {
            printf("+++You don't have enough money+++\n");
        	printf("Please contact to your Bank Customer Services\n");
        	printf("****Your Balance is:   $%.2f\n\n", balance);
	    }
    }
    return balance;
}
void menuExit()
{
    printf("--------------Take your receipt!!!------------------\n");
    printf("-----Thank you for using ATM Banking Machine!!!-----\n");
    menu();
}
void errorMessage() 
{
    printf("+++!!!You selected invalid number!!!+++\n");
}
int main()
{
    char pass[10],password[10]="MYproject";//UPDATE YOUR PASSWORD HERE BEFORE EXECUTION
    int i=0;
    printf("\n\n\n\t\t\t\t   Bank Management System\n\t\t\t\t\t User Login ");
    printf("\n\n\n\n\n\t\t\t\tEnter the password to login: ");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
    {
    	printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(". ");
        }
        printf("\n");
        system("pause");
		system("cls");
        menu();
    }
    else
    {   
    	printf("\n\nWrong password!!\a\a\a");
        login_try: 
        printf("\nEnter 1 to try again and 0 to exit: ");
        scanf("%d",&mexit);
        if (mexit==1)
        {
            system("cls");
            main();
        }
        else if (mexit==0)
        {
            system("cls");
            close();
        }
        else
        {
        	printf("\nInvalid!");
            fordelay(1000000000);
            system("cls");
            goto login_try;
        }
    }
    return 0;
}
