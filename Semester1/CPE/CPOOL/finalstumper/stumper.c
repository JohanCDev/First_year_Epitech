/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-finalstumper-johan.chrillesen
** File description:
** stumper
*/
#include <unistd.h>
#define BUFF_SIZE 4096

void rush3(char *buff);

int main(void)
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len ;

    while ((len = read(0 , buff + offset , BUFF_SIZE - offset)) > 0) {
        offset = offset + len ;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84) ;
    rush3(buff) ;
    return (0) ;
}