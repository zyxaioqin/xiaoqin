#include <stdio.h>
#include <conio.h> 
#include <windows.h>
// 获取某年某月的总天数
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
// 获取某年某月的第一天是星期几
int getFirstDayOfWeek(int year, int month) 
{
    int c, y, m, d;//用于存储年份、月份和临时计算结果。 
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
    c = y / 100;//计算世纪数。
    y = y % 100;//计算年数。 
    d = 1;
    int w = (y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1) % 7;//计算天数 
    if (w < 0) 
	{
        w += 7;
    }
    return w;
}
// 显示日历
void showCalendar(int year, int month, int day) 
{
    system("cls");  // 清屏
    // 获取当前日期
    SYSTEMTIME curTime;
    GetLocalTime(&curTime);
    // 获取当前年月的第一天是星期几和总天数
    int firstDayOfWeek = getFirstDayOfWeek(year, month);
    int days = getDaysOfMonth(year, month);
    // 打印日历
    printf("      %d年%d月\n", year, month);
    printf("-----------------------------\n");
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    int i;//用于循环计数器。 
    for (i = 0; i < firstDayOfWeek; i++) 
	{
        printf("     ");
    }
    for (i = 1; i <= days; i++) 
	{
        if (i == day && year == curTime.wYear && month == curTime.wMonth) 
		{
            printf("\033[31m");  // 设置红色字体颜色
        }
        printf(" %3d ", i);
        if ((firstDayOfWeek + i) % 7 == 0) 
		{
            printf("\n");
        }
        if (i == day && year == curTime.wYear && month == curTime.wMonth) 
		{
            printf("\033[0m");  // 重置字体颜色
        }
    }
    printf("\n-----------------------------\n");
}
int main() 
{
    int year, month, day;
    // 获取当前日期
    SYSTEMTIME curTime;//存储当前系统时间。
    GetLocalTime(&curTime);//获取当前系统时间。 
    year = curTime.wYear;
    month = curTime.wMonth;
    day = curTime.wDay;//获取当前系统日期。
    while (1) 
	{
        showCalendar(year, month, day);
        // 获取用户输入
        int key = getch();
        if (key == 72) 
		{  // 方向键上
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
		else if (key == 80)// 方向键下 
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
		else if (key == 75)// 方向键左 
		{  
            year--;
        } 
        
		else if (key == 77)  // 方向键右
		{ 
            year++;
        }
		else if (key == 13)// 回车键 
		{  
            printf("请输入年份和月份：");
            scanf("%d %d", &year, &month);
            day = 1;  // 切换年份和月份时，重置日期为1号
        } 
		else if (key == 27) 
		{  // ESC键退出
            break;
        }
        // 边界处理
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
