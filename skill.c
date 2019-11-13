#include <stdio.h>
#include "boolean.h"
#include "skill.h"
#include <stdlib.h>

boolean IsEmptyQueue (Queue Q){
    return ((Head(Q)==0) && (Tail(Q)==0));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQueue (Queue Q){
    return ((Head(Q)==1) && (Tail(Q)==MaxEl(Q)));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtQueue (Queue Q){
    if (!IsEmptyQueue(Q)){
        return (((Tail(Q) - Head(Q) + MaxEl(Q))% MaxEl(Q)) +1);
    }
    else{
        return 0;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max){
    (*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype *));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = 0;
        Tail(*Q) = 0;
    } 
    else /* alokasi gagal */ {
        MaxEl(*Q) = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q){
    MaxEl(*Q) = 0;
    free((*Q).T); 
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
infotype SkillChecker(char X[25]){
    infotype y;
    
    if (X == "InstantUpgrade"){
        y = 1;
    }
    else if (X == "Shield"){
        y = 2;
    }
    else if (X == "ExtraTurn"){
        y = 3;
    }
    else if (X == "AttackUp"){
        y = 4;
    }
    else if (X == "CriticalHit"){
        y = 5;
    }
    else if (X == "InstantReinforcement"){
        y = 6;
    }
    else if (X == "Barrage"){
        y = 7;
    }
    return y;
}

char readSkill (Queue *Q){
    char *X[25];
    if (InfoHead(*Q) == 1){
        X[25] = "InstantUpgrade";
    }
    else if (InfoHead(*Q) == 2){
        X[25] = "Shield";
    }
    else if (InfoHead(*Q) == 3){
        X[25] = "ExtraTurn";
    }
    else if (InfoHead(*Q) == 4){
        X[25] = "AttackUp";
    }
    else if (InfoHead(*Q) == 5){
        X[25] = "CriticalHit";
    }
    else if (InfoHead(*Q) == 6){
       X[25] = "InstantReinforcement";
    }
    else if (InfoHead(*Q) == 7){
        X[25] = "Barrage";
    }
    return *X[25];
}
void AddSkillQueue(Queue * Q, char Y){
    address i,j;
    boolean valid;
    valid = false;
    int *X;
    
    *X = SkillChecker(&Y);
    while (!valid){
        if (*X == 1|| *X != 2 || *X != 3 || *X != 4 || *X != 5 || *X != 6 || *X != 7) {
            // 1 == > Instant Upgrade
            // 2 == > Shield
            // 3 == > Extra Turn 
            // 4 == > Attack Up
            // 5 == > Critical Hit
            // 6 == > Instant Reinforcement
            // 7 == > Barrage
            printf("Maaf, skill yang ingin ditambahkan tidak boleh dimasukkan.");
            scanf("%p",&X);
        }
        else /* Q tidak kosong */ {
            if (Tail(*Q) == MaxEl(*Q) && NBElmtQueue(*Q) != MaxEl(*Q)) { /* Geser elemen smp Head(Q)=1 */
                Tail(*Q) = 1;
                InfoTail(*Q) = *X;
                valid = true;
            }
            else if (Tail(*Q) != MaxEl(*Q)){
                Tail(*Q)++;
                InfoTail(*Q)= *X;
                valid = true;
            }
            else{
                valid = true;
            }
        }
    }
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void DelSkillQueue(Queue * Q, infotype * X){
    if (Head(*Q)==Tail(*Q)) { /* Set mjd queue kosong */
        *X = InfoHead(*Q);
        InfoHead(*Q)=0;
        Head(*Q)=0;
        Tail(*Q)=0;
    } 
    else if (Head(*Q) == MaxEl(*Q)){
            *X = InfoHead(*Q);
            InfoHead(*Q)=0;
            Head(*Q)=1;
    }
    else{
            *X = InfoHead(*Q);
            InfoHead(*Q)=0;
            Head(*Q)++;
    }   
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = 0ai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
void startSkillQueue(Queue *Q){
    CreateEmptyQueue(Q,10);
    InfoHead(*Q) = 1; //1 ==> InstantUpgrade
}


