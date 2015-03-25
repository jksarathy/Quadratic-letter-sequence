#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define c1_RANGE ( (double) (textlength - c0) / (double) (stringlength - 1))
#define c2_RANGE ( (double) (textlength - c0 - c1 * (stringlength - 1)) / (double) ((stringlength -1) * (stringlength - 1)))
#define QLS (c0 + c1*j + c2*(j*j) )

char *
readFile()
{
    int mycount;       
    int size;           
    char *a;            
    int c;        

    mycount = 0;
    size = 1;

    a = malloc(sizeof(int) * size);     
    assert(a);
    if(a == 0) return 0;

    while((c = getchar()) != EOF) {
        
        while(mycount > size) {
            size *= 2;
            a = realloc(a, sizeof(int) * size);
            assert(a);
            if(a == 0) return 0;
        }

        a[mycount++] = c;
    }

    a = realloc(a, sizeof(int) * (mycount + 1));
    assert(a);

    return a;
}

void deleteArray(char *array) {
	free(array);
}

int main(int argc, char **argv) {
	int c0;
	int c1;
	int c2;
	
	int i;
	int j;
	int k;

	int stringlength;
	int textlength;

	char *string;
	char *compstring;

	char *text = readFile();
	textlength = strlen(text);

	for (i = 1; i < argc; i++) {
		string = argv[i];
		
		stringlength = strlen(string);
		
		if (i == 1) {
			compstring = malloc(sizeof(char) * (stringlength + 1));
		}
		else {
			compstring = realloc(compstring, sizeof(char) * (stringlength + 1));
		}
		
		strcpy(compstring, string);
		compstring[stringlength] = '\0';

	    for (k = 0; k < textlength; k++) {

	        if (text[k] == string[0]) {
	            c0 = k;
	            
	            for (c1 = 0; c1 < c1_RANGE; c1++) { 
	            	for (c2 = 0; c2 < c2_RANGE; c2++) { 
	            		
	            		for (j = 0; j < stringlength; j++) {
	            			compstring[j] = text[QLS];
	            		}

	            		if (strcmp(compstring,string) == 0){
	            			if (c1 != 0 || c2 != 0) {
	            				printf("%d %d %d %s\n", c0, c1, c2, string);
	            			}
	            		}
	            	}
	            }
	        }

	     }
	}

	deleteArray(text);
	
	return 0;
}
