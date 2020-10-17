#include<stdio.h>
 
int main() {
	char str[30];
	gets(str);
	int len = 0, length = 0, flag = 1, place = 0, point;
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')) {
			if (flag == 1) {
				point = i;
				flag = 0;
			} else
				len++;
 
		} else {
			flag = 1;
			if (len >= length) {
				length = len;
				place = point;
				len = 0;
			}
		}
	}
	for (i = place; i <=( place + length); i++)
		printf("%c", str[i]);
	return 0;
}

