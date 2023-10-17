

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>


#define FILE_PATH               "../res/name_scores"
#define FILE_BUFFER             49152
#define WORD_SIZE               16 
#define NUMBER_WORDS            6124


int compare(const void* a, const void* b);
uint32_t getWordTotal(const char* a);
int main(int argc, char** argv);
FILE* getFile(const char* path);
char* readWords(FILE* file);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        FILE* file = getFile(FILE_PATH);
        char* line = readWords(file);
        char** words = malloc(NUMBER_WORDS * sizeof(char*));
        int wc = 0;

        for(int i = 0; line[i] != EOF ; i++){

                if(line[i] == '\0') continue;

                words[wc++] = (line + i);

                /* Get to the next word */
                while(*(line + i) != '\0') i++;

        }

        qsort(words, wc, sizeof(char*), compare);

        uint64_t sum = 0;

        for(uint32_t i = 1; *words; i++){
                sum += i * getWordTotal(*words++);
        }

        printf("%"PRIu64"\n", sum);

        return 0;

}


FILE* getFile(const char* path)
{
	FILE* file = NULL;

	if(!(file = fopen(path, "r"))){
		printf("Couldn't open file\n");
		exit(1);
	}

        return file;
}


uint32_t getWordTotal(const char* a)
{
        /* The ampersand character takes
         * a capital letter to being the integer 
         * representation of its alpha position */
        uint32_t sum = 0;

        for( ; *a; sum += *a++ - '@')
                ;

        return sum;
}


char* readWords(FILE* file)
{
        size_t n = FILE_BUFFER;

        char* words = malloc(n * sizeof(char));
        memset(words, 0, (n * sizeof(char)));

        char c;

        /* We don't want the first character */
        (void) fgetc(file); 

        for(uint32_t i = 0; i < n; i++){

                c = (char) fgetc(file);

                if(c == EOF) break;

                if(i + 1 == n){
                        n *= 2;
                        char* tmp = realloc(words, (n * sizeof(char)));

                        if(!tmp) exit(2);

                        words = tmp;
                }

                words[i] =  c;
        }

        char* tmp = words;

        /* Replace the delimeters with null characters so we can pass in 
         * addresses to substrings from the same character array */
        while(*tmp){
                *tmp = (*tmp == '"' || *tmp == ',') ? '\0' : *tmp;
                tmp++;
        }

        /* So we know when to stop iterating */
        *++tmp = EOF;

        fclose(file);

        return words;
} 

int compare(const void* a, const void* b)
{
        return strcmp(*((char**) a), *((char**) b));
}


