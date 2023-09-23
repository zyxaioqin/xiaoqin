#include <stdio.h>
#include <conio.h> 
#include <windows.h>
// ��ȡĳ��ĳ�µ�������
int getDaysOfMonth(int year, int month) 
{
    int days;
    if (month == 4 || month == 6 || month == 9 || month == 11) 
	{
        days = 30;
    } 
	else if (month == 2)
	{
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) 
		{
            days = 29;
        } 
		else
		{
            days = 28;
        }
    } 
	else 
	{
        days = 31;
    }
    return days;
}
// ��ȡĳ��ĳ�µĵ�һ�������ڼ�
int getFirstDayOfWeek(int year, int month) 
{
    int c, y, m, d;//���ڴ洢��ݡ��·ݺ���ʱ�������� 
    if(month == 1 || month == 2) 
	{
        m = month + 12;
        y = year - 1;
    } 
	else 
	{
        m = month;
        y = year;
    }
    c = y / 100;//������������
    y = y % 100;//���������� 
    d = 1;
    int w = (y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1) % 7;//�������� 
    if (w < 0) 
	{
        w += 7;
    }
    return w;
}
// ��ʾ����
void showCalendar(int year, int month, int day) 
{
    system("cls");  // ����
    // ��ȡ��ǰ����
    SYSTEMTIME curTime;
    GetLocalTime(&curTime);
    // ��ȡ��ǰ���µĵ�һ�������ڼ���������
    int firstDayOfWeek = getFirstDayOfWeek(year, month);
    int days = getDaysOfMonth(year, month);
    // ��ӡ����
    printf("      %d��%d��\n", year, month);
    printf("-----------------------------\n");
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    int i;//����ѭ���������� 
    for (i = 0; i < firstDayOfWeek; i++) 
	{
        printf("     ");
    }
    for (i = 1; i <= days; i++) 
	{
        if (i == day && year == curTime.wYear && month == curTime.wMonth) 
		{
            printf("\033[31m");  // ���ú�ɫ������ɫ
        }
        printf(" %3d ", i);
        if ((firstDayOfWeek + i) % 7 == 0) 
		{
            printf("\n");
        }
        if (i == day && year == curTime.wYear && month == curTime.wMonth) 
		{
            printf("\033[0m");  // ����������ɫ
        }
    }
    printf("\n-----------------------------\n");
}
int main() 
{
    int year, month, day;
    // ��ȡ��ǰ����
    SYSTEMTIME curTime;//�洢��ǰϵͳʱ�䡣
    GetLocalTime(&curTime);//��ȡ��ǰϵͳʱ�䡣 
    year = curTime.wYear;
    month = curTime.wMonth;
    day = curTime.wDay;//��ȡ��ǰϵͳ���ڡ�
    while (1) 
	{
        showCalendar(year, month, day);
        // ��ȡ�û�����
        int key = getch();
        if (key == 72) 
		{  // �������
            if (month == 1) 
			{
                year--;
                month = 12;
            } 
			else 
			{
                month--;
            }
        } 
		else if (key == 80)// ������� 
		{  
            if (month == 12) 
			{
                year++;
                month = 1;
            } 
			else 
			{
                month++;
            }
        } 
		else if (key == 75)// ������� 
		{  
            year--;
        } 
        
		else if (key == 77)  // �������
		{ 
            year++;
        }
		else if (key == 13)// �س��� 
		{  
            printf("��������ݺ��·ݣ�");
            scanf("%d %d", &year, &month);
            day = 1;  // �л���ݺ��·�ʱ����������Ϊ1��
        } 
		else if (key == 27) 
		{  // ESC���˳�
            break;
        }
        // �߽紦��
        if (year < 1) 
		{
            year = 1;
        }
        if (month < 1) 
		{
            month = 1;
        }
        if (month > 12) 
		{
            month = 12;
        }
    }
    return 0;
}
