   #include "assignment2.h"

   int line_count() {
      static int count = 1;
      char c[3];
      
      if(count == 20) {
         printf("\nCountinue?(y/n): ");
         while(c[0] != 'y') {
            scanf("%s", c);
            if(c[0] == 'y') {
               continue;
            } else if (c[0] == 'n') {
               exit(FALSE);
            } else {
               printf("Undefined input, please retype: ");
            }
            }
         count = 1;
      }
      count++;
   }
   // int openfile(FILE *fptr) //open file by type file name, if cannot open, print and exit
   // {
   //    char file_name[30];

   //    printf("Type your file name: ");
   //    scanf("%s", file_name);
   //    fptr = fopen(file_name,"r");
   //    if(!fptr) {
   //       printf("\nCann't open file.");
   //       return SUCCESS;
   //    }   
   // }
   int length_per_line(void) //type the present length of line in monitor you want to see
   {
         int length;
         printf("Length of each line you want to print(40 <= length <= 80): ");
         scanf("%d", &length);
      
      while (length < 40 || length > 80){
         printf("\nOut of range, please retype: ");
         scanf("%d", &length);
      }

      return length;
   }
   int wordlen(char* str) { // calculate length of a word
      int tempindex=0;

      while(str[tempindex]!=' ' && str[tempindex]!=0 && str[tempindex]!='\n'){
         tempindex++;
      }

      return tempindex;
   }



   STATUS wrap(char *buffer,int length){ //use for wrap lines which buffer readed from file

      int index=0;
      int curlinelen = 0;

      while(buffer[index] != '\0'){

         if(buffer[index] == '\n'){
             line_count();
            curlinelen=0;
         }
         else if(buffer[index] == ' '){

            if(curlinelen+wordlen(&buffer[index+1]) >= length){
               buffer[index] = '\n';
               line_count();
               curlinelen = 0;
            }

         }
         putchar(buffer[index]);
         curlinelen++;
         index++;

      }
      return SUCCESS;
   }

   STATUS buffer_store(FILE* fptr, char *buffer)
   {
      if (fgets(buffer, BUFFER_SIZE, fptr) == NULL) {
         // Error handling for failed fgets
         return FALSE;
      }
      return SUCCESS;
   }


   STATUS file_present(void)
   {
      char *buffer = malloc(BUFFER_SIZE);
      FILE* fptr;
      // if(!openfile(fptr)) {
      //    return 0;
      // }

      //temporary openfile function
      char file_name[30];

      printf("Type your file name: ");
      scanf("%s", file_name);
      fptr = fopen(file_name,"r");
      if(!fptr) {
         printf("\nCann't open file.");
         exit(1);
      }
      //end funtion
      
      int temp = length_per_line();

      

      while(SUCCESS) {
         
         if(!buffer_store(fptr, buffer)) {
            break;
         }
         if(!wrap(buffer, temp)) {
            exit(FALSE);
         };

      
      }
      fclose(fptr);
      return SUCCESS;
   }



