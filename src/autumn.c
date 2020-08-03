//
// Created by Administrator on 2020/7/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "maple.h"
#include "ginkgo.h"
#include "poplar.h"

#define AUTUMN_VERSION 1.0

static void autumn_print_version ();
static void autumn_print_help ();


static struct option long_options[] = {
        {"version", 0, 0, 'v'},
        {"file", 1, 0, 'f'},
        {"help", 0, 0, 'h'},
        {NULL, 0, NULL, 0},
};
int main(int argc, char **argv) {
    int c;
    int option_index = 0;
    while ((c = getopt_long(argc, argv, "vlwcf:h", long_options, &option_index)) != -1) {
        switch (c) {
            case 0:
                printf("option %s", long_options[option_index].name);

                if (optarg) {
                    printf(" with arg %s", optarg);
                }

                putchar('\n');
                break;

            case 'v':
                // version
                autumn_print_version();
                break;

            case 'f':
                // file
                printf("%s\n",optarg);
                m_parser(optarg);
                g_hello();
                p_hello();
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


void autumn_print_version () {
    printf("autumn %1.1f\n", AUTUMN_VERSION);
}

void autumn_print_help () {
    puts("Usage:");
    puts("-v, --version\n\tsee version number");
    puts("-f, --file [filename]:\n\tinterpret [filename]. Argument not optional.");
    puts("-h, --help:\n\tget this message");
}
