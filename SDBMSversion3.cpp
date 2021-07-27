//(A Shaban Khan Software v-1.2.0)
#include<iostream>
#include<string>
#include<fstream>


using namespace std;

class stud{
public:
    int roll;
    float marks;
    char name[20];
};

//for checking is password right or not
void password_set()
{
     //writing password to file
     
         ofstream ps;
         ps.open("POSDBS1.txt");
         string s;
          cout<<"Enter your New password (Do not use \"space\" key):";
          cin>>s;
         ps<<s<<endl;
         cout<<"Your password has been set successfully ";
         ps.close();
         
     
}
bool password_varify(string a)
{
    string line ;
    ifstream ps("POSDBS1.txt");
    getline(ps,line);
    if(a==line)
    {
        return true;
    }
    else 
    {
        return false;
    }
}



int main(){
    FILE *fp;
    int pop; int atmp=3; int snum; int l; int red; int eds; 
    char pwd[10]; int s1; bool fcheck=0;
    stud data[100]; int sop; char fdata;
    cout<<"||STUDENT DATABASE MANAGEMENT SYSTEM||";
    cout<<"\n\n\n\t\t1.Sign in : \n\n\t\t2.Exit";
    
    here:
    cout<<"\n\n\n\n (A Shaban Khan Software v-1.0.3)"<<endl;
    cin>>s1;
    
    if(s1==1)
    {
        goto penter;
    }
    else {
        goto bottom;
        }


     penter:
     cout<<"\n\nHello!! \nWelcome to students data base system.Select the following option.\n\n\n\n\n\t1.Enter password\n\t2.Forget password\n\n\n\nResponse_ ";
      cin>>pop;
    
    
    
    
    if(pop==1){
       
       pent:
        cout<<"\n\nEnter your password - ";
        cin>>pwd;
        
        if(password_varify(pwd)){
            cout<<"password match:\n\n\n";
            start:
            cout<<"\n\nWelcome to student data base. \nTo continue please chose one option.\n\n1.Write the data\n2.Read data\n3.Exit\n\n\nResponse_ ";
            cin>>sop;
            if(sop==1)
            {
                cout<<"Which Data you want to write? \n\n1.Rewrite for a single student \n2.Write Whole data\n3.Goto main page\n\nResponse_ ";
                cin>>red;
                if(red==2)
                {
                   //writing data to the file
                   fp=fopen("Shaban.txt","w");
                    cout<<"\n\nEnter the number of students:\nResponse_ ";
                   cin>>snum;
                   for(l=1;l<=snum;l++)
                   {
                       printf("\n\nData of student %d:\n",l);
                       printf("\nEnter roll : ");
                       scanf("%d",&data[l].roll);
                       printf("\nEnter name : ");
                       scanf("%s",data[l].name);
                       printf("\nEnter marks : ");
                       scanf("%f",&data[l].marks);
                    
                    }
                   printf("\n\n\n");
                       edited:
                    
                    fprintf(fp,"S.No  Roll\t    Name\t\tMarks\n");
                    for(l=1;l<=snum;l++)
                    {
                    
                       fprintf(fp,"%d.      %d\t\t",l,data[l].roll);
                       fprintf(fp,"%s",data[l].name);
                       fprintf(fp,"\t\t%2.2f\n",data[l].marks);
                    }
                    fprintf(fp,"\n\n\n");
                    printf("\n\nData has been stored successfully!\n\n");
                    fclose(fp);
                    goto start;
                    }
                
                
                else if(red==1){
                    //reading data from that file
                    fp=fopen("Shaban.txt","r");
                    
                    while(!feof(fp)){
                        
                        fdata=fgetc(fp);
                        printf("%c",fdata);
                        }
                    printf("\n\nEnter serial number you want to rewrite.\n\nResponse_ ");
                    scanf("%d",&eds);
                     fp=fopen("Shaban.txt","w");
                    printf("\n\nData of student %d:\n",eds);
                    printf("\nEnter roll : ");
                    scanf("%d",&data[eds].roll);
                    printf("\nEnter name : ");
                    scanf("%s",data[eds].name[20]);
                    printf("\nEnter marks : ");
                    scanf("%f",&data[eds].marks);
                    goto edited;
                    
                    }
                else if(red==3){
                    goto start;
                }
                else{
                    printf("Invalid Input ");
                    
                }
            }
            else if(sop==2){
                fp=fopen("Shaban.txt","r");
                
                while(!feof(fp)){
                    
                    fdata=fgetc(fp);
                    cout<<fdata;
                    }
                cout<<"\n\n";
                fclose(fp);
                goto start;

                
            }
            else if(sop==3){
                goto bottom;
            }
            else{
                cout<<"\nWrong input:";
                goto start;
            }
            
            
            }
        else{
            if(atmp==1)
            {
                cout<<"\n\nToo many wrong attemp!!\nProgram has been closed.\n\n\n\n\n\n";
                goto end;
            }
            atmp-=1;
            cout<<"\n\npassword wrong:\n";
            cout<<"Only "<<atmp<<" attempts left.\n\n\n";
            goto pent;
        
            
              
        }
        
        
        
    }
    else if(pop==2){
        
        
        cout<<"\n\t\t1.Create password : \n\n\n\n\nResponse_ ";
        
        
         password_set();
        
        
        goto penter;
    }
    
    else{
        cout<<"\n\nInvalid input !";
        goto penter;
    }
    
    
    
    
    
    bottom:
    end:


    cout<<"\n\n\n (A Shaban Khan Software v-1.0.3)"<<endl;
    return 0;
}
