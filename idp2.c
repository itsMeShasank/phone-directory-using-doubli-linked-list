#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<time.h>
struct contact
{
	long long int num;		
	char str1[300];
	struct contact *nxt,*prev;
}*head,*temp,*ptr,*cpy,*tr,*prv,*p,*ser,*del,*b;
int x,n,flag=0;
int checkNumLen(long long int num){
	int len=0;
	while(num!=0){
		len++;
		num/=10;
		
	}
	if(len==10)
		return 1;
	else{
		printf("\n\t\t**Check Length of Number**\n");
		return 0;}
}

int checkName(char name[]){
	ptr = head;
	while(ptr!=NULL){
		int val = strcmp(name,ptr->str1);
		if(val==0){
			printf("\n**Similar Name Exixts***\n");
			return 0;}
		ptr = ptr->nxt; 
	}
	return 1;
}
void sort()
{
	struct contact *i,*j;
	int temp;
	char n[300];long long int no;
	if(head == NULL)
	{
		printf("DATA NOT FOUND.\n");
	}
	else
	{
		for(i=head;i->nxt!=NULL;i = i->nxt)
		{
			for(j=i->nxt;j!=NULL;j=j->nxt)
			{
				temp = strcmp(i->str1,j->str1);
				if(temp>0)
				{
					strcpy(n,i->str1);
					no = i->num;
					strcpy(i->str1,j->str1);
					i->num = j->num;
					strcpy(j->str1,n);
					j->num = no;
				}
			}
		}
	}
}
void creation()
{

	long long int mbl;
	char s[300];
	printf("Enter the name:");
	scanf("%s",&s);
	printf("Enter the number:");
	scanf("%lld",&mbl);
	if(checkNumLen(mbl)==1 && checkName(s)==1)
	{
		if(flag==0 || head == NULL)
		{
			head = (struct contact*)malloc(sizeof(struct contact));
			head->num = mbl;
			strcpy(head->str1,s);
			head->prev = NULL;
			head->nxt = NULL;
			cpy = head;
			flag=1;
		}							//2
		else
		{ 	ptr = head;
			while(ptr->nxt!=NULL)
			{
				ptr = ptr->nxt;
			}
			cpy = ptr;
			temp = (struct contact*)malloc(sizeof(struct contact));
			temp->num = mbl;
			strcpy(temp->str1,s);
			temp->prev = cpy;
			cpy->nxt = temp;
			temp->nxt = NULL;
			cpy = cpy->nxt;
		}
		printf("DATA entered.\n");
		sort();
	}
}
void deleteContact()
{
	char find[300];int len = 0,pos = 1,flag = 0;
	printf("Enter the data to be deleted:");
	scanf("%s",&find);
	ptr = head;
	while(ptr!=NULL)
	{
		ptr = ptr->nxt;
		len+=1;
	}
	ptr = head;
	while(ptr!=NULL)
	{							//3
		if(strcmp(ptr->str1,find) == 0)
		{
			flag = 1;
			break;
		}
		pos+=1;
		ptr = ptr->nxt;
	}
	if(flag == 1)
	{
		if(pos == 1 && len > 1)
		{
			del = head;
			head = head->nxt;
			free(del);
			printf("DATA DELETED.\n");
		}
		else if(pos == 1 && len == 1)
		{
			del = head;
			head = head->nxt;
			free(del);
			head = NULL;
			printf("DATA DELETED.\n");
		}
		else if(pos!=len)
		{
			p = head;
			prv = head;
			p = p->nxt;				//4
			while(p!=NULL)
			{
				if(strcmp(p->str1,find) != 0)
				{
					p = p->nxt;
					prv = prv->nxt;
				}
				else
				{
					break;
				}
			}
			if(p->nxt == NULL)
			{
				p->prev->nxt = NULL;
				p->prev = NULL;
				free(p);
				printf("DATA DELETED.\n");
			}
			else
			{
				prv->nxt = p->nxt;
				p->prev = p->nxt = NULL;
				free(p);
				printf("DATA DELELTED.\n");
			}
		}
		if(pos == len)
		{
			p=head;
			while(p->nxt!=NULL)
			{
				 p = p->nxt;
			}
			p->prev->nxt = NULL;
			p->prev = NULL;
			free(p);
			printf("DATA DELETED.\n");
		}
	}
	else
	{
		printf("DATA NOT FOUND!!\n");
	}
	p = head;
	while(p!=NULL)
	{
		p = p->nxt;
	}
	
}
void search()
{
	char src[300],newname[300];long long int newn;int x,y,o=0;
	printf("Enter the name to be searched:");
	scanf("%s",&src);
	ser = head;
	while(ser!=NULL)
	{
		if(strcmp(ser->str1,src)==0)
		{
			o+=1;
			printf("DATA FOUND.\n");
			printf("name\tnumber\n");	//7
			printf("--------------------------------------------------------------\n");
			printf("%s\t\t%lld\n",ser->str1,ser->num);
			printf("--------------------------------------------------------------\n");
			printf("1.edit contact.\n2.back to menu.\n");
			printf("--------------------------------------------------------------\n");
			printf("enter the option diplayed above:");
			scanf("%d",&x);
			switch(x)
			{
				case 1:
					printf("--------------------------------------------------------------\n");
					printf("1.change the number.\n2.change the name.\n");
					printf("--------------------------------------------------------------\n");
					printf("select any option dislpayed above:");
					scanf("%d",&y);
					switch(y)
					{
						case 1:
							printf("Enter the new number:");
							scanf("%lld",&newn);
							ser->num = newn;
							printf("--------------------------------------------------------------\n");
							printf("data updated.\n");
							printf("--------------------------------------------------------------\n");
						break;
						case 2:
							printf("Enter the new name:");
							scanf("%s",&newname);
							strcpy(ser->str1,newname);
							printf("--------------------------------------------------------------\n");
							printf("data updated.\n");
							sort();
							printf("--------------------------------------------------------------\n");
						break;			//8
						default :
							printf("INVLAID OPTION.\n");
					}
				case 2 : 
				printf("--------------------------------------------------------------\n");
					printf("BACK TO MENU\n");
					break;
			}
		}
		ser = ser->nxt;
	}
	if(o!=1)
	{
		printf("data not found!!\n");
	}
}
void traverse()
{
	sort();
	printf("--------------------------------------------------------------\n");
	tr = head;
	if(head == NULL)
	{
		printf("DATA NOT FOUND.\n");
	}
	else
	{
		while(tr!=NULL)
		{
			printf("%s\t%lld\n",tr->str1,tr->num);
			tr = tr->nxt;
		}
		
	}
}
void fileoperation()
{
	FILE *fptr = fopen("\\Dev-Cpp\\coding\\contact.txt","r");
	char s;
	if(fptr == NULL)
	{
		printf("FILE NOT FOUND.\n");
	}
	else
	{
		while((s=fgetc(fptr))!=EOF)
		{
			printf("%c",s);
		}
	}
}
void file()
{
	FILE *fp = fopen("\\Dev-Cpp\\coding\\contact.txt","a");
	if(fp==NULL)
	{
		printf("FILE NOT FOUND.\n");
	}
	else
	{
		ptr = head;
		if(ptr == NULL)
		{
			printf("DATA NOT FOUND.\n");
		}
		else
		{
			while(ptr!=NULL)
			{
				fprintf(fp,"%s\t%lld\n",ptr->str1,ptr->num);
				ptr = ptr->nxt;
			}
			printf("DATA ENTERED TO FILE.\n");
		}
	}
}
int main()
{
	clock_t Start,end;
	double exe;
	char name[300],find[300];int c=1,len = 0;
	do
	{
			printf("-------------------------------------------------------------\n");
			printf("\t\tPHONE DIRECTORY.\n");
			printf("-------------------------------------------------------------\n");
			printf("1.create a contact.\n");
			printf("2.delete a contact.\n");
			printf("3.search an contact\n");
			printf("4.traverse contact details.\n");
			printf("5.saved data.\n");
			printf("6.save to file.\n");
			printf("7.exit.\n");
			printf("Enter any option you like:");
			scanf("%d",&x);
			switch(x)		//10
			{
				case 1:
					Start = clock();
					creation();
					end = clock();
					exe = (double)(end - Start)/CLOCKS_PER_SEC;
					//printf("%lf\n",exe);
					break;
				case 2:
					Start = clock();
					deleteContact();
					end = clock();
					exe= (double)(end-Start)/CLOCKS_PER_SEC;
					//printf("%lf\n",exe);
					break;
				case 3:
					Start = clock();
					search();
					exe = (double)(end - Start)/CLOCKS_PER_SEC;
					//printf("%lf\n",exe);
					break;
				case 4:
					Start = clock();
					traverse();
					exe = (double)(end-Start)/CLOCKS_PER_SEC;
					//printf("%lf\n",exe);
					break;
				case 5:
					Start = clock();
					fileoperation();
					end = clock();
					exe = (double)(end-Start)/CLOCKS_PER_SEC;
					//printf("%lf\n",exe);
					break;
				case 6:
					Start = clock();
					file();
					end = clock();
					exe = (double)(end-Start)/CLOCKS_PER_SEC;
					break;
				case 7:
					printf("THANK YOU.\n");
					break;
				default:
					printf("INVLAID OPTION.\n");
					break;
			}
		}while(x!=7);
}
