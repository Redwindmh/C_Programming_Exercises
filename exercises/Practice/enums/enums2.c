#include <stdio.h>

typedef enum { SUCCESS, FAILURE, PENDING } Status;

void checkStatus(Status conStat);

int main() {
  Status status = SUCCESS;
  checkStatus(status);

  return 0;
}

void checkStatus(Status conStat) {
  switch (conStat) {
  case SUCCESS:
    printf("Connection successful!\n");
    break;
  case FAILURE:
    printf("Connection failed.\n");
    break;
  case PENDING:
    printf("Connecting...\n");
    break;
  }
}
