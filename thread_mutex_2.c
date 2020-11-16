/**
 * @file 	thread_mutex_2.c
 * @brief 	
 * @author 
 * @date 	2020년 11월 13일
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
<<<<<<< HEAD

// ���ؽ� ��ü ����
pthread_mutex_t mutex_lock;

int g_count = 0;  // ������ �����ڿ�.


=======
 
// 뮤텍스 객체 선언
pthread_mutex_t mutex_lock;
 
int g_count = 0;  // 쓰레드 공유자원.
 
>>>>>>> 4aaca66ee4d23303bb735dd51882eb3239cace06
void *t_function(void *data)
{
    int i;
    char* thread_name = (char*)data;

    pthread_mutex_lock(&mutex_lock);

    // critical section
<<<<<<< HEAD
    g_count = 0;   // �����帶�� 0���� ����.

    for (i = 0; i < 5; i++)
=======
    g_count = 0;   // 쓰레드마다 0부터 시작.
    for (i = 0; i < 3; i++)
>>>>>>> 4aaca66ee4d23303bb735dd51882eb3239cace06
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;  // 쓰레드 공유자원
        sleep(1);
    }

    pthread_mutex_unlock(&mutex_lock);
}


int main()
{
<<<<<<< HEAD
	pthread_t p_thread1, p_thread2;

	// ���ؽ� ��ü �ʱ�ȭ, �⺻ Ư������ �ʱ�ȭ ����.
	// mutex �� �������� �����尡 �����ϴ� ����Ÿ�� ��ȣ�ϱ� ���ؼ� ���Ǵ� �����ν�, ��ȣ�ϰ��� �ϴ� �����͸� �ٷ�� �ڵ念���� ���� '�ѹ��� �ϳ��� �����常' ���డ�� �ϵ��� �ϴ� ������� �����Ǵ� �����͸� ��ȣ�Ѵ�. 

	pthread_mutex_init(&mutex_lock, NULL);

	pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
	pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");

	pthread_join(p_thread1, NULL);
	pthread_join(p_thread2, NULL);

	return 0;

=======
    pthread_t p_thread1, p_thread2;
    int status;
    // 뮤텍스 객체 초기화, 기본 특성으로 초기화 했음
    pthread_mutex_init(&mutex_lock, NULL);
 
    pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
    pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");
 
    pthread_join(p_thread1, (void *)&status);
    pthread_join(p_thread2, (void *)&status);
>>>>>>> 4aaca66ee4d23303bb735dd51882eb3239cace06
}






















