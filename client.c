#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include"server.h"

int main(){
	int i=0;  // Loop variable
	int f=0;  // a counter variable
	int f1=0;
	char namereq[40];			//A string which will store the name of user required (for case 3)
	char cat[15];				//A string to store category of bugs whose list is reqd. (for case 4)
	char status_req[15];			//A string which will store the status whose list is to be displayed (case 5)
	int change_status;			//To store the id of the bug whose status is to be changed(case 2)
	char new_status[20];			// New status after being changed (case 2)
	struct Bug bugs[40];			//Array of structures
	
	int state=1;				
	FILE *fp=fopen("bugs_desc","w");	//Opening the file in "write" mode and storing in pointer fp
	while(state==1)
    	{
		//Displaying options

		printf("1. To file a bug.\n");
		printf("2. To change the status of a bug.\n");
		printf("3. To display list of bugs filed by specific user.\n");
		printf("4. To display list of bugs of same category.\n");
		printf("5. To display list of bugs having same status.\n");
		
		int choice;				//switch variable
		printf("Enter your choice :");
		scanf("%d",&choice);
		int id;
		switch (choice)
		{
			case 1:
				
				printf("enter a brief description of the bug:\n"); 	//accepting all necessary details
				fflush(stdin);
				scanf("%[^\n]",bugs[i].desc);

				printf("Enter your name: ");
				scanf("%s",bugs[i].name);
				fprintf(fp,"Name of user: %s\n",bugs[i].name);
				
				id=rand();						//To generate and store an id for a bug
				bugs[i].id=id;
				fprintf(fp,"Id of the bug: %d \n",id);
				
				getTime(fp);						//To display system time when bug is filed

				printf("Enter type of bug: Major/Minor/Cosmetic\n");	
				scanf("%s",bugs[i].type);
				fprintf(fp,"Type of bug: %s \n",bugs[i].type);
				
				printf("Enter priority of bug: Low/Medium/High \n");
				scanf("%s",bugs[i].priority);
				fprintf(fp,"Priority of the bug: %s \n",bugs[i].priority);
				
				printf("Enter status of bug: unassigned/processing/Fixed/Delivered \n");
				scanf("%s",bugs[i].status);
				fprintf(fp,"Status of the bug: %s\n \n",bugs[i].status);
				
				i++;
				break;

			case 2:
				printf("Enter the id of the bug whose status is to be changed: ");
				scanf("%d",&change_status);
				for(int x=0;x<20;x++)
				{
					if(bugs[x].id==change_status)					//Checking whether bug id equals the id required
					{
						printf("Enter new status: Assigned/Fixed/Delivered: ");
						scanf("%s",new_status);
						strcpy(bugs[x].status,new_status);			//Changing the status
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
					printf("Bug Description: %s \n",bugs[j].desc);
					printf("Type: %s, Status: %s, Priority: %s\n",bugs[j].type,bugs[j].status,bugs[j].priority);
					f1++;
					}
				}
				if(f1==0)
				printf("No such user found\n");
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