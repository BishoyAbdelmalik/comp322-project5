#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/queue.h>

void openfolders(char *fileName)
{
    chdir(fileName);
    DIR *dp;
    struct dirent *dir;

    if ((dp = opendir(".")) == NULL)
    {
        printf("error openning folder %s\n", fileName);
    }

    while ((dir = readdir(dp)) != NULL)
    {
        char *fileName = dir->d_name;
        if (dir->d_ino == 0 || strcmp(fileName, ".") == 0 || strcmp(fileName, "..") == 0)
        {
            continue;
        }

        if (dir->d_type & DT_DIR)
        {

            printf("%s\n", fileName);

            openfolders(fileName);
            chdir("..");
        }
    }
}

TAILQ_HEAD(tailhead, entry) head;
struct entry {
  char *c;
  TAILQ_ENTRY(entry) entries;
};

void add_to_queue(char *ch) {
  struct entry *elem;
  elem = malloc(sizeof(struct entry));
  if (elem) {
    elem->c = ch;
  }
  TAILQ_INSERT_HEAD(&head, elem, entries);
}

int main(int argc, char *argv[])
{

    char *fileName;

    if (argc < 2)
    {
        /* code */
        fileName = ".";
    }
    else if (argc == 2)
    {
        fileName = argv[1];
    }
    else
    {
        printf("lsdir: too many files.\n");
        exit(1);
    }

    openfolders(fileName);

     char *ch = "A";
  int i;
  struct entry *elem;
  TAILQ_INIT(&head);
  add_to_queue(ch);
  ch = "B";
  add_to_queue(ch);

  elem = head.tqh_first;
  printf("string %s",elem->c);
  TAILQ_REMOVE(&head, head.tqh_first, entries);
  elem = head.tqh_first;
  printf("string %s", elem->c);



    return 0;
}