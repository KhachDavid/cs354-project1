#ifndef __student_functions__
#define __student_functions__
/* This function takes a string as input and removes 
 * leading and trailing whitespace including spaces
 * tabs and newlines. It also removes multiple internal
 * spaces in a row. Arrays are passed by reference.
 */
void Clean_Whitespace(char str[]);
/* This function takes a string and makes the first
 * letter of every word upper case and the rest of the
 * letters lower case
 */ 
void Fix_Case(char str[]);
/* this function takes a string and returns the 
 * integer equivalent
 */
int String_To_Year(char str[]);
/* this function takes the name of a 
 * director as a string and removes all but
 * the last name.  Example:
 * "Bucky Badger" -> "Badger"
 */
void Director_Last_Name(char str[]);
/* this function takes the a string and returns
 * the floating point equivalent
 */
float String_To_Rating(char str[]);
/* this function takes a string representing
 * the revenue of a movie and returns the decimal
 * equivlaent. The suffix M or m represents millions,
 * K or k represents thousands.
* example: "123M" -> 123000000 
*/
long long String_To_Dollars(char str[]);
/* This function takes the array of strings representing 
 * the csv movie data and divides it into the individual
 * components for each movie
 */
void Split(char csv[10][1024], int num_movies, char titles[10][1024], int 
years[10], char directors[10][1024], float ratings[10], long long dollars[10]);
/* This function prints a well formatted table of
 * the movie data 
 * Row 1: Header - use name and field width as below
 * Column 1: Id, field width = 3, left justified
 * Column 2: Title, field width = lenth of longest movie + 2 or 7 which ever is 
larger, left justified
 * Column 3: Year, field with = 6, left justified
 * Column 4: Director, field width = length of longest director last name + 2 or 10
(which ever is longer), left justified
 * column 5: Rating, field width = 6, precision 1 decimal place (e.g. 8.9, or 
10.0), right justified
 * column 6: Revenue, field width = 11, right justified
 */
void Print_Table(int num_movies, char titles[10][1024], int years[10], char 
directors[10][1024], float ratings[10], long long dollars[10]);
#endif