//
//  main.c
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
#include "commandhandler.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char input[100];
    printf("[Information] Waycore 0.1\n");
    printf("[Information] Loading...\n");
    for( ; ; ) {
        printf("==> ");
        
        scanf("%s", input);
        handle(input, "manual");
        
        
    }

    return 0;
}
