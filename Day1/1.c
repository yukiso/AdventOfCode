#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


int* get_numbers(const char *file_name, int *number_of_elements){
    FILE *f = fopen(file_name, "r");
    int *numbers;
    *number_of_elements = 0;
    numbers = (int *) malloc(sizeof(int)*500);
    while(fscanf(f, "%d", &numbers[*number_of_elements]) != EOF){
        *number_of_elements+=1;
    }
    
    fclose(f);
    return numbers;
}

void solve(int *numbers, int no_elems){
    int look_for;
    for (int i = 0; i < no_elems; i++)
    {
        look_for = 2020-numbers[i];
        for (int j = i+1; j < no_elems; j++)
        {
            if(numbers[j] == look_for){
                printf("Numbers: %d, %d\nProduct: %d\n", numbers[i], look_for, numbers[i] * look_for);
                break;
            }
        }
        
    }
}

int main(int argc, char const *argv[]){
    if(argc != 2)
        return -1;

    double time_spent;
    int no_elems;
    int *numbers = get_numbers(argv[1], &no_elems);
 
    clock_t start_time = clock();
    
    solve(numbers, no_elems);

    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(clock() - start_time) / CLOCKS_PER_SEC;
 
    printf("Run time: %f\n", time_spent);
    
    return 0;
}
