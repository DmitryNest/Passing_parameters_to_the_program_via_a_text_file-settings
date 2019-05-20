/*
 ============================================================================
 Name        : Passing_parameters_to_the_program_via_a_text_file.c
 Author      : =^_^=
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio.h>
#include <math.h>
int main(void){
  float *vector_a=NULL,*vector_b=NULL;// Объявлеие указателей к массивам с векторами
  FILE *myfile, *rezult;
  float n,val,sum,a,b,c;
  int zapros,kom,f=1;
  myfile = fopen ("test.txt", "r");//Чтение файла
  rezult = fopen ("rezult.txt", "w");//Запись в файл
  fscanf(myfile,"%d",&zapros);
  if(zapros == 0){//условие для работы с обычными числами
      fscanf(myfile,"%d %f %f %f",&kom,&a,&b,&c);
      switch(kom){
      case 1:
          c=a+b;
          break;
      case 2:
          c=a-b;
          break;
      case 3:
          c=a*b;
          break;
      case 4:
          c=a/b;
          break;
      case 5:
          c=pow(a,b);
          break;
      case 6:
          while (a>0){
              f*=a;
              a--;
          }
          c=f;
      }
      fprintf(rezult,"%.2f", c);
      }

  if(zapros==1){//Условие для работы с векторами
      fscanf(myfile,"%d" "%f",&kom,&n);// Выделение памяти для вектора 1 и считывание результатов
      vector_a = malloc(n * sizeof(float));
      for (int i = 0; i < n; i++){
          fscanf(myfile,"%f",&vector_a[i]);
      }
      vector_b = malloc(n * sizeof(float));// Выделение памяти для вектора 2 и считывание результатов
      for (int i = 0; i < n; i++){
          fscanf(myfile,"%f",&vector_b[i]);
      }
      switch(kom){
      case 1://Сумма векторов
          fprintf(rezult,"(");
          for(int i = 0; i < n; i++){//Вывод вектора
              fprintf(rezult,"%.2f ",vector_a[i]);
          }
          fprintf(rezult,")");
          fprintf(rezult,"+");
          fprintf(rezult,"(");
          for(int i = 0; i < n; i++){//Вывод вектора
              fprintf(rezult,"%.2f ",vector_b[i]);
          }
          fprintf(rezult,")");
          fprintf(rezult,"=");
          fprintf(rezult,"(");
          for(int i = 0; i < n; i++){
              val = vector_a[i] + vector_b[i];
              fprintf(rezult,"%.2f ",val);
          }
          fprintf(rezult,")");
          free(vector_a);//Очистка памяти
          free(vector_b);//Очистка памяти
          break;

      case 2://Разность векторов
          fprintf(rezult,"(");
          for(int i = 0; i < n; i++){//Вывод вектора
              fprintf(rezult,"%.2f ",vector_a[i]);
          }
          fprintf(rezult,")");
          fprintf(rezult,"-");
          fprintf(rezult,"(");
          for(int i = 0; i < n; i++){//Вывод вектора
              fprintf(rezult,"%.2f ",vector_b[i]);
          }
          fprintf(rezult,")");
          fprintf(rezult,"=");
          fprintf(rezult,"(");
          for(int i = 0; i < n; i++){
              val = vector_a[i] - vector_b[i];
              fprintf(rezult,"%.2f ",val);
                }
          fprintf(rezult,")");
          free(vector_a);//Очистка памяти
          free(vector_b);//Очистка памяти
          break;
      case 3://Скалярное произведение векторов
          fprintf(rezult,"(");
          for(int i = 0; i < n; i++){//Вывод вектора
              fprintf(rezult,"%.2f ",vector_a[i]);
          }
          fprintf(rezult,")");
          fprintf(rezult,"*");
          fprintf(rezult,"(");
          for(int i = 0; i < n; i++){//Вывод вектора
              fprintf(rezult,"%.2f ",vector_b[i]);
          }
          fprintf(rezult,")");
          fprintf(rezult," = ");
          for(int i = 0; i < n; i++){
              val = (vector_a[i] * vector_b[i]);
              sum = sum + val;
          }
          fprintf(rezult,"%.2f ",sum);
          free(vector_a);//Очистка памяти
          free(vector_b);//Очистка памяти
          break;
      }
  }
}
