#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20
typedef struct lnode{
    char str1[max];
    struct lnode* link;
    struct lnode* next;
}lnode;

lnode *nod1(lnode *index,char str0[max]){
    lnode *Node=NULL;
    Node=malloc(sizeof(lnode));
    if(Node==NULL){
        exit(-1);
    }
    if(index!=NULL){
        index->next=Node;
    }
    Node->link=index;
    Node->next=NULL;
    strcpy(Node->str1, str0);
    index=Node;
    return index;
}
lnode *nod3(lnode *index){
    lnode *str0=NULL;
    while (index->next!=NULL) {
        str0=index;
        index=index->next;
        free(str0);
    }
    free(index);
    index=NULL;
    return index;
}
lnode *ae(lnode *index,char str0[max]){
    lnode *Node=NULL;
    Node=malloc(sizeof(lnode));
    if(Node==NULL){
        exit(-1);
    }
    strcpy(Node->str1, str0);
    if(index==NULL){
        index=Node;
        index->link=NULL;
        index->next=NULL;
        return index;
    }
    lnode *rindex=index;
    while (rindex->next!=NULL) {
        rindex=rindex->next;
    }
    rindex->next=Node;
    Node->link=rindex;
    Node->next=NULL;
    return index;
}
lnode *af(lnode *index,char str0[max]){
    lnode *Node=NULL;
    Node=malloc(sizeof(lnode));
    if(Node==NULL){
        exit(-1);
    }
    strcpy(Node->str1, str0);
    if(index==NULL){
        index=Node;
        index->link=NULL;
        index->next=NULL;
        return index;
    }
    Node->next=index;
    Node->link=NULL;
    index->link=Node;
    index=Node;
    return index;
}
lnode *i(lnode *index,char str0[max],int lp){
    int lps=1;
    lnode *Node=NULL;
    Node=malloc(sizeof(lnode));
    strcpy(Node->str1, str0);
    if(index==NULL){
        free(Node);
        return index;
    }
    lnode *rindex=index;
    for(lps=1;lps<lp;lps++){
        if(rindex->next!=NULL){
            rindex=rindex->next;
        }else{
            return index;
        }
        
    }
    if(rindex->next!=NULL){
        rindex->next->link=Node;
        Node->next=rindex->next;
        Node->link=rindex;
        rindex->next=Node;
    }else if(rindex->next==NULL){
        index=ae(index, str0);
    }
    return index;
}
lnode *nod2(lnode *index,char str0[max]){
    if(index==NULL){
        return index;
    }
    lnode *rindex=index,*nod2ch=NULL;
    while (rindex!=NULL) {
        if(strcmp(rindex->str1, str0)==0){
            nod2ch=rindex;
            if(rindex->link!=NULL){
                rindex=rindex->link;
                if(nod2ch->next!=NULL){
                    rindex->next=nod2ch->next;
                    nod2ch->next->link=rindex;
                    free(nod2ch);
                    return index;
                }else{
                    rindex->next=NULL;
                    free(nod2ch);
                    return index;
                }
            }else if(rindex->link==NULL&&rindex->next!=NULL){
                nod2ch=rindex;
                index=nod2ch->next;
                index->link=NULL;
                free(nod2ch);
                return index;
            }else if(rindex->link==NULL&&rindex->next==NULL){
                free(index);
                index=NULL;
                return index;
            }
        }
        rindex=rindex->next;
    }
    return index;
}
int main(int argc,char *argv[]){
    char str0[max];
    lnode *index=NULL;
    while (scanf("%20s",str0)!=EOF) {
        index=nod1(index,str0);
    }
    if(index!=NULL){
        while (index->link!=NULL) {
            index=index->link;
        }
    }
    if(argc==3){
        if(strcmp(argv[1],"-ae")==0){
            index=ae(index, argv[2]);
        }
        if(strcmp(argv[1],"-af")==0){
            index=af(index, argv[2]);
        }
        if(strcmp(argv[1],"-d")==0){
            index=nod2(index, argv[2]);
        }
    }
    if(argc==4){
        if(strcmp(argv[1],"-i")==0){
            if(atoi(argv[3])!=0){
            index=i(index, argv[2], atoi(argv[3]));
            }
        }
    }
    while (index!=NULL) {
        printf("%s ",index->str1);
        index=index->next;
    }
    if(index!=NULL){
        while (index->link!=NULL) {
            index=index->link;
        }
    }
    if(index!=NULL){
        nod3(index);
    }
    return 0;
}
