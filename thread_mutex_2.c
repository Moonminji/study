/**
 * @file 	thread_mutex_2.c
 * @brief 	
 * @author 
 * @date 	2020ë…„ 11ì›” 13ì¼
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
<<<<<<< HEAD

// ¹ÂÅØ½º °´Ã¼ ¼±¾ğ
pthread_mutex_t mutex_lock;

int g_count = 0;  // ¾²·¹µå °øÀ¯ÀÚ¿ø.


=======
 
// ë®¤í…ìŠ¤ ê°ì²´ ì„ ì–¸
pthread_mutex_t mutex_lock;
 
int g_count = 0;  // ì“°ë ˆë“œ ê³µìœ ìì›.
 
>>>>>>> 4aaca66ee4d23303bb735dd51882eb3239cace06
void *t_function(void *data)
{
    int i;
    char* thread_name = (char*)data;

    pthread_mutex_lock(&mutex_lock);

    // critical section
<<<<<<< HEAD
    g_count = 0;   // ¾²·¹µå¸¶´Ù 0ºÎÅÍ ½ÃÀÛ.

    for (i = 0; i < 5; i++)
=======
    g_count = 0;   // ì“°ë ˆë“œë§ˆë‹¤ 0ë¶€í„° ì‹œì‘.
    for (i = 0; i < 3; i++)
>>>>>>> 4aaca66ee4d23303bb735dd51882eb3239cace06
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;  // ì“°ë ˆë“œ ê³µìœ ìì›
        sleep(1);
    }

    pthread_mutex_unlock(&mutex_lock);
}


int main()
{
<<<<<<< HEAD
	pthread_t p_thread1, p_thread2;

	// ¹ÂÅØ½º °´Ã¼ ÃÊ±âÈ­, ±âº» Æ¯¼ºÀ¸·Î ÃÊ±âÈ­ ÇßÀ½.
	// mutex ´Â ¿©·¯°³ÀÇ ¾²·¹µå°¡ °øÀ¯ÇÏ´Â µ¥ÀÌÅ¸¸¦ º¸È£ÇÏ±â À§ÇØ¼­ »ç¿ëµÇ´Â µµ±¸·Î½á, º¸È£ÇÏ°íÀÚ ÇÏ´Â µ¥ÀÌÅÍ¸¦ ´Ù·ç´Â ÄÚµå¿µ¿ªÀ» ´ÜÁö 'ÇÑ¹ø¿¡ ÇÏ³ªÀÇ ¾²·¹µå¸¸' ½ÇÇà°¡´É ÇÏµµ·Ï ÇÏ´Â ¹æ¹ıÀ¸·Î °øÀ¯µÇ´Â µ¥ÀÌÅÍ¸¦ º¸È£ÇÑ´Ù. 

	pthread_mutex_init(&mutex_lock, NULL);

	pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
	pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");

	pthread_join(p_thread1, NULL);
	pthread_join(p_thread2, NULL);

	return 0;

=======
    pthread_t p_thread1, p_thread2;
    int status;
    // ë®¤í…ìŠ¤ ê°ì²´ ì´ˆê¸°í™”, ê¸°ë³¸ íŠ¹ì„±ìœ¼ë¡œ ì´ˆê¸°í™” í–ˆìŒ
    pthread_mutex_init(&mutex_lock, NULL);
 
    pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
    pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");
 
    pthread_join(p_thread1, (void *)&status);
    pthread_join(p_thread2, (void *)&status);
>>>>>>> 4aaca66ee4d23303bb735dd51882eb3239cace06
}






















