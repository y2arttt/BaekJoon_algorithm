#include <stdio.h>
double getGrade(char *grade){
	double result;
	
	if (grade[0] == 'A') result = 4.0;
	else if (grade[0] == 'B') result = 3.0;
	else if (grade[0] == 'C') result = 2.0;
	else if (grade[0] == 'D') result = 1.0;
	else if (grade[0] == 'F') result = 0.0;
	
	if (grade[1] == '+') result += 0.3;
	else if (grade[1] == '-') result -= 0.3;
	
	return result;
}

int main(){
	int n, credit_sum = 0, cal;
	double grade_sum = 0.0, total;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		char name[101], grade[3];
		int credit;
		
		scanf("%s %d %s", name, &credit, grade);
		credit_sum += credit;
		grade_sum += credit * getGrade(grade);
	}
	
	total = grade_sum/credit_sum + 0.0000001;
	printf("%.2f", total);
	return 0;
}