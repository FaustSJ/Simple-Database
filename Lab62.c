#import <stdio.h>
#import <stdlib.h>

typedef struct EmployeeStruct
{
        char LastName[20];
        char FirstName[20];
        int EmployeeNumber;  // Holds the employee's ID. This value is
                                 // equal to the number of employees
        struct EmployeeStruct *next;  // Pointer to the next most recently hired Employee
}Employee;

Employee* hireEmployee(Employee* Tail, char LastName[20], char FirstName[20]);
Employee* promoteEmployee(Employee* Head);
Employee* getnextPromotionCandidate(Employee* Head);
void printEmployees(Employee* Head);
void DeletePromotionRoster(Employee* Head);


int main()
{

        int pick = -1;
        Employee *head;
        Employee *tail;
        head = NULL;
        tail = NULL;


        while(pick!=5)
        {
                printf("Welcome to the Employee Management Program!\n");
                printf("\t1. Hire an employee\n");
                printf("\t2. Promote an employee\n");
                printf("\t3. Print next employee in line for a promotion\n");
                printf("\t4. Print out a list of all the employees\n");
                printf("\t5. Quit\n");
                scanf("%d",pick);

                if(pick==1)
                {
                        char lName[20];
                        char fName[20];
                        printf("What is the employee's first name?\n");
                        getchar();
			scanf("%s",fName);
                        printf("What is the employee's last names?\n");
			getchar();
                        scanf("%s",lName);
                        
                        if(head==NULL)
			{
				int i;
				for(i=0; i<(sizeof(fName)/sizeof(fName[0])); i++)
                        		head->FirstName[i] = fName[i];
                                for(i=0; i<(sizeof(lName)/sizeof(lName[0])); i++)
                                        head->LastName[i] = lName[i];
                        	head->EmployeeNumber = 1;
                        	head->next = tail;
                        	
				for(i=0; i<(sizeof(fName)/sizeof(fName[0])); i++)
                                        tail->FirstName[i] = fName[i];
                                for(i=0; i<(sizeof(lName)/sizeof(lName[0])); i++)
                                        tail->LastName[i] = lName[i];
                        	tail->EmployeeNumber = 1;
                        	tail->next = NULL;
                        }
                        if(head!=NULL)
                        {
                        	tail =  hireEmployee(tail, lName, fName);
                        	if(tail->EmployeeNumber == 2)
                        		head->next = tail;
                        }
                        
                        printf("The employee was hired.");
                }
                if(pick==2)
                {
                		head = promoteEmployee(head);
                }
                if(pick==3)
                {
                		Employee *promo;
                		promo = getnextPromotionCandidate(head);
				if(promo!=NULL)
				{
                			printf("%s %s ",promo->FirstName,promo->LastName);
                			printf("is next in line for a promotion.\n");
				}
                		free(promo);
                }
                if(pick==4)
                {
                		printEmployees(head);
                }
                if(pick==5)
                {
                		DeletePromotionRoster(head);
                        	printf("Goodbye!");
                }
        }
        return 0;
}

// Precondition:  A pointer to the end of the queue is passed in, the new hire's
//                name is passed in via two cstring parameters, and the maximum
//                number of employees has not been reached.
// Postcondition: A new employee with the given name has been added to the employee
//                roster. The new queue tailptr is returned to the calling function.
Employee* hireEmployee(Employee* Tail, char LastName[20], char FirstName[20])
{
		Employee *n00b;
		n00b = (Employee*)malloc(sizeof(Employee));
		int i;
		for(i=0; i<(sizeof(LastName)/sizeof(LastName[0])); i++)
                        n00b->LastName[i] =  LastName[i];
                for(i=0; i<(sizeof(FirstName)/sizeof(FirstName[0])); i++)
                	n00b->FirstName[i] = FirstName[i];
		n00b->EmployeeNumber = Tail->EmployeeNumber + 1;
		n00b->next = NULL;
		Tail->next = n00b;
		return n00b;
}

//  Precondition:  A pointer to the front of the queue is passed in as a parameter,
//                 and at least one employee remains with the company.
//  Postcondition:  The employee with the highest seniority is removed from the employee
//                  roster and an appropriate statement about who was promoted is printed
//                  to the screen.  A pointer to the new front of the queue is returned
//                  to the calling function.
Employee* promoteEmployee(Employee* Head)
{
		printf("%s %s ",Head->FirstName,Head->LastName);
		printf("with ID %d ",Head->EmployeeNumber);
		printf("was just promoted!\n");
		Employee *temp;
		temp = Head->next;
		free(Head);
		return temp;
}

//  Precondition:   A pointer to the front of the queue is passed in as a parameter.
//  Postcondition:  A pointer to a NEW node containing the information for the employee
//                  with the highest seniority is returned to the calling function.
//                  The employee promotion roster is left unchanged.  If the company
//                has NO current employees in the promotion queue, an appropriate message
//                  is printed to the screen and a NULL pointer is returned.
Employee* getnextPromotionCandidate(Employee* Head)
{
		if(Head==NULL)
		{
			printf("There aren't any employees hired yet!\n");
			return NULL;
		}
		Employee *temp;
		temp = (Employee*)malloc(sizeof(Employee));
		temp = Head;
		return temp;
}

//  Precondition:   A pointer to the head of the queue is passed in as a parameter.
//  Postcondition:  Prints the first and last names of all employees in the Roster,
//              in the order of seniority (oldest employee to the most recently hired).
void printEmployees(Employee* Head)
{
		Employee *temp;
		temp = (Employee*)malloc(sizeof(Employee));
		temp = Head;
		printf("\n");
		while(temp!=NULL)
		{
				printf("%s %s\n", temp->FirstName, temp->LastName);
				if(temp->next!=NULL)
				{
					temp = temp->next;
				}
				if(temp->next==NULL)
					temp=NULL;
		}
}

//  Precondition:  A pointer to the front of the Queue is passed in as a parameter.
//  Postcondition: All nodes in the Employee Promotion Roster have been deleted, and
//                 an appropriate message has been printed to the screen.
void DeletePromotionRoster(Employee* Head)
{
		Employee *temp;
		temp = (Employee*)malloc(sizeof(Employee));
		temp = Head;
		Employee *temp2;
		temp2 = (Employee*)malloc(sizeof(Employee));
		while(temp!=NULL)
		{
				
				if(temp->next!=NULL)
				{
					temp2 = temp2->next;
					free(temp);
					Employee *temp;
					temp = temp2;
				}
				if(temp->next==NULL)
					temp=NULL;
		}
		free(temp2);
		free(temp);
}
