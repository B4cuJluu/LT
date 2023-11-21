#include <stdio.h>

int main(void){
    int choice;

	printf("Выберите писателя по номеру: ");
    if(!scanf("%d", &choice)){
		printf("Ошибка! Неверный ввод.");
		return -1;
	}

    switch (choice){
	case 1:
	    printf("Борис Пастернак");
	    break;
	case 2:
	    printf("Агата Кристи");
	    break;
	case 3:
	    printf("Александр Дюма");
	    break;
	case 5:
	    printf("Сергей Есенин");
	    break;
	case 6:
	    printf("Гарри Гарисон");
	    break;
	case 7:
	    printf("Антон Чехов");
	    break;
	default:
	    printf("None");
	    break;
    }
	
    return 0;
}
