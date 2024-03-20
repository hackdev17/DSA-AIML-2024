#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t bs=256;

typedef struct day{
    char *day;
    int d,m,y;
    char *AD;
}Day;

void create(Day *calendar){
        char *Days[]= \
                {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
        for(int i=0;i<7;i++){
                calendar[i].day=strdup(Days[i]);
                calendar[i].AD=(char *)malloc(bs*sizeof(char));
        }
}

void read(Day *calendar){
        for(int i=0;i<7;i++){
                printf("Enter date for %s in dd/mm/yy : ",calendar[i].day);
                scanf("%d%d%d",&calendar[i].d,&calendar[i].m,&calendar[i].y);
                printf("Enter activity for %s : ",calendar[i].day);
                while(getchar()!='\n')
                    ;
                getline(&calendar[i].AD,&bs,stdin);
        }
}

void display(Day *calendar){
        printf("%-10s %-10s \t %s\n","Day","Date","Activity");
        for(int i=0;i<7;++i){
                printf("%-10s %d/%d/%d \t %s\n", \
                        calendar[i].day,calendar[i].d, \
                        calendar[i].m,calendar[i].y, \
                        calendar[i].AD
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
                free(calendar[i].day);
                free(calendar[i].AD);
        }
        free(calendar);
        return 0;
}
