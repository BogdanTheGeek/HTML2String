#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] )
{
    if (argc < 2){
        printf("Please provide a file to convert.\n");
    }
    else{
        FILE *file = fopen( argv[1], "r" );
        if ( file == 0 ){
            printf( "Could not open file\n" );
            fclose( file );
            exit(EXIT_FAILURE);
        }

        printf("const static char http_html[] = \"");

        char c;
        char last_c;
        int open_h = 0;
        int open_dh = 0;

        while( (c = fgetc(file)) != EOF ){
            switch (c){

            case '\"':
                printf("\\\"");
                open_h == !open_h;
            break;

            case '\'':
                printf("\\\'");
                open_dh == !open_dh;
            break;

            case '\\':
                printf("\\\\");
            break;

            case ' ':
                if ((!open_dh || !open_h)&&(last_c != ' ')){
                    printf("%c", c);
                }
            break;

            case '\n':
            break;

            case '\r':
            break;

            case '\t':
            break;

            case '\f':
            break;

            default:
                printf("%c", c);
            break;

            }

            last_c = c;
        }
        printf("\";\n");
        fclose( file );
    }

    return 0;
}