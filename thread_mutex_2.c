/**
 * @file 	thread_mutex_2.c
 * @brief 	
 * @author 	minji (minji@nasmedia.co.kr)
 * @date 	2020�� 11�� 13��
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
// ���ؽ� ��ü ����
pthread_mutex_t mutex_lock;
 
int g_count = 0;  // ������ �����ڿ�.
 
void *t_function(void *data)
{
    int i;
    char* thread_name = (char*)data;
    
    
 
    pthread_mutex_lock(&mutex_lock);
 
    // critical section
    g_count = 0;   // �����帶�� 0���� ����.
    for (i = 0; i < 3; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;  // ������ �����ڿ�
        sleep(1);
    }
 
    pthread_mutex_unlock(&mutex_lock);
}
int main()
{
    pthread_t p_thread1, p_thread2;
    int status;
    // ���ؽ� ��ü �ʱ�ȭ, �⺻ Ư������ �ʱ�ȭ ����
    pthread_mutex_init(&mutex_lock, NULL);
 
    pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
    pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");
 
    pthread_join(p_thread1, (void *)&status);
    pthread_join(p_thread2, (void *)&status);
}

