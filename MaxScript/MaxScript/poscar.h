#ifndef POSCAR_H
#define POSCAR_H

struct POSCAR
{
	char name[255];
	float scale;
	double lattice[3][3];//晶格参数
	char element[118][3];//元素类别 sz
	int atom_num[118];//元素数量
	double position[500][3];//元素位置
	int isFixed[500][3];
	int elem_num;
	int total_num;
	int is_selective;
	char pos_type[10];
	int suc;
};
typedef struct POSCAR POSCAR;


//char TableofElements[118][3];
//POSCAR poscar = load_file();
//POSCAR * p_poscar = &poscar;
//print_file(poscar);
//fix_file(p_poscar);
//fix_by_height(p_poscar, 0.01, 0.02);
//print_file(poscar);

//load_PTE_file(TableofElements);
/*printf("\nThis is a Periodic Table of Elements:\n");
for (i = 0; i < 118; )
{
printf("%d %s  ", i + 1, TableofElements[i]);
if ((++i) % 5 == 0)
printf("\n");
}*/

#endif