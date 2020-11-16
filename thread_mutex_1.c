/**
 * @file 	thread_mutex.c
 * @brief 	
 * @author 	
 * @date 	2020년 11월 13일
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
// 뮤텍스 객체 선언
pthread_mutex_t mutex_lock;
 
<<<<<<< HEAD
int g_count = 0;  // ������ �����ڿ�.
=======
int g_count = 0;  // 쓰레드 공유자원.
>>>>>>> 4aaca66ee4d23303bb735dd51882eb3239cace06
 
void *t_function(void *data)
{
    int i;
    char* thread_name = (char*)data;
<<<<<<< HEAD
    
	// critical section
    g_count = 0;   // �����帶�� 0���� ����.

    for (i = 0; i < 5; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;  // ������ �����ڿ�, 1����.
=======
    // critical section
    g_count = 0;   // 쓰레드마다 0부터 시작.
    for (i = 0; i < 3; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;  // 쓰레드 공유자원, 1증가.
>>>>>>> 4aaca66ee4d23303bb735dd51882eb3239cace06
        sleep(1);
    }
}
int main()
{
    pthread_t p_thread1, p_thread2;
    int status;
 
    pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
    pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");
 
    pthread_join(p_thread1, NULL);
    pthread_join(p_thread2, NULL);

}



<<<<<<< HEAD
// thread ���Ե� �ڵ带 ������ ��  �� gcc -o ���ϸ� ���ϸ�.c -lpthread �������.
=======
// 이 코드를 돌릴 땐 gcc -o 파일명 파일명.c -lpthread 해줘야함.
>>>>>>> 4aaca66ee4d23303bb735dd51882eb3239cace06
