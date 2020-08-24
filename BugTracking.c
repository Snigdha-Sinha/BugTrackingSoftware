#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

//Creating an array of structures
struct Bug{
	char name[40];
	char type[40];
	char status[40];
	char priority[40];
	char desc[100];
	int id;
};


void getTime(FILE *fp)
{
    
    struct timeval usec_time;
    time_t now = time(0);
    gettimeofday(&usec_time,NULL);
    // format time
    struct tm *current = localtime(&now);
    printf("Time of bug entry: %d:%d:%d\n",current->tm_hour, current->tm_min, current->tm_sec);
    fprintf(fp,"Time of bug entry: %d:%d:%d\n",current->tm_hour, current->tm_min, current->tm_sec);
}

int main(){
	int i=0;
	int f=0;
	int f1=0;
	char namereq[40];
	char cat[15];
	char status_req[15];
	int change_status;
	char new_status[20];
	struct Bug bugs[40];
	int state=1;
	FILE *fp=fopen("bugs_desc","w");
	while(state==1)
    	{
		printf("1. To file a bug.\n");
		printf("2. To change the status of a bug.\n");
		printf("3. To display list of bugs filed by specific user.\n");
		printf("4. To display list of bugs of same category.\n");
		printf("5. To display list of bugs having same status.\n");
		
		int choice;
		printf("Enter your choice :");
		scanf("%d",&choice);
		int id;
		switch (choice)
		{
			case 1:
				
				printf("Enter your name: ");
				scanf("%s",bugs[i].name);
				fprintf(fp,"Name of user: %s\n",bugs[i].name);

				printf("enter a brief description of the bug:\n"); 	//accepting all necessary details
				fflush(stdin);
				scanf("%[^\n]",bugs[i].desc);
				
				id=rand();
				bugs[i].id=id;
				fprintf(fp,"Id of the bug: %d \n",id);
				printf("Id of the bug: %d \n",id);
				
				getTime(fp);

				printf("Enter type of bug: Major/Minor/Cosmetic\n");	
				scanf("%s",&bugs[i].type);
				fprintf(fp,"Type of bug: %s \n",bugs[i].type);
				
				printf("Enter priority of bug: Low/Medium/High \n");
				scanf("%s",&bugs[i].priority);
				fprintf(fp,"Priority of the bug: %s \n",bugs[i].priority);
				
				printf("Enter status of bug: unassigned/processing/Fixed/Delivered \n");
				scanf("%s",&bugs[i].status);
				fprintf(fp,"Status of the bug: %s\n \n",bugs[i].status);
				
				i++;
				break;

			case 2:
				printf("Enter the id of the bug whose status is to be changed: ");
				scanf("%d",&change_status);
				for(int x=0;x<20;x++)
				{
					if(bugs[x].id==change_status)
					{
						printf("Enter new status: Assigned/Fixed/Delivered: ");
						scanf("%s",new_status);
						strcpy(bugs[x].status,new_status);
						f=1;
						break;
					}
				}
				if(f==0)
				printf("No such bug id exists in the file.\n");
				break;

			case 3:
				printf("Enter name of user: ");
				scanf("%s",namereq);
				int j;
				for(j=0;j<20;j++)
				{
					if(strcmp(bugs[j].name,namereq)==0){
					printf("ID: %d\n",bugs[j].id);
					printf("Type: %s, Status: %s, Priority: %s\n",bugs[j].type,bugs[j].status,bugs[j].priority);
					f1++;}
				}
				if(f1==0)
				printf("no such user found\n");
				break;

			case 4:
				printf("Enter category required: Major/Minor/Cosmetic");
				scanf("%s",cat);
				int k;
				printf("The IDs of bugs of required category are: \n");
				for(k=0;k<20;k++)
				{
					if(strcmp(bugs[k].type,cat)==0)
					printf("%d\n",bugs[k].id);
				}
				break;

			case 5:
				printf("Enter status required: unassigned/processing/Fixed/Delivered ");
				scanf("%s",status_req);
				int l;
				printf("The IDs of bugs of required category are: \n");
				for(l=0;l<20;l++)
				{
					if(strcmp(bugs[l].status,status_req)==0)
					printf("%d\n",bugs[l].id);
				}
				break;


			default:
				printf("Invalid choice. Enter a choice between 1-5");
				break;
		
		}
		printf("\nDo you want to continue?\n");
		printf("Enter 1 for YES, 0 for NO\n");
		scanf("%d",&state);
	}
	
}