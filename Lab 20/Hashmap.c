#include<string.h>
#include<stdio.h>

# define m 10

struct pair{
    char key[10];
    int value;
};

struct pair hashmap[m];
int f(char key[]){
    int h=0;
    for(int i=0; i<strlen(key); i++){
        h = h+key[i];
    }
    return h%m;
}

void add(char k[], int v){
    int index = f(k);
    if(hashmap[index].key[0] == '\0'){
        strcpy(hashmap[index].key, k);
        hashmap[index].value = v;
        return;
    }
    else if(strcmp(hashmap[index].key,k) == 0){
        hashmap[index].value = v;
        return;
    }
    else{
        //collision
        for(int probe = 1; probe<m; probe++){
            int i = (index + probe) % m;
            if(hashmap[i].key[0] == '\0'){
                strcpy(hashmap[i].key, k);
                hashmap[i].value = v;
                return;
            }
            if(strcmp(hashmap[i].key, k) == 0){
                hashmap[i].value = v;
                return;
            }
        }
        printf("Hashmap Overflow\n");
    }
}

int get(char k[]){
    int index = f(k);
    if(strcmp(hashmap[index].key, k) == 0){
        return hashmap[index].value;
    }
    else{
        for(int probe=1; probe<m; probe++){
            int i=(index + probe)%m;
            if(strcmp(hashmap[i].key, k) == 0){
                return hashmap[i].value;
            }
        }
    }
}

void main(){
    add("i1", 10);
    add("i2", 10);
    add("i3", 10);
    add("i1", 20);
    printf("Value of i1: %d\n", get("i1"));
    printf("Value of i3: %d\n", get("i3"));
}
