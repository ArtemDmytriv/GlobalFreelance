// threading without mutex

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>

#define NUM_STUD 3
#define SLEEP_TIME 1 // also can set 0.2, 0.3

int scholarship = 4000;

typedef struct Arguments_t {
    const char *name;
		int totalEarned;
} Student_t;

void* func(void* in);

int main()
{

    pthread_t t1, t2, t3;
    printf("Start ScholarShip is: %d\n", scholarship);

		Student_t students[3] =
    {
        {"A", 0},
        {"B", 0},
        {"C", 0},
    };

    pthread_create(&t1, NULL, func, &students[0]);
    pthread_create(&t2, NULL, func, &students[1]);
    pthread_create(&t3, NULL, func, &students[2]);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("End ScholarShip is: %d\n", scholarship);

    for (int i = 0; i < NUM_STUD; i++)
		printf("Student %s earned: %d \n", students[i].name, students[i].totalEarned);

    return 0;

}

void* func(void* in){
	    Student_t * st;
	    st = (Student_t *) in;
	    while(scholarship > 0)
	    {
	        double payment = ceil(scholarship * 0.25); //
	        printf("%s = %.0lf\n", st->name,  payment);
	        scholarship = scholarship - (int)payment;
					st->totalEarned += (int)payment;

					sleep(SLEEP_TIME);
	    }
      return 0;
}
