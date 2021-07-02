/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int c1, c2, c3, c4;
    c1 = 1;
    c2 = 1;
    c3 = 2;
    c4 = 2;
    
    if (c1 == c2 && c1 == c3 && c1 == c4){
        printf("todos iguais\n");
    }
    else if(c1 == c2 && c1 == c3){
        printf("c1, c2 e c3 iguais\n");
        
        if(c4 > c1){
            printf("O maior é c4");
        }else{
            printf("O menor é c4");
        }
    }
    else if(c1 == c2 && c1 == c4){
        printf("c1, c2 e c4 iguais\n");
        
        if(c3 > c1){
            printf("O maior é c3");
        }else{
            printf("O menor é c3");
        }
    }
    else if(c1 == c3 && c1 == c4){
        printf("c1, c3 e c4 iguais\n");
        
        if(c2 > c1){
            printf("O maior é c2");
        }else{
            printf("O menor é c2");
        }
    }
    else if(c2 == c3 && c2 == c4){
        printf("c2, c3 e c4 iguais\n");
        
        if(c1 > c2){
            printf("O maior é c1");
        }else{
            printf("O menor é c1");
        }
    }
    else if(c1 == c2){
        printf("Segundo turno entre c1 e c2\n");
        
        if(c3 > c1 && c3 > c4){
            printf("O maior é c3");
        }else if (c3 < c1 && c3 < c4){
          printf("O menor é c3");  
        }else if(c4 > c1 && c4 > c3){
            printf("O maior é c4");
        }else if(c4 < c1 && c4 < c3){
            printf("O menor é c4");
        }else{
            printf("c3 e c4 são iguais entre si");
        }
    }
    else if(c1 == c3){
        printf("Segundo turno entre c1 e c3\n");
        
        if(c2 > c1 && c2 > c4){
            printf("O maior é c2");
        }else if (c2 < c1 && c2 < c4){
          printf("O menor é c2");  
        }else if(c4 > c1 && c4 > c2){
            printf("O maior é c4");
        }else if(c4 < c1 && c4 < c2){
            printf("O menor é c4");
        }else{
            printf("c2 e c4 são iguais entre si");
        }
    }
    else if(c1 == c4){
        printf("Segundo turno entre c1 e c4\n");
        
        if(c2 > c1 && c2 > c3){
            printf("O maior é c2");
        }else if (c2 < c1 && c2 < c3){
          printf("O menor é c2");  
        }else if(c3 > c1 && c3 > c2){
            printf("O maior é c3");
        }else if(c3 < c1 && c3 < c2){
            printf("O menor é c3");
        }else{
            printf("c2 e c3 são iguais entre si");
        }
    }
    else if(c2 == c3){
        printf("Segundo turno entre c2 e c3\n");
        
        if(c1 > c2 && c1 > c4){
            printf("O maior é c1");
        }else if (c1 < c2 && c1 < c4){
          printf("O menor é c1");  
        }else if(c4 > c2 && c4 > c1){
            printf("O maior é c4");
        }else if(c4 < c2 && c4 < c1){
            printf("O menor é c4");
        }else{
            printf("c1 e c4 são iguais entre si");
        }
    }
    else if(c2 == c4){
        printf("Segundo turno entre c2 e c4\n");
        if(c1 > c2 && c1 > c4){
            printf("O maior é c1");
        }else if (c1 < c2 && c1 < c4){
          printf("O menor é c1");  
        }else if(c3 > c2 && c3 > c1){
            printf("O maior é c3");
        }else if(c3 < c2 && c3 < c1){
            printf("O menor é c3");
        }else{
            printf("c1 e c3 são iguais entre si");
        }
    }
    else if(c3 == c4){
        printf("Segundo turno entre c3 e c4\n");
        if(c1 > c3 && c1 > c2){
            printf("O maior é c1");
        }else if (c1 < c3 && c1 < c2){
          printf("O menor é c1");  
        }else if(c2 > c3 && c2 > c1){
            printf("O maior é c2");
        }else if(c2 < c3 && c2 < c1){
            printf("O menor é c2");
        }else{
            printf("c1 e c2 são iguais entre si");
        }
    }else{
        // Pegando o maior
        if (c1 > c2 && c1 > c3 && c1 > c4){
            printf("o maior é c1\n");
        }
        else if (c2 > c3 && c2 > c4){
            printf("o maior é c2\n");
        }
            
        else if (c3 > c4){
            printf("o maior é c3\n");
        }
        else{
            printf("o maior é c4\n");
        }
        
         // Pegando o menor
        if (c1 < c2 && c1 < c3 && c1 < c4){
            printf("o menor é c1\n");
        }
        else if (c2 < c3 && c2 < c4){
            printf("o menor é c2\n");
        }
            
        else if (c3 < c4){
            printf("o menor é c3\n");
        }
        else{
            printf("o menor é c4\n");
        }
    }
    
     
    
    return 0;
}
