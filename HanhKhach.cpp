#pragma once
#include "ctdl.h"
#include "mylib.h"

void init_HK(TREEHanhKhach& lstHK) {
	lstHK = NULL;
}

int empty_HK(TREEHanhKhach lstHK) {
	return lstHK == NULL;
}

int timTrung_HK(TREEHanhKhach lstHK, char soCMND[]) {
	if (lstHK == NULL)
		return 0;
	if (lstHK != NULL)
	{
		if (stricmp(lstHK->data.CMND, soCMND) == 0) // neu so CMND ton tai trong cay
		{
			return 1;
		}
		else if (stricmp(lstHK->data.CMND, soCMND) > 0)
		{
			timTrung_HK(lstHK->Left, soCMND);
		}
		else if (stricmp(lstHK->data.CMND, soCMND) < 0)
		{
			timTrung_HK(lstHK->Right, soCMND);
		}
	}
}

TREEHanhKhach timKiem_HK(TREEHanhKhach lstHK, char cmnd[]) {
	TREEHanhKhach p;
	p = lstHK;

	while (p != NULL && stricmp(p->data.CMND, cmnd) != 0)
	{
		if (stricmp(p->data.CMND, cmnd) > 0)
		{
			p = p->Left;
		}
		else if (stricmp(p->data.CMND, cmnd) < 0)
		{
			p = p->Right;
		}
	}
	return p;
}

void insertNode_HK(TREEHanhKhach& lstHK, HANHKHACH p) {
	if (lstHK == NULL)
	{
		lstHK = new NodeHanhKhach;
		lstHK->data = p;
		lstHK->Left = NULL;
		lstHK->Right = NULL;
	}
	else
	{
		if (stricmp(lstHK->data.CMND, p.CMND) > 0)
		{
			insertNode_HK(lstHK->Left, p);
		}
		else if (stricmp(lstHK->data.CMND, p.CMND) < 0)
		{
			insertNode_HK(lstHK->Right, p);
		}
	}
}

HANHKHACH create_HK(TREEHanhKhach& lstHK, PTRChuyenBay& lstCB) {
	khungNhapThongTin(GDTHEM_HK, "NHAP THONG TIN HANH KHACH", "Nhap CMND", "Nhap ho", "Nhap ten", "Chon phai");
	HANHKHACH hk;

	do
	{
		strcpy(hk.CMND, CheckInputCMND(DONGNHAP1));
		/* kiem tra hanh khach da co hay chua */
		TREEHanhKhach tmp = timKiem_HK(lstHK, hk.CMND);
		if (tmp != NULL) {
			showHK(tmp);
		DatVe:
			int sua = confirm("SUA THONG TIN", "DAT VE", false);
			if (sua == YES) {
				int hieuChinh = hieuChinh_HK(lstHK, tmp, lstCB);
				if (hieuChinh) {
					Green_Highlight();
					hienThongBao("Sua thong tin thanh cong!");
					int savehk = saveHK(lstHK);
					int savecb = saveCB(lstCB);
					int datVe = confirm("DAT VE", "TRO VE", false);
					if (datVe == YES) {
						return tmp->data;
					}
					else {
						tmp->data.CMND[0] = ESC;
						return tmp->data;
					}
				}
				else
					goto DatVe;
			}
			else if (sua == NO) {
				int datVe = confirm("DONG Y", "TRO VE", false);
				if (datVe == YES) {

					return tmp->data;
				}
				else {
					tmp->data.CMND[0] = ESC;
					return tmp->data;
				}
			}

		}
		else {
			if (hk.CMND[0] == ESC) {
				return hk;
			}
			else break;
		}
	} while (true);

	do
	{
		strcpy(hk.ho, CheckInputStr(false, DONGNHAP2));

		if (hk.ho[0] == ESC) {
			hk.CMND[0] = ESC;
			return hk;
		}
		else
			break;
	} while (true);

	do
	{
		strcpy(hk.ten, CheckInputStr(false, DONGNHAP3));

		if (hk.ten[0] == ESC) {
			hk.CMND[0] = ESC;
			return hk;
		}
		else
			break;
	} while (true);

	int chon = confirm("NAM", "NU", false);
	if (chon == YES)
		hk.phai = NAM; // nam
	if (chon == NO)
		hk.phai = NU; // nam
	return hk;
}

int hieuChinh_HK(TREEHanhKhach& lstHK, TREEHanhKhach t, PTRChuyenBay& lstCB) {
	HANHKHACH hk;

	do
	{
		strcpy(hk.CMND, CheckInputCMND(DONGNHAP1));

		if (timTrung_HK(lstHK, hk.CMND)) {
			/* ham kiem tra dat ve tren cung 1 chuyen bay hay khong */
			Red_Highlight();
			hienThongBao("CMND nay da co!");
		}
		else {
			if (hk.CMND[0] == ESC) {
				return 0;
			}
			else break;
		}
	} while (true);

	do
	{
		strcpy(hk.ho, CheckInputStr(false, DONGNHAP2));

		if (hk.ho[0] == ESC) {
			hk.CMND[0] = ESC;
			return 0;
		}
		else
			break;
	} while (true);

	do
	{
		strcpy(hk.ten, CheckInputStr(false, DONGNHAP3));

		if (hk.ten[0] == ESC) {
			hk.CMND[0] = ESC;
			return 0;
		}
		else
			break;
	} while (true);

	int chon = confirm("NAM", "NU", false);
	if (chon == YES)
		hk.phai = NAM; // nam
	if (chon == NO)
		hk.phai = NU; // nam

	// doi lai CMND moi trong ds ve cua chuyen bay
	for (PTRChuyenBay p = lstCB; p != NULL; p = p->next) {
		for (int i = 0; i < p->data.dsVe.n; i++) {
			if (stricmp(t->data.CMND, p->data.dsVe.Ve[i]->data.CMND) == 0) {
				strcpy(p->data.dsVe.Ve[i]->data.CMND, hk.CMND);
				break;
			}
		}
	}
	t->data = hk;

	return 1;
}

void xuat_HK(TREEHanhKhach lstHK, int& stt) {
}

void timNodeTheMang(TREEHanhKhach& lstHK, TREEHanhKhach& r) {
	if (r->Left != NULL)
	{
		timNodeTheMang(lstHK, r->Left);
	}
	else
	{
		lstHK->data = r->data;
		lstHK = r;
		r = r->Right;
	}
}

void remove_HK(TREEHanhKhach& lstHK, char soCMND[]) {
	if (lstHK != NULL)
	{
		if (stricmp(lstHK->data.CMND, soCMND) > 0)
		{
			remove_HK(lstHK->Left, soCMND);
		}
		else if (stricmp(lstHK->data.CMND, soCMND) < 0)
		{
			remove_HK(lstHK->Right, soCMND);
		}
		else if (stricmp(lstHK->data.CMND, soCMND) == 0)
		{
			TREEHanhKhach q;
			q = lstHK;
			if (lstHK->Left == NULL) // truong hop khong co cay con ben trai
			{
				lstHK = lstHK->Right;
			}
			else if (lstHK->Right == NULL) // truong hop khong co cay con ben phai
			{
				lstHK = lstHK->Left;
			}
			else // truong hop co cay con 2 ben
			{
				timNodeTheMang(q, lstHK->Right);
			}
			delete q;
		}
	}
}

void showHK(TREEHanhKhach lstHK) {
	gotoxy(COT + 1, DONGNHAP1 + 2);
	cout << lstHK->data.CMND;
	gotoxy(COT + 1, DONGNHAP2 + 2);
	cout << lstHK->data.ho;
	gotoxy(COT + 1, DONGNHAP3 + 2);
	cout << lstHK->data.ten;
	gotoxy(COT + 1, DONGNHAP4 + 2);
	cout << (lstHK->data.phai == NAM ? "Nam" : "Nu");
}

void xuatHK_1_CB(CHUYENBAY* cb, TREEHanhKhach lstHK, int page) {
	int j = page, pageHK = page, dem = 0;
	for (j, pageHK; pageHK < cb->dsVe.n; pageHK++, j++) {
		if (stricmp(cb->dsVe.Ve[j]->data.CMND, "") != 0) {
			TREEHanhKhach t = timKiem_HK(lstHK, cb->dsVe.Ve[j]->data.CMND);

			gotoxy(COTDS_L + 1, DONGDS_U + 27 + dem);
			cout << dem + 1;
			gotoxy(COTDS_L + 6, DONGDS_U + 27 + dem);
			cout << cb->dsVe.Ve[j]->data.soVe;
			gotoxy(COTDS_L + 26, DONGDS_U + 27 + dem);
			cout << t->data.CMND;
			gotoxy(COTDS_L + 46, DONGDS_U + 27 + dem);
			cout << t->data.ho << " " << t->data.ten;
			gotoxy(COTDS_L + 94, DONGDS_U + 27 + dem);
			cout << (t->data.phai == NAM ? "Nam" : "Nu");
			dem++;
		}

		if (dem == MAX_PAGE_SMALL) {
			break;
		}

	}
}

void count_HK(TREEHanhKhach lstHK, int& dem) {
	if (lstHK != NULL)
	{
		dem++;
		count_HK(lstHK->Left, dem);
		count_HK(lstHK->Right, dem);
	}
}

