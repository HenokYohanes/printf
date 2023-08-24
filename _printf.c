#include <stdarg.h>
#include <stdio.h>
/**
 * print_int - print an integer
 *@n: given integer.
 */
void print_int(int n)
{
if (n < 0)
{
putchar('-');
n = -n;
}
if (n / 10)
{
print_int(n / 10);
}
putchar(n % 10 + '0');
}
/**
 * _printtf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printtf(const char *format, ...)
{
va_list args;
int count = 0, num, i;
va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
{
switch (format[i + 1])
{
case 'd':
case 'i':
{
num = va_arg(args, int);
print_int(num);
i++;
}
break;
}
}
else
{
putchar(format[i]);
count++;
}
}
va_end(args);
return (count);
}
