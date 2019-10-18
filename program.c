#include<stdio.h>
#include<locale.h>
#include<math.h>
#define AUTO_MORPHS 1000000
/*1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h);
 * где m-масса тела в килограммах, h - рост в метрах.*/
float index_m(float m, float h){
    float i = m / (h * h);
    return i;
}
/*3. Написать программу обмена значениями двух целочисленных переменных:
b. *без использования третьей переменной.*/
void replace_int(int* a, int* b){
    *a ^= *b;
    *b ^= *a;
    *a ^=*b;
}

/*4. Написать программу нахождения корней заданного квадратного уравнения.*/
void root_squer(float* x1, float* x2, float a, float b, float c){
    float d = (b * b) - (4 * a * c);
    if(d > 0){
        *x1 = (- b + sqrt(d)) / (2 * a);
        *x2 = (- b - sqrt(d)) / (2 * a);
        printf("x1 = %.2f, x2 = %.2f", *x1, *x2);
    }
    else if(d == 0){
        *x1 = -b / (2 * a);
        *x2 = *x1;
        printf("x = %.2f", *x1);
    }
    else
        printf("Нет корней!");
}
/*6.Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год»,
    «года» или «лет».*/
void your_age(){
    int age;
    printf("\nУкажите свой возраст: ");
    scanf("%d", &age);
    switch(age % 10){
    case 1: printf("Вам %d год.", age);
        break;
    case 2:
    case 3:
    case 4: printf("Вам %d года", age);
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0: printf("Вам %d лет.", age);
        break;
    }
}
/*7. Имеются числовые координаты двух полей шахматной доски (x1,y1,x2,y2).
   Требуется определить, относятся ли к поля к одному цвету или нет.*/
void chah_mate(int x1, int y1, int x2, int y2){
    if(((x1 + y1) % 2) == ((x2 + y2) % 2))
        printf("\nПоля относятся к одному цвету.");
    else
        printf("\nПоля не относятся к одному цвету.");
}
/*9. Даны целые положительные числа N и K.
    Используя только операции сложения и вычитания, найти частное от деления нацело N на K,
    а также остаток от этого деления */
 void div_mod(int a, int b){
    if(b == 0){
        printf("Некорректная операция!");
        return ;
    }
    int res1 = 0;
    int res2;
    int a1 = a;
    while(a1 > b){
        a1 -= b;
        res1++;
    }
    (a > 0)? res2 = a : res2 = 0;
    printf("\n%d/%d = %d", a, b, res1);
    printf("\nОстаток от деления: %d", res2);
}
/*10. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить,
      имеются ли в записи числа N нечетные цифры.
      Если имеются, то вывести True, если нет — вывести False.*/
 void odd_numbers(int a){
     int b;
     while(a){
         b = a % 10;
         if((b % 2) != 0 ){
             printf("True");
             return;
         }
         a /= 10;
     }
     printf("False");
 }
 /*14. * Автоморфные числа. Натуральное число называется автоморфным,
     если оно равно последним цифрам своего квадрата.
     Например, 25 \ :sup: 2 = 625. Напишите программу, которая выводит на экран все автоморфные числа,
     в пределах 1_000_000*/
 void auto_morphs(){
     int c;
     int res;
     for(int i = 0; i < AUTO_MORPHS; i++){
         c = 1;
         res = 0;
         while(i >= c) c*=10;
         res = (i * i) % c;
         if(res == i) printf("\n%d", i);
     }
     printf("\n");
 }
/*15. Дублирую задание по улучшению алгоритма с урока))
float mean() { // homework #1
  int sum = 0;
  int counter = 0;
  int in;
  scanf("%d", &in);
  while (in != -1) {
        sum = sum + in;
        counter++;
        scanf("%d", &in);
  }
  if (counter != 0)
        return sum / counter;
  else
        return -1;
}*/
float mean(){
        int sum = 0;
        int counter = 0;
        int in;
        while((scanf("%d", &in)), in > 0){
            sum = sum + in;
            counter++;
        }
        if(counter != 0)
            return  sum / counter;
        else {
            return -1;
        }
    }

 int main(int argc, char* args[]){
    setlocale(LC_ALL, "1251");
//1.
    float m;
    float h;
    printf("Введите массу: ");
    scanf("%f", &m);
    printf("Введите рост: ");
    scanf("%f", &h);
    printf("Индекс равен: %.2f кг/m2\n", index_m(m, h));
//3.
    int a = 50;
    int b = 30;
    printf("a = %d, b = %d\n", a, b);
    replace_int(&a, &b);
    printf("a = %d, b = %d\n", a, b);
//4.x^2-1/2x-1/2=0
    float i = 1;
    float j = -0.5;
    float k = -0.5;
    float x1;
    float x2;
    root_squer(&x1, &x2, i, j, k);
//6.
    your_age();
//7.
    int chx1, chx2, chy1, chy2;
    chx1 = 2;
    chy1 = 3;
    chx2 = 0;
    chy2 = 1;
    chah_mate(chx1, chy1, chx2, chy2);
//9.
    printf("\nВведите делимое: ");
    scanf("%d", &a);
    printf("Введите делитель: ");
    scanf("%d", &b);
    div_mod(a, b);
//10.
    printf("\nВведите число(если есть нечет. цифры -True, нет -False): ");
    scanf("%d", &a);
    odd_numbers(a);
//14.
    auto_morphs();
//15.
    printf("%f", mean());
    return 0;
}
