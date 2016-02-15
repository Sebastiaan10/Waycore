//
//  commandhandler.c
//  Waycore
//
//  Created by Sebastiaan mearadji on 14-02-16.
//  Copyright (c) © 2016 NOZTools. All rights reserved.
//
// \\                         //\\         //                    \       /
//   \\                     // \\         //          ___         \     /
//     \\                 //   \\        //          /   \         \___/
//       \\              //     \\      //          /     \          |
//         \\          //       \\     //          /-------\         |
//           \\       //        \\     //         /         \        |
//             \\=====           \\====//        /           \       |
//
//
//          -------       --------      |-----     |-----
//          |             |       |     |     |    |
//          |             |       |     |-----|    |-----
//          |             |       |     |\         |
//          |             |       |     |  \       |
//          -------       --------      |    \     |-----
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#if defined(_WIN32) || defined(_WIN64)
const char* os = "Windows";
#else
#ifdef __linux
const char* os = "Linux";
#else
#ifdef __unix
const char* os = "Unix";
#else
#ifdef __APPLE__
#include "TargetConditionals.h"
#if TARGET_OS_MAC
const char* os = "Mac os x";
#else
const char* os = "Unknow apple platform.";
#endif
#else
#ifdef defined(_POSIX_VERSION)
const char* os = "POSIX";
#else
const char* os = "Unknown platform";
#endif
#endif
#endif
#endif
#endif
void replace (char *, char *, char *);


void handle(char *input,char *handlemethod)  {
    
    if (strstr(input, "waycore.version==") != NULL) {
        replace(input, "waycore.version==", "V0.1");
    }
    if (strstr(input, "waycore.platform==") != NULL) {
        replace(input, "waycore.platform==", os);
    }
    if (strstr(input, "waycore.method==") != NULL) {
        replace(input, "waycore.method==", handlemethod);
    }
    
    replace(input, "^", " ");
    
    
    if (StartsWith(input, "exit@") == 1)
    {
        if (endsWith(input,";") == 1) {
            exit(0);
        }
        else {
            printf("[Error] Use by end of a function: ;\n");
        }
        
    }
    else if (StartsWith(input, "print@") == 1)
    {
        if (endsWith(input,";") == 1) {
            replace(input, "print@", "");
            replace(input, ";", "");
            printf("%s\n", input);
            
        }
        else {
            printf("[Error] Use by end of a function: ;\n");
        }
    }
    else {
        printf("[Information] Unknow function: %s \n", input);
    }
    
}

void replace(char * o_string, char * s_string, char * r_string) {
    //a buffer variable to do all replace things
    char buffer[4096];
    //to store the pointer returned from strstr
    char * ch;
    
    //first exit condition
    if(!(ch = strstr(o_string, s_string)))
        return;
    
    //copy all the content to buffer before the first occurrence of the search string
    strncpy(buffer, o_string, ch-o_string);
    
    //prepare the buffer for appending by adding a null to the end of it
    buffer[ch-o_string] = 0;
    
    //append using sprintf function
    sprintf(buffer+(ch - o_string), "%s%s", r_string, ch + strlen(s_string));
    
    //empty o_string for copying
    o_string[0] = 0;
    strcpy(o_string, buffer);
    //pass recursively to replace other occurrences
    return replace(o_string, s_string, r_string);
}
int StartsWith(const char *a, const char *b)
{
    if(strncmp(a, b, strlen(b)) == 0) return 1;
    return 0;
}
int endsWith (char* base, char* str) {
    int blen = strlen(base);
    int slen = strlen(str);
    return (blen >= slen) && (0 == strcmp(base + blen - slen, str));
}



