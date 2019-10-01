//A.Illarionov
#include<stdio.h>
/*1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию*/
int change_to_binary(int a){
    if(a == 1) return 1;
    int b = a;
    (a % 2) ? a = a / 2 : a = a / 2;
    int res = change_to_binary(a);
    res = (b % 2) + 10 * res;
    return res;
}
/*2. Реализовать функцию возведения числа a в степень b:
a. без рекурсии;
b. рекурсивно;
c. *рекурсивно, используя свойство чётности степени.*/
int pow_a(int a, int b){
    int res = a;
    for(int i = 0; i < (b - 1); i++){
        res *= a;
    }
    return res;
}
int pow_b(int a, int b){
    if(b == 1) return a;
    b -= 1;
    int res = pow_b(a, b);
    return a * res;
}
int pow_c(int a, int b){
    if( b == 1 ) return a;
    if(b % 2 == 0){
        b /= 2;
        int res = pow_c(a, b);
        res *= res;
        return res;
    }
    else{
        b /= 2;
        int res = pow_c(a, b);
        res = res * res * a;
        return res;
    }
}
/*3. Исполнитель Калькулятор преобразует целое число, записанное на экране.
 *У исполнителя две команды, каждой команде присвоен номер:
  Прибавь 1 2.Умножь на 2 Первая команда увеличивает число на экране на 1,
  вторая увеличивает это число в 2 раза. Сколько существует программ, которые число 3 преобразуют в число 20?
  а) с использованием массива; б) с использованием рекурсии.*/
int calculate(int a, int b){
    if(b / 2 <= a) return 1;
    int res;
    b /= 2;
    res = calculate(a, b);
    res++;

    return res;




}

int main(int argc, char* args[]){
//1.
    int a;
    printf("Inter num: ");
    scanf("%d", &a);
    printf("%d in binary: %d",a , change_to_binary(a));
//2.
    int b;
    printf("\nInter power: ");
    scanf("%d",&b);
    printf("a. %d^%d = %d\n",a , b, pow_a(a, b));
    printf("b. %d^%d = %d\n",a , b, pow_b(a, b));
    printf("c. %d^%d = %d\n",a , b, pow_c(a, b));
//3.
    int begin = 3;
    int end = 20;
    printf("betwin %d and %d %d paths.", begin, end, calculate(begin, end));
    return 0;
}
