#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0, i, j;
char c;
va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%' && (format[i + 1] == 'c'
|| format[i + 1] == 's' || format[i + 1] == '%'))
{
switch (format[i + 1])
{
case 'c':
c = va_arg(args, int);
putchar(c);
count++;
i++;
break;
case 's':
{
char *str = va_arg(args, char *);
for (j = 0; str[j] != '\0'; j++, count++)
{
putchar(str[j]);
} i++;
} break;
case '%':
putchar('%');
count++;
i++;
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
