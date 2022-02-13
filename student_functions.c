/* name David Khachatryan
 * uw net Id: 908 167 8576
*/

/* This function takes a string as input and removes 
 * leading and trailing whitespace including spaces
 * tabs and newlines. It also removes multiple internal
 * spaces in a row. Arrays are passed by reference.
 */

#include <stdio.h>
#include <stdlib.h>
#include "student_functions.h"

#define CONVERT_TO_UPPERCASE(c) (c + 'A' - 'a')
#define CONVERT_TO_LOWERCASE(c) (c - 'A' + 'a')
#define MIN_DIRECTOR_LENGTH 10
#define MIN_TITLE_LENGTH 7
#define LONGEST_ID 3
#define LONGEST_YEAR 6
#define LONGEST_RATING 6
#define LONGEST_REVENUE 11
#define ID "Id";
#define YEAR "Year";
#define RATING "Rating";
#define REVENUE "Revenue";
#define TITLE "Title";
#define DIRECTOR "Director";


float Power(int base, int exponent) {

    if (exponent < 0) {
        return 1 / Power(base, -exponent);
    }

    float result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int isDigit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

void swap(char str[], int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void insert_into_array(int arr[], int size, int value) {
    arr[size] = value;
}

int contains(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

void Clean_Whitespace(char str[]) {

    // check if string is empty
    if (str[0] == '\0') {
        return;
    }

    // get string length
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // remove leading spaces
    int i = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') {
        i++;
    }
    int j;
    for (j = 0; j < length; j++) {
        str[j] = str[i + j];
    }

    j = length - 1;

    // remove middle spaces
    int k = 0;
    while (k < j) {
        if (str[k] == ' ') {
            int l = k + 1;
            while (str[l] == ' ' || str[l] == '\t' || str[l] == '\n' || str[l] == '\r') {
                l++;
            }

            int number_of_spaces_to_remove = l - k - 1;

            if (number_of_spaces_to_remove == 0) {
                k++;
                continue;
            }

            // find the length of the word that follows the space

            int space_index_start = k + 1;
            int space_index_end = k + number_of_spaces_to_remove ;

            for (int i = space_index_end; i >= space_index_start; i--) {
                int current_index = i;
                while (str[current_index + 1] != ' ' && str[current_index + 1] != '\t' && str[current_index + 1] != '\n' && str[current_index + 1] != '\r') {
                    swap(str, current_index, current_index + 1);
                    current_index++;
                }
            }

            //for (int m = k; m < l; m++) {
            //    //str[m] = str[l + m - k];
            //    // check if m + 1 is l and skip if it is
            //    if (m + 1 == l) {
            //        break;
            //    }
//
            //    if (l + m - k < length) {
            //        // remove str m + 1 and put all the rest of the string to left by 1
            //        // keep swapping until hit null
            //        swap(str, m + 1, l + m - k);
            //    }
            //}
            j -= (l - k - 1);
        }

        else if (str[k] == '\n' || str[k] == '\t' || str[k] == '\r') {
            int l = k + 1;
            while (str[l] == ' ' || str[l] == '\t' || str[l] == '\n' || str[l] == '\r') {
                l++;
            }
            for (int m = k; m < l; m++) {
                //str[m] = str[l + m - k];
                // check if m + 1 is l and skip if it is
                if (m == l) {
                    break;
                }

                else if (l + m - k < length) {
                    // remove str m + 1
                    swap(str, m, l + m - k);
                }
            }
            j -= (l - k - 1);

        }
        k++;
    }

    // remove trailing spaces, tabs, and newline
    int len = length - 1;
    while (str[len] == ' ' || str[len] == '\t' || str[len] == '\n' || str[len] == '\r') {
        len--;
    }

    // null terminate string
    str[len + 1] = '\0';

    // if a character is preceded by a space and is lowercase, convert it to uppercase
    for (int i = 1; i < len + 1; i++) {
        if (str[i - 1] == ' ' && str[i] >= 'a' && str[i] <= 'z') {
            str[i] = CONVERT_TO_UPPERCASE(str[i]);
        }
    }

    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = CONVERT_TO_UPPERCASE(str[0]);
    }

    return;
}

/* This function takes a string and makes the first
 * letter of every word upper case and the rest of the
 * letters lower case
 */ 
void Fix_Case(char str[]) {
    // check if the string is empty
    if (str[0] == '\0') {
        return;
    }

    // get the length of the string
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // check if the first character is a letter lower case 
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = CONVERT_TO_UPPERCASE(str[0]);
    } 
    
    // loop over the string staring at index 1
    for (int i = 1; i < length; i++) {
        // check if the current character is letter upper case
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = CONVERT_TO_LOWERCASE(str[i]);
        }

        else if (str[i - 1] == ' ' && str[i] >= 'a' && str[i] <= 'z') {
            str[i] = CONVERT_TO_UPPERCASE(str[i]);
        }
    }
    return;
}

/* this function takes a string and returns the 
 * integer equivalent
 */
int String_To_Year(char str[]) {
    Clean_Whitespace(str);

    // check if string is empty
    if (str[0] == '\0') {
        return 0;
    }

    // get the length of the string
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // check if string is a number
    for (int i = 0; i < length; i++) {
        if (!isDigit(str[i])) {
            // invalid number
            return -1;
        }
    }

    // convert string to integer
    int year = 0;
    for (int i = 0; i < length; i++) {
        year = year * 10 + (str[i] - '0');
    }

    return year;
}


/* this function takes the name of a 
 * director as a string and removes all but
 * the last name.  Example:
 * "Bucky Badger" -> "Badger"
 */
void Director_Last_Name(char str[]) {
    Clean_Whitespace(str);

    // check if the string is empty
    // if it is, return
    // if it is not, remove all but the last name
    // and return
    if (str[0] == '\0') {
        return;
    }
    
    // remove everything that comes before space
    // get the length of the string
    int i = 0;
    // get the length of the string
    int length = 0;
    while (str[i] != '\0') {
        length++;
        i++;
    }

    int contains_space = 0;
    // check if the string contains a space
    // if it does, remove all but the last name
    // and return
    // do this to avoid infinite looping
    for (int j = 0; j < length; j++) {
        if (str[j] == ' ') {
            contains_space = 1;
        }
    }

    if (contains_space == 0) {
        return;
    }

    // remove everything that comes before space

    // find the last space
    int last_space = 0;
    for (int j = 0; j < length; j++) {
        if (str[j] == ' ') {
            last_space = j;
        }
    }
    last_space++;

    // copy everything after space to the beginning of the string
    int k = 0;
    while (last_space < length) {
        str[k] = str[last_space];
        k++;
        last_space++;
    }
    str[k] = '\0';

    return;
}


/* this function takes the a string and returns
 * the floating point equivalent
 */
float String_To_Rating(char str[]) {
    Clean_Whitespace(str);

    float result = 0;
    int i = 0;
    int sign = 1;
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    int is_fractional_part = 0;
    int current_decimal_place = 1;
    while (str[i] != '\0') {
        if (isDigit(str[i]) && is_fractional_part == 0) {
            result = result * 10 + (str[i] - '0');
        }

        else if (isDigit(str[i]) && is_fractional_part == 1) {
            result += (str[i] - '0') * Power(10, -current_decimal_place);
            current_decimal_place++;
        }

        // if we find a decimal point, we need to
        // multiply by 10 and then divide by 10
        if (str[i] == '.') {
            is_fractional_part = 1;
        }

        i++;
    }
    return result * sign;
}


/* this function takes a string representing
 * the revenue of a movie and returns the decimal
 * equivlaent. The suffix M or m represents millions,
 * K or k represents thousands.
* example: "123M" -> 123000000 
*/
long long String_To_Dollars(char str[])  {
    Clean_Whitespace(str);    

    // check if the string is empty
    if (str[0] == '\0') {
        return 0;
    }

    int contains_letters = 0;

    // check if the string only contains numbers
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isDigit(str[i])) {
            contains_letters = 1;
            break;
        }
    }

    // if the string contains doesn't contain letters, 
    // return the string as an integer
    if (!contains_letters) {
        // convert the string to an long long
        return atoll(str);
    }

    int i = 0;
    long long dollars = 0;

    while (str[i] != '\0') {
        if (str[i] == 'M' || str[i] == 'm') {
            dollars = dollars * 1000000;
        } 
        
        else if (str[i] == 'K' || str[i] == 'k') {
            dollars = dollars * 1000;
        } 
        
        // is a number
        else {
            dollars = dollars * 10 + str[i] - '0';
        }
        i++;
    }
    return dollars;
}


/* This function takes the array of strings representing 
 * the csv movie data and divides it into the individual
 * components for each movie.
 * Use the above helper functions.
 */
void Split(char csv[10][1024], int num_movies, char titles[10][1024], int years[10], char directors[10][1024], float ratings[10], long long dollars[10]) {
    // loop over the number of movies
    for (int i = 0; i < num_movies; i++) {
        // split the string into the individual components         
        // get the title
        int j = 0;

        // get the title
        while (csv[i][j] != ',') {
            titles[i][j] = csv[i][j];
            j++;
        }
        titles[i][j] = '\0';
        Clean_Whitespace(titles[i]);
        Fix_Case(titles[i]);

        // get the year
        j++;
        int yearStart = j + 1;
        while (csv[i][j] != ',') {
            j++;
        }
        int yearEnd = j;
        
        // build the year string
        char year[1024];
        int k = 0;
        for (int l = yearStart; l < yearEnd; l++) {
            year[k] = csv[i][l];
            k++;
        }

        // convert the year string to an integer
        year[k] = '\0';
        years[i] = String_To_Year(year);

        // skip the duration component
        j++;
        while (csv[i][j] != ',') {
            j++;
        }

        // get the director
        j += 2;
        int starting_index = j;
        while (csv[i][j] != ',') {
            directors[i][j - starting_index] = csv[i][j];
            j++;
        }
        Director_Last_Name(directors[i]);

        // get the rating
        j++;
        int ratingStart = j + 1;
        while (csv[i][j] != ',') {
            j++;
        }
        int ratingEnd = j;

        // build the rating string
        char rating[1024];
        k = 0;
        for (int l = ratingStart; l < ratingEnd; l++) {
            rating[k] = csv[i][l];
            k++;
        }

        // convert the rating string to a floating point number
        rating[k] = '\0';
        ratings[i] = String_To_Rating(rating);

        // get the dollars
        j++;
        int dollarsStart = j + 1;
        while (csv[i][j] != ',') {
            j++;
        }
        int dollarsEnd = j;

        // build the dollars string
        char dollarsTmp[1024];
        k = 0;
        for (int l = dollarsStart; l < dollarsEnd; l++) {
            dollarsTmp[k] = csv[i][l];
            k++;
        }

        // convert the dollars string to a long long
        dollarsTmp[k] = '\0';
        dollars[i] = String_To_Dollars(dollarsTmp);
    }
    return;
}


/* This function prints a well formatted table of
 * the movie data 
 * Row 1: Header - use name and field width as below
 * Column 1: Id, field width = 3, left justified
 * Column 2: Title, field width = lenth of longest movie + 2 or 7 which ever is larger, left justified, first letter of each word upper case, remaining letters lower case, one space between words
 * Column 3: Year, field with = 6, left justified
 * Column 4: Director, field width = length of longest director last name + 2 or 10 (which ever is longer), left justified, only last name, first letter upper case, remaining letters lower case
 * column 5: Rating, field width = 6, precision 1 decimal place (e.g. 8.9, or 10.0), right justified
 * column 6: Revenue, field width = 11, right justified
 */
void Print_Table(int num_movies, char titles[10][1024], int years[10], char directors[10][1024], float ratings[10], long long dollars[10]) {
    // get the length of the longest movie
    int longest_movie = 0;
    for (int i = 0; i < num_movies; i++) {
        // get the length of the movie
        int j = 0;
        while (titles[i][j] != '\0') {
            j++;
        }

        // check if the length is longer than the longest movie
        if (j > longest_movie) {
            longest_movie = j;
        }
    }
    longest_movie += 2;

    // get the length of the longest director
    int longest_director = 0;
    for (int i = 0; i < num_movies; i++) {
        // get the length of the director
        int j = 0;
        while (directors[i][j] != '\0') {
            j++;
        }

        // check if the length is longer than the longest director
        if (j > longest_director) {
            longest_director = j;
        }
    }
    longest_director += 2;

    if (longest_movie < MIN_TITLE_LENGTH) {
        longest_movie = MIN_TITLE_LENGTH;
    }

    if (longest_director < MIN_DIRECTOR_LENGTH) {
        longest_director = MIN_DIRECTOR_LENGTH;
    }

    char id_column[1024][LONGEST_ID + 1];
    char year_column[1024][LONGEST_YEAR + 1];
    char rating_column[1024][LONGEST_RATING + 1];
    char revenue_column[1024][LONGEST_REVENUE + 1];
    char title_column[1024][longest_movie + 1];
    char director_column[1024][longest_director + 1];

    // place the id in the id column
    sprintf(id_column[0], "Id ");

    // place the title in the title column
    char title_string[1024];
    sprintf(title_string, "%s", "Title");
    for (int i = 5; i < longest_movie; i++) {
        title_string[i] = ' ';
    }

    sprintf(title_column[0], "%s", title_string);
    Fix_Case(title_column[0]);
    // place the year in the year column
    sprintf(year_column[0], "%s", "Year  ");

    // place the director in the director column
    char director_string[1024];
    sprintf(director_string, "Director");
    for (int i = 8; i < longest_director; i++) {
        director_string[i] = ' ';
    }

    sprintf(director_column[0], "%s", director_string);

    // place the rating in the rating column
    sprintf(rating_column[0], "Rating");    
    // place the revenue in the revenue column
    sprintf(revenue_column[0], "    Revenue");

    for (int i = 1; i <= num_movies; i++) {

        // place the id in the id column
        sprintf(id_column[i], "%d", i);

        // check if length of id_column is less than 3 and add space to make it 3
        int id_length = 0;
        while (id_column[i][id_length] != '\0') {
            id_length++;
        }
        if (id_length < 3) {
            for (int j = id_length; j < 3; j++) {
                id_column[i][j] = ' ';
            }
            id_column[i][3] = '\0';
        }

        // place the title in the title column
        sprintf(title_column[i], "%s", titles[i - 1]);

        // check if length of title_column is less than longest_movie and add space to make it longest_movie
        int title_length = 0;
        while (title_column[i][title_length] != '\0') {
            title_length++;
        }

        if (title_length < longest_movie) {
            for (int j = title_length; j < longest_movie; j++) {
                title_column[i][j] = ' ';
            }
            title_column[i][longest_movie] = '\0';
        }

        Fix_Case(title_column[i]);

        // place the year in the year column
        sprintf(year_column[i], "%d", years[i - 1]);

        // check if length of year_column is less than 6 and add space to make it 6
        int year_length = 0;
        while (year_column[i][year_length] != '\0') {
            year_length++;
        }

        if (year_length < 6) {
            for (int j = year_length; j < 6; j++) {
                year_column[i][j] = ' ';
            }
            year_column[i][6] = '\0';
        }

        // place the director in the director column
        sprintf(director_column[i], "%s", directors[i - 1]);

        // check if length of director_column is less than longest_director and add space to make it longest_director
        int director_length = 0;
        while (director_column[i][director_length] != '\0') {
            director_length++;
        }

        if (director_length < longest_director) {
            for (int j = director_length; j < longest_director; j++) {
                director_column[i][j] = ' ';
            }
            director_column[i][longest_director] = '\0';
        }

        // place the rating in the rating column
        sprintf(rating_column[i], "%0.1f", ratings[i - 1]);

        // check if length of rating_column is less than 6 and add space to make it 6
        int rating_length = 0;
        while (rating_column[i][rating_length] != '\0') {
            rating_length++;
        }

        if (rating_length < 6) {
            for (int j = rating_length; j < 6; j++) {
                rating_column[i][j] = ' ';
            }
            rating_column[i][6] = '\0';
        }

        // swap the space characters to come before the numbers in rating_column
        char tmpRating[1024];

        int num_spaces = 0;

        for (int j = 0; j < 7; j++) {
            if (rating_column[i][j] == ' ') {
                num_spaces++;
            }
        }

        for (int j = 0; j < num_spaces; j++) {
            tmpRating[j] = ' ';
        }

        int k = 0;
        for (int j = num_spaces; j < 6; j++) {
            tmpRating[j] = rating_column[i][k];
            k++;
        }
        tmpRating[6] = '\0';

        sprintf(rating_column[i], "%s", tmpRating);

        // place the revenue in the revenue column
        sprintf(revenue_column[i], "%lld", dollars[i - 1]);

        // check if length of revenue_column is less than 11 and add space to make it 11
        int revenue_length = 0;
        while (revenue_column[i][revenue_length] != '\0') {
            revenue_length++;
        }

        if (revenue_length < 11) {
            for (int j = revenue_length; j < 11; j++) {
                revenue_column[i][j] = ' ';
            }
            revenue_column[i][11] = '\0';
        }

        // swap the space characters to come before the numbers in revenue_column
        
        // count the number of spaces in revenue_column
        num_spaces = 0;
        for (int j = 0; j < 11; j++) {
            if (revenue_column[i][j] == ' ') {
                num_spaces++;
            }
        }        

        char tmpColumn[1024];
        // add num_spaces white spaces to the beginning of revenue_column
        for (int j = 0; j < num_spaces; j++) {
            tmpColumn[j] = ' ';
        }

        // add the revenue_column to tmpColumn
        k = 0;
        for (int j = num_spaces; j < 11; j++) {
            tmpColumn[j] = revenue_column[i][k];
            k++;
        }
        tmpColumn[11] = '\0';

        // copy tmpColumn to revenue_column
        sprintf(revenue_column[i], "%s", tmpColumn);

        // loop over revenue column and remove any space that comes after a number
        for (int j = 1; j < 11; j++) {
            if (revenue_column[i][j] == ' ' && revenue_column[i][j - 1] > '0' && revenue_column[i][j - 1] < '9') {
                revenue_column[i][j] = '\0';
            }
        }
    }

    // print the header
    printf("%s", id_column[0]);
    printf("%s", title_column[0]);
    printf("%s", year_column[0]);
    printf("%s", director_column[0]);
    printf("%s", rating_column[0]);
    printf("%s", revenue_column[0]);
    printf("\n");

    for (int i = 1; i <= num_movies; i++) {
        // print everything
        printf("%s", id_column[i]);
        printf("%s", title_column[i]);
        printf("%s", year_column[i]);
        printf("%s", director_column[i]);
        printf("%s", rating_column[i]);
        printf("%s", revenue_column[i]);
        printf("\n");
    }

    return;
}
