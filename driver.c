#include <stdio.h>
#include "student_functions.h"


void Read_CSV(char *filename, char csv[10][1024], int *num_movies) {
    FILE *fp;
    fp = fopen(filename, "r");
    fscanf(fp, "%d", num_movies);
    char read_rest_of_line[1024];
    fgets(read_rest_of_line, 1024, fp);
    for (int i=0; i<*num_movies; i++) 
        fgets(csv[i], 1024, fp);
    fclose(fp);
    return;
}

int main() {

    char csv[10][1024]; // data structure for the entire movie csv file
    int num_movies;
    char titles[10][1024];
    int years[10];
    char directors[10][1024];
    float ratings[10];
    long long dollars[10];


    Read_CSV("movies2.csv", csv, &num_movies);
    Split(csv, num_movies, titles, years, directors, ratings, dollars);
    Print_Table(num_movies, titles, years, directors, ratings, dollars);

    char* search_title = "  test  movie   four  ";
    Clean_Whitespace(search_title);
    printf("%s\n", search_title);

    return 0;
}
