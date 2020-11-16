/**
 * @file 	thread_mutex_2.c
 * @brief 	
 * @author 	minji (minji@nasmedia.co.kr)
 * @date 	2020년 11월 13일
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// 뮤텍스 객체 선언
pthread_mutex_t mutex_lock;

int g_count = 0;  // 쓰레드 공유자원.


void *t_function(void *data)
{
    int i;
    char* thread_name = (char*)data;

    pthread_mutex_lock(&mutex_lock);

    // critical section
    g_count = 0;   // 쓰레드마다 0부터 시작.

    for (i = 0; i < 5; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;  // 쓰레드 공유자원
        sleep(1);
    }

    pthread_mutex_unlock(&mutex_lock);
}


int main()
{
	pthread_t p_thread1, p_thread2;

	// 뮤텍스 객체 초기화, 기본 특성으로 초기화 했음.
	// mutex 는 여러개의 쓰레드가 공유하는 데이타를 보호하기 위해서 사용되는 도구로써, 보호하고자 하는 데이터를 다루는 코드영역을 단지 '한번에 하나의 쓰레드만' 실행가능 하도록 하는 방법으로 공유되는 데이터를 보호한다. 

	pthread_mutex_init(&mutex_lock, NULL);

	pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
	pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");

	pthread_join(p_thread1, NULL);
	pthread_join(p_thread2, NULL);

	return 0;

}






















