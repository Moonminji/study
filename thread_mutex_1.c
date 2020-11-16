/**
 * @file 	thread_mutex.c
 * @brief 	
 * @author 	
 * @date 	2020ë…„ 11ì›” 13ì¼
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
// ë®¤í…ìŠ¤ ê°ì²´ ì„ ì–¸
pthread_mutex_t mutex_lock;
 
<<<<<<< HEAD
int g_count = 0;  // ½º·¹µå °øÀ¯ÀÚ¿ø.
=======
int g_count = 0;  // ì“°ë ˆë“œ ê³µìœ ìì›.
>>>>>>> 4aaca66ee4d23303bb735dd51882eb3239cace06
 
void *t_function(void *data)
{
    int i;
    char* thread_name = (char*)data;
<<<<<<< HEAD
    
	// critical section
    g_count = 0;   // ½º·¹µå¸¶´Ù 0ºÎÅÍ ½ÃÀÛ.

    for (i = 0; i < 5; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;  // ½º·¹µå °øÀ¯ÀÚ¿ø, 1Áõ°¡.
=======
    // critical section
    g_count = 0;   // ì“°ë ˆë“œë§ˆë‹¤ 0ë¶€í„° ì‹œì‘.
    for (i = 0; i < 3; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;  // ì“°ë ˆë“œ ê³µìœ ìì›, 1ì¦ê°€.
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
// thread Æ÷ÇÔµÈ ÄÚµå¸¦ ÄÄÆÄÀÏ ÇÒ  ¶© gcc -o ÆÄÀÏ¸í ÆÄÀÏ¸í.c -lpthread ÇØÁà¾ßÇÔ.
=======
// ì´ ì½”ë“œë¥¼ ëŒë¦´ ë• gcc -o íŒŒì¼ëª… íŒŒì¼ëª….c -lpthread í•´ì¤˜ì•¼í•¨.
>>>>>>> 4aaca66ee4d23303bb735dd51882eb3239cace06
