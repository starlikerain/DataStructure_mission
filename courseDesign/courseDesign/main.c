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

#define MAX         100                                 // 矩阵最大容量
#define INF (~(0x1<<31))                                  /*表示走不通*/
#define M 10
typedef int datatype;
typedef char vertextype;
typedef int edgetype;

// 定一个 flag 队列
typedef struct javaScriptObj{
    char vex[M];
} js_Obj;

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
    char each_ABCDEF;
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
        fseek(rf, 1L, SEEK_CUR);
        // 做一些 graph 的 vex[M] 字母赋值
        for(i=0; i< g->n; i++){
            fscanf(rf, "%c", &each_ABCDEF);
            g->vexs[i] = each_ABCDEF;
            fseek(rf, 1L, SEEK_CUR);
        }
       // fseek(rf, 1L, SEEK_CUR);
        for (i = 0; i < g->n; i++) {
            fscanf(rf, "%d %c %s", &index, &alias, &profile, i); // i用于插入的pos
            school_single_spot_insert(index, alias, profile, i);
        }
        for(i=0;i<g->n;i++){  // 初始化邻接矩阵
            for(j=0;j<g->n;j++){
                if(j == i){
                    g->edges[i][j] = 0;
                }else{
                    g->edges[i][j] = INF;
                }
            }
        }
        for(k=0;k<g->e;k++){ // 读取网格的边信息
            fscanf(rf, "%d %d %d", &i, &j, &w); // 0 1 1
            g->edges[i][j] = w;
            g->edges[j][i] = w; // 因为是无向图，所以双向赋值
        }
    } else {
        g->n = 0;
        printf("create 文件读取失败呀");
    }
    
    /*
     * 看一下矩阵
     */
    int xx,yy;
    printf("________________________________________________________________________________________\n");
    printf("       /*A*/          /*B*/          /*C*/          /*D*/          /*E*/          /*F*/ \n");
    for(xx=0;xx<6;xx++){
        printf("/*%c*/  ", g->vexs[xx]);
        for(yy=0;yy<6;yy++){
            printf("%-15d", g->edges[xx][yy]);
        }
        printf("\n");
    }
    printf("________________________________________________________________________________________\n");
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

void dijkstra(Mgraph *G, int vs, int p, int prev[], int dist[]){
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    js_Obj* js_obj;
    //    Graph* pG;
    int useless=0;
    int i,j,k;
    int min;
    int tmp;
    int flag[MAX];      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。
    js_obj = (js_Obj*)malloc(sizeof(js_Obj));
    memset(js_obj, 0, sizeof(js_Obj));
    
    
    // 初始化
    for (i = 0; i < G->n; i++)
    {
        flag[i] = 0;              // 顶点i的最短路径还没获取到。
        prev[i] = 0;              // 顶点i的前驱顶点为0。
        dist[i] = G->edges[vs][i];// 顶点i的最短路径为"顶点vs"到"顶点i"的权。
    }
    
    
    
    // 对"顶点vs"自身进行初始化
    flag[vs] = 1;

    js_obj->vex[useless] = vexs[vs];
    useless++;
    dist[vs] = 0;
    
    // 遍历G.vexnum-1次；每次找出一个顶点的最短路径。
    for (i = 1; i < G->n; i++) // 1~5
    {
        printf("这里:%d \n", dist[1]);
//        printf(">>>>%d\n", i);
        // 寻找当前最小的路径；
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
        min = INF;
        for (j = 0; j < G->n; j++)
        {
            if (flag[j]==0 && dist[j]<min) // 没有走过的点，树状的 dist
            {
                min = dist[j];
                k = j;
            }
        }
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;
//        if(){
//
//        }
//        js_obj->vex[useless] = vexs[k];
//        useless++;
        
        
        
        
        
        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (j = 0; j < G->n; j++)
        {
            tmp = (G->edges[k][j]==INF ? INF : (min + G->edges[k][j])); // 防止溢出
//            if(tmp  < dist[j] && j == p){
//                js_obj->vex[useless] = vexs[k];
//                useless++;
//            }
            if (flag[j] == 0 && (tmp  < dist[j]) )
            {
                if(j == p){
                    js_obj->vex[useless] = vexs[k];
                    useless++;
                }
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }
    
    
//    int fuck = 5;
//    while (fuck > 0) {
//        if(fuck <= p && fuck >= j){
//            printf("最终！ : %c \n", js_obj->vex[fuck]);
//        }
//        fuck--;
//    }
    // 打印dijkstra最短路径的结果
    printf("dijkstra(%c): \n", G->vexs[vs]);
    printf("%c 到 %c 的最短路径是", vexs[vs], vexs[p]);
    for(i=0; i<useless; i++){
        printf("%c", js_obj->vex[i]);
    }
    printf("%c", vexs[p]);
    
    for (i = 0; i < G->n; i++){
        if(i == p){
            printf("  shortest(%c, %c)=%d\n", G->vexs[vs], G->vexs[i], dist[i]);
        }
    }
    
}



int recursion_flag[M];
void abord_recursion(){
    int i;
    for(i=0; i<6; i++){ // 直接赋值了
        recursion_flag[i] = 0;
    }
}


int get_all_path(Mgraph *my_graph, int x, int y, char *str){ // 无责任获取两点之间所有路径
    char str2[100];
    int sLen;
    
    strcpy(str2, str);
    sLen = strlen(str);
    str2[sLen] = my_graph->vexs[x];
    str2[sLen + 1] = '\0';
    
    int i;
    if(x == y){ // find targe
        printf("final -> %s \n", str2);
        return 0;
    }
    
    recursion_flag[x] = 1;
    
    for(i=0; i<6; i++){
        if(my_graph->edges[x][i] > 0 && my_graph->edges[x][i] < INF && recursion_flag[i] != 1){
            get_all_path(my_graph, i, y, str2);
        }
    }
   
    return 0;
}


/*
 * 用户 GUI 选择界面
 */
int menu() {
    int inputNum = 10;
    printf("******* GUI 选择界面 *******\n");
    printf("        A \n");
    printf("       1|  5   6 \n");
    printf("        B —— E —— F\n");
    printf("       3|    |4\n");
    printf("        C —— D\n");
    printf("          2\n");
    puts("1、显示所有节点信息\n");
    puts("2、查询各个景点的相关信息\n");
    puts("3、查询任意两个景点的最短路径\n");
    puts("4、查询两个景点的所有路径\n");
    puts("0、退出程序\n");
    
    scanf("%d", &inputNum);
    getchar();
    return inputNum;
}


int main() {
    Mgraph my_graph;
    int prev[MAX] = {0}; // 还没想好等下 吧
    int dist[MAX] = {0}; // 用于 dijkstra 输出存储
    char file_Path[] = "/Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission/School_map.txt";
    init_school_sequence_head();
    create(&my_graph, file_Path);
    
    int switchCase = 1, i, p;
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
            case 3:
                puts("输入你想查询的两个点的 index （ 用空格隔开 ）");
                scanf("%d %d", &i,&p);
                getchar();
                dijkstra(&my_graph, i, p, prev, dist);
                break;
            case 4:
                abord_recursion();
                puts("输入你想查询 所有路径的两个点的 index （ 用空格隔开 ）");
                scanf("%d %d", &i,&p);
                getchar();
                get_all_path(&my_graph,i,p, "");
                break;
            case 0:
                puts("退出程序ing");
                sleep(1);
                puts("已退出!");
                exit(1);
            default:
                printf("你为何要输入一个奇怪得数字！\n");
                break;
        }
    }
    return 0;
}





