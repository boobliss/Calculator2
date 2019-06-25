/*
 ============================================================================
 Name        : calculator2.c
 Author      : stasya
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	//size - размерность векторов
	//operation - операция над векторами
	//q - переменная для выхода из программы
	int size, operation, q;
	//sum - переменная для работы скалярного произведения
	float *vector_1, *vector_2, sum;
	do{
		printf("Введите размерность векторов: ");
		scanf("%i", &size);

		//выделяем память для векторов
		vector_1 = malloc(size*sizeof(float));
		vector_2 = malloc(size*sizeof(float));

		//вводим координаты для векторов
		printf("\nВведите координаты первого вектора: ");
		for(int i = 0; i<size; i++){
			scanf("%f", &vector_1[i]);
		}
		printf("\nВведите координаты второго вектора: ");
		for(int i = 0; i<size; i++){
			scanf("%f", &vector_2[i]);
		}

		printf("\nВведите номер операции, которую нужно выполнить: \n1) '+' - сложение\n2) '-' - разность\n3) '*' - скалярное произведение\n");
		//вводим операцию над векторами
		scanf("%i", &operation);

		//выводим первые два вектора в консоль
		printf("\nРезультат:\n");
		printf("(");
		for(int i = 0; i<size; i++){
			//если это НЕ последняя координата вектора, то число вместе с пробелом
			if(i != size-1)
				printf("%.0f ", vector_1[i]);
			else
				printf("%.0f", vector_1[i]);
		}
		if(operation == 1)
			printf(") + (");
		else if(operation == 2)
			printf(") - (");
		else
			printf(") * (");
		for(int i = 0; i<size; i++){
			if(i != size-1)
				printf("%.0f ", vector_2[i]);
			else
				printf("%.0f", vector_2[i]);
		}
		printf(") = ");
		sum = 0;
		//выполняем операцию над векторами
		switch(operation){
		case 1:  //сложение
			printf("(");
			for(int i = 0; i<size; i++){
				if(i != size-1)
					printf("%.0f ", vector_1[i] + vector_2[i]);
				else
					printf("%.0f", vector_1[i] + vector_2[i]);
			}
			printf(")\n");
			break;
		case 2:  //разность
			printf("(");
			for(int i = 0; i<size; i++){
				if(i != size-1)
					printf("%.0f ", vector_1[i] - vector_2[i]);
				else
					printf("%.0f", vector_1[i] - vector_2[i]);
			}
			printf(")\n");
			break;
		case 3:  //скалярное произведение
			for(int i = 0; i<size; i++){
				sum = sum + vector_1[i] * vector_2[i];
			}
			printf("%.0f", sum);
			break;
		}
		printf("\nДля выхода введите 1. Для продолжения введите любую другую цифру: ");
		//выхрдить из программы или нет ?
		scanf("%i", &q);
	} while(q != 1);
	printf("Работа программы завершена.");
	return EXIT_SUCCESS;
}
