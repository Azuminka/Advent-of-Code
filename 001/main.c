#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    FILE *file;
    char buf[100];
    int sum = 0;
    int max = 0;
    int num= 0;
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Can't open file\n");
        return -1;
    }
    while(fgets(buf, sizeof(buf), file) != NULL){
        if(buf[0] != '\n'){
            sscanf(buf, "%d", &num);
            sum += num;
        }else{ 
            if(max < sum)
                max = sum;
            sum = 0;
        }
        memset(buf,0,sizeof(buf));
    }
    printf("%d\n", max);
    fclose(file);
    return 0;
}