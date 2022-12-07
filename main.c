#include <stdio.h>
#include <syslog.h>
#include <unistd.h>
int main() {
	int loop;
	FILE *fptr;
	setlogmask (LOG_UPTO (LOG_NOTICE));

	openlog ("exampleprog", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
	
	loop = 0;
	while (loop >= 0){
		loop = loop + 1;
		syslog (LOG_NOTICE, "Program started by User %d", getuid ());
		syslog (LOG_INFO, "A tree falls in a forest");
		printf("This is a log line: %d\n", loop);

	fptr = fopen("some.log","a");
		fprintf(fptr,"This is a log line: %d\n", loop);
	fclose(fptr);
		sleep(1);
	}
	closelog ();
   printf("Finishig program....");
   return 0;
}
