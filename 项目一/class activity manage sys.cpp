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
#define MAX_STUDENTS 53 // ����ѧ����Ŀ����
#define FILE_NAME "students.txt" // �洢ѧ����Ϣ���ļ���
#define MAX_ACTIVITIES 100//���û��Ŀ���� 
#define FILE_CONTENTS "activities.txt" // �洢���Ϣ���ļ���
void addStudent(struct student *s) 
{
    printf("������ѧ�ţ�");
    scanf("%s", s->student_id);
    printf("������������");
    scanf(" %[^\n]", s->name);
    printf("�������Ա�");
    scanf(" %[^\n]", s->gender);
    printf("������������£�");
    scanf("%s", s->birth_date);
    printf("������רҵ��");
    scanf(" %[^\n]", s->major);
    printf("������༶��");
    scanf(" %[^\n]", s->class_name);
    printf("�������ͥ��ַ��");
    scanf(" %[^\n]", s->address); 
    printf("������������룺");
    scanf(" %[^\n]", s->dormitory);
}
void addActivity(struct activity *a) 
{
    printf("���������ƣ�");
    scanf(" %[^\n]", a->name);
    printf("���������ڣ�");
    scanf("%s", a->date);
    printf("���������ݣ�");
    scanf(" %[^\n]", a->content);
    printf("����������ߣ�");
    scanf(" %[^\n]", a->participants);
}
void displayStudent(struct student *s) 
{
    printf("ѧ�ţ�%s\n", s->student_id);
    printf("������%s\n", s->name);
    printf("�Ա�%s\n", s->gender);
    printf("�������£�%s\n", s->birth_date);
    printf("רҵ��%s\n", s->major);
    printf("�༶��%s\n", s->class_name);
    printf("��ͥ��ַ��%s\n", s->address);
    printf("������룺%s\n", s->dormitory);
}
void displayAllStudents(struct student *students, int count) 
{
    printf("����ѧ����Ϣ��\n");
    for (int i = 0; i < count; i++) 
	{
        printf("ѧ�� %d��\n", i+1);
        displayStudent(&students[i]);
    }
}
void displayActivity(struct activity *a) 
{
    printf("����ƣ�%s\n", a->name);
    printf("����ڣ�%s\n", a->date);
    printf("����ݣ�%s\n", a->content);
    printf("�����ߣ�%s\n", a->participants);
}
void searchStudent(struct student *students, int count) 
{
    char query[53];
    int found = 0;
    printf("������ѧ�Ż�������");
    scanf(" %[^\n]", query);
    printf("ƥ��Ľ�����£�\n");
    for (int i = 0; i < count; i++) 
	{
        if (strcmp(students[i].student_id, query) == 0 ||
            strcmp(students[i].name, query) == 0) 
			{
            printf("ѧ�� %d��\n", i+1);
            displayStudent(&students[i]);
            found = 1;
        }
    }
    if (!found) 
	{
        printf("δ�ҵ���ؼ�¼��\n");
    }
}
void modifyStudent(struct student *students, int count) 
{
    char search_name[10];
    printf("������Ҫ�޸���Ϣ��ѧ����������");
    scanf("%s", search_name);
    int i;
    for (i = 0; i < count; i++) 
	{
        if (strcmp(students[i].name, search_name) == 0) 
		{
            displayStudent(&students[i]);
            printf("�������޸ĺ����Ϣ��\n");
            addStudent(&students[i]);
            printf("�޸ĳɹ���\n");
            return;
        }
    }
    printf("δ�ҵ����ѧ����¼��\n");
}
void modifyActivity(struct activity *activities, int count) 
{
    char search_name[50];
    printf("������Ҫ�޸���Ϣ�Ļ���ƣ�");
    scanf(" %[^\n]", search_name);
    int i;
    for (i = 0; i < count; i++) 
	{
        if (strcmp(activities[i].name, search_name) == 0) 
		{
            displayActivity(&activities[i]);
            printf("�������޸ĺ����Ϣ��\n");
            addActivity(&activities[i]);
            printf("�޸ĳɹ���\n");
            return;
        }
    }
    printf("δ�ҵ���ػ��¼��\n");
}
void saveStudents(struct student *students, int count) 
{
    FILE *fp;
    if ((fp = fopen(FILE_NAME, "a")) == NULL) 
	{
        printf("�޷����ļ� %s ����д�롣\n", FILE_NAME);
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
        printf("�޷����ļ� %s ���ж�ȡ��\n", FILE_NAME);
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
        printf("�޷����ļ� %s ����д�롣\n", FILE_NAME);
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
        printf("�޷����ļ� %s ���ж�ȡ��\n", FILE_NAME);
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
    student_count = readStudents(students); // ���ļ��ж�ȡѧ����Ϣ������ѧ����Ŀ
    activity_count=readActivities(activities);// ���ļ��ж�ȡ���Ϣ�����»��Ŀ
do {
    printf("\n�༶�����ϵͳ\n");
        printf("1. ����ѧ����Ϣ\n");
		printf("2. ������Ϣ\n");
		printf("3. ��ʾѧ����Ϣ\n");
		printf("4. ��ʾ���Ϣ\n");
		printf("5. ����ѧ����Ϣ\n");
		printf("6. �޸�ѧ����Ϣ\n");
		printf("7. �޸Ļ��Ϣ\n");
		printf("0. �˳�\n");
		printf("��ѡ��");
		scanf("%d", &choice);
    switch (choice) 
	{
        case 1:
            if (student_count >= MAX_STUDENTS) 
			{
                printf("�Ѵﵽѧ����Ŀ���ޣ��޷������ѧ����Ϣ��\n");
                break;
            }
            addStudent(&students[student_count]);
            student_count++;
            saveStudents(students, student_count); // ÿ������󣬱���ѧ����Ϣ���ļ�
            printf("ѧ����Ϣ����ɹ���\n");
            break;
        case 2:
		if (activity_count >= MAX_ACTIVITIES) 
		{
                printf("�Ѵﵽ���Ŀ���ޣ��޷�����»��Ϣ��\n");
                break;
            }
            addActivity(&activities[activity_count]);
            activity_count++;
            saveActivities(activities, activity_count); // ÿ������󣬱�����Ϣ���ļ�
            printf("���Ϣ����ɹ���\n");
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
            printf("��лʹ�ð༶ѧ������ϵͳ��\n");
            break;
        default:
            printf("��Ч��ѡ�����������롣\n");
            break;
    }
} while (choice != 0);
	return 0;
}
