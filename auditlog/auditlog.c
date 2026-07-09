#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define LOG_FILE "audit.log"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc < 2) {
        write(1, "Usage:\n", 7);
        write(1, "./auditlog --add \"message\"\n", 28);
        write(1, "./auditlog --view\n", 18);
        return 1;
    }

    // ---------------- ADD ----------------
    if (strcmp(argv[1], "--add") == 0) {

        if (argc != 3) {
            write(1, "Usage: ./auditlog --add \"message\"\n", 35);
            return 1;
        }

        int fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);

        if (fd < 0) {
            write(1, "Unable to open log file\n", 24);
            return 1;
        }

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);

        write(1, "Entry added.\n", 13);
    }

    // ---------------- VIEW ----------------
    else if (strcmp(argv[1], "--view") == 0) {

        int fd = open(LOG_FILE, O_RDONLY);

        if (fd < 0) {
            write(1, "No log file found.\n", 19);
            return 1;
        }

        char buffer[BUFFER_SIZE];
        int bytesRead;
        int line = 1;

        char num[20];

        sprintf(num, "%d: ", line++);
        write(1, num, strlen(num));

        while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {

            for (int i = 0; i < bytesRead; i++) {

                write(1, &buffer[i], 1);

                if (buffer[i] == '\n' && i != bytesRead - 1) {
                    sprintf(num, "%d: ", line++);
                    write(1, num, strlen(num));
                }
            }
        }

        close(fd);
    }

    else {
        write(1, "Invalid command\n", 16);
    }

    return 0;
}
