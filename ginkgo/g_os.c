//
// Created by leijin on 2020/8/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int open_file(char * name){
    int fd = open("name.db", O_RDWR | O_CREAT , S_IRUSR | S_IWUSR | S_IROTH);
    if(fd == -1)
    {
        perror("open file error:");//只有上面的函数设置了error全局错误号，才可使用，会根据error输出对应的错误信息
        exit(-1);
    }
    printf("fd = %d\n", fd);
    return  fd;
}
int close_file(int fb){
    close(fb);
}
void read_page(int fd,off_t num,void *buf,size_t size){
    lseek(fd, num, SEEK_SET);
    int rd_ret = read(fd, buf, size);
    if(rd_ret == -1)
    {
        perror("read file error:");
        exit(-1);
    }
    printf("rd_ret = %d\n",rd_ret);
}

void write_page(int fd,off_t num,void *buf,size_t size){
    lseek(fd, num, SEEK_SET);
    int wr_ret = write(fd, buf, size);
    if(wr_ret == -1)
    {
        perror("write file error:");
        exit(-1);
    }
    printf("wr_ret = %d\n", wr_ret);
}