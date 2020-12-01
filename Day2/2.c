#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


void solve(int *inputs, int no_elems){
    return;
}


int* get_input(const char *file_name, int *no_of_lines){
    FILE *f = fopen(file_name, "r");
    int *inputs;
    *no_of_lines = 0;
    inputs = (int *) malloc(sizeof(int)*500);
    while(fscanf(f, "%d", &inputs[*no_of_lines]) != EOF){
        *no_of_lines+=1;
    }
    fclose(f);
    
    return inputs;
}


int main(int argc, char const *argv[]){
    const char *file_name = "input.txt";
    double time_spent;
    int no_elems;

    if(argc == 2)
        file_name = argv[1];

    int *numbers = get_input(file_name, &no_elems);
 
    clock_t start_time = clock();
    
    solve(numbers, no_elems);

    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(clock() - start_time) / CLOCKS_PER_SEC;
 
    printf("Score: %.0f\n", 1/time_spent);
    
    return 0;
}
