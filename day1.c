#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct values{
	
	int value;
	struct values *next;
	
}VALUES;

void part1(FILE *fp){
	
	int tmp,comp;
	int iter=0,counter=0;
	
	if(fp==NULL){
		printf("Dosya acilamadi!\n");
	}
	while(!feof(fp)){
		
		if(iter!=0){
			fscanf(fp,"%d\n",&comp);
			if(comp>tmp){
				counter++;
			}
			tmp=comp;
		}
		else{
			fscanf(fp,"%d\n",&tmp);
			iter++;
		}
	}
	printf("%d\n",counter);
	fclose(fp);
}

void part2(FILE *fp,VALUES **head){
	int sum=0,prev=0,ct=0;
	VALUES *tmp = *head;
	while(!feof(fp)){
		if(*head == NULL){
			*head = (VALUES*)malloc(sizeof(VALUES));
			(*head)->next =NULL;
			fscanf(fp,"%d\n",&(*head)->value);	
		}
		else{
			tmp = *head;
			while(tmp->next != NULL){
				tmp = tmp->next;
			}
			tmp->next = (VALUES*)malloc(sizeof(VALUES));
			fscanf(fp,"%d\n",&(tmp->next->value));
			tmp->next->next=NULL;
		}
		
	}
	tmp = *head;
	while(tmp->next->next!=NULL){
		sum += tmp->value;
		sum += tmp->next->value;
		sum += tmp->next->next->value;
		
		if(prev!=0 && sum>prev){
			ct++;
		}
		prev=sum;
		tmp=tmp->next;
		sum=0;
	}
	printf("%d",ct);
	fclose(fp);
}

int main(){
	
	VALUES *head = NULL;
	FILE *fp= fopen("measurements.txt","r");
	part1(fp);
	FILE *fp2= fopen("measurements.txt","r");
	part2(fp2,&head);
	
	return 0;
}
