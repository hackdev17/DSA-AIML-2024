#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct day{
    char *dayname;
    int d,m,y;
    char *activitydescription;
}Day;

void create(Day *calendar){
        char *daynames[]= \
                {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
        for(int i=0;i<7;i++){
                calendar[i].dayname=strdup(daynames[i]);
                size_t bufferSize=256;
                calendar[i].activitydescription=(char *)malloc(bufferSize*sizeof(char));
        }
}

void read(Day *calendar){
        for(int i=0;i<7;i++){
                printf("Enter date for %s in dd/mm/yy : ",calendar[i].dayname);
                scanf("%d%d%d",&calendar[i].d,&calendar[i].m,&calendar[i].y);
                printf("Enter activity for %s : ",calendar[i].dayname);
                while(getchar()!='\n')
                    ;
                size_t bufferSize=256;
                getline(&calendar[i].activitydescription,&bufferSize,stdin);
        }
}

void display(Day *calendar){
        printf("%-10s %-10s %-10s\n","Day","Date","Activity");
        for(int i=0;i<7;++i){
                printf("%-10s %d/%d/%d %-10s\n", \
                        calendar[i].dayname,calendar[i].d, \
                        calendar[i].m,calendar[i].y, \
                        calendar[i].activitydescription
                );
        }
}

int main(){
        Day *calendar=(Day *)malloc(7*sizeof(Day));
        if(calendar==NULL){
                fprintf(stderr,"Memory allocation failed\n");
                return 1;
        }

        create(calendar);
        read(calendar);
        display(calendar);

        for(int i=0;i<7;++i){
                free(calendar[i].dayname);
                free(calendar[i].activitydescription);
        }
        free(calendar);
        return 0;
}
