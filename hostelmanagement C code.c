//including header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining global variables
int i,j,main_exit;

//declaring functions
void menu();
void new_entry();
void edit();
void view_list();
void erase();
void see();
void sorter();
void closer();

//defining structures
struct date{
    int month,day,year;
};
struct {

    char name[60];
    int age;
    char city[60];
    char email_id[30];
    char room_no[8];
    char father_name[60];
    int father_phone;
    int phone;
    char hostel_name[6];
    char roll_number[10];
    struct date date_of_birth;
    }add,upd,check,rem,sort;

//--------------------------------------------------------------------------------------------------------------------
//main function
int main()
{
	pass();
  menu();
  return 0;
}


//menu function
void menu()
{  
system("CLS");
    int choice;
    printf("\n\n\t\t\t********** HOSTEL MANAGEMENT SYSTEM **********");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1>> Enter new Student's data\n\t\t2>> Update information of existing account\n\t\t3>> Check the details of existing account\n\t\t4>> View all Students of a particular Hostel\n\t\t5>> Removing existing account\n\t\t6>> View all students list\n\t\t7>> Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {

        case 1:new_entry();
        break;
        case 2:edit();
        break;
        case 3:see();
        break;
        case 4:sorter();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:closer();
        break;
        default:menu();
    }
}

//------------------------------------------------------------------------------------------------------------------
//function to display all students of a hostel 
void sorter()
{
	system("CLS");
    int choice,test=0;
    
    printf("Enter your choice:\n\n\t\t1. BH-1 \n\t\t2. BH-2 \n\t\t3. GH-1 \n\t\t4. GH-2 \n\n");
    scanf("%d",&choice);
    
    FILE *fp, *hostel;
    switch(choice)
    {
    	case 1: hostel=fopen("BH-1.dat","a+");break;
    	case 2: hostel=fopen("BH-2.dat","a+");break;
    	case 3: hostel=fopen("GH-1.dat","a+");break;
    	case 4: hostel=fopen("GH-2.dat","a+");break;
    	default: sorter();
    }
    while(fscanf(hostel,"%s\n",check.roll_number)!=EOF)
    {
   	    fp=fopen("record.dat","r");
    	while(fscanf(fp,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",sort.roll_number, sort.name, &sort.date_of_birth.month, &sort.date_of_birth.day, &sort.date_of_birth.year, &sort.age, sort.city, &sort.phone, sort.email_id, sort.father_name, &sort.father_phone, sort.room_no, sort.hostel_name)!=EOF)
    	{
    		if(strcmp(check.roll_number,sort.roll_number)==0)
    		{
    			if(test==0)
    			{
    				printf("\t\tFollowing are the list of requested students:");
		            printf("\n\tROLL NO.\tNAME\tROOM NO.\n");
    			}
    			printf("\n\t%8s\t %8s\t %s", sort.roll_number, sort.room_no, sort.name);
           		test++;
    		}
    	}
    }
    
    fclose(fp);
    if (test==0)
        printf("\nNO RECORDS!!\n");
    
    sort_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        closer();
    else
    {
        printf("\nInvalid!\a");
        goto sort_list_invalid;
    }
    
}

//------------------------------------------------------------------------------------------------------------------
//new entry function
void new_entry()
{
	system("CLS");
    int choice;
    FILE *ptr,*hostel;

    ptr=fopen("record.dat","a+");
    roll_number:
    
    printf("\t\t\t\xB2\xB2\xB2 ADD STUDENTS DATA  \xB2\xB2\xB2\xB2");
    printf("\nEnter your roll number:");
    scanf("%s",check.roll_number);
    while(fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_number, add.name, &add.date_of_birth.month, &add.date_of_birth.day, &add.date_of_birth.year, &add.age, add.city, &add.phone, add.email_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
    {
        if (strcmp(check.roll_number,add.roll_number)==0)
            {printf("Students roll no. already in exist!");
             goto roll_number;
        }
    }

    strcpy(add.roll_number,check.roll_number);
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.date_of_birth.month,&add.date_of_birth.day,&add.date_of_birth.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the city:");
    scanf("%s",add.city);
    printf("\nEnter the phone number: ");
    scanf("%d",&add.phone);
    printf("\n Enter your email id :");
    scanf("%s",add.email_id);
    printf("\n Enter your Father's name:");
    scanf("%s",add.father_name);
    printf("\n Enter your Father's phone number:");
    scanf("%d",&add.father_phone);
    printf("\n Enter your room number:");
    scanf("%s",add.room_no);
    printf("\n Enter your hostel block name from BH-1, BH-2, GH-1, GH-2 :");
    scanf("%s",add.hostel_name);
        fprintf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_number, add.name, add.date_of_birth.month, add.date_of_birth.day, add.date_of_birth.year, add.age, add.city, add.phone, add.email_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
	
		//adding student roll no. to hostels' list
	if(strcmp(add.hostel_name,"BH-1")==0)
	{
		hostel=fopen("BH-1.dat","a+");
		fprintf(hostel, "%s\n", add.roll_number);
		fclose(hostel);		
	}
	else if(strcmp(add.hostel_name,"BH-2")==0)
	{
		hostel=fopen("BH-2.dat","a+");
		fprintf(hostel, "%s\n", add.roll_number);
		fclose(hostel);		
	}
	else if(strcmp(add.hostel_name,"GH-1")==0)
	{
		hostel=fopen("GH-1.dat","a+");
		fprintf(hostel, "%s\n", add.roll_number);
		fclose(hostel);		
	}
	else if(strcmp(add.hostel_name,"GH-2")==0)
	{
		hostel=fopen("GH-2.dat","a+");
		fprintf(hostel, "%s\n", add.roll_number);
		fclose(hostel);		
	}
		//----------------------------------------
    
    fclose(ptr);
    printf("\nStudent record added successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    
    if (main_exit==1)
    
        menu();
    else if(main_exit==0)
            closer();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
//nsbfunction to view all students
void view_list()
{
	system("CLS");
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    
    printf("\nROLL NO.\tNAME\t\t\tcity\t\t\tPHONE\n");

    while(fscanf(view,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_number, add.name, &add.date_of_birth.month, &add.date_of_birth.day, &add.date_of_birth.year, &add.age, add.city, &add.phone, add.email_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
       {
           printf("\n%8s\t %10s\t\t\t %10s\t\t %d",add.roll_number,add.name,add.city,add.phone);
           test++;
       }
    fclose(view);
    
    if (test==0)
        {   
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            closer();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
//function to view all data of 1 student
void see()
{
	system("CLS");
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Roll number\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("\n\nEnter the roll number:");
        scanf("%s",check.roll_number);

        while (fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_number, add.name, &add.date_of_birth.month, &add.date_of_birth.day, &add.date_of_birth.year, &add.age, add.city, &add.phone, add.email_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
        {
            if(strcmp(add.roll_number,check.roll_number)==0)
            {   
                test=1;

                printf("\nROLL NO.:%s\nName:%s \ndate_of_birth:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%d \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%d \nRoom No:%s \nHostel:%s \n",add.roll_number, add.name, add.date_of_birth.month, add.date_of_birth.day, add.date_of_birth.year, add.age, add.city, add.phone, add.email_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
            }
        }
    }
    else if (choice==2)
    {   printf("\n\nEnter the name:");
        scanf("%s",check.name);
        while (fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_number, add.name, &add.date_of_birth.month, &add.date_of_birth.day, &add.date_of_birth.year, &add.age, add.city, &add.phone, add.email_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
        {
            if(strcmp(add.name,check.name)==0)
            {   
                test=1;
                printf("\nROLL NO.:%s\nName:%s \ndate_of_birth:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%d \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%d \nRoom No:%s \nHostel:%s \n",add.roll_number, add.name, add.date_of_birth.month, add.date_of_birth.day, add.date_of_birth.year, add.age, add.city, add.phone, add.email_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
            }
        }
    }

    fclose(ptr);
     if(test!=1)
     	printf("\nStudent Record not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            erase();
        else
        {	
        	printf("\nInvalid!\a");
            goto see_invalid;
		}
}

//------------------------------------------------------------------------------------------------------------------
//function to update student info
void edit()
{
	system("CLS");
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the roll number of the student whose info you want to change:");
    scanf("%s",upd.roll_number);
    while(fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_number, add.name, &add.date_of_birth.month, &add.date_of_birth.day, &add.date_of_birth.year, &add.age, add.city, &add.phone, add.email_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)

    {
        if (strcmp(add.roll_number,upd.roll_number)==0)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Room no.\n2.Phone\n\nEnter your choice(1 for room no. and 2 for phone ):");
            scanf("%d",&choice);
            
            if(choice==1)
                {printf("Enter the new room number:");
                scanf("%s",upd.room_no);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_number, add.name, add.date_of_birth.month, add.date_of_birth.day, add.date_of_birth.year, add.age, add.city, add.phone, add.email_id, add.father_name, add.father_phone, upd.room_no, add.hostel_name);
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%d",&upd.phone);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_number, add.name, add.date_of_birth.month, add.date_of_birth.day, add.date_of_birth.year, add.age, add.city, upd.phone, add.email_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_number, add.name, add.date_of_birth.month, add.date_of_birth.day, add.date_of_birth.year, add.age, add.city, add.phone, add.email_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

	if(test!=1)
        printf("\nRecord not found!!\a\a\a");
    
    edit_invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);  
        if (main_exit==1)
			menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            edit();
        else
        {
        	printf("\nInvalid!\a");
            goto edit_invalid;
        }
       
}

//------------------------------------------------------------------------------------------------------------------
//cpfunction to delete records
void erase()
{
	system("CLS");
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the roll number of student whose data you want to delete:");
    scanf("%s",rem.roll_number);
    while (fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_number, add.name, &add.date_of_birth.month, &add.date_of_birth.day, &add.date_of_birth.year, &add.age, add.city, &add.phone, add.email_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
   {
        if(add.roll_number!=rem.roll_number)
            fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_number, add.name, add.date_of_birth.month, add.date_of_birth.day, add.date_of_birth.year, add.age, add.city, add.phone, add.email_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test==0)
	    printf("\nRecord not found!!\a\a\a");
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            erase();
        else
        {	
        	printf("\nInvalid!\a");
            goto erase_invalid;
		}
}

//------------------------------------------------------------------------------------------------------------------
//function displaying developer credits 1353functioncalls
void closer()
{
	system("CLS");
}

int pass(void)
{
   int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="name";
    char pass[10]="word";
    do
{
	system("cls");
	
    printf("\n  **************************  LOGIN FORM  **************************  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
	system("PAUSE");
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
		system("PAUSE");
		a++;
		
		getch();
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
