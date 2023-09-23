#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student 
{
    char student_id[10];
    char name[53];
    char gender[10];
    char birth_date[20];
    char major[50];
    char class_name[50];
    char address[100];
    char dormitory[10];
};
struct activity
{
    char name[53];
    char date[20];
    char content[200];
    char participants[100];
};
#define MAX_STUDENTS 53 // 设置学生数目上限
#define FILE_NAME "students.txt" // 存储学生信息的文件名
#define MAX_ACTIVITIES 100//设置活动数目上限 
#define FILE_CONTENTS "activities.txt" // 存储活动信息的文件名
void addStudent(struct student *s) 
{
    printf("请输入学号：");
    scanf("%s", s->student_id);
    printf("请输入姓名：");
    scanf(" %[^\n]", s->name);
    printf("请输入性别：");
    scanf(" %[^\n]", s->gender);
    printf("请输入出生年月：");
    scanf("%s", s->birth_date);
    printf("请输入专业：");
    scanf(" %[^\n]", s->major);
    printf("请输入班级：");
    scanf(" %[^\n]", s->class_name);
    printf("请输入家庭地址：");
    scanf(" %[^\n]", s->address); 
    printf("请输入宿舍号码：");
    scanf(" %[^\n]", s->dormitory);
}
void addActivity(struct activity *a) 
{
    printf("请输入活动名称：");
    scanf(" %[^\n]", a->name);
    printf("请输入活动日期：");
    scanf("%s", a->date);
    printf("请输入活动内容：");
    scanf(" %[^\n]", a->content);
    printf("请输入参与者：");
    scanf(" %[^\n]", a->participants);
}
void displayStudent(struct student *s) 
{
    printf("学号：%s\n", s->student_id);
    printf("姓名：%s\n", s->name);
    printf("性别：%s\n", s->gender);
    printf("出生年月：%s\n", s->birth_date);
    printf("专业：%s\n", s->major);
    printf("班级：%s\n", s->class_name);
    printf("家庭地址：%s\n", s->address);
    printf("宿舍号码：%s\n", s->dormitory);
}
void displayAllStudents(struct student *students, int count) 
{
    printf("所有学生信息：\n");
    for (int i = 0; i < count; i++) 
	{
        printf("学生 %d：\n", i+1);
        displayStudent(&students[i]);
    }
}
void displayActivity(struct activity *a) 
{
    printf("活动名称：%s\n", a->name);
    printf("活动日期：%s\n", a->date);
    printf("活动内容：%s\n", a->content);
    printf("参与者：%s\n", a->participants);
}
void searchStudent(struct student *students, int count) 
{
    char query[53];
    int found = 0;
    printf("请输入学号或姓名：");
    scanf(" %[^\n]", query);
    printf("匹配的结果如下：\n");
    for (int i = 0; i < count; i++) 
	{
        if (strcmp(students[i].student_id, query) == 0 ||
            strcmp(students[i].name, query) == 0) 
			{
            printf("学生 %d：\n", i+1);
            displayStudent(&students[i]);
            found = 1;
        }
    }
    if (!found) 
	{
        printf("未找到相关记录。\n");
    }
}
void modifyStudent(struct student *students, int count) 
{
    char search_name[10];
    printf("请输入要修改信息的学生的姓名：");
    scanf("%s", search_name);
    int i;
    for (i = 0; i < count; i++) 
	{
        if (strcmp(students[i].name, search_name) == 0) 
		{
            displayStudent(&students[i]);
            printf("请输入修改后的信息：\n");
            addStudent(&students[i]);
            printf("修改成功！\n");
            return;
        }
    }
    printf("未找到相关学生记录。\n");
}
void modifyActivity(struct activity *activities, int count) 
{
    char search_name[50];
    printf("请输入要修改信息的活动名称：");
    scanf(" %[^\n]", search_name);
    int i;
    for (i = 0; i < count; i++) 
	{
        if (strcmp(activities[i].name, search_name) == 0) 
		{
            displayActivity(&activities[i]);
            printf("请输入修改后的信息：\n");
            addActivity(&activities[i]);
            printf("修改成功！\n");
            return;
        }
    }
    printf("未找到相关活动记录。\n");
}
void saveStudents(struct student *students, int count) 
{
    FILE *fp;
    if ((fp = fopen(FILE_NAME, "a")) == NULL) 
	{
        printf("无法打开文件 %s 进行写入。\n", FILE_NAME);
        return;
    }
    fprintf(fp, "%d\n", count);
    for (int i = 0; i < count; i++) 
	{
        fprintf(fp, "%s %s %s %s %s %s %s %s\n", students[i].student_id,
            students[i].name, students[i].gender, students[i].birth_date,
            students[i].major, students[i].class_name, students[i].address,
            students[i].dormitory);
    }
    fclose(fp);
}
int readStudents(struct student *students) 
{
    FILE *fp;
    int count = 0;
    if ((fp = fopen(FILE_NAME, "r")) == NULL) 
	{
        printf("无法打开文件 %s 进行读取。\n", FILE_NAME);
        return count;
    }
    fscanf(fp, "%d", &count);
    for (int i = 0; i < count; i++) 
	{
        fscanf(fp, "%s %s %s %s %s %s %s %s", students[i].student_id,
            students[i].name, students[i].gender, students[i].birth_date,
            students[i].major, students[i].class_name, students[i].address,
            students[i].dormitory);
    }
    fclose(fp);
    return count;
    
}

void saveActivities(struct activity *activities, int count) 
{
    FILE *fp;
    if ((fp = fopen(FILE_CONTENTS, "a")) == NULL) 
	{
        printf("无法打开文件 %s 进行写入。\n", FILE_NAME);
        return;
    }
    fprintf(fp, "%d\n", count);
    for (int i = 0; i < count; i++) 
	{
        fprintf(fp, "%s %s %s %s \n",activities[i].name,
			activities[i].date,activities[i].content,activities[i].participants); 
    }
    fclose(fp);
}
int readActivities(struct activity *activities ) 
{
    FILE *fp;
    int count = 0;
    if ((fp = fopen(FILE_CONTENTS, "r")) == NULL) 
	{
        printf("无法打开文件 %s 进行读取。\n", FILE_NAME);
        return count;
    }
    fscanf(fp, "%d", &count);
    for (int i = 0; i < count; i++) 
	{
        fscanf(fp, "%s %s %s %s ", activities[i].name,
			activities[i].date,activities[i].content,activities[i].participants);
    }
    fclose(fp);
    return count;
    
}
int main() 
{
    struct student students[MAX_STUDENTS];
    struct activity activities[MAX_ACTIVITIES]; 
    int student_count = 0;
    int activity_count = 0;
    int choice;
    student_count = readStudents(students); // 从文件中读取学生信息，更新学生数目
    activity_count=readActivities(activities);// 从文件中读取活动信息，更新活动数目
do {
    printf("\n班级活动管理系统\n");
        printf("1. 输入学生信息\n");
		printf("2. 输入活动信息\n");
		printf("3. 显示学生信息\n");
		printf("4. 显示活动信息\n");
		printf("5. 查找学生信息\n");
		printf("6. 修改学生信息\n");
		printf("7. 修改活动信息\n");
		printf("0. 退出\n");
		printf("请选择：");
		scanf("%d", &choice);
    switch (choice) 
	{
        case 1:
            if (student_count >= MAX_STUDENTS) 
			{
                printf("已达到学生数目上限，无法添加新学生信息。\n");
                break;
            }
            addStudent(&students[student_count]);
            student_count++;
            saveStudents(students, student_count); // 每次输入后，保存学生信息到文件
            printf("学生信息输入成功！\n");
            break;
        case 2:
		if (activity_count >= MAX_ACTIVITIES) 
		{
                printf("已达到活动数目上限，无法添加新活动信息。\n");
                break;
            }
            addActivity(&activities[activity_count]);
            activity_count++;
            saveActivities(activities, activity_count); // 每次输入后，保存活动信息到文件
            printf("活动信息输入成功！\n");
		break;
		case 3:
		for (int i = 0; i < student_count; i++) 
		{
		displayStudent(&students[i]);
		}
		break;
		case 4:
		for (int i = 0; i < activity_count; i++)
		{
		displayActivity(&activities[i]);
		}
		break;
		case 5:
		searchStudent(students, student_count);
		break;
		case 6:
		modifyStudent(students, student_count);
		break;
		case 7:
		modifyActivity(activities, activity_count);
		break;
        case 0:
            printf("感谢使用班级学生管理系统！\n");
            break;
        default:
            printf("无效的选择，请重新输入。\n");
            break;
    }
} while (choice != 0);
	return 0;
}
