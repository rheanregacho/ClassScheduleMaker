//initialize preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//initialize structure
typedef struct subject{
	char subjCode[20];
	int classHour;
}subj;

//function for sorting of time
void sortSched(subj *x, int num){
	
	subj temp;
	int i, j;
	for(i = 0; i < num; i++){
		for(j = 0; j < num; j++){
			if (x[i].classHour < x[j].classHour){
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
	
}

//functin for viewing entire sched
void viewSched(subj *x, int num){
	
	int i;
	printf("\n\t Class No. | Class Time Slot | Class Name\n");
	printf("\t ----------------------------------------\n");
	for(i = 0; i < num; i++){
		if(x[i].classHour <= 8){
			printf("\n\t     %d         0%d00-0%d00         %s", i+1, x[i].classHour, (x[i].classHour)+1, x[i].subjCode);
		} else if(x[i].classHour == 9){
			printf("\n\t     %d         0%d00-%d00         %s", i+1, x[i].classHour, (x[i].classHour)+1, x[i].subjCode);
		} else{
			printf("\n\t     %d         %d00-%d00         %s", i+1, x[i].classHour, (x[i].classHour)+1, x[i].subjCode);
		}
	}
	printf("\n");
	
}

//function for adding subjects
void addClass(subj *x, int num){
	
	int i;
	printf("\nClass name: ");
	scanf("%s", x[num].subjCode);
	printf("Class time slot (_th Hour): ");
	scanf("%d", &x[num].classHour);
	
	//checks if the time slot is within the range of allowed time of classes
	while ((x[num].classHour <= 6)||(x[num].classHour >= 21)){
		printf("\nGiven time is outside school hours.");
		printf("\nRe-enter time slot: ");
		scanf("%d", &x[num].classHour);
	}
	
	//checks if the time given is occupied already
	for(i = 0; i < num; i++){
		while(x[num].classHour == x[i].classHour){
			printf("\nTime conflicts with another class.");
			printf("\nRe-enter time slot: ");
			scanf("%d", &x[num].classHour);
		}
	}	
	
}

//function for removing subjects
void removeClass(subj *x, int num){
	
	int i, classNo;
	printf("\nEnter class number of the subject to be removed: ");
	scanf("%d", &classNo);
	for(i = classNo-1; i < num; i++){
		x[i] = x[i+1];
	}
	
	//checks if the given class number is within the total number of subjects
	while((classNo <= 0)||(classNo > num)){
		printf("\nThe given number is not included in the list.");
		printf("\nRe-enter class number: ");
		scanf("%d", &classNo);
	}
	
}

int main(){
	
	subj classes[10];
	int choice, num = 0;
	
	while(true){
		printf("\nSelection Menu: \n[1] Add Class \n[2] Remove Class \n[3] View Schedule \n[4] Exit Program \nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:{
				if(num<=9){
					addClass(classes, num);
					num++;
				} else{
					//prohibits user to use the function if num is equals to the maximum number of allowed subjects
					printf("\nYou have reached the maximum number of subjects allowed.\n");
				}
				break;
			}
			case 2:{
				if(num!=0){
					sortSched(classes, num);
					viewSched(classes, num);
					removeClass(classes, num);
					num--;
				} else{
					//prohibits user to use the function if no classes are to be removed
					printf("\nYour schedule is empty.\n");
				}
				break;
			}
			case 3:{
				if(num!=0){
					sortSched(classes, num);
					viewSched(classes, num);
				} else{
					//prohibits user to use the function if no classes are to be viewed
					printf("\nYour schedule is empty.\n");
				}
				break;
			}
			case 4:{
				//exits the program
				exit(0);
			}
			default:{
				//displays an appropriate message if choice is not included in the menu
				printf("\nYour choice is not included.\n");
				break;
			}
		}
		
	}
	
}
