#include <stdio.h>

main(){
    int celsius, fahr;
    int lower, upper, step;    
    
    lower = 0;
    upper = 300;
    step = 20; 
    celsius = lower;

    while(celsius < 300){
        fahr = celsius * 9/5 + 32; 
        printf("%d %d\n", celsius, fahr);
        celsius += step;
    }

}