/**
 * @file 	thread_mutex_1.c
 * @brief 	
 * @author 	
 * @date 	2020.11.16
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 

pthread_mutex_t mutex_lock;
 
int g_count = 0;  // ������ �����ڿ�.
 
void *t_function(void *data)
{
    int i;
    char* thread_name = (char*)data;
    
	// critical section
    g_count = 0;   // �����帶�� 0���� ����.

    for (i = 0; i < 5; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;  // ������ �����ڿ�, 1����
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

// thread ���Ե� �ڵ带 ������ ��  �� gcc -o ���ϸ� ���ϸ�.c -lpthread �������.
