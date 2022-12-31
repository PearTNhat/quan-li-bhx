#include "khaibao.h"
char box_menu_chinh[3][20] = { "Quan ly hang","Quan ly nhan vien","Mua hang" };
char product_header_table[10][20] = {
		"MSP",
		"Ten",
		"Gia",
		"Can nang",
		"Han su dung",
		"Chuc nang",
		"Phan Loai",
		"Ngay san xuat",
		"Nha san xuat",
		"So luong",
};
char staff_header_table[9][20] = {
		"MNV",
		"Ten",
		"Mail",
		"SDT",
		"Thoi gian lam viec",
		"Chuc nang",
		"Dia chi",
		"Ngay sinh",
		"CCCD",
};
char CURD_O[3][20] = {
			"Chinh sua",
			"Xoa",
			"Chi tiet"
};
int index_bill_p;
int code_bill = 0;
 //product
 vector <product> ds ;
 product temp;
 view_page page_p;
 view_page page_add_more_p;
 check_CURD detail[9];
 check_CURD edit[9];
 check_CURD _delete[9];
 // staff
 vector <staff> list_s;
 staff temp_s;
 view_page page_s;
 check_CURD detail_s[9];
 check_CURD edit_s[9];
 check_CURD _delete_s[9];

 bool	quan_li_sp = false,
		home_p = false,
		p_detail_product=false,
		p_add_product=false,
		p_edit_product=false;
int	 i_edit = 0,i_edit_s=0;
bool	staff_page = false,
		home_staff = false,
		p_detail_staff = false,
		p_add_staff=false,
		p_edit_staff=false;
//buy
view_page page_b;
view_page page_card;
view_page page_bill;
view_page page_list_bill;
view_page page_p_in_list;
check_CURD detail_b[9];
check_CURD left_arrow[9];
check_CURD right_arrow[9];
check_CURD detail_top10[10];
check_CURD detail_list_bill[10];
check_CURD detail_p_in_list[10];
vector <buy_product> adjust_lr;
vector <product> product_sold;
vector <list_bill> l_bills;
bool buy_page = false,
	home_buy = false,
	in_card_page = false,
	in_bill_page = false,
	top_10_page=false,
	in_detail_top10=false,
	in_list_bill = false,
	in_show_detail_p_bill=false,
	in_page_list_p=false;
int main() {	
	read_file(ds);
	read_file_staff(list_s);
	read_top10(product_sold);
	read_list_bill(l_bills);
	vector<string> dateTemp;
	vector<string> check_day;
	split('/',getDate(), dateTemp);
	split(' ', dateTemp[0], check_day);
	if (l_bills.size()>0) {
		vector<string> day_bill;
		split('/', l_bills[0].date, day_bill);
		split(' ', day_bill[0], day_bill);
		if (check_day[1]!= day_bill[4]) {
			l_bills.clear();
		}
	}
	if(l_bills.size()>0){
		code_bill =atoi( l_bills[l_bills.size() - 1].mhd)+1;
	}
	cout << l_bills.size();
	initwindow(1000, 600);
	setbkcolor(8);
	cleardevice();
	menu_chinh(box_menu_chinh);
	for (int i = 0; i <ds.size(); i++)
	{
		buy_product x;
		strcpy_s(x.ten, ds[i].ten);
		strcpy_s(x.msp, ds[i].msp);
		adjust_lr.push_back(x);
	}
	int x, y;
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			line(x, y, x + 20, y);
			cout << "\nvi tri x:" << x << " - vi tri y:" << y << endl;
			//quan li sp product// trang quan li hang hoa
			if (ktVT(60, 62, 245, 94, x, y)) {
				setbkscreen();
				page_p.current = 1;
				menu_chinh(box_menu_chinh);
				table_CURD(product_header_table, ds, CURD_O, page_p, detail, edit, _delete);
				highlight_box(60, 62, 245, 94, box_menu_chinh[0], f_lon, 1, 5, 8);
				home_p = true;
				quan_li_sp = true;
				staff_page = false;
				home_staff = false;
				buy_page = false;
				home_buy = false;
			}
			//staff page
			if (ktVT(363, 63, 598, 94, x, y)) {
				setbkscreen();
				page_s.current = 1;
				menu_chinh(box_menu_chinh);
				staff_table(staff_header_table, list_s, CURD_O, page_s, detail_s, edit_s, _delete_s);
				highlight_box(363, 63, 598, 94, box_menu_chinh[1], f_lon, 1, 5, 8);
				home_staff = true;
				staff_page = true;
				quan_li_sp = false;
				home_p = false;
				buy_page = false;
				home_buy = false;
			}
			//buy page
			if (ktVT(716, 63, 850, 94, x, y)) {
				setbkscreen();
				page_b.current = 1;
				menu_chinh(box_menu_chinh);
				buy_table(product_header_table, ds, CURD_O, page_b, detail_b, adjust_lr, left_arrow,right_arrow);
				highlight_box(716, 63, 850, 94, box_menu_chinh[2], f_lon, 1, 5, 8);
				quan_li_sp = false;
				home_p = false;
				staff_page = false;
				home_staff = false;
				buy_page = true;
				home_buy = true;
			}
			if (quan_li_sp) {
				if (home_p) {
					//chuyen so trang product
					// <
					if (ktVT(450, 555, 465, 578, x, y)) {
						if (!p_detail_product) {
							if (page_p.current <= 1) {
								cout << "no <" << endl;
							}
							else {
								cout << "<" << endl;
								page_p.current -= 1;
								char z[] = { "<" };
								highlight_box(445, 553, 470, 578, z, f_vua, 3, 5, 1);
								delay(200);
								delete_after_main();
								table_CURD(product_header_table, ds, CURD_O, page_p, detail, edit, _delete);
							}

						}
					}

					// >	cong them 10 o bottm vi text co bk
					//		tru 10 o top
					if (ktVT(500, 545, 517, 587, x, y)) {
						if (!p_detail_product) {
							cout << "page " << page_p.page << endl;
							if (page_p.current >= page_p.page) {
								cout << "no >" << endl;
							}
							else {
								page_p.current += 1;
								cout << ">" << endl;
								char z[] = { ">" };
								highlight_box(498, 553, 523, 578, z, f_vua, 3, 5, 1);
								delay(200);
								delete_after_main();
								table_CURD(product_header_table, ds, CURD_O, page_p, detail, edit, _delete);
							}
						}
					}

					//check vt detail
					for (int i = 0; i < detail[0].n; i++)
					{
						if (ktVT(detail[i].l, detail[i].t, detail[i].r, detail[i].b, x, y)) {
							cout << "show detail";
							int t = i + (page_p.current - 1) * 9;
							char z[] = { "Chi tiet" };
							highlight_box(detail[i].l, detail[i].t - 2, detail[i].r, detail[i].b + 1, z, f_ds, 1, 4, 1);
							delay(400);
							show_detail_product(product_header_table, ds[t]);
							home_p = false;
							p_detail_product = true;

						}
					}

					// kiem tra click vao them sp;
					if (ktVT(60, 115, 240, 145, x, y)) {
						cout << "Them sp" << endl;
						char text_add[20] = { "Them san pham" };
						highlight_box(60, 115, 240, 145, text_add, f_vua, 1, 10, 6);
						delay(200);
						delete_after_main();
						UI_add_p(product_header_table);
						p_add_product = true;
					}

					// xoa sp
					for (int i = 0; i < _delete[0].n; i++)
					{
						if (ktVT(_delete[i].l, _delete[i].t, _delete[i].r, _delete[i].b, x, y)) {
							cout << "Xoa" << endl;
							char z[] = { "Xoa" };
							highlight_box(_delete[i].l, _delete[i].t - 2, _delete[i].r, _delete[i].b + 1, z, f_ds, 1, 4, 1);
							delay(200);
							int t = (page_p.current - 1) * 9 + i;
							adjust_lr.erase(adjust_lr.begin() + t);
							ds.erase(ds.begin() + t);
							delete_after_main();
							table_CURD(product_header_table, ds, CURD_O, page_p, detail, edit, _delete);
							write_file(ds);
						}
					}

					//kiem tra click edit product
					for (int i = 0; i < edit[0].n; i++)
					{
						if (ktVT(edit[i].l, edit[i].t, edit[i].r, edit[i].b, x, y)) {
							cout << "Chinh sua" << endl;
							char z[] = { "Chinh sua" };
							highlight_box(edit[i].l, edit[i].t, edit[i].r, edit[i].b, z, f_ds, 1, 4, 1);
							delay(200);
							i_edit = (page_p.current - 1) * 9 + i;
							delete_after_main();
							UI_edit_p(product_header_table, ds[i_edit]);
							p_edit_product = true;
							home_p = false;
						}
					}
				}
				if (p_detail_product) {
					// -- button tro ve trong detail
					if (ktVT(400, 530, 571, 570, x, y)) {
						cout << "detail back product" << endl;
						delete_after_main();
						table_CURD(product_header_table, ds, CURD_O, page_p, detail, edit, _delete);
						p_detail_product = false;
						home_p = true;
					}
				}
				// kiem tra click input trong them sp
				if (p_add_product) {
					string s0 = "", s1 = "", s2 = "", s3 = "", s4 = "", s5 = "",
						nsx_d = "", nsx_m = "", nsx_y = "", hsd_d = "", hsd_m = "", hsd_y = "";

					while (1) {
						if (ismouseclick(WM_LBUTTONDOWN)) {
							getmouseclick(WM_LBUTTONDOWN, x, y);
							line(x, y, x + 20, y);
							cout << "\nvi tri x:" << x << " - vi tri y:" << y << endl;
							if (ktVT(320, 135, 750, 160, x, y)) {// ten
								char letter[] = { "" };
								highlight_box(320, 135, 750, 160, letter);
								s0 = input(320, 135, 750, 160, 2, 2, s0);
								s0 = trim(s0);
								strcpy_s(temp.ten, s0.c_str());
							}
							else if (ktVT(320, 190, 410, 215, x, y)) {//phan loai
								char letter[] = { "" };
								while (1) {
									char e[25] = { "Phan loai chua hop le" };
									highlight_box(320, 190, 410, 215, letter);
									s1 = input(320, 190, 410, 215, 2, 2, s1, 2);
									s1 = to_upper(s1);
									s1 = trim(s1);
									if (s1 == "TP" || s1 == "TC" || s1 == "GD") {
										char z[255];
										strcpy_s(z, s1.c_str());
										outtextxy(322, 192, z);
										break;
									}
									noti_input(320, 190, 410, 215, 2, 2, e);
								}
								strcpy_s(temp.pl, s1.c_str());
							}
							else if (ktVT(320, 245, 750, 270, x, y)) {// Gia 
								char letter[] = { "" };
								while (1) {
								highlight_box(320, 245, 750, 270, letter);
								s2 = input(320, 245, 750, 270, 2, 2, s2, 9, 2);
								s2 = trim(s2);
									int count = 0;
									for (int i = 0; i < s2.length(); i++)
									{
										if (s2[i] == '.')count++;
									}
									if (count >= 2 || s2[0] == '.') {
										char out[] = { "So khong hop le " };
										noti_input(320, 245, 750, 270, 2, 2, out);
									}
									else {
										break;
									}
								}
								string gia = s2 + "k";
								strcpy_s(temp.gia, gia.c_str());
							}
							else if (ktVT(320, 300, 750, 325, x, y)) {// can nang
								char letter[] = { "" };
								while (1) {
								highlight_box(320, 300, 750, 325, letter);
								s3 = input(320, 300, 750, 325, 2, 2, s3, 9, 2);
									int count = 0;
									for (int i = 0; i < s3.length(); i++)
									{
										if (s3[i] == '.')count++;
									}
									if (count >= 2 || s3[0] == '.') {
										char out[] = { "So khong hop le " };
										noti_input(320, 300, 750, 325, 2, 2, out);
										
									}
									else {
										break;
									}
								}
								string cn = s3 + "g";
								strcpy_s(temp.can_nang, cn.c_str());
							}
							else if (ktVT(320, 355, 750, 380, x, y)) {// so luong
								char letter[] = { "" };
								highlight_box(320, 355, 750, 380, letter);
								s4 = input(320, 355, 750, 380, 2, 2, s4, 9, 1);
								strcpy_s(temp.sl, s4.c_str());
							}
							else if (ktVT(320, 410, 750, 435, x, y)) {//nha sx
								char letter[] = { "" };
								highlight_box(320, 410, 750, 435, letter);
								s5 = input(320, 410, 750, 435, 2, 2, s5);
								s5 = trim(s5);
								strcpy_s(temp.nha_sx, s5.c_str());
							}
							else if (ktVT(320, 465, 370, 490, x, y)) {//nsx day
								while (1) {
									char letter[] = { "" };
									highlight_box(320, 465, 370, 490, letter);
									nsx_d = input(320, 465, 370, 490, 2, 2, nsx_d, 2, 1);
									bool a = check_day_month(320, 465, 370, 490, 2, 2, nsx_d);
									if (a) {
										break;
									}

								}

							}
							else if (ktVT(400, 465, 450, 490, x, y)) {//nsx month
								while (1) {
									char letter[] = { "" };
									highlight_box(400, 465, 450, 490, letter);
									nsx_m = input(400, 465, 450, 490, 2, 2, nsx_m, 2, 1);
									bool a = check_day_month(400, 465, 450, 490, 2, 2, nsx_d, nsx_m);
									if (a) {
										break;
									}

								}

							}
							else if (ktVT(480, 465, 560, 490, x, y)) {//nsx year
								while (1) {
									char letter[] = { "" };
									highlight_box(480, 465, 560, 490, letter);
									nsx_y = input(480, 465, 560, 490, 2, 2, nsx_y, 4, 1);
									bool a = check_day_month(480, 465, 560, 490, 2, 2, nsx_d, nsx_m, nsx_y);
									if (a) {
										break;
									}
								}
							}
							//hsd
							else if (ktVT(320, 520, 370, 545, x, y)) {//hsd d
								while (1) {
									char letter[] = { "" };
									highlight_box(320, 520, 370, 545, letter);
									hsd_d = input(320, 520, 370, 545, 2, 2, hsd_d, 2, 1);
									bool a = check_day_month(320, 520, 370, 545, 2, 2, hsd_d, hsd_m);
									if (a) {
										break;
									}
								}


							}
							else if (ktVT(400, 520, 450, 545, x, y)) {//hsd m
								while (1) {
									char letter[] = { "" };
									highlight_box(400, 520, 450, 545, letter);
									hsd_m = input(400, 520, 450, 545, 2, 2, hsd_m, 2, 1);
									bool a = check_day_month(400, 520, 450, 545, 2, 2, hsd_d, hsd_m);
									if (a) {
										break;
									}
								}


							}
							else if (ktVT(480, 520, 560, 545, x, y)) {//hsd y
								while (1) {
									char letter[] = { "" };
									highlight_box(480, 520, 560, 545, letter);
									hsd_y = input(480, 520, 560, 545, 2, 2, hsd_y, 4, 1);
									bool a = check_day_month(480, 520, 560, 545, 2, 2, hsd_d, hsd_m, hsd_y);
									if (a) {
										break;
									}
								}
							}

							if (ktVT(815, 520, 890, 550, x, y)) {
								cout << "Huy" << endl;
								char letter[] = { "Huy" };
								highlight_box(815, 520, 890, 550, letter, f_vua, 1, 20, 6);
								delay(200);
								delete_after_main();
								table_CURD(product_header_table, ds, CURD_O, page_p, detail, edit, _delete);
								p_add_product = false;
								home_p = true;
								break;
							}
							settextstyle(f_ds, 0, 1);
							if (ktVT(900, 520, 975, 550, x, y)) {
								if (s0 == "" || s1 == "" || s2 == "" || s3 == "" || s4 == "" || s5 == "" ||
									nsx_d == "" || nsx_m == "" || nsx_y == "" || hsd_d == "" || hsd_m == "" || hsd_y == "") {
									char n[] = { "K duoc de trong" };
									outtextxy(800, 560, n);
									delay(1000);
									setfillstyle(1, 8);
									bar(790, 550, 975, 590);
									continue;
								}
								if (hsd_y == nsx_y) {
									if (hsd_m == nsx_m) {
										if (hsd_d <= nsx_d) {
											char n[] = { "ngay hsd k hop le" };
											outtextxy(800, 560, n);
											delay(1000);
											setfillstyle(1, 8);
											bar(790, 550, 975, 590);
											continue;
										}
									}
									else if (hsd_m < nsx_m) {
										char n[] = { "thang hsd k hop le" };
										outtextxy(800, 560, n);
										delay(1000);
										setfillstyle(1, 8);
										bar(790, 550, 975, 590);
										continue;
									}
								}
								else if (hsd_y < nsx_y) {
									char n[] = { "nam hsd k hop le" };
									outtextxy(800, 560, n);
									delay(1000);
									setfillstyle(1, 8);
									bar(790, 550, 975, 590);
									continue;
								}
								// ghep nsx hsd lai
								nsx_d = format_num(nsx_d);
								cout << nsx_d;
								nsx_m = format_num(nsx_m);
								hsd_d = format_num(hsd_d);
								hsd_m = format_num(hsd_m);
								string _nsx = nsx_d + "/" + nsx_m + "/" + nsx_y;
								string _hsd = hsd_d + "/" + hsd_m + "/" + hsd_y;
								strcpy_s(temp.nsx, _nsx.c_str());
								strcpy_s(temp.hsd, _hsd.c_str());
								settextstyle(f_vua, 0, 1);
								// check to push
								int c = check_duplicate(ds, temp);
								if (c == -1) {
									buy_product x;
									adjust_lr.push_back(x);
									cout << adjust_lr.size();
								};
								push_product(ds, temp);
									
								
								//
								write_file(ds);
								cout << "Luu" << endl;
								char letter[] = { "Luu" };
								highlight_box(900, 520, 975, 550, letter, f_vua, 1, 20, 6);
								delay(200);
								delete_after_main();
								table_CURD(product_header_table, ds, CURD_O, page_p, detail, edit, _delete);
								p_add_product = false;
								home_p = true;
								break;
							}
						}
						delay(1);
					}

				}
				// edit product
				if (p_edit_product) {
					string s0 = "", s1 = "", s2 = "", s3 = "", s4 = "", s5 = "",
						nsx_d = "", nsx_m = "", nsx_y = "", hsd_d = "", hsd_m = "", hsd_y = "";
					vector  <string> v_nsx;
					vector  <string> v_hsd;
					string s_nsx = ds[i_edit].nsx, s_hsd = ds[i_edit].hsd;
					split('/', s_nsx, v_nsx);
					split('/', s_hsd, v_hsd);
					nsx_d = v_nsx[0];
					nsx_m = v_nsx[1];
					nsx_y = v_nsx[2];

					hsd_d = v_hsd[0];
					hsd_m = v_hsd[1];
					hsd_y = v_hsd[2];
					s0 = ds[i_edit].ten;
					strcpy_s(temp.ten, s0.c_str());
					s1 = ds[i_edit].pl;
					strcpy_s(temp.pl, s1.c_str());
					s2 = ds[i_edit].gia;
					strcpy_s(temp.gia, s2.c_str());
					s3 = ds[i_edit].can_nang;
					strcpy_s(temp.can_nang, s3.c_str());
					s4 = ds[i_edit].sl;
					strcpy_s(temp.sl, s4.c_str());
					s5 = ds[i_edit].nha_sx;
					strcpy_s(temp.nha_sx, s5.c_str());
					while (1) {
						if (ismouseclick(WM_LBUTTONDOWN)) {
							getmouseclick(WM_LBUTTONDOWN, x, y);
							line(x, y, x + 20, y);
							cout << "\nvi tri x1:" << x << " - vi tri y1:" << y << endl;
							if (ktVT(320, 135, 750, 160, x, y)) {// ten
								char letter[] = { "" };
								highlight_box(320, 135, 750, 160, letter);
								s0 = input(320, 135, 750, 160, 2, 2, s0);
								s0 = trim(s0);
								strcpy_s(temp.ten, s0.c_str());
							}
							else if (ktVT(320, 190, 410, 215, x, y)) {//phan loai
								char letter[] = { "" };
								while (1) {
									char e[25] = { "Phan loai chua hop le" };
									highlight_box(320, 190, 410, 215, letter);
									s1 = input(320, 190, 410, 215, 2, 2, s1, 2);
									s1 = to_upper(s1);
									s1 = trim(s1);
									if (s1 == "TP" || s1 == "TC" || s1 == "GD") {
										char z[255];
										strcpy_s(z, s1.c_str());
										outtextxy(322, 192, z);
										break;
									}
									noti_input(320, 190, 410, 215, 2, 2, e);
								}
								strcpy_s(temp.pl, s1.c_str());
							}
							else if (ktVT(320, 245, 750, 270, x, y)) {// Gia 
								s2.erase(s2.length()-1 );
								char letter[] = { "" };
								while (1) {
									highlight_box(320, 245, 750, 270, letter);
									s2 = input(320, 245, 750, 270, 2, 2, s2, 9, 2);
									s2 = trim(s2);
									int count = 0;
									for (int i = 0; i < s2.length(); i++)
									{
										if (s2[i] == '.')count++;
									}
									if (count >= 2 || s2[0]=='.') {
										char out[] = { "So khong hop le " };
										noti_input(320, 245, 750, 270, 2, 2, out);
									}
									else {
										break;
									}
								}
								string gia = s2 + "k";
								s2 += "k";
								strcpy_s(temp.gia, s2.c_str());
							}
							else if (ktVT(320, 300, 750, 325, x, y)) {// can nang
								s3.erase(s3.end() - 1);
								char letter[] = { "" };
								while (1) {
									highlight_box(320, 300, 750, 325, letter);
									s3 = input(320, 300, 750, 325, 2, 2, s3, 9, 2);
									int count = 0;
									for (int i = 0; i < s2.length(); i++)
									{
										if (s2[i] == '.')count++;
									}
									if (count >= 2 || s3[0] == '.') {
										char out[] = { "So khong hop le " };
										noti_input(320, 300, 750, 325, 2, 2, out);
									}
									else {
										break;
									}
								}
								
								string cn = s3 + "g";
								s3 += "g";
								strcpy_s(temp.can_nang, s3.c_str());
							}
							else if (ktVT(320, 355, 750, 380, x, y)) {// so luong
								char letter[] = { "" };
								highlight_box(320, 355, 750, 380, letter);
								s4 = input(320, 355, 750, 380, 2, 2, s4, 9, 1);
								strcpy_s(temp.sl, s4.c_str());
							}
							else if (ktVT(320, 410, 750, 435, x, y)) {//nha sx
								char letter[] = { "" };
								highlight_box(320, 410, 750, 435, letter);
								s5 = input(320, 410, 750, 435, 2, 2, s5);
								s5 = trim(s5);
								strcpy_s(temp.nha_sx, s5.c_str());
							}
							else if (ktVT(320, 465, 370, 490, x, y)) {//nsx day
								while (1) {
									char letter[] = { "" };
									highlight_box(320, 465, 370, 490, letter);
									nsx_d = input(320, 465, 370, 490, 2, 2, nsx_d, 2, 1);
									bool a = check_day_month(320, 465, 370, 490, 2, 2, nsx_d);
									if (a) {
										break;
									}

								}

							}
							else if (ktVT(400, 465, 450, 490, x, y)) {//nsx month
								while (1) {
									char letter[] = { "" };
									highlight_box(400, 465, 450, 490, letter);
									nsx_m = input(400, 465, 450, 490, 2, 2, nsx_m, 2, 1);
									bool a = check_day_month(400, 465, 450, 490, 2, 2, nsx_d, nsx_m);
									if (a) {
										break;
									}

								}

							}
							else if (ktVT(480, 465, 560, 490, x, y)) {//nsx year
								while (1) {
									char letter[] = { "" };
									highlight_box(480, 465, 560, 490, letter);
									nsx_y = input(480, 465, 560, 490, 2, 2, nsx_y, 4, 1);
									bool a = check_day_month(480, 465, 560, 490, 2, 2, nsx_d, nsx_m, nsx_y);
									if (a) {
										break;
									}
								}
							}
							//hsd
							else if (ktVT(320, 520, 370, 545, x, y)) {//hsd d
								while (1) {
									char letter[] = { "" };
									highlight_box(320, 520, 370, 545, letter);
									hsd_d = input(320, 520, 370, 545, 2, 2, hsd_d, 2, 1);
									bool a = check_day_month(320, 520, 370, 545, 2, 2, hsd_d);
									if (a) {
										break;
									}
								}


							}
							else if (ktVT(400, 520, 450, 545, x, y)) {//hsd m
								while (1) {
									char letter[] = { "" };
									highlight_box(400, 520, 450, 545, letter);
									hsd_m = input(400, 520, 450, 545, 2, 2, hsd_m, 2, 1);
									bool a = check_day_month(400, 520, 450, 545, 2, 2, hsd_d, hsd_m);
									if (a) {
										break;
									}
								}


							}
							else if (ktVT(480, 520, 560, 545, x, y)) {//hsd y
								while (1) {
									char letter[] = { "" };
									highlight_box(480, 520, 560, 545, letter);
									hsd_y = input(480, 520, 560, 545, 2, 2, hsd_y, 4, 1);
									bool a = check_day_month(480, 520, 560, 545, 2, 2, hsd_d, hsd_m, hsd_y);
									if (a) {
										break;
									}
								}
							}

							if (ktVT(815, 520, 890, 550, x, y)) {
								cout << "Huy" << endl;
								char letter[] = { "Huy" };
								highlight_box(815, 520, 890, 550, letter, f_vua, 1, 20, 6);
								delay(200);
								delete_after_main();
								table_CURD(product_header_table, ds, CURD_O, page_p, detail, edit, _delete);
								p_edit_product = false;
								home_p = true;
								break;
							}
							if (ktVT(900, 520, 975, 550, x, y)) {
								
								if (s0 == "" || s1 == "" || s2 == "" || s3 == "" || s4 == "" || s5 == "" ||
									nsx_d == "" || nsx_m == "" || nsx_y == "" || hsd_d == "" || hsd_m == "" || hsd_y == "") {
									cout << s0 << " " << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " <<
										nsx_d << " " << nsx_m << " " << nsx_y << " " << hsd_d << " " << hsd_m << " " << hsd_y;
									char n[] = { "K duoc de trong" };
									outtextxy(800, 560, n);
									delay(1000);
									setfillstyle(1, 8);
									bar(790, 550, 975, 590);
									continue;
								}
								if (hsd_y == nsx_y) {
									if (hsd_m == nsx_m) {
										if (hsd_d <= nsx_d) {
											char n[] = { "ngay hsd k hop le" };
											outtextxy(800, 560, n);
											delay(1000);
											setfillstyle(1, 8);
											bar(790, 550, 975, 590);
											continue;
										}
									}
									else if (hsd_m < nsx_m) {
											char n[] = { "thang hsd k hop le" };
											outtextxy(800, 560, n);
											delay(1000);
											setfillstyle(1, 8);
											bar(790, 550, 975, 590);
											continue;
									}
								}
								else if (hsd_y < nsx_y) {
									char n[] = { "nam hsd k hop le" };
									outtextxy(800, 560, n);
									delay(1000);
									setfillstyle(1, 8);
									bar(790, 550, 975, 590);
									continue;
								}
								// ghep nsx hsd lai
								nsx_d = format_num(nsx_d);
								nsx_m = format_num(nsx_m);
								hsd_d = format_num(hsd_d);
								hsd_m = format_num(hsd_m);
								string _nsx = nsx_d + "/" + nsx_m + "/" + nsx_y;
								string _hsd = hsd_d + "/" + hsd_m + "/" + hsd_y;
								strcpy_s(ds[i_edit].nsx, _nsx.c_str());
								strcpy_s(ds[i_edit].hsd, _hsd.c_str());

								//them vao ds
								strcpy_s(ds[i_edit].ten, temp.ten);
								strcpy_s(ds[i_edit].pl, temp.pl);
								strcpy_s(ds[i_edit].gia, temp.gia);
								strcpy_s(ds[i_edit].can_nang, temp.can_nang);
								strcpy_s(ds[i_edit].sl, temp.sl);
								strcpy_s(ds[i_edit].nha_sx, temp.nha_sx);

								write_file(ds);
								cout << "Luu" << endl;
								char letter[] = { "Luu" };
								highlight_box(900, 520, 975, 550, letter, f_vua, 1, 20, 6);
								delay(200);
								delete_after_main();
								table_CURD(product_header_table, ds, CURD_O, page_p, detail, edit, _delete);
								p_edit_product = false;
								home_p = true;
								break;
							}
						}
						delay(1);
					}
				}
			}
			//staff
			if (staff_page) {
				if (home_staff) {
					if (ktVT(500, 545, 517, 587, x, y)) {
						if (!p_detail_product) {
							cout << "page " << page_s.page << endl;
							if (page_s.current >= page_s.page) {
								cout << "no >" << endl;
							}
							else {
								page_s.current += 1;
								cout << ">" << endl;
								char z[] = { ">" };
								highlight_box(498, 553, 523, 578, z, f_vua, 3, 5, 1);
								delay(200);
								delete_after_main();
								staff_table(product_header_table, list_s, CURD_O, page_s, detail_s, edit_s, _delete_s);
							}
						}
					}
					if (ktVT(450, 555, 465, 578, x, y)) {
						if (!p_detail_product) {
							if (page_s.current <= 1) {
								cout << "no <" << endl;
							}
							else {
								cout << "<" << endl;
								page_s.current -= 1;
								char z[] = { "<" };
								highlight_box(445, 553, 470, 578, z, f_vua, 3, 5, 1);
								delay(200);
								delete_after_main();
								staff_table(product_header_table, list_s, CURD_O, page_s, detail_s, edit_s, _delete_s);
							}

						}
					}
					//check vt detail staff
					for (int i = 0; i < detail_s[0].n; i++)
					{
						if (ktVT(detail_s[i].l, detail_s[i].t, detail_s[i].r, detail_s[i].b, x, y)) {
							cout << "show detail_s";
							p_detail_staff = true;
							int t = i + (page_s.current - 1) * 9;
							char z[] = { "Chi tiet" };
							highlight_box(detail_s[i].l, detail_s[i].t - 2, detail_s[i].r, detail_s[i].b + 1, z, f_ds, 1, 4, 1);
							delay(400);
							show_deatil_staff(staff_header_table, list_s[t]);
							p_detail_staff = true;
							home_staff = false;
						}
					}
					// kiem tra click vao them nhan vien;
					if (ktVT(60, 115, 240, 145, x, y)) {
						cout << "Them nhan vien" << endl;
						char text_add[20] = { "Them nhan vien" };
						highlight_box(60, 115, 240, 145, text_add, f_vua, 1, 10, 6);
						delay(200);
						delete_after_main();
						UI_add_staff(staff_header_table);
						p_add_staff = true;
					}
					// click edit staff
					for (int i = 0; i < edit_s[0].n; i++)
					{
						if (ktVT(edit_s[i].l, edit_s[i].t, edit_s[i].r, edit_s[i].b, x, y)) {
							cout << "Chinh sua" << endl;
							char z[] = { "Chinh sua" };
							highlight_box(edit_s[i].l, edit_s[i].t, edit_s[i].r, edit_s[i].b, z, f_ds, 1, 4, 1);
							delay(200);
							i_edit_s = (page_s.current - 1) * 9 + i;
							delete_after_main();
							UI_edit_staff(staff_header_table, list_s[i_edit_s]);
							p_edit_staff = true;
							home_p = false;
						}
					}
					// xoa staff
					for (int i = 0; i < _delete_s[0].n; i++)
					{
						if (ktVT(_delete_s[i].l, _delete_s[i].t, _delete_s[i].r, _delete_s[i].b, x, y)) {
							cout << "Xoa" << endl;
							char z[] = { "Xoa" };
							highlight_box(_delete_s[i].l, _delete_s[i].t - 2, _delete_s[i].r, _delete_s[i].b + 1, z, f_ds, 1, 4, 1);
							delay(200);
							int t = (page_s.current - 1) * 9 + i;
							list_s.erase(list_s.begin() + t);
							delete_after_main();
							staff_table(product_header_table, list_s, CURD_O, page_s, detail_s, edit_s, _delete_s);
							write_file_staff(list_s);
						}
					}
				}
				if (p_detail_staff) {
					//tro ve trong detail staff
					if (ktVT(400, 530, 571, 570, x, y) && p_detail_staff) {
						cout << "detail back product" << endl;
						delete_after_main();
						staff_table(staff_header_table, list_s, CURD_O, page_s, detail_s, edit_s, _delete_s);
						p_detail_staff = false;
						home_staff = true;
					}
				}
				if (p_add_staff) {
					string s0 = "", s1 = "", s2 = "", s3 = "", s4 = "", s5 = "",
						ns_d = "", ns_m = "", ns_y = "";

					while (1) {
						if (ismouseclick(WM_LBUTTONDOWN)) {
							getmouseclick(WM_LBUTTONDOWN, x, y);
							line(x, y, x + 20, y);
							cout << "\nvi tri x2:" << x << " - vi tri y2:" << y << endl;
							if (ktVT(320, 155, 750, 180, x, y)) {// ten
								char letter[] = { "" };
								highlight_box(320, 155, 750, 180, letter);
								s0 = input(320, 155, 750, 180, 2, 2, s0);
								s0 = trim(s0);
								vector <string> nameUp;

								strcpy_s(temp_s.ten, s0.c_str());
							}
							else if (ktVT(320, 210, 370, 235, x, y)) {//ns d
								while (1) {
									char letter[] = { "" };
									highlight_box(320, 210, 370, 235, letter);
									ns_d = input(320, 210, 370, 235, 2, 2, ns_d, 2, 1);
									bool a = check_day_month(320, 210, 370, 235, 2, 2, ns_d);
									if (a) {
										break;
									}
								}

							}
							else if (ktVT(400, 210, 450, 235, x, y)) {//ns m
								while (1) {
									char letter[] = { "" };
									highlight_box(400, 210, 450, 235, letter);
									ns_m = input(400, 210, 450, 235, 2, 2, ns_m, 2, 1);
									bool a = check_day_month(400, 210, 450, 235, 2, 2, ns_d, ns_m);
									if (a) {
										break;
									}
								}

							}
							else if (ktVT(480, 210, 560, 235, x, y)) {//ns y
								while (1) {
									char letter[] = { "" };
									highlight_box(480, 210, 560, 235, letter);
									ns_y = input(480, 210, 560, 235, 2, 2, ns_y, 4, 1);
									bool a = check_day_month(480, 210, 560, 235, 2, 2, ns_d, ns_m, ns_y,1);
									if (a) {
										break;
									}
								}
							}
						
							if (ktVT(320, 265, 750, 290, x, y)) {// sdt
								char letter[] = { "" };
								string noti =  "Yeu cau 10 chu so";
								while (1) {
								highlight_box(320, 265, 750, 290, letter);
								s1 = input(320, 265, 750, 290, 2, 2, s1,10,1);
								s1 = trim(s1);
								if (s1.length() == 10) {
									break;
								}
								else {
									noti_input(320, 265, 750, 290, 2,2, noti);
								}
								}
								strcpy_s(temp_s.sdt, s1.c_str());
							}
							if (ktVT(320, 320, 750, 345, x, y)) {// email
								char letter[] = { "" };
								char noti[] = { "email khong hop le" };
								while (1) {
									vector <string> check_mail;
									highlight_box(320, 320, 750, 345, letter);
									s2 = input(320, 320, 750, 345, 2, 2, s2);
									split('@', s2, check_mail);
									if (check_mail.size() > 1 && check_mail[0].find("@") >= check_mail[0].length() && check_mail[1]=="gmail.com" ) {
										
										break;
										
									}
									else {
										cout << "loi" << endl;
										noti_input(320, 320, 750, 345, 2, 2, noti);
									}
								}
								strcpy_s(temp_s.mail,s2.c_str());
							}
							if (ktVT(320, 375, 750, 400, x, y)) {// cccd
								char letter[] = { "" };
								string noti = "Yeu cau 12 chu so";
								while (1) {
									highlight_box(320, 375, 750, 400, letter);
									s3 = input(320, 375, 750, 400, 2, 2, s3, 12, 1);
									s3 = trim(s3);
									if (s3.length() == 12) {
										break;
									}
									else {
										noti_input(320, 375, 750, 400, 2, 2, noti);
									}
								}
								strcpy_s(temp_s.cccd, s1.c_str());
							}
							if (ktVT(320, 430, 750, 455, x, y)) {// tlv
								char letter[] = { "" };
								highlight_box(320, 430, 750, 455, letter);
								s4 = input(320, 430, 750, 455, 2, 2, s4,1,1);
								s4 = trim(s4);
								strcpy_s(temp_s.t_l_v, s4.c_str());
							}
							if (ktVT(320, 485, 750, 510, x, y)) {// dia chi
								char letter[] = { "" };
								highlight_box(320, 485, 750, 510, letter);
								s5 = input(320, 485, 750, 510, 2, 2, s5);
								s5 = trim(s5);
								strcpy_s(temp_s.dia_chi, s5.c_str());
							}

							if (ktVT(815, 520, 890, 550, x, y)) {
								cout << "Huy" << endl;
								char letter[] = { "Huy" };
								highlight_box(815, 520, 890, 550, letter, f_vua, 1, 20, 6);
								delay(200);
								delete_after_main();
								staff_table(staff_header_table, list_s, CURD_O, page_s, detail_s, edit_s, _delete_s);
								p_add_staff = false;
								home_staff = true;
								break;
							}
							if (ktVT(900, 520, 975, 550, x, y)) {
								if (s0 == "" || s1 == "" || s2 == "" || s3 == "" || s4 == "" || s5 == "" ||
									ns_d == "" || ns_m == "" || ns_y == "" ) {

									char n[] = { "K duoc de trong" };
									outtextxy(800, 560, n);
									delay(1000);
									setfillstyle(1, 8);
									bar(790, 550, 975, 590);
									continue;
								}
								// ghep nsx hsd lai
								ns_d = format_num(ns_d);
								ns_m = format_num(ns_m);
								string ns = ns_d + "/" + ns_m + "/" + ns_y;
								strcpy_s(temp_s.ntns, ns.c_str());
								// check to push
								if (check_push_staff(list_s,temp_s)) {
									int mnv;
									if (list_s.size() != 0) {
										mnv = stoi(list_s[list_s.size() - 1].mnv);
										mnv++;
										strcpy_s(temp_s.mnv, to_string(mnv).c_str());
									}
									else {
										mnv = 0;
									}
									list_s.push_back(temp_s);
								}
								else {
									char n[] = { "Thong tin da bi trung" };
									outtextxy(800, 560, n);
									delay(1000);
									setfillstyle(1, 8);
									bar(790, 550, 975, 590);
									continue;
								}
								//
								write_file_staff(list_s);
								cout << "Luu" << endl;
								char letter[] = { "Luu" };
								highlight_box(900, 520, 975, 550, letter, f_vua, 1, 20, 6);
								delay(200);
								delete_after_main();
								staff_table(staff_header_table, list_s, CURD_O, page_s, detail_s, edit_s, _delete_s);
								p_add_staff = false;
								home_staff= true;
								break;
							}

						}
					}
				}
				if (p_edit_staff) {
					string s0 = "", s1 = "", s2 = "", s3 = "", s4 = "", s5 = "",
						ns_d = "", ns_m = "", ns_y = "";
					string s_ns = ds[i_edit_s].nsx;
					vector <string> v_ns;
					split('/', s_ns, v_ns);
					ns_d = v_ns[0];
					ns_m = v_ns[1];
					ns_y = v_ns[2];
					s0 = list_s[i_edit_s].ten;
					strcpy_s(temp_s.ten, s0.c_str());
					s1 = list_s[i_edit_s].sdt;
					strcpy_s(temp_s.sdt, s1.c_str());
					s2 = list_s[i_edit_s].mail;
					strcpy_s(temp_s.mail, s2.c_str());
					s3 = list_s[i_edit_s].cccd;
					strcpy_s(temp_s.cccd, s3.c_str());
					s4 = list_s[i_edit_s].t_l_v;
					strcpy_s(temp_s.t_l_v, s4.c_str());
					s5 = list_s[i_edit_s].dia_chi;
					strcpy_s(temp_s.dia_chi, s5.c_str());
					while (1) {
						if (ismouseclick(WM_LBUTTONDOWN)) {
							getmouseclick(WM_LBUTTONDOWN, x, y);
							line(x, y, x + 20, y);
							cout << "\nvi tri x2:" << x << " - vi tri y2:" << y << endl;
							if (ktVT(320, 155, 750, 180, x, y)) {// ten
								char letter[] = { "" };
								highlight_box(320, 155, 750, 180, letter);
								s0 = input(320, 155, 750, 180, 2, 2, s0);
								s0 = trim(s0);
								strcpy_s(temp_s.ten, s0.c_str());
							}
							else if (ktVT(320, 210, 370, 235, x, y)) {//ns d
								while (1) {
									char letter[] = { "" };
									highlight_box(320, 210, 370, 235, letter);
									ns_d = input(320, 210, 370, 235, 2, 2, ns_d, 2, 1);
									bool a = check_day_month(320, 210, 370, 235, 2, 2, ns_m, ns_d);
									if (a) {
										break;
									}
								}

							}
							else if (ktVT(400, 210, 450, 235, x, y)) {//ns m
								while (1) {
									char letter[] = { "" };
									highlight_box(400, 210, 450, 235, letter);
									ns_m = input(400, 210, 450, 235, 2, 2, ns_m, 2, 1);
									bool a = check_day_month(400, 210, 450, 235, 2, 2, ns_d, ns_m);
									if (a) {
										break;
									}
								}

							}
							else if (ktVT(480, 210, 560, 235, x, y)) {//ns y
								while (1) {
									char letter[] = { "" };
									highlight_box(480, 210, 560, 235, letter);
									ns_y = input(480, 210, 560, 235, 2, 2, ns_y, 4, 1);
									bool a = check_day_month(480, 210, 560, 235, 2, 2, ns_d, ns_m, ns_y, 1);
									if (a) {
										break;
									}
								}
							}

							if (ktVT(320, 265, 750, 290, x, y)) {// sdt
								char letter[] = { "" };
								string noti = "Yeu cau 10 chu so";
								while (1) {
									highlight_box(320, 265, 750, 290, letter);
									s1 = input(320, 265, 750, 290, 2, 2, s1, 10, 1);
									s1 = trim(s1);
									if (s1.length() == 10) {
										break;
									}
									else {
										noti_input(320, 265, 750, 290, 2, 2, noti);
									}
								}
								strcpy_s(temp_s.sdt, s1.c_str());
							}
							if (ktVT(320, 320, 750, 345, x, y)) {// email
								char letter[] = { "" };
								char noti[] = { "email khong hop le" };
								while (1) {
									vector <string> check_mail;
									highlight_box(320, 320, 750, 345, letter);
									s2 = input(320, 320, 750, 345, 2, 2, s2);
									split('@', s2, check_mail);
									if (check_mail.size() > 1 && check_mail[0].find("@") >= check_mail[0].length() && check_mail[1] == "gmail.com") {

										break;

									}
									else {
										cout << "loi" << endl;
										noti_input(320, 320, 750, 345, 2, 2, noti);
									}
								}
								strcpy_s(temp_s.mail, s2.c_str());
							}
							if (ktVT(320, 375, 750, 400, x, y)) {// cccd
								char letter[] = { "" };
								string noti = "Yeu cau 12 chu so";
								while (1) {
									highlight_box(320, 375, 750, 400, letter);
									s3 = input(320, 375, 750, 400, 2, 2, s3, 12, 1);
									s3 = trim(s3);
									if (s3.length() == 12) {
										break;
									}
									else {
										noti_input(320, 375, 750, 400, 2, 2, noti);
									}
								}
								strcpy_s(temp_s.cccd, s1.c_str());
							}
							if (ktVT(320, 430, 750, 455, x, y)) {// tlv
								char letter[] = { "" };
								highlight_box(320, 430, 750, 455, letter);
								s4 = input(320, 430, 750, 455, 2, 2, s4, 1, 1);
								s4 = trim(s4);
								strcpy_s(temp_s.t_l_v, s4.c_str());
							}
							if (ktVT(320, 485, 750, 510, x, y)) {// dia chi
								char letter[] = { "" };
								highlight_box(320, 485, 750, 510, letter);
								s5 = input(320, 485, 750, 510, 2, 2, s5);
								s5 = trim(s5);
								strcpy_s(temp_s.dia_chi, s5.c_str());
							}
							if (ktVT(815, 520, 890, 550, x, y)) {
								cout << "Huy" << endl;
								char letter[] = { "Huy" };
								highlight_box(815, 520, 890, 550, letter, f_vua, 1, 20, 6);
								delay(200);
								delete_after_main();
								staff_table(staff_header_table, list_s, CURD_O, page_s, detail_s, edit_s, _delete_s);
								p_edit_staff = false;
								home_staff = true;
								break;
							}
							if (ktVT(900, 520, 975, 550, x, y)) {
								if (s0 == "" || s1 == "" || s2 == "" || s3 == "" || s4 == "" || s5 == "" ||
									ns_d == "" || ns_m == "" || ns_y == "") {

									char n[] = { "K duoc de trong" };
									outtextxy(800, 560, n);
									delay(1000);
									setfillstyle(1, 8);
									bar(790, 550, 975, 590);
									continue;
								}
								// ghep nsx hsd lai
								ns_d = format_num(ns_d);
								ns_m = format_num(ns_m);
								string ns = ns_d + "/" + ns_m + "/" + ns_y;
								strcpy_s(temp_s.ntns, ns.c_str());
								// check to push
								if (check_push_staff(list_s, temp_s,i_edit_s)) {
									strcpy_s(list_s[i_edit_s].ten , temp_s.ten);
									strcpy_s(list_s[i_edit_s].mail , temp_s.mail);
									strcpy_s(list_s[i_edit_s].ntns , temp_s.ntns);
									strcpy_s(list_s[i_edit_s].dia_chi , temp_s.dia_chi);
									strcpy_s(list_s[i_edit_s].cccd , temp_s.cccd);
									strcpy_s(list_s[i_edit_s].t_l_v , temp_s.t_l_v);
									strcpy_s(list_s[i_edit_s].sdt , temp_s.sdt);
								}
								else {
									char n[] = { "Thong tin da bi trung" };
									outtextxy(800, 560, n);
									delay(1000);
									setfillstyle(1, 8);
									bar(790, 550, 975, 590);
									continue;
								}
								//
								write_file_staff(list_s);
								cout << "Luu" << endl;
								char letter[] = { "Luu" };
								highlight_box(900, 520, 975, 550, letter, f_vua, 1, 20, 6);
								delay(200);
								delete_after_main();
								staff_table(staff_header_table, list_s, CURD_O, page_s, detail_s, edit_s, _delete_s);
								p_edit_staff = false;
								home_staff = true;
								break;
							}

						}
					}
				}
			}
			// buy
			if (home_buy) {
				//left_arrow
				for (int i = 0; i < left_arrow[0].n; i++)
				{
					if (ktVT(left_arrow[i].l, left_arrow[i].t, left_arrow[i].r, left_arrow[i].b, x, y)) {
						int t = i + (page_b.current - 1) * 9;
						if (adjust_lr[t].sl == 0) {
							cout << "no left";
							break;
						}
						else {
							adjust_lr[t].sl--;
							char x[] = { "<" };
							highlight_box(left_arrow[i].l, left_arrow[i].t, left_arrow[i].r, left_arrow[i].b, x, 3, 1, 2, 1);
							delay(150);
							delete_after_main();
							buy_table(product_header_table, ds, CURD_O, page_b, detail_b, adjust_lr, left_arrow, right_arrow);
						}
					}
				}
				//right_arrow
				for (int i = 0; i < right_arrow[0].n; i++)
				{

					if (ktVT(right_arrow[i].l, right_arrow[i].t, right_arrow[i].r, right_arrow[i].b, x, y)) {
						int t = i + (page_b.current - 1) * 9;
						if (adjust_lr[t].sl >= atoi(ds[t].sl)) {
							cout << "no right";
							break;
						}
						else {
							cout << "yes right";
							adjust_lr[t].sl++;
							char x[] = { ">" };
							highlight_box(right_arrow[i].l, right_arrow[i].t, right_arrow[i].r, right_arrow[i].b, x, 3, 1, 3, 1);
							delay(150);
							delete_after_main();
							buy_table(product_header_table, ds, CURD_O, page_b, detail_b, adjust_lr, right_arrow, right_arrow);
							for (int i = 0; i < adjust_lr.size(); i++)
							{
								cout << adjust_lr[i].index << " ";
							}
						}
					}
				}
				//show detail
				for (int i = 0; i < detail_b[0].n; i++)
				{
					if (ktVT(detail_b[i].l, detail_b[i].t, detail_b[i].r, detail_b[i].b, x, y)) {
						cout << "show detail_b";
						int t = i + (page_b.current - 1) * 9;
						char z[] = { "Chi tiet" };
						highlight_box(detail_b[i].l, detail_b[i].t - 2, detail_b[i].r, detail_b[i].b + 1, z, f_ds, 1, 4, 1);
						delay(400);
						show_detail_product(product_header_table, ds[t]);
						home_buy = false;
						p_detail_product = true;
					}
				}
				//< buy page
				if (ktVT(450, 555, 465, 578, x, y)) {
					if (!p_detail_product) {
						if (page_b.current <= 1) {
							cout << "no <" << endl;
						}
						else {
							cout << "<" << endl;
							page_b.current -= 1;
							char z[] = { "<" };
							highlight_box(445, 553, 470, 578, z, f_vua, 3, 5, 1);
							delay(200);
							delete_after_main();
							buy_table(product_header_table, ds, CURD_O, page_b, detail_b, adjust_lr, right_arrow, right_arrow);
						}

					}
				}				// > buy page
				if (ktVT(500, 545, 517, 587, x, y)) {
					if (!p_detail_product) {
						cout << "page " << page_b.page << endl;
						if (page_b.current >= page_b.page) {
							cout << "no >" << endl;
						}
						else {
							page_b.current += 1;
							cout << ">" << endl;
							char z[] = { ">" };
							highlight_box(498, 553, 523, 578, z, f_vua, 3, 5, 1);
							delay(200);
							delete_after_main();
							buy_table(product_header_table, ds, CURD_O, page_b, detail_b, adjust_lr, right_arrow, right_arrow);
						}
					}
				}
				// click card
				if (ktVT(865, 115, 975, 145, x, y)) {
					UI_card(product_header_table, adjust_lr, ds, page_card);
					home_buy = false;
					in_card_page = true;
				}

				// click mua san pham
				if (ktVT(730, 550, 890, 585, x, y)) {
					if (check_empty_buy(adjust_lr) == 1) {
						list_bill temp;
						for (int i = 0; i < adjust_lr.size(); i++)
						{
							if (adjust_lr[i].sl != 0) {
								int c = check_name(adjust_lr[i], product_sold);
								if (c != -1) {
									int s = atoi(product_sold[c].sl) + adjust_lr[i].sl;
									strcpy_s(product_sold[c].sl, to_string(s).c_str());
								}
								else {
									product t;
									t = ds[i];
									strcpy_s(t.sl, to_string(adjust_lr[i].sl).c_str());
									product_sold.push_back(t);
								}
								int f = atoi(ds[i].sl) - adjust_lr[i].sl;
								strcpy_s(ds[i].sl, to_string(f).c_str());
								temp.ds.push_back(ds[i]);
							}
						}
						bill(code_bill, page_bill, adjust_lr, ds);
						strcpy_s(temp.mhd, adjust_lr[0].mhd);
						strcpy_s(temp.date, adjust_lr[0].date);
						l_bills.push_back(temp);
						write_file_list_bill(l_bills);
						write_file(ds);
						in_bill_page = true;
						home_buy = false;
					}
					else {
						char x[] = { "Ban chua chon sp" };
						setcolor(0);
						settextstyle(f_vua, 0, 1);
						setbkcolor(8);
						setcolor(RED);
						outtextxy(550, 560, x);
						setcolor(0);
					}
				}
				if (ktVT(60, 115, 340, 145, x, y)) {
					char s[] = { "Top 10 sp ban chay nhat" };
					highlight_box(60, 115, 340, 145, s, f_vua, 1, 8, 6);
					delay(200);
					UI_top10(product_sold,detail_top10);
					top_10_page = true;
					home_buy = false;
				}
				if (ktVT(363, 115, 625, 145, x, y)) {
					char x[] = { "Hoa don trong ngay" };
					highlight_box(363, 115, 590, 145, x, f_vua, 1, 10, 6);
					delay(200);
					UI_list_bill(l_bills, detail_list_bill, page_list_bill);
					in_list_bill = true;
					home_buy = false;
				}
				
			}
			if (in_bill_page) {
				//Tro ve
				if (ktVT(865, 510, 950, 540, x, y)) {
					for (int i = 0; i < adjust_lr.size(); i++)
					{
						adjust_lr[i].sl = 0;
					}
					for (int i = 0; i < product_sold.size() - 1; i++)
					{
						for (int j = i + 1; j < product_sold.size(); j++)
						{
							if (atoi(product_sold[i].sl) < atoi(product_sold[j].sl)) {
								swap(product_sold[i], product_sold[j]);
							}
						}
					}
					write_file_top10(product_sold);
					page_bill.current=1;
					char z[] = { "Tro ve" };
					highlight_box(865, 510, 950, 540, z, f_vua, 1,8, 6);
					delay(200);
					delete_after_main();
					buy_table(product_header_table, ds, CURD_O, page_b, detail_b, adjust_lr, right_arrow, right_arrow);
					in_bill_page = false;
					home_buy = true;
				}
				//< bill page
				if (ktVT(450, 555, 465, 578, x, y)) {
					if (page_bill.current <= 1) {
						cout << "no <" << endl;
					}
					else {
						cout << "<" << endl;
						page_bill.current -= 1;
						char z[] = { "<" };
						highlight_box(445, 553, 470, 578, z, f_vua, 3, 5, 1);
						delay(200);
						delete_after_main();
						bill(code_bill, page_bill, adjust_lr, ds);
					}

				}
				// > bill page
				if (ktVT(500, 545, 517, 587, x, y)) {
					cout << "page " << page_bill.page << endl;
					if (page_bill.current >= page_bill.page) {
						cout << "no >" << endl;
					}
					else {
						page_bill.current += 1;
						cout << ">" << endl;
						char z[] = { ">" };
						highlight_box(498, 553, 523, 578, z, f_vua, 3, 5, 1);
						delay(200);
						delete_after_main();
						bill(code_bill, page_bill, adjust_lr, ds);
				}
			}

			}
			if (in_card_page) {
				//>
				if (ktVT(450, 555, 465, 578, x, y)) {
					if (page_card.current <= 1) {
						cout << "no <" << endl;
					}
					else {
						cout << "<" << endl;
						page_card.current -= 1;
						char z[] = { "<" };
						highlight_box(445, 553, 470, 578, z, f_vua, 3, 5, 1);
						delay(200);
						delete_after_main();
						UI_card(product_header_table, adjust_lr, ds, page_card);
					}

				}
				// >	
				if (ktVT(500, 545, 517, 587, x, y)) {

					cout << "page " << page_card.page << endl;
					if (page_card.current >= page_card.page) {
						cout << "no >" << endl;
					}
					else {
						page_card.current += 1;
						cout << ">" << endl;
						char z[] = { ">" };
						highlight_box(498, 553, 523, 578, z, f_vua, 3, 5, 1);
						delay(200);
						delete_after_main();
						UI_card(product_header_table, adjust_lr, ds, page_card);
					}
				}
				// tro ve buy
				if (ktVT(865, 140, 950, 170, x, y)) {
					char back[] = { "Tro ve" };
					highlight_box(865, 140, 950, 170, back, f_vua, 1, 8, 6);
					delay(200);
					delete_after_main();
					buy_table(product_header_table, ds, CURD_O, page_b, detail_b, adjust_lr, left_arrow, right_arrow);
					home_buy = true;
					in_card_page = false;
				}
			
			}
			//back detail buy
			if (p_detail_product) {
				// -- button tro ve trong detail
				if (ktVT(400, 530, 571, 570, x, y)) {
					cout << "detail back product" << endl;
					delete_after_main();
					buy_table(product_header_table, ds, CURD_O, page_b, detail_b, adjust_lr, right_arrow, right_arrow);
					p_detail_product = false;
					home_buy = true;
				}
			}
			if (in_list_bill) {
				//detail
				for (int i = 0; i < detail_list_bill[0].n; i++)
				{
					if (ktVT(detail_list_bill[i].l, detail_list_bill[i].t, detail_list_bill[i].r, detail_list_bill[i].b, x, y)) {
						char z[] = { "Xem chi tiet" };
						highlight_box(detail_list_bill[i].l, detail_list_bill[i].t, detail_list_bill[i].r, detail_list_bill[i].b, z, f_ds, 1, 4, 1);
						delay(200);
						index_bill_p = (page_list_bill.current - 1) * 9 + i;
						delete_after_main();
						UI_detail_list(product_header_table, l_bills[index_bill_p].ds, page_p_in_list, detail_p_in_list);
						in_list_bill = false;
						in_page_list_p = true;
					}
				}
				//<
				if (ktVT(450, 555, 465, 578, x, y)) {
					if (page_list_bill.current <= 1) {
					
						cout << "no <" << endl;
					}
					else {
						cout << "<" << endl;
						page_list_bill.current -= 1;
						char z[] = { "<" };
						highlight_box(445, 553, 470, 578, z, f_vua, 3, 5, 1);
						delay(200);
						delete_after_main();
						UI_list_bill(l_bills, detail_list_bill, page_list_bill);
					}

				}
				// >	
				if (ktVT(500, 545, 517, 587, x, y)) {
					if (page_list_bill.current >= page_list_bill.page) {
						cout << "no >" << endl;
					}
					else {
						page_list_bill.current += 1;
						cout << ">" << endl;
						char z[] = { ">" };
						highlight_box(498, 553, 523, 578, z, f_vua, 3, 5, 1);
						delay(200);
						delete_after_main();
						UI_list_bill(l_bills, detail_list_bill, page_list_bill);
					}
				}
				if (ktVT(865, 510, 950, 540, x, y)) {
					char back[] = { "Tro ve" };
					highlight_box(865, 510, 950, 540, back, f_vua, 1, 8, 6);
					delay(200);
					delete_after_main();
					buy_table(product_header_table, ds, CURD_O, page_b, detail_b, adjust_lr, left_arrow, right_arrow);
					in_list_bill = false;
					home_buy = true;
				}
			}
			if (in_page_list_p) {
				//detail
				for (int i = 0; i < detail_p_in_list[0].n; i++)
				{
					if (ktVT(detail_p_in_list[i].l, detail_p_in_list[i].t, detail_p_in_list[i].r, detail_p_in_list[i].b, x, y)) {
						char z[] = { "Chi tiet" };
						highlight_box(detail_p_in_list[i].l, detail_p_in_list[i].t, detail_p_in_list[i].r, detail_p_in_list[i].b, z, f_ds, 1, 4, 1);
						delay(200);
						int t = (page_list_bill.current - 1) * 9 + i;
						delete_after_main();
						show_detail_product(product_header_table, l_bills[index_bill_p].ds[t]);
						in_page_list_p = false;
						in_show_detail_p_bill = true;
					}
				}
				if (ktVT(740, 555, 820, 585, x, y)) {
					char back[] = { "Tro ve" };
					highlight_box(740, 555, 820, 585, back, f_vua, 1, 8, 6);
					delay(200);
					UI_list_bill(l_bills, detail_list_bill, page_list_bill);
					in_page_list_p = false;
					in_list_bill = true;
				}

			}
			if (in_show_detail_p_bill) {
				if (ktVT(400, 530, 571, 570, x, y)) {
					cout << "detail back product" << endl;
					delete_after_main();
					UI_detail_list(product_header_table, l_bills[index_bill_p].ds, page_p_in_list, detail_p_in_list);
					in_page_list_p = true;
					in_show_detail_p_bill = false;
				}
			}
			if (in_detail_top10) {
				if (ktVT(400, 530, 571, 570, x, y)) {
					char back[] = { "Tro ve" };
					highlight_box(400, 530, 571, 570,back , f_vua, 1, 50, 12);
					delay(200);
					UI_top10(product_sold, detail_top10);
					in_detail_top10 = false;
					top_10_page = true;
				}
			}
			// tro ve top 10
			if (top_10_page) {
				for (int i = 0; i < detail_top10[0].n; i++)
				{
					if (ktVT(detail_top10[i].l, detail_top10[i].t, detail_top10[i].r, detail_top10[i].b, x, y)) {
						char x[] = { "Chi tiet" };
						highlight_box(detail_top10[i].l, detail_top10[i].t, detail_top10[i].r, detail_top10[i].b, x, f_ds, 1, 4, 1);
						delay(200);
						show_detail_product(product_header_table, product_sold[i]);
						in_detail_top10 = true;
						top_10_page = false;
					}
				}
				if (ktVT(865, 510, 950, 540, x, y)) {
					char back[] = { "Tro ve" };
					highlight_box(865, 510, 950, 540, back, f_vua, 1, 8, 6);
					delay(200);
					delete_after_main();
					buy_table(product_header_table, ds, CURD_O, page_b, detail_b, adjust_lr, left_arrow, right_arrow);
					top_10_page = false;
					home_buy = true;
				}
			}
		}
		
		delay(1);
	}

	getch();
	closegraph();
	return 0;
}