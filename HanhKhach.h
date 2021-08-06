#pragma once
#include "ctdl.h"
#include "mylib.h"

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
void quickSortTK(int* soLuot, mayBay tempMB, int q, int r);
