/* #include<stdio.h>
#include<time.h>

int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");

    time_t t;   // not a primitive datatype
    time(&t);

    printf("\nThis program has been writeen at (date and time): %s", ctime(&t));

    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}
 */
#include<stdio.h>
#include<time.h>

void main(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Date and time: %d-%02d-%02d %02d:%02d:%02d\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}