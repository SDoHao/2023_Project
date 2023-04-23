#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include"poscar.h"
#include"file.h"
#include"ReadConfig.h"
#define MaxElement 99
#define M_PI 3.14159265358979323846
#define AtomBondLength  1

struct CSVHolder
{
	int num;
	char row[MaxElement][6];
};
typedef struct CSVHolder CSVHolder;

void OutputElementScriptCreat(FILE *fp,config *prule, char elem[],double x,double y,double z)
{
	//printf("    Creat %s\n", elem);
	fprintf(fp,"%s = sphere()\n", elem);
	//printf("%s.name = %s\n");
	fprintf(fp, "%s.wirecolor = [%d,%d,%d]\n", 
		elem, 
		atoi(GetValue(prule, "red")),
		atoi(GetValue(prule, "green")), 
		atoi(GetValue(prule, "blue"))
		);
	fprintf(fp, "%s.pos = [%f,%f,%f]\n", elem, x, y, z);
	//fprintf(fp, "%s.radius = %f\n", elem, atof(GetValue(prule, "radius")));
	fprintf(fp, "%s.radius = %f\n", elem, atof(GetValue(prule, "radius")) / 2);
}

int FindElementRule(config rule[], int max, char * elem)
{
	//config *p_erule;
	int i,i_l;
	char * value = NULL;
	char szvalue[3];
	i_l = 2;
	if (max >= 10)
		i_l = 3;
	else
		i_l = 2;
	for (i = 1; i < max; i++)
	{
		_itoa_s(i, szvalue, i_l, 10);
		value = GetValue(&rule[0], szvalue);
		//printf("szvalue %s value %s\n", szvalue, value);
		if (strcmp(value, elem) == 0)
		{
			//printf("elem %s %d\n", elem, i);
			//[Rule]中找到1为起始 保存的数组 0 记录所有元素，元素H从1开始
			return i;
		}
	}
	return 0;
}

void AtomBondScriptCreat(FILE *fp, POSCAR poscar, config rule[], CSVHolder * csv)
{
	int i, j, k;
	int eindex1, eindex2;
	config *prule1, *prile2;
	char * pelem1, *pelem2;
	double *ppos1, *ppos2, Angle_X, Angle_Y, Vector[3], Diameter;
	double acosX,acosY;
	i = j = 0;
	for (; i < poscar.total_num; i++)
	{
		pelem1 = GetAtomType(poscar, i);
		eindex1 = FindElementRule(rule, MaxElement, pelem1);
		if (eindex1)
		{
			ppos1 = &poscar.position[i];
			for (j = i + 1; j < poscar.total_num; j++)
			{
				//if (i == j)continue;
				pelem2 = GetAtomType(poscar, j);
				eindex2 = FindElementRule(rule, MaxElement, pelem2);
				if (eindex2)
				{
					ppos2 = &poscar.position[j];
					for (k = 0; k < 3; k++)
						Vector[k] = *(ppos2 + k) - *(ppos1 + k);
					Diameter = sqrt(Vector[0] * Vector[0] + Vector[1] * Vector[1] + Vector[2] * Vector[2]);
					//printf("%d %d %f %s\n", eindex1, eindex2, Diameter, (csv + eindex1)->row[eindex2]);
					if (Diameter <= atof((csv + eindex1)->row[eindex2]))
					{
						//fprintf(fp, "向量为 %f %f %f \n", Vector[0], Vector[1], Vector[2]);
						//两向量夹角
						if (Vector[2] != 0 && Vector[1] != 0)
							acosX = Vector[2] / sqrt(Vector[2] * Vector[2] + Vector[1] * Vector[1]);
						else
							acosX = 0;
						acosY = sqrt(Vector[2] * Vector[2] + Vector[1] * Vector[1]) / Diameter;
						//fprintf(fp,"X %f Y %f\n", acosX, acosY);
						//弧度制转为角度制
						Angle_X = acos(acosX) / M_PI * 90 * 2;
						if (Vector[1] < 0)
							Angle_X = 360 - Angle_X;
						//printf("X旋转的角度为[%f][%f]\n", acosX,Angle_X);
						Angle_Y = acos(acosY) / M_PI * 90 * 2;
						if (Vector[0] < 0)
							Angle_Y = 360 - Angle_Y;
						//printf("y旋转的角度为[%f][%f]\n", acosY,Angle_Y);
						fprintf(fp, "%s_%s_bond = Cylinder()\n", pelem1, pelem2);
						fprintf(fp, "%s_%s_bond.radius = 0.1\n", pelem1, pelem2);
						fprintf(fp, "%s_%s_bond.height = %f\n", pelem1, pelem2, Diameter / 2);
						fprintf(fp, "%s_%s_bond.pos = [0, 0, 0]\n", pelem1, pelem2);
						fprintf(fp, "%s_%s_bond.rotation = (eulerangles %f %f 0)\n", pelem1, pelem2, Angle_X, -Angle_Y);
						fprintf(fp, "%s_%s_bond.wirecolor = [%d,%d,%d]\n", pelem1, pelem2, atoi(GetValue(&rule[eindex1], "red")), atoi(GetValue(&rule[eindex1], "green")), atoi(GetValue(&rule[eindex1], "blue")));
						fprintf(fp, "%s_%s_bond.pos = %s_%s_bond.pos + [%f , %f , %f]\n", pelem1, pelem2, pelem1, pelem2, *(ppos1), *(ppos1 + 1), *(ppos1 + 2));
						fprintf(fp, "%s_%s_bond = Cylinder()\n", pelem1, pelem2);
						fprintf(fp, "%s_%s_bond.radius = 0.1\n", pelem1, pelem2);
						fprintf(fp, "%s_%s_bond.height = %f\n", pelem1, pelem2, Diameter / 2);
						fprintf(fp, "%s_%s_bond.pos = [0, 0, 0]\n", pelem1, pelem2);
						fprintf(fp, "%s_%s_bond.rotation = (eulerangles %f %f 0)\n", pelem1, pelem2, Angle_X, -Angle_Y);
						fprintf(fp, "%s_%s_bond.wirecolor = [%d,%d,%d]\n", pelem1, pelem2, atoi(GetValue(&rule[eindex2], "red")), atoi(GetValue(&rule[eindex2], "green")), atoi(GetValue(&rule[eindex2], "blue")));
						fprintf(fp, "%s_%s_bond.pos = %s_%s_bond.pos + [%f , %f , %f]\n", pelem1, pelem2, pelem1, pelem2, *(ppos1) + (*(ppos2)-*(ppos1))/2, *(ppos1 + 1)+(*(ppos2 + 1)-*(ppos1 +1)) / 2, *(ppos1 + 2) + (*(ppos2 + 2) - *(ppos1 + 2)) / 2);
					}
					
				}
			}
		}
	}
}

void Output(POSCAR poscar, config rule[], CSVHolder * csv)
{
	int i,eindex;
	char *peletype;
	FILE *fp = NULL;
	fopen_s(&fp,"MaxScript.txt", "w+");
	for (i = 0; i < poscar.total_num; i++)
	{
		peletype = GetAtomType(poscar, i);

		//printf("%s\n", peletype);
		eindex = FindElementRule(rule, MaxElement, peletype);
		//printf("elem %s %d\n", peletype, eindex);
		if(eindex)
			OutputElementScriptCreat(fp,&rule[eindex], peletype, poscar.position[i][0], poscar.position[i][1], poscar.position[i][2]);
		else
			printf("%d %s Not Found.\n", i,peletype);
	}
	printf("\nElement Script Creat Succeeded.\n");
	AtomBondScriptCreat(fp, poscar, rule, csv);
	printf("\nAtom Bond Script Creat Succeeded.\n");
	fclose(fp);
}


int ReadCSVFile(CSVHolder * csv, char * path)
{
	//读取的一行
	char p_read_line[MaxElement];
	//每次分割的值
	char * p_sztoken;
	char * p_char;
	FILE *fp = fopen(path, "r");
	int num;
	int i;
	int line = 0;
	while (fgets(p_read_line, MaxElement, fp) != NULL)
	{
		line++;
		num = 0;
		p_sztoken = strtok(p_read_line, ",");
		while (p_sztoken != NULL) {
			//printf("Token: %s\n", p_sztoken);
			p_char = p_sztoken;
			i = 0;
			while (*p_char != '\0')
			{
				//printf("p_char: %c", *p_char);
				
				csv->row[num][i] = *p_char;
				i++;
				p_char++;
			}
			//printf("\n");
			csv->row[num][i] = '\0';
			p_sztoken = strtok(NULL, ",");
			num++;
		}
		csv->num = num;
		csv++;
	}
	fclose(fp);
	return line;
}

int main()
{
	CSVHolder _CSVHolder[MaxElement];
	int max_line,i, j,max_list;

	max_line = ReadCSVFile(_CSVHolder, "BondLength.csv");
	for (i = 0; i < max_line; i++)
	{
		for (j = 0; j < _CSVHolder[i].num; j++)
			printf("%4s ", _CSVHolder[i].row[j]);
		printf("\n");
	}

	config RuleList[MaxElement];
	
	ReadConfig("Rule.ini", RuleList); 
	max_list = CountConfig(RuleList);

	if(max_line < max_list)
		printf("Not enough scv file data.\n");

	//PrintConfig(RuleList);
	POSCAR poscar_file =  load_file(1,"POSCAR.txt");
	PtintElemArray(poscar_file,5);
	Output(poscar_file, RuleList, _CSVHolder);
	
	//print_file(poscar_file);
	
	return 0;
}

