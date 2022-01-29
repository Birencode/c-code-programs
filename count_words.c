#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef uint16_t bool;
#define FALSE 0
#define TRUE 1
typedef struct node {
      int word_count;
      struct node *next;
      int word_len;
      char word[];
}NODE;
NODE *head = NULL;

// To add the unique word into growing linked list 
// and add the unique word count.
void allocate_buffer(char *ptr, int charac_count)
{
  
  NODE *temp =NULL;
  if(head != NULL)
  {
    temp = head;
    while(temp)
    {
      if((temp->word_len == (charac_count+1)) && 
          (strncmp(temp->word, ptr, charac_count) == 0))
       {
	  temp->word_count++;
	  return;
       }
       temp = temp->next;
    }
  }
  
  NODE *node = (NODE*)malloc(sizeof(NODE) + charac_count+1);
  node->word_len = charac_count + 1;
  node->word_count = 0;
  strncpy(node->word, ptr ,charac_count);
  node->word[charac_count] = '\0';
  node->next = head;
  head = node;
  printf("%s %d\n",node->word, charac_count);
}
void print_word_and_count()
{
  NODE *temp = head;
  while(temp)
  {
    printf("\n word: %s & count : %d",temp->word, ++temp->word_count);
    temp = temp->next;
  }
}
void main()
{
 char read_line[] = "hello I am Birendra \n"
                     "good people \n"
		     "good work is hello";
 char *ptr = read_line;
 int i=0, count_word=0, line=0;
 static int count_char_in_word=0;
 bool start_word = FALSE;
 bool end_line = FALSE;
 while(*ptr != '\0')
 {
  if(*ptr == ' ' || (*ptr == '\n'))
  {
    if(*ptr == '\n')
       line++;
    if(start_word)
    {
      count_word++;
      start_word=FALSE;
      char *start_word_pointer = ptr - count_char_in_word;
      allocate_buffer(start_word_pointer, count_char_in_word);
      count_char_in_word = 0;
    }
    ptr++;
  }
  else
  {
    start_word=TRUE;
    ptr++;
    ++count_char_in_word;
    
  }
 }
 char *str_wrd = ptr - (count_char_in_word );
 allocate_buffer(str_wrd, count_char_in_word);
 printf("\nwords in para:%d", ++count_word); // increment to add last word, as while loop will exit '\0'
 printf("\nNumber of line:%d", ++line); // increment to add last line
 print_word_and_count();
}

#if 0
Test Result
 ==============================
 5
 I 1
 am 2
 Birendra 8
 good 4
 people 6
 work 4
 is 2

 words in para:10
 Number of line:3
 word: is & count : 1
 word: work & count : 1
 word: people & count : 1
 word: good & count : 2
 word: Birendra & count : 1
 word: am & count : 1
 word: I & count : 1
 word: hello & count : 2 
 ==============================
>>>>>>> cleanup of code
#endif
