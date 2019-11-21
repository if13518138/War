#include "prosedur_skill.h"

void InstantUpgrade(TabBangunan * tab, Pemain p1){
	/* Implementasi Dari Instant Upgrade */
	address last=FirstL(p1.b);

    for (int i = 1; i <= NbElmtList(p1.b); i++){
		if (Level(ElmtArray((*tab), InfoL(last))) < 4) {
			Pasukan(ElmtArray((*tab), InfoL(last))) += M(ElmtArray((*tab), InfoL(last))) / 2;
			NaikLevel(&(ElmtArray((*tab), InfoL(last))));
		}
        last = NextL(last);
    }
}

void TambahPasukanB(Bangunan * bangunan, int n){
	/* Prosedur antara untuk menambah jumlah bangunan */
	Pasukan(*bangunan) += n;
}

void KurangPasukan(Bangunan * bangunan, int n){
	if ((Pasukan(*bangunan) - n) < 0){
		Pasukan(*bangunan) = 0;
	} else {
		Pasukan(*bangunan) -= n;
	}
}

void InstantReinforcement(TabBangunan * tab, Pemain p1) {
	/* Implementasi dari instant reinforcement */
	address last = FirstL(p1.b);
	int tambahanPasukan = 5;
	for (int i = 1; i <= NbElmtList(p1.b); i++){
		TambahPasukanB(&(ElmtArray((*tab), InfoL(last))),tambahanPasukan);
		last = NextL(last);
	}
}

void Barrage(TabBangunan * tab, Pemain p1, Pemain p2){
	/* Implementasi dari Barrage */
	address last = FirstL(p2.b);
	int kurangPasukan = 10;
	for(int i = 1; i <= NbElmtList(p2.b); i++){
		KurangPasukan(&(ElmtArray((*tab), InfoL(last))), kurangPasukan);
		last = NextL(last);
	}
}

void ExtraTurn (int * n){
	(*n) += 1;
}

boolean IsObtainIR (TabBangunan tab, Pemain p1){
	/* Fungsi untuk melakukan pengecekan apakah pemain 
	   mendapatkan skill Instant Reinforcement atau tidak */
	address last = FirstL(p1.b);
	boolean checker = true;
	int i = 1;
	while (i <= NbElmtList(p1.b) && checker){
		if (Level(ElmtArray(tab, InfoL(last))) < 4){
			checker = false;
		}
		i++;
		last = NextL(last);
	}
	return checker;
}
boolean IsObtainBarrage(TabBangunan tab, Pemain p2){
	/* Fungsi untuk melakukan pengecekan apakah seorang pemain mendapatkan skill Barrage atau tidak
	Notes : yang dibutuhkan untuk pengecekan hanyalah List bangunan musuh */
	if (NbElmtList(p2.b) == 10) return true;
	else false;
}
boolean IsObtainExtraTurn(TabBangunan tab, IdxTypeArray i, Pemain p2){
	/* Fungsi untuk melakukan pengecekan apakah seorang pemain mendapatkan skill Extra Turn 
	   Pengecekan dilakukan dengan mengecek apakah bangunan yang akan didapatkan berupa Fort atau tidak */
	if (Type(ElmtArray(tab, i)) == 'F') return true;
	else return false; 
}