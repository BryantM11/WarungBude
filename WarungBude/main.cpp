#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../WarungBude/Controllers.h"

void time(){
#ifdef __ANDROID__
  printf("system:android\n");
 #elif __linux__
  printf("system:linux\n");
 #elif _WIN32
  printf("system:windows\n");
 #else 
  printf("unidentified OS\n\n");
 #endif
 time_t currentClock;
 time(&currentClock);
 printf("%s",ctime(&currentClock));
}

int main(){
    printf("1. Add Dish\n");
    printf("2. Remove Dish\n");
    printf("3. Add Customer\n");
    printf("4. Search Customer\n");
    printf("5. View Warteg\n");
    printf("6. Order\n");
    printf("7. Payment\n");
    printf("8. Exit Warteg\n");

    int input;
    scanf("%d", &input);
    switch (input) {
        case 1:
        	void addDish();
        	
            break;
        case 2:
        	void removeDish();
        	
            break;
        case 3:
        	void AddCustomer();
            break;
        case 4:
        	void SearchCustomer();
            break;
        case 5:
        	void ViewWarteg();
            break;
        case 6:
        	void Order();
            break;
        case 7:
        	void  Payment();
            break;
        case 8:
        	return 0;
            break;
        default:
            break;
    }
    return 0;
}
