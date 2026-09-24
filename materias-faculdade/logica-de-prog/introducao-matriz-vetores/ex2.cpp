#include <stdio.h>

main(){
	int n[10] = {12,45,33,58,90,99,75,45,120,130};
	
	for(int c= 0; c < 10; c++){
		if(n[c] % 2 == 0){
			printf("%d \n", n[c]);
		}
	}
}
