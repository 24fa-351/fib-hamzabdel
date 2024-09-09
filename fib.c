#include <stdio.h>
#include <stdlib.h>

int fibonacci_recursive(int number);
int fibonacci_iterative(int number);

int main(int argc, char *argv[]) {
   if (argc != 4){
      printf("Usage: %s <integer> <r/i> <filename>\n", argv[0]);
      return 1;
   }

   int input_num = atoi(argv[1]);
   char method = argv[2][0];
   char *filename = argv[3];

   FILE *file = fopen(filename, "r");

   int file_num;
   fscanf(file, "%d", &file_num);
   fclose(file);

   int fibonacci_input = (input_num + file_num) - 1;  

   int result;
   if (method == 'r') {
      result = fibonacci_recursive(fibonacci_input);
   }
   else if (method == 'i'){
      result = fibonacci_iterative(fibonacci_input);
   }
   else{
      return 1;
   }

   printf("%d\n", result);
   return 0;
}

int fibonacci_recursive(int number) {
    if (number == 0) {
        return 0;
    }
    if (number == 1) {
        return 1;
    }
    return fibonacci_recursive(number - 1) + fibonacci_recursive(number - 2);
}

int fibonacci_iterative(int number) {
   if (number <= 1)
      return number;
   int a = 0, b = 1, next;
   for (int i = 2; i <= number; i++) {
      next = a + b;
      a = b;
      b = next;
   }
   return b;
}
