#include "khaibao.h"
void read_file(vector <product> &ds ) {
	ifstream filein;
	filein.open("hanghoa.txt",ios_base::in);
	product a;
	while (filein.eof() != true) 
	{
		filein.getline(a.msp, 10, ',');
		filein.getline(a.ten, 255, ',');
		filein.getline(a.pl, 3, ',');
		filein.getline(a.gia, 11, ',');
		filein.getline(a.sl, 11, ',');
		filein.getline(a.can_nang, 11, ',');
		filein.getline(a.nsx, 21, ',');
		filein.getline(a.hsd, 21, ',');
		filein.getline(a.nha_sx, 255);
		ds.push_back(a);
	};
	cout << "read file "<<ds.size() << endl;
	filein.close();
}
void read_file_staff(vector <staff>& ds) {
	ifstream filein;
	filein.open("nhanvien.txt", ios_base::in);
	staff a;
	while (filein.eof() != true)
	{
		filein.getline(a.mnv, 10, ',');
		filein.getline(a.ten, 255, ',');
		filein.getline(a.ntns, 11, ',');
		filein.getline(a.cccd, 13, ',');
		filein.getline(a.dia_chi, 255, ',');
		filein.getline(a.mail, 30, ',');
		filein.getline(a.sdt, 11, ',');
		filein.getline(a.t_l_v, 2);
		ds.push_back(a);
	};
	cout << "read file " << ds.size() << endl;
	filein.close();
}
void read_top10(vector <product>& ds) {
	ifstream filein;
	filein.open("top10.txt", ios_base::in);
	product a;
	while (filein.eof() != true)
	{
		
		filein.getline(a.msp, 10, ',');
		if (a.msp[0] =='\0')break;
		filein.getline(a.ten, 255, ',');
		filein.getline(a.pl, 3, ',');
		filein.getline(a.gia, 11, ',');
		filein.getline(a.sl, 11, ',');
		filein.getline(a.can_nang, 11, ',');
		filein.getline(a.nsx, 21, ',');
		filein.getline(a.hsd, 21, ',');
		filein.getline(a.nha_sx, 255);
		ds.push_back(a);
	};
	cout << "read file top 10 " << ds.size() << endl;
	filein.close();
}
void read_list_bill(vector <list_bill>& ds) {
	ifstream filein;
	filein.open("bills_in_day.txt", ios_base::in); 
	while (filein.eof() != true)
	{
		list_bill temp;
		product a;
		filein.getline(temp.mhd,10);
		filein.getline(temp.date,30);
		string n;
		getline(filein, n);
		if (n == "")break;
		for (int i = 0; i < stoi(n); i++)
		{
			filein.getline(a.msp, 10, ',');
			filein.getline(a.ten, 255, ',');
			filein.getline(a.pl, 3, ',');
			filein.getline(a.gia, 11, ',');
			filein.getline(a.sl, 11, ',');
			filein.getline(a.can_nang, 11, ',');
			filein.getline(a.nsx, 21, ',');
			filein.getline(a.hsd, 21, ',');
			filein.getline(a.nha_sx, 255);
			temp.ds.push_back(a);
		}
		ds.push_back(temp);
	};
	cout << "read file bill in day " << ds.size() << endl;
	filein.close();
}

void write_file(vector <product>& ds) {
	ofstream outfile;
	outfile.open("hanghoa.txt");
	for (int i = 0; i < ds.size(); i++) {
		outfile << ds[i].msp << ",";
		outfile << ds[i].ten << ",";
		outfile << ds[i].pl << ",";
		outfile << ds[i].gia << ",";
		outfile << ds[i].sl << ",";
		outfile << ds[i].can_nang << ",";
		outfile << ds[i].nsx << ",";
		outfile << ds[i].hsd << ",";
		if (i == ds.size() - 1) {
			outfile << ds[i].nha_sx;
			// tranh du thua endl

		}
		else {
			outfile << ds[i].nha_sx << endl;
		}
	}
	outfile.close();
}
void write_file_staff(vector <staff>& ds) {
	ofstream outfile;
	outfile.open("nhanvien.txt");
	for (int i = 0; i < ds.size(); i++) {
		outfile << ds[i].mnv << ",";
		outfile << ds[i].ten << ",";
		outfile << ds[i].ntns << ",";
		outfile << ds[i].cccd << ",";
		outfile << ds[i].dia_chi << ",";
		outfile << ds[i].mail << ",";
		outfile << ds[i].sdt << ",";
		if (i == ds.size() - 1) {
			outfile << ds[i].t_l_v;
			// tranh du thua endl
		}
		else {
			outfile << ds[i].t_l_v << endl;
		}
	}
	outfile.close();
}
void write_file_top10(vector <product>& ds) {
	ofstream outfile;
	outfile.open("top10.txt");
	for (int i = 0; i < ds.size(); i++) {
		outfile << ds[i].msp << ",";
		outfile << ds[i].ten << ",";
		outfile << ds[i].pl << ",";
		outfile << ds[i].gia << ",";
		outfile << ds[i].sl << ",";
		outfile << ds[i].can_nang << ",";
		outfile << ds[i].nsx << ",";
		outfile << ds[i].hsd << ",";
		if (i == ds.size() - 1) {
			outfile << ds[i].nha_sx;
			// tranh du thua endl
		}
		else {
			outfile << ds[i].nha_sx << endl;
		}
	}
	outfile.close();
}
void write_file_list_bill(vector <list_bill> list) {
	ofstream outfile;
	outfile.open("bills_in_day.txt");
	for (int i = 0; i < list.size(); i++) {
		outfile << list[i].mhd << endl;
		outfile << list[i].date << endl;
		int n = list[i].ds.size();
		cout << "n list " << n<<endl;
		outfile << n<<endl;
		for (int j= 0; j < n; j++)
		{
			outfile << list[i].ds[j].msp << ",";
			outfile << list[i].ds[j].ten << ",";
			outfile << list[i].ds[j].pl << ",";
			outfile << list[i].ds[j].gia << ",";
			outfile << list[i].ds[j].sl << ",";
			outfile << list[i].ds[j].can_nang << ",";
			outfile << list[i].ds[j].nsx << ",";
			outfile << list[i].ds[j].hsd << ",";
			if (i == list.size()- 1 && j==n-1) {
				outfile << list[i].ds[j].nha_sx;
				// tranh du thua endl

			}
			else {
				outfile << list[i].ds[j].nha_sx << endl;
			}

		}
	}
	outfile.close();
}
// tao box
bool ktVT(int l, int t, int r ,int b, int x, int y,int p) {
	/*cout << l << " " << x << " " << r << "|" << t << " " << y << " " << b << " ";*/
	if (x <= r && x >= l && y >= t && y <= b) return true;
	return false;
}
void normal_box(int l, int t, int r, int b, char s[],int font,int f_size,  int kcl, int kct = 8) {
	setcolor(0);
	settextstyle(font,0,f_size);
	setfillstyle(1,11);
	bar3d(l,t,r,b,0,0); //6 1
	setbkcolor(11);	
	outtextxy(l+kcl,t+kct,s);
}
void normal_text() { //set mau mac dinh cua ung dung
	setbkcolor(8);//xam
	setcolor(0);//den
}
void menu_chinh(char a[][20]) {
	setfillstyle(1,7);
	bar(0,52,1000,100);
	settextstyle(f_lon, 0, 4);
	char x[] = { "Bach hoa xanh" };
	outtextxy(333, 10, x);
	normal_box(60,63,237,94,a[0],f_lon, 1,5);
	normal_box(363,63,598,94,a[1],f_lon, 1, 5);
	normal_box(716,63,850,94,a[2],f_lon, 1, 5);
}
//product page
void table_CURD(
	char product_header[][20],
	vector <product> &ds,
	char CURD_O[][20],
	view_page &view_page,
	check_CURD detail[] ,
	check_CURD edit[],
	check_CURD _delete[]
	)
{	//chuc nang khac
	char text_func[2][20] = {"Them san pham","Nhap hang hoa"};
	normal_box(60, 115, 240, 145, text_func[0], f_vua, 1, 10, 6);
	/*normal_box(300, 115, 480, 145, text_func[1], f_vua, 1, 10, 6);*/
	// tnh so page co trong trang
	int n = ds.size();
	int page = n/ 9;
	int du = n % 9;
	view_page.page = du ? page + 1 : page;
	cout << "page: " << view_page.page << endl;
	int max_page = n > (9 * view_page.current ) ? (9 * view_page.current) : n;
	// reder page
	int i = 9 * (view_page.current - 1);
	//header
	int bar_top = 155, bar_bottom = 185;
	int text_top = 160;
	setfillstyle(1, 6);
	setbkcolor(6);
	settextstyle(f_ds, 0, 1);
	bar3d(0, bar_top, 1000, bar_bottom,1,1);
	outtextxy(5, 160, product_header[0]);
	outtextxy(60, 160, product_header[1]);
	outtextxy(261, 160, product_header[2]);
	outtextxy(400, 160, product_header[3]);
	outtextxy(560, 160, product_header[4]);
	outtextxy(738, 160, product_header[5]);
	setfillstyle(1, 15);
	setbkcolor(15);
	int j = 0; //detail
	int d = 0;//delete
	int e = 0;
	for (; i < max_page; i++)
	{
		if (i%9 ==0) {
		bar_top += 30;
		bar_bottom += 40;
		text_top += 35;
		}
		else {
			bar_top += 40;
			bar_bottom += 40;
			text_top += 40;
		}

		//lay vi tri xem chi tiet
		detail[j].l = 730;
		detail[j].t = text_top;
		detail[j].r = 790;
		detail[j].b= text_top + 22;
		j++;
		// vi tri delete
		_delete[d].l = 905;
		_delete[d].t = text_top;
		_delete[d].r = 948;
		_delete[d].b = text_top + 22;
		d++;
		//vi tri edit
		edit[e].l = 810;
		edit[e].t = text_top;
		edit[e].r = 888;
		edit[e].b = text_top + 22;
		e++;
		bar3d(0, bar_top, 1000, bar_bottom, 1, 1);
		outtextxy(5, text_top, ds[i].msp);
		outtextxy(60, text_top, ds[i].ten);
		outtextxy(261, text_top, ds[i].gia);
		outtextxy(400, text_top, ds[i].can_nang);
		outtextxy(560, text_top, ds[i].hsd);
		normal_box(730, text_top, 790, text_top + 22, CURD_O[2], f_ds, 1, 4,1);
		normal_box(810, text_top, 888, text_top + 22, CURD_O[0], f_ds, 1, 2,1);
		normal_box(905, text_top, 948, text_top + 22, CURD_O[1], f_ds, 1, 6,1);
		setfillstyle(1, 15);
		setbkcolor(15);
	}
	detail[0].n = j;
	_delete[0].n = d;
	edit[0].n = e;

	// < >
	
	navigation_page(view_page);
}
void show_detail_product(char name_comp[][20], product p) {
	delete_after_main();
	setfillstyle(1, 7);
	setbkcolor(7);
	settextstyle(f_vua, 0, 1);
	bar3d(100, 150, 900, 510,0,0);
	// thanh phan
	setcolor(5);
	outtextxy(130, 180,name_comp[0]); //msp
	outtextxy(130, 220, name_comp[1]);//ten
	outtextxy(130, 260, name_comp[6]);//gia
	outtextxy(130,300, name_comp[2]);// phan loai
	outtextxy(130, 340, name_comp[3]);//can nang
	outtextxy(380, 340, name_comp[9]);//so luong
	outtextxy(130, 380, name_comp[8]);// nha san xuat
	outtextxy(130, 420, name_comp[7]);// ngay san xuat
	outtextxy(130, 460, name_comp[4]); // hsd
	setcolor(0);
	// :
	char x[] = { ":" };
	outtextxy(170, 180, x);
	outtextxy(170, 220, x);
	outtextxy(230, 260, x);
	outtextxy(165, 300, x);
	outtextxy(225, 340, x);
	outtextxy(470, 340, x);
	outtextxy(265, 380, x);
	outtextxy(265, 420, x);
	outtextxy(255, 460, x);
	// ten

	outtextxy(185, 180, p.msp);
	outtextxy(185, 220, p.ten);
	outtextxy(240, 260, p.pl);
	outtextxy(180, 300, p.gia);
	outtextxy(240, 340, p.can_nang);
	outtextxy(485, 340,p.sl);//so luong
	outtextxy(275, 380, p.nha_sx);
	outtextxy(275, 420, p.nsx);
	outtextxy(270, 460, p.hsd);
	// tro ve
	setfillstyle(1,11);
	setbkcolor(11);
	bar(400, 530, 571, 570);
	char back[] = { "Tro ve" };
	outtextxy(450, 542, back);
}
// UI add product
void UI_add_p(char name_comp[][20]) {
	delete_after_main();
	setfillstyle(1, 7);
	bar(100, 120, 790, 580);
	setbkcolor(7);
	outtextxy(130, 140, name_comp[1]);//ten
	outtextxy(130, 195, name_comp[6]);//phan loai
	outtextxy(130, 250, name_comp[2]);// gia
	outtextxy(130, 305, name_comp[3]);//can nang
	outtextxy(130, 360, name_comp[9]);//so luong
	outtextxy(130, 415, name_comp[8]);// nha san xuat
	outtextxy(130, 470, name_comp[7]);// ngay san xuat
	outtextxy(130, 525, name_comp[4]); // hsd
	setfillstyle(1, 15);
	
		// bar 
		bar3d(320, 135, 750, 160, 0, 0);
		bar3d(320, 190, 410, 215, 0, 0);
		char x[2][12] = { "TP,TC,GD","/" };
		outtextxy(430, 190, x[0]);
		bar3d(320, 245, 750, 270, 0, 0);
		bar3d(320, 300, 750, 325, 0, 0);
		bar3d(320, 355, 750, 380, 0, 0);
		bar3d(320, 410, 750, 435, 0, 0);
		//nsx
		bar3d(320, 465, 370, 490, 0, 0);
		settextstyle(f_vua, 0, 3);
		outtextxy(378, 466, x[1]);
		bar3d(400, 465, 450, 490, 0, 0);
		outtextxy(458, 466, x[1]);
		bar3d(480, 465, 560, 490, 0, 0);
		//hsd
		bar3d(320, 520, 370, 545, 0, 0);
		settextstyle(f_vua, 0, 3);
		outtextxy(378, 521, x[1]);
		bar3d(400, 520, 450, 545, 0, 0);
		outtextxy(458, 521, x[1]);
		bar3d(480, 520, 560, 545, 0, 0);
	
	
	char func[2][10] = { "Huy", "Luu" };
	normal_box(815, 520, 890, 550, func[0], f_vua, 1, 20,6);
	normal_box(900, 520, 975, 550, func[1], f_vua, 1, 20, 6);
}
void UI_edit_p(char name_comp[][20],product p) {
	delete_after_main();
	setfillstyle(1, 7);
	settextstyle(f_vua, 0, 1);
	bar(100, 120, 790, 580);
	setbkcolor(7);
	outtextxy(130, 140, name_comp[1]);//ten
	outtextxy(130, 195, name_comp[6]);//phan loai
	outtextxy(130, 250, name_comp[2]);// gia
	outtextxy(130, 305, name_comp[3]);//can nang
	outtextxy(130, 360, name_comp[9]);//so luong
	outtextxy(130, 415, name_comp[8]);// nha san xuat
	outtextxy(130, 470, name_comp[7]);// ngay san xuat
	outtextxy(130, 525, name_comp[4]); // hsd
	setfillstyle(1, 15);
	// bar 
	bar3d(320, 135, 750, 160, 0, 0);
	bar3d(320, 190, 410, 215, 0, 0);
	char x[2][12] = { "TP,TC,GD","/" };
	outtextxy(430, 190, x[0]);
	bar3d(320, 245, 750, 270, 0, 0);//
	bar3d(320, 300, 750, 325, 0, 0);//
	bar3d(320, 355, 750, 380, 0, 0);//
	
	bar3d(320, 410, 750, 435, 0, 0); //nha sx
	//nsx
	bar3d(320, 465, 370, 490, 0, 0);
	settextstyle(f_vua, 0, 3);
	outtextxy(378, 466, x[1]);
	bar3d(400, 465, 450, 490, 0, 0);
	outtextxy(458, 466, x[1]);
	bar3d(480, 465, 560, 490, 0, 0);
	//hsd
	bar3d(320, 520, 370, 545, 0, 0);
	settextstyle(f_vua, 0, 3);
	outtextxy(378, 521, x[1]);
	bar3d(400, 520, 450, 545, 0, 0);
	outtextxy(458, 521, x[1]);
	bar3d(480, 520, 560, 545, 0, 0);
	//
	setbkcolor(15);
	settextstyle(f_ds, 0, 1);
	outtextxy(322, 137, p.ten);
	outtextxy(322, 192, p.pl);
	string gia = p.gia;
	gia.erase(gia.end() - 1);
	char c_gia[12];
	strcpy_s(c_gia, gia.c_str());
	outtextxy(322, 247, c_gia);

	outtextxy(322, 357, p.sl);

	string cn = p.can_nang;
	cn.erase(cn.end() - 1);
	char c_cn[12];
	strcpy_s(c_cn, cn.c_str());
	outtextxy(322, 302, c_cn);
	outtextxy(322, 412, p.nha_sx);
	//nsx 
	vector <string> arr1;
	string value = p.nsx;
	split('/', value, arr1);
	char sd[4], sm[4], sy[6];
	strcpy_s(sd, arr1[0].c_str());
	strcpy_s(sm, arr1[1].c_str());
	strcpy_s(sy, arr1[2].c_str());
	outtextxy(322, 467, sd);
	outtextxy(402, 467, sm);
	outtextxy(482, 467, sy);
	//hsd
	vector <string> arr2;
	string value1 = p.hsd;
	split('/', value1, arr2);
	char dd[4], dm[4], dy[8];
	strcpy_s(dd, arr2[0].c_str());
	strcpy_s(dm, arr2[1].c_str());
	strcpy_s(dy, arr2[2].c_str());
	outtextxy(322,522, dd);
	outtextxy(402, 522, dm);
	outtextxy(482, 522, dy);

	char func[2][10] = { "Huy", "Luu" };
	normal_box(815, 520, 890, 550, func[0], f_vua, 1, 20, 6);
	normal_box(900, 520, 975, 550, func[1], f_vua, 1, 20, 6);
}
// staff page
void staff_table(
	char product_header[][20],
	vector <staff>& ds,
	char CURD_O[][20],
	view_page& view_page,
	check_CURD detail[],
	check_CURD edit[],
	check_CURD _delete[]
) {
	//chuc nang khac
	char text_func[][15] = { "Them nhan vien" };
	normal_box(60, 115, 240, 145, text_func[0], f_vua, 1, 10, 6);
	// tnh so page co trong trang
	int n = ds.size();
	int page = n / 9;
	int du = n % 9;
	view_page.page = du ? page + 1 : page;
	cout << "page: " << view_page.page << endl;
	int max_page = n > (9 * view_page.current) ? (9 * view_page.current) : n;
	// reder page
	int i = 9 * (view_page.current - 1);
	//header
	int bar_top = 155, bar_bottom = 185;
	int text_top = 160;
	setfillstyle(1, 6);
	setbkcolor(6);
	settextstyle(f_ds, 0, 1);
	bar3d(0, bar_top, 1000, bar_bottom, 1, 1);
	outtextxy(5, 160, product_header[0]);
	outtextxy(60, 160, product_header[1]);
	outtextxy(261, 160, product_header[2]);
	outtextxy(460, 160, product_header[3]);
	outtextxy(590, 160, product_header[4]);
	outtextxy(738, 160, product_header[5]);
	setfillstyle(1, 15);
	setbkcolor(15);
	int j = 0; //detail
	int d = 0;//delete
	int e = 0;//edit
	for (; i < max_page; i++)
	{
		if (i % 9 == 0) {
			bar_top += 30;
			bar_bottom += 40;
			text_top += 35;
		}
		else {
			bar_top += 40;
			bar_bottom += 40;
			text_top += 40;
		}

		//lay vi tri xem chi tiet
		detail[j].l = 730;
		detail[j].t = text_top;
		detail[j].r = 790;
		detail[j].b = text_top + 22;
		j++;
		// vi tri delete
		_delete[d].l = 905;
		_delete[d].t = text_top;
		_delete[d].r = 948;
		_delete[d].b = text_top + 22;
		d++;
		//vi tri edit
		edit[e].l = 810;
		edit[e].t = text_top;
		edit[e].r = 888;
		edit[e].b = text_top + 22;
		e++;
		bar3d(0, bar_top, 1000, bar_bottom, 1, 1);
		outtextxy(5, text_top, ds[i].mnv);
		outtextxy(60, text_top, ds[i].ten);
		outtextxy(261, text_top, ds[i].mail);
		outtextxy(460, text_top, ds[i].sdt);
		outtextxy(590, text_top, ds[i].t_l_v);
		normal_box(730, text_top, 790, text_top + 22, CURD_O[2], f_ds, 1, 4, 1);
		normal_box(810, text_top, 888, text_top + 22, CURD_O[0], f_ds, 1, 2, 1);
		normal_box(905, text_top, 948, text_top + 22, CURD_O[1], f_ds, 1, 6, 1);
		setfillstyle(1, 15);
		setbkcolor(15);
	}
	detail[0].n = j;
	_delete[0].n = d;
	edit[0].n = e;

	// < >

	/*string s = to_string(view_page.current);
	char num_p[2];
	strcpy_s(num_p, s.c_str());
	setbkcolor(8);
	settextstyle(f_vua, 0, 2);
	outtextxy(477, 555, num_p);
	char a[] = "<";
	char b[] = ">";
	if (view_page.page > view_page.current && view_page.page > 1) {
		setbkcolor(11);
		settextstyle(f_vua, 0, 3);
		outtextxy(450, 555, a);
		outtextxy(500, 555, b);
	}
	else if (view_page.page <= view_page.current) {
		settextstyle(f_vua, 0, 3);
		setbkcolor(11);
		outtextxy(450, 555, a);

	}*/
	navigation_page(view_page);

}
void UI_add_staff(char name_comp[][20]) {
	delete_after_main();
	settextstyle(f_vua, 0, 1);
	setfillstyle(1, 7);
	bar(80, 120, 790, 580);
	setbkcolor(7);
	outtextxy(110, 160, name_comp[1]);//ten
	outtextxy(110, 215, name_comp[7]);//ngay sinh
	outtextxy(110, 270, name_comp[3]);// sdt
	outtextxy(110, 325, name_comp[2]);//mail
	outtextxy(110, 380, name_comp[8]);//cccd
	outtextxy(110, 435, name_comp[4]);// tlv
	outtextxy(110, 490, name_comp[6]);// dc
	setfillstyle(1, 15);

	//ten
	bar3d(320, 155, 750, 180, 0, 0);
	//ngay sinh
	char x[][2] = { "/" };
	bar3d(320, 210, 370, 235, 0, 0);
	settextstyle(f_vua, 0, 3);
	outtextxy(378, 211, x[0]);
	bar3d(400, 210, 450, 235, 0, 0);
	outtextxy(458, 211, x[0]);
	bar3d(480, 210, 560, 235, 0, 0);
	//sdt
	bar3d(320, 265, 750, 290, 0, 0);
	//mail
	bar3d(320, 320, 750, 345, 0, 0);
	//cccd
	bar3d(320, 375, 750, 400, 0, 0);
	//tlv
	bar3d(320, 430, 750, 455, 0, 0);
	//dia chi
	bar3d(320, 485, 750, 510, 0, 0);

	char func[2][10] = { "Huy", "Luu" };
	normal_box(815, 520, 890, 550, func[0], f_vua, 1, 20, 6);
	normal_box(900, 520, 975, 550, func[1], f_vua, 1, 20, 6);
}
void UI_edit_staff(char name_comp[][20],staff s) {
	delete_after_main();
	settextstyle(f_vua, 0, 1);
	setfillstyle(1, 7);
	bar(80, 120, 790, 580);
	setbkcolor(7);
	outtextxy(110, 160, name_comp[1]);//ten
	outtextxy(110, 215, name_comp[7]);//ngay sinh
	outtextxy(110, 270, name_comp[3]);// sdt
	outtextxy(110, 325, name_comp[2]);//mail
	outtextxy(110, 380, name_comp[8]);//cccd
	outtextxy(110, 435, name_comp[4]);// tlv
	outtextxy(110, 490, name_comp[6]);// dc
	setfillstyle(1, 15);
	//ten
	bar3d(320, 155, 750, 180, 0, 0);
	//ngay sinh
	char x[][2] = { "/" };

	bar3d(320, 210, 370, 235, 0, 0);
	settextstyle(f_vua, 0, 3);
	outtextxy(378, 211, x[0]);
	bar3d(400, 210, 450, 235, 0, 0);
	outtextxy(458, 211, x[0]);
	bar3d(480, 210, 560, 235, 0, 0);
	//sdt
	bar3d(320, 265, 750, 290, 0, 0);
	//mail
	bar3d(320, 320, 750, 345, 0, 0);
	//cccd
	bar3d(320, 375, 750, 400, 0, 0);
	//tlv
	bar3d(320, 430, 750, 455, 0, 0);
	//dia chi
	bar3d(320, 485, 750, 510, 0, 0);
	//
	setbkcolor(15);
	settextstyle(f_ds, 0, 1);
	string ns = s.ntns;
	vector <string> v_ns;
	split('/', ns, v_ns);
	char ns_d[3], ns_m[3], ns_y[5];
	strcpy_s(ns_d, v_ns[0].c_str());
	strcpy_s(ns_m, v_ns[1].c_str());
	strcpy_s(ns_y, v_ns[2].c_str());
	outtextxy(322, 157, s.ten);
	outtextxy(322, 212, ns_d);
	outtextxy(402, 212, ns_m);
	outtextxy(482, 212, ns_y);
	outtextxy(322, 267, s.sdt);
	outtextxy(322, 322, s.mail);
	outtextxy(322, 377, s.cccd);
	outtextxy(322, 432, s.t_l_v);
	outtextxy(322, 487, s.dia_chi);
	char func[2][10] = { "Huy", "Luu" };
	normal_box(815, 520, 890, 550, func[0], f_vua, 1, 20, 6);
	normal_box(900, 520, 975, 550, func[1], f_vua, 1, 20, 6);
}
void show_deatil_staff(char name_comp[][20], staff p) {
	delete_after_main();
	setfillstyle(1, 7);
	setbkcolor(7);
	settextstyle(f_vua, 0, 1);
	bar3d(100, 150, 900, 510, 0, 0);

	// thanh phan
	setcolor(5);
	outtextxy(130, 180, name_comp[0]); //mnv
	outtextxy(130, 220, name_comp[1]);//ten
	outtextxy(130, 260, name_comp[7]);// ngay sinh
	outtextxy(130, 300, name_comp[3]);// sdt
	outtextxy(130, 340, name_comp[2]);//mail
	outtextxy(130, 380, name_comp[8]);//cccd
	outtextxy(130, 420, name_comp[4]);// tlv
	outtextxy(130, 460, name_comp[6]); // dia chi
	setcolor(0);
	// :
	char x[] = { ":" };
	outtextxy(170, 180, x);
	outtextxy(170, 220, x);
	outtextxy(238, 260, x);
	outtextxy(165, 300, x);
	outtextxy(180, 340, x);
	outtextxy(180, 380, x);
	outtextxy(335, 420, x);
	outtextxy(215, 460, x);
	// ten
	outtextxy(185, 180, p.mnv);
	outtextxy(185, 220, p.ten);
	outtextxy(248, 260, p.ntns);
	outtextxy(180, 300, p.sdt);
	outtextxy(190, 340, p.mail);
	outtextxy(190, 380, p.cccd);
	outtextxy(345, 420, p.t_l_v);
	outtextxy(225, 460, p.dia_chi);
	// tro ve
	setfillstyle(1, 11);
	setbkcolor(11);
	bar(400, 530, 571, 570);
	char back[] = { "Tro ve" };
	outtextxy(450, 542, back);
}
bool check_push_staff(vector <staff> s, staff temp,int index) {
	cout <<"indenx " << index;
	for (int i = 0; i < s.size(); i++)
	{
		if (i==index) {
			cout << "pass";
			i++;
			continue;
		}
		string c1 = s[i].mail, c2 = s[i].cccd, c3 = s[i].sdt;
		string z1 = temp.mail, z2 = temp.cccd, z3 = temp.sdt;
		if (c1==z1 || c2==z2|| c3==z3) {
			return false;
		}
	}
	return true;
}
//buy page
void buy_table(
	char product_header[][20],
	vector <product>& ds,
	char CURD_O[][20],
	view_page& view_page,
	check_CURD detail[],
	vector <buy_product> &buy_p,
	check_CURD  left_arrow[],
	check_CURD right_arrow[]

)
{	//chuc nang khac
	char text_func[3][30] = { "Top 10 sp ban chay nhat","Hoa don trong ngay","Gio hang"};
	normal_box(60, 115, 340, 145, text_func[0], f_vua, 1, 10, 6);
	normal_box(363, 115, 590, 145, text_func[1], f_vua, 1, 10, 6);
	normal_box(865, 115, 975, 145, text_func[2], f_vua, 1, 10, 6);
	// tnh so page co trong trang

	int n = ds.size();
	int page = n / 9;
	int du = n % 9;
	view_page.page = du ? page + 1 : page;
	cout << "page: " << view_page.page << endl;
	int max_page = n > (9 * view_page.current) ? (9 * view_page.current) : n;
	// reder page
	int i = 9 * (view_page.current - 1);
	//header
	int bar_top = 155, bar_bottom = 185;
	int text_top = 160;
	setfillstyle(1, 6);
	setbkcolor(6);
	settextstyle(f_ds, 0, 1);
	bar3d(0, bar_top, 1000, bar_bottom, 1, 1);
	outtextxy(5, 160, product_header[0]);
	outtextxy(60, 160, product_header[1]);
	outtextxy(261, 160, product_header[2]);
	outtextxy(400, 160, product_header[9]);
	outtextxy(560, 160, product_header[4]);
	outtextxy(738, 160, product_header[5]);
	setfillstyle(1, 15);
	setbkcolor(15);
	int j = 0; //detail
	int l_b = 0; //left
	int r_b = 0; //right

	for (; i < max_page; i++)
	{
		if (i % 9 == 0) {
			bar_top += 30;
			bar_bottom += 40;
			text_top += 35;
		}
		else {
			bar_top += 40;
			bar_bottom += 40;
			text_top += 40;
		}

		//lay vi tri xem chi tiet
		detail[j].l = 730;
		detail[j].t = text_top;
		detail[j].r = 790;
		detail[j].b = text_top + 22;
		j++;
		// left_arrow
		left_arrow[l_b].l = 810;
		left_arrow[l_b].t = text_top;
		left_arrow[l_b].r = 825;
		left_arrow[l_b].b = text_top+22;
		l_b++;
		//right_arrow
		right_arrow[r_b].l = 875;
		right_arrow[r_b].t = text_top;
		right_arrow[r_b].r = 890;
		right_arrow[r_b].b = text_top + 22;
		r_b++;

		bar3d(0, bar_top, 1000, bar_bottom, 1, 1);
		outtextxy(5, text_top, ds[i].msp);
		outtextxy(60, text_top, ds[i].ten);
		outtextxy(261, text_top, ds[i].gia);
		outtextxy(400, text_top, ds[i].sl);
		outtextxy(560, text_top, ds[i].hsd);
		normal_box(730, text_top, 790, text_top + 22, CURD_O[2], f_ds, 1, 4, 1);
		char symboy[][3] = {"<",">","00"};
		char sl_b[3];
		normal_box(810, text_top, 825, text_top + 22, symboy[0], f_ds, 1, 2, 1);
		buy_p[i].index = i;
		if (buy_p[i].sl==0) {
			normal_box(835, text_top, 865, text_top + 22, symboy[2], f_ds, 1, 6, 1);
		}
		else {
			strcpy_s(sl_b, format_num(to_string(buy_p[i].sl)).c_str());
			normal_box(835, text_top, 865, text_top + 22, sl_b, f_ds, 1, 6, 1);

		}
		normal_box(875, text_top, 890, text_top + 22, symboy[1], f_ds, 1, 3, 1);
		setfillstyle(1, 15);
		setbkcolor(15);
	}
	detail[0].n = j;
	left_arrow[0].n = l_b;
	right_arrow[0].n = r_b;
	// < >
	navigation_page(view_page);
	char text_buy[20] = { "Mua san pham" };
	normal_box(730, 550, 890, 585, text_buy, f_vua, 1, 12, 8);
}
void UI_card(char product_header[][20], vector <buy_product> num_buy, vector <product> ds, view_page& view_page) {
	delete_after_main();
	char back[] = { "Tro ve" };
	normal_box(865, 140, 950, 170, back, f_vua, 1, 8, 6);
	setfillstyle(1, 6);
	setbkcolor(6);
	settextstyle(f_ds, 0, 1);
	int text_top = 145;
	int bar_top = 140, bar_bottom = 170;
	bar3d(180, bar_top, 770, bar_bottom, 0, 0);
	outtextxy(185, text_top, product_header[0]);
	outtextxy(280, text_top, product_header[1]);
	outtextxy(630, text_top, product_header[9]);
	setfillstyle(1, 15);
	setbkcolor(15);
	vector <product> temp;
	for (int i = 0; i < ds.size(); i++)
	{
		
		if (num_buy[i].sl != 0) {
			product t;
			t = ds[i];
			strcpy_s(t.sl,to_string(num_buy[i].sl).c_str());
			temp.push_back(t);
		}
	}
	int n = temp.size();
	int page = n / 12;
	int du = n % 12;
	view_page.page = du ? page + 1 : page;
	int max_page = n > (12 * view_page.current) ? (12 * view_page.current) : n;
	int i = 12 * (view_page.current - 1);
	for (; i < max_page; i++)
	{
			bar_top += 30;
			bar_bottom += 30;
			text_top += 30;
			bar3d(180, bar_top, 770, bar_bottom, 0, 0);
			outtextxy(185, text_top, temp[i].msp);
			outtextxy(280, text_top, temp[i].ten);
			outtextxy(630, text_top, temp[i].sl);
	}
	string s = to_string(view_page.current);
	char num_p[2];
	strcpy_s(num_p, s.c_str());
	setbkcolor(8);
	settextstyle(f_vua, 0, 2);
	outtextxy(477, 555, num_p);
	char a[] = "<";
	char b[] = ">";
	if (view_page.page > view_page.current && view_page.page > 1) {
		setbkcolor(11);
		settextstyle(f_vua, 0, 3);
		outtextxy(450, 555, a);
		outtextxy(500, 555, b);
	}
	else {
		setbkcolor(11);
		outtextxy(450, 555, a);
	}
}
void bill(int &code_bill , view_page& view_page, vector <buy_product> &num_buy, vector <product> ds) {
	delete_after_main();
	setfillstyle(1, 7);
	setbkcolor(7);
	settextstyle(f_ds, 0, 1);
	bar3d(150, 140, 800, 540, 0, 0);
	char st[][20] = {"Bach Hoa Xanh","Thoi gian","MNV","MSP","Ten","SL","Gia","Tien nhan","Tien thoi","Tong cong","MHD"};
	outtextxy(410, 155, st[0]);
	outtextxy(180, 180, st[1]);
	outtextxy(455, 180, st[10]);
	char mhd[4] ;
	strcpy_s(mhd, to_string(code_bill).c_str());
	outtextxy(500, 180, mhd);
	char date[20];
	strcpy_s(date, getDate().c_str());
	outtextxy(250, 180, date);
	// luu ma hoa don ,date o index 0
	strcpy_s(num_buy[0].mhd, to_string(code_bill).c_str());
	strcpy_s(num_buy[0].date, date);
	code_bill++;
	srand(time(NULL));
	int iSecret;
	iSecret = rand() % 10 + 1;
	char mnv[4];
	strcpy_s(mnv, to_string(iSecret).c_str());
	outtextxy(680, 180, mnv);
	outtextxy(640, 180, st[2]);
	outtextxy(180, 215, st[3]);
	outtextxy(300, 215, st[4]);
	outtextxy(500, 215, st[5]);
	outtextxy(640, 215, st[6]);
	int top = 250;
	vector <product> temp;

	for (int i = 0; i < num_buy.size(); i++)
	{
		if (num_buy[i].sl != 0) {
			product t;
			t = ds[i];
			strcpy_s(t.sl, to_string(num_buy[i].sl).c_str());
			temp.push_back(t);
		}
	}
	int n = temp.size();
	int page = n / 5;
	int du = n % 5;
	view_page.page = du ? page + 1 : page;
	int max_page = n > (5 * view_page.current) ? (5 * view_page.current) : n;
	int i = 5 * (view_page.current - 1);
	double total = 0;
	for (; i <max_page ; i++)
	{
		outtextxy(180, top, temp[i].msp);
		outtextxy(300, top, temp[i].ten);
		outtextxy(500, top, temp[i].sl);
		outtextxy(640, top, temp[i].gia);
		top += 35;
	}
	if (view_page.current == view_page.page) {
		for (int i = 0; i < temp.size(); i++)
		{
			string gia = temp[i].gia;
			double a = stof(gia);
			gia.erase(gia.end()-1);
			total += (atoi(temp[i].sl)*a);
		}
		outtextxy(550, top, st[9]);
		char tc[20];
		string t = to_string(total);
		t.erase(t.length() - 4);
		strcpy_s(tc, t.c_str());
		outtextxy(640, top, tc);
		char tn[10]={"10000"};
		outtextxy(640, top + 35,tn );
		outtextxy(550, top + 35, st[7]);
		char tt[10];
		string s_tt = to_string(atoi(tn) - stof(t));
		s_tt.erase(s_tt.length() - 4);
		strcpy_s(tt, s_tt.c_str());
		outtextxy(640, top + 35 * 2, tt);
		outtextxy(550, top + 35 * 2, st[8]);
	}
	string s = to_string(view_page.current);
	char num_p[2];
	strcpy_s(num_p, s.c_str());
	setbkcolor(8);
	settextstyle(f_vua, 0, 2);
	outtextxy(477, 555, num_p);
	char a[] = "<";
	char b[] = ">";
	if (view_page.current == 1 && view_page.page > view_page.current) {
		setbkcolor(11);
		settextstyle(f_vua, 0, 3);
		outtextxy(500, 555, b);
	}
	else if (view_page.current == 1) {
		setbkcolor(11);
		settextstyle(f_vua, 0, 3);
	}
	else if (view_page.page == view_page.current) {
		settextstyle(f_vua, 0, 3);
		setbkcolor(11);
		outtextxy(450, 555, a);
	}
	else if (view_page.page > 1) {
		settextstyle(f_vua, 0, 3);
		setbkcolor(11);
		outtextxy(450, 555, a);
		outtextxy(500, 555, b);
	}
	char back[] = { "Tro ve" };
	normal_box(865, 510, 950, 540, back, f_vua, 1, 8, 6);

}
void UI_top10(vector <product> sold, check_CURD d_top10[]) {
	delete_after_main();
	char text[][30] = { "Top 10 san pham ban chay nhat","STT","MSP","Ten","SL","Chi tiet"};
	setfillstyle(1, 7);
	setbkcolor(7);
	settextstyle(f_lon, 0, 1);
	bar3d(150, 140, 800, 540, 0, 0);
	setcolor(4);
	outtextxy(290, 150, text[0]);
	setcolor(0);
	settextstyle(f_ds, 0, 1);
	int text_top = 180;
	int bar_top = 175, bar_bottom = 205;
	setfillstyle(1, 9);
	setbkcolor(9);
	bar3d(150, bar_top, 800, bar_bottom, 0, 0);
	outtextxy(170, text_top, text[1]);
	outtextxy(240, text_top, text[2]);
	outtextxy(340, text_top, text[3]);
	outtextxy(580, text_top, text[4]);
	setfillstyle(1, 7);
	setbkcolor(7);
	int max_list = sold.size() >= 10 ? 10 : sold.size();
	d_top10[0].n = max_list;
	for (int i = 0 ; i < max_list; i++)
	{
		text_top += 30;
		bar_top += 30;
		bar_bottom += 30;
		d_top10[i].l= 730,
		d_top10[i].t= bar_top + 3,
		d_top10[i].r= 790,
		d_top10[i].b= bar_bottom - 3,
		bar3d(150, bar_top, 800, bar_bottom, 0, 0);
		char x[4];
		strcpy_s(x, to_string(i+1).c_str());
		outtextxy(170, text_top, x);
		outtextxy(240, text_top, sold[i].msp);
		outtextxy(340, text_top, sold[i].ten);
		outtextxy(580, text_top, sold[i].sl);
		normal_box(730, bar_top + 3, 790, bar_bottom - 3, text[5], f_ds,1, 4, 1);
		setfillstyle(1, 7);
		setbkcolor(7);

	}
	char back[] = { "Tro ve" };
	normal_box(865, 510, 950, 540, back, f_vua, 1, 8, 6);
}
void UI_list_bill(vector <list_bill> lb, check_CURD detail[], view_page& view_page) {
	delete_after_main();
	char text[][40] = { "Danh sach hoa don ban duoc trong ngay","Thoi gian","Ma hoa don","Chi tiet san pham","Xem chi tiet"};
	setfillstyle(1, 7);
	setbkcolor(7);
	settextstyle(f_lon, 0, 1);
	bar3d(150, 140, 800, 535, 0, 0);
	setcolor(4);
	outtextxy(230, 150, text[0]);
	setcolor(0);
	settextstyle(f_ds, 0, 1);
	int text_top = 180;
	int bar_top = 175, bar_bottom = 205;
	setfillstyle(1, 9);
	setbkcolor(9);
	bar3d(150, bar_top, 800, bar_bottom, 0, 0);
	outtextxy(170, text_top, text[1]);
	outtextxy(360, text_top, text[2]);
	outtextxy(520, text_top, text[3]);
	setfillstyle(1, 7);
	setbkcolor(7);
	int n = lb.size();
	int page = n / 11;
	int du = n % 11;
	view_page.page = du ? page + 1 : page;
	int max_page = n > (11 * view_page.current) ? (11* view_page.current) : n;
	int i = 11 * (view_page.current - 1);
	int d = 0;
	for (; i < max_page; i++)
	{
		text_top += 30;
		bar_top += 30;
		bar_bottom += 30;
		detail[d].l = 535;
		detail[d].t = bar_top + 3;
		detail[d].r = 630;
		detail[d].b = bar_bottom - 3;
		d++;
		bar3d(150, bar_top, 800, bar_bottom, 0, 0);
		outtextxy(170, text_top, lb[i].date);
		outtextxy(360, text_top, lb[i].mhd);
		normal_box(535, bar_top + 3, 630, bar_bottom - 3, text[4], f_ds, 1, 4, 1);
		setfillstyle(1, 7);
		setbkcolor(7);
	}
	detail[0].n = d;

	string s = to_string(view_page.current);
	char num_p[2];
	strcpy_s(num_p, s.c_str());
	setbkcolor(8);
	settextstyle(f_vua, 0, 2);
	outtextxy(477, 555, num_p);
	char a[] = "<";
	char b[] = ">";
	if (view_page.current == 1 && view_page.page > view_page.current) {
		setbkcolor(11);
		settextstyle(f_vua, 0, 3);
		outtextxy(500, 555, b);
	}
	else if (view_page.current == 1) {
		setbkcolor(11);
		settextstyle(f_vua, 0, 3);
	}
	else if (view_page.page == view_page.current) {
		settextstyle(f_vua, 0, 3);
		setbkcolor(11);
		outtextxy(450, 555, a);
	}
	else if (view_page.page > 1) {
		settextstyle(f_vua, 0, 3);
		setbkcolor(11);
		outtextxy(450, 555, a);
		outtextxy(500, 555, b);
	}
	char back[] = { "Tro ve" };
	normal_box(865, 510, 950, 540, back, f_vua, 1, 8, 6);
}
void UI_detail_list(char product_header[][20], vector <product> ds, view_page& view_page, check_CURD detail[]) {
	char CURD_O[][20] = { "Chi tiet" };
	// tnh so page co trong trang
	int n = ds.size();
	int page = n / 9;
	int du = n % 9;
	view_page.page = du ? page + 1 : page;
	cout << "page: " << view_page.page << endl;
	int max_page = n > (9 * view_page.current) ? (9 * view_page.current) : n;
	// reder page
	int i = 9 * (view_page.current - 1);
	//header
	int bar_top = 155, bar_bottom = 185;
	int text_top = 160;
	setfillstyle(1, 6);
	setbkcolor(6);
	settextstyle(f_ds, 0, 1);
	bar3d(0, bar_top, 1000, bar_bottom, 1, 1);
	outtextxy(5, 160, product_header[0]);
	outtextxy(60, 160, product_header[1]);
	outtextxy(261, 160, product_header[2]);
	outtextxy(400, 160, product_header[3]);
	outtextxy(560, 160, product_header[4]);
	outtextxy(738, 160, product_header[5]);
	setfillstyle(1, 15);
	setbkcolor(15);
	int j = 0; //detail
	for (; i < max_page; i++)
	{
		if (i % 9 == 0) {
			bar_top += 30;
			bar_bottom += 40;
			text_top += 35;
		}
		else {
			bar_top += 40;
			bar_bottom += 40;
			text_top += 40;
		}

		//lay vi tri xem chi tiet
		detail[j].l = 750;
		detail[j].t = text_top;
		detail[j].r = 810;
		detail[j].b = text_top + 22;
		j++;
		bar3d(0, bar_top, 1000, bar_bottom, 1, 1);
		outtextxy(5, text_top, ds[i].msp);
		outtextxy(60, text_top, ds[i].ten);
		outtextxy(261, text_top, ds[i].gia);
		outtextxy(400, text_top, ds[i].can_nang);
		outtextxy(560, text_top, ds[i].hsd);
		normal_box(750, text_top, 810, text_top + 22, CURD_O[0], f_ds, 1, 4, 1);
		setfillstyle(1, 15);
		setbkcolor(15);
	}
	detail[0].n = j;
	navigation_page(view_page);
	char back[] = { "Tro ve" };
	normal_box(740, 555, 820, 585, back, f_vua, 1, 8, 6);
}
bool kt_KTu(char x) {
	if (x >= 'a' && x <= 'z') {
		return true;
	}
	if (x >= 'A' && x <= 'Z') {
		return true;
	}
	else if (x >= '0' && x <= '9') {
		return true;
	}
	else if (x == '/' || x == '\\' || x == '@' || x == 8|| x==13 || x == ' '|| x=='.') {
		return true;
	}
	return false;
}
bool only_number(char x) {

	if (x >= '0' && x <= '9') {
		return true;
	}
	else if (x == 8 || x == 13) {
		return true;
	}
	return false;
}
bool decimal_number(char x) {

	if (x >= '0' && x <= '9') {
		return true;
	}
	else if (x == 8 || x == 13 || x=='.') {
		return true;
	}
	return false;
}
void navigation_page(view_page& view_page) {

	string s = to_string(view_page.current);
	char num_p[2];
	strcpy_s(num_p, s.c_str());
	setbkcolor(8);
	settextstyle(f_vua, 0, 2);
	
		outtextxy(477, 555, num_p);
		char a[] = "<";
		char b[] = ">";
		if (view_page.current == 1 && view_page.page > view_page.current) {
			setbkcolor(11);
			settextstyle(f_vua, 0, 3);
			outtextxy(500, 555, b);
		}
		else if (view_page.current == 1) {
			setbkcolor(11);
			settextstyle(f_vua, 0, 3);
		}
		else if (view_page.page == view_page.current) {
			settextstyle(f_vua, 0, 3);
			setbkcolor(11);
			outtextxy(450, 555, a);
		}
		else if (view_page.page > 1) {
			settextstyle(f_vua, 0, 3);
			setbkcolor(11);
			outtextxy(450, 555, a);
			outtextxy(500, 555, b);
		}
	
	
}
string input(int l, int t, int r, int b,int kcl,int kct,string value,int max_value, int o_num) {
	bool key_enter = false;
	string input = value;

	input += "_";
	char result[255]={};
	strcpy_s(result, input.c_str());
	outtextxy(l + kcl, t + kct, result);
	while (!key_enter) {
		
		char key = (char)getch();
		int z = o_num;		
		bool check_key;
		if (z == 1) {
			check_key =only_number(key);
		}
		else if (z==2) {
			check_key= decimal_number(key);
		}
		else {
			check_key=kt_KTu(key);
		}
		if (check_key) {
			if (key == 8) {// <- back
				if (input.length() == 1) {

				}
				else {
					input.erase(input.end() - 2);
				}
			}
			else if(key != 13) {
				if (input.length()==(max_value+1)) {
					string s = "Toi da chi co ";
					s += to_string(max_value);
					s += " ki tu.";
					char m[30];
					strcpy_s(m, s.c_str());
					setcolor(RED);
					setbkcolor(7);
					settextstyle(f_vua, 0, 1);
					outtextxy(l + kcl, t + 30, m);
					settextstyle(f_ds, 0, 1);
					setbkcolor(HIGHLIGHT_BOX);
					setcolor(0);
					continue;
				}
				input.erase(input.end() - 1);
				input += key;
				input += "_";
			}
			if (input.length() > 2) {
				// kiem tra 2 dau cach thi xoa
				int n = input.length();
				if ((input[n - 2] == input[n - 3]) && (input[n - 2] == ' ' || input[n - 2] == '.')) {
					input.erase(input.end() - 2);
				}
			}
			strcpy_s(result, input.c_str());
			setfillstyle(1, 7);
			bar(l + kcl, t+26, 780, b+22);// xoa canh bao
			setfillstyle(1,HIGHLIGHT_BOX);

			bar3d(l, t, r, b, 0, 0);
			outtextxy(l+kcl,t+kct, result);
			cout <<"input: " << input << endl;
			if (key == 13) {
				key_enter = true;
				input.erase(input.end() - 1);
				strcpy_s(result, input.c_str());
				cout << "result:"<<result;
				setfillstyle(1, 15);
				setbkcolor(15);
				bar3d(l, t, r, b, 0, 0);
				outtextxy(l + kcl, t + kct, result);
			}
		}
		else {
			cout << "ki tu k hop le" << endl;
		}
		delay(1);
	}
	return input;
}
void split(char x, string v, vector <string>& arr) {
	string temp = "";
	v = trim(v);
	for (int i = 0; i < v.length(); i++)
	{
		if (v[i] == x) {
			arr.push_back(temp);
			temp = "";
			continue;
		}
		temp += v[i];
	}
	arr.push_back(temp);
}
string format_num(string s) {
	if (s.length() == 1) {
		s = "0" + s;
	}
	return s;
}
bool check_day_month(int l, int t, int r, int b, int kcl, int kct, string day,string month,string year,int small_y) {
	int d = (day.length() > 0 ? stoi(day) : -1);
	int m = (month.length() > 0 ? stoi(month) : -1);
	int y = (year.length() > 0 ? stoi(year) : -1);
	string out ="";
	setfillstyle(1, 7);
	bar(l + kcl, t + 26, 780, b + 20);// xoa canh bao
	setfillstyle(1, HIGHLIGHT_BOX);
	cout << d << " " << m << endl;
	if (m == -1) {
		if ((d > 31 || d==-1) || d<=0) {
			cout << "Ngay chua hop le ";
			out = "Ngay chua hop le ";
			noti_input(l, t, r, b, kcl, kct, out);
			return false;
		}
	}
	else {
		if (m <= 12 && m > 0) {

			if ((m == 4 || m == 6 || m == 9 || m == 11 ) && d == 31) {
				out = "Thang chua hop le ";
				noti_input(l, t, r, b, kcl, kct, out);
				return false;
			}
			if (m==2 && (d==30||d==31)) {
				out = "Thang chua hop le ";
				noti_input(l, t, r, b, kcl, kct, out);
				return false;
			}
		}
		else {
			out = "Thang chua hop le ";
			noti_input(l, t, r, b, kcl, kct, out);
			return false;
		}
	}
	if (y != -1 && small_y==0) {
		if (y < 2011) {
			out = "Nam phai lon hon 2010 ";
			noti_input(l, t, r, b, kcl, kct, out);
			return false;
		}
		if (y>=2050) {
			out = "Nam phai < 2050";
			noti_input(l, t, r, b, kcl, kct,out);
			return false;
		}
	}
	if (y != -1 && small_y == 1) {
		if (y < 1960) {
			out = "Nam phai lon hon 1960 ";
			noti_input(l, t, r, b, kcl, kct, out);
			return false;
		}
		if (y >= 2023) {
			out = "Nam phai < 2023";
			noti_input(l, t, r, b, kcl, kct, out);
			return false;
		}
	}
	return true;

}
void push_product(vector <product>& ds, product temp) {
	int c = check_duplicate(ds, temp);
	
	if (c != -1) {
		int sl = stoi(temp.sl) + stoi(ds[c].sl);
		strcpy_s(ds[c].sl, to_string(sl).c_str());
	}
	else {
		int msp;
		if (ds.size() != 0) {
			msp = stoi(ds[ds.size() - 1].msp);
			msp++;
			strcpy_s(temp.msp, to_string(msp).c_str());
		}
		else {
			msp = 0;
		}
		ds.push_back(temp);

	}
}
int check_duplicate(vector <product>& ds,product p) {
	for (int i = 0; i < ds.size(); i++)
	{
		string s1 = ds[i].ten, s2 = ds[i].gia, s3 = ds[i].hsd, s4 = ds[i].nha_sx;
		string  z1 = p.ten, z2 = p.gia, z3 = p.hsd, z4 = p.nha_sx;
		if (s1 == z1 &&
			s2 ==z2&&
			s3 ==z3 &&
			s4 == z4
			) {
			return i;
		}
	}
	return -1;
}
int check_name(buy_product name_buy, vector <product> sold) {
	for (int i = 0; i < sold.size(); i++)
	{
		string c1 = name_buy.ten, c2 = sold[i].ten;
		string c3 = name_buy.msp, c4 = sold[i].msp;
		if (c1 ==c2 && c3==c4 ) {
			return i;
		}
	}
	return -1;
}
int check_empty_buy(vector <buy_product> buy) {
	for (int i = 0; i < buy.size(); i++)
	{
		if (buy[i].sl != 0) {
			return 1;
		}

	}
	return 0;
}
string to_upper(string s) {
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] -= 32;
			cout << s[i] << endl;
		}
	}
	return s;
}
string trim(string s) {
	int i = 0;
	if (s.length() == 0) return "";
	while (1) {
		if (s[i] == ' ') {
			s.erase(s.begin());
		}
		else {
			break;
		}
	}
	while (1) {
		if (s[s.length() - 1] == ' ') {
			s.erase(s.end() - 1);
		}
		else {
			break;
		}
	}
	return s;
}
string getDate() {
	time_t curr_time;
	curr_time = time(NULL);

	tm* ltm = localtime(&curr_time);
	int day = ltm->tm_mday;
	int month = 1 + ltm->tm_mon;
	int year = 1900 + ltm->tm_year;
	string time = to_string(ltm->tm_hour) + ":" +
		to_string(ltm->tm_min) + ":" 
		+to_string(ltm->tm_sec);
	string s = time+ " "+ to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	return s;
}
void noti_input(int l, int t, int r, int b, int kcl, int kct,string out) {
	char ou[255];
	strcpy_s(ou, out.c_str());
	setcolor(RED);
	setbkcolor(7);
	settextstyle(f_vua, 0, 1);
	outtextxy(l + kcl, t + 30, ou);
	settextstyle(f_ds, 0, 1);
	setbkcolor(HIGHLIGHT_BOX);
	setcolor(0);
}
void highlight_box(int l, int t, int r, int b, char s[], int font, int f_size, int kcl, int kct,int bg) {
	setcolor(0);
	settextstyle(font, 0, f_size);
	setfillstyle(1,bg );
	bar3d(l, t, r, b, 0, 0);
	setbkcolor(HIGHLIGHT_BOX);
	outtextxy(l + kcl, t + kct, s);
}
void setbkscreen() {
	setfillstyle(1, 8);
	bar(0, 0, 1000, 600);
}
void delete_after_main(){
	setfillstyle(1,8);
	bar(0,100,1000,600);
}
