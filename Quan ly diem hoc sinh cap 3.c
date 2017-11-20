//created by Yukineko69
//*K62 lớp số 7 ĐHCN - ĐHQGHN
//*Phần mềm quản lý điểm của học sinh THPT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-------------------
#include <time.h>
#include <windows.h>
//-------------------
//Hai thư viện trên để lấy date & time của Windows System

typedef struct HocSinh{
    //----------------------------------------------------------
    //Khai báo các dữ liệu bên trong struct sẽ dùng
    int STT;
    char name[50], ten[10], dem[10];
    float Toan, Van, Anh, Ly, Hoa, Sinh, Su, Dia, GDCD, CN, Tin;
    float DTB;
    int TD;
    int rank;
    //----------------------------------------------------------    
    struct HocSinh *next; //Khai báo con trỏ next để lưu địa chỉ của struct kế tiếp trong danh
                          //sách móc nối
}hs;

hs *head = NULL; //Khai báo con trỏ struct head để lưu địa chỉ của struct đầu tiên trong danh
                 //sách móc nối và để thực hiện các thao tác
hs *head2 = NULL;

//----------------------------------------------------------------------------------------------
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
void printList();
void FilterHS(int case_i);
float returnFilter(hs *filter, int case_);
void printFilter(hs *prt);
void TimKiem(char *name);
void PrtCerti();
//----------------------------------------------------------------------------------------------
//Khai báo các hàm con sẽ sử dụng trong bài

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
        //---------------------------------------------------------------------------------------
        //Nhập dữ liệu để truyền vào trong struct qua hàm insertFirst
        printf("Moi ban nhap ten cua hoc sinh: ");
        fflush(stdin); //Refresh lại stdin để tránh hiện tượng trôi lệnh
        fgets(name, 50, stdin);
        strtok(name, "\n"); //Duyệt xâu name cho đến khi gặp "\n" thì dừng lại rồi lấy đoạn
                            //phía trước của xâu, gán xâu mới này lại cho name.
                            //Ở đây lệnh này có tác dụng loại kí tự enter khỏi xâu
        printf("Moi ban nhap diem mon Toan: ");
        scanf("%f", &Toan);
        Toan = KTraNhap(Toan); //Hàm KTraNhap có tác dụng chủ yếu để tránh các thành phần
                               //lầy lội thích nhập số lung tung để phá chương trình
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
        while (TD != 0 && TD != 1){ //Vì thể dục chỉ có đạt vào ko đạt nên chỉ được lưu
                                    //2 giá trị là 0 và 1
            printf("Da bao la nhap 0 hay 1 co ma nhap linh tinh cai gi the nhap lai di: ");
            scanf("%d", &TD);
        }
        //---------------------------------------------------------------------------------------        
        insertFirst(name, Toan, Van, Anh, Ly, Hoa, Sinh, Su, Dia, GDCD, CN, Tin, TD);
        //Truyền dữ liệu đã nhập vào hàm con insertFirst
        ++i;
        printf("\n");
    }

    insertionSort(); //Hàm này có tác dụng sắp xếp danh sách sau khi đã nhập theo thứ tự
                     //từ A ~ Z của họ tên học sinh
    putSTT();        //Hàm putSTT để truyền giá trị số thứ tự vào cho các học sinh
    XepLoaiHS();     //Hàm XepLoaiHS để gán xếp loại học lực vào cho từng học sinh
    printList();     //In ra danh sách học sinh sau khi đã sắp xếp và xếp loại

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
    //Nếu như người dùng chọn yes thì sẽ thực hiện lệnh xóa màn hình rồi bắt đầu
    //chạy chương trình mở rộng
    //Nếu như người dùng chọn no thì chương trình chạy đến nhãn dán exit đã được
    //đặt sẵn ở phía cuối của chương trình để kết thúc

    //--------------------------------------------------------------------------------------------------
    //Phần chức năng mở rộng của chương trình
    menu:{ //Nhãn dán menu giúp quay trở lại menu để tiếp tục thực hiện các chức năng 
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
                default:{ //Nếu nhập sai case thì báo lỗi rồi cho nhập lại case
                    printf("Nhap sai cu phap xin moi ban nhap lai.\n");
                    break;
                }
                case 1:{ //Bộ lọc để lọc danh sách theo yêu cầu
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
                        while (case_ < 0 && case_ > 5){ //Nhập lại case nếu nhập sai
                            printf("Nhap sai cu phap xin moi ban nhap lai case: ");
                            scanf("%d", &case_);
                        }
                        if (case_ == 0) goto menu; //Quay trở lại menu
                        else FilterHS(case_);
                        //Truyền case vào trong hàm con FilterHS để lấy dấu so sánh
                        printf("\nNhan nut bat ki de tiep tuc.\n");
                        getch();
                        //Tạm ngưng chương trình để nhìn danh sách trước khi bắt đầu
                        //lọc danh sách mới
                    }
                }
                case 2:{ //Tìm kiếm học sinh theo tên nhập vào
                    while (1){
                        system("cls");
                        printf("Moi ban nhap ten cua hoc sinh muon tim: ");
                        fflush(stdin);
                        fgets(name, 50, stdin);
                        strtok(name, "\n");
                        TimKiem(name); //truyền xâu vừa nhập vào hàm con TimKiem để tìm
                                       //xem có học sinh nào trùng tên đã nhập không
                        printf("Nhap 0 de thoat tim kiem, nhap so bat ki de tiep tuc tim kiem.\n");
                        int k;
                        scanf("%d", &k);
                        if (k == 0) goto menu; //Quay lại menu
                    }
                }
                case 3:{ //In bằng khen ra tệp
                         //Lưu ý: Nhân vật hiệu trưởng trong bằng khen chỉ là
                         //nhân vật hư cấu, bằng khen không có giá trị lưu hành
                    PrtCerti();
                    system("cls");
                    printf("Bang khen da duoc in thanh cong.\n");
                    printf("Nhap 0 de quay tro lai menu, nhap 1 de thoat chuong trinh: ");
                    int k;
                    scanf("%d", &k);
                    while (k != 0 && k != 1){
                        printf("Nhap sai cu phap xin moi ban nhap lai: ");
                        scanf("%d", &k);
                    }
                    if (k == 0) goto menu; //Quay lại menu
                    else goto exit;        //Thoát chương trình
                    break;
                }
                case 4:{ //In ra danh sách học sinh lần cuối rồi thoát chương trình
                    system("cls");
                    printf("\n");
                    printList();
                    goto exit;
                }
            }
        }
    }
    //--------------------------------------------------------------------------------------------------

    exit:{ //Nhãn dán exit để thoát chương trình khi cần
        return 1;
    }
}

float KTraNhap(float DiemSo){ //Kiểm tra xem có nhập điểm tử tế hay không
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

char* TheDuc(int TD){ //Hàm có tác dụng in ra Dat hoặc Ko Dat khi in danh sách
                      //từ các giá trị 0 và 1 đã nhập được truyền vào
    if (TD == 1) return "Dat";
    if (TD == 0) return "Ko Dat";
    else return;
}

char* XepLoai(int XL){ //Hàm có tác dụng in ra xếp loại học lực từ các giá trị
                       //1 ~ 5 được truyền vào
    if (XL == 5) return "Gioi";
    if (XL == 4) return "Kha";
    if (XL == 3) return "TB";
    if (XL == 2) return "Yeu";
    if (XL == 1) return "Kem";
    else return;
}

void printList(){
    hs *prt = head; //Khai báo con trỏ prt bắt đầu từ head của danh sách liên kết
    printf("Danh sach hoc sinh va bang diem cua lop hoc:\n\n");
    printf("%-6s %-22s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-8s\n", \
        "STT" , "Ho va Ten", "Toan", "Van", "Anh", "Ly" , "Hoa", "Sinh", \
        "Su"  , "Dia"      , "GDCD", "CN" , "Tin", "DTB",  "TD", "Xep Loai");
    while(prt != NULL) { //Khi con trỏ prt chưa đến cuối danh sách liên kết thì in
                         //điểm vào học lực của học sinh đã nhập vào danh sách
        printf("%-6d %-22s %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6s %-8s\n", \
        prt->STT, prt->name, prt->Toan, prt->Van, prt->Anh , prt->Ly  , prt->Hoa, prt->Sinh, prt->Su, \
        prt->Dia, prt->GDCD, prt->CN  , prt->Tin, prt->DTB , TheDuc(prt->TD)    , XepLoai(prt->rank) );
        prt = prt->next; //Gán con trỏ prt cho giá trị tiếp theo trong danh sách liên kết
    }
    return;
}

//Hàm có tác dụng truyền vào các giá trị của struct học sinh rồi móc nối lại thanh một
//danh sách liên kết hoàn chỉnh
void insertFirst(char *name, float Toan, float  Van, float  Anh, float  Ly, float Hoa,
                 float Sinh, float   Su, float  Dia, float GDCD, float  CN, float Tin, int TD){
    char temp1[50], temp2[50];
    int k;
    hs *new_ = (hs*) malloc(sizeof(hs)); //Khai báo con trỏ động new_ làm mắt xích mới
                                         //cho danh sách
    strcpy(new_->name, name);
    //-----------------------------------------------------------------------------------------------
        strcpy(temp1, new_->name);
        strcpy(new_->ten, xoachuoi(temp1, strlen(temp1) - 1));
        //Hàm xoachuoi sẽ trả về từ cuối cùng  của xâu temp1
        //tức là ở đây sẽ tách được thành phân tên trong họ và tên
        strcpy(temp1, new_->name);
        k = daucach(temp1) - 1; //Gán k là vị trí trước dấu cách cuối cùng của xâu
        strcpy(temp2, copy(temp1, 0, k)); //Hàm copy trả về xâu họ tên từ kí tự 0
                                          //đến kí tự k
        //Xâu temp2 giờ sẽ là họ và tên nhưng bị bỏ mất từ cuối cùng tức là phần tên
        strcpy(new_->dem, xoachuoi(temp2, k));
        //Tiếp tục chạy hàm xoachuoi để trả về từ cuối cùng tức là phần đệm của họ tên
    //Phần này có tác dụng tách thành phần tên và đệm trong họ và tên nhằm phục vụ
    //cho mục đích sắp xếp sau này
    //-----------------------------------------------------------------------------------------------
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
    //Gán các giá trị được truyền vào hàm sau khi nhập vào trong struct
    //-----------------------------------------------------------------------------------------------

    new_->next = head; //Gán con trỏ next của struct new_ với địa chỉ mà hiện tại head đang lưu
                       //tức là để con trỏ next lưu địa chỉ mắt xích tiếp theo trong danh sách
    head = new_;       //Gán địa chỉ của new_ cho con trỏ head, tức là giờ head sẽ lưu địa chỉ
                       //của mắt xích new_
    return;
}

char* copy(char s[], int x, int y){ //Hàm có tác dụng gán lại xâu s được tryền bắt đầu từ
                                    //kí tự thứ x đến kí tự thứ y
    char s2[50];
    int i, j = 0;

    for (i = x; i <= y; ++i){
        if (j <= (y - x)){
            s2[j] = s[i];
            j++;
        }
    }
    s2[j] = '\0';  //Gán giá trị NULL kết thúc xâu cho xâu s2
    strcpy(s, s2); //Gán xâu s2 sau khi copy cho xâu s rồi trả về xâu s sau khi đã copy
    return s;
}

int daucach(char s[]){ //Hàm có tác dụng trả về vị trí dấu cách đầu tiền tìm thấy được
                       //tính từ cuối xâu lên đầu
    int i;
    for (i = strlen(s) - 1; i >= 0; i--){
        if (s[i] == ' ') break;
    }
    return i;
}

char* xoachuoi(char s[], int x){ //Hàm có tác dụng gán lại xâu s được truyền vào thành
                                 //từ cuối cùng sau dấu cách của xâu
    int i = 0, j;
    j = daucach(s);
    copy(s, j + 1, x); //Sau khi tìm được vị trí dấu cách cuối cùng thì sẽ gán
                       //lại xâu s từ vị trí sau dấu cách đến hết xâu
    return s;
}

void insertionSort(){
    if (head == NULL) return;       //Nếu xâu rỗng thì thoát hàm con vì không có gì để sắp xếp
    if (head->next == NULL) return; //Nếu xâu chỉ có 1 phần tử thì thoát vì không có gì để sắp xếp
    hs *new_ = head;
    while (new_ != NULL){
        hs *temp = new_->next; //Khai báo một con trỏ trung gian để lưu con trỏ next của new_
        sortedInsert(new_);    //Truyền new_ vào trong hàm sortedInsert để thực hiện thuật toán
                               //Insertion Sort
        new_ = temp;           //Gán new_ cho mắt xích tiếp theo của danh sách liên kết
    }
    head = head2;              //Gán địa chỉ của head2 cho head để có thể chạy các hàm con khác
    return;
}

//Thuật toán Insertion Sort: ta sẽ lần lượt duyệt từng mắt xích ở danh sách liên kết cũ rồi
//sau đó lấy phần tử đó thêm vào danh sách liên kết mới, mỗi lần thêm 1 phần tử ta so sánh
//nó với các phần tử đã được thêm vào trước đó để chọn vị trí phù hợp
void sortedInsert(hs* new_){
    if (head2 == NULL || strcmp(head2->ten, new_->ten) > 0 ||
       (!strcmp(head2->ten, new_->ten) && strcmp(head2->dem, new_->dem) > 0)){
        //Lệnh if (!strcmp(...)) tương đương với lệnh if (strcmp(...) == 0)
        //Hàm strcmp sẽ so sánh 2 xâu, trả về 0 nếu 2 xâu bằng nhau, 1 nếu xâu 1 lớn hơn xâu 2
        //trả về -1 nếu xâu 1 nhỏ hơn xâu 2 (tính theo bảng mã ASCII)
        new_->next = head2;
        head2 = new_;
        //Nếu xâu mới rỗng (tức là thêm phần tử đầu tiên) hoặc phần tử đầu tiên lớn hơn phần
        //tử chuẩn bị được thêm vào thì sẽ nhập mắt xích lên đầu
    }
    else{ //Nếu như không phải thì sẽ bắt đầu thực hiện bước so sánh tìm vị trí thích hợp
        hs *current = head2; //Khai báo con trỏ current bắt đầu từ head2 để duyệt danh sách
        while (current->next != NULL && (strcmp(current->next->ten, new_->ten) < 0 ||
              (!strcmp(current->next->ten, new_->ten) && strcmp(current->next->dem, new_->dem) < 0))){
            current = current->next;
            //Khi mắt xích hiện tại chưa phải mắt xích cuối và họ tên của new_ vẫn lớn
            //hơn họ tên hiện tại đang duyệt thì duyệt tiếp mắt xích sau
        }
        //Sau khi kết thúc vòng while, giờ đây con trỏ current đang duyệt đến mắt xích có
        //họ và tên lớn nhất trong số các họ và tên bé hơn họ và tên của new_
        new_->next = current->next; //Gán next của new với địa chỉ của mắt xích phía sau current
        current->next = new_;       //Gán next của current với địa chỉ của mắt xích new_
    }
    return;
}

void putSTT(){ //Hàm có tác dụng gán giá trị STT cho struct
    int i = 0;
    hs *put = head;
    while (put != NULL){
        put->STT = ++i;
        put = put->next;
    }
    return;
}

void XepLoaiHS(){ //Hàm có tác dụng gán xếp loại học lực cho struct
    hs *XepLoai = head;
    while (XepLoai != NULL){ //Duyệt từng mắt xích rồi duyệt điều kiện để xếp lại học lực
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

void TimKiem(char *name){ //Hàm có tác dụng in ra danh sách học sinh có tên trùng với 
                          //xâu name được truyền vào
    hs *prt = head;
    int count = 0;
    while (prt != NULL){
        if (!strcmp(prt->name, name)) ++count;
        prt = prt->next;
    }
    if (count == 0) printf("Khong tim thay bat ki hoc sinh nao ten %s .\n", name);
    //Nếu như không đếm được bất kì họ tên nào giống name thì in ra không tìm thấy
    else{
        prt = head;
        printf("Thong tin cac hoc sinh tim thay duoc:\n\n");
        printf("%-6s %-22s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-8s\n", \
            "STT" , "Ho va Ten", "Toan", "Van", "Anh", "Ly" , "Hoa", "Sinh", \
            "Su"  , "Dia"      , "GDCD", "CN" , "Tin", "DTB",  "TD", "Xep Loai");
        while (prt != NULL) { //Duyệt từng mắt xích trong danh sách nếu họ tên giống với
                              //name thì sẽ được in ra màn hình
            if (!strcmp(prt->name, name))
            printf("%-6d %-22s %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6s %-8s\n", \
            prt->STT, prt->name, prt->Toan, prt->Van, prt->Anh , prt->Ly  , prt->Hoa, prt->Sinh, prt->Su, \
            prt->Dia, prt->GDCD, prt->CN  , prt->Tin, prt->DTB , TheDuc(prt->TD)    , XepLoai(prt->rank) );
            prt = prt->next;
        }
    }
    return;
}

void FilterHS(int case_i){ //Hàm có tác dụng chạy bộ lọc danh sách
    int n, case_;
    printf("\nCase 1: Toan\nCase 2: Van\nCase 3: Anh\nCase 4: Ly\nCase 5: Hoa\nCase 6: Sinh\n");
    printf("Case 7: Su\nCase 8: Dia\nCase 9: GDCD\nCase 10: CN\nCase 11: Tin\nCase 12: Diem TB\n");
    printf("Case 13: TD\nCase 14: Xep Loai\n");
    printf("\nMoi ban nhap case: ");
    scanf("%d", &case_);
    while (case_ < 1 && case_ > 14){ //Nếu nhập sai case thì nhập lại
        printf("Nhap sai cu phap xin moi ban nhap lai case: ");
        scanf("%d", &case_);
    }
    printf("\nMoi ban nhap moc: ");
    scanf("%d", &n);
    if (case_ >= 1 && case_ <= 12){
        n = KTraNhap(n); //Với các mốc là điểm số thì cho chạy hàm KTraNhap để tránh
                         //tình trạng lầy lội thích troll chương trình
    }
    else if (case_ == 13){
        while (n != 1 && n != 0){ //Nếu lọc môn thể dục thì chỉ có thể nhập 0 và 1
            printf("Nhap sai moc xin hay nhap lai (Dat nhap 1, Ko Dat nhap 0): ");
            scanf("%d", &n);
        }
    }
    else{
        while (n < 1 || n > 5){ //Nếu lọc xếp loại học lực thì phải nhập số từ 1 ~ 5
            printf("Nhap sai moc xin hay nhap lai (1 ~ 5 <=> XL Kem ~ XL Gioi): ");
            scanf("%d", &n);
        }
    }
    hs *filter = head;
    printf("Danh sach hoc sinh sau khi loc la:\n\n");
    printf("%-6s %-22s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-6s %-8s\n", \
            "STT" , "Ho va Ten", "Toan", "Van", "Anh", "Ly" , "Hoa", "Sinh", \
            "Su"  , "Dia"      , "GDCD", "CN" , "Tin", "DTB",  "TD", "Xep Loai");
    while (filter != NULL){ //Duyệt từng mắt xích trong danh sách nếu hợp điều kiện thì in ra
                            //màn hình
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

float returnFilter(hs *filter, int case_){ //Hàm có tác dụng trả về giá trị điểm số môn học
                                           //bên trong của struct filter được truyền vào
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

void printFilter(hs *prt){ //Hàm có tác dụng in ra màn hình thông tin học sinh của hàm FilterHS
    printf("%-6d %-22s %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6.1f %-6s %-8s\n", \
            prt->STT, prt->name, prt->Toan, prt->Van, prt->Anh , prt->Ly  , prt->Hoa, prt->Sinh, prt->Su, \
            prt->Dia, prt->GDCD, prt->CN  , prt->Tin, prt->DTB , TheDuc(prt->TD)    , XepLoai(prt->rank) );
    return;
}

void PrtCerti(){ //Hàm có tác dụng in bằng khen học sinh Giỏi và Khá ra tệp
    hs *prt = head;
    int count = 0, i = 0;
    //----------------------------------------------------------------------
    SYSTEMTIME time;      //Gán biến time có kiểu biến là SYSTEMTIME
    GetSystemTime(&time); //Lấy date time từ hệ thống gán cho biến time
    //----------------------------------------------------------------------
    while (prt != NULL){
        if (prt->rank >= 4) ++count;
        prt = prt->next;
    }
    prt = head;
    FILE *fp[count]; //Đếm số lượng học sinh Giỏi và Khá rồi mới khai mảng để tiết kiệm bộ nhớ
    while (prt != NULL){ //Duyệt từng mắt xích trong danh sách nếu là học sinh Giỏi hoặc Khá
                         //thì sẽ tạo tệp rồi in bằng khen
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
