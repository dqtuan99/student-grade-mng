//created by Yukineko69

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

typedef struct HocSinh{
    int STT;
    char name[50], ten[10], dem[10];
    float Toan, Van, Anh, Ly, Hoa, Sinh, Su, Dia, GDCD, CN, Tin;
    float DTB;
    int TD;
    int rank;
    struct HocSinh *next;
}hs;

hs *head = NULL;
hs *head2 = NULL;

void insertFirst(char *name, float Toan, float  Van, float  Anh, float  Ly, float Hoa,
                 float Sinh, float   Su, float  Dia, float GDCD, float  CN, float Tin, int TD);
char* copy(char s[], int x, int y);
int daucach(char s[]);
char* xoachuoi(char s[], int x);
float KTraNhap(float DiemSo);
void putSTT();
char* TheDuc(int TD);
char* XepLoai(int XL);
void XepLoaiHS();
void insertionSort();
void sortedInsert(hs* new_);
float returnFilter(hs *filter, int case_);
void printFilter(hs *prt);
void TimKiem(char *name);
void PrtCerti();

int main(){
    int i = 0, sl, case_;
    char name[50], ten[10], dem[10];
    char case_c;
    float Toan, Van, Anh, Ly, Hoa, Sinh, Su, Dia, GDCD, CN, Tin;
    int TD;

    printf("Moi ban nhap si so lop hoc: ");
    scanf("%d", &sl);
    while (sl < 1){
        printf("Xin loi so luong hoc sinh khong the it hon 1 xin moi ban nhap lai.\n");
        printf("Moi ban nhap lai si so: ");
        scanf("%d", &sl);
    }
    printf("\n");

    while (i < sl){
        printf("Moi ban nhap ten cua hoc sinh: ");
        fflush(stdin);
        fgets(name, 50, stdin);
        strtok(name, "\n");
        printf("Moi ban nhap diem mon Toan: ");
        scanf("%f", &Toan);
        Toan = KTraNhap(Toan);
        printf("Moi ban nhap diem mon Van: ");
        scanf("%f", &Van);
        Van = KTraNhap(Van);
        printf("Moi ban nhap diem mon Anh: ");
        scanf("%f", &Anh);
        Anh = KTraNhap(Anh);
        printf("Moi ban nhap diem mon Ly: ");
        scanf("%f", &Ly);
        Ly = KTraNhap(Ly);
        printf("Moi ban nhap diem mon Hoa: ");
        scanf("%f", &Hoa);
        Hoa = KTraNhap(Hoa);
        printf("Moi ban nhap diem mon Sinh: ");
        scanf("%f", &Sinh);
        Sinh = KTraNhap(Sinh);
        printf("Moi ban nhap diem mon Su: ");
        scanf("%f", &Su);
        Su = KTraNhap(Su);
        printf("Moi ban nhap diem mon Dia: ");
        scanf("%f", &Dia);
        Dia = KTraNhap(Dia);
        printf("Moi ban nhap diem mon GDCD: ");
        scanf("%f", &GDCD);
        GDCD = KTraNhap(GDCD);
        printf("Moi ban nhap diem mon CN: ");
        scanf("%f", &CN);
        CN = KTraNhap(CN);
        printf("Moi ban nhap diem mon Tin: ");
        scanf("%f", &Tin);
        Tin = KTraNhap(Tin);
        printf("Moi ban nhap ket qua mon The Duc (Neu Dat nhap 1, Chua Dat nhap 0): ");
        scanf("%d", &TD);
        while (TD != 0 && TD != 1){
            printf("Da bao la nhap 0 hay 1 co ma nhap linh tinh cai gi the nhap lai di: ");
            scanf("%d", &TD);
        }
        insertFirst(name, Toan, Van, Anh, Ly, Hoa, Sinh, Su, Dia, GDCD, CN, Tin, TD);
        ++i;
        printf("\n");
    }

    insertionSort();
    putSTT();
    XepLoaiHS();
    printList();

    printf("\nBan co muon dung chuc nang mo rong cua chuong trinh khong (Y/N)?: ");
    fflush(stdin);
    scanf("%c", &case_c);
    while (case_c != 'y' && case_c != 'Y' && case_c != 'n' && case_c != 'N'){
        printf("Nhap sai cu phap xin moi ban nhap lai (Y/N): ");
        fflush(stdin);
        scanf("%c", &case_c);
    }
    if (case_c == 'y' || case_c == 'Y') system("cls");
    else if (case_c == 'n' || case_c == 'N') goto exit;

    menu:{
        system("cls");
        printf("-------------------------------Menu-------------------------------\n");
        printf("Case 1: Filter.\n");
        printf("Case 2: Tim kiem hoc sinh theo ten.\n");
        printf("Case 3: In bang khen cho hoc sinh Gioi va Kha.\n");
        printf("Case 4: In danh sach hoc sinh roi thoat chuong trinh.\n\n");
        while (1){
            printf("Moi ban nhap case: ");
            scanf("%d", &case_);
            switch (case_){
                default:{
                    printf("Nhap sai cu phap xin moi ban nhap lai.\n");
                    break;
                }
                case 1:{
                    while (1){
                        system("cls");
                        printf("Case 1: Tim kiem lon hon.\n");
                        printf("Case 2: Tim kiem nho hon.\n");
                        printf("Case 3: Tim kiem lon hon hoac bang.\n");
                        printf("Case 4: Tim kiem nho hon hoac bang.\n");
                        printf("Case 5: Tim kiem bang.\n");
                        printf("Case 0: Quay lai.\n");
                        printf("Moi ban nhap case: ");
                        scanf("%d", &case_);
                        while (case_ < 0 && case_ > 5){
                            printf("Nhap sai cu phap xin moi ban nhap lai case: ");
                            scanf("%d", &case_);
                        }
                        if (case_ == 0) goto menu;
                        else FilterHS(case_);
                        printf("\nNhan nut bat ki de tiep tuc.\n");
                        getch();
                    }
                }
                case 2:{
                    while (1){
                        system("cls");
                        printf("Moi ban nhap ten cua hoc sinh muon tim: ");
                        fflush(stdin);
                        fgets(name, 50, stdin);
                        strtok(name, "\n");
                        TimKiem(name);
                        printf("Nhap 0 de thoat tim kiem, nhap so bat ki de tiep tuc tim kiem.\n");
                        int k;
                        scanf("%d", &k);
                        if (k == 0) goto menu;
                    }
                }
                case 3:{
                    PrtCerti();
                    printf("Bang khen da duoc in thanh cong.\n");
                    break;
                }
                case 4:{
                    printf("\n");
                    printList();
                    goto exit;
                }
            }
        }
    }

    exit:{
        return 1;
    }
}

float KTraNhap(float DiemSo){
    while(DiemSo < 0){
        printf("Lam gi co diem am nhap lai diem di ong: ");
        scanf("%f", &DiemSo);
        KTraNhap(DiemSo);
    }
    while(DiemSo > 10){
        printf("Ong hack dau ra diem cao the nhap lai diem di ong: ");
        scanf("%f", &DiemSo);
        KTraNhap(DiemSo);
    }
    return DiemSo;
}

char* TheDuc(int TD){
    if (TD == 1) return "Dat";
    if (TD == 0) return "Ko Dat";
    else return;
}

char* XepLoai(int XL){
    if (XL == 5) return "Gioi";
    if (XL == 4) return "Kha";
    if (XL == 3) return "TB";
    if (XL == 2) return "Yeu";
    if (XL == 1) return "Kem";
    else return;
}

void printList(){
    hs *prt = head;
    printf("Danh sach hoc sinh va bang diem cua lop hoc:\n\n");
    printf("%-6s %-22s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-8s\n", \
        "STT" , "Ho va Ten", "Toan", "Van", "Anh", "Ly" , "Hoa", "Sinh", \
        "Su"  , "Dia"      , "GDCD", "CN" , "Tin", "DTB",  "TD", "Xep Loai");
    while(prt != NULL) {
        printf("%-6d %-22s %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6s %-8s\n", \
        prt->STT, prt->name, prt->Toan, prt->Van, prt->Anh , prt->Ly  , prt->Hoa, prt->Sinh, prt->Su, \
        prt->Dia, prt->GDCD, prt->CN  , prt->Tin, prt->DTB , TheDuc(prt->TD)    , XepLoai(prt->rank) );
        prt = prt->next;
    }
    return;
}

void insertFirst(char *name, float Toan, float  Van, float  Anh, float  Ly, float Hoa,
                 float Sinh, float   Su, float  Dia, float GDCD, float  CN, float Tin, int TD){
    char temp1[50], temp2[50];
    int k;
    hs *new_ = (hs*) malloc(sizeof(hs));
    strcpy(new_->name, name);
    //-----------------------------------
        strcpy(temp1, new_->name);
        strcpy(new_->ten, xoachuoi(temp1, strlen(temp1) - 1) );
        strcpy(temp1, new_->name);
        k = daucach(temp1) - 1;
        strcpy(temp2, copy(temp1, 0, k) );
        strcpy(new_->dem, xoachuoi(temp2, k) );
    //-----------------------------------
    new_->Toan = Toan;
    new_->Van = Van;
    new_->Anh = Anh;
    new_->Ly = Ly;
    new_->Hoa = Hoa;
    new_->Sinh = Sinh;
    new_->Su = Su;
    new_->Dia = Dia;
    new_->GDCD = GDCD;
    new_->CN = CN;
    new_->Tin = Tin;
    new_->TD = TD;
    new_->DTB = (Toan*2 + Van*2 + Anh + Ly + Hoa + Sinh + Su + Dia + GDCD + CN + Tin) / 13;

    new_->next = head;
    head = new_;
    return;
}

char* copy(char s[], int x, int y){
    char s2[50];
    int i, j = 0;

    for (i = x; i <= y; ++i){
        if (j <= (y-x) ){
            s2[j] = s[i];
            j++;
        }
    }
    s2[j] = '\0';
    strcpy(s, s2);
    return s;
}

int daucach(char s[]){
    int i;
    for (i = strlen(s) - 1; i >= 0; i--){
        if (s[i] == ' ') break;
    }
    return i;
}

char* xoachuoi(char s[], int x){
    int i = 0, j;
    j = daucach(s);
    copy(s, j + 1, x);
    return s;
}

void insertionSort(){
    if (head == NULL) return;
    if (head->next == NULL) return;
    hs *new_ = head;
    while (new_ != NULL){
        hs *temp = new_->next;
        sortedInsert(new_);
        new_ = temp;
    }
    head = head2;
    return;
}

void sortedInsert(hs* new_){
    if (head2 == NULL || strcmp(head2->ten, new_->ten) > 0 ||
       (!strcmp(head2->ten, new_->ten) && strcmp(head2->dem, new_->dem) > 0)){
        new_->next = head2;
        head2 = new_;
    }
    else{
        hs *current;
        current = head2;
        while (current->next != NULL && (strcmp(current->next->ten, new_->ten) < 0 ||
              (!strcmp(current->next->ten, new_->ten) && strcmp(current->next->dem, new_->dem) < 0))){
            current = current->next;
        }
        new_->next = current->next;
        current->next = new_;
    }
    return;
}

void putSTT(){
    int i = 0;
    hs *put = head;
    while (put != NULL){
        put->STT = ++i;
        put = put->next;
    }
    return;
}

void XepLoaiHS(){
    hs *XepLoai = head;
    while (XepLoai != NULL){
        if (XepLoai->TD == 1){
            if ((XepLoai->Toan >= 8 || XepLoai-> Van >= 8) && XepLoai->DTB >= 8 && XepLoai->Anh >= 6.5 &&
             XepLoai->Ly >= 6.5 && XepLoai->Hoa >= 6.5 && XepLoai->Sinh >= 6.5 &&
             XepLoai->Su >= 6.5 && XepLoai->Dia >= 6.5 && XepLoai->GDCD >= 6.5 &&
             XepLoai->CN >= 6.5 && XepLoai->Tin >= 6.5) XepLoai->rank = 5;
            else if ((XepLoai->Toan >= 6.5 || XepLoai-> Van >= 6.5) && XepLoai->DTB >= 6.5 && XepLoai->Anh >= 5 &&
                 XepLoai->Ly >= 5 && XepLoai->Hoa >= 5 && XepLoai->Sinh >= 5 &&
                 XepLoai->Su >= 5 && XepLoai->Dia >= 5 && XepLoai->GDCD >= 5 &&
                 XepLoai->CN >= 5 && XepLoai->Tin >= 5) XepLoai->rank = 4;
            else if ((XepLoai->Toan >= 5 || XepLoai-> Van >= 5) && XepLoai->DTB >= 5 && XepLoai->Anh >= 3.5 &&
                 XepLoai->Ly >= 3.5 && XepLoai->Hoa >= 3.5 && XepLoai->Sinh >= 3.5 &&
                 XepLoai->Su >= 3.5 && XepLoai->Dia >= 3.5 && XepLoai->GDCD >= 3.5 &&
                 XepLoai->CN >= 3.5 && XepLoai->Tin >= 3.5) XepLoai->rank = 3;
            else if (XepLoai->Toan >= 2 && XepLoai-> Van >= 2 && XepLoai->DTB >= 3.5 && XepLoai->Anh >= 2 &&
                XepLoai->Ly >= 2 && XepLoai->Hoa >= 2 && XepLoai->Sinh >= 2 &&
                XepLoai->Su >= 2 && XepLoai->Dia >= 2 && XepLoai->GDCD >= 2 &&
                XepLoai->CN >= 2 && XepLoai->Tin >= 2) XepLoai->rank = 2;
            else XepLoai->rank = 1;
        }
        else{
            if ((XepLoai->Toan >= 5 || XepLoai-> Van >= 5) && XepLoai->DTB >= 5 && XepLoai->Anh >= 3.5 &&
                 XepLoai->Ly >= 3.5 && XepLoai->Hoa >= 3.5 && XepLoai->Sinh >= 3.5 &&
                 XepLoai->Su >= 3.5 && XepLoai->Dia >= 3.5 && XepLoai->GDCD >= 3.5 &&
                 XepLoai->CN >= 3.5 && XepLoai->Tin >= 3.5) XepLoai->rank = 3;
            else if (XepLoai->Toan >= 2 && XepLoai-> Van >= 2 && XepLoai->DTB >= 3.5 && XepLoai->Anh >= 2 &&
                XepLoai->Ly >= 2 && XepLoai->Hoa >= 2 && XepLoai->Sinh >= 2 &&
                XepLoai->Su >= 2 && XepLoai->Dia >= 2 && XepLoai->GDCD >= 2 &&
                XepLoai->CN >= 2 && XepLoai->Tin >= 2) XepLoai->rank = 2;
            else XepLoai->rank = 1;
        }
        XepLoai = XepLoai->next;
    }
    return;
}

void TimKiem(char *name){
    hs *prt = head;
    int count = 0;
    while (prt != NULL){
        if (!strcmp(prt->name, name)) ++count;
        prt = prt->next;
    }
    if (count == 0) printf("Khong tim thay bat ki hoc sinh nao ten %s .\n", name);
    else{
        prt = head;
        printf("Thong tin cac hoc sinh tim thay duoc:\n\n");
        printf("%-6s %-22s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-8s\n", \
            "STT" , "Ho va Ten", "Toan", "Van", "Anh", "Ly" , "Hoa", "Sinh", \
            "Su"  , "Dia"      , "GDCD", "CN" , "Tin", "DTB",  "TD", "Xep Loai");
        while (prt != NULL) {
            if (!strcmp(prt->name, name))
            printf("%-6d %-22s %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6s %-8s\n", \
            prt->STT, prt->name, prt->Toan, prt->Van, prt->Anh , prt->Ly  , prt->Hoa, prt->Sinh, prt->Su, \
            prt->Dia, prt->GDCD, prt->CN  , prt->Tin, prt->DTB , TheDuc(prt->TD)    , XepLoai(prt->rank) );
            prt = prt->next;
        }
    }
    return;
}

void FilterHS(int case_i){
    int n, case_;
    printf("\nCase 1: Toan\nCase 2: Van\nCase 3: Anh\nCase 4: Ly\nCase 5: Hoa\nCase 6: Sinh\n");
    printf("Case 7: Su\nCase 8: Dia\nCase 9: GDCD\nCase 10: CN\nCase 11: Tin\nCase 12: Diem TB\n");
    printf("Case 13: TD\nCase 14: Xep Loai\n");
    printf("\nMoi ban nhap case: ");
    scanf("%d", &case_);
    while (case_ < 1 && case_ > 14){
        printf("Nhap sai cu phap xin moi ban nhap lai case: ");
        scanf("%d", &case_);
    }
    printf("\nMoi ban nhap moc: ");
    scanf("%d", &n);
    if (case_ >= 1 && case_ <= 12){
        n = KTraNhap(n);
    }
    else if (case_ == 13){
        while (n != 1 && n != 0){
            printf("Nhap sai moc xin hay nhap lai (Dat nhap 1, Ko Dat nhap 0): ");
            scanf("%d", &n);
        }
    }
    else{
        while (n < 1 || n > 5){
            printf("Nhap sai moc xin hay nhap lai (0 ~ 5 <=> XL Kem ~ XL Gioi): ");
            scanf("%d", &n);
        }
    }
    hs *filter = head;
    printf("Danh sach hoc sinh sau khi loc la:\n\n");
    printf("%-6s %-22s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-8s\n", \
            "STT" , "Ho va Ten", "Toan", "Van", "Anh", "Ly" , "Hoa", "Sinh", \
            "Su"  , "Dia"      , "GDCD", "CN" , "Tin", "DTB",  "TD", "Xep Loai");
    while (filter != NULL){
        if (case_i == 1){
            if (returnFilter(filter, case_) > n) printFilter(filter);
        }
        if (case_i == 2){
            if (returnFilter(filter, case_) < n) printFilter(filter);
        }
        if (case_i == 3){
            if (returnFilter(filter, case_) >= n) printFilter(filter);
        }
        if (case_i == 4){
            if (returnFilter(filter, case_) <= n) printFilter(filter);
        }
        if (case_i == 5){
            if (returnFilter(filter, case_) == n) printFilter(filter);
        }
        filter = filter->next;
    }
    return;
}

float returnFilter(hs *filter, int case_){
    if (case_ == 1) return filter->Toan;
    else if (case_ == 2) return filter->Van;
    else if (case_ == 3) return filter->Anh;
    else if (case_ == 4) return filter->Ly;
    else if (case_ == 5) return filter->Hoa;
    else if (case_ == 6) return filter->Sinh;
    else if (case_ == 7) return filter->Su;
    else if (case_ == 8) return filter->Dia;
    else if (case_ == 9) return filter->GDCD;
    else if (case_ == 10) return filter->CN;
    else if (case_ == 11) return filter->Tin;
    else if (case_ == 12) return filter->DTB;
    else if (case_ == 13) return filter->TD;
    else return filter->rank;
}

void printFilter(hs *prt){
    printf("%-6d %-22s %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6s %-8s\n", \
            prt->STT, prt->name, prt->Toan, prt->Van, prt->Anh , prt->Ly  , prt->Hoa, prt->Sinh, prt->Su, \
            prt->Dia, prt->GDCD, prt->CN  , prt->Tin, prt->DTB , TheDuc(prt->TD)    , XepLoai(prt->rank) );
    return;
}

void PrtCerti(){
    hs *prt = head;
    int count = 0, i = 0;
    SYSTEMTIME time;
    GetSystemTime(&time);
    while (prt != NULL){
        if (prt->rank >= 4) ++count;
        prt = prt->next;
    }
    prt = head;
    FILE *fp[count];
    while (prt != NULL){
        if (prt->rank >= 4){
            char filename[54];
            strcpy(filename, prt->name);
            strcat(filename, ".txt");
            fp[i] = fopen(filename, "w+");
            fprintf(fp[i], "\t\t\t\t\t\t Cong Hoa Xa Hoi Chu Nghia Viet Nam\n");
            fprintf(fp[i], "\t\t\t\t\t\t     Doc Lap - Tu Do - Hanh Phuc\n\n");
            fprintf(fp[i], "\t\t\t\t\t\t\t     GIAY KHEN\n\n");
            fprintf(fp[i], "\t\t\t\t      HIEU TRUONG TRUONG THPT LE QUY DON - DONG DA KHEN NGOI\n\n");
            fprintf(fp[i], "\t\t\t\t      Em: %s\n", "Do Quang Tuan");
            fprintf(fp[i], "\t\t\t\t      Da dat danh hieu hoc sinh %s nam hoc 2017 - 2018\n\n", XepLoai(prt->rank));
            fprintf(fp[i], "\t\t\t\t\t\t\t\t\t\t\t\t Ngay %d Thang %d Nam %d\n", time.wDay, time.wMonth, time.wYear);
            fprintf(fp[i], "\t\t\t\t\t\t\t\t\t\t\t\t\t HIEU TRUONG\n");
            fprintf(fp[i], "\t\t\t\t\t\t\t\t\t\t\t\t\t    Tuan\n");
            fprintf(fp[i], "\t\t\t\t\t\t\t\t\t\t\t\t        Do Quang Tuan\n");
            fclose(fp[i]);
        }
        prt = prt->next;
    }
    return;
}
