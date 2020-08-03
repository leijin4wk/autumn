//
// Created by Administrator on 2020/7/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "maple.h"
#include "ginkgo.h"
#include "poplar.h"

#define AUTUMN_VERSION 1.0

static void autumn_print_version ();
static void autumn_print_help ();
static int autumn_process_command();
static struct option long_options[] = {
        {"version", no_argument, NULL, 'v'},
        {"run", required_argument, NULL, 'r'},
        {"help", no_argument, NULL, 'h'},
        {NULL, no_argument, NULL, 0},
};
int main(int argc, char **argv) {
    int c;
    int option_index = 0;
    while ((c = getopt_long(argc, argv, "vrh", long_options, &option_index)) != -1) {
        switch (c) {
            case 'v':
                // version
                autumn_print_version();
                break;
            case 'r':
                printf("run:\n");
                int flag=1;
                while (flag) {
                    char str[50];
                    char *string = str;
                    printf("SQL->");
                    gets(string);
                    printf("%s\n", string);
                    flag=autumn_process_command(string);
                }
                break;
            case 'h':
                // help
                autumn_print_help();
                break;

            default:
                puts("For usage, run `autumn -h' or `autumn --help'.");
                break;
        }
    }

    return EXIT_SUCCESS;
}

int autumn_process_command(char * command){
    if (strcmp("quit",command)==0){
        printf("goodbye!\n");
        return 0;
    }
    m_parser(command);
    g_hello();
    p_hello();
    return 1;
}

void autumn_print_version () {
    printf("autumn %1.1f\n", AUTUMN_VERSION);
}

void autumn_print_help () {
    puts("Usage:");
    puts("-v, --version\n\t see version number");
    puts("-r, --run\n\t run ");
    puts("-h, --help:\n\t get this message");
}
