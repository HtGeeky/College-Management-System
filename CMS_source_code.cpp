#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream.h>
#include <conio.h>
char un[20];
class Admin
{
    char name[20];//student name
    int totsub;// total subjects
    char subject[10][10];//subject matrix
    char mobile[15];//contact number
    char mail[50];//email id
    char fname[20];//father name
    char passwd[20];//login password
    char rpasswd[20];//recovery password
    
    public:
    char rollno[15];//student id/rollno
    
    //This function is used to get the student data entry from the ADMIN_PORTAL
    void getstdata()
    {
        cout<<"\n Enter the Student Name: ";
        gets(name);
        cout<<"\n Enter the Student ID/Roll NO.: ";
        cin>>rollno;
        cout<<"\n Enter the Student Father's Name: ";
        gets(fname);
        cout<<"\n Enter the Mobile Number: ";
        gets(mobile);
        cout<<"\n Enter the E-Mail ID: ";
        gets(mail);
        cout<<"\n Enter the Total Subjects: ";
        cin>>totsub;
        for (int i = 0; i < totsub; i++)
        {
            cout<<"\n Enter the Subject "<<i+1<<" Name: ";
            cin>>subject[i];
        }
        cout<<"\n Create your Login Password: ";
        cin>>passwd;
        cout<<"\n Enter the Unique Keyword to Recover Password: ";
        cin>>rpasswd;
        cout<<"\n\n\t Please note your UserName is ID/Roll No. "<<endl;
    }

    /* This function authenticates the login of both the student and faculties
     with reference to their unique user id and password*/
    int login()
    {
        if ((strcmp(::un,rollno))==0)
        {
            cout<<"\n Enter the Login Password: ";
            int len=0;
            len=strlen(passwd);
            char inputpasswd[20];
            for (int i = 0; i < len; i++)
            {
                inputpasswd[i]=getch();
                cout<<"#";
            }
            inputpasswd[i]=NULL;
            if ((strcmp(::un, rollno)==0)&&(strcmp(passwd, inputpasswd)==0))
                return 1;
                else
                return 0;
        }
        else
        return 0;
    }

    /*this function help both the students and faculties to recover the password
    with the help of unique keyword provided by the Admin*/
    int recover()
    {
        char key[20];
        if (strcmp(::un, rollno)==0)
        {
            cout<<"\n Enter the Unique Keyword (Provided by the Admin): ";
            cin>>key;
            if ((strcmp(key, rpasswd)==0))
            {
                cout<<"\n You are a Valid User. ";
                cout<<"\n Your Password is "<<passwd;
                cout<<"\n PLEASE EXIT TO LOGIN AGAIN."<<endl;
                return 1;
            }
            else
            return 0;
        }
        else
        return 0;
    }

    //this function displays the faculty profile to the faculty at their respective portals
    int faprofile()
    {
        if ((strcmp(::un, rollno)==0))
        {
            cout<<"\n Faculty Name:             "<<name;
            cout<<"\n Faculty Fathers's Name:   "<<fname;
            cout<<"\n Faculty Contact Number:   "<<mobile;
            cout<<"\n Faculty E-Mail ID:        "<<mail;
            return 1;
        }
        else 
        return 0;
    }

    //this function displays the different subjects of the faculty at their respective portals
    int knowfasub()
    {
        if ((strcmp(::un, rollno)==0))
        {
            cout<<"\n Faculty Total Subjects: "<<totsub;
            for (int i = 0; i < totsub; i++)
            {
                cout<<"\n\t Subject "<<i+1<<" : "<<subject[i];
            }
            return 1;
        }   
        else
        return 0;
    }

    //this function helps a faculty to add a subject in their profile/module
    void addfasub()
    {
        if ((strcmp(::un, rollno)==0))
        {
            cout<<"\n Enter the New Subject: ";
            cin>>subject[totsub];
            totsub++;
            cout<<"\n\n New Subject Added Successfully! "<<endl;
        }
    }

    //this function helps a faculty to delete a subject from their module
    void delfasub()
    {
        knowfasub();
        int de=0;
        if ((strcmp(::un, rollno)==0))
        {
            if (totsub==0||totsub<0)
            {
                totsub=0;
                cout<<"\n No Subjecs Exist! ";
                getch();
                exit(0);
            }
            cout<<"\n Enter the Subject No. to be Deleted: ";
            cin>>de;
            if (de==totsub)
            {
                totsub--;
                strcpy(subject[totsub], " ");
            }
            else if (totsub==1)
            {
                totsub=0;
                strcpy(subject[totsub], " ");
            }
            else
            {
                de--;
                strcpy(subject[totsub], " ");
                for (int p = de; p < totsub; p++)
                {
                    strcpy(subject[p], subject[p+1]);
                }
                totsub--;
            }
            cout<<"\n Records Updated Successfully! ";
        }
    }

    //this function helps a faculty to modify his personal profile
    void modfaprofile()
    {
        if ((strcmp(::un, rollno)==0))
        {
            cout<<"\n The Profile Details are: ";
            cout<<"\n 1. Faculty E-Mail: "<<mail;
            cout<<"\n 2. Faculty Mobile: "<<mobile;
            int g=-1;
            cout<<"\n Enter the Detail No. to be Modified: ";
            cin>>g;
            if (g==1)
            {
                char nmail[50];
                cout<<"\n Enter the New Email Address: ";
                strcpy(mail, nmail);
                cout<<"\n Records Updated Successfully! ";
            }
            else if (g==2)
            {
                char nmobile[15];
                cout<<"\n Enter the New Contact Number: ";
                gets(nmobile);
                strcpy(mobile, nmobile);
                cout<<"\n Records Updated Successfully! ";
            }
            else
            {
                cout<<"\n Invalid Input Provided! "<<endl;
            }
        }
    }

    //this function displays the student profile at the student portal
    int stprofile()
    {
        if ((strcmp(::un, rollno)==0))
        {
            cout<<"\n Student Name:             "<<name;
            cout<<"\n Student Fathers's Name:   "<<fname;
            cout<<"\n Student Contact Number:   "<<mobile;
            cout<<"\n Student E-Mail ID:        "<<mail;
            return 1;
        }
        else 
        return 0;
    }

    /*this function displays the different enrolled subjects of the respective student
    according to their profile*/
    int knowstsub()
    {
        if ((strcmp(::un, rollno)==0))
        {
            cout<<"\n Student Total Subjects: "<<totsub;
            for (int i = 0; i < totsub; i++)
            {
                cout<<"\n\t Subject "<<i+1<<" : "<<subject[i];
            }
            return 1;
        }   
        else
        return 0;
    }

    //this function allows the student to add a subject in total subjects of the student profile
    void addstsub()
    {
        if ((strcmp(::un, rollno)==0))
        {
            cout<<"\n Enter the New Subject: ";
            cin>>subject[totsub];
            totsub++;
            cout<<"\n\n New Subject Added Successfully! "<<endl;
        }
    }

    //this function allows the student to delete a subject in the total subjects of the student profile
    void delstsub()
    {
        knowstsub();
        int de=0;
        if ((strcmp(::un, rollno)==0))
        {
            if (totsub==0||totsub<0)
            {
                totsub=0;
                cout<<"\n No Subjecs Exist! ";
                getch();
                exit(0);
            }
            cout<<"\n Enter the Subject No. to be Deleted: ";
            cin>>de;
            if (de==totsub)
            {
                totsub--;
                strcpy(subject[totsub], " ");
            }
            else if (totsub==1)
            {
                totsub=0;
                strcpy(subject[totsub], " ");
            }
            else
            {
                de--;
                strcpy(subject[totsub], " ");
                for (int p = de; p < totsub; p++)
                {
                    strcpy(subject[p], subject[p+1]);
                }
                totsub--;
            }
            cout<<"\n Records Updated Successfully! ";
        }
    }

    //this function allows the student to modify their personal details at the student portal
    void modstprofile()
    {
        if ((strcmp(::un, rollno)==0))
        {
            cout<<"\n The Profile Details are: ";
            cout<<"\n 1. Student E-Mail: "<<mail;
            cout<<"\n 2. Student Mobile: "<<mobile;
            int g=-1;
            cout<<"\n Enter the Detail No. to be Modified: ";
            cin>>g;
            if (g==1)
            {
                char nmail[50];
                cout<<"\n Enter the New Email Address: ";
                strcpy(mail, nmail);
                cout<<"\n Records Updated Successfully! ";
            }
            else if (g==2)
            {
                char nmobile[15];
                cout<<"\n Enter the New Contact Number: ";
                gets(nmobile);
                strcpy(mobile, nmobile);
                cout<<"\n Records Updated Successfully! ";
            }
            else
            {
                cout<<"\n Invalid Input Provided! "<<endl;
            }
        }
    }

    /*this function allows the ADMIN  to make a new Record Entry 
    for the different new faculties...new faculty records are 
    updated with the help of this function*/
    void getfadata()
    {
        cout<<"\n Enter the Faculty Name: ";
        gets(name);
        cout<<"\n Enter the Faculty ID/Roll NO.: ";
        cin>>rollno;
        cout<<"\n Enter the Faculty Father's Name: ";
        gets(fname);
        cout<<"\n Enter the Mobile Number: ";
        gets(mobile);
        cout<<"\n Enter the E-Mail ID: ";
        gets(mail);
        cout<<"\n Enter the Total Subjects: ";
        cin>>totsub;
        for (int i = 0; i < totsub; i++)
        {
            cout<<"\n Enter the Subject "<<i+1<<" Name: ";
            cin>>subject[i];
        }
        cout<<"\n Create your Login Password: ";
        cin>>passwd;
        cout<<"\n Enter the Unique Keyword to Recover Password: ";
        cin>>rpasswd;
        cout<<"\n\n\t Please note your UserName is ID/Roll No. "<<endl;
    }

    /*this function displays all the relevant information 
    to the admin related to the Students at the ADMIN portal*/
    void stdisplay()
    {
        cout<<"\n Student Name :            "<<name;       
        cout<<"\n Student ID/Roll No. :     "<<rollno;
        cout<<"\n Student Father's Name :   "<<fname;
        cout<<"\n Student Mobile No. :      "<<mobile;
        cout<<"\n Student E-Mail ID :       "<<mail;
        cout<<"\n Student Subjects :        "<<totsub;
        for (int i = 0; i < totsub; i++)
        {
            cout<<"\n Subject "<<i+1<<" : "<<subject[i];
        }
        if (totsub==0)
        {
            cout<<"\n ( No Subjects Specified! )";
        }
    }

    /*this function displays all the relevant information 
    to the admin related to the Faculty at the ADMIN portal*/
    void fadisplay()
    {
        cout<<"\n Faculty Name :            "<<name;       
        cout<<"\n Faculty ID/Roll No. :     "<<rollno;
        cout<<"\n Faculty Father's Name :   "<<fname;
        cout<<"\n Faculty Mobile No. :      "<<mobile;
        cout<<"\n Faculty E-Mail ID :       "<<mail;
        cout<<"\n Faculty Subjects :        "<<totsub;
        for (int i = 0; i < totsub; i++)
        {
            cout<<"\n Subject "<<i+1<<" : "<<subject[i];
        }
        if (totsub==0)
        {
            cout<<"\n ( No Subjects Specified! )";
        }
    }
}a;
Admin f;
//'a' and 'f' are the objects the the class 'ADMIN' 
void main()
{
    int ch;
    clrscr();
    cout<<"\n\n\n\t\t\t Welcome To the College Management System ";
    cout<<"\n\n\n\t\t\t Press Enter to Coninue ";
    getch();
    clrscr();
    cout<<"\n\n\t\t Press 1 for Admin Portal";
    cout<<"\n\n\t\t Press 2 for Faculty Portal";
    cout<<"\n\n\t\t Press 3 for Student Portal";
    cout<<"\n\n\t\t Enter your choice: ";
    cin>>ch;
    clrscr();
    if (ch==1)//admin
    {
        char adminuser[20], adminpass[20];
        cout<<"\n\t Welcome to the Admin Login Portal ";
        cout<<"\n\t Enter the UserName: ";
        cin>>adminuser;
        cout<<"\n\t Enter the password: ";
        for (int k = 0; k < 8; k++)
        {
            adminpass[k]=getch();
            cout<<"*";
        }
        getch();
        adminpass[k]=NULL;
        if ((strcmp(adminuser, "admin")==0)&&(strcmp(adminpass, "password")==0))
        {
            clrscr();
        }
        else
        {
            cout<<"\n\t Invalid Access To The Portal ";
            getch();
            exit(0);
        }
        char opera='y';
        do
        {
            int tmp;
            cout<<"\n\t\t\t\t Welcome To Admin Panel ";
            cout<<"\n\t Press 1 to Add a Faculty Record ";
            cout<<"\n\t Press 2 to add Multiple Records of Faculty ";
            cout<<"\n\t Press 3 to view all Records of the Faculty ";
            cout<<"\n\t Press 4 to Delete a Faculty Record ";
            cout<<"\n\t Press 5 to Add a Student Record ";
            cout<<"\n\t Press 6 to Add Multiple Records of the Students ";
            cout<<"\n\t Press 7 to view all Records of the Students ";
            cout<<"\n\t Press 8 to Delete a Student Record ";
            cout<<"\n\t press 9 to EXIT. ";
            cout<<"\n\n\n\t Enter your choice: ";
            cin>>tmp;
            clrscr();
            if (tmp==1)
            {
                cout<<"\n\t Enter the Details: ";
                fstream fs;
                fs.open("fainfo.txt", ios::in|ios::out|ios::ate);
                a.getfadata();
                fs.write((char *)&a, sizeof(Admin));
                fs.close();
                cout<<"\n Record Entered Successfully! ";
            }
            if (tmp==2)
            {
                int m=0;
                fstream fs;
                fs.open("fainfo.txt", ios::in|ios::out|ios::ate);
                do
                {
                    cout<<"\n\t Enter the details: ";
                    a.getfadata();
                    fs.write((char *)&a, sizeof(Admin));
                    cout<<"\n\t Press 0 if you want to enter more records: ";
                    cin>>m;
                }while (m==0);
                fs.close();
                cout<<"\n Record Entered Successfully! ";
            }
            if (tmp==3)
            {
                fstream fs;
                fs.open("fainfo.txt", ios::in);
                fs.seekg(0);
                while (!fs.eof())
                {
                    fs.read((char *)&a, sizeof(Admin));
                    a.fadisplay();
                }
                fs.close();
            }
            if (tmp==4)
            {
                char tmpfaid[15];
                int de=0;
                int result=-1;
                cout<<"\n\t Enter the Faculty ID/Roll No.: ";
                cin>>tmpfaid;
                fstream fs;
                fs.open("fainfo.txt", ios::in);
                fstream fs1;
                fs1.open("fanewinfo.txt", ios::out|ios::ate);
                while (!fs.eof())
                {
                    fs.read((char *)&a, sizeof(Admin));
                    result=strcmp(tmpfaid, a.rollno);
                    if (result==0)
                    {
                        de=1;
                    }
                    else
                    fs1.write((char*)&a, sizeof(Admin));
                }
                if (de==1)
                {
                    cout<<"\nRecord Deleted Successfully ";
                }
                else
                {
                    cout<<"\nRecord not found ";
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("fanewinfo.txt","fainfo.txt");
            }
            if (tmp==5)
            {
                cout<<"\n\t Enter the Details: ";
                fstream fs;
                fs.open("stinfo.txt", ios::in|ios::out|ios::ate);
                a.getstdata();
                fs.write((char *)&a, sizeof(Admin));
                fs.close();
                cout<<"\n Record Entered Successfully! ";
            }
            if (tmp==6)
            {
                int m=0;
                fstream fs;
                fs.open("stinfo.txt", ios::in|ios::out|ios::ate);
                do
                {
                    cout<<"\n\t Enter the details: ";
                    a.getstdata();
                    fs.write((char *)&a, sizeof(Admin));
                    cout<<"\n\t Press 0 if you want to enter more records: ";
                    cin>>m;
                }while (m==0);
                fs.close();
                cout<<"\n Record Entered Successfully! ";
            }
            if (tmp==7)
            {
                fstream fs;
                fs.open("stinfo.txt", ios::in);
                fs.seekg(0);
                while (!fs.eof())
                {
                    fs.read((char *)&a, sizeof(Admin));
                    a.stdisplay();
                }
                fs.close();
            }
            if (tmp==8)
            {
                char tmpstid[15];
                int de=0;
                int result=-1;
                cout<<"\n\t Enter the Student ID/Roll No.: ";
                cin>>tmpstid;
                fstream fs;
                fs.open("stinfo.txt", ios::in);
                fstream fs1;
                fs1.open("stnewinfo.txt", ios::out|ios::ate);
                while (!fs.eof())
                {
                    fs.read((char *)&a, sizeof(Admin));
                    result=strcmp(tmpstid, a.rollno);
                    if (result==0)
                    {
                        de=1;
                    }
                    else
                    fs1.write((char*)&a, sizeof(Admin));
                }
                if (de==1)
                {
                    cout<<"\nRecord Deleted Successfully ";
                }
                else
                {
                    cout<<"\nRecord not found ";
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("stnewinfo.txt","stinfo.txt");
            }
            if (tmp==9)
            {
                cout<<"\n\n\n\n\t\t\t\t THANK YOU ";
                getch();
                exit(0);
            }
            if (tmp<1||tmp>9)
            {
                clrscr();
                cout<<"\n\n\n\n\t\t\t\t Invalid Input ";
            }
            getch();
            cout<<"\n\t Press y: For More Operations Otherwise n: ";
            cin>>opera;
            if (opera!='y')
            {
                getch();
                clrscr();
                cout<<"\n\n\n\n\t\t\t\t THANK YOU ";
                getch();
            }
            
        }while(opera=='Y'||opera=='y');
    }//closing of admin login
    if(ch == 2)//faculty
    {
        clrscr();
        char un[20];
        int val , s = 0;
        cout<<"\n\t\t\tWelcome to the faculty login Page";
        cout<<"\nEnter the User Name : ";
        cin>>::un;
        fstream fs;
        fs.open("fainfo.txt" , ios::in | ios::binary);
        fs.seekg(0);
        while(!fs.eof())
        {
            val = -1;
            fs.read((char *)&f , sizeof(Admin));
            val = f.login();
            if(val == 1)
            {
                s = 1;
                break;
            }
        }
        fs.close();
        if(s==1)
        {
            clrscr();
        }    
        //If first Login Is valid
        if(s!=1) // If Invalid
        {
            clrscr();
            int ho = 0;
            cout<<"\n\t\tYour Login Credentials are Incorrect";
            cout<<"\nThe UserName is Your ID/RollNo";
            cout<<"\nThe Password Is Case Sensitive";
            cout<<"\nPress 1 to recover Pass or press 2 to Re Attempt";
            cout<<"\nEnter Your Choice : ";
            cin>>ho;
            if(ho==1)//Recover Pass
            {
                cout<<"Enter The User Name : ";
                cin>>::un;
                fstream fs;
                fs.open("fainfo.txt" , ios::in|ios::binary);
                fs.seekg(0);
                int re,su = -1;
                while(!fs.eof())
                {
                    re = -1;
                    fs.read((char*)&f , sizeof(Admin));
                    re = f.recover();
                    if(re == 1)
                    {
                        su = 1;
                        break;
                    }
                }
                fs.close();
                if(su == 1)
                {
                    getch();
                    clrscr();
                    cout<<"\n\n\n\n\t\t\tThank You !!! ";
                    getch();
                    exit(0);
                }
                else
                {
                    cout<<"\nYou Are a Invalid User ";
                    getch();
                    exit(0);
                }
            }
            if(ho == 2)
            {
                cout<<"\nEnter the User Name  : ";
                cin>>::un;
                fstream fs;
                fs.open("fainfo.txt" , ios::in | ios::binary);
                fs.seekg(0);
                int suc = -1 , valu;
                while(!fs.eof())
                {
                    valu = -1;
                    fs.read((char *)&f, sizeof(Admin));
                    valu=f.login();
                    if(valu == -1)
                    {
                        suc = 1;
                        break;
                    }
                }
                fs.close();
                if(suc == 1)
                {
                    clrscr();
                }
                else
                {
                    getch();
                    cout<<"\nYou Are Invalid User..";
                    cout<<"Thank You ...";
                    getch();
                    exit(0);
                    exit(0);
                }
            }
            if(ho != 1 && ho != 2)
            {
                cout<<"\nInvalid Input Provided ";
                cout<<"\n\n\t\t\tThank You !!!";
                getch();
                exit(0);
            }
        }
        char con = 'y';
        do
        {
            clrscr();
            cout<<"\n\n\t\tWelcome to The Faculty Panel ";
            cout<<"\n\n\t\t\t\t\t    Your User Id is  : "<<::un ;
            cout<<"\n\nPress 1 to View Your Profile ";
            cout<<"\nPress 2 to know your subjects ";
            cout<<"\nPress 3 to Add a Subject ";
            cout<<"\nPress 4 to Delete a Subject ";
            cout<<"\nPress 5 to Modify Your Profile ";
            int choice;
            cout<<"\nEnter Your Choice ";
            cin>>choice;
            if(choice == 1)
            {
                fstream fs;
                fs.open("fainfo.txt" , ios::in);
                fs.seekg(0);
                int x;
                while(!fs.eof())
                {
                    x = 0;
                    fs.read((char*)&f , sizeof(Admin));
                    x = f.faprofile();
                    if(x==1)
                    {
                        break;
                    }
                }
                fs.close();
            }
            if(choice == 2)
            {
                fstream fs;
                fs.open("fainfo.txt" , ios::in);
                fs.seekg(0);
                int y;
                while(!fs.eof())
                {
                    y = 0;
                    fs.read((char*)&f , sizeof(Admin));
                    int y = f.knowfasub();
                    if(y==1)
                    {
                        break;
                    }
                }
                fs.close(); 
            }
            if(choice == 3)
            {
                fstream fs;
                fstream fs1;
                fs.open("fainfo.txt" , ios::in | ios :: binary);
                fs1.open("tmpfainfo.txt" , ios::out | ios :: ate);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char*)&f , sizeof(Admin));
                    f.addfasub();
                    fs1.write((char*)&f , sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("tmpfainfo.txt","fainfo.txt");
            }
            if(choice == 4)
            {
                fstream fs;
                fs.open("fainfo.txt" , ios::in | ios::binary);
                fstream fs1;
                fs1.open("delfainfo.txt" , ios::out | ios :: ate);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char*)&f , sizeof(Admin));
                    f.delfasub();
                    fs1.write((char*)&f , sizeof(Admin));
                }
                fs.close(); 
                fs1.close();
                remove("fainfo.txt");
                rename("delfainfo.txt" , "fainfo.txt");
            }
            if(choice == 5)
            {
                fstream fs;
                fstream fs1;
                fs.open("fainfo.txt" , ios::in | ios :: binary);
                fs.seekg(0);
                fs1.open("modfainfo.txt" , ios::out | ios :: ate);
                while(!fs.eof())
                {
                    fs.read((char*)&f , sizeof(Admin));
                    f.modfaprofile();
                    fs1.write((char*)&f , sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("modfainfo.txt","fainfo.txt"); 
            }
            if(choice<1 || choice>5)
            cout<<"\nInvalid Input Provided !!!";
            cout<<"\n\n\t\t\t\tEnter To continue ";
            getch();
            cout<<"\n\nPress y to continue ; otherwise press n : ";
            cin>>con;
            if(con != 'y' && con != 'Y')
            {
                clrscr();
                cout<<"\n\n\n\n\n\t\t\t\tThank You !!! ";
                getch();
                exit(0);
            }
        }while(con == 'y' || con == 'Y');
    }//close of faculty view
    //begin of student view
    if(ch==3)
    {
	    clrscr();
	    //char un[20];
	    int value,s1=0;
	    cout<<"\n\t\t\t	Welcome to Student Login Page";
	    cout<<"\n\nEnter the UserName : ";
	    cin>>::un;
	    fstream fs;
	    fs.open("stinfo.txt",ios::in|ios::binary);
	    fs.seekg(0);
	    while(!fs.eof())
	    {
		    value=-1;
		    fs.read((char *)&f, sizeof(Admin));
		    value=f.login();
		    if(value==1)
		    {
			    s1=1;
			    break;
		    }
	    }
	    fs.close();
	    if(s1==1)
	    {
		    clrscr();
	    }//if first login is valid
	    if(s1!=1)
	    {
		    clrscr();
		    int sho=0;
		    cout<<"\n\t\t Your Login Credentials are In-Correct";
		    cout<<"\nThe UserName is your ID/Rollno.";
		    cout<<"\nThe Password is Case-Sensitive.";
		    cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login";
		    cout<<"\nEnter the Choice : ";
		    cin>>sho;
		    if(sho==1)
		    {
			    cout<<"Enter the UserName :- ";
			    cin>>::un;
			    fstream fs;
			    fs.open("stinfo.txt",ios::in|ios::binary);
			    fs.seekg(0);
			    int re,su=-1;
			    while(!fs.eof())
			    {
				    re=-1;
				    fs.read((char *)&f, sizeof(Admin));
				    re=f.recover();
				    if(re==1)
				    {
					    su=1;
					    break;
				    }
			    }
			    fs.close();
			    if(su==1)
			    {
				    getch();
				    clrscr();
				    cout<<"\n\n\n\n\t\t\tThank You !!! ";
				    getch();
				    exit(0);
			    }
			    else
			    {
				    cout<<"\n You are a Invalid User.";
				    cout<<"\nThank you !!! ";
				    getch();
				    exit(0);
			    }
		    }//recover password
		    if(sho==2)
		    {
			    cout<<"\n\nEnter the UserName";
			    cin>>::un;
			    fstream fs;
			    fs.open("stinfo.txt",ios::in|ios::binary);
			    fs.seekg(0);
			    int suc=-1,valu; //valu for storing login() returned value suc for success login
			    while(!fs.eof())
			    {
				    valu=-1;
				    fs.read((char *)&f, sizeof(Admin));
				    valu=f.login();
				    if(valu==1)
				    {
					    suc=1;
					    break;
				    }
			    }
			    fs.close();
			    if(suc==1)
			    {
				    clrscr();
			    }
			    else
			    {
				    getch();
				    cout<<"\n You are an Invali-User...";
				    cout<<"\n Thank You";
				    getch();
				    exit(0);
				    exit(0);
			    }
		    }
		    if(sho!=1 && sho!=2)
		    {
			    cout<<"\n\nInvalid Input Provided. ";
			    cout<<"\n\n\t\t Thank You !!!";
			    getch();
			    exit(0);
		    }
	    }//closing of first invalid login (forget password and recover password)
	    //getch();
	    //begin of student panel
	    char moreop='y';
	    do
	    {
		    clrscr();
		    cout<<"\n\n\t\t\tWelcome to Student Panel ";
		    cout<<"\n\n\t\t\t\t\t\t Your UserId is : "<<::un;
		    cout<<"\n Press 1 to View Your Profile.";
		    cout<<"\n Press 2 to Know Your Subjects.";
		    cout<<"\n Press 3 to Add a Subject.";
		    cout<<"\n Press 4 to Delete a Subject.";
		    cout<<"\n Press 5 to Modify Your Profile.";
		    int inchoice;
            cout<<"\n Enter your choice: ";
            cin>>inchoice;
		    if(inchoice==1)
		    {
			    fstream fs;
			    fs.open("stinfo.txt",ios::in);
			    fs.seekg(0);
			    int x;
			    while(!fs.eof())
			    {
				    x=0;
				    fs.read((char *)&f, sizeof(Admin));
				    x=f.stprofile();
				    if(x==1)
				    {
					    break;
				    }
			    }
			    fs.close();
		    }//closing of inchoice =1
		    if(inchoice==2)
		    {
			    fstream fs;
			    fs.open("stinfo.txt", ios::in);
			    fs.seekg(0);
			    int y;
			    while(!fs.eof())
			    {
				    y=0;
				    fs.read((char *)&f, sizeof(Admin));
				    int y=f.knowstsub();
				    if(y==1)
				    {
					    break;
				    }
			    }
			    fs.close();
		    }//closing of choice =2
		    if(inchoice==3)
		    {
			    fstream fs;
			    fstream fs1;
			    fs.open("stinfo.txt",ios::in|ios::binary);
			    fs1.open("tmpstinfo.txt",ios::out|ios::ate);
			    fs.seekg(0);
			    while(!fs.eof())
			    {
				    fs.read((char *)&f, sizeof(Admin));
				    f.addstsub();
				    fs1.write((char *)&f, sizeof(Admin));
			    }
			    fs.close();
			    fs1.close();
			    remove("stinfo.txt");
			    rename("tmpstinfo.txt","stinfo.txt");
		    }//closing of choice=3
		    if(inchoice==4)
		    {
			    fstream fs;
			    fs.open("stinfo.txt",ios::in|ios::binary);
			    fstream fs1;
			    fs1.open("delstinfo.txt",ios::out|ios::ate);
			    fs.seekg(0);
			    while(!fs.eof())
			    {
				    fs.read((char *)&f, sizeof(Admin));
				    f.delstsub();
				    fs1.write((char *)&f, sizeof(Admin));
			    }
			    fs.close();
			    fs1.close();
			    remove("stinfo.txt");
			    rename("delstinfo.txt","stinfo.txt");
		    }
		    if(inchoice==5)
		    {
			    fstream fs;
			    fstream fs1;
			    fs.open("stinfo.txt",ios::in|ios::binary);
			    fs.seekg(0);
			    fs1.open("modstinfo.txt",ios::out|ios::ate);
			    while(!fs.eof())
			    {
				    fs.read((char *)&f, sizeof(Admin));
				    f.modstprofile();
				    fs1.write((char *)&f, sizeof(Admin));
			    }
			    fs.close();
			    fs1.close();
			    remove("stinfo.txt");
			    rename("modstinfo.txt","stinfo.txt");
		    }
		    if(inchoice<1||inchoice>5)
		    cout<<"Invalid Input Provided...";
		    cout<<"\n\n\t\t\t Enter to Continue ";
		    getch();
		    cout<<"\n\nPress y , otherwisen to Perform More Operations : ";
		    cin>>moreop;
		    if(moreop!='Y' && moreop!='y')
		    {
			    clrscr();
			    cout<<"\n\n\n\t\t\t Thank You !!!";
			    getch();
			    exit(0);
		    }
	    }while(moreop=='Y'||moreop=='y');
	    getch();
    }//closing of student panel ch=3
    if(ch<1||ch>3)
    {
	    cout<<"\nInvalid Input Provided !!! ";
	    getch();
	    clrscr();
	    cout<<"\n\n\n\t\t\tThank You";
    }
}