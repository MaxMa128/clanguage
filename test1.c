int main()
{
         char c;
         int fd[2], fd2[2];
         pipe(fd);
         pipe(fd2);
         if (fork() == 0)
         {
                    write(fd[1], &c, 1);
                    putchar('b');
                    read(fd2[0], &c, 1);
                    putchar('d');
                    exit(0);
          }
          putchar('a');
          read(fd[0], &c, 1);
          putchar('c');
          write(fd2[1], &c, 1);
          wait(NULL);
          putchar('f');
          return 0;
}
