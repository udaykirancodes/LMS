//ITS WORKING FINE //
//LMS CODE 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include"fun.c"
// #include"fun.c"

struct student{
    char id[10];
    char password[10];
    char name[15];
};
struct faculty{
    char id[10];
    char password[10];
    char name[15];
};


struct notes{
    char sub1[100];
    char sub2[100];
    char sub3[100];
};


void reg(){     
    int n;
    printf("\n*1.Administration");
    printf("\n*2.Student");
    printf("\nChoose : \n");
    scanf("%d",&n);
    if(n==2){
        struct student f;
        FILE *fp;
        fp=fopen("stu.txt","a");
        if(fp==NULL){
            printf("\n**ERROR IN WRITING DATA**");
        }
        printf("\nEnter ID : ");
        scanf("%s",&f.id);
        printf("\nEnter Password : ");
        scanf("%s",&f.password);
        printf("\nEnter Name : ");
        scanf("%s",&f.name);
        fwrite(&f , sizeof(f) , 1, fp);
        fclose(fp);
        printf("Your ID : %s \n",f.id);
        printf("Your Password : %s \n",f.password);
    }

    else if(n==1){
        struct faculty f;
        FILE *fp;
        fp=fopen("adm.txt","a");
        if(fp==NULL){
            printf("\n**ERROR IN WRITING DATA**");
        }
        
        printf("\nEnter ID : ");
        scanf("%s",&f.id);
        printf("\nEnter Password : ");
        scanf("%s",&f.password);
        printf("\nEnter Name : ");
        scanf("%s",&f.name);
        fwrite(&f , sizeof(f) , 1, fp);
        fclose(fp);
        printf("Your ID : %s \n",f.id);
        printf("Your Password : %s \n",f.password);
    }
    else{
        printf("\n*Error");
    }
    

}
void show(){
    int i=1;
    FILE *fp;
    struct student s;
    fp=fopen("stu.txt","r");
    if(fp==NULL){
        printf("\n**ERROR IN READING DATA**");
    }
    // else{
    //     printf("\n\tNAME\t\t\t\t\tID\t\t\t\t\t\tPASSWORD\n");
    // }
    printf("\nSTUDENT DATA :- \n");
    while(fread(&s,sizeof(s),1,fp)){
        printf("\n%d\t%s\t\t\t%s\t\t\t\t%s\n",i,s.name,s.id,s.password);
        i++;
    }
    fclose(fp);
}

void providenotes(){
    char notes[200];
    struct notes n;
    FILE *fp;
    fp=fopen("notes.txt","a");

    int s=1;
    printf("\nEnter Subject Number : 1-3 \n");
    scanf("%d",&s);

    if(s==1){
        printf("\nEnter Notes/Link of Video (sub1): \n");
        scanf("%s",&n.sub1);     

    }
    else if(s==2){
        printf("\nEnter Notes/Link of Video (sub2): \n");
        scanf("%s",&n.sub2);        
    }
    else if(s==3){
        printf("\nEnter Notes/Link of Video (sub3): \n");
        scanf("%s",&n.sub3);
    }
    else{
        printf("\nError Input\n");
    }

    fwrite(&n,sizeof(n),1,fp);
    printf("\n!!!DATA HAS BEEN SHARED!!!\n");
    fclose(fp);
    
   
    

}
void takenotes(){
    FILE *fp;
    fp=fopen("notes.txt","r");
    struct notes n;

    int s;
    printf("\nEnter Subject Number : 1-3\n");
    scanf("%d",&s);

    int i=1;
    
    while(fread(&n , sizeof(n),1,fp)){

        if(s==1){
            printf("\t%d\t%s\n",i,n.sub1);
            i++;
        
        }
        else if(s==2){
            printf("\t%d\t%s\n",i,n.sub2);
            i++;  

        }
        else if(s==3){
            printf("\t%d\t%s\n",i,n.sub3);
            i++;
        }
        else{
            printf("\nError Input\n");
        }

        
    }
       
    
    fclose(fp);
    
}
void facultydatashow(){
    struct faculty f;
    FILE *fp;
    fp=fopen("adm.txt","r");
    printf("\n**Only Names will be printed Due to privacy**\n\n");
    int i=1;
    while(fread(&f , sizeof(f),1,fp)){
        printf("\t%d\t\t%s\n",i,f.name);
        i++;
    }
    fclose(fp);
}
void studentsearch(){
    struct student s;
    FILE *fp;
    fp=fopen("stu.txt","r");
    char id[10];
    printf("\nEnter ID To Search : ");
    scanf("%s",&id);
    int found=0;
    while(fread(&s,sizeof(s),1,fp)){
        if(strcmp(id,s.id)==0){
            found=1;
            printf("\n\t%s\t\t\t%s\t\t\t\t%s\n",s.name,s.id,s.password);
        }
    }
    if(found==0){
        printf("\n*Data_Not_Found");
    }
}
int loginto(){
    int n;
    int login,a;
    printf("\n*1.Administration");
    printf("\n*2.Student");
    printf("\nChoose : \n");
    scanf("%d",&n);
    if(n==1){
    
        struct student s;
        char id[10];
        char password[10];
        
        printf("\nEnter ID : ");
        scanf("%s",&id);
        printf("\nEnter Password : ");
        scanf("%s",&password);
        

        FILE *fp;
        fp=fopen("adm.txt","r");
        if(fp==NULL){
            printf("\n**ERROR IN READING DATA**");
        }
        while(fread(&s,sizeof(s),1,fp)){
            if(strcmp(password,s.password)==0 && strcmp(id,s.id)==0){
                printf("\n**LOGGED IN**\n");
                login=1;
            
            }
            
            
        }
        
        if(login==1){
        // faculty:
            printf("\n1.SHOW_STUDENT_DATA");
            printf("\n2.PROVIDE_NOTES ");
            // printf("\n3.PASSWORD_CHANGE ");
            printf("\n3.SEARCH_WITH_STUDENT_ID ");
            printf("\n4.EXIT");
            printf("\nChoose : \n");
            scanf("%d",&a);
            if(a==1){
                show();
            }
            else if(a==2){
                providenotes();
            }
           
            else if(a==3){
                studentsearch();
            }
            else if(a==4){
                return 0;
            }
            else{
                printf("\n***WRONG_INPUT***");
                
            }
            // goto faculty;
        }

        else{
        	printf("\nWRONG USERNAME/PASSWORD");
		}
        return 2;

    }

    else if(n==2){
        
        struct student s;
        char id[10];
        char password[10];
        
        printf("\nEnter ID : ");
        scanf("%s",&id);
        printf("\nEnter Password : ");
        scanf("%s",&password);
        

        FILE *fp;
        fp=fopen("stu.txt","r");
        if(fp==NULL){
            printf("\n**ERROR IN READING DATA**");
        }
        while(fread(&s,sizeof(s),1,fp)){
            if(strcmp(password,s.password)==0 && strcmp(id,s.id)==0){
                printf("\n**LOGGED IN**\n");
                int login =1;
            
            }
            
            
        }
        if(login!=1){
        	printf("\nWRONG USERNAME/PASSWORD");
		}
        // student:
            printf("\n1.SHOW FACULTY DATA");
            printf("\n2.SHOW NOTES");
            // printf("\n3.CHANGE_PASSWORD ");
            printf("\nChoose : \n");
            scanf("%d",&a);
            // printf("\n3.EXIT");
            if(a==1){
                facultydatashow();
            }
            else if(a==2){
                takenotes();
            }
            else if(a==3){
                // changepassword(2);
            }

            // goto student;
        else{
            
        }

        return 1;


    }
    return 0;    
}

int main(){
    int n=1;

    // char password[100];
    // getstring(password);
    // printf("Your Pasword is : %s",password);

    while(n!=0){
        printf("\n\n***WELCOME TO LMS***");
        printf("\n1.SIGN IN\n2.SIGN UP\n\n0.Exit\n");
        printf("\nChoose : \n");
        scanf("%d",&n);
        char password[10];
        if(n==2){
            reg();
        }
        else if(n==1){
            loginto();
        }        
        
        else if (n==0){
            return 0;
        }        
        else{
            printf("\n*****_WRONG_INPUT_*****\n");
           
        }
    }
    return 0;
}
