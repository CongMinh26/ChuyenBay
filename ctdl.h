//#pragma once
#include <iostream>

#include <fstream>
#include <string>

#define MAXLIST 300
#define MAX_INPUT 255

#define MAX_PAGE 35
// 1800 <  NAM < 9999
const int MAX_NAM = 9999;
const int MIN_NAM = 1800;
const int MAX_DAY = 10;
const int MAX_DONG = 20;
const int KC_GIO = 5;
const int KC_GIOAM = 19;

using namespace std;

//struct may bay
struct maybay {
	char soHieuMayBay[20];
	char loaiMayBay[45];
	int soCho;

	//Chi so phu
	int soLuotThucHien = 0;

};
typedef struct maybay mayBay;

//struct ds may bay
struct list_MB {
	int n = 0;
	mayBay *MB[MAXLIST];

};
typedef struct list_MB LIST_MB;

//struct thoi gian
struct ThoiGian
{
	int gio;
	int phut;

	int ngay;
	int thang;
	int nam;
};
typedef struct ThoiGian THOI_GIAN;

// struct chuyen bay
struct ChuyenBay {
	char maChuyenBay[20];
	THOI_GIAN tgKhoiHanh;
	char sanBayDen[50];
	int trangThai;
	char soHieuMayBay[20];
	string *dsVe;
	int slVe; //slVe = soCho;
};
typedef struct ChuyenBay CHUYENBAY;

typedef struct NodeChuyenBay {
	CHUYENBAY data;
	struct NodeChuyenBay *next;
};
typedef struct NodeChuyenBay *PTRChuyenBay;

//struct hanh khach
struct HanhKhach {
	char CMND[21];
	char ho[31];
	char ten[11];
	int phai;
};
typedef struct HanhKhach HANHKHACH;

struct nodeHanhKhach {
	HANHKHACH data;
	struct nodeHanhKhach *Left;
	struct nodeHanhKhach *Right;
};
typedef struct nodeHanhKhach NodeHanhKhach;
typedef struct nodeHanhKhach *TREEHanhKhach;

struct NhapChuoi {
	int n = 0;
	char *data[MAX_INPUT];
};

//======Hang so GD======
const int soItem_MenuChinh = 7;
const int soItem_MenuMB = 4;
const int soItem_MenuCB = 5;
const int soItem_MenuDV = 3;

//=== To mau ====
void Normal();
void Highlight();
void Red_Highlight();
void Green_Highlight();

//======Ham Ve Khung Giao Dien======
void khungGiaoDien();

void khungGiaoDienEdit();
void fullScreen();
void khungThongBao();
void veKhungNhap(int dai, int rong, int posx, int posy, string source);
void hienThongBao(string notif, string notif2 = "", string notif3 = "", string NoiDen = "");
void hienHuongDan(int type);
void xoaKhungDS();
//======Menu Chon======
int menuDong_Prim(char td[soItem_MenuChinh][100]);

//======Ham Nhap======
void NhapMA(char var[], int len);
void NhapCHUOI(char var[], int len);
void NhapCHUOI_SO(char var[], int len);
void Nhap_SO(int& var, int len);
void NhapNGAY(int& var, int len);
void NhapTHANG(int& var, int len);
void NhapNAM(int& var, int len);
void NhapGIO(int& var, int len);
void NhapPHUT(int& var, int len);
void catChuoi(string chuoi, char splitChar, int& vtri, char cmnd[]);

// ==================================== check ham nhap ===================
char *CheckInputStr(bool nhapMa, int DongInfo);
int NameCmp(char* name1, char* name2);
THOI_GIAN CheckInputDate(THOI_GIAN& tg, int DongInfo);
int rangBuocThoiGian(THOI_GIAN tg);
THOI_GIAN CheckInputTime(THOI_GIAN& tg, int DongInfo);
char* CheckInputCMND(int DongInfo);
int rangBuocGio(THOI_GIAN h);
int checkTimeHienTai(THOI_GIAN tg);
int checkStatus_CB(CHUYENBAY cb);
void xoaThongTin(int type);
//============================================ May Bay========================================
int emptyMB(LIST_MB lstMB);
int fullMB(LIST_MB lstMB);
mayBay createMB(LIST_MB& lstMB);
int TimViTriThem(LIST_MB dsMB, mayBay addMAY_BAY);
int InsertOrderMB(LIST_MB& dsMB, mayBay addMAY_BAY);
int delete_MB(LIST_MB& lstMB, int i, PTRChuyenBay lstCB);
void show_MB(LIST_MB lstMB);
int search_MB(LIST_MB lstMB, char ma[]);
mayBay getMB(LIST_MB lstMB, char ma[]);
int hieuChinh_MB(LIST_MB& lstMB, int i);
void show_1_MB(LIST_MB lstMB, int chon, bool type, int dem);
void show_MB(LIST_MB lstMB);
void QLMB(LIST_MB& lstMB);

//=========================================== Chuyen Bay ===================================
int checkHoanTat_CB(PTRChuyenBay& lstCB);
void initCB(PTRChuyenBay& lstCB);
void initCB(PTRChuyenBay& lstCB);
int empty_CB(PTRChuyenBay lstCB);
CHUYENBAY createCB(PTRChuyenBay lstCB, LIST_MB lstMB);
void insert_OrderNodeCB(PTRChuyenBay& lstCB, CHUYENBAY cb);
int insertNodeCB(PTRChuyenBay& lstCB, CHUYENBAY cb);
PTRChuyenBay searchBin_CB(PTRChuyenBay lstCB, char ma[]);
int hieuChinh_CB(PTRChuyenBay& lstCB, PTRChuyenBay p, LIST_MB lstMB);
int xoa_CB(PTRChuyenBay& lstCB, char ma[]);
int huy_CB(PTRChuyenBay& lstCB, PTRChuyenBay p);
mayBay ChonMB_LapCB(LIST_MB lstMB);
void showCB(PTRChuyenBay lstCB);
void showCB_DatVe(PTRChuyenBay lstCB);
void show_1_CB_DatVe(CHUYENBAY* cb, int chon);
void showCB_ConVe(CHUYENBAY* p, int& i);
void show_1_CB(CHUYENBAY* cb, int chon);
void chuyenMang(PTRChuyenBay lstCB, CHUYENBAY* cb[], int& n, LIST_MB lstMB, int trangThai);
void QLCB(PTRChuyenBay& lstCB, LIST_MB& lstMB);

//======================Dat Huy Ve================

void show_1_Ve(int dsVe[], int cot, int dong, int chon, int kc);
int chonVe_HUY(PTRChuyenBay& lstCB, HANHKHACH hk);
PTRChuyenBay ChonCB_DatVe_HuyVe(PTRChuyenBay lstCB, int& chonCB, LIST_MB lstMB);
void DatHuyVe(PTRChuyenBay& lstCB, LIST_MB lstMB, TREEHanhKhach& lstHK);
void showCB_DatVe(PTRChuyenBay lstCB);
void show_1_CB_DatVe(CHUYENBAY* cb, int chon);
void chuyenMang(PTRChuyenBay lstCB, CHUYENBAY* cb[], int& n, LIST_MB lstMB, int trangThai);
int createDsVe(mayBay mb, string* lstVe);
int demSoVe(string dsVe[], int slVe);
void insertVe(string dsVe[], int vitri, char cmnd[]);
int checkVeCung_CB(PTRChuyenBay p, HANHKHACH hk);
PTRChuyenBay checkVeCungTime(PTRChuyenBay lstCB, PTRChuyenBay p, HANHKHACH hk);
int checkHK_HuyVe(PTRChuyenBay p, HANHKHACH& hk);
void QLDatHuyVe(PTRChuyenBay& lstCB, LIST_MB lstMB, TREEHanhKhach& lstHK);
// =========================================== Hành khách ===================================

void init_HK(TREEHanhKhach& lstHK);
int empty_HK(TREEHanhKhach lstHK);
int timTrung_HK(TREEHanhKhach lstHK, char soCMND[]);
TREEHanhKhach timKiem_HK(TREEHanhKhach lstHK, char cmnd[]);
void insertNode_HK(TREEHanhKhach& lstHK, HANHKHACH p);
HANHKHACH create_HK(TREEHanhKhach& lstHK, PTRChuyenBay& lstCB);
int hieuChinh_HK(TREEHanhKhach& lstHK, TREEHanhKhach t, PTRChuyenBay& lstCB);
void xuat_HK(TREEHanhKhach lstHK, int& stt); // theo thu tu NLR
void timNodeTheMang(TREEHanhKhach& lstHK, TREEHanhKhach& r);
void remove_HK(TREEHanhKhach& lstHK, char soCMND[]);
void showHK(TREEHanhKhach lstHK);
void duyetCay(TREEHanhKhach lstHK, fstream& file);

//=========================================== doc xuat file =================================
int loadMB(LIST_MB& mb);
int saveMB(LIST_MB mb);
int loadCB(PTRChuyenBay& lstCB, LIST_MB mb);
int saveCB(PTRChuyenBay lstCB);
int loadHK(TREEHanhKhach& lstHK);
int saveHK(TREEHanhKhach lstHK);