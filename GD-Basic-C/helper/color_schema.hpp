//
//  color_schema.h
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#ifndef color_schema_h
#define color_schema_h

// Reset
#define RESET                       "\033[0m"       // Text Reset

// Regular Colors
#define BLACK                       "\033[0;30m"    // BLACK
#define RED                         "\033[0;31m"    // RED
#define GREEN                       "\033[0;32m"    // GREEN
#define YELLOW                      "\033[0;33m"    // YELLOW
#define BLUE                        "\033[0;34m"    // BLUE
#define PURPLE                      "\033[0;35m"    // PURPLE
#define CYAN                        "\033[0;36m"    // CYAN
#define WHITE                       "\033[0;37m"    // WHITE

// Bold
#define BLACK_BOLD                  "\033[1;30m"    // BLACK
#define RED_BOLD                    "\033[1;31m"    // RED
#define GREEN_BOLD                  "\033[1;32m"    // GREEN
#define YELLOW_BOLD                 "\033[1;33m"    // YELLOW
#define BLUE_BOLD                   "\033[1;34m"    // BLUE
#define PURPLE_BOLD                 "\033[1;35m"    // PURPLE
#define String CYAN_BOLD            "\033[1;36m"    // CYAN
#define WHITE_BOLD                  "\033[1;37m"    // WHITE

// Underline
#define BLACK_UNDERLINED            "\033[4;30m"    // BLACK
#define RED_UNDERLINED              "\033[4;31m"    // RED
#define GREEN_UNDERLINED            "\033[4;32m"    // GREEN
#define YELLOW_UNDERLINED           "\033[4;33m"    // YELLOW
#define BLUE_UNDERLINED             "\033[4;34m"    // BLUE
#define PURPLE_UNDERLINED           "\033[4;35m"    // PURPLE
#define CYAN_UNDERLINED             "\033[4;36m"    // CYAN
#define WHITE_UNDERLINED            "\033[4;37m"    // WHITE

// Background
#define BLACK_BACKGROUND            "\033[40m"      // BLACK
#define RED_BACKGROUND              "\033[41m"      // RED
#define GREEN_BACKGROUND            "\033[42m"      // GREEN
#define YELLOW_BACKGROUND           "\033[43m"      // YELLOW
#define BLUE_BACKGROUND             "\033[44m"      // BLUE
#define PURPLE_BACKGROUND           "\033[45m"      // PURPLE
#define CYAN_BACKGROUND             "\033[46m"      // CYAN
#define WHITE_BACKGROUND            "\033[47m"      // WHITE

// High Intensity
#define BLACK_BRIGHT                "\033[0;90m"    // BLACK
#define RED_BRIGHT                  "\033[0;91m"    // RED
#define GREEN_BRIGHT                "\033[0;92m"    // GREEN
#define YELLOW_BRIGHT               "\033[0;93m"    // YELLOW
#define BLUE_BRIGHT                 "\033[0;94m"    // BLUE
#define PURPLE_BRIGHT               "\033[0;95m"    // PURPLE
#define CYAN_BRIGHT                 "\033[0;96m"    // CYAN
#define WHITE_BRIGHT                "\033[0;97m"    // WHITE

// Bold High Intensity
#define BLACK_BOLD_BRIGHT           "\033[1;90m"    // BLACK
#define RED_BOLD_BRIGHT             "\033[1;91m"    // RED
#define GREEN_BOLD_BRIGHT           "\033[1;92m"    // GREEN
#define YELLOW_BOLD_BRIGHT          "\033[1;93m"    // YELLOW
#define BLUE_BOLD_BRIGHT            "\033[1;94m"    // BLUE
#define PURPLE_BOLD_BRIGHT          "\033[1;95m"    // PURPLE
#define CYAN_BOLD_BRIGHT            "\033[1;96m"    // CYAN
#define WHITE_BOLD_BRIGHT           "\033[1;97m"    // WHITE

// High Intensity backgrounds
#define BLACK_BACKGROUND_BRIGHT     "\033[0;100m"   // BLACK
#define RED_BACKGROUND_BRIGHT       "\033[0;101m"   // RED
#define GREEN_BACKGROUND_BRIGHT     "\033[0;102m"   // GREEN
#define YELLOW_BACKGROUND_BRIGHT    "\033[0;103m"   // YELLOW
#define BLUE_BACKGROUND_BRIGHT      "\033[0;104m"   // BLUE
#define PURPLE_BACKGROUND_BRIGHT    "\033[0;105m"   // PURPLE
#define CYAN_BACKGROUND_BRIGHT      "\033[0;106m"   // CYAN
#define WHITE_BACKGROUND_BRIGHT     "\033[0;107m"   // WHITE

#endif /* color_schema_h */
