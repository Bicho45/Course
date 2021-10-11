#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
int num;
char name[30];
float grade;
struct student *left, *right;
} stud;
typedef struct tree {
stud * root;
} tree;

tree createEmpty() {
tree * t = (tree *)malloc(sizeof(tree));
t->root = NULL;
return * t;
}

stud * createLeaf(int num, char *name, float grade) {
stud *new = (stud *)malloc(sizeof(stud));
new->num = num;
strcpy(new->name, name);
new->grade = grade;
new->left = NULL;
new->right = NULL;
return new;
}
void insertStud(stud * S, int num, char *name, float grade) {
if(S->grade > grade) { if(S->left == NULL)
                                      S->left = createLeaf(num, name, grade);
                              else insertStud(S->left, num, name, grade);
}
else {                          if(S->right == NULL) S->right = createLeaf(num, name, grade);
                               else insertStud(S->right, num, name, grade);
}
}
void insertTree(tree * a, int num, char *name, float grade) {
if (a->root != NULL) insertStud(a->root, num, name, grade);
else                         a->root = createLeaf(num, name, grade);
}

void displayStud(stud * S) {
if(S->right != NULL) displayStud(S->right);
printf("%d\t%s\t%f\n", S->num, S->name, S->grade);
if(S->left != NULL)   displayStud(S->left);
}
void displayTree(tree a) {
if (a.root != NULL) displayStud(a.root);
}

int nbStud(stud * S) {
int nb = 0;
if(S != NULL) {
if (S->grade >= 50) nb++;
nb += nbStud(S->left);
nb += nbStud(S->right);
}
return nb;
}
int nbTree(tree a) {
if (a.root == NULL) return 0;
else return nbStud(a.root);
}

stud * studMax(stud *S) {
if (S == NULL) return NULL;
else { while(S->right != NULL)
                   S = S->right;
return S;
}
}
stud * maxTree(tree a) {
if (a.root == NULL) return NULL;
else return studMax(a.root);
}

void main() {
int n, i, num;
float grade;
char name[30];
tree a = createEmpty();
stud * max;

do {
printf("give nb stud between 3 and 10 : ");
scanf("%d", &n);
} while(n < 3 || n > 10);
printf("\n----- Add %d stud -----\n", n);
for (i = 1; i <= n; i++) {
printf("for stud %d, give \n", i);
printf("\this num : "); scanf("%d", &num);
printf("\this name : "); scanf("%s", name);
printf("\this grade : "); scanf("%f", &grade);
insertTree(&a, num, name, grade);
}

printf("\n----- Stud in Course I2206 -----\n");
displayTree(a);

printf("\nnb of students passed exam is %d\n", nbTree(a));

printf("\n----- Stud having max grade -----\n");
max = maxTree(a);
printf("%d\t%s\t%f\n", max->num, max->name, max->grade);
}
