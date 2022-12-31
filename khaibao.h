#ifndef KHAIBAO_H
#define KHAIBAO_H
#include"graphics.h"
#pragma comment(lib,"graphics.lib")
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <time.h> 
#include <ctime>
using namespace std;
#pragma warning(disable : 4996)
struct product {
	char msp[10];
	char ten[255];
	char pl[4];
	char gia[10];
	char sl[10];
	char can_nang[10];
	char nsx[20];
	char hsd[20];
	char nha_sx[255];
};
struct top_product {
	char date[30];
	char msp[10];
	char ten[255];
	char pl[4];
	char gia[10];
	char sl[10];
	char can_nang[10];
	char nsx[20];
	char hsd[20];
	char nha_sx[255];
};
struct list_bill {
	char mhd[10];
	char date[30];
	vector <product> ds;
};
struct buy_product {
	int sl = 0;
    int index=-1;
	char date[30];
	char mhd[4];
	char ten[255];
	char msp[10];
};
struct staff {
	char mnv[10];
	char ten[255];
	char ntns[11];
	char cccd[13];
	char dia_chi[255];
	char mail[30];
	char sdt[11];
	char t_l_v[2];
};
struct view_page {
	int current=1;
	int page=1;
};
struct check_CURD {
	int l;
	int t;
	int r;
	int b;
	int n; // luu so luong can check // o vi tri so 0
};
const int f_lon = 1; //ma TRIPLEX_FONT settextstyle() trong box chinh kc l? 2
const int f_vua = 10; //ma BOLD_FONT settextstyle() trong box chuc nang kc l? 1
const int f_ds = 3;// kc l? 1
const int HIGHLIGHT_BOX = 10; //green;

void read_file(vector <product>&ds);
void read_file_staff(vector <staff>& ds);
void read_top10(vector <product>& ds);
void read_list_bill(vector <list_bill>& ds);
void write_file(vector <product>& ds);
void write_file_staff(vector <staff>& ds);
void write_file_list_bill(vector <list_bill> list);
void write_file_top10(vector <product>& ds);
bool ktVT(int l, int t, int r, int b, int x, int y,int p=1);
void normal_box(int l, int t, int r, int b, char s[], int font, int f_size, int kc, int kct);
void normal_text(); //set mau mac dinh cua ung dung
void menu_chinh(char box_menu_chinh[][20]); // phan dau cua menu chinh
void table_CURD(char box_header[][20],vector <product> &ds, 
	char CURD_O[][20], 
	view_page &view_page,
	check_CURD detail[],
	check_CURD edit[],
	check_CURD _delete[]
);
void UI_add_p(char name_comp[][20]);
//void UI_add_more_p(char name_comp[][20], view_page& view_page, product p = {});
void UI_edit_p(char name_comp[][20], product p);
void show_detail_product(char name_comp[][20],product p);
void staff_table(
	char product_header[][20],
	vector <staff>& ds,
	char CURD_O[][20],
	view_page& view_page,
	check_CURD detail[],
	check_CURD edit[],
	check_CURD _delete[]
);
void show_deatil_staff(char name_comp[][20], staff p);
void UI_add_staff(char name_comp[][20]);
bool check_push_staff(vector <staff> s, staff temp, int index=-1);
void UI_edit_staff(char name_comp[][20], staff s);
void buy_table(
	char product_header[][20],
	vector <product>& ds,
	char CURD_O[][20],
	view_page& view_page,
	check_CURD detail[],
	vector <buy_product> &buy_p,
	check_CURD left_arrow[],
	check_CURD right_arrow[]
);
void UI_card(char product_header[][20], vector <buy_product> num_buy, vector <product> ds, view_page& view_page);
void bill(int &code_bill, view_page& view_page, vector <buy_product>& num_buy, vector <product> ds);
void UI_top10(vector <product> sold, check_CURD d_top10[]);
void UI_list_bill(vector <list_bill> lb, check_CURD detail[], view_page& view_page);
void UI_detail_list(char product_header[][20], vector <product> ds, view_page& view_page, check_CURD detail[]);
int check_name(buy_product name_buy, vector <product> sold);
int check_empty_buy(vector <buy_product> buy);
void navigation_page(view_page& view_page);
bool kt_KTu(char x);
bool decimal_number(char x);
string input(int l, int t, int r, int b, int kcl=0,
			int kct=0,  string value="",
			int max_value=255, int o_num = 0);



void push_product(vector <product>& ds, product temp);
void split(char x, string v, vector <string>& arr);
string format_num(string s);
string to_upper(string s, bool all = true);
string trim(string s);
string getDate();
bool check_day_month(int l, int t, int r, int b, int kcl, int kct, string day, string month="", string year="", int small_y=0);
int check_duplicate(vector <product>& ds, product p);
void noti_input(int l, int t, int r, int b, int kcl, int kct,string out="");
void highlight_box(int l, int t, int r, int b, char s[], int font = f_ds, int f_size = 1, 
int kcl = 0, int kct =0, int bg= HIGHLIGHT_BOX);
void delete_after_main();
void setbkscreen();
#endif 