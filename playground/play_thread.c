#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*do_something(void *arg)
{
	puts("do something");
	sleep(5);
}

int	main(void)
{
	pthread_t	thread;
	void		*retval;

	// スレッドを作成
	if (pthread_create(&thread, NULL, do_something, NULL) != 0)
	{
		// エラー処理
		return (0);
	}
	// スレッドの終了方法
	// 1. スレッドが終了するまで待つ
	pthread_join(thread, &retval);
	puts("wait");
	pthread_detach(thread);
	puts("no wait");
	// 2. スレッドを待たない
}
