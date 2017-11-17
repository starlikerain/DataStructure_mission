//
//  main.c
//  courseDesign
//
//  Created by StarLikeRain on 17/11/2017.
//  Copyright © 2017 EvanYann. All rights reserved.
//
/**
 * @author [StarLikeRain]
 * @email [pengyaokang@gmail.com]
 * @create date 15/11/2017
 * @modify date 15/11/2017
 * @desc [学校数据结构任务书]
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FINITY 5000                                   /*表示无穷大*/
#define M 20
typedef int datatype;
typedef char vertextype;
typedef int edgetype;

typedef struct {
    vertextype vexs[M];
    edgetype edges[M][M];
    int n, e;                                           /*顶点数 && 边数*/
} Mgraph;

typedef struct link_node {
    int index;
    char alias;
    char describe[100];
    struct link_node *next;
} school_single_spot;
struct link_node *head;

void init_school_sequence_head() {
    head = (school_single_spot *) malloc(sizeof(head));
    head->next = NULL;
}

struct school_single_spot *find(int pos) { // 根据输入位置，返回节点的值
    int j = 0;
    school_single_spot *p = head;
    if (pos < 0) {
        puts("find 输入非法");
        exit(1);
    }
    for (p = head; p != NULL; p = p->next) {
        if (j == pos) {
            break;
        } else {
            j++;
        }
    }
    return p;
}

/*
 * 初始化学校每个地点 插入头节点单链表
 */
void school_single_spot_insert(int index, char alias, char profile[100], int pos1) {
    school_single_spot *p, *q; //p用于存放要插入的结点，q指向要插入的位置
    q = find(pos1); // i=0; 第一个是头结点
    if (q == NULL) {
        printf("\n找不到%d位置的节点", pos1);
    } else {
        p = (school_single_spot *) malloc(sizeof(school_single_spot));    //分配空间暂定变量为p
        // 活动 节点赋值
        p->index = index;
        p->alias = alias;
        strcpy(p->describe, profile);
        // end
        p->next = q->next;            //执行next变量的迁移
        q->next = p;                //执行next变量的迁移
    }
}

void search_Spot() {
    school_single_spot *p = head;
    // i用于防止死循环
    char mark,i=0;
    puts("输入景点的单字符");
    scanf("%c", &mark);
    getchar();
    while (p->alias != mark && i<7) {
        p = p->next;
    }
    printf("对应的%c景点的信息是: %s \n", mark, p->describe);
}

/*
 * Mgraph *g    自定义图的结构类型
 * char *s      读取文件的路径
 * read file and create sequence & graph
 */
void create(Mgraph *g, char *s) {
    int i, j, k, w;
    // 下面声明的变量用于 school_single_spot
    int index;
    char alias;
    char profile[100];
    // end
    FILE *rf = NULL;
    rf = fopen(s, "r");
    if (rf) {
        fscanf(rf, "%d %d", &g->n, &g->e); // 读图 「定点」和 「边」 信息
        for (i = 0; i < g->n; i++) {
            fscanf(rf, "%d %c %s", &index, &alias, &profile, i); // i用于插入的pos
            school_single_spot_insert(index, alias, profile, i);
        }
        
    } else {
        g->n = 0;
        printf("create 文件读取失败呀");
    }
    fclose(rf);
}

void school_spot_display() {
    school_single_spot *p;
    p = head->next; // 指向第一个有意义的节点
    if (p == NULL) {
        printf("school_spot_display() execute ERROR!!!");
    } else {
        while (p) {
            printf("第 %d 个景点,标记为 %2c 描述为: %s\n", p->index, p->alias, p->describe);
            p = p->next;
        }
        //        for(p=head->next;p!=NULL;p=p->next){
        //            printf("%5c", p->info);
        //        }
        puts("显示完毕\n");
    }
}

/*
 * 用户 GUI 选择界面
 */
int menu() {
    int inputNum = 0;
    printf("******* GUI 选择界面 *******\n");
    printf("        A \n");
    printf("        | \n");
    printf("        B —— E —— F\n");
    printf("        |    |\n");
    printf("        C —— D\n");
    puts("1、显示所有节点信息\n");
    puts("2、查询各个景点的相关信息\n");
    puts("3、查询任意两个景点的最短路径\n");
    puts("4、查询两个景点的所有路径\n");
    puts("0、退出程序\n");
    
    scanf("%d", &inputNum);
    getchar();
    return inputNum;
}

void main() {
    Mgraph *my_graph;
    char file_Path[] = "/Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission/School_map.txt";
    init_school_sequence_head();
    create(&my_graph, file_Path);
    
    int switchCase = 1;
    int CustomerOperator;
    while (switchCase) {
        CustomerOperator = menu();
        switch (CustomerOperator) {
            case 1:
                school_spot_display();
                break;
            case 2:
                search_Spot();
                break;
            case 0:
                puts("退出程序ing");
                sleep(2);
                puts("已退出!");
                exit(1);
            default:
                printf("你为何要输入一个奇怪得数字！\n");
                break;
        }
    }
}





