#include "./bangunan.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/***********************************************************
*Bangunan                                                  *
*Author : William                                          *
*Created at : 26 Oktober 2019                              *
*File Implementasi dari Header File Bangunan               *
*Digunakan sebagai implementasi dari fungsi - fungsi utama *
*yang terdapat pada objek bangunan dalam game              *
***********************************************************/

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Bangunan *** */
void MakeBangunan(Bangunan * bangunan, char type, Point letak) {
	/*
	I.S. : Bangunan sembarang
	F.S  : Bangunan terdefinisi
	*/
	Level(*bangunan) = 1;
	Letak(*bangunan) = letak;
	if (type == 'C') {
		Type(*(bangunan)) = 'C';
		A(*bangunan) = 10;
		M(*bangunan) = 40;
		Pasukan(*bangunan) = 40; // INI U BANGUNAN NYA DI TYPE BENTUKAN BLM ADA
		Pertahanan(*bangunan) = false;
	}
	else if (type == 'T') {
		Type(*(bangunan)) = 'T';
		A(*bangunan) = 5;
		M(*bangunan) = 20;
		Pasukan(*bangunan) = 30;
		Pertahanan(*bangunan) = true;
	}
	else if (type == 'F') {
		Type(*(bangunan)) = 'F';
		A(*bangunan) = 10;
		M(*bangunan) = 20;
		Pasukan(*bangunan) = 80;
		Pertahanan(*bangunan) = false;
	}
	else if (type == 'V') {
		Type(*(bangunan)) = 'V';
		A(*bangunan) = 5;
		M(*bangunan) = 20;
		Pasukan(*bangunan) = 20;
		Pertahanan(*bangunan) = false;
	}
	Serang(*bangunan) = false;
	Move(*bangunan) = false;
}

/* Fungsi - fungsi Primitif */
boolean IsAbleNaikLevel(Bangunan bangunan) {
// memberikan informasi apakah suatu bangunan dapat naik level atau tidak
// asumsi boleh nol
	if (Level(bangunan) < 4) return (Pasukan(bangunan) >= M(bangunan) / 2);
	else return false;
}

boolean IsMaxLevel(Bangunan bangunan) {
//memberikan informasi apakah suatu bangunan sudah berada di level maksimum atau belum
	return (Level(bangunan) == 4);
}

/* Fungsi - fungsi primitif terhadap naik level bangunan*/
Bangunan NaikLevelFort(Bangunan bangunan) {
	Bangunan newBangunan;
	newBangunan = bangunan;
	if (IsAbleNaikLevel(newBangunan)) {
		if (Level(newBangunan) == 1) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 40;
			A(newBangunan) = 20;
		} else if (Level(newBangunan) == 2) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 60;
			A(newBangunan) = 30;
			Pertahanan(newBangunan) = true;
		} else  if (Level(newBangunan) == 3) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 80;
			A(newBangunan) = 40;
		}
		Level(newBangunan) += 1;
	}
	return newBangunan;
}

Bangunan NaikLevelTower(Bangunan bangunan) {
	Bangunan newBangunan;
	newBangunan = bangunan;
	if (IsAbleNaikLevel(newBangunan)) {
		if (Level(newBangunan) == 1) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 30;
			A(newBangunan) = 10;
		} else if (Level(newBangunan) == 2) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 40;
			A(newBangunan) = 20;
		} else if (Level(newBangunan) == 3) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 50;
			A(newBangunan) = 30;
		}
		Level(newBangunan) += 1;
	}
	return newBangunan;
}

Bangunan NaikLevelCastle(Bangunan bangunan) {
	Bangunan newBangunan;
	newBangunan = bangunan;

	if (IsAbleNaikLevel(newBangunan)) {
		if (Level(newBangunan) == 1) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 60;
			A(newBangunan) = 15;
		} else if (Level(newBangunan) == 2) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 80;
			A(newBangunan) = 20;
		} else if (Level(newBangunan) == 3) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 100;
			A(newBangunan) = 25;
		}
		Level(newBangunan) += 1;
	}
	return newBangunan;
}

Bangunan NaikLevelVillage(Bangunan bangunan) {
	Bangunan newBangunan;
	newBangunan = bangunan;

	if (IsAbleNaikLevel(newBangunan)) {
		if (Level(newBangunan) == 1) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 30;
			A(newBangunan) = 10;
		} else if (Level(newBangunan) == 2) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 40;
			A(newBangunan) = 15;
		} else if (Level(newBangunan) == 3) {
			Pasukan(newBangunan) -= M(newBangunan) / 2;
			M(newBangunan) = 50;
			A(newBangunan) = 20;
		}
		Level(newBangunan) += 1;
	}
	return newBangunan;
}

void NaikLevel(Bangunan * bangunan) {
	/*
		I.S. Bangunan akan naik level
		F.S. Bangunan naik levelnya apabila "valid" untuk naik level
	*/
	if (IsAbleNaikLevel(*bangunan)) {
		if (Type(*bangunan) == 'C') {
			(*bangunan) = NaikLevelCastle(*bangunan);
		} else if (Type(*bangunan) == 'T') {
			(*bangunan) = NaikLevelTower(*bangunan);
		} else if (Type(*bangunan) == 'F') {
			(*bangunan) = NaikLevelFort(*bangunan);
		} else { // village
			(*bangunan) = NaikLevelVillage(*bangunan);
		}
	}
}

/* Fungsi - fungsi primitif untuk Penyerangan*/
//void Serang(Bangunan * bserang, Bangunan * bdiserang, int jPSerang);
/*
	I.S. Bangunan belum diserang
	F.S. Bangunan telah diserang
	Apabila Bangunan beralih kepemilikan, maka bangunan diserang akan berubah tempat listnya
*/


/* Fungsi - fungsi lainnya*/
boolean IsPindahPemilik(Bangunan bBertahan, int jumlahPenyerang) {
	float jumlahPenyerangDesimal;
	if (Pertahanan(bBertahan)) {
		jumlahPenyerangDesimal = (jumlahPenyerang * 3) / 4.0;
		return (Pasukan(bBertahan) <= jumlahPenyerangDesimal);
	} else {
		return (Pasukan(bBertahan) <= jumlahPenyerang);
	}
}

boolean IsSudahSerang(Bangunan bangunan){
	return Serang(bangunan);
}

boolean IsSudahMove(Bangunan bangunan) {
	return Move(bangunan);
}

Point letakBangunan(Bangunan bangunan){
	/* Mengembalikan letak point dari suatu bangunan */
	return Letak(bangunan);
}

void PlusPasukan(Bangunan * bangunan) {
	/*
		I.S. : Jumlah Pasukan belum ditambahkan
		F.S. : Jumlah Pasukan telah bertambah
	*/
	if (Pasukan(*bangunan) < M(*bangunan)){
		Pasukan(*bangunan) += A(*bangunan);
	}
}

void NextTurnBangunan(Bangunan * bangunan){
/*
	I.S. : Kondisi bangunan sebelum next turn
	F.S. : Kondisi bangunan setelah next turn
*/
	// Pertama tambah pasukan
	PlusPasukan(bangunan);

	// Kedua perbolehkan menyerang
	Serang(*bangunan) = false;

	// Bangunan blh bergerak
	Move(*bangunan) = false;
}



/* Cetak Info Bangunan*/
void PrintInfoBangunan(Bangunan bangunan) {
	/*
		Melakukan pencetakan terhadap info bangunan dengan format
		<jenis_bangunan> <letak_bangunan> <jumlah_pasukan> lv. <level_bangunan>
	*/
	if (Type(bangunan) == 'C'){
		printf("%s ", "Castle");
	} else if (Type(bangunan) == 'T'){
		printf("%s ", "Tower");
	} else if (Type(bangunan) == 'F'){
		printf("%s ", "Fort");
	} else if (Type(bangunan) == 'V'){
		printf("%s ", "Village");
	} 

	TulisPoint(Letak(bangunan));
	printf(" ");

	printf("%d", Pasukan(bangunan));

	printf(" ");

	printf("lv. %d\n", Level(bangunan)); 
}

boolean EQBangunan(Bangunan b1, Bangunan b2){
	if(Type(b1) == Type(b2) && Level(b1) == Level(b2) && A(b1) == A(b2) && TambahPasukan(b1) == TambahPasukan(b2) && M(b1) == M(b2) && Maksimum(b1) == Maksimum(b2) && Pertahanan(b1) == Pertahanan(b2) && EQ(Letak(b1), Letak(b2))){
		return true;
	}
	return false;
}

void CopyBangunan(Bangunan B,Bangunan *T){
	(*T).type=B.type; // T : Tower, C : Castle, F : Fort, V : Village
    (*T).level=B.level; // 1 - 4
 	(*T).A=B.A; // nilai pertambahan pasukan
 	(*T).M=B.M; // maksimum penambahan pasukan
	(*T).P=B.P; // true -> ada pertahanan, dan sebaliknya
	(*T).pasukan=B.pasukan; // pasukan awal
	(*T).letak=B.letak;
	(*T).serang=B.serang;
}

void MakeLevelOne(Bangunan * bangunan){
	Level(*bangunan) = 1;
	Serang(*bangunan) = false;
	Move(*bangunan) = false;
	if (Type(*bangunan) == 'C') {
		A(*bangunan) = 10;
		M(*bangunan) = 40;
		Pertahanan(*bangunan) = false;
	}
	else if (Type(*bangunan) == 'T') {
		A(*bangunan) = 5;
		M(*bangunan) = 20;
		Pertahanan(*bangunan) = true;
	}
	else if (Type(*bangunan) == 'F') {
		A(*bangunan) = 10;
		M(*bangunan) = 20;
		Pertahanan(*bangunan) = false;
	}
	else if (Type(*bangunan) == 'V') {
		A(*bangunan) = 5;
		M(*bangunan) = 20;
		Pertahanan(*bangunan) = false;
	}
}




