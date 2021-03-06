//Akshat Gupta(181112052)
//A-6  Q-1(Implement Binary and counting semaphore.)

// a) Binary Semaphore:-

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int a, b;
sem_t sem;
void ScanNumbers(void *ptr){
    for (;;){
        printf("%s", (char *)ptr);
        scanf("%d %d", &a, &b);
        sem_post(&sem);
        usleep(100 * 1000);
    }
}
void SumAndPrint(void *ptr){
    for (;;){
        sem_wait(&sem);
        printf("%s %d\n", (char *)ptr, a + b);
    }
}
int main()
{
    pthread_t thread1;
    pthread_t thread2;
    char *Msg1 = "Enter Number Two No\n";
    char *Msg2 = "sum = ";
    sem_init(&sem, 0, 0);
    pthread_create(&thread1, NULL, (void *)ScanNumbers, (void *)Msg1);
    pthread_create(&thread2, NULL, (void *)SumAndPrint, (void *)Msg2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Wait For Both Thread Finished\n");
    sem_destroy(&sem);     `
    return 0;
}

// b) Counting Semaphore:-

#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>
#include <unistd.h>
sem_t s;
void handler(int signal)
{
    sem_post(&s);
}
void *singsong(void *param)
{
    sem_wait(&s);
    printf("I had to wait until your signal released me!\n");
}
int main()
{
    int ok = sem_init(&s, 0, 0);
    if (ok == -1) {
       perror("Could not create unnamed semaphore");
       return 1;
    }
    signal(SIGINT, handler);

    pthread_t tid;
    pthread_create(&tid, NULL, singsong, NULL);
    pthread_exit(NULL);
}
