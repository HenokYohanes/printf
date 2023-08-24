#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Our printf function.
 * @format: The formatting string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0, i;
char *str, c;
if (!format)
return (-1);
va_start(args, format);
for (i = 0; format[i]; i++)
{
if (format[i] == '%' && (format[i + 1] == 'c'
|| format[i + 1] == 's' || format[i + 1] == '%'))
{
switch (format[++i])
{
case 'c':
putchar(c = va_arg(args, int));
count++;
break;
case 's':
str = va_arg(args, char *);
if (!str)
str = "(null)";
while (*str)
{
putchar(*str++);
count++;
} break;
case '%':
putchar('%');
count++;
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
