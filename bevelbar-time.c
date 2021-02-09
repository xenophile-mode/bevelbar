/* For nanosleep() */
#define _POSIX_C_SOURCE 199309L

#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

void
read_msg(char *path)
{
    FILE *fp;
    char buf[BUFSIZ];
    size_t have_read;

    if ((fp = fopen(path, "r")) != NULL)
    {
        while ((have_read = fread(buf, 1, sizeof buf, fp)) != 0)
            fwrite(buf, 1, have_read, stdout);
        fclose(fp);
    }
}

int
main(int argc, char **argv)
{
    struct timeval tv;
    struct timespec sleep;
    struct tm *l;
    char *fmt = "%a, %F (W%V), %T %z";
    char style = '2';
    char out[128] = "";
    char *msg_left = NULL, *msg_right = NULL;
    bool show_time = true;
    int opt;

    while ((opt = getopt(argc, argv, "f:l:r:ns:")) != -1)
    {
        switch (opt)
        {
            case 'l':
                msg_left = optarg;
                break;
            case 'r':
                msg_right = optarg;
                break;
            case 'f':
                fmt = optarg;
                break;
            case 's':
                style = optarg[0];
                break;
            case 'n':
                show_time = false;
                break;
        }
    }

    for (;;)
    {
        gettimeofday(&tv, NULL);

        printf("a\n");

        if (msg_left != NULL)
            read_msg(msg_left);

        if (show_time)
        {
            l = localtime(&tv.tv_sec);
            strftime(out, sizeof out, fmt, l);
            out[(sizeof out) - 1] = 0;
            printf("%c%s\n", style, out);
        }

        if (msg_right != NULL)
            read_msg(msg_right);

        printf("e\nf\n");
        fflush(stdout);

        sleep.tv_sec = 0;
        sleep.tv_nsec = (1000000 - tv.tv_usec) * 1000;
        nanosleep(&sleep, NULL);
    }

    /* unreached */
}
